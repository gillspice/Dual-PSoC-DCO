/*******************************************************************************
* File Name: Pulse4.h  
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

#if !defined(CY_PINS_Pulse4_H) /* Pins Pulse4_H */
#define CY_PINS_Pulse4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pulse4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pulse4__PORT == 15 && ((Pulse4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pulse4_Write(uint8 value);
void    Pulse4_SetDriveMode(uint8 mode);
uint8   Pulse4_ReadDataReg(void);
uint8   Pulse4_Read(void);
void    Pulse4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pulse4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pulse4_SetDriveMode() function.
     *  @{
     */
        #define Pulse4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pulse4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pulse4_DM_RES_UP          PIN_DM_RES_UP
        #define Pulse4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pulse4_DM_OD_LO           PIN_DM_OD_LO
        #define Pulse4_DM_OD_HI           PIN_DM_OD_HI
        #define Pulse4_DM_STRONG          PIN_DM_STRONG
        #define Pulse4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pulse4_MASK               Pulse4__MASK
#define Pulse4_SHIFT              Pulse4__SHIFT
#define Pulse4_WIDTH              1u

/* Interrupt constants */
#if defined(Pulse4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pulse4_SetInterruptMode() function.
     *  @{
     */
        #define Pulse4_INTR_NONE      (uint16)(0x0000u)
        #define Pulse4_INTR_RISING    (uint16)(0x0001u)
        #define Pulse4_INTR_FALLING   (uint16)(0x0002u)
        #define Pulse4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pulse4_INTR_MASK      (0x01u) 
#endif /* (Pulse4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pulse4_PS                     (* (reg8 *) Pulse4__PS)
/* Data Register */
#define Pulse4_DR                     (* (reg8 *) Pulse4__DR)
/* Port Number */
#define Pulse4_PRT_NUM                (* (reg8 *) Pulse4__PRT) 
/* Connect to Analog Globals */                                                  
#define Pulse4_AG                     (* (reg8 *) Pulse4__AG)                       
/* Analog MUX bux enable */
#define Pulse4_AMUX                   (* (reg8 *) Pulse4__AMUX) 
/* Bidirectional Enable */                                                        
#define Pulse4_BIE                    (* (reg8 *) Pulse4__BIE)
/* Bit-mask for Aliased Register Access */
#define Pulse4_BIT_MASK               (* (reg8 *) Pulse4__BIT_MASK)
/* Bypass Enable */
#define Pulse4_BYP                    (* (reg8 *) Pulse4__BYP)
/* Port wide control signals */                                                   
#define Pulse4_CTL                    (* (reg8 *) Pulse4__CTL)
/* Drive Modes */
#define Pulse4_DM0                    (* (reg8 *) Pulse4__DM0) 
#define Pulse4_DM1                    (* (reg8 *) Pulse4__DM1)
#define Pulse4_DM2                    (* (reg8 *) Pulse4__DM2) 
/* Input Buffer Disable Override */
#define Pulse4_INP_DIS                (* (reg8 *) Pulse4__INP_DIS)
/* LCD Common or Segment Drive */
#define Pulse4_LCD_COM_SEG            (* (reg8 *) Pulse4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pulse4_LCD_EN                 (* (reg8 *) Pulse4__LCD_EN)
/* Slew Rate Control */
#define Pulse4_SLW                    (* (reg8 *) Pulse4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pulse4_PRTDSI__CAPS_SEL       (* (reg8 *) Pulse4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pulse4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pulse4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pulse4_PRTDSI__OE_SEL0        (* (reg8 *) Pulse4__PRTDSI__OE_SEL0) 
#define Pulse4_PRTDSI__OE_SEL1        (* (reg8 *) Pulse4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pulse4_PRTDSI__OUT_SEL0       (* (reg8 *) Pulse4__PRTDSI__OUT_SEL0) 
#define Pulse4_PRTDSI__OUT_SEL1       (* (reg8 *) Pulse4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pulse4_PRTDSI__SYNC_OUT       (* (reg8 *) Pulse4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pulse4__SIO_CFG)
    #define Pulse4_SIO_HYST_EN        (* (reg8 *) Pulse4__SIO_HYST_EN)
    #define Pulse4_SIO_REG_HIFREQ     (* (reg8 *) Pulse4__SIO_REG_HIFREQ)
    #define Pulse4_SIO_CFG            (* (reg8 *) Pulse4__SIO_CFG)
    #define Pulse4_SIO_DIFF           (* (reg8 *) Pulse4__SIO_DIFF)
#endif /* (Pulse4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pulse4__INTSTAT)
    #define Pulse4_INTSTAT            (* (reg8 *) Pulse4__INTSTAT)
    #define Pulse4_SNAP               (* (reg8 *) Pulse4__SNAP)
    
	#define Pulse4_0_INTTYPE_REG 		(* (reg8 *) Pulse4__0__INTTYPE)
#endif /* (Pulse4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pulse4_H */


/* [] END OF FILE */
