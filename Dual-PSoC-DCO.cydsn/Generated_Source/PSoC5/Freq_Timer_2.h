/*******************************************************************************
* File Name: Freq_Timer_2.h
* Version 2.70
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_60_Freq_Timer_2_H)
#define CY_Timer_v2_60_Freq_Timer_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Freq_Timer_2_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_70 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define Freq_Timer_2_Resolution                 24u
#define Freq_Timer_2_UsingFixedFunction         0u
#define Freq_Timer_2_UsingHWCaptureCounter      0u
#define Freq_Timer_2_SoftwareCaptureMode        0u
#define Freq_Timer_2_SoftwareTriggerMode        0u
#define Freq_Timer_2_UsingHWEnable              1u
#define Freq_Timer_2_EnableTriggerMode          0u
#define Freq_Timer_2_InterruptOnCaptureCount    0u
#define Freq_Timer_2_RunModeUsed                0u
#define Freq_Timer_2_ControlRegRemoved          0u

#if defined(Freq_Timer_2_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define Freq_Timer_2_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (Freq_Timer_2_UsingFixedFunction)
    #define Freq_Timer_2_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define Freq_Timer_2_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End Freq_Timer_2_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!Freq_Timer_2_UsingFixedFunction)

        uint32 TimerUdb;
        uint8 InterruptMaskValue;
        #if (Freq_Timer_2_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!Freq_Timer_2_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}Freq_Timer_2_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    Freq_Timer_2_Start(void) ;
void    Freq_Timer_2_Stop(void) ;

void    Freq_Timer_2_SetInterruptMode(uint8 interruptMode) ;
uint8   Freq_Timer_2_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define Freq_Timer_2_GetInterruptSource() Freq_Timer_2_ReadStatusRegister()

#if(!Freq_Timer_2_UDB_CONTROL_REG_REMOVED)
    uint8   Freq_Timer_2_ReadControlRegister(void) ;
    void    Freq_Timer_2_WriteControlRegister(uint8 control) ;
#endif /* (!Freq_Timer_2_UDB_CONTROL_REG_REMOVED) */

uint32  Freq_Timer_2_ReadPeriod(void) ;
void    Freq_Timer_2_WritePeriod(uint32 period) ;
uint32  Freq_Timer_2_ReadCounter(void) ;
void    Freq_Timer_2_WriteCounter(uint32 counter) ;
uint32  Freq_Timer_2_ReadCapture(void) ;
void    Freq_Timer_2_SoftwareCapture(void) ;

#if(!Freq_Timer_2_UsingFixedFunction) /* UDB Prototypes */
    #if (Freq_Timer_2_SoftwareCaptureMode)
        void    Freq_Timer_2_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!Freq_Timer_2_UsingFixedFunction) */

    #if (Freq_Timer_2_SoftwareTriggerMode)
        void    Freq_Timer_2_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (Freq_Timer_2_SoftwareTriggerMode) */

    #if (Freq_Timer_2_EnableTriggerMode)
        void    Freq_Timer_2_EnableTrigger(void) ;
        void    Freq_Timer_2_DisableTrigger(void) ;
    #endif /* (Freq_Timer_2_EnableTriggerMode) */


    #if(Freq_Timer_2_InterruptOnCaptureCount)
        void    Freq_Timer_2_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (Freq_Timer_2_InterruptOnCaptureCount) */

    #if (Freq_Timer_2_UsingHWCaptureCounter)
        void    Freq_Timer_2_SetCaptureCount(uint8 captureCount) ;
        uint8   Freq_Timer_2_ReadCaptureCount(void) ;
    #endif /* (Freq_Timer_2_UsingHWCaptureCounter) */

    void Freq_Timer_2_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void Freq_Timer_2_Init(void)          ;
void Freq_Timer_2_Enable(void)        ;
void Freq_Timer_2_SaveConfig(void)    ;
void Freq_Timer_2_RestoreConfig(void) ;
void Freq_Timer_2_Sleep(void)         ;
void Freq_Timer_2_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define Freq_Timer_2__B_TIMER__CM_NONE 0
#define Freq_Timer_2__B_TIMER__CM_RISINGEDGE 1
#define Freq_Timer_2__B_TIMER__CM_FALLINGEDGE 2
#define Freq_Timer_2__B_TIMER__CM_EITHEREDGE 3
#define Freq_Timer_2__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define Freq_Timer_2__B_TIMER__TM_NONE 0x00u
#define Freq_Timer_2__B_TIMER__TM_RISINGEDGE 0x04u
#define Freq_Timer_2__B_TIMER__TM_FALLINGEDGE 0x08u
#define Freq_Timer_2__B_TIMER__TM_EITHEREDGE 0x0Cu
#define Freq_Timer_2__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define Freq_Timer_2_INIT_PERIOD             35999u
#define Freq_Timer_2_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << Freq_Timer_2_CTRL_CAP_MODE_SHIFT))
#define Freq_Timer_2_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << Freq_Timer_2_CTRL_TRIG_MODE_SHIFT))
#if (Freq_Timer_2_UsingFixedFunction)
    #define Freq_Timer_2_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Freq_Timer_2_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << Freq_Timer_2_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define Freq_Timer_2_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << Freq_Timer_2_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Freq_Timer_2_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << Freq_Timer_2_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (Freq_Timer_2_UsingFixedFunction) */
#define Freq_Timer_2_INIT_CAPTURE_COUNT      (2u)
#define Freq_Timer_2_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << Freq_Timer_2_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (Freq_Timer_2_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define Freq_Timer_2_STATUS         (*(reg8 *) Freq_Timer_2_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Freq_Timer_2_STATUS_MASK    (*(reg8 *) Freq_Timer_2_TimerHW__SR0 )
    #define Freq_Timer_2_CONTROL        (*(reg8 *) Freq_Timer_2_TimerHW__CFG0)
    #define Freq_Timer_2_CONTROL2       (*(reg8 *) Freq_Timer_2_TimerHW__CFG1)
    #define Freq_Timer_2_CONTROL2_PTR   ( (reg8 *) Freq_Timer_2_TimerHW__CFG1)
    #define Freq_Timer_2_RT1            (*(reg8 *) Freq_Timer_2_TimerHW__RT1)
    #define Freq_Timer_2_RT1_PTR        ( (reg8 *) Freq_Timer_2_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Freq_Timer_2_CONTROL3       (*(reg8 *) Freq_Timer_2_TimerHW__CFG2)
        #define Freq_Timer_2_CONTROL3_PTR   ( (reg8 *) Freq_Timer_2_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Freq_Timer_2_GLOBAL_ENABLE  (*(reg8 *) Freq_Timer_2_TimerHW__PM_ACT_CFG)
    #define Freq_Timer_2_GLOBAL_STBY_ENABLE  (*(reg8 *) Freq_Timer_2_TimerHW__PM_STBY_CFG)

    #define Freq_Timer_2_CAPTURE_LSB         (* (reg16 *) Freq_Timer_2_TimerHW__CAP0 )
    #define Freq_Timer_2_CAPTURE_LSB_PTR       ((reg16 *) Freq_Timer_2_TimerHW__CAP0 )
    #define Freq_Timer_2_PERIOD_LSB          (* (reg16 *) Freq_Timer_2_TimerHW__PER0 )
    #define Freq_Timer_2_PERIOD_LSB_PTR        ((reg16 *) Freq_Timer_2_TimerHW__PER0 )
    #define Freq_Timer_2_COUNTER_LSB         (* (reg16 *) Freq_Timer_2_TimerHW__CNT_CMP0 )
    #define Freq_Timer_2_COUNTER_LSB_PTR       ((reg16 *) Freq_Timer_2_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define Freq_Timer_2_BLOCK_EN_MASK                     Freq_Timer_2_TimerHW__PM_ACT_MSK
    #define Freq_Timer_2_BLOCK_STBY_EN_MASK                Freq_Timer_2_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define Freq_Timer_2_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define Freq_Timer_2_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define Freq_Timer_2_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define Freq_Timer_2_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define Freq_Timer_2_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define Freq_Timer_2_CTRL_ENABLE                        ((uint8)((uint8)0x01u << Freq_Timer_2_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Freq_Timer_2_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define Freq_Timer_2_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << Freq_Timer_2_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define Freq_Timer_2_CTRL_MODE_SHIFT                 0x01u
        #define Freq_Timer_2_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << Freq_Timer_2_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define Freq_Timer_2_CTRL_RCOD_SHIFT        0x02u
        #define Freq_Timer_2_CTRL_ENBL_SHIFT        0x00u
        #define Freq_Timer_2_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define Freq_Timer_2_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << Freq_Timer_2_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define Freq_Timer_2_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << Freq_Timer_2_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define Freq_Timer_2_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << Freq_Timer_2_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define Freq_Timer_2_CTRL_RCOD       ((uint8)((uint8)0x03u << Freq_Timer_2_CTRL_RCOD_SHIFT))
        #define Freq_Timer_2_CTRL_ENBL       ((uint8)((uint8)0x80u << Freq_Timer_2_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Freq_Timer_2_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define Freq_Timer_2_RT1_MASK                        ((uint8)((uint8)0x03u << Freq_Timer_2_RT1_SHIFT))
    #define Freq_Timer_2_SYNC                            ((uint8)((uint8)0x03u << Freq_Timer_2_RT1_SHIFT))
    #define Freq_Timer_2_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define Freq_Timer_2_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << Freq_Timer_2_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define Freq_Timer_2_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << Freq_Timer_2_SYNCDSI_SHIFT))

    #define Freq_Timer_2_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << Freq_Timer_2_CTRL_MODE_SHIFT))
    #define Freq_Timer_2_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << Freq_Timer_2_CTRL_MODE_SHIFT))
    #define Freq_Timer_2_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << Freq_Timer_2_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Freq_Timer_2_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Freq_Timer_2_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define Freq_Timer_2_STATUS_TC_INT_MASK_SHIFT        (Freq_Timer_2_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define Freq_Timer_2_STATUS_CAPTURE_INT_MASK_SHIFT   (Freq_Timer_2_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define Freq_Timer_2_STATUS_TC                       ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_TC_SHIFT))
    #define Freq_Timer_2_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define Freq_Timer_2_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define Freq_Timer_2_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define Freq_Timer_2_STATUS              (* (reg8 *) Freq_Timer_2_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define Freq_Timer_2_STATUS_MASK         (* (reg8 *) Freq_Timer_2_TimerUDB_rstSts_stsreg__MASK_REG)
    #define Freq_Timer_2_STATUS_AUX_CTRL     (* (reg8 *) Freq_Timer_2_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define Freq_Timer_2_CONTROL             (* (reg8 *) Freq_Timer_2_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(Freq_Timer_2_Resolution <= 8u) /* 8-bit Timer */
        #define Freq_Timer_2_CAPTURE_LSB         (* (reg8 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Freq_Timer_2_CAPTURE_LSB_PTR       ((reg8 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Freq_Timer_2_PERIOD_LSB          (* (reg8 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Freq_Timer_2_PERIOD_LSB_PTR        ((reg8 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Freq_Timer_2_COUNTER_LSB         (* (reg8 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
        #define Freq_Timer_2_COUNTER_LSB_PTR       ((reg8 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
    #elif(Freq_Timer_2_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define Freq_Timer_2_CAPTURE_LSB         (* (reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Freq_Timer_2_CAPTURE_LSB_PTR       ((reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Freq_Timer_2_PERIOD_LSB          (* (reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Freq_Timer_2_PERIOD_LSB_PTR        ((reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Freq_Timer_2_COUNTER_LSB         (* (reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
            #define Freq_Timer_2_COUNTER_LSB_PTR       ((reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Freq_Timer_2_CAPTURE_LSB         (* (reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG )
            #define Freq_Timer_2_CAPTURE_LSB_PTR       ((reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG )
            #define Freq_Timer_2_PERIOD_LSB          (* (reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG )
            #define Freq_Timer_2_PERIOD_LSB_PTR        ((reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG )
            #define Freq_Timer_2_COUNTER_LSB         (* (reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG )
            #define Freq_Timer_2_COUNTER_LSB_PTR       ((reg16 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(Freq_Timer_2_Resolution <= 24u)/* 24-bit Timer */
        #define Freq_Timer_2_CAPTURE_LSB         (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Freq_Timer_2_CAPTURE_LSB_PTR       ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
        #define Freq_Timer_2_PERIOD_LSB          (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Freq_Timer_2_PERIOD_LSB_PTR        ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
        #define Freq_Timer_2_COUNTER_LSB         (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
        #define Freq_Timer_2_COUNTER_LSB_PTR       ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Freq_Timer_2_CAPTURE_LSB         (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Freq_Timer_2_CAPTURE_LSB_PTR       ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__F0_REG )
            #define Freq_Timer_2_PERIOD_LSB          (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Freq_Timer_2_PERIOD_LSB_PTR        ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__D0_REG )
            #define Freq_Timer_2_COUNTER_LSB         (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
            #define Freq_Timer_2_COUNTER_LSB_PTR       ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Freq_Timer_2_CAPTURE_LSB         (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__32BIT_F0_REG )
            #define Freq_Timer_2_CAPTURE_LSB_PTR       ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__32BIT_F0_REG )
            #define Freq_Timer_2_PERIOD_LSB          (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__32BIT_D0_REG )
            #define Freq_Timer_2_PERIOD_LSB_PTR        ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__32BIT_D0_REG )
            #define Freq_Timer_2_COUNTER_LSB         (* (reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__32BIT_A0_REG )
            #define Freq_Timer_2_COUNTER_LSB_PTR       ((reg32 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define Freq_Timer_2_COUNTER_LSB_PTR_8BIT       ((reg8 *) Freq_Timer_2_TimerUDB_sT24_timerdp_u0__A0_REG )
    
    #if (Freq_Timer_2_UsingHWCaptureCounter)
        #define Freq_Timer_2_CAP_COUNT              (*(reg8 *) Freq_Timer_2_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Freq_Timer_2_CAP_COUNT_PTR          ( (reg8 *) Freq_Timer_2_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define Freq_Timer_2_CAPTURE_COUNT_CTRL     (*(reg8 *) Freq_Timer_2_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define Freq_Timer_2_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) Freq_Timer_2_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (Freq_Timer_2_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define Freq_Timer_2_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define Freq_Timer_2_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define Freq_Timer_2_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define Freq_Timer_2_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define Freq_Timer_2_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define Freq_Timer_2_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << Freq_Timer_2_CTRL_INTCNT_SHIFT))
    #define Freq_Timer_2_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << Freq_Timer_2_CTRL_TRIG_MODE_SHIFT))
    #define Freq_Timer_2_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << Freq_Timer_2_CTRL_TRIG_EN_SHIFT))
    #define Freq_Timer_2_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << Freq_Timer_2_CTRL_CAP_MODE_SHIFT))
    #define Freq_Timer_2_CTRL_ENABLE                    ((uint8)((uint8)0x01u << Freq_Timer_2_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define Freq_Timer_2_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define Freq_Timer_2_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define Freq_Timer_2_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define Freq_Timer_2_STATUS_TC_INT_MASK_SHIFT       Freq_Timer_2_STATUS_TC_SHIFT
    #define Freq_Timer_2_STATUS_CAPTURE_INT_MASK_SHIFT  Freq_Timer_2_STATUS_CAPTURE_SHIFT
    #define Freq_Timer_2_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define Freq_Timer_2_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define Freq_Timer_2_STATUS_FIFOFULL_INT_MASK_SHIFT Freq_Timer_2_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define Freq_Timer_2_STATUS_TC                      ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define Freq_Timer_2_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Freq_Timer_2_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Freq_Timer_2_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define Freq_Timer_2_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define Freq_Timer_2_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define Freq_Timer_2_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << Freq_Timer_2_STATUS_FIFOFULL_SHIFT))

    #define Freq_Timer_2_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define Freq_Timer_2_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define Freq_Timer_2_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define Freq_Timer_2_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define Freq_Timer_2_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define Freq_Timer_2_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_Freq_Timer_2_H */


/* [] END OF FILE */
