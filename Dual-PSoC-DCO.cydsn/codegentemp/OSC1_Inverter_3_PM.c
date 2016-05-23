/*******************************************************************************
* File Name: OSC1_Inverter_3.c
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for the 
*  inverting PGA component.
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

#include "OSC1_Inverter_3.h"

static OSC1_Inverter_3_BACKUP_STRUCT  OSC1_Inverter_3_backup;


/*******************************************************************************  
* Function Name: OSC1_Inverter_3_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void OSC1_Inverter_3_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************
* Function Name: OSC1_Inverter_3_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
* 
* Parameters:
*  void.
* 
* Return:
*  void
*
*******************************************************************************/
void OSC1_Inverter_3_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************
* Function Name: OSC1_Inverter_3_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  OSC1_Inverter_3_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void OSC1_Inverter_3_Sleep(void) 
{
    /* Save PGA_Inv enable state */
    if((OSC1_Inverter_3_PM_ACT_CFG_REG & OSC1_Inverter_3_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        OSC1_Inverter_3_backup.enableState = 1u;
        /* Stop the configuration */
        OSC1_Inverter_3_Stop();
    }
    else
    {
        /* Component is disabled */
        OSC1_Inverter_3_backup.enableState = 0u;
    }
    /* Save the configurations */
    OSC1_Inverter_3_SaveConfig();
}


/*******************************************************************************
* Function Name: OSC1_Inverter_3_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  OSC1_Inverter_3_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void OSC1_Inverter_3_Wakeup(void) 
{
    /* Restore the register configurations */
    OSC1_Inverter_3_RestoreConfig();
    
    /* Enable's the component operation */
    if(OSC1_Inverter_3_backup.enableState == 1u)
    {
        OSC1_Inverter_3_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
