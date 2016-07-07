/*******************************************************************************
* File Name: FM_Sign_Compare.c
* Version 2.0
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "FM_Sign_Compare.h"

static FM_Sign_Compare_backupStruct FM_Sign_Compare_backup;


/*******************************************************************************
* Function Name: FM_Sign_Compare_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void FM_Sign_Compare_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: FM_Sign_Compare_RestoreConfig
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
********************************************************************************/
void FM_Sign_Compare_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: FM_Sign_Compare_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  FM_Sign_Compare_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void FM_Sign_Compare_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(FM_Sign_Compare_ACT_PWR_EN == (FM_Sign_Compare_PWRMGR & FM_Sign_Compare_ACT_PWR_EN))
    {
        /* Comp is enabled */
        FM_Sign_Compare_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        FM_Sign_Compare_backup.enableState = 0u;
    }    
    
    FM_Sign_Compare_Stop();
    FM_Sign_Compare_SaveConfig();
}


/*******************************************************************************
* Function Name: FM_Sign_Compare_Wakeup
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
*  FM_Sign_Compare_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void FM_Sign_Compare_Wakeup(void) 
{
    FM_Sign_Compare_RestoreConfig();
    
    if(FM_Sign_Compare_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        FM_Sign_Compare_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
