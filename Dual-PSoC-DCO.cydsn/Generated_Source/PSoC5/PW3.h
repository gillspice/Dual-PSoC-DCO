/*******************************************************************************
* File Name: PW3.h  
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

#if !defined(CY_PINS_PW3_H) /* Pins PW3_H */
#define CY_PINS_PW3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PW3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PW3__PORT == 15 && ((PW3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PW3_Write(uint8 value);
void    PW3_SetDriveMode(uint8 mode);
uint8   PW3_ReadDataReg(void);
uint8   PW3_Read(void);
void    PW3_SetInterruptMode(uint16 position, uint16 mode);
uint8   PW3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PW3_SetDriveMode() function.
     *  @{
     */
        #define PW3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PW3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PW3_DM_RES_UP          PIN_DM_RES_UP
        #define PW3_DM_RES_DWN         PIN_DM_RES_DWN
        #define PW3_DM_OD_LO           PIN_DM_OD_LO
        #define PW3_DM_OD_HI           PIN_DM_OD_HI
        #define PW3_DM_STRONG          PIN_DM_STRONG
        #define PW3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PW3_MASK               PW3__MASK
#define PW3_SHIFT              PW3__SHIFT
#define PW3_WIDTH              1u

/* Interrupt constants */
#if defined(PW3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PW3_SetInterruptMode() function.
     *  @{
     */
        #define PW3_INTR_NONE      (uint16)(0x0000u)
        #define PW3_INTR_RISING    (uint16)(0x0001u)
        #define PW3_INTR_FALLING   (uint16)(0x0002u)
        #define PW3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PW3_INTR_MASK      (0x01u) 
#endif /* (PW3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PW3_PS                     (* (reg8 *) PW3__PS)
/* Data Register */
#define PW3_DR                     (* (reg8 *) PW3__DR)
/* Port Number */
#define PW3_PRT_NUM                (* (reg8 *) PW3__PRT) 
/* Connect to Analog Globals */                                                  
#define PW3_AG                     (* (reg8 *) PW3__AG)                       
/* Analog MUX bux enable */
#define PW3_AMUX                   (* (reg8 *) PW3__AMUX) 
/* Bidirectional Enable */                                                        
#define PW3_BIE                    (* (reg8 *) PW3__BIE)
/* Bit-mask for Aliased Register Access */
#define PW3_BIT_MASK               (* (reg8 *) PW3__BIT_MASK)
/* Bypass Enable */
#define PW3_BYP                    (* (reg8 *) PW3__BYP)
/* Port wide control signals */                                                   
#define PW3_CTL                    (* (reg8 *) PW3__CTL)
/* Drive Modes */
#define PW3_DM0                    (* (reg8 *) PW3__DM0) 
#define PW3_DM1                    (* (reg8 *) PW3__DM1)
#define PW3_DM2                    (* (reg8 *) PW3__DM2) 
/* Input Buffer Disable Override */
#define PW3_INP_DIS                (* (reg8 *) PW3__INP_DIS)
/* LCD Common or Segment Drive */
#define PW3_LCD_COM_SEG            (* (reg8 *) PW3__LCD_COM_SEG)
/* Enable Segment LCD */
#define PW3_LCD_EN                 (* (reg8 *) PW3__LCD_EN)
/* Slew Rate Control */
#define PW3_SLW                    (* (reg8 *) PW3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PW3_PRTDSI__CAPS_SEL       (* (reg8 *) PW3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PW3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PW3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PW3_PRTDSI__OE_SEL0        (* (reg8 *) PW3__PRTDSI__OE_SEL0) 
#define PW3_PRTDSI__OE_SEL1        (* (reg8 *) PW3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PW3_PRTDSI__OUT_SEL0       (* (reg8 *) PW3__PRTDSI__OUT_SEL0) 
#define PW3_PRTDSI__OUT_SEL1       (* (reg8 *) PW3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PW3_PRTDSI__SYNC_OUT       (* (reg8 *) PW3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PW3__SIO_CFG)
    #define PW3_SIO_HYST_EN        (* (reg8 *) PW3__SIO_HYST_EN)
    #define PW3_SIO_REG_HIFREQ     (* (reg8 *) PW3__SIO_REG_HIFREQ)
    #define PW3_SIO_CFG            (* (reg8 *) PW3__SIO_CFG)
    #define PW3_SIO_DIFF           (* (reg8 *) PW3__SIO_DIFF)
#endif /* (PW3__SIO_CFG) */

/* Interrupt Registers */
#if defined(PW3__INTSTAT)
    #define PW3_INTSTAT            (* (reg8 *) PW3__INTSTAT)
    #define PW3_SNAP               (* (reg8 *) PW3__SNAP)
    
	#define PW3_0_INTTYPE_REG 		(* (reg8 *) PW3__0__INTTYPE)
#endif /* (PW3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PW3_H */


/* [] END OF FILE */
