/*******************************************************************************
* File Name: Tri_In.h  
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

#if !defined(CY_PINS_Tri_In_H) /* Pins Tri_In_H */
#define CY_PINS_Tri_In_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Tri_In_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Tri_In__PORT == 15 && ((Tri_In__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Tri_In_Write(uint8 value);
void    Tri_In_SetDriveMode(uint8 mode);
uint8   Tri_In_ReadDataReg(void);
uint8   Tri_In_Read(void);
void    Tri_In_SetInterruptMode(uint16 position, uint16 mode);
uint8   Tri_In_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Tri_In_SetDriveMode() function.
     *  @{
     */
        #define Tri_In_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Tri_In_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Tri_In_DM_RES_UP          PIN_DM_RES_UP
        #define Tri_In_DM_RES_DWN         PIN_DM_RES_DWN
        #define Tri_In_DM_OD_LO           PIN_DM_OD_LO
        #define Tri_In_DM_OD_HI           PIN_DM_OD_HI
        #define Tri_In_DM_STRONG          PIN_DM_STRONG
        #define Tri_In_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Tri_In_MASK               Tri_In__MASK
#define Tri_In_SHIFT              Tri_In__SHIFT
#define Tri_In_WIDTH              1u

/* Interrupt constants */
#if defined(Tri_In__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Tri_In_SetInterruptMode() function.
     *  @{
     */
        #define Tri_In_INTR_NONE      (uint16)(0x0000u)
        #define Tri_In_INTR_RISING    (uint16)(0x0001u)
        #define Tri_In_INTR_FALLING   (uint16)(0x0002u)
        #define Tri_In_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Tri_In_INTR_MASK      (0x01u) 
#endif /* (Tri_In__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Tri_In_PS                     (* (reg8 *) Tri_In__PS)
/* Data Register */
#define Tri_In_DR                     (* (reg8 *) Tri_In__DR)
/* Port Number */
#define Tri_In_PRT_NUM                (* (reg8 *) Tri_In__PRT) 
/* Connect to Analog Globals */                                                  
#define Tri_In_AG                     (* (reg8 *) Tri_In__AG)                       
/* Analog MUX bux enable */
#define Tri_In_AMUX                   (* (reg8 *) Tri_In__AMUX) 
/* Bidirectional Enable */                                                        
#define Tri_In_BIE                    (* (reg8 *) Tri_In__BIE)
/* Bit-mask for Aliased Register Access */
#define Tri_In_BIT_MASK               (* (reg8 *) Tri_In__BIT_MASK)
/* Bypass Enable */
#define Tri_In_BYP                    (* (reg8 *) Tri_In__BYP)
/* Port wide control signals */                                                   
#define Tri_In_CTL                    (* (reg8 *) Tri_In__CTL)
/* Drive Modes */
#define Tri_In_DM0                    (* (reg8 *) Tri_In__DM0) 
#define Tri_In_DM1                    (* (reg8 *) Tri_In__DM1)
#define Tri_In_DM2                    (* (reg8 *) Tri_In__DM2) 
/* Input Buffer Disable Override */
#define Tri_In_INP_DIS                (* (reg8 *) Tri_In__INP_DIS)
/* LCD Common or Segment Drive */
#define Tri_In_LCD_COM_SEG            (* (reg8 *) Tri_In__LCD_COM_SEG)
/* Enable Segment LCD */
#define Tri_In_LCD_EN                 (* (reg8 *) Tri_In__LCD_EN)
/* Slew Rate Control */
#define Tri_In_SLW                    (* (reg8 *) Tri_In__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Tri_In_PRTDSI__CAPS_SEL       (* (reg8 *) Tri_In__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Tri_In_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Tri_In__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Tri_In_PRTDSI__OE_SEL0        (* (reg8 *) Tri_In__PRTDSI__OE_SEL0) 
#define Tri_In_PRTDSI__OE_SEL1        (* (reg8 *) Tri_In__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Tri_In_PRTDSI__OUT_SEL0       (* (reg8 *) Tri_In__PRTDSI__OUT_SEL0) 
#define Tri_In_PRTDSI__OUT_SEL1       (* (reg8 *) Tri_In__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Tri_In_PRTDSI__SYNC_OUT       (* (reg8 *) Tri_In__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Tri_In__SIO_CFG)
    #define Tri_In_SIO_HYST_EN        (* (reg8 *) Tri_In__SIO_HYST_EN)
    #define Tri_In_SIO_REG_HIFREQ     (* (reg8 *) Tri_In__SIO_REG_HIFREQ)
    #define Tri_In_SIO_CFG            (* (reg8 *) Tri_In__SIO_CFG)
    #define Tri_In_SIO_DIFF           (* (reg8 *) Tri_In__SIO_DIFF)
#endif /* (Tri_In__SIO_CFG) */

/* Interrupt Registers */
#if defined(Tri_In__INTSTAT)
    #define Tri_In_INTSTAT            (* (reg8 *) Tri_In__INTSTAT)
    #define Tri_In_SNAP               (* (reg8 *) Tri_In__SNAP)
    
	#define Tri_In_0_INTTYPE_REG 		(* (reg8 *) Tri_In__0__INTTYPE)
#endif /* (Tri_In__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Tri_In_H */


/* [] END OF FILE */
