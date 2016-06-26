/*******************************************************************************
* File Name: OSC2_IDAC8_SAW_1.c
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


#include "OSC2_IDAC8_SAW_1.h"

static OSC2_IDAC8_SAW_1_backupStruct OSC2_IDAC8_SAW_1_backup;


/*******************************************************************************
* Function Name: OSC2_IDAC8_SAW_1_SaveConfig
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
void OSC2_IDAC8_SAW_1_SaveConfig(void) 
{
    if (!((OSC2_IDAC8_SAW_1_CR1 & OSC2_IDAC8_SAW_1_SRC_MASK) == OSC2_IDAC8_SAW_1_SRC_UDB))
    {
        OSC2_IDAC8_SAW_1_backup.data_value = OSC2_IDAC8_SAW_1_Data;
    }
}


/*******************************************************************************
* Function Name: OSC2_IDAC8_SAW_1_RestoreConfig
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
void OSC2_IDAC8_SAW_1_RestoreConfig(void) 
{
    if (!((OSC2_IDAC8_SAW_1_CR1 & OSC2_IDAC8_SAW_1_SRC_MASK) == OSC2_IDAC8_SAW_1_SRC_UDB))
    {
        if((OSC2_IDAC8_SAW_1_Strobe & OSC2_IDAC8_SAW_1_STRB_MASK) == OSC2_IDAC8_SAW_1_STRB_EN)
        {
            OSC2_IDAC8_SAW_1_Strobe &= (uint8)(~OSC2_IDAC8_SAW_1_STRB_MASK);
            OSC2_IDAC8_SAW_1_Data = OSC2_IDAC8_SAW_1_backup.data_value;
            OSC2_IDAC8_SAW_1_Strobe |= OSC2_IDAC8_SAW_1_STRB_EN;
        }
        else
        {
            OSC2_IDAC8_SAW_1_Data = OSC2_IDAC8_SAW_1_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: OSC2_IDAC8_SAW_1_Sleep
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
*  OSC2_IDAC8_SAW_1_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void OSC2_IDAC8_SAW_1_Sleep(void) 
{
    if(OSC2_IDAC8_SAW_1_ACT_PWR_EN == (OSC2_IDAC8_SAW_1_PWRMGR & OSC2_IDAC8_SAW_1_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        OSC2_IDAC8_SAW_1_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        OSC2_IDAC8_SAW_1_backup.enableState = 0u;
    }

    OSC2_IDAC8_SAW_1_Stop();
    OSC2_IDAC8_SAW_1_SaveConfig();
}


/*******************************************************************************
* Function Name: OSC2_IDAC8_SAW_1_Wakeup
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
*  OSC2_IDAC8_SAW_1_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void OSC2_IDAC8_SAW_1_Wakeup(void) 
{
    OSC2_IDAC8_SAW_1_RestoreConfig();
    
    if(OSC2_IDAC8_SAW_1_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        OSC2_IDAC8_SAW_1_Enable();
        
        /* Set the data register */
        OSC2_IDAC8_SAW_1_SetValue(OSC2_IDAC8_SAW_1_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
