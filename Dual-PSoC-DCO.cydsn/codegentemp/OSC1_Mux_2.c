/*******************************************************************************
* File Name: OSC1_Mux_2.c
* Version 1.80
*
*  Description:
*    This file contains functions for the AMuxSeq.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "OSC1_Mux_2.h"

uint8 OSC1_Mux_2_initVar = 0u;


/*******************************************************************************
* Function Name: OSC1_Mux_2_Start
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Mux_2_Start(void)
{
    OSC1_Mux_2_DisconnectAll();
    OSC1_Mux_2_initVar = 1u;
}


/*******************************************************************************
* Function Name: OSC1_Mux_2_Init
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Mux_2_Init(void)
{
    OSC1_Mux_2_DisconnectAll();
}


/*******************************************************************************
* Function Name: OSC1_Mux_2_Stop
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Mux_2_Stop(void)
{
    OSC1_Mux_2_DisconnectAll();
}

#if (OSC1_Mux_2_MUXTYPE == OSC1_Mux_2_MUX_DIFF)

/*******************************************************************************
* Function Name: OSC1_Mux_2_Next
********************************************************************************
* Summary:
*  Disconnects the previous channel and connects the next one in the sequence.
*  When Next is called for the first time after Init, Start, Enable, Stop, or
*  DisconnectAll, it connects channel 0.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Mux_2_Next(void)
{
    OSC1_Mux_2_CYAMUXSIDE_A_Next();
    OSC1_Mux_2_CYAMUXSIDE_B_Next();
}


/*******************************************************************************
* Function Name: OSC1_Mux_2_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels. The next time Next is called, channel
*  0 will be connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void OSC1_Mux_2_DisconnectAll(void)
{
    OSC1_Mux_2_CYAMUXSIDE_A_DisconnectAll();
    OSC1_Mux_2_CYAMUXSIDE_B_DisconnectAll();
}


/*******************************************************************************
* Function Name: OSC1_Mux_2_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 OSC1_Mux_2_GetChannel(void)
{
    return OSC1_Mux_2_CYAMUXSIDE_A_curChannel;
}

#else

/*******************************************************************************
* Function Name: OSC1_Mux_2_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 OSC1_Mux_2_GetChannel(void)
{
    return OSC1_Mux_2_curChannel;
}

#endif


/* [] END OF FILE */
