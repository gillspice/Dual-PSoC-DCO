/*******************************************************************************
* File Name: Pulse2.h  
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

#if !defined(CY_PINS_Pulse2_H) /* Pins Pulse2_H */
#define CY_PINS_Pulse2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pulse2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pulse2__PORT == 15 && ((Pulse2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pulse2_Write(uint8 value);
void    Pulse2_SetDriveMode(uint8 mode);
uint8   Pulse2_ReadDataReg(void);
uint8   Pulse2_Read(void);
void    Pulse2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pulse2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pulse2_SetDriveMode() function.
     *  @{
     */
        #define Pulse2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pulse2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pulse2_DM_RES_UP          PIN_DM_RES_UP
        #define Pulse2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pulse2_DM_OD_LO           PIN_DM_OD_LO
        #define Pulse2_DM_OD_HI           PIN_DM_OD_HI
        #define Pulse2_DM_STRONG          PIN_DM_STRONG
        #define Pulse2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pulse2_MASK               Pulse2__MASK
#define Pulse2_SHIFT              Pulse2__SHIFT
#define Pulse2_WIDTH              1u

/* Interrupt constants */
#if defined(Pulse2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pulse2_SetInterruptMode() function.
     *  @{
     */
        #define Pulse2_INTR_NONE      (uint16)(0x0000u)
        #define Pulse2_INTR_RISING    (uint16)(0x0001u)
        #define Pulse2_INTR_FALLING   (uint16)(0x0002u)
        #define Pulse2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pulse2_INTR_MASK      (0x01u) 
#endif /* (Pulse2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pulse2_PS                     (* (reg8 *) Pulse2__PS)
/* Data Register */
#define Pulse2_DR                     (* (reg8 *) Pulse2__DR)
/* Port Number */
#define Pulse2_PRT_NUM                (* (reg8 *) Pulse2__PRT) 
/* Connect to Analog Globals */                                                  
#define Pulse2_AG                     (* (reg8 *) Pulse2__AG)                       
/* Analog MUX bux enable */
#define Pulse2_AMUX                   (* (reg8 *) Pulse2__AMUX) 
/* Bidirectional Enable */                                                        
#define Pulse2_BIE                    (* (reg8 *) Pulse2__BIE)
/* Bit-mask for Aliased Register Access */
#define Pulse2_BIT_MASK               (* (reg8 *) Pulse2__BIT_MASK)
/* Bypass Enable */
#define Pulse2_BYP                    (* (reg8 *) Pulse2__BYP)
/* Port wide control signals */                                                   
#define Pulse2_CTL                    (* (reg8 *) Pulse2__CTL)
/* Drive Modes */
#define Pulse2_DM0                    (* (reg8 *) Pulse2__DM0) 
#define Pulse2_DM1                    (* (reg8 *) Pulse2__DM1)
#define Pulse2_DM2                    (* (reg8 *) Pulse2__DM2) 
/* Input Buffer Disable Override */
#define Pulse2_INP_DIS                (* (reg8 *) Pulse2__INP_DIS)
/* LCD Common or Segment Drive */
#define Pulse2_LCD_COM_SEG            (* (reg8 *) Pulse2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pulse2_LCD_EN                 (* (reg8 *) Pulse2__LCD_EN)
/* Slew Rate Control */
#define Pulse2_SLW                    (* (reg8 *) Pulse2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pulse2_PRTDSI__CAPS_SEL       (* (reg8 *) Pulse2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pulse2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pulse2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pulse2_PRTDSI__OE_SEL0        (* (reg8 *) Pulse2__PRTDSI__OE_SEL0) 
#define Pulse2_PRTDSI__OE_SEL1        (* (reg8 *) Pulse2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pulse2_PRTDSI__OUT_SEL0       (* (reg8 *) Pulse2__PRTDSI__OUT_SEL0) 
#define Pulse2_PRTDSI__OUT_SEL1       (* (reg8 *) Pulse2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pulse2_PRTDSI__SYNC_OUT       (* (reg8 *) Pulse2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pulse2__SIO_CFG)
    #define Pulse2_SIO_HYST_EN        (* (reg8 *) Pulse2__SIO_HYST_EN)
    #define Pulse2_SIO_REG_HIFREQ     (* (reg8 *) Pulse2__SIO_REG_HIFREQ)
    #define Pulse2_SIO_CFG            (* (reg8 *) Pulse2__SIO_CFG)
    #define Pulse2_SIO_DIFF           (* (reg8 *) Pulse2__SIO_DIFF)
#endif /* (Pulse2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pulse2__INTSTAT)
    #define Pulse2_INTSTAT            (* (reg8 *) Pulse2__INTSTAT)
    #define Pulse2_SNAP               (* (reg8 *) Pulse2__SNAP)
    
	#define Pulse2_0_INTTYPE_REG 		(* (reg8 *) Pulse2__0__INTTYPE)
#endif /* (Pulse2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pulse2_H */


/* [] END OF FILE */
