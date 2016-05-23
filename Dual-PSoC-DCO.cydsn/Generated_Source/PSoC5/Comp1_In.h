/*******************************************************************************
* File Name: Comp1_In.h  
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

#if !defined(CY_PINS_Comp1_In_H) /* Pins Comp1_In_H */
#define CY_PINS_Comp1_In_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Comp1_In_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Comp1_In__PORT == 15 && ((Comp1_In__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Comp1_In_Write(uint8 value);
void    Comp1_In_SetDriveMode(uint8 mode);
uint8   Comp1_In_ReadDataReg(void);
uint8   Comp1_In_Read(void);
void    Comp1_In_SetInterruptMode(uint16 position, uint16 mode);
uint8   Comp1_In_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Comp1_In_SetDriveMode() function.
     *  @{
     */
        #define Comp1_In_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Comp1_In_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Comp1_In_DM_RES_UP          PIN_DM_RES_UP
        #define Comp1_In_DM_RES_DWN         PIN_DM_RES_DWN
        #define Comp1_In_DM_OD_LO           PIN_DM_OD_LO
        #define Comp1_In_DM_OD_HI           PIN_DM_OD_HI
        #define Comp1_In_DM_STRONG          PIN_DM_STRONG
        #define Comp1_In_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Comp1_In_MASK               Comp1_In__MASK
#define Comp1_In_SHIFT              Comp1_In__SHIFT
#define Comp1_In_WIDTH              1u

/* Interrupt constants */
#if defined(Comp1_In__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Comp1_In_SetInterruptMode() function.
     *  @{
     */
        #define Comp1_In_INTR_NONE      (uint16)(0x0000u)
        #define Comp1_In_INTR_RISING    (uint16)(0x0001u)
        #define Comp1_In_INTR_FALLING   (uint16)(0x0002u)
        #define Comp1_In_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Comp1_In_INTR_MASK      (0x01u) 
#endif /* (Comp1_In__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Comp1_In_PS                     (* (reg8 *) Comp1_In__PS)
/* Data Register */
#define Comp1_In_DR                     (* (reg8 *) Comp1_In__DR)
/* Port Number */
#define Comp1_In_PRT_NUM                (* (reg8 *) Comp1_In__PRT) 
/* Connect to Analog Globals */                                                  
#define Comp1_In_AG                     (* (reg8 *) Comp1_In__AG)                       
/* Analog MUX bux enable */
#define Comp1_In_AMUX                   (* (reg8 *) Comp1_In__AMUX) 
/* Bidirectional Enable */                                                        
#define Comp1_In_BIE                    (* (reg8 *) Comp1_In__BIE)
/* Bit-mask for Aliased Register Access */
#define Comp1_In_BIT_MASK               (* (reg8 *) Comp1_In__BIT_MASK)
/* Bypass Enable */
#define Comp1_In_BYP                    (* (reg8 *) Comp1_In__BYP)
/* Port wide control signals */                                                   
#define Comp1_In_CTL                    (* (reg8 *) Comp1_In__CTL)
/* Drive Modes */
#define Comp1_In_DM0                    (* (reg8 *) Comp1_In__DM0) 
#define Comp1_In_DM1                    (* (reg8 *) Comp1_In__DM1)
#define Comp1_In_DM2                    (* (reg8 *) Comp1_In__DM2) 
/* Input Buffer Disable Override */
#define Comp1_In_INP_DIS                (* (reg8 *) Comp1_In__INP_DIS)
/* LCD Common or Segment Drive */
#define Comp1_In_LCD_COM_SEG            (* (reg8 *) Comp1_In__LCD_COM_SEG)
/* Enable Segment LCD */
#define Comp1_In_LCD_EN                 (* (reg8 *) Comp1_In__LCD_EN)
/* Slew Rate Control */
#define Comp1_In_SLW                    (* (reg8 *) Comp1_In__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Comp1_In_PRTDSI__CAPS_SEL       (* (reg8 *) Comp1_In__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Comp1_In_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Comp1_In__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Comp1_In_PRTDSI__OE_SEL0        (* (reg8 *) Comp1_In__PRTDSI__OE_SEL0) 
#define Comp1_In_PRTDSI__OE_SEL1        (* (reg8 *) Comp1_In__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Comp1_In_PRTDSI__OUT_SEL0       (* (reg8 *) Comp1_In__PRTDSI__OUT_SEL0) 
#define Comp1_In_PRTDSI__OUT_SEL1       (* (reg8 *) Comp1_In__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Comp1_In_PRTDSI__SYNC_OUT       (* (reg8 *) Comp1_In__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Comp1_In__SIO_CFG)
    #define Comp1_In_SIO_HYST_EN        (* (reg8 *) Comp1_In__SIO_HYST_EN)
    #define Comp1_In_SIO_REG_HIFREQ     (* (reg8 *) Comp1_In__SIO_REG_HIFREQ)
    #define Comp1_In_SIO_CFG            (* (reg8 *) Comp1_In__SIO_CFG)
    #define Comp1_In_SIO_DIFF           (* (reg8 *) Comp1_In__SIO_DIFF)
#endif /* (Comp1_In__SIO_CFG) */

/* Interrupt Registers */
#if defined(Comp1_In__INTSTAT)
    #define Comp1_In_INTSTAT            (* (reg8 *) Comp1_In__INTSTAT)
    #define Comp1_In_SNAP               (* (reg8 *) Comp1_In__SNAP)
    
	#define Comp1_In_0_INTTYPE_REG 		(* (reg8 *) Comp1_In__0__INTTYPE)
#endif /* (Comp1_In__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Comp1_In_H */


/* [] END OF FILE */
