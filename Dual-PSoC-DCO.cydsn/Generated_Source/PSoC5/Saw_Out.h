/*******************************************************************************
* File Name: Saw_Out.h  
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

#if !defined(CY_PINS_Saw_Out_H) /* Pins Saw_Out_H */
#define CY_PINS_Saw_Out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Saw_Out_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Saw_Out__PORT == 15 && ((Saw_Out__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Saw_Out_Write(uint8 value);
void    Saw_Out_SetDriveMode(uint8 mode);
uint8   Saw_Out_ReadDataReg(void);
uint8   Saw_Out_Read(void);
void    Saw_Out_SetInterruptMode(uint16 position, uint16 mode);
uint8   Saw_Out_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Saw_Out_SetDriveMode() function.
     *  @{
     */
        #define Saw_Out_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Saw_Out_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Saw_Out_DM_RES_UP          PIN_DM_RES_UP
        #define Saw_Out_DM_RES_DWN         PIN_DM_RES_DWN
        #define Saw_Out_DM_OD_LO           PIN_DM_OD_LO
        #define Saw_Out_DM_OD_HI           PIN_DM_OD_HI
        #define Saw_Out_DM_STRONG          PIN_DM_STRONG
        #define Saw_Out_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Saw_Out_MASK               Saw_Out__MASK
#define Saw_Out_SHIFT              Saw_Out__SHIFT
#define Saw_Out_WIDTH              1u

/* Interrupt constants */
#if defined(Saw_Out__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Saw_Out_SetInterruptMode() function.
     *  @{
     */
        #define Saw_Out_INTR_NONE      (uint16)(0x0000u)
        #define Saw_Out_INTR_RISING    (uint16)(0x0001u)
        #define Saw_Out_INTR_FALLING   (uint16)(0x0002u)
        #define Saw_Out_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Saw_Out_INTR_MASK      (0x01u) 
#endif /* (Saw_Out__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Saw_Out_PS                     (* (reg8 *) Saw_Out__PS)
/* Data Register */
#define Saw_Out_DR                     (* (reg8 *) Saw_Out__DR)
/* Port Number */
#define Saw_Out_PRT_NUM                (* (reg8 *) Saw_Out__PRT) 
/* Connect to Analog Globals */                                                  
#define Saw_Out_AG                     (* (reg8 *) Saw_Out__AG)                       
/* Analog MUX bux enable */
#define Saw_Out_AMUX                   (* (reg8 *) Saw_Out__AMUX) 
/* Bidirectional Enable */                                                        
#define Saw_Out_BIE                    (* (reg8 *) Saw_Out__BIE)
/* Bit-mask for Aliased Register Access */
#define Saw_Out_BIT_MASK               (* (reg8 *) Saw_Out__BIT_MASK)
/* Bypass Enable */
#define Saw_Out_BYP                    (* (reg8 *) Saw_Out__BYP)
/* Port wide control signals */                                                   
#define Saw_Out_CTL                    (* (reg8 *) Saw_Out__CTL)
/* Drive Modes */
#define Saw_Out_DM0                    (* (reg8 *) Saw_Out__DM0) 
#define Saw_Out_DM1                    (* (reg8 *) Saw_Out__DM1)
#define Saw_Out_DM2                    (* (reg8 *) Saw_Out__DM2) 
/* Input Buffer Disable Override */
#define Saw_Out_INP_DIS                (* (reg8 *) Saw_Out__INP_DIS)
/* LCD Common or Segment Drive */
#define Saw_Out_LCD_COM_SEG            (* (reg8 *) Saw_Out__LCD_COM_SEG)
/* Enable Segment LCD */
#define Saw_Out_LCD_EN                 (* (reg8 *) Saw_Out__LCD_EN)
/* Slew Rate Control */
#define Saw_Out_SLW                    (* (reg8 *) Saw_Out__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Saw_Out_PRTDSI__CAPS_SEL       (* (reg8 *) Saw_Out__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Saw_Out_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Saw_Out__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Saw_Out_PRTDSI__OE_SEL0        (* (reg8 *) Saw_Out__PRTDSI__OE_SEL0) 
#define Saw_Out_PRTDSI__OE_SEL1        (* (reg8 *) Saw_Out__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Saw_Out_PRTDSI__OUT_SEL0       (* (reg8 *) Saw_Out__PRTDSI__OUT_SEL0) 
#define Saw_Out_PRTDSI__OUT_SEL1       (* (reg8 *) Saw_Out__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Saw_Out_PRTDSI__SYNC_OUT       (* (reg8 *) Saw_Out__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Saw_Out__SIO_CFG)
    #define Saw_Out_SIO_HYST_EN        (* (reg8 *) Saw_Out__SIO_HYST_EN)
    #define Saw_Out_SIO_REG_HIFREQ     (* (reg8 *) Saw_Out__SIO_REG_HIFREQ)
    #define Saw_Out_SIO_CFG            (* (reg8 *) Saw_Out__SIO_CFG)
    #define Saw_Out_SIO_DIFF           (* (reg8 *) Saw_Out__SIO_DIFF)
#endif /* (Saw_Out__SIO_CFG) */

/* Interrupt Registers */
#if defined(Saw_Out__INTSTAT)
    #define Saw_Out_INTSTAT            (* (reg8 *) Saw_Out__INTSTAT)
    #define Saw_Out_SNAP               (* (reg8 *) Saw_Out__SNAP)
    
	#define Saw_Out_0_INTTYPE_REG 		(* (reg8 *) Saw_Out__0__INTTYPE)
#endif /* (Saw_Out__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Saw_Out_H */


/* [] END OF FILE */
