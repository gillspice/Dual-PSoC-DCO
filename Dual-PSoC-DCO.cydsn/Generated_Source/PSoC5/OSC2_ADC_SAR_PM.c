/*******************************************************************************
* File Name: OSC2_ADC_SAR_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "OSC2_ADC_SAR.h"
#include "OSC2_ADC_SAR_SAR.h"
#if(OSC2_ADC_SAR_CLOCK_SOURCE == OSC2_ADC_SAR_CLOCK_INTERNAL)
    #include "OSC2_ADC_SAR_IntClock.h"
#endif   /* OSC2_ADC_SAR_CLOCK_SOURCE == OSC2_ADC_SAR_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: OSC2_ADC_SAR_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC2_ADC_SAR_Sleep(void)
{
    OSC2_ADC_SAR_SAR_Stop();
    OSC2_ADC_SAR_SAR_Sleep();
    OSC2_ADC_SAR_Disable();

    #if(OSC2_ADC_SAR_CLOCK_SOURCE == OSC2_ADC_SAR_CLOCK_INTERNAL)
        OSC2_ADC_SAR_IntClock_Stop();
    #endif   /* OSC2_ADC_SAR_CLOCK_SOURCE == OSC2_ADC_SAR_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: OSC2_ADC_SAR_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC2_ADC_SAR_Wakeup(void)
{
    OSC2_ADC_SAR_SAR_Wakeup();
    OSC2_ADC_SAR_SAR_Enable();

    #if(OSC2_ADC_SAR_CLOCK_SOURCE == OSC2_ADC_SAR_CLOCK_INTERNAL)
        OSC2_ADC_SAR_IntClock_Start();
    #endif   /* OSC2_ADC_SAR_CLOCK_SOURCE == OSC2_ADC_SAR_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    OSC2_ADC_SAR_Enable();

    #if(OSC2_ADC_SAR_SAMPLE_MODE == OSC2_ADC_SAR_SAMPLE_MODE_FREE_RUNNING)
        OSC2_ADC_SAR_SAR_StartConvert();
    #endif /* (OSC2_ADC_SAR_SAMPLE_MODE == OSC2_ADC_SAR_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(OSC2_ADC_SAR_STATUS_PTR);
}


/*******************************************************************************
* Function Name: OSC2_ADC_SAR_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC2_ADC_SAR_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: OSC2_ADC_SAR_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC2_ADC_SAR_RestoreConfig(void)
{

}


/* [] END OF FILE */
