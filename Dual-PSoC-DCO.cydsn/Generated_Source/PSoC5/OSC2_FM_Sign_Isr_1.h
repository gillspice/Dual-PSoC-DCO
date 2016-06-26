/*******************************************************************************
* File Name: OSC2_FM_Sign_Isr_1.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_OSC2_FM_Sign_Isr_1_H)
#define CY_ISR_OSC2_FM_Sign_Isr_1_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void OSC2_FM_Sign_Isr_1_Start(void);
void OSC2_FM_Sign_Isr_1_StartEx(cyisraddress address);
void OSC2_FM_Sign_Isr_1_Stop(void);

CY_ISR_PROTO(OSC2_FM_Sign_Isr_1_Interrupt);

void OSC2_FM_Sign_Isr_1_SetVector(cyisraddress address);
cyisraddress OSC2_FM_Sign_Isr_1_GetVector(void);

void OSC2_FM_Sign_Isr_1_SetPriority(uint8 priority);
uint8 OSC2_FM_Sign_Isr_1_GetPriority(void);

void OSC2_FM_Sign_Isr_1_Enable(void);
uint8 OSC2_FM_Sign_Isr_1_GetState(void);
void OSC2_FM_Sign_Isr_1_Disable(void);

void OSC2_FM_Sign_Isr_1_SetPending(void);
void OSC2_FM_Sign_Isr_1_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the OSC2_FM_Sign_Isr_1 ISR. */
#define OSC2_FM_Sign_Isr_1_INTC_VECTOR            ((reg32 *) OSC2_FM_Sign_Isr_1__INTC_VECT)

/* Address of the OSC2_FM_Sign_Isr_1 ISR priority. */
#define OSC2_FM_Sign_Isr_1_INTC_PRIOR             ((reg8 *) OSC2_FM_Sign_Isr_1__INTC_PRIOR_REG)

/* Priority of the OSC2_FM_Sign_Isr_1 interrupt. */
#define OSC2_FM_Sign_Isr_1_INTC_PRIOR_NUMBER      OSC2_FM_Sign_Isr_1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable OSC2_FM_Sign_Isr_1 interrupt. */
#define OSC2_FM_Sign_Isr_1_INTC_SET_EN            ((reg32 *) OSC2_FM_Sign_Isr_1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the OSC2_FM_Sign_Isr_1 interrupt. */
#define OSC2_FM_Sign_Isr_1_INTC_CLR_EN            ((reg32 *) OSC2_FM_Sign_Isr_1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the OSC2_FM_Sign_Isr_1 interrupt state to pending. */
#define OSC2_FM_Sign_Isr_1_INTC_SET_PD            ((reg32 *) OSC2_FM_Sign_Isr_1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the OSC2_FM_Sign_Isr_1 interrupt. */
#define OSC2_FM_Sign_Isr_1_INTC_CLR_PD            ((reg32 *) OSC2_FM_Sign_Isr_1__INTC_CLR_PD_REG)


#endif /* CY_ISR_OSC2_FM_Sign_Isr_1_H */


/* [] END OF FILE */
