/*******************************************************************************
* File Name: OSC1_IDAC8_2.c
* Version 2.0
*
* Description:
*  This file provides the power management source code to API for the
*  IDAC8.
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


#include "OSC1_IDAC8_2.h"

static OSC1_IDAC8_2_backupStruct OSC1_IDAC8_2_backup;


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_IDAC8_2_SaveConfig(void) 
{
    if (!((OSC1_IDAC8_2_CR1 & OSC1_IDAC8_2_SRC_MASK) == OSC1_IDAC8_2_SRC_UDB))
    {
        OSC1_IDAC8_2_backup.data_value = OSC1_IDAC8_2_Data;
    }
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_RestoreConfig
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
*******************************************************************************/
void OSC1_IDAC8_2_RestoreConfig(void) 
{
    if (!((OSC1_IDAC8_2_CR1 & OSC1_IDAC8_2_SRC_MASK) == OSC1_IDAC8_2_SRC_UDB))
    {
        if((OSC1_IDAC8_2_Strobe & OSC1_IDAC8_2_STRB_MASK) == OSC1_IDAC8_2_STRB_EN)
        {
            OSC1_IDAC8_2_Strobe &= (uint8)(~OSC1_IDAC8_2_STRB_MASK);
            OSC1_IDAC8_2_Data = OSC1_IDAC8_2_backup.data_value;
            OSC1_IDAC8_2_Strobe |= OSC1_IDAC8_2_STRB_EN;
        }
        else
        {
            OSC1_IDAC8_2_Data = OSC1_IDAC8_2_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_Sleep
********************************************************************************
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
*  OSC1_IDAC8_2_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void OSC1_IDAC8_2_Sleep(void) 
{
    if(OSC1_IDAC8_2_ACT_PWR_EN == (OSC1_IDAC8_2_PWRMGR & OSC1_IDAC8_2_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        OSC1_IDAC8_2_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        OSC1_IDAC8_2_backup.enableState = 0u;
    }

    OSC1_IDAC8_2_Stop();
    OSC1_IDAC8_2_SaveConfig();
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_Wakeup
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
*  OSC1_IDAC8_2_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void OSC1_IDAC8_2_Wakeup(void) 
{
    OSC1_IDAC8_2_RestoreConfig();
    
    if(OSC1_IDAC8_2_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        OSC1_IDAC8_2_Enable();
        
        /* Set the data register */
        OSC1_IDAC8_2_SetValue(OSC1_IDAC8_2_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
