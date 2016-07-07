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
#define CALCULATE_USING_PERIOD
#ifdef CALCULATE_USING_PERIOD
  #include "periodLUT.h"
#else  
#include "countToFrequencyLookup.h"
#endif
//#define SCALE_FM_INPUT

uint8_t dac_value;
uint32_t count;
uint32_t oldCount;
uint8_t oldSign = 1;
uint8_t newSign;

#define C_TRI_UF 0.01
#define I_MAX_1_UA 32.0
#define I_MAX_2_UA 255.0
#define V_PP 3.0

enum adcChannels
{
  adcCvInputChannel = 0,
  adcRangeInputChannel,
  adcCoarseInputChannel,
  adcFineInputChannel
};

int main()
{
    int pinState = 0;
    CyGlobalIntEnable; /* Enable global interrupts. */
  int32_t newReg;
  int32_t deltaCount;
  
  float freq_break_1 = I_MAX_1_UA / (C_TRI_UF * V_PP);
  float freq_break_2 = I_MAX_2_UA / (C_TRI_UF * V_PP);
#ifdef CALCULATE_USING_PERIOD
  uint32_t period_break_1 = 12000000 / freq_break_1 / 8;
  uint32_t period_break_2 = 12000000 / freq_break_2 / 8;
#endif

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    OSC1_Freq_Timer_Start();
    OSC1_IDAC8_Start();
    Clock_1_Start();
    OSC1_IDAC8_SetValue(255);
    OSC1_IDAC8_SAW_Start();
    OSC1_IDAC8_SAW_SetValue(255);
    ADC_DelSig_1_Start();
    ADC_DelSig_1_StartConvert();
    OSC1_Freq_Timer_WritePeriod(2400);
    OSC1_Triangle_Follower_Start();
    OSC1_Triangle_Follower_Enable();
    OSC1_Saw_Follower_Start();
    OSC1_Saw_Follower_Enable();
    OSC1_Comp_Start();
    OSC1_Comp_Enable();
    OSC1_ADC_SAR_Start();
    OSC1_ADC_SAR_StartConvert();
//    OSC1_Mux_Init();
//    OSC1_Mux_Start();
//    OSC1_Mux_Next();
//    OSC1_ISR_Start();
//    OSC1_Inverter_Start();
//    OSC1_Inverter_Enable();
    
    FM_Sign_Compare_Start();
    FM_Sign_Compare_Enable();
    
    int32_t result;
#ifndef CALCULATE_USING_PERIOD
    float frequency;
#endif
    uint32_t cvAdcValue;
    
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
        
        #ifdef SCALE_FM_INPUT
        result = abs(ADC_DelSig_1_GetResult32()+32767);
        #else
        result = abs(ADC_DelSig_1_GetResult32());
        #endif
        
        // detect no FM input and clamp to midpoint
        if (result < 100) result = 32767;
        
//        frequency = (20*result*(
//            pow(1.059463094,(
//                12*(OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(0)) + 
//                    OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(1))*2 + 
//                    OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(2))/5 + 
//                    OSC1_ADC_SAR_CountsTo_Volts(OSC1_ADC_SAR_GetResult16(3))/5/12))
//            )))/32767;
        cvAdcValue = OSC1_ADC_SAR_GetResult16(adcCvInputChannel);
        cvAdcValue = cvAdcValue + 2*4096/5;
//        if (cvAdcValue > 8191) cvAdcValue = 8191;
        cvAdcValue &= 0x1fff;
        
        oldCount = count;
        
#ifdef CALCULATE_USING_PERIOD
        count = countToPeriodLookup[cvAdcValue]/result;
#else
        frequency = result * countToFrequencyLookup[cvAdcValue]/32767;
//        frequency = countToFrequencyLookup[cvAdcValue];
//        frequency = countToFrequencyLookup[OSC1_ADC_SAR_GetResult16(adcCvInputChannel)];

        if (frequency > 20000)
        {
            frequency = 20000;
        } else if (frequency < 1)
        {
            frequency = 1;
        }
        
        count = 12000000/frequency;
        count /= 8;
#endif

//        count = 3409; // 440hz value for testing
        
        deltaCount = (int32_t)count - (int32_t)oldCount;
        newReg = OSC1_Freq_Timer_ReadCounter() + deltaCount;
        OSC1_Freq_Timer_WritePeriod(count);
        if (newReg < 0)
        {
          newReg = 1;
        OSC1_Freq_Timer_WriteCounter(newReg);
        }
        else if ((uint32_t)newReg > count)
        {
          newReg = count-1;
        OSC1_Freq_Timer_WriteCounter(newReg);
        }
        
//        OSC1_Freq_Timer_Stop();
//        OSC1_Freq_Timer_Start();
        
#ifndef CALCULATE_USING_PERIOD
    if (frequency > freq_break_2){
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_2mA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_2mA);
        dac_value = frequency * C_TRI_UF * V_PP / 8;
    }
    else if (frequency > freq_break_1){
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_255uA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_255uA);
        dac_value = frequency * C_TRI_UF * V_PP;
    } else {
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_32uA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_32uA);
        dac_value = frequency * C_TRI_UF * V_PP * 8;
    }   
#else
    if (count < period_break_2){
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_2mA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_2mA);
        dac_value = (45000/8) / count;
    }
    else if (count < period_break_1){
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_255uA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_255uA);
        dac_value = 45000 / count;
    } else {
        OSC1_IDAC8_SetRange(OSC1_IDAC8_RANGE_32uA);
        OSC1_IDAC8_SAW_SetRange(OSC1_IDAC8_SAW_RANGE_32uA);
        dac_value = (45000 * 8) / count;
    }   
#endif

    OSC1_IDAC8_SetValue(dac_value);
    OSC1_IDAC8_SAW_SetValue(dac_value);
    }
}

/* [] END OF FILE */
