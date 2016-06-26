/*******************************************************************************
* File Name: OSC2_ADC_SAR.h
* Version 2.0
*
* Description:
*  Contains the function prototypes, constants and register definition of the
*  ADC SAR Sequencer Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_OSC2_ADC_SAR_H)
    #define CY_OSC2_ADC_SAR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "OSC2_ADC_SAR_TempBuf_dma.h"
#include "OSC2_ADC_SAR_FinalBuf_dma.h"
#include "OSC2_ADC_SAR_SAR.h"

#define OSC2_ADC_SAR_NUMBER_OF_CHANNELS    (4u)
#define OSC2_ADC_SAR_SAMPLE_MODE           (0u)
#define OSC2_ADC_SAR_CLOCK_SOURCE          (0u)

extern int16  OSC2_ADC_SAR_finalArray[OSC2_ADC_SAR_NUMBER_OF_CHANNELS];
extern uint32 OSC2_ADC_SAR_initVar;

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ADC_SAR_SEQ_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*        Function Prototypes
***************************************/
void OSC2_ADC_SAR_Init(void);
void OSC2_ADC_SAR_Enable(void);
void OSC2_ADC_SAR_Disable(void);
void OSC2_ADC_SAR_Start(void);
void OSC2_ADC_SAR_Stop(void);

uint32 OSC2_ADC_SAR_IsEndConversion(uint8 retMode);
int16 OSC2_ADC_SAR_GetResult16(uint16 chan);
int16 OSC2_ADC_SAR_GetAdcResult(void);
void OSC2_ADC_SAR_SetOffset(int32 offset);
void OSC2_ADC_SAR_SetResolution(uint8 resolution);
void OSC2_ADC_SAR_SetScaledGain(int32 adcGain);
int32 OSC2_ADC_SAR_CountsTo_mVolts(int16 adcCounts);
int32 OSC2_ADC_SAR_CountsTo_uVolts(int16 adcCounts);
float32 OSC2_ADC_SAR_CountsTo_Volts(int16 adcCounts);
void OSC2_ADC_SAR_Sleep(void);
void OSC2_ADC_SAR_Wakeup(void);
void OSC2_ADC_SAR_SaveConfig(void);
void OSC2_ADC_SAR_RestoreConfig(void);

CY_ISR_PROTO( OSC2_ADC_SAR_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void OSC2_ADC_SAR_SetGain(int32 adcGain);


/**************************************
*    Initial Parameter Constants
**************************************/
#define OSC2_ADC_SAR_IRQ_REMOVE             (0u)                /* Removes internal interrupt */


/***************************************
*             Registers
***************************************/
#define OSC2_ADC_SAR_CYCLE_COUNTER_AUX_CONTROL_REG \
                                               (*(reg8 *) OSC2_ADC_SAR_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define OSC2_ADC_SAR_CYCLE_COUNTER_AUX_CONTROL_PTR \
                                               ( (reg8 *) OSC2_ADC_SAR_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define OSC2_ADC_SAR_CONTROL_REG    (*(reg8 *) \
                                             OSC2_ADC_SAR_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define OSC2_ADC_SAR_CONTROL_PTR    ( (reg8 *) \
                                             OSC2_ADC_SAR_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define OSC2_ADC_SAR_COUNT_REG      (*(reg8 *) \
                                             OSC2_ADC_SAR_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define OSC2_ADC_SAR_COUNT_PTR      ( (reg8 *) \
                                             OSC2_ADC_SAR_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define OSC2_ADC_SAR_STATUS_REG     (*(reg8 *) OSC2_ADC_SAR_bSAR_SEQ_EOCSts__STATUS_REG)
#define OSC2_ADC_SAR_STATUS_PTR     ( (reg8 *) OSC2_ADC_SAR_bSAR_SEQ_EOCSts__STATUS_REG)

#define OSC2_ADC_SAR_SAR_DATA_ADDR_0 (OSC2_ADC_SAR_SAR_ADC_SAR__WRK0)
#define OSC2_ADC_SAR_SAR_DATA_ADDR_1 (OSC2_ADC_SAR_SAR_ADC_SAR__WRK1)
#define OSC2_ADC_SAR_SAR_DATA_ADDR_0_REG (*(reg8 *) \
                                              OSC2_ADC_SAR_SAR_ADC_SAR__WRK0)
#define OSC2_ADC_SAR_SAR_DATA_ADDR_1_REG (*(reg8 *) \
                                              OSC2_ADC_SAR_SAR_ADC_SAR__WRK1)


/**************************************
*       Register Constants
**************************************/

#if(OSC2_ADC_SAR_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define OSC2_ADC_SAR_INTC_PRIOR_NUMBER          (uint8)(OSC2_ADC_SAR_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define OSC2_ADC_SAR_INTC_NUMBER                (uint8)(OSC2_ADC_SAR_IRQ__INTC_NUMBER)

#endif   /* End OSC2_ADC_SAR_IRQ_REMOVE */


/***************************************
*       API Constants
***************************************/

/* Constants for IsEndConversion() "retMode" parameter */
#define OSC2_ADC_SAR_RETURN_STATUS              (0x01u)
#define OSC2_ADC_SAR_WAIT_FOR_RESULT            (0x00u)

/* Defines for the Resolution parameter */
#define OSC2_ADC_SAR_BITS_12    OSC2_ADC_SAR_SAR__BITS_12
#define OSC2_ADC_SAR_BITS_10    OSC2_ADC_SAR_SAR__BITS_10
#define OSC2_ADC_SAR_BITS_8     OSC2_ADC_SAR_SAR__BITS_8

#define OSC2_ADC_SAR_CYCLE_COUNTER_ENABLE    (0x20u)
#define OSC2_ADC_SAR_BASE_COMPONENT_ENABLE   (0x01u)
#define OSC2_ADC_SAR_LOAD_COUNTER_PERIOD     (0x02u)
#define OSC2_ADC_SAR_SOFTWARE_SOC_PULSE      (0x04u)

/* Generic DMA Configuration parameters */
#define OSC2_ADC_SAR_TEMP_BYTES_PER_BURST     (uint8)(2u)
#define OSC2_ADC_SAR_TEMP_TRANSFER_COUNT      ((uint16)OSC2_ADC_SAR_NUMBER_OF_CHANNELS << 1u)
#define OSC2_ADC_SAR_FINAL_BYTES_PER_BURST    ((uint16)OSC2_ADC_SAR_NUMBER_OF_CHANNELS << 1u)
#define OSC2_ADC_SAR_REQUEST_PER_BURST        (uint8)(1u)

#define OSC2_ADC_SAR_GET_RESULT_INDEX_OFFSET    ((uint8)OSC2_ADC_SAR_NUMBER_OF_CHANNELS - 1u)

/* Define for Sample Mode  */
#define OSC2_ADC_SAR_SAMPLE_MODE_FREE_RUNNING    (0x00u)
#define OSC2_ADC_SAR_SAMPLE_MODE_SW_TRIGGERED    (0x01u)
#define OSC2_ADC_SAR_SAMPLE_MODE_HW_TRIGGERED    (0x02u)

/* Define for Clock Source  */
#define OSC2_ADC_SAR_CLOCK_INTERNAL              (0x00u)
#define OSC2_ADC_SAR_CLOCK_EXTERNAL              (0x01u)


/***************************************
*        Optional Function Prototypes
***************************************/
#if(OSC2_ADC_SAR_SAMPLE_MODE != OSC2_ADC_SAR_SAMPLE_MODE_HW_TRIGGERED)
    void OSC2_ADC_SAR_StartConvert(void);
    void OSC2_ADC_SAR_StopConvert(void);
#endif /* OSC2_ADC_SAR_SAMPLE_MODE != OSC2_ADC_SAR_SAMPLE_MODE_HW_TRIGGERED */

#endif  /* !defined(CY_OSC2_ADC_SAR_H) */

/* [] END OF FILE */
