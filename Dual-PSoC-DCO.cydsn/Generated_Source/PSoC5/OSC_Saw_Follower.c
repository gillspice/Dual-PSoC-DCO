/*******************************************************************************
* File Name: OSC_Saw_Follower.c
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

#include "OSC_Saw_Follower.h"

uint8 OSC_Saw_Follower_initVar = 0u;


/*******************************************************************************   
* Function Name: OSC_Saw_Follower_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  OSC_Saw_Follower_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC_Saw_Follower_Init(void) 
{
    OSC_Saw_Follower_SetPower(OSC_Saw_Follower_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: OSC_Saw_Follower_Enable
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
void OSC_Saw_Follower_Enable(void) 
{
    /* Enable negative charge pumps in ANIF */
    OSC_Saw_Follower_PUMP_CR1_REG  |= (OSC_Saw_Follower_PUMP_CR1_CLKSEL | OSC_Saw_Follower_PUMP_CR1_FORCE);

    /* Enable power to buffer in active mode */
    OSC_Saw_Follower_PM_ACT_CFG_REG |= OSC_Saw_Follower_ACT_PWR_EN;

    /* Enable power to buffer in alternative active mode */
    OSC_Saw_Follower_PM_STBY_CFG_REG |= OSC_Saw_Follower_STBY_PWR_EN;
}


/*******************************************************************************
* Function Name:   OSC_Saw_Follower_Start
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
*  OSC_Saw_Follower_initVar: Used to check the initial configuration, modified 
*  when this function is called for the first time.
*
*******************************************************************************/
void OSC_Saw_Follower_Start(void) 
{
    if(OSC_Saw_Follower_initVar == 0u)
    {
        OSC_Saw_Follower_initVar = 1u;
        OSC_Saw_Follower_Init();
    }

    OSC_Saw_Follower_Enable();
}


/*******************************************************************************
* Function Name: OSC_Saw_Follower_Stop
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
void OSC_Saw_Follower_Stop(void) 
{
    /* Disable power to buffer in active mode template */
    OSC_Saw_Follower_PM_ACT_CFG_REG &= (uint8)(~OSC_Saw_Follower_ACT_PWR_EN);

    /* Disable power to buffer in alternative active mode template */
    OSC_Saw_Follower_PM_STBY_CFG_REG &= (uint8)(~OSC_Saw_Follower_STBY_PWR_EN);
    
    /* Disable negative charge pumps for ANIF only if all ABuf is turned OFF */
    if(OSC_Saw_Follower_PM_ACT_CFG_REG == 0u)
    {
        OSC_Saw_Follower_PUMP_CR1_REG &= (uint8)(~(OSC_Saw_Follower_PUMP_CR1_CLKSEL | OSC_Saw_Follower_PUMP_CR1_FORCE));
    }
}


/*******************************************************************************
* Function Name: OSC_Saw_Follower_SetPower
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
void OSC_Saw_Follower_SetPower(uint8 power) 
{
    #if (CY_PSOC3 || CY_PSOC5LP)
        OSC_Saw_Follower_CR_REG &= (uint8)(~OSC_Saw_Follower_PWR_MASK);
        OSC_Saw_Follower_CR_REG |= power & OSC_Saw_Follower_PWR_MASK;      /* Set device power */
    #else
        CYASSERT(OSC_Saw_Follower_HIGHPOWER == power);
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


/* [] END OF FILE */
