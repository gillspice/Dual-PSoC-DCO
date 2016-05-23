/*******************************************************************************
* File Name: OSC1_Freq_Timer_1_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "OSC1_Freq_Timer_1.h"

static OSC1_Freq_Timer_1_backupStruct OSC1_Freq_Timer_1_backup;


/*******************************************************************************
* Function Name: OSC1_Freq_Timer_1_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC1_Freq_Timer_1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void OSC1_Freq_Timer_1_SaveConfig(void) 
{
    #if (!OSC1_Freq_Timer_1_UsingFixedFunction)
        OSC1_Freq_Timer_1_backup.TimerUdb = OSC1_Freq_Timer_1_ReadCounter();
        OSC1_Freq_Timer_1_backup.InterruptMaskValue = OSC1_Freq_Timer_1_STATUS_MASK;
        #if (OSC1_Freq_Timer_1_UsingHWCaptureCounter)
            OSC1_Freq_Timer_1_backup.TimerCaptureCounter = OSC1_Freq_Timer_1_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!OSC1_Freq_Timer_1_UDB_CONTROL_REG_REMOVED)
            OSC1_Freq_Timer_1_backup.TimerControlRegister = OSC1_Freq_Timer_1_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: OSC1_Freq_Timer_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC1_Freq_Timer_1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void OSC1_Freq_Timer_1_RestoreConfig(void) 
{   
    #if (!OSC1_Freq_Timer_1_UsingFixedFunction)

        OSC1_Freq_Timer_1_WriteCounter(OSC1_Freq_Timer_1_backup.TimerUdb);
        OSC1_Freq_Timer_1_STATUS_MASK =OSC1_Freq_Timer_1_backup.InterruptMaskValue;
        #if (OSC1_Freq_Timer_1_UsingHWCaptureCounter)
            OSC1_Freq_Timer_1_SetCaptureCount(OSC1_Freq_Timer_1_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!OSC1_Freq_Timer_1_UDB_CONTROL_REG_REMOVED)
            OSC1_Freq_Timer_1_WriteControlRegister(OSC1_Freq_Timer_1_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: OSC1_Freq_Timer_1_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC1_Freq_Timer_1_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void OSC1_Freq_Timer_1_Sleep(void) 
{
    #if(!OSC1_Freq_Timer_1_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(OSC1_Freq_Timer_1_CTRL_ENABLE == (OSC1_Freq_Timer_1_CONTROL & OSC1_Freq_Timer_1_CTRL_ENABLE))
        {
            /* Timer is enabled */
            OSC1_Freq_Timer_1_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            OSC1_Freq_Timer_1_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    OSC1_Freq_Timer_1_Stop();
    OSC1_Freq_Timer_1_SaveConfig();
}


/*******************************************************************************
* Function Name: OSC1_Freq_Timer_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC1_Freq_Timer_1_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void OSC1_Freq_Timer_1_Wakeup(void) 
{
    OSC1_Freq_Timer_1_RestoreConfig();
    #if(!OSC1_Freq_Timer_1_UDB_CONTROL_REG_REMOVED)
        if(OSC1_Freq_Timer_1_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                OSC1_Freq_Timer_1_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
