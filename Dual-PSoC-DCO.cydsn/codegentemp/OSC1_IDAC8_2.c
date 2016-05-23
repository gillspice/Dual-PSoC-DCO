/*******************************************************************************
* File Name: OSC1_IDAC8_2.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the 8-bit Current 
*  DAC (IDAC8) User Module.
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

#include "cytypes.h"
#include "OSC1_IDAC8_2.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 OSC1_IDAC8_2_initVar = 0u;


#if (CY_PSOC5A)
    static OSC1_IDAC8_2_LOWPOWER_BACKUP_STRUCT  OSC1_IDAC8_2_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 OSC1_IDAC8_2_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void OSC1_IDAC8_2_Init(void) 
{
    OSC1_IDAC8_2_CR0 = (OSC1_IDAC8_2_MODE_I | OSC1_IDAC8_2_DEFAULT_RANGE );

    /* Set default data source */
    #if(OSC1_IDAC8_2_DEFAULT_DATA_SRC != 0u )    
        OSC1_IDAC8_2_CR1 = (OSC1_IDAC8_2_DEFAULT_CNTL | OSC1_IDAC8_2_DACBUS_ENABLE);
    #else
        OSC1_IDAC8_2_CR1 = (OSC1_IDAC8_2_DEFAULT_CNTL | OSC1_IDAC8_2_DACBUS_DISABLE);
    #endif /* (OSC1_IDAC8_2_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(OSC1_IDAC8_2_DEFAULT_POLARITY == OSC1_IDAC8_2_HARDWARE_CONTROLLED)
        OSC1_IDAC8_2_CR1 |= OSC1_IDAC8_2_IDIR_SRC_UDB;
    #else
        OSC1_IDAC8_2_CR1 |= OSC1_IDAC8_2_DEFAULT_POLARITY;
    #endif/* (OSC1_IDAC8_2_DEFAULT_POLARITY == OSC1_IDAC8_2_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(OSC1_IDAC8_2_HARDWARE_ENABLE != 0u ) 
        OSC1_IDAC8_2_CR1 |= OSC1_IDAC8_2_IDIR_CTL_UDB;
    #endif /* (OSC1_IDAC8_2_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(OSC1_IDAC8_2_DEFAULT_STRB != 0u)
        OSC1_IDAC8_2_Strobe |= OSC1_IDAC8_2_STRB_EN;
    #endif /* (OSC1_IDAC8_2_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    OSC1_IDAC8_2_SetSpeed(OSC1_IDAC8_2_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    OSC1_IDAC8_2_DacTrim();
    
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_Enable
********************************************************************************
* Summary:
*  Enable the IDAC8
* 
* Parameters:
*  void:
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void OSC1_IDAC8_2_Enable(void) 
{
    OSC1_IDAC8_2_PWRMGR |= OSC1_IDAC8_2_ACT_PWR_EN;
    OSC1_IDAC8_2_STBY_PWRMGR |= OSC1_IDAC8_2_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(OSC1_IDAC8_2_restoreReg == 1u)
        {
            OSC1_IDAC8_2_CR0 = OSC1_IDAC8_2_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            OSC1_IDAC8_2_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_Start
********************************************************************************
* Summary:
*  Set power level then turn on IDAC8.
*
* Parameters:  
*  power: Sets power level between off (0) and (3) high power
*
* Return:
*  (void)
*
* Global variables:
*  OSC1_IDAC8_2_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void OSC1_IDAC8_2_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( OSC1_IDAC8_2_initVar == 0u)  
    {
        OSC1_IDAC8_2_Init();
        
        OSC1_IDAC8_2_initVar = 1u;
    }
   
    /* Enable power to DAC */
    OSC1_IDAC8_2_Enable();

    /* Set default value */
    OSC1_IDAC8_2_SetValue(OSC1_IDAC8_2_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_Stop
********************************************************************************
* Summary:
*  Powers down IDAC8 to lowest power state.
*
* Parameters:
*  (void)
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void OSC1_IDAC8_2_Stop(void) 
{
    /* Disble power to DAC */
    OSC1_IDAC8_2_PWRMGR &= (uint8)(~OSC1_IDAC8_2_ACT_PWR_EN);
    OSC1_IDAC8_2_STBY_PWRMGR &= (uint8)(~OSC1_IDAC8_2_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        OSC1_IDAC8_2_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        OSC1_IDAC8_2_lowPowerBackup.DACCR0Reg = OSC1_IDAC8_2_CR0;
        OSC1_IDAC8_2_CR0 = (OSC1_IDAC8_2_MODE_I | OSC1_IDAC8_2_RANGE_3 | OSC1_IDAC8_2_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_SetSpeed
********************************************************************************
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void OSC1_IDAC8_2_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    OSC1_IDAC8_2_CR0 &= (uint8)(~OSC1_IDAC8_2_HS_MASK);
    OSC1_IDAC8_2_CR0 |=  ( speed & OSC1_IDAC8_2_HS_MASK);
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_SetPolarity
********************************************************************************
* Summary:
*  Sets IDAC to Sink or Source current.
*  
* Parameters:
*  Polarity: Sets the IDAC to Sink or Source 
*  0x00 - Source
*  0x04 - Sink
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
#if(OSC1_IDAC8_2_DEFAULT_POLARITY != OSC1_IDAC8_2_HARDWARE_CONTROLLED)
    void OSC1_IDAC8_2_SetPolarity(uint8 polarity) 
    {
        OSC1_IDAC8_2_CR1 &= (uint8)(~OSC1_IDAC8_2_IDIR_MASK);                /* clear polarity bit */
        OSC1_IDAC8_2_CR1 |= (polarity & OSC1_IDAC8_2_IDIR_MASK);             /* set new value */
    
        OSC1_IDAC8_2_DacTrim();
    }
#endif/*(OSC1_IDAC8_2_DEFAULT_POLARITY != OSC1_IDAC8_2_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_SetRange
********************************************************************************
* Summary:
*  Set current range
*
* Parameters:
*  Range: Sets on of four valid ranges.
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void OSC1_IDAC8_2_SetRange(uint8 range) 
{
    OSC1_IDAC8_2_CR0 &= (uint8)(~OSC1_IDAC8_2_RANGE_MASK);       /* Clear existing mode */
    OSC1_IDAC8_2_CR0 |= ( range & OSC1_IDAC8_2_RANGE_MASK );     /*  Set Range  */
    OSC1_IDAC8_2_DacTrim();
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_SetValue
********************************************************************************
* Summary:
*  Set DAC value
*
* Parameters:
*  value: Sets DAC value between 0 and 255.
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void OSC1_IDAC8_2_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 OSC1_IDAC8_2_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    OSC1_IDAC8_2_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        OSC1_IDAC8_2_Data = value;
        CyExitCriticalSection(OSC1_IDAC8_2_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: OSC1_IDAC8_2_DacTrim
********************************************************************************
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  None
*
* Return:
*  (void) 
*
* Theory:
*  Trim values for the IDAC blocks are stored in the "Customer Table" area in 
*  Row 1 of the Hidden Flash.  There are 8 bytes of trim data for each 
*  IDAC block.
*  The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* Side Effects:
*
*******************************************************************************/
void OSC1_IDAC8_2_DacTrim(void) 
{
    uint8 mode;

    mode = ((OSC1_IDAC8_2_CR0 & OSC1_IDAC8_2_RANGE_MASK) >> 1u);
    
    if((OSC1_IDAC8_2_IDIR_MASK & OSC1_IDAC8_2_CR1) == OSC1_IDAC8_2_IDIR_SINK)
    {
        mode++;
    }

    OSC1_IDAC8_2_TR = CY_GET_XTND_REG8((uint8 *)(OSC1_IDAC8_2_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
