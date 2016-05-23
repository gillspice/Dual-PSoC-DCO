/*******************************************************************************
* File Name: Freq_Timer_PM.c
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

#include "Freq_Timer.h"

static Freq_Timer_backupStruct Freq_Timer_backup;


/*******************************************************************************
* Function Name: Freq_Timer_SaveConfig
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
*  Freq_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Freq_Timer_SaveConfig(void) 
{
    #if (!Freq_Timer_UsingFixedFunction)
        Freq_Timer_backup.TimerUdb = Freq_Timer_ReadCounter();
        Freq_Timer_backup.InterruptMaskValue = Freq_Timer_STATUS_MASK;
        #if (Freq_Timer_UsingHWCaptureCounter)
            Freq_Timer_backup.TimerCaptureCounter = Freq_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Freq_Timer_UDB_CONTROL_REG_REMOVED)
            Freq_Timer_backup.TimerControlRegister = Freq_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Freq_Timer_RestoreConfig
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
*  Freq_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Freq_Timer_RestoreConfig(void) 
{   
    #if (!Freq_Timer_UsingFixedFunction)

        Freq_Timer_WriteCounter(Freq_Timer_backup.TimerUdb);
        Freq_Timer_STATUS_MASK =Freq_Timer_backup.InterruptMaskValue;
        #if (Freq_Timer_UsingHWCaptureCounter)
            Freq_Timer_SetCaptureCount(Freq_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Freq_Timer_UDB_CONTROL_REG_REMOVED)
            Freq_Timer_WriteControlRegister(Freq_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Freq_Timer_Sleep
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
*  Freq_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Freq_Timer_Sleep(void) 
{
    #if(!Freq_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Freq_Timer_CTRL_ENABLE == (Freq_Timer_CONTROL & Freq_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Freq_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Freq_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Freq_Timer_Stop();
    Freq_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Freq_Timer_Wakeup
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
*  Freq_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Freq_Timer_Wakeup(void) 
{
    Freq_Timer_RestoreConfig();
    #if(!Freq_Timer_UDB_CONTROL_REG_REMOVED)
        if(Freq_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Freq_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
