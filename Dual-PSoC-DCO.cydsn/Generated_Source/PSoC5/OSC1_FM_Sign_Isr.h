/*******************************************************************************
* File Name: OSC1_FM_Sign_Isr.h
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
#if !defined(CY_ISR_OSC1_FM_Sign_Isr_H)
#define CY_ISR_OSC1_FM_Sign_Isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void OSC1_FM_Sign_Isr_Start(void);
void OSC1_FM_Sign_Isr_StartEx(cyisraddress address);
void OSC1_FM_Sign_Isr_Stop(void);

CY_ISR_PROTO(OSC1_FM_Sign_Isr_Interrupt);

void OSC1_FM_Sign_Isr_SetVector(cyisraddress address);
cyisraddress OSC1_FM_Sign_Isr_GetVector(void);

void OSC1_FM_Sign_Isr_SetPriority(uint8 priority);
uint8 OSC1_FM_Sign_Isr_GetPriority(void);

void OSC1_FM_Sign_Isr_Enable(void);
uint8 OSC1_FM_Sign_Isr_GetState(void);
void OSC1_FM_Sign_Isr_Disable(void);

void OSC1_FM_Sign_Isr_SetPending(void);
void OSC1_FM_Sign_Isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the OSC1_FM_Sign_Isr ISR. */
#define OSC1_FM_Sign_Isr_INTC_VECTOR            ((reg32 *) OSC1_FM_Sign_Isr__INTC_VECT)

/* Address of the OSC1_FM_Sign_Isr ISR priority. */
#define OSC1_FM_Sign_Isr_INTC_PRIOR             ((reg8 *) OSC1_FM_Sign_Isr__INTC_PRIOR_REG)

/* Priority of the OSC1_FM_Sign_Isr interrupt. */
#define OSC1_FM_Sign_Isr_INTC_PRIOR_NUMBER      OSC1_FM_Sign_Isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable OSC1_FM_Sign_Isr interrupt. */
#define OSC1_FM_Sign_Isr_INTC_SET_EN            ((reg32 *) OSC1_FM_Sign_Isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the OSC1_FM_Sign_Isr interrupt. */
#define OSC1_FM_Sign_Isr_INTC_CLR_EN            ((reg32 *) OSC1_FM_Sign_Isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the OSC1_FM_Sign_Isr interrupt state to pending. */
#define OSC1_FM_Sign_Isr_INTC_SET_PD            ((reg32 *) OSC1_FM_Sign_Isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the OSC1_FM_Sign_Isr interrupt. */
#define OSC1_FM_Sign_Isr_INTC_CLR_PD            ((reg32 *) OSC1_FM_Sign_Isr__INTC_CLR_PD_REG)


#endif /* CY_ISR_OSC1_FM_Sign_Isr_H */


/* [] END OF FILE */
