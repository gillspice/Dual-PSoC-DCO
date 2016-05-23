/*******************************************************************************
* File Name: OSC1_Mux_1.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the AMuxSeq.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUXSEQ_OSC1_Mux_1_H)
#define CY_AMUXSEQ_OSC1_Mux_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define OSC1_Mux_1_MUX_SINGLE 1
#define OSC1_Mux_1_MUX_DIFF   2
#define OSC1_Mux_1_MUXTYPE    1


/***************************************
*        Function Prototypes
***************************************/

void OSC1_Mux_1_Start(void);
void OSC1_Mux_1_Init(void);
void OSC1_Mux_1_Stop(void);
#if (OSC1_Mux_1_MUXTYPE == OSC1_Mux_1_MUX_DIFF)
void OSC1_Mux_1_Next(void);
void OSC1_Mux_1_DisconnectAll(void);
#else
/* The Next and DisconnectAll functions are declared in cyfitter_cfg.h. */
/* void OSC1_Mux_1_Next(void); */
/* void OSC1_Mux_1_DisconnectAll(void); */
#endif
int8 OSC1_Mux_1_GetChannel(void);


/***************************************
*           Global Variables
***************************************/

extern uint8 OSC1_Mux_1_initVar;


/***************************************
*         Parameter Constants
***************************************/
#define OSC1_Mux_1_CHANNELS 2


#endif /* CY_AMUXSEQ_OSC1_Mux_1_H */


/* [] END OF FILE */
