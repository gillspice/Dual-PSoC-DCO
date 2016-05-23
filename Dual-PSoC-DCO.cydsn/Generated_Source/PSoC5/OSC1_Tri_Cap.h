/*******************************************************************************
* File Name: OSC1_Tri_Cap.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_OSC1_Tri_Cap_H) /* Pins OSC1_Tri_Cap_H */
#define CY_PINS_OSC1_Tri_Cap_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OSC1_Tri_Cap_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OSC1_Tri_Cap__PORT == 15 && ((OSC1_Tri_Cap__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    OSC1_Tri_Cap_Write(uint8 value);
void    OSC1_Tri_Cap_SetDriveMode(uint8 mode);
uint8   OSC1_Tri_Cap_ReadDataReg(void);
uint8   OSC1_Tri_Cap_Read(void);
void    OSC1_Tri_Cap_SetInterruptMode(uint16 position, uint16 mode);
uint8   OSC1_Tri_Cap_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the OSC1_Tri_Cap_SetDriveMode() function.
     *  @{
     */
        #define OSC1_Tri_Cap_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define OSC1_Tri_Cap_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define OSC1_Tri_Cap_DM_RES_UP          PIN_DM_RES_UP
        #define OSC1_Tri_Cap_DM_RES_DWN         PIN_DM_RES_DWN
        #define OSC1_Tri_Cap_DM_OD_LO           PIN_DM_OD_LO
        #define OSC1_Tri_Cap_DM_OD_HI           PIN_DM_OD_HI
        #define OSC1_Tri_Cap_DM_STRONG          PIN_DM_STRONG
        #define OSC1_Tri_Cap_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define OSC1_Tri_Cap_MASK               OSC1_Tri_Cap__MASK
#define OSC1_Tri_Cap_SHIFT              OSC1_Tri_Cap__SHIFT
#define OSC1_Tri_Cap_WIDTH              1u

/* Interrupt constants */
#if defined(OSC1_Tri_Cap__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in OSC1_Tri_Cap_SetInterruptMode() function.
     *  @{
     */
        #define OSC1_Tri_Cap_INTR_NONE      (uint16)(0x0000u)
        #define OSC1_Tri_Cap_INTR_RISING    (uint16)(0x0001u)
        #define OSC1_Tri_Cap_INTR_FALLING   (uint16)(0x0002u)
        #define OSC1_Tri_Cap_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define OSC1_Tri_Cap_INTR_MASK      (0x01u) 
#endif /* (OSC1_Tri_Cap__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OSC1_Tri_Cap_PS                     (* (reg8 *) OSC1_Tri_Cap__PS)
/* Data Register */
#define OSC1_Tri_Cap_DR                     (* (reg8 *) OSC1_Tri_Cap__DR)
/* Port Number */
#define OSC1_Tri_Cap_PRT_NUM                (* (reg8 *) OSC1_Tri_Cap__PRT) 
/* Connect to Analog Globals */                                                  
#define OSC1_Tri_Cap_AG                     (* (reg8 *) OSC1_Tri_Cap__AG)                       
/* Analog MUX bux enable */
#define OSC1_Tri_Cap_AMUX                   (* (reg8 *) OSC1_Tri_Cap__AMUX) 
/* Bidirectional Enable */                                                        
#define OSC1_Tri_Cap_BIE                    (* (reg8 *) OSC1_Tri_Cap__BIE)
/* Bit-mask for Aliased Register Access */
#define OSC1_Tri_Cap_BIT_MASK               (* (reg8 *) OSC1_Tri_Cap__BIT_MASK)
/* Bypass Enable */
#define OSC1_Tri_Cap_BYP                    (* (reg8 *) OSC1_Tri_Cap__BYP)
/* Port wide control signals */                                                   
#define OSC1_Tri_Cap_CTL                    (* (reg8 *) OSC1_Tri_Cap__CTL)
/* Drive Modes */
#define OSC1_Tri_Cap_DM0                    (* (reg8 *) OSC1_Tri_Cap__DM0) 
#define OSC1_Tri_Cap_DM1                    (* (reg8 *) OSC1_Tri_Cap__DM1)
#define OSC1_Tri_Cap_DM2                    (* (reg8 *) OSC1_Tri_Cap__DM2) 
/* Input Buffer Disable Override */
#define OSC1_Tri_Cap_INP_DIS                (* (reg8 *) OSC1_Tri_Cap__INP_DIS)
/* LCD Common or Segment Drive */
#define OSC1_Tri_Cap_LCD_COM_SEG            (* (reg8 *) OSC1_Tri_Cap__LCD_COM_SEG)
/* Enable Segment LCD */
#define OSC1_Tri_Cap_LCD_EN                 (* (reg8 *) OSC1_Tri_Cap__LCD_EN)
/* Slew Rate Control */
#define OSC1_Tri_Cap_SLW                    (* (reg8 *) OSC1_Tri_Cap__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OSC1_Tri_Cap_PRTDSI__CAPS_SEL       (* (reg8 *) OSC1_Tri_Cap__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OSC1_Tri_Cap_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OSC1_Tri_Cap__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OSC1_Tri_Cap_PRTDSI__OE_SEL0        (* (reg8 *) OSC1_Tri_Cap__PRTDSI__OE_SEL0) 
#define OSC1_Tri_Cap_PRTDSI__OE_SEL1        (* (reg8 *) OSC1_Tri_Cap__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OSC1_Tri_Cap_PRTDSI__OUT_SEL0       (* (reg8 *) OSC1_Tri_Cap__PRTDSI__OUT_SEL0) 
#define OSC1_Tri_Cap_PRTDSI__OUT_SEL1       (* (reg8 *) OSC1_Tri_Cap__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OSC1_Tri_Cap_PRTDSI__SYNC_OUT       (* (reg8 *) OSC1_Tri_Cap__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(OSC1_Tri_Cap__SIO_CFG)
    #define OSC1_Tri_Cap_SIO_HYST_EN        (* (reg8 *) OSC1_Tri_Cap__SIO_HYST_EN)
    #define OSC1_Tri_Cap_SIO_REG_HIFREQ     (* (reg8 *) OSC1_Tri_Cap__SIO_REG_HIFREQ)
    #define OSC1_Tri_Cap_SIO_CFG            (* (reg8 *) OSC1_Tri_Cap__SIO_CFG)
    #define OSC1_Tri_Cap_SIO_DIFF           (* (reg8 *) OSC1_Tri_Cap__SIO_DIFF)
#endif /* (OSC1_Tri_Cap__SIO_CFG) */

/* Interrupt Registers */
#if defined(OSC1_Tri_Cap__INTSTAT)
    #define OSC1_Tri_Cap_INTSTAT            (* (reg8 *) OSC1_Tri_Cap__INTSTAT)
    #define OSC1_Tri_Cap_SNAP               (* (reg8 *) OSC1_Tri_Cap__SNAP)
    
	#define OSC1_Tri_Cap_0_INTTYPE_REG 		(* (reg8 *) OSC1_Tri_Cap__0__INTTYPE)
#endif /* (OSC1_Tri_Cap__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OSC1_Tri_Cap_H */


/* [] END OF FILE */
