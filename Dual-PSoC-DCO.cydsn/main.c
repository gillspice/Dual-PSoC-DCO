/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>
#include <stdlib.h>

#define CAP_VALUE 0.027
#define VPP_VALUE 2.5

int dac_value;
uint32_t count;
uint32_t oldCount;
uint8_t oldSign = 1;
uint8_t newSign;

enum adcChannels
{
  adcCvInputChannel = 0,
  adcRangeInputChannel,
  adcCoarseInputChannel,
  adcFineInputChannel
};

CY_ISR_PROTO(SIGNCHANGE_PositiveInterrupt_Handler);
CY_ISR(SIGNCHANGE_PositiveInterrupt_Handler)
{
    #ifdef OSC1_SIGNCHANGE_ISR1_INTERRUPT_INTERRUPT_CALLBACK
        OSC1_SIGNCHANGE_ISR1_Interrupt_InterruptCallback();
    #endif /* OSC1_SIGNCHANGE_ISR1_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START OSC1_SIGNCHANGE_ISR1_Interrupt` */
    OSC1_Freq_Timer_Stop();
   OSC1_Freq_Timer_WriteCounter(count-OSC1_Freq_Timer_ReadCounter());
   OSC1_Freq_Timer_Start();
    /* `#END` */
}

CY_ISR_PROTO(SIGNCHANGE_NegativeInterrupt_Handler);
CY_ISR(SIGNCHANGE_NegativeInterrupt_Handler)
{
    #ifdef OSC1_SIGNCHANGE_ISR2_INTERRUPT_INTERRUPT_CALLBACK
        OSC1_SIGNCHANGE_ISR2_Interrupt_InterruptCallback();
    #endif /* OSC1_SIGNCHANGE_ISR2_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START OSC1_SIGNCHANGE_ISR2_Interrupt` */
    
    OSC1_Freq_Timer_Stop();

    OSC1_Freq_Timer_WriteCounter(count-OSC1_Freq_Timer_ReadCounter());

   OSC1_Freq_Timer_Start();
/* `#END` */
}


int main()
{
    int pinState = 0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    volatile int myFixedValue = 1;
  int32_t newReg;
  int32_t deltaCount;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    OSC1_Freq_Timer_Start();
//    OSC1_Freq_Timer_1_Start();
    OSC1_IDAC8_Start();
    Clock_1_Start();
    OSC1_IDAC8_SetValue(255);
    OSC1_IDAC8_SAW_Start();
    OSC1_IDAC8_SAW_SetValue(255);
    ADC_DelSig_1_Start();
    ADC_DelSig_1_StartConvert();
    OSC1_Freq_Timer_WritePeriod(36000);
//    OSC1_Freq_Timer_1_WritePeriod(36000);
    OSC1_Triangle_Follower_Start();
    OSC1_Triangle_Follower_Enable();
    OSC1_Saw_Follower_Start();
    OSC1_Saw_Follower_Enable();
    OSC1_Comp_Start();
    OSC1_Comp_Enable();
//    Comp_1_Start();
//    Comp_1_Enable();
    OSC1_ADC_SAR_Start();
    OSC1_ADC_SAR_StartConvert();
//    OSC1_SIGNCHANGE_PositiveISR_StartEx(SIGNCHANGE_PositiveInterrupt_Handler);
//    OSC1_SIGNCHANGE_NegativeISR_StartEx(SIGNCHANGE_NegativeInterrupt_Handler);
//    OSC1_Mux_Init();
//    OSC1_Mux_Start();
//    OSC1_Mux_Next();
//    OSC1_ISR_Start();
//    OSC1_Inverter_Start();
//    OSC1_Inverter_Enable();
    SW_Sign_Change_Write(0);
    
    int32_t result;
    uint32_t frequency;
    float cvVolts;
    
    for(;;)
    {
        if (pinState == 0)
        {
            pinState = 1;
            test_pin_Write(00);
        }
        else
        {
            pinState = 0;
            test_pin_Write(0xff);
        }
        
        result = ADC_DelSig_1_GetResult32();
        if (result < 0)
        {
          newSign = 0;
            SW_Sign_Change_Write(0);
        }
        else
        {
          newSign = 1;
            SW_Sign_Change_Write(1);
        }                        
        result = abs(result);
        
        
//        frequency = (20*result*(
//            pow(1.059463094,(
//                12*(OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(0)) + 
//                    OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(1))*2 + 
//                    OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(2))/5 + 
//                    OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(3))/5/12))
//            )))/32767;
        
        cvVolts = OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(adcCvInputChannel));
        frequency = (20.0*result*pow(1.059463094,12*cvVolts))/32767;
//        int frequency = (220*(pow(1.059463094,(12*myFixedValue))));
 //       int frequency = (110*(pow(2, 5*result/65535)));
        if (frequency > 20000)
        {
            frequency = 20000;
        } else if (frequency < 1)
        {
            frequency = 1;
        }
        __disable_irq();
        oldCount = count;
        count = 12000000/frequency;
        deltaCount = (int32_t)count - (int32_t)oldCount;
        OSC1_Freq_Timer_Stop();
        newReg = OSC1_Freq_Timer_ReadCounter() + deltaCount;
        if (newReg < 0)
        {
          newReg = 1;
        }
        else if ((uint32_t)newReg > count)
        {
          newReg = count-1;
        }
        if (newSign != oldSign)
        {
          oldSign = newSign;
          newReg = count-newReg;
        }
        OSC1_Freq_Timer_WriteCounter(newReg);
        OSC1_Freq_Timer_WritePeriod(count);
//        if (count < OSC1_Freq_Timer_ReadCounter()) {
//            OSC1_Freq_Timer_WriteCounter(count);
//        }
        OSC1_Freq_Timer_Start();
        __enable_irq();
//       OSC1_Freq_Timer_1_WritePeriod(count*2);
    if (frequency > 3950){
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_2mA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_2mA);
        dac_value = frequency / 32 ;
    }
    else if (frequency > 493){
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_255uA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_255uA);
        dac_value = frequency /4 ;}
    else {
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_32uA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_32uA);
        dac_value = frequency * 2;
     }   
        
   //    dac_value=(frequency/8);
    OSC1_IDAC8_SetValue(dac_value/4);
    OSC1_IDAC8_SAW_SetValue(dac_value/4);
  //      CyDelay(1000); /* Place your application code here. */
    //   Freq_Timer_WritePeriod(36000);
   //    IDAC8_1_SetValue(127);
//       CyDelay(5000);
//       Freq_Timer_WritePeriod(18000);
   //    IDAC8_1_SetValue(255);
    }
}

/* [] END OF FILE */
