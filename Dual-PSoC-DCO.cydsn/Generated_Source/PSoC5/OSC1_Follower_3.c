/*******************************************************************************
* File Name: OSC1_Follower_3.c
* Version 1.90
*
* Description:
*  This file provides the source code to the API for OpAmp (Analog Buffer) 
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "OSC1_Follower_3.h"

uint8 OSC1_Follower_3_initVar = 0u;


/*******************************************************************************   
* Function Name: OSC1_Follower_3_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  OSC1_Follower_3_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Follower_3_Init(void) 
{
    OSC1_Follower_3_SetPower(OSC1_Follower_3_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: OSC1_Follower_3_Enable
********************************************************************************
*
* Summary:
*  Enables the OpAmp block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Follower_3_Enable(void) 
{
    /* Enable negative charge pumps in ANIF */
    OSC1_Follower_3_PUMP_CR1_REG  |= (OSC1_Follower_3_PUMP_CR1_CLKSEL | OSC1_Follower_3_PUMP_CR1_FORCE);

    /* Enable power to buffer in active mode */
    OSC1_Follower_3_PM_ACT_CFG_REG |= OSC1_Follower_3_ACT_PWR_EN;

    /* Enable power to buffer in alternative active mode */
    OSC1_Follower_3_PM_STBY_CFG_REG |= OSC1_Follower_3_STBY_PWR_EN;
}


/*******************************************************************************
* Function Name:   OSC1_Follower_3_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Buffer with the default values and 
*  sets the power to the given level. A power level of 0, is same as 
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OSC1_Follower_3_initVar: Used to check the initial configuration, modified 
*  when this function is called for the first time.
*
*******************************************************************************/
void OSC1_Follower_3_Start(void) 
{
    if(OSC1_Follower_3_initVar == 0u)
    {
        OSC1_Follower_3_initVar = 1u;
        OSC1_Follower_3_Init();
    }

    OSC1_Follower_3_Enable();
}


/*******************************************************************************
* Function Name: OSC1_Follower_3_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Follower_3_Stop(void) 
{
    /* Disable power to buffer in active mode template */
    OSC1_Follower_3_PM_ACT_CFG_REG &= (uint8)(~OSC1_Follower_3_ACT_PWR_EN);

    /* Disable power to buffer in alternative active mode template */
    OSC1_Follower_3_PM_STBY_CFG_REG &= (uint8)(~OSC1_Follower_3_STBY_PWR_EN);
    
    /* Disable negative charge pumps for ANIF only if all ABuf is turned OFF */
    if(OSC1_Follower_3_PM_ACT_CFG_REG == 0u)
    {
        OSC1_Follower_3_PUMP_CR1_REG &= (uint8)(~(OSC1_Follower_3_PUMP_CR1_CLKSEL | OSC1_Follower_3_PUMP_CR1_FORCE));
    }
}


/*******************************************************************************
* Function Name: OSC1_Follower_3_SetPower
********************************************************************************
*
* Summary:
*  Sets power level of Analog buffer.
*
* Parameters: 
*  power: PSoC3: Sets power level between low (1) and high power (3).
*         PSoC5: Sets power level High (0)
*
* Return:
*  void
*
**********************************************************************************/
void OSC1_Follower_3_SetPower(uint8 power) 
{
    #if (CY_PSOC3 || CY_PSOC5LP)
        OSC1_Follower_3_CR_REG &= (uint8)(~OSC1_Follower_3_PWR_MASK);
        OSC1_Follower_3_CR_REG |= power & OSC1_Follower_3_PWR_MASK;      /* Set device power */
    #else
        CYASSERT(OSC1_Follower_3_HIGHPOWER == power);
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


/* [] END OF FILE */
