/*******************************************************************************
* File Name: FM_Sign_Pin.h  
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

#if !defined(CY_PINS_FM_Sign_Pin_H) /* Pins FM_Sign_Pin_H */
#define CY_PINS_FM_Sign_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FM_Sign_Pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FM_Sign_Pin__PORT == 15 && ((FM_Sign_Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    FM_Sign_Pin_Write(uint8 value);
void    FM_Sign_Pin_SetDriveMode(uint8 mode);
uint8   FM_Sign_Pin_ReadDataReg(void);
uint8   FM_Sign_Pin_Read(void);
void    FM_Sign_Pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   FM_Sign_Pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the FM_Sign_Pin_SetDriveMode() function.
     *  @{
     */
        #define FM_Sign_Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define FM_Sign_Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define FM_Sign_Pin_DM_RES_UP          PIN_DM_RES_UP
        #define FM_Sign_Pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define FM_Sign_Pin_DM_OD_LO           PIN_DM_OD_LO
        #define FM_Sign_Pin_DM_OD_HI           PIN_DM_OD_HI
        #define FM_Sign_Pin_DM_STRONG          PIN_DM_STRONG
        #define FM_Sign_Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define FM_Sign_Pin_MASK               FM_Sign_Pin__MASK
#define FM_Sign_Pin_SHIFT              FM_Sign_Pin__SHIFT
#define FM_Sign_Pin_WIDTH              1u

/* Interrupt constants */
#if defined(FM_Sign_Pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FM_Sign_Pin_SetInterruptMode() function.
     *  @{
     */
        #define FM_Sign_Pin_INTR_NONE      (uint16)(0x0000u)
        #define FM_Sign_Pin_INTR_RISING    (uint16)(0x0001u)
        #define FM_Sign_Pin_INTR_FALLING   (uint16)(0x0002u)
        #define FM_Sign_Pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define FM_Sign_Pin_INTR_MASK      (0x01u) 
#endif /* (FM_Sign_Pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FM_Sign_Pin_PS                     (* (reg8 *) FM_Sign_Pin__PS)
/* Data Register */
#define FM_Sign_Pin_DR                     (* (reg8 *) FM_Sign_Pin__DR)
/* Port Number */
#define FM_Sign_Pin_PRT_NUM                (* (reg8 *) FM_Sign_Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define FM_Sign_Pin_AG                     (* (reg8 *) FM_Sign_Pin__AG)                       
/* Analog MUX bux enable */
#define FM_Sign_Pin_AMUX                   (* (reg8 *) FM_Sign_Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define FM_Sign_Pin_BIE                    (* (reg8 *) FM_Sign_Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define FM_Sign_Pin_BIT_MASK               (* (reg8 *) FM_Sign_Pin__BIT_MASK)
/* Bypass Enable */
#define FM_Sign_Pin_BYP                    (* (reg8 *) FM_Sign_Pin__BYP)
/* Port wide control signals */                                                   
#define FM_Sign_Pin_CTL                    (* (reg8 *) FM_Sign_Pin__CTL)
/* Drive Modes */
#define FM_Sign_Pin_DM0                    (* (reg8 *) FM_Sign_Pin__DM0) 
#define FM_Sign_Pin_DM1                    (* (reg8 *) FM_Sign_Pin__DM1)
#define FM_Sign_Pin_DM2                    (* (reg8 *) FM_Sign_Pin__DM2) 
/* Input Buffer Disable Override */
#define FM_Sign_Pin_INP_DIS                (* (reg8 *) FM_Sign_Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define FM_Sign_Pin_LCD_COM_SEG            (* (reg8 *) FM_Sign_Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define FM_Sign_Pin_LCD_EN                 (* (reg8 *) FM_Sign_Pin__LCD_EN)
/* Slew Rate Control */
#define FM_Sign_Pin_SLW                    (* (reg8 *) FM_Sign_Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FM_Sign_Pin_PRTDSI__CAPS_SEL       (* (reg8 *) FM_Sign_Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FM_Sign_Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FM_Sign_Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FM_Sign_Pin_PRTDSI__OE_SEL0        (* (reg8 *) FM_Sign_Pin__PRTDSI__OE_SEL0) 
#define FM_Sign_Pin_PRTDSI__OE_SEL1        (* (reg8 *) FM_Sign_Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FM_Sign_Pin_PRTDSI__OUT_SEL0       (* (reg8 *) FM_Sign_Pin__PRTDSI__OUT_SEL0) 
#define FM_Sign_Pin_PRTDSI__OUT_SEL1       (* (reg8 *) FM_Sign_Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FM_Sign_Pin_PRTDSI__SYNC_OUT       (* (reg8 *) FM_Sign_Pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(FM_Sign_Pin__SIO_CFG)
    #define FM_Sign_Pin_SIO_HYST_EN        (* (reg8 *) FM_Sign_Pin__SIO_HYST_EN)
    #define FM_Sign_Pin_SIO_REG_HIFREQ     (* (reg8 *) FM_Sign_Pin__SIO_REG_HIFREQ)
    #define FM_Sign_Pin_SIO_CFG            (* (reg8 *) FM_Sign_Pin__SIO_CFG)
    #define FM_Sign_Pin_SIO_DIFF           (* (reg8 *) FM_Sign_Pin__SIO_DIFF)
#endif /* (FM_Sign_Pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(FM_Sign_Pin__INTSTAT)
    #define FM_Sign_Pin_INTSTAT            (* (reg8 *) FM_Sign_Pin__INTSTAT)
    #define FM_Sign_Pin_SNAP               (* (reg8 *) FM_Sign_Pin__SNAP)
    
	#define FM_Sign_Pin_0_INTTYPE_REG 		(* (reg8 *) FM_Sign_Pin__0__INTTYPE)
#endif /* (FM_Sign_Pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FM_Sign_Pin_H */


/* [] END OF FILE */
