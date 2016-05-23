/*******************************************************************************
* File Name: OSC1_Inverter_1.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the inverting PGA 
*  Component.
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

#include "OSC1_Inverter_1.h"

#if (!CY_PSOC5A)
    #if (CYDEV_VARIABLE_VDDA == 1u)
        #include "CyScBoostClk.h"
    #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
#endif /* (!CY_PSOC5A) */

#if (CY_PSOC5A)
    static OSC1_Inverter_1_BACKUP_STRUCT  OSC1_Inverter_1_P5backup;
#endif /* (CY_PSOC5A) */

uint8 OSC1_Inverter_1_initVar = 0u;



/*******************************************************************************   
* Function Name: OSC1_Inverter_1_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  OSC1_Inverter_1_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Inverter_1_Init(void) 
{
    /* Set PGA mode */
    OSC1_Inverter_1_CR0_REG = OSC1_Inverter_1_MODE_PGA;

    /* Set inverting PGA mode  and reference mode */
    OSC1_Inverter_1_CR1_REG &= (uint8)(~OSC1_Inverter_1_PGA_INV);

    /* Set gain and compensation */
    OSC1_Inverter_1_SetGain(OSC1_Inverter_1_DEFAULT_GAIN);

    /* Set power */
    OSC1_Inverter_1_SetPower(OSC1_Inverter_1_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: OSC1_Inverter_1_Enable
********************************************************************************
*
* Summary:
*  Enables the inverting PGA block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Inverter_1_Enable(void) 
{
    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modifications in stop() API */
    #if (CY_PSOC5A)
        if(OSC1_Inverter_1_P5backup.enableState == 1u)
        {
            OSC1_Inverter_1_CR1_REG = OSC1_Inverter_1_P5backup.scCR1Reg;
            OSC1_Inverter_1_CR2_REG = OSC1_Inverter_1_P5backup.scCR2Reg;
            OSC1_Inverter_1_P5backup.enableState = 0u;
        }
    #endif /* CY_PSOC5A */
    
    /* Enable power to the Amp in Active mode */
    OSC1_Inverter_1_PM_ACT_CFG_REG |= OSC1_Inverter_1_ACT_PWR_EN;

    /* Enable power to the Amp in Alternative active mode  */
    OSC1_Inverter_1_PM_STBY_CFG_REG |= OSC1_Inverter_1_STBY_PWR_EN;
    
    OSC1_Inverter_1_PUMP_CR1_REG |= OSC1_Inverter_1_PUMP_CR1_SC_CLKSEL;
    
    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            if(CyScPumpEnabled == 1u)
            {
                OSC1_Inverter_1_BSTCLK_REG &= (uint8)(~OSC1_Inverter_1_BST_CLK_INDEX_MASK);
                OSC1_Inverter_1_BSTCLK_REG |= OSC1_Inverter_1_BST_CLK_EN | CyScBoostClk__INDEX;
                OSC1_Inverter_1_SC_MISC_REG |= OSC1_Inverter_1_PUMP_FORCE;
                CyScBoostClk_Start();
            }
            else
            {
                OSC1_Inverter_1_BSTCLK_REG &= (uint8)(~OSC1_Inverter_1_BST_CLK_EN);
                OSC1_Inverter_1_SC_MISC_REG &= (uint8)(~OSC1_Inverter_1_PUMP_FORCE);
            }
        #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
    #endif /* (!CY_PSOC5A) */
}


/*******************************************************************************
* Function Name: OSC1_Inverter_1_Start
********************************************************************************
*
* Summary:
*  The start function initializes the inverting PGA with the default values,
*  and sets the power to the given level.A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*  This function modifies the global variable OSC1_Inverter_1_initVar: which 
*  defines where component's configuration are taken from the customizer 
*  (equals 0) or parameters changed by API will be used instead (equals 1).
*
*******************************************************************************/
void OSC1_Inverter_1_Start(void) 
{

    if(OSC1_Inverter_1_initVar == 0u)
    {
        OSC1_Inverter_1_initVar = 1u;
        OSC1_Inverter_1_Init();
    }
    
    OSC1_Inverter_1_Enable();
}


/*******************************************************************************
* Function Name: OSC1_Inverter_1_Stop
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
void OSC1_Inverter_1_Stop(void) 
{
    /* Disble power to the Amp in Active mode*/
    OSC1_Inverter_1_PM_ACT_CFG_REG &= (uint8)(~OSC1_Inverter_1_ACT_PWR_EN);

    /* Disble power to the Amp in Alternative active mode*/
    OSC1_Inverter_1_PM_STBY_CFG_REG &= (uint8)(~OSC1_Inverter_1_STBY_PWR_EN);

    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            OSC1_Inverter_1_BSTCLK_REG &= (uint8)(~OSC1_Inverter_1_BST_CLK_EN);
            /* Disable pumps only if there aren't any SC block in use */
            if ((OSC1_Inverter_1_PM_ACT_CFG_REG & OSC1_Inverter_1_PM_ACT_CFG_MASK) == 0u)
            {
                OSC1_Inverter_1_SC_MISC_REG &= (uint8)(~OSC1_Inverter_1_PUMP_FORCE);
                OSC1_Inverter_1_PUMP_CR1_REG &= (uint8)(~OSC1_Inverter_1_PUMP_CR1_SC_CLKSEL);
                CyScBoostClk_Stop();
            }
        #endif /* CYDEV_VARIABLE_VDDA == 1u */
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    
    /* This sets PGA in zero current mode and output routes are valid */
    #if (CY_PSOC5A)
        OSC1_Inverter_1_P5backup.scCR1Reg = OSC1_Inverter_1_CR1_REG;
        OSC1_Inverter_1_P5backup.scCR2Reg = OSC1_Inverter_1_CR2_REG;
        OSC1_Inverter_1_CR1_REG = 0x00u;
        OSC1_Inverter_1_CR2_REG = 0x00u;
        OSC1_Inverter_1_P5backup.enableState = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: OSC1_Inverter_1_SetPower
********************************************************************************
*
* Summary:
*  Set the power of the inverting PGA
*
* Parameters:
*  power:  Sets power level between (0) and (3) high power
*
* Return:
*  void 
*
*******************************************************************************/
void OSC1_Inverter_1_SetPower(uint8 power) 
{
    uint8 tmpCR;

    tmpCR = OSC1_Inverter_1_CR1_REG & (uint8)(~OSC1_Inverter_1_DRIVE_MASK);
    tmpCR |= (power & OSC1_Inverter_1_DRIVE_MASK);
    OSC1_Inverter_1_CR1_REG = tmpCR;
}


/*******************************************************************************
* Function Name: OSC1_Inverter_1_SetGain
********************************************************************************
*
* Summary:
*  This function sets values of the input and feedback resistors to set a 
*  specific gain of the amplifier.
*
* Parameters:
*  gain: Sets gain of amplifier.
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Inverter_1_SetGain(uint8 gain) 
{
    /* Constant array for gain settings */
    const uint8 OSC1_Inverter_1_GainArray[9] = { 
        (OSC1_Inverter_1_PGA_INV_GAIN_01 | OSC1_Inverter_1_BIAS_LOW), /* G=-1  */
        (OSC1_Inverter_1_PGA_INV_GAIN_03 | OSC1_Inverter_1_BIAS_LOW), /* G=-3  */
        (OSC1_Inverter_1_PGA_INV_GAIN_07 | OSC1_Inverter_1_BIAS_LOW), /* G=-7  */
        (OSC1_Inverter_1_PGA_INV_GAIN_15 | OSC1_Inverter_1_BIAS_LOW), /* G=-15 */
        (OSC1_Inverter_1_PGA_INV_GAIN_22 | OSC1_Inverter_1_BIAS_LOW), /* G=-22 */
        (OSC1_Inverter_1_PGA_INV_GAIN_24 | OSC1_Inverter_1_BIAS_LOW), /* G=-24 */
        (OSC1_Inverter_1_PGA_INV_GAIN_31 | OSC1_Inverter_1_BIAS_LOW), /* G=-31 */
        (OSC1_Inverter_1_PGA_INV_GAIN_47 | OSC1_Inverter_1_BIAS_LOW), /* G=-47 */
        (OSC1_Inverter_1_PGA_INV_GAIN_49 | OSC1_Inverter_1_BIAS_LOW)  /* G=-49 */
    };

    /* Constant array for gain compenstion settings */
    const uint8 OSC1_Inverter_1_GainComp[9] = { 
        ( OSC1_Inverter_1_COMP_4P35PF  | (uint8)( OSC1_Inverter_1_REDC_00 >> 2 )), /* G=-1  */
        ( OSC1_Inverter_1_COMP_4P35PF  | (uint8)( OSC1_Inverter_1_REDC_01 >> 2 )), /* G=-3  */
        ( OSC1_Inverter_1_COMP_3P0PF   | (uint8)( OSC1_Inverter_1_REDC_01 >> 2 )), /* G=-7  */
        ( OSC1_Inverter_1_COMP_3P0PF   | (uint8)( OSC1_Inverter_1_REDC_01 >> 2 )), /* G=-15 */
        ( OSC1_Inverter_1_COMP_3P6PF   | (uint8)( OSC1_Inverter_1_REDC_01 >> 2 )), /* G=-22 */
        ( OSC1_Inverter_1_COMP_3P0PF   | (uint8)( OSC1_Inverter_1_REDC_10 >> 2 )), /* G=-24 */
        ( OSC1_Inverter_1_COMP_3P6PF   | (uint8)( OSC1_Inverter_1_REDC_11 >> 2 )), /* G=-31 */
        ( OSC1_Inverter_1_COMP_3P6PF   | (uint8)( OSC1_Inverter_1_REDC_00 >> 2 )), /* G=-47 */
        ( OSC1_Inverter_1_COMP_3P6PF   | (uint8)( OSC1_Inverter_1_REDC_00 >> 2 ))  /* G=-49 */
    };
    
    
    /* Only set new gain if it is a valid gain */
    if( gain <= OSC1_Inverter_1_GAIN_MAX)
    {
        /* Clear resistors, redc, and bias */
        OSC1_Inverter_1_CR2_REG &= (uint8)(~(OSC1_Inverter_1_RVAL_MASK | OSC1_Inverter_1_R20_40B_MASK | 
                                      OSC1_Inverter_1_REDC_MASK | OSC1_Inverter_1_BIAS_MASK ));

        /* Set gain value resistors, redc comp, and bias */
        OSC1_Inverter_1_CR2_REG |= (OSC1_Inverter_1_GainArray[gain] |
                                ( (uint8)(OSC1_Inverter_1_GainComp[gain] << 2 ) & OSC1_Inverter_1_REDC_MASK) );

        /* Clear sc_comp  */
        OSC1_Inverter_1_CR1_REG &= (uint8)(~OSC1_Inverter_1_COMP_MASK);

        /* Set sc_comp  */
        OSC1_Inverter_1_CR1_REG |= ( OSC1_Inverter_1_GainComp[gain] | OSC1_Inverter_1_COMP_MASK );
    }
}


/* [] END OF FILE */
