/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *         \brief
 *
 *         \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Port_Cfg.h"
#include "Port_Lcfg.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
typedef enum {
    PORT_INITIALIZED,
    PORT_NOT_INTIALIZED
} Port_StateType;

static Port_StateType g_PortState = PORT_NOT_INTIALIZED;
static const Port_ConfigType *g_Port_ConfigPtr = NULL_PTR;

GPIO_Type * const Ports_APB_Base[MAX_NUMBER_OF_GPIO_PORTS] = {
    PORT_A_APB_BASE,
    PORT_B_APB_BASE,
    PORT_C_APB_BASE,
    PORT_D_APB_BASE,
    PORT_E_APB_BASE,
    PORT_F_APB_BASE
};

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
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)
* \Description     : Initializes the Port Driver module.
*                                                                     
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ConfigPtr Pointer to configuration set.
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    Port_PinType                pinID;
    Port_PinDirectionType       pinDirection;
    Port_PinModeType            pinMode;
    Port_PinInternalAttachType  internalAttach;
    Port_PinOutputCurrentType   outputCurrent;
    uint8 i, pinIndex, portIndex;

    g_Port_ConfigPtr = ConfigPtr;

    for (i = 0; i < PORT_ACTIVATED_CHANNELS_SIZE; ++i) {
        pinID          = g_Port_ConfigPtr->channelConfigs[i].pinType;
        pinDirection   = g_Port_ConfigPtr->channelConfigs[i].pinDirection;
        pinMode        = g_Port_ConfigPtr->channelConfigs[i].pinMode;
        internalAttach = g_Port_ConfigPtr->channelConfigs[i].pinInternalAttach;
        outputCurrent  = g_Port_ConfigPtr->channelConfigs[i].pinOutputCurrent;

        pinIndex  = pinID % MAX_NUMBER_OF_PINS_PER_PORT;
        portIndex = pinID / MAX_NUMBER_OF_PINS_PER_PORT;

        /* Unlock The port and set the Commit Register for the specified pin */
        Ports_APB_Base[portIndex]->LOCK = 0x4C4F434B; // Unlock
        Ports_APB_Base[portIndex]->CR |= 1<<pinIndex;  // Commit

        /* (1) Set Pin Direction */
        switch (pinDirection) {
            case PORT_PIN_IN:
                Ports_APB_Base[portIndex]->DIR &= ~((uint32)0 << pinIndex);
                break;
            case PORT_PIN_OUT:
                Ports_APB_Base[portIndex]->DIR |= ((uint32)1 << pinIndex);
                break;
        }

        /* (2) Set Pin Mode */
        switch (pinMode) {
            case Port_Pin_Mode_XXX_DIO:
                Ports_APB_Base[portIndex]->DEN |= ((uint32)1 << pinIndex);
                break;
            default:
                break;
        }
        /* (3) Set Pin Internal Attach */
        switch (internalAttach) {
            case Port_PinInternalAttach_PullUp:
                Ports_APB_Base[portIndex]->PUR |= ((uint32)1 << pinIndex);
                break;
            case Port_PinInternalAttach_PullDown:
                Ports_APB_Base[portIndex]->PDR |= ((uint32)1 << pinIndex);
                break;
            case Port_PinInternalAttach_OpenDrain:
                Ports_APB_Base[portIndex]->ODR |= ((uint32)1 << pinIndex);
                break;
            case Port_PinInternalAttach_Default:
                break;
        }
        /* (4) Set Pin OutputCurrent */
        switch (outputCurrent) {
            case Port_PinOutputCurrent_2MA:
                Ports_APB_Base[portIndex]->DR2R |= ((uint32)1 << pinIndex);
                break;
            case Port_PinOutputCurrent_4MA:
                Ports_APB_Base[portIndex]->DR4R |= ((uint32)1 << pinIndex);
                break;
            case Port_PinOutputCurrent_8MA:
                Ports_APB_Base[portIndex]->DR8R |= ((uint32)1 << pinIndex);
                break;
            case Port_PinOutputCurrent_NA:
                break;
        }
        Ports_APB_Base[portIndex]->LOCK = 0; // Lock
    } /* for loop */
    g_PortState = PORT_INITIALIZED;
}

#if defined(PortSetPinDirectionApi) && PortSetPinDirectionApi == TRUE
/******************************************************************************
* \Syntax          : void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction)
* \Description     : Sets the port pin direction
*                                                                                                  
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Pin Port Pin ID number
* \Parameters (in) : Direction Port Pin Direction
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Port_SetPinDirection(Port_PinType pin, Port_PinDirectionType direction)
{
    (void)pin;
    (void)direction;
}
#endif

/******************************************************************************
* \Syntax          : void Port_RefreshPortDirection( void)
* \Description     : Refreshes port direction.
*                                                          
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value    : None
*******************************************************************************/
void Port_RefreshPortDirection( void)
{

}

/******************************************************************************
* \Syntax          : void Port_GetVersionInfo( Std_VersionInfoType* versioninfo)
* \Description     : Returns the version information of this module.
*                                                                                                  
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): versioninfo Pointer to where to store the version information of this module.
* \Return value    : None
*******************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo)
{
    (void)versioninfo;
}

/******************************************************************************
* \Syntax          : void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode)
* \Description     : Sets the port pin mode.
*                                                                                   
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Pin Port Pin ID number
* \Parameters (in) : Mode New Port Pin mode to be set on port pin.
* \Parameters (out): None
* \Return value    : None
*******************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode)
{
    (void)Pin;
    (void)Mode;
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/

