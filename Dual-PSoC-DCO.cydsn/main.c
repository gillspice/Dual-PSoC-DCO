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

#define CAP_VALUE 0.027;
#define VPP_VALUE 2.5;

int dac_value;

int main()
{
    int pinState = 0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    volatile int myFixedValue = 1;

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
//    OSC1_Mux_Init();
//    OSC1_Mux_Start();
//    OSC1_Mux_Next();
//    OSC1_ISR_Start();
//    OSC1_Inverter_Start();
//    OSC1_Inverter_Enable();
    
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
        int result = ADC_DelSig_1_GetResult32();
//        int frequency = (220*(pow(1.059463094,(12*ADC_DelSig_1_CountsTo_Volts(result)))));
//        int frequency = (220*(pow(1.059463094,(12*myFixedValue))));
        int frequency = (110*(pow(2, 5*result/65535)));
        int count = 12000000/frequency;
       OSC1_Freq_Timer_WritePeriod(count);
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
