/*******************************************************************************
* File Name: OSC1_Comp.c
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

#include "OSC1_Comp.h"

static OSC1_Comp_backupStruct OSC1_Comp_backup;


/*******************************************************************************
* Function Name: OSC1_Comp_SaveConfig
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
void OSC1_Comp_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: OSC1_Comp_RestoreConfig
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
void OSC1_Comp_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: OSC1_Comp_Sleep
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
*  OSC1_Comp_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void OSC1_Comp_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(OSC1_Comp_ACT_PWR_EN == (OSC1_Comp_PWRMGR & OSC1_Comp_ACT_PWR_EN))
    {
        /* Comp is enabled */
        OSC1_Comp_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        OSC1_Comp_backup.enableState = 0u;
    }    
    
    OSC1_Comp_Stop();
    OSC1_Comp_SaveConfig();
}


/*******************************************************************************
* Function Name: OSC1_Comp_Wakeup
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
*  OSC1_Comp_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void OSC1_Comp_Wakeup(void) 
{
    OSC1_Comp_RestoreConfig();
    
    if(OSC1_Comp_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        OSC1_Comp_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
