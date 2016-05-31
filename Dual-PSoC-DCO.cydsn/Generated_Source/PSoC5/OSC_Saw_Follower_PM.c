/*******************************************************************************
* File Name: OSC_Saw_Follower_PM.c
* Version 1.90
*
* Description:
*  This file provides the power management source code to the API for the 
*  OpAmp (Analog Buffer) component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "OSC_Saw_Follower.h"

static OSC_Saw_Follower_BACKUP_STRUCT  OSC_Saw_Follower_backup;


/*******************************************************************************  
* Function Name: OSC_Saw_Follower_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void OSC_Saw_Follower_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: OSC_Saw_Follower_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration registers.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC_Saw_Follower_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: OSC_Saw_Follower_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC_Saw_Follower_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void OSC_Saw_Follower_Sleep(void) 
{
    /* Save OpAmp enable state */
    if((OSC_Saw_Follower_PM_ACT_CFG_REG & OSC_Saw_Follower_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        OSC_Saw_Follower_backup.enableState = 1u;
         /* Stops the component */
         OSC_Saw_Follower_Stop();
    }
    else
    {
        /* Component is disabled */
        OSC_Saw_Follower_backup.enableState = 0u;
    }
    /* Saves the configuration */
    OSC_Saw_Follower_SaveConfig();
}


/*******************************************************************************  
* Function Name: OSC_Saw_Follower_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC_Saw_Follower_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void OSC_Saw_Follower_Wakeup(void) 
{
    /* Restore the user configuration */
    OSC_Saw_Follower_RestoreConfig();

    /* Enables the component operation */
    if(OSC_Saw_Follower_backup.enableState == 1u)
    {
        OSC_Saw_Follower_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
