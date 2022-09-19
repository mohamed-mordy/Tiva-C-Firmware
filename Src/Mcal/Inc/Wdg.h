/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Wdg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __WDG_H__
#define __WDG_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef void (*CallBackFuncPtr)(void);

typedef enum {
    Standard_Interrupt,
    Non_Maskable_Interrupt
} Wdg_InterruptType;

typedef uint16 Wdg_InitialTimeoutType;

typedef uint16 Wdg_MaxTimeoutType;

typedef struct {
    CallBackFuncPtr cbk_fptr;
    Wdg_InterruptType interrupt;
    Wdg_InitialTimeoutType initialTimeout;
    Wdg_MaxTimeoutType maxTimeOut;
} Wdg_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Wdg_Init(const Wdg_ConfigType *ConfigPtr)
* \Description     : Intializes the module.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr  Pointer to configuration set. 
* \Parameters (out): None
* \Return value:   : void
*******************************************************************************/
void Wdg_Init(const Wdg_ConfigType *ConfigPtr);

#ifdef WDG_INTERFACE
/******************************************************************************
* \Syntax          : Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode)
* \Description     : Switches the watch dog into the mode Mode.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Mode  One of the following statically configured modes:
*                       1. WDGIF_OFF_MODE
*                       2. WDGIF_SLOW_MODE
*                       3. WDGIF_FAST_MODE
* \Parameters (out): None
* \Return value:   : Std_ReturnType   E_OK
*                                     E_NOT_OK
*******************************************************************************/
Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode);
#endif

/******************************************************************************
* \Syntax          : void Wdg_SetTriggerCondition(uint16 timeout)
* \Description     : Sets the timeout value for the trigger counter.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : timeout   Timeout value (milliseconds) for setting the trigger counter.
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Wdg_SetTriggerCondition(uint16 timeout);

/******************************************************************************
* \Syntax             : void Wdg_GetVersionInfo ( Std_VersionInfoType* versioninfo)
* \Description        : Returns the version information of the module.
*                                                                                
* \Sync\Async         : Synchronous                                               
* \Reentrancy         : Reentrant                                             
* \Parameters (in)    : None
* \Parameters (inout) : None
* \Parameters (out)   : versioninfo Pointer to where to store the version information of the module.
* \Return value:      : None
*******************************************************************************/
void Wdg_GetVersionInfo ( Std_VersionInfoType* versioninfo);
 
#endif  /* __WDG_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Wdg.h
 *********************************************************************************************************************/
