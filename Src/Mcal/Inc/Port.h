/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __PORT_H__
#define __PORT_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Port_Cfg.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define MAX_NUMBER_OF_PINS_PER_PORT              8
#define MAX_NUMBER_OF_GPIO_PORTS                 6

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/******************************************************************************
* \Name            : Port_PinType
* \Type            : uint
* \Range           : 0 - <number of port pins:> 
*                     -- Shall cover all available port pins.
*                     The type should be chosen for the specific MCU platform (best performance).
* \Description     : Data type for the symbolic name of a port pin.
*******************************************************************************/
typedef uint32 Port_PinType;

/******************************************************************************
* \Name            : Port_PinDirectionType
* \Type            : Enumeration
* \Range           : PORT_PIN_IN -- Sets port pin as input.
*                    PORT_PIN_OUT -- Sets port pin as output.
* \Description     : Possible directions of a port pin.
*******************************************************************************/
typedef enum {
    PORT_PIN_IN,
    PORT_PIN_OUT,
} Port_PinDirectionType;

/******************************************************************************
* \Name            : Port_PinModeType
* \Type            : uint
* \Range           : Implementation specific -- As several port pin modes shall be configurable on one pin,
*                    the range shall be determined by the implementation.
* \Description     : Different port pin modes.
*******************************************************************************/
typedef uint32 Port_PinModeType;

typedef struct {
    Port_PinType                pinType;
    Port_PinDirectionType       pinDirection;
    Port_PinModeType            pinMode;
    Port_PinInternalAttachType  pinInternalAttach;
    Port_PinOutputCurrentType   pinOutputCurrent;
} Port_ChannelConfigType;

/******************************************************************************
* \Name            : Port_ConfigType
* \Type            : Structure
* \Range           : Hardware Dependent Structure
*                    The contents of the initialization data structure are specific to the microcontroller.
* \Description     : Type of the external data structure containing the initialization data for this module.
*******************************************************************************/
typedef struct {
    Port_ChannelConfigType channelConfigs[NUMBER_OF_ACTIVATED_CHANNES];
} Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

extern GPIO_Type * const Ports_APB_Base[MAX_NUMBER_OF_GPIO_PORTS];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void Port_Init(const Port_ConfigType *ConfigPtr);

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
void Port_SetPinDirection(Port_PinType pin, Port_PinDirectionType direction);
#endif

/******************************************************************************
* \Syntax          : void Port_RefreshPortDirection( void)
* \Description     : Refreshes port direction.
*                                                          
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Port_RefreshPortDirection(void);

/******************************************************************************
* \Syntax          : void Port_GetVersionInfo( Std_VersionInfoType* versioninfo)
* \Description     : Returns the version information of this module.
*                                                                                                  
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): versioninfo Pointer to where to store the version information of this module.
* \Return value:   : None
*******************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo);

/******************************************************************************
* \Syntax          : void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode)
* \Description     : Sets the port pin mode.
*                                                                                   
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Pin Port Pin ID number
* \Parameters (in) : Mode New Port Pin mode to be set on port pin.
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode);

#endif  /* __PORT_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
