/*******************************************************************************
* File Name: SW_Sign_Change.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_SW_Sign_Change_H) /* CY_CONTROL_REG_SW_Sign_Change_H */
#define CY_CONTROL_REG_SW_Sign_Change_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} SW_Sign_Change_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    SW_Sign_Change_Write(uint8 control) ;
uint8   SW_Sign_Change_Read(void) ;

void SW_Sign_Change_SaveConfig(void) ;
void SW_Sign_Change_RestoreConfig(void) ;
void SW_Sign_Change_Sleep(void) ; 
void SW_Sign_Change_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define SW_Sign_Change_Control        (* (reg8 *) SW_Sign_Change_Sync_ctrl_reg__CONTROL_REG )
#define SW_Sign_Change_Control_PTR    (  (reg8 *) SW_Sign_Change_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_SW_Sign_Change_H */


/* [] END OF FILE */
