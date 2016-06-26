/*******************************************************************************
* File Name: test_pin.h  
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

#if !defined(CY_PINS_test_pin_H) /* Pins test_pin_H */
#define CY_PINS_test_pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "test_pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 test_pin__PORT == 15 && ((test_pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    test_pin_Write(uint8 value);
void    test_pin_SetDriveMode(uint8 mode);
uint8   test_pin_ReadDataReg(void);
uint8   test_pin_Read(void);
void    test_pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   test_pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the test_pin_SetDriveMode() function.
     *  @{
     */
        #define test_pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define test_pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define test_pin_DM_RES_UP          PIN_DM_RES_UP
        #define test_pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define test_pin_DM_OD_LO           PIN_DM_OD_LO
        #define test_pin_DM_OD_HI           PIN_DM_OD_HI
        #define test_pin_DM_STRONG          PIN_DM_STRONG
        #define test_pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define test_pin_MASK               test_pin__MASK
#define test_pin_SHIFT              test_pin__SHIFT
#define test_pin_WIDTH              1u

/* Interrupt constants */
#if defined(test_pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in test_pin_SetInterruptMode() function.
     *  @{
     */
        #define test_pin_INTR_NONE      (uint16)(0x0000u)
        #define test_pin_INTR_RISING    (uint16)(0x0001u)
        #define test_pin_INTR_FALLING   (uint16)(0x0002u)
        #define test_pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define test_pin_INTR_MASK      (0x01u) 
#endif /* (test_pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define test_pin_PS                     (* (reg8 *) test_pin__PS)
/* Data Register */
#define test_pin_DR                     (* (reg8 *) test_pin__DR)
/* Port Number */
#define test_pin_PRT_NUM                (* (reg8 *) test_pin__PRT) 
/* Connect to Analog Globals */                                                  
#define test_pin_AG                     (* (reg8 *) test_pin__AG)                       
/* Analog MUX bux enable */
#define test_pin_AMUX                   (* (reg8 *) test_pin__AMUX) 
/* Bidirectional Enable */                                                        
#define test_pin_BIE                    (* (reg8 *) test_pin__BIE)
/* Bit-mask for Aliased Register Access */
#define test_pin_BIT_MASK               (* (reg8 *) test_pin__BIT_MASK)
/* Bypass Enable */
#define test_pin_BYP                    (* (reg8 *) test_pin__BYP)
/* Port wide control signals */                                                   
#define test_pin_CTL                    (* (reg8 *) test_pin__CTL)
/* Drive Modes */
#define test_pin_DM0                    (* (reg8 *) test_pin__DM0) 
#define test_pin_DM1                    (* (reg8 *) test_pin__DM1)
#define test_pin_DM2                    (* (reg8 *) test_pin__DM2) 
/* Input Buffer Disable Override */
#define test_pin_INP_DIS                (* (reg8 *) test_pin__INP_DIS)
/* LCD Common or Segment Drive */
#define test_pin_LCD_COM_SEG            (* (reg8 *) test_pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define test_pin_LCD_EN                 (* (reg8 *) test_pin__LCD_EN)
/* Slew Rate Control */
#define test_pin_SLW                    (* (reg8 *) test_pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define test_pin_PRTDSI__CAPS_SEL       (* (reg8 *) test_pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define test_pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) test_pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define test_pin_PRTDSI__OE_SEL0        (* (reg8 *) test_pin__PRTDSI__OE_SEL0) 
#define test_pin_PRTDSI__OE_SEL1        (* (reg8 *) test_pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define test_pin_PRTDSI__OUT_SEL0       (* (reg8 *) test_pin__PRTDSI__OUT_SEL0) 
#define test_pin_PRTDSI__OUT_SEL1       (* (reg8 *) test_pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define test_pin_PRTDSI__SYNC_OUT       (* (reg8 *) test_pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(test_pin__SIO_CFG)
    #define test_pin_SIO_HYST_EN        (* (reg8 *) test_pin__SIO_HYST_EN)
    #define test_pin_SIO_REG_HIFREQ     (* (reg8 *) test_pin__SIO_REG_HIFREQ)
    #define test_pin_SIO_CFG            (* (reg8 *) test_pin__SIO_CFG)
    #define test_pin_SIO_DIFF           (* (reg8 *) test_pin__SIO_DIFF)
#endif /* (test_pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(test_pin__INTSTAT)
    #define test_pin_INTSTAT            (* (reg8 *) test_pin__INTSTAT)
    #define test_pin_SNAP               (* (reg8 *) test_pin__SNAP)
    
	#define test_pin_0_INTTYPE_REG 		(* (reg8 *) test_pin__0__INTTYPE)
#endif /* (test_pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_test_pin_H */


/* [] END OF FILE */
