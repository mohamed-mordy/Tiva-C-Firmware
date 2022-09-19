/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdg.c
 *         \brief  
 *
 *         \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Wdg.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define CLOCK_RATE 16000000

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static CallBackFuncPtr fptr;
static Wdg_InitialTimeoutType initialTimeout;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Wdg_Init(const Wdg_ConfigType *ConfigPtr)
{
    fptr = ConfigPtr->cbk_fptr;
    switch (ConfigPtr->interrupt) {
        case Standard_Interrupt:
            WDT0.CTL.B.INTTYPE = 0;
            break;
        case Non_Maskable_Interrupt:
            WDT0.CTL.B.INTTYPE = 1;
            break;
        default:
            // catch errors here
            break;
    }
    WDT0.LOAD = (initialTimeout * CLOCK_RATE) / 1000;
    WDT0.CTL.B.INTEN = 1;
}

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
Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode)
{
    //TODO
    (void)Mode; /* Unused Parameter */
    return E_NOT_OK;
}
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
void Wdg_SetTriggerCondition(uint16 timeout)
{
	WDT0.LOAD =  (timeout * CLOCK_RATE) / 1000;
}

/******************************************************************************
* \Syntax             : void Wdg_GetVersionInfo(Std_VersionInfoType* versioninfo)
* \Description        : Returns the version information of the module.
*                                                                                
* \Sync\Async         : Synchronous                                               
* \Reentrancy         : Reentrant                                             
* \Parameters (in)    : None
* \Parameters (inout) : None
* \Parameters (out)   : versioninfo Pointer to where to store the version information of the module.
* \Return value:      : None
*******************************************************************************/
void Wdg_GetVersionInfo (Std_VersionInfoType* versioninfo)
{
	// TODO
    (void)versioninfo; /* Unused Parameter */
}

/**********************************************************************************************************************
 *  END OF FILE: Wdg.c
 *********************************************************************************************************************/
