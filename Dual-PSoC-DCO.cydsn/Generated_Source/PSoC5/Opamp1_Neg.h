/*******************************************************************************
* File Name: Opamp1_Neg.h  
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

#if !defined(CY_PINS_Opamp1_Neg_H) /* Pins Opamp1_Neg_H */
#define CY_PINS_Opamp1_Neg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Opamp1_Neg_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Opamp1_Neg__PORT == 15 && ((Opamp1_Neg__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Opamp1_Neg_Write(uint8 value);
void    Opamp1_Neg_SetDriveMode(uint8 mode);
uint8   Opamp1_Neg_ReadDataReg(void);
uint8   Opamp1_Neg_Read(void);
void    Opamp1_Neg_SetInterruptMode(uint16 position, uint16 mode);
uint8   Opamp1_Neg_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Opamp1_Neg_SetDriveMode() function.
     *  @{
     */
        #define Opamp1_Neg_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Opamp1_Neg_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Opamp1_Neg_DM_RES_UP          PIN_DM_RES_UP
        #define Opamp1_Neg_DM_RES_DWN         PIN_DM_RES_DWN
        #define Opamp1_Neg_DM_OD_LO           PIN_DM_OD_LO
        #define Opamp1_Neg_DM_OD_HI           PIN_DM_OD_HI
        #define Opamp1_Neg_DM_STRONG          PIN_DM_STRONG
        #define Opamp1_Neg_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Opamp1_Neg_MASK               Opamp1_Neg__MASK
#define Opamp1_Neg_SHIFT              Opamp1_Neg__SHIFT
#define Opamp1_Neg_WIDTH              1u

/* Interrupt constants */
#if defined(Opamp1_Neg__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Opamp1_Neg_SetInterruptMode() function.
     *  @{
     */
        #define Opamp1_Neg_INTR_NONE      (uint16)(0x0000u)
        #define Opamp1_Neg_INTR_RISING    (uint16)(0x0001u)
        #define Opamp1_Neg_INTR_FALLING   (uint16)(0x0002u)
        #define Opamp1_Neg_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Opamp1_Neg_INTR_MASK      (0x01u) 
#endif /* (Opamp1_Neg__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Opamp1_Neg_PS                     (* (reg8 *) Opamp1_Neg__PS)
/* Data Register */
#define Opamp1_Neg_DR                     (* (reg8 *) Opamp1_Neg__DR)
/* Port Number */
#define Opamp1_Neg_PRT_NUM                (* (reg8 *) Opamp1_Neg__PRT) 
/* Connect to Analog Globals */                                                  
#define Opamp1_Neg_AG                     (* (reg8 *) Opamp1_Neg__AG)                       
/* Analog MUX bux enable */
#define Opamp1_Neg_AMUX                   (* (reg8 *) Opamp1_Neg__AMUX) 
/* Bidirectional Enable */                                                        
#define Opamp1_Neg_BIE                    (* (reg8 *) Opamp1_Neg__BIE)
/* Bit-mask for Aliased Register Access */
#define Opamp1_Neg_BIT_MASK               (* (reg8 *) Opamp1_Neg__BIT_MASK)
/* Bypass Enable */
#define Opamp1_Neg_BYP                    (* (reg8 *) Opamp1_Neg__BYP)
/* Port wide control signals */                                                   
#define Opamp1_Neg_CTL                    (* (reg8 *) Opamp1_Neg__CTL)
/* Drive Modes */
#define Opamp1_Neg_DM0                    (* (reg8 *) Opamp1_Neg__DM0) 
#define Opamp1_Neg_DM1                    (* (reg8 *) Opamp1_Neg__DM1)
#define Opamp1_Neg_DM2                    (* (reg8 *) Opamp1_Neg__DM2) 
/* Input Buffer Disable Override */
#define Opamp1_Neg_INP_DIS                (* (reg8 *) Opamp1_Neg__INP_DIS)
/* LCD Common or Segment Drive */
#define Opamp1_Neg_LCD_COM_SEG            (* (reg8 *) Opamp1_Neg__LCD_COM_SEG)
/* Enable Segment LCD */
#define Opamp1_Neg_LCD_EN                 (* (reg8 *) Opamp1_Neg__LCD_EN)
/* Slew Rate Control */
#define Opamp1_Neg_SLW                    (* (reg8 *) Opamp1_Neg__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Opamp1_Neg_PRTDSI__CAPS_SEL       (* (reg8 *) Opamp1_Neg__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Opamp1_Neg_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Opamp1_Neg__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Opamp1_Neg_PRTDSI__OE_SEL0        (* (reg8 *) Opamp1_Neg__PRTDSI__OE_SEL0) 
#define Opamp1_Neg_PRTDSI__OE_SEL1        (* (reg8 *) Opamp1_Neg__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Opamp1_Neg_PRTDSI__OUT_SEL0       (* (reg8 *) Opamp1_Neg__PRTDSI__OUT_SEL0) 
#define Opamp1_Neg_PRTDSI__OUT_SEL1       (* (reg8 *) Opamp1_Neg__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Opamp1_Neg_PRTDSI__SYNC_OUT       (* (reg8 *) Opamp1_Neg__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Opamp1_Neg__SIO_CFG)
    #define Opamp1_Neg_SIO_HYST_EN        (* (reg8 *) Opamp1_Neg__SIO_HYST_EN)
    #define Opamp1_Neg_SIO_REG_HIFREQ     (* (reg8 *) Opamp1_Neg__SIO_REG_HIFREQ)
    #define Opamp1_Neg_SIO_CFG            (* (reg8 *) Opamp1_Neg__SIO_CFG)
    #define Opamp1_Neg_SIO_DIFF           (* (reg8 *) Opamp1_Neg__SIO_DIFF)
#endif /* (Opamp1_Neg__SIO_CFG) */

/* Interrupt Registers */
#if defined(Opamp1_Neg__INTSTAT)
    #define Opamp1_Neg_INTSTAT            (* (reg8 *) Opamp1_Neg__INTSTAT)
    #define Opamp1_Neg_SNAP               (* (reg8 *) Opamp1_Neg__SNAP)
    
	#define Opamp1_Neg_0_INTTYPE_REG 		(* (reg8 *) Opamp1_Neg__0__INTTYPE)
#endif /* (Opamp1_Neg__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Opamp1_Neg_H */


/* [] END OF FILE */
