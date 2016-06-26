/*******************************************************************************
* File Name: OSC1_ADC_SAR.c
* Version 2.0
*
* Description:
*  This file provides the API functionality of the ADC SAR Sequencer Component
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

#include "OSC1_ADC_SAR.h"
#if(OSC1_ADC_SAR_IRQ_REMOVE == 0u)
    #include "OSC1_ADC_SAR_IRQ.h"
#endif   /* End OSC1_ADC_SAR_IRQ_REMOVE */

int16  OSC1_ADC_SAR_finalArray[OSC1_ADC_SAR_NUMBER_OF_CHANNELS];
uint32 OSC1_ADC_SAR_initVar = 0u;
static uint8 OSC1_ADC_SAR_tempChan;
static uint8 OSC1_ADC_SAR_finalChan;
static uint8 OSC1_ADC_SAR_tempTD = CY_DMA_INVALID_TD;
static uint8 OSC1_ADC_SAR_finalTD = CY_DMA_INVALID_TD;


/****************************************************************************
* Function Name: OSC1_ADC_SAR_Disable()
*****************************************************************************
*
* Summary:
*  Disables the component without disabling the ADC SAR.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
****************************************************************************/
void OSC1_ADC_SAR_Disable(void)
{
    OSC1_ADC_SAR_CONTROL_REG &= ((uint8)(~OSC1_ADC_SAR_BASE_COMPONENT_ENABLE));

    (void) CyDmaChDisable(OSC1_ADC_SAR_tempChan);
    CyDmaTdFree(OSC1_ADC_SAR_tempTD);
    OSC1_ADC_SAR_tempTD = CY_DMA_INVALID_TD;

    (void) CyDmaChDisable(OSC1_ADC_SAR_finalChan);
    CyDmaTdFree(OSC1_ADC_SAR_finalTD);
    OSC1_ADC_SAR_finalTD = CY_DMA_INVALID_TD;
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_Init
********************************************************************************
*
* Summary:
*  Inits channels for DMA transfer. Provides loading period to the AMUX address
*  selection counter
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC1_ADC_SAR_Init(void)
{
    /* Init DMA, 2 bytes bursts, each burst requires a request */
    OSC1_ADC_SAR_tempChan = OSC1_ADC_SAR_TempBuf_DmaInitialize(OSC1_ADC_SAR_TEMP_BYTES_PER_BURST,
        OSC1_ADC_SAR_REQUEST_PER_BURST, (uint16)(HI16(CYDEV_PERIPH_BASE)), (uint16)(HI16(CYDEV_SRAM_BASE)));

    /* Init DMA, (OSC1_ADC_SAR_NUMBER_OF_CHANNELS << 1u) bytes bursts, each burst requires a request */
    OSC1_ADC_SAR_finalChan = OSC1_ADC_SAR_FinalBuf_DmaInitialize((uint8)OSC1_ADC_SAR_FINAL_BYTES_PER_BURST,
        OSC1_ADC_SAR_REQUEST_PER_BURST, (uint16)(HI16(CYDEV_SRAM_BASE)), (uint16)(HI16(CYDEV_SRAM_BASE)));

    #if(OSC1_ADC_SAR_IRQ_REMOVE == 0u)
        /* Set the ISR to point to the OSC1_ADC_SAR_IRQ Interrupt. */
        OSC1_ADC_SAR_IRQ_SetVector(&OSC1_ADC_SAR_ISR);
        /* Set the priority. */
        OSC1_ADC_SAR_IRQ_SetPriority((uint8)OSC1_ADC_SAR_INTC_NUMBER);
    #endif   /* End OSC1_ADC_SAR_IRQ_REMOVE */

}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_Enable
********************************************************************************
*
* Summary:
*  Enables DMA channels, address selection counter and FSM of Base component
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC1_ADC_SAR_Enable(void)
{
    uint8 enableInterrupts;

    static int16 OSC1_ADC_SAR_tempArray[OSC1_ADC_SAR_NUMBER_OF_CHANNELS];
    
    (void)CyDmaClearPendingDrq(OSC1_ADC_SAR_tempChan);
    (void)CyDmaClearPendingDrq(OSC1_ADC_SAR_finalChan);
    
    
    /* Provides initialization procedure for the TempBuf DMA
    * Configure this Td as follows:
    *  - The TD is looping on itself
    *  - Increment the destination address, but not the source address
    */

    if (OSC1_ADC_SAR_tempTD == DMA_INVALID_TD)
    {
        OSC1_ADC_SAR_tempTD = CyDmaTdAllocate();
    }

    (void) CyDmaTdSetConfiguration(OSC1_ADC_SAR_tempTD, OSC1_ADC_SAR_TEMP_TRANSFER_COUNT,
        OSC1_ADC_SAR_tempTD, ((uint8)OSC1_ADC_SAR_TempBuf__TD_TERMOUT_EN | (uint8)TD_INC_DST_ADR));

    /* From the SAR to the TempArray */
    (void) CyDmaTdSetAddress(OSC1_ADC_SAR_tempTD, (uint16)(LO16((uint32)OSC1_ADC_SAR_SAR_DATA_ADDR_0)),
        (uint16)(LO16((uint32)OSC1_ADC_SAR_tempArray)));

    /* Associate the TD with the channel */
    (void) CyDmaChSetInitialTd(OSC1_ADC_SAR_tempChan, OSC1_ADC_SAR_tempTD);


    /* Provides initialization procedure for the FinalBuf DMA
    * Configure this Td as follows:
    *  - The TD is looping on itself
    *  - Increment the source and destination address
    */

    if (OSC1_ADC_SAR_finalTD == DMA_INVALID_TD)
    {
        OSC1_ADC_SAR_finalTD = CyDmaTdAllocate();
    }
    
    (void) CyDmaTdSetConfiguration(OSC1_ADC_SAR_finalTD, (OSC1_ADC_SAR_FINAL_BYTES_PER_BURST),
        OSC1_ADC_SAR_finalTD, ((uint8)(OSC1_ADC_SAR_FinalBuf__TD_TERMOUT_EN) | (uint8)TD_INC_SRC_ADR |
            (uint8)TD_INC_DST_ADR));

    /* From the the TempArray to Final Array */
    (void) CyDmaTdSetAddress(OSC1_ADC_SAR_finalTD, (uint16)(LO16((uint32)OSC1_ADC_SAR_tempArray)),
        (uint16)(LO16((uint32)OSC1_ADC_SAR_finalArray)));

    /* Associate the TD with the channel */
    (void) CyDmaChSetInitialTd(OSC1_ADC_SAR_finalChan, OSC1_ADC_SAR_finalTD);
    
    (void) CyDmaChEnable(OSC1_ADC_SAR_tempChan, 1u);
    (void) CyDmaChEnable(OSC1_ADC_SAR_finalChan, 1u);

    /* Enable Counter and give Enable pulse to set an address of the last channel */
    enableInterrupts = CyEnterCriticalSection();
    OSC1_ADC_SAR_CYCLE_COUNTER_AUX_CONTROL_REG |= ((uint8)(OSC1_ADC_SAR_CYCLE_COUNTER_ENABLE));
    CyExitCriticalSection(enableInterrupts);

    /* Enable FSM of the Base Component */
    OSC1_ADC_SAR_CONTROL_REG |= ((uint8)(OSC1_ADC_SAR_BASE_COMPONENT_ENABLE));
    OSC1_ADC_SAR_CONTROL_REG |= ((uint8)(OSC1_ADC_SAR_LOAD_COUNTER_PERIOD));

    #if(OSC1_ADC_SAR_IRQ_REMOVE == 0u)
        /* Clear a pending interrupt */
        CyIntClearPending(OSC1_ADC_SAR_INTC_NUMBER);
    #endif   /* End OSC1_ADC_SAR_IRQ_REMOVE */
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_Start
********************************************************************************
*
* Summary:
*  Starts component
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  If the initVar variable is already set, this function only calls the 
*  OSC1_ADC_SAR_Enable() function
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC1_ADC_SAR_Start(void)
{
    if(OSC1_ADC_SAR_initVar == 0u)
    {
        OSC1_ADC_SAR_Init();
        OSC1_ADC_SAR_initVar = 1u;
    }

    OSC1_ADC_SAR_Enable();
    OSC1_ADC_SAR_SAR_Start();
    (void) CY_GET_REG8(OSC1_ADC_SAR_STATUS_PTR);

}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_Stop
********************************************************************************
*
* Summary:
*  Stops component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC1_ADC_SAR_Stop(void)
{
    OSC1_ADC_SAR_SAR_Stop();
    OSC1_ADC_SAR_Disable();
}

#if(OSC1_ADC_SAR_SAMPLE_MODE != OSC1_ADC_SAR_SAMPLE_MODE_HW_TRIGGERED)

    /*******************************************************************************
    * Function Name: OSC1_ADC_SAR_StartConvert
    ********************************************************************************
    *
    * Summary:
    *  When the Sample Mode parameter is set to 'Free Running', the component will
    * operate in a continuous mode. The channels will be scanned continuously until
    * _StopConvert()or  _Stop() is called
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  Calling OSC1_ADC_SAR_StartConvert() disables the external SOC pin.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void OSC1_ADC_SAR_StartConvert(void)
    {
        #if(OSC1_ADC_SAR_SAMPLE_MODE != OSC1_ADC_SAR_SAMPLE_MODE_FREE_RUNNING)

            OSC1_ADC_SAR_CONTROL_REG |= ((uint8)(OSC1_ADC_SAR_SOFTWARE_SOC_PULSE));

        #else

            OSC1_ADC_SAR_SAR_StartConvert();

        #endif /*
                 #if(OSC1_ADC_SAR_SAMPLE_MODE !=
                 OSC1_ADC_SAR_SAMPLE_MODE_FREE_RUNNING)
               */
    }


    /*******************************************************************************
    * Function Name: OSC1_ADC_SAR_StopConvert
    ********************************************************************************
    *
    * Summary:
    *  Forces the component to stop all conversions
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  In free-running and software trigger mode, this function sets a software 
    *  version of the SOC to low level and switches the SOC source to hardware SOC 
    *  input (Hardware trigger).
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void OSC1_ADC_SAR_StopConvert(void)
    {
        OSC1_ADC_SAR_SAR_StopConvert();
    }

#endif /* OSC1_ADC_SAR_SAMPLE_MODE != OSC1_ADC_SAR_SAMPLE_MODE_HW_TRIGGERED */


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_IsEndConversion
********************************************************************************
*
* Summary:
*  Checks for ADC end of conversion for the case one channel and end of scan
*  for the case of multiple channels
*
* Parameters:
*  retMode: Check conversion return mode
*   Values:
*         - OSC1_ADC_SAR_RETURN_STATUS      - Immediately returns the 
*                                                 status
*         - OSC1_ADC_SAR_WAIT_FOR_RESULT    - Does not return a result 
*                                                 until the conversion 
*                                                 is complete
*
* Return:
*  If a nonzero value is returned, the last conversion is complete. If the 
*  returned value is zero, the ADC_SAR_Seq is still calculating the last result
*
* Side Effects:
*  This function reads the end of conversion status, which is cleared on read
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint32 OSC1_ADC_SAR_IsEndConversion(uint8 retMode)
{
    uint8 status;

    do
    {
      status = OSC1_ADC_SAR_STATUS_REG;
    } while ((status == 0u) && (retMode == OSC1_ADC_SAR_WAIT_FOR_RESULT));

    return((uint32)status);
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_GetResult16
********************************************************************************
*
* Summary:
*  Returns the ADC result for channel chan
*
* Parameters:
*  chan: The ADC channel in which to return the result. The first channel is 0 
*        and the last channel is the total number of channels - 1
*
* Return:
*  Returns converted data as a signed 16-bit integer
*
* Side Effects:
*  Converts the ADC counts to the 2's complement form
*
* Reentrant:
*  No.
*
*******************************************************************************/
int16 OSC1_ADC_SAR_GetResult16(uint16 chan)
{
    return (OSC1_ADC_SAR_finalArray[OSC1_ADC_SAR_GET_RESULT_INDEX_OFFSET - chan] - OSC1_ADC_SAR_SAR_shift);
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_GetAdcResult
********************************************************************************
*
* Summary:
*  Gets the data available in the SAR DATA register, not the results buffer
*
* Parameters:
*  None.
*
* Return:
*  The last ADC conversion result
*
* Side Effects:
*  Converts the ADC counts to the 2's complement form
*
* Reentrant:
*  No.
*
*******************************************************************************/
int16 OSC1_ADC_SAR_GetAdcResult(void)
{
    return (OSC1_ADC_SAR_SAR_GetResult16());
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_SetOffset
********************************************************************************
*
* Summary:
*  Sets the ADC offset which is used by the functions _CountsTo_uVolts(),
*  _CountsTo_mVolts() and _CountsTo_Volts() to substract the offset from the
*  given reading before calculating the voltage conversion
*
* Parameters:
*  offset: This value is measured when the inputs are shorted or connected to
*  the same input voltage
*
* Return:
*  None.
*
* Side Effects:
*  Affects OSC1_ADC_SAR_CountsTo_Volts(), 
*  OSC1_ADC_SAR_CountsTo_mVolts(), and OSC1_ADC_SAR_CountsTo_uVolts() 
*  by subtracting the given offset.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC1_ADC_SAR_SetOffset(int32 offset)
{
    OSC1_ADC_SAR_SAR_SetOffset((int16)offset);
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_SetResolution
********************************************************************************
*
* Summary:
*  Sets the Relution of the SAR.
*  This function does not affect the actual conversion with PSoC5 ES1 silicon.
*
* Parameters:
*  resolution:
*  12 ->    RES12
*  10 ->    RES10
*  8  ->    RES8
*
* Return:
*  None.
*
* Side Effects:
*  The ADC_SAR_Seq resolution cannot be changed during a conversion cycle. The
*  recommended best practice is to stop conversions with
*  OSC1_ADC_SAR_StopConvert(), change the resolution, then restart the
*  conversions with OSC1_ADC_SAR_StartConvert().
*  If you decide not to stop conversions before calling this API, you
*  should use OSC1_ADC_SAR_IsEndConversion() to wait until conversion is 
*  complete  before changing the resolution.
*  If you call ADC_SetResolution() during a conversion, the resolution will
*  not be changed until the current conversion is complete. Data will not be
*  available in the new resolution for another 6 + "New Resolution(in bits)"
*  clock cycles.
*  You may need add a delay of this number of clock cycles after
*  OSC1_ADC_SAR_SetResolution() is called before data is valid again.
*  Affects OSC1_ADC_SAR_CountsTo_Volts(), OSC1_ADC_SAR_CountsTo_mVolts(), 
*  and OSC1_ADC_SAR_CountsTo_uVolts() by calculating the correct conversion 
*  between ADC counts and the applied input voltage. Calculation depends on 
*  resolution, input range, and voltage reference.
*
*******************************************************************************/
void OSC1_ADC_SAR_SetResolution(uint8 resolution)
{
    OSC1_ADC_SAR_SAR_SetResolution(resolution);
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_SetGain
********************************************************************************
*
* Summary:
*  Sets the ADC gain in counts per volt for the voltage conversion
*
* Parameters:
*  adcGain: counts per volt
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC1_ADC_SAR_SetGain(int32 adcGain)
{
    OSC1_ADC_SAR_SAR_SetGain((int16)adcGain);
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_SetScaledGain
********************************************************************************
*
* Summary:
*  Sets the ADC gain in counts per 10 volts for the voltage conversion functions
*  that follow. This value is set by default by the reference and input range
*  settings. It should only be used to further calibrate the ADC with a known
*  input or if the ADC is using an external reference.
*
* Parameters:
*  int32  adcGain  counts per 10 volt
*
* Return:
*  None.
*
* Side Effects:
*  Affects OSC1_ADC_SAR_CountsTo_Volts(), OSC1_ADC_SAR_CountsTo_mVolts(),
*  OSC1_ADC_SAR_CountsTo_uVolts() by supplying the correct conversion 
*  between ADC counts and the applied input voltage
*
* Reentrant:
*  No.
*
*******************************************************************************/
void OSC1_ADC_SAR_SetScaledGain(int32 adcGain)
{
    OSC1_ADC_SAR_SAR_SetScaledGain(adcGain);
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_CountsTo_mVolts
********************************************************************************
*
* Summary:
*  Converts the ADC output to mVolts as a 32-bit integer
*
* Parameters:
*  adcCounts: Result from the ADC_SAR_Seq conversion
*
* Return:
*  Result in mV
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
int32 OSC1_ADC_SAR_CountsTo_mVolts(int16 adcCounts)
{
    return ((int32) OSC1_ADC_SAR_SAR_CountsTo_mVolts(adcCounts));
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_CountsTo_uVolts
********************************************************************************
*
* Summary:
*  Converts the ADC output to uVolts as a 32-bit integer
*
* Parameters:
*  adcCounts: Result from the ADC conversion
*
* Return:
*  Result in uV
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
int32 OSC1_ADC_SAR_CountsTo_uVolts(int16 adcCounts)
{
    return (OSC1_ADC_SAR_SAR_CountsTo_uVolts(adcCounts));
}


/*******************************************************************************
* Function Name: OSC1_ADC_SAR_CountsTo_Volts
********************************************************************************
*
* Summary:
*  Converts the ADC output to Volts as a floating point number
*
* Parameters:
*  adcCounts: Result from the ADC_SAR_Seq conversion
*
* Return:
*  Result in volts
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
float32 OSC1_ADC_SAR_CountsTo_Volts(int16 adcCounts)
{
    return (OSC1_ADC_SAR_SAR_CountsTo_Volts(adcCounts));
}


/* [] END OF FILE */
