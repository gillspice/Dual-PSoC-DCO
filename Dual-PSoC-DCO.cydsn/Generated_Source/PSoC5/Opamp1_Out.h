/*******************************************************************************
* File Name: Opamp1_Out.h  
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

#if !defined(CY_PINS_Opamp1_Out_H) /* Pins Opamp1_Out_H */
#define CY_PINS_Opamp1_Out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Opamp1_Out_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Opamp1_Out__PORT == 15 && ((Opamp1_Out__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Opamp1_Out_Write(uint8 value);
void    Opamp1_Out_SetDriveMode(uint8 mode);
uint8   Opamp1_Out_ReadDataReg(void);
uint8   Opamp1_Out_Read(void);
void    Opamp1_Out_SetInterruptMode(uint16 position, uint16 mode);
uint8   Opamp1_Out_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Opamp1_Out_SetDriveMode() function.
     *  @{
     */
        #define Opamp1_Out_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Opamp1_Out_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Opamp1_Out_DM_RES_UP          PIN_DM_RES_UP
        #define Opamp1_Out_DM_RES_DWN         PIN_DM_RES_DWN
        #define Opamp1_Out_DM_OD_LO           PIN_DM_OD_LO
        #define Opamp1_Out_DM_OD_HI           PIN_DM_OD_HI
        #define Opamp1_Out_DM_STRONG          PIN_DM_STRONG
        #define Opamp1_Out_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Opamp1_Out_MASK               Opamp1_Out__MASK
#define Opamp1_Out_SHIFT              Opamp1_Out__SHIFT
#define Opamp1_Out_WIDTH              1u

/* Interrupt constants */
#if defined(Opamp1_Out__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Opamp1_Out_SetInterruptMode() function.
     *  @{
     */
        #define Opamp1_Out_INTR_NONE      (uint16)(0x0000u)
        #define Opamp1_Out_INTR_RISING    (uint16)(0x0001u)
        #define Opamp1_Out_INTR_FALLING   (uint16)(0x0002u)
        #define Opamp1_Out_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Opamp1_Out_INTR_MASK      (0x01u) 
#endif /* (Opamp1_Out__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Opamp1_Out_PS                     (* (reg8 *) Opamp1_Out__PS)
/* Data Register */
#define Opamp1_Out_DR                     (* (reg8 *) Opamp1_Out__DR)
/* Port Number */
#define Opamp1_Out_PRT_NUM                (* (reg8 *) Opamp1_Out__PRT) 
/* Connect to Analog Globals */                                                  
#define Opamp1_Out_AG                     (* (reg8 *) Opamp1_Out__AG)                       
/* Analog MUX bux enable */
#define Opamp1_Out_AMUX                   (* (reg8 *) Opamp1_Out__AMUX) 
/* Bidirectional Enable */                                                        
#define Opamp1_Out_BIE                    (* (reg8 *) Opamp1_Out__BIE)
/* Bit-mask for Aliased Register Access */
#define Opamp1_Out_BIT_MASK               (* (reg8 *) Opamp1_Out__BIT_MASK)
/* Bypass Enable */
#define Opamp1_Out_BYP                    (* (reg8 *) Opamp1_Out__BYP)
/* Port wide control signals */                                                   
#define Opamp1_Out_CTL                    (* (reg8 *) Opamp1_Out__CTL)
/* Drive Modes */
#define Opamp1_Out_DM0                    (* (reg8 *) Opamp1_Out__DM0) 
#define Opamp1_Out_DM1                    (* (reg8 *) Opamp1_Out__DM1)
#define Opamp1_Out_DM2                    (* (reg8 *) Opamp1_Out__DM2) 
/* Input Buffer Disable Override */
#define Opamp1_Out_INP_DIS                (* (reg8 *) Opamp1_Out__INP_DIS)
/* LCD Common or Segment Drive */
#define Opamp1_Out_LCD_COM_SEG            (* (reg8 *) Opamp1_Out__LCD_COM_SEG)
/* Enable Segment LCD */
#define Opamp1_Out_LCD_EN                 (* (reg8 *) Opamp1_Out__LCD_EN)
/* Slew Rate Control */
#define Opamp1_Out_SLW                    (* (reg8 *) Opamp1_Out__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Opamp1_Out_PRTDSI__CAPS_SEL       (* (reg8 *) Opamp1_Out__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Opamp1_Out_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Opamp1_Out__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Opamp1_Out_PRTDSI__OE_SEL0        (* (reg8 *) Opamp1_Out__PRTDSI__OE_SEL0) 
#define Opamp1_Out_PRTDSI__OE_SEL1        (* (reg8 *) Opamp1_Out__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Opamp1_Out_PRTDSI__OUT_SEL0       (* (reg8 *) Opamp1_Out__PRTDSI__OUT_SEL0) 
#define Opamp1_Out_PRTDSI__OUT_SEL1       (* (reg8 *) Opamp1_Out__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Opamp1_Out_PRTDSI__SYNC_OUT       (* (reg8 *) Opamp1_Out__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Opamp1_Out__SIO_CFG)
    #define Opamp1_Out_SIO_HYST_EN        (* (reg8 *) Opamp1_Out__SIO_HYST_EN)
    #define Opamp1_Out_SIO_REG_HIFREQ     (* (reg8 *) Opamp1_Out__SIO_REG_HIFREQ)
    #define Opamp1_Out_SIO_CFG            (* (reg8 *) Opamp1_Out__SIO_CFG)
    #define Opamp1_Out_SIO_DIFF           (* (reg8 *) Opamp1_Out__SIO_DIFF)
#endif /* (Opamp1_Out__SIO_CFG) */

/* Interrupt Registers */
#if defined(Opamp1_Out__INTSTAT)
    #define Opamp1_Out_INTSTAT            (* (reg8 *) Opamp1_Out__INTSTAT)
    #define Opamp1_Out_SNAP               (* (reg8 *) Opamp1_Out__SNAP)
    
	#define Opamp1_Out_0_INTTYPE_REG 		(* (reg8 *) Opamp1_Out__0__INTTYPE)
#endif /* (Opamp1_Out__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Opamp1_Out_H */


/* [] END OF FILE */
