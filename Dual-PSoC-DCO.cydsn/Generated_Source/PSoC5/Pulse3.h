/*******************************************************************************
* File Name: Pulse3.h  
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

#if !defined(CY_PINS_Pulse3_H) /* Pins Pulse3_H */
#define CY_PINS_Pulse3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pulse3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pulse3__PORT == 15 && ((Pulse3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pulse3_Write(uint8 value);
void    Pulse3_SetDriveMode(uint8 mode);
uint8   Pulse3_ReadDataReg(void);
uint8   Pulse3_Read(void);
void    Pulse3_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pulse3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pulse3_SetDriveMode() function.
     *  @{
     */
        #define Pulse3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pulse3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pulse3_DM_RES_UP          PIN_DM_RES_UP
        #define Pulse3_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pulse3_DM_OD_LO           PIN_DM_OD_LO
        #define Pulse3_DM_OD_HI           PIN_DM_OD_HI
        #define Pulse3_DM_STRONG          PIN_DM_STRONG
        #define Pulse3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pulse3_MASK               Pulse3__MASK
#define Pulse3_SHIFT              Pulse3__SHIFT
#define Pulse3_WIDTH              1u

/* Interrupt constants */
#if defined(Pulse3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pulse3_SetInterruptMode() function.
     *  @{
     */
        #define Pulse3_INTR_NONE      (uint16)(0x0000u)
        #define Pulse3_INTR_RISING    (uint16)(0x0001u)
        #define Pulse3_INTR_FALLING   (uint16)(0x0002u)
        #define Pulse3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pulse3_INTR_MASK      (0x01u) 
#endif /* (Pulse3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pulse3_PS                     (* (reg8 *) Pulse3__PS)
/* Data Register */
#define Pulse3_DR                     (* (reg8 *) Pulse3__DR)
/* Port Number */
#define Pulse3_PRT_NUM                (* (reg8 *) Pulse3__PRT) 
/* Connect to Analog Globals */                                                  
#define Pulse3_AG                     (* (reg8 *) Pulse3__AG)                       
/* Analog MUX bux enable */
#define Pulse3_AMUX                   (* (reg8 *) Pulse3__AMUX) 
/* Bidirectional Enable */                                                        
#define Pulse3_BIE                    (* (reg8 *) Pulse3__BIE)
/* Bit-mask for Aliased Register Access */
#define Pulse3_BIT_MASK               (* (reg8 *) Pulse3__BIT_MASK)
/* Bypass Enable */
#define Pulse3_BYP                    (* (reg8 *) Pulse3__BYP)
/* Port wide control signals */                                                   
#define Pulse3_CTL                    (* (reg8 *) Pulse3__CTL)
/* Drive Modes */
#define Pulse3_DM0                    (* (reg8 *) Pulse3__DM0) 
#define Pulse3_DM1                    (* (reg8 *) Pulse3__DM1)
#define Pulse3_DM2                    (* (reg8 *) Pulse3__DM2) 
/* Input Buffer Disable Override */
#define Pulse3_INP_DIS                (* (reg8 *) Pulse3__INP_DIS)
/* LCD Common or Segment Drive */
#define Pulse3_LCD_COM_SEG            (* (reg8 *) Pulse3__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pulse3_LCD_EN                 (* (reg8 *) Pulse3__LCD_EN)
/* Slew Rate Control */
#define Pulse3_SLW                    (* (reg8 *) Pulse3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pulse3_PRTDSI__CAPS_SEL       (* (reg8 *) Pulse3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pulse3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pulse3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pulse3_PRTDSI__OE_SEL0        (* (reg8 *) Pulse3__PRTDSI__OE_SEL0) 
#define Pulse3_PRTDSI__OE_SEL1        (* (reg8 *) Pulse3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pulse3_PRTDSI__OUT_SEL0       (* (reg8 *) Pulse3__PRTDSI__OUT_SEL0) 
#define Pulse3_PRTDSI__OUT_SEL1       (* (reg8 *) Pulse3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pulse3_PRTDSI__SYNC_OUT       (* (reg8 *) Pulse3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pulse3__SIO_CFG)
    #define Pulse3_SIO_HYST_EN        (* (reg8 *) Pulse3__SIO_HYST_EN)
    #define Pulse3_SIO_REG_HIFREQ     (* (reg8 *) Pulse3__SIO_REG_HIFREQ)
    #define Pulse3_SIO_CFG            (* (reg8 *) Pulse3__SIO_CFG)
    #define Pulse3_SIO_DIFF           (* (reg8 *) Pulse3__SIO_DIFF)
#endif /* (Pulse3__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pulse3__INTSTAT)
    #define Pulse3_INTSTAT            (* (reg8 *) Pulse3__INTSTAT)
    #define Pulse3_SNAP               (* (reg8 *) Pulse3__SNAP)
    
	#define Pulse3_0_INTTYPE_REG 		(* (reg8 *) Pulse3__0__INTTYPE)
#endif /* (Pulse3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pulse3_H */


/* [] END OF FILE */
