/*******************************************************************************
* File Name: Soft_Sync.h  
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

#if !defined(CY_PINS_Soft_Sync_H) /* Pins Soft_Sync_H */
#define CY_PINS_Soft_Sync_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Soft_Sync_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Soft_Sync__PORT == 15 && ((Soft_Sync__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Soft_Sync_Write(uint8 value);
void    Soft_Sync_SetDriveMode(uint8 mode);
uint8   Soft_Sync_ReadDataReg(void);
uint8   Soft_Sync_Read(void);
void    Soft_Sync_SetInterruptMode(uint16 position, uint16 mode);
uint8   Soft_Sync_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Soft_Sync_SetDriveMode() function.
     *  @{
     */
        #define Soft_Sync_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Soft_Sync_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Soft_Sync_DM_RES_UP          PIN_DM_RES_UP
        #define Soft_Sync_DM_RES_DWN         PIN_DM_RES_DWN
        #define Soft_Sync_DM_OD_LO           PIN_DM_OD_LO
        #define Soft_Sync_DM_OD_HI           PIN_DM_OD_HI
        #define Soft_Sync_DM_STRONG          PIN_DM_STRONG
        #define Soft_Sync_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Soft_Sync_MASK               Soft_Sync__MASK
#define Soft_Sync_SHIFT              Soft_Sync__SHIFT
#define Soft_Sync_WIDTH              1u

/* Interrupt constants */
#if defined(Soft_Sync__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Soft_Sync_SetInterruptMode() function.
     *  @{
     */
        #define Soft_Sync_INTR_NONE      (uint16)(0x0000u)
        #define Soft_Sync_INTR_RISING    (uint16)(0x0001u)
        #define Soft_Sync_INTR_FALLING   (uint16)(0x0002u)
        #define Soft_Sync_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Soft_Sync_INTR_MASK      (0x01u) 
#endif /* (Soft_Sync__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Soft_Sync_PS                     (* (reg8 *) Soft_Sync__PS)
/* Data Register */
#define Soft_Sync_DR                     (* (reg8 *) Soft_Sync__DR)
/* Port Number */
#define Soft_Sync_PRT_NUM                (* (reg8 *) Soft_Sync__PRT) 
/* Connect to Analog Globals */                                                  
#define Soft_Sync_AG                     (* (reg8 *) Soft_Sync__AG)                       
/* Analog MUX bux enable */
#define Soft_Sync_AMUX                   (* (reg8 *) Soft_Sync__AMUX) 
/* Bidirectional Enable */                                                        
#define Soft_Sync_BIE                    (* (reg8 *) Soft_Sync__BIE)
/* Bit-mask for Aliased Register Access */
#define Soft_Sync_BIT_MASK               (* (reg8 *) Soft_Sync__BIT_MASK)
/* Bypass Enable */
#define Soft_Sync_BYP                    (* (reg8 *) Soft_Sync__BYP)
/* Port wide control signals */                                                   
#define Soft_Sync_CTL                    (* (reg8 *) Soft_Sync__CTL)
/* Drive Modes */
#define Soft_Sync_DM0                    (* (reg8 *) Soft_Sync__DM0) 
#define Soft_Sync_DM1                    (* (reg8 *) Soft_Sync__DM1)
#define Soft_Sync_DM2                    (* (reg8 *) Soft_Sync__DM2) 
/* Input Buffer Disable Override */
#define Soft_Sync_INP_DIS                (* (reg8 *) Soft_Sync__INP_DIS)
/* LCD Common or Segment Drive */
#define Soft_Sync_LCD_COM_SEG            (* (reg8 *) Soft_Sync__LCD_COM_SEG)
/* Enable Segment LCD */
#define Soft_Sync_LCD_EN                 (* (reg8 *) Soft_Sync__LCD_EN)
/* Slew Rate Control */
#define Soft_Sync_SLW                    (* (reg8 *) Soft_Sync__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Soft_Sync_PRTDSI__CAPS_SEL       (* (reg8 *) Soft_Sync__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Soft_Sync_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Soft_Sync__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Soft_Sync_PRTDSI__OE_SEL0        (* (reg8 *) Soft_Sync__PRTDSI__OE_SEL0) 
#define Soft_Sync_PRTDSI__OE_SEL1        (* (reg8 *) Soft_Sync__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Soft_Sync_PRTDSI__OUT_SEL0       (* (reg8 *) Soft_Sync__PRTDSI__OUT_SEL0) 
#define Soft_Sync_PRTDSI__OUT_SEL1       (* (reg8 *) Soft_Sync__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Soft_Sync_PRTDSI__SYNC_OUT       (* (reg8 *) Soft_Sync__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Soft_Sync__SIO_CFG)
    #define Soft_Sync_SIO_HYST_EN        (* (reg8 *) Soft_Sync__SIO_HYST_EN)
    #define Soft_Sync_SIO_REG_HIFREQ     (* (reg8 *) Soft_Sync__SIO_REG_HIFREQ)
    #define Soft_Sync_SIO_CFG            (* (reg8 *) Soft_Sync__SIO_CFG)
    #define Soft_Sync_SIO_DIFF           (* (reg8 *) Soft_Sync__SIO_DIFF)
#endif /* (Soft_Sync__SIO_CFG) */

/* Interrupt Registers */
#if defined(Soft_Sync__INTSTAT)
    #define Soft_Sync_INTSTAT            (* (reg8 *) Soft_Sync__INTSTAT)
    #define Soft_Sync_SNAP               (* (reg8 *) Soft_Sync__SNAP)
    
	#define Soft_Sync_0_INTTYPE_REG 		(* (reg8 *) Soft_Sync__0__INTTYPE)
#endif /* (Soft_Sync__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Soft_Sync_H */


/* [] END OF FILE */
