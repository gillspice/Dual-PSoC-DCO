/*******************************************************************************
* File Name: OSC1_Mux_3.h
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

#if !defined(CY_AMUXSEQ_OSC1_Mux_3_H)
#define CY_AMUXSEQ_OSC1_Mux_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define OSC1_Mux_3_MUX_SINGLE 1
#define OSC1_Mux_3_MUX_DIFF   2
#define OSC1_Mux_3_MUXTYPE    1


/***************************************
*        Function Prototypes
***************************************/

void OSC1_Mux_3_Start(void);
void OSC1_Mux_3_Init(void);
void OSC1_Mux_3_Stop(void);
#if (OSC1_Mux_3_MUXTYPE == OSC1_Mux_3_MUX_DIFF)
void OSC1_Mux_3_Next(void);
void OSC1_Mux_3_DisconnectAll(void);
#else
/* The Next and DisconnectAll functions are declared in cyfitter_cfg.h. */
/* void OSC1_Mux_3_Next(void); */
/* void OSC1_Mux_3_DisconnectAll(void); */
#endif
int8 OSC1_Mux_3_GetChannel(void);


/***************************************
*           Global Variables
***************************************/

extern uint8 OSC1_Mux_3_initVar;


/***************************************
*         Parameter Constants
***************************************/
#define OSC1_Mux_3_CHANNELS 2


#endif /* CY_AMUXSEQ_OSC1_Mux_3_H */


/* [] END OF FILE */
