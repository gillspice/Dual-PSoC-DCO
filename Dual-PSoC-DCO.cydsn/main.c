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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    OSC1_Freq_Timer_Start();
    OSC1_Freq_Timer_1_Start();
    OSC1_IDAC8_Start();
    OSC1_IDAC8_SetValue(255);
    OSC1_IDAC8_SAW_Start();
    OSC1_IDAC8_SAW_SetValue(255);
    ADC_DelSig_1_Start();
    ADC_DelSig_1_StartConvert();
    OSC1_Freq_Timer_WritePeriod(36000);
    OSC1_Freq_Timer_1_WritePeriod(36000);
    OSC1_Follower_Start();
    OSC1_Follower_Enable();
    OSC1_Comp_Start();
    OSC1_Comp_Enable();
//    OSC1_Mux_Init();
//    OSC1_Mux_Start();
//    OSC1_Mux_Next();
    OSC1_ISR_Start();
//    OSC1_Inverter_Start();
//    OSC1_Inverter_Enable();
    
    for(;;)
    {
        int result = ADC_DelSig_1_GetResult32();
        int frequency = (110*(pow(1.059463094,(12*ADC_DelSig_1_CountsTo_Volts(result)))));
        int count = 12000000/frequency;
       OSC1_Freq_Timer_WritePeriod(count);
       OSC1_Freq_Timer_1_WritePeriod(count*2);
       int dac_value=(frequency/8);
    OSC1_IDAC8_SetValue(dac_value);
    OSC1_IDAC8_SAW_SetValue(dac_value/2);
  //      CyDelay(1000); /* Place your application code here. */
    //   Freq_Timer_WritePeriod(36000);
   //    IDAC8_1_SetValue(127);
//       CyDelay(5000);
//       Freq_Timer_WritePeriod(18000);
   //    IDAC8_1_SetValue(255);
    }
}

/* [] END OF FILE */
