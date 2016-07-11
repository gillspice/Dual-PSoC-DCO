/*******************************************************************************
* File Name: GlitchClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_GlitchClock_H)
#define CY_CLOCK_GlitchClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void GlitchClock_Start(void) ;
void GlitchClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void GlitchClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void GlitchClock_StandbyPower(uint8 state) ;
void GlitchClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 GlitchClock_GetDividerRegister(void) ;
void GlitchClock_SetModeRegister(uint8 modeBitMask) ;
void GlitchClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 GlitchClock_GetModeRegister(void) ;
void GlitchClock_SetSourceRegister(uint8 clkSource) ;
uint8 GlitchClock_GetSourceRegister(void) ;
#if defined(GlitchClock__CFG3)
void GlitchClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 GlitchClock_GetPhaseRegister(void) ;
#endif /* defined(GlitchClock__CFG3) */

#define GlitchClock_Enable()                       GlitchClock_Start()
#define GlitchClock_Disable()                      GlitchClock_Stop()
#define GlitchClock_SetDivider(clkDivider)         GlitchClock_SetDividerRegister(clkDivider, 1u)
#define GlitchClock_SetDividerValue(clkDivider)    GlitchClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define GlitchClock_SetMode(clkMode)               GlitchClock_SetModeRegister(clkMode)
#define GlitchClock_SetSource(clkSource)           GlitchClock_SetSourceRegister(clkSource)
#if defined(GlitchClock__CFG3)
#define GlitchClock_SetPhase(clkPhase)             GlitchClock_SetPhaseRegister(clkPhase)
#define GlitchClock_SetPhaseValue(clkPhase)        GlitchClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(GlitchClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define GlitchClock_CLKEN              (* (reg8 *) GlitchClock__PM_ACT_CFG)
#define GlitchClock_CLKEN_PTR          ((reg8 *) GlitchClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define GlitchClock_CLKSTBY            (* (reg8 *) GlitchClock__PM_STBY_CFG)
#define GlitchClock_CLKSTBY_PTR        ((reg8 *) GlitchClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define GlitchClock_DIV_LSB            (* (reg8 *) GlitchClock__CFG0)
#define GlitchClock_DIV_LSB_PTR        ((reg8 *) GlitchClock__CFG0)
#define GlitchClock_DIV_PTR            ((reg16 *) GlitchClock__CFG0)

/* Clock MSB divider configuration register. */
#define GlitchClock_DIV_MSB            (* (reg8 *) GlitchClock__CFG1)
#define GlitchClock_DIV_MSB_PTR        ((reg8 *) GlitchClock__CFG1)

/* Mode and source configuration register */
#define GlitchClock_MOD_SRC            (* (reg8 *) GlitchClock__CFG2)
#define GlitchClock_MOD_SRC_PTR        ((reg8 *) GlitchClock__CFG2)

#if defined(GlitchClock__CFG3)
/* Analog clock phase configuration register */
#define GlitchClock_PHASE              (* (reg8 *) GlitchClock__CFG3)
#define GlitchClock_PHASE_PTR          ((reg8 *) GlitchClock__CFG3)
#endif /* defined(GlitchClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define GlitchClock_CLKEN_MASK         GlitchClock__PM_ACT_MSK
#define GlitchClock_CLKSTBY_MASK       GlitchClock__PM_STBY_MSK

/* CFG2 field masks */
#define GlitchClock_SRC_SEL_MSK        GlitchClock__CFG2_SRC_SEL_MASK
#define GlitchClock_MODE_MASK          (~(GlitchClock_SRC_SEL_MSK))

#if defined(GlitchClock__CFG3)
/* CFG3 phase mask */
#define GlitchClock_PHASE_MASK         GlitchClock__CFG3_PHASE_DLY_MASK
#endif /* defined(GlitchClock__CFG3) */

#endif /* CY_CLOCK_GlitchClock_H */


/* [] END OF FILE */
