/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Port_Lcfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

const Port_ConfigType Port_ConfigContainer = {
    .channelConfigs[PORT_CHANNEL_00] = {
        .pinType = PORT_F_PIN_0,
        .pinDirection = PORT_PIN_IN,
        .pinMode = Port_Pin_Mode_XXX_DIO,
        .pinInternalAttach = Port_PinInternalAttach_PullUp,
        .pinOutputCurrent = Port_PinOutputCurrent_NA,
    },

    .channelConfigs[PORT_CHANNEL_01] = {
        .pinType = PORT_F_PIN_1,
        .pinDirection = PORT_PIN_OUT,
        .pinMode = Port_Pin_Mode_XXX_DIO,
        .pinInternalAttach = Port_PinInternalAttach_Default,
        .pinOutputCurrent = Port_PinOutputCurrent_8MA,
    },

    .channelConfigs[PORT_CHANNEL_02] = {
        .pinType = PORT_F_PIN_2,
        .pinDirection = PORT_PIN_OUT,
        .pinMode = Port_Pin_Mode_XXX_DIO,
        .pinInternalAttach = Port_PinInternalAttach_Default,
        .pinOutputCurrent = Port_PinOutputCurrent_8MA,
    },

    .channelConfigs[PORT_CHANNEL_03] = {
        .pinType = PORT_F_PIN_3,
        .pinDirection = PORT_PIN_OUT,
        .pinMode = Port_Pin_Mode_XXX_DIO,
        .pinInternalAttach = Port_PinInternalAttach_Default,
        .pinOutputCurrent = Port_PinOutputCurrent_8MA,
    },

    .channelConfigs[PORT_CHANNEL_04] = {
        .pinType = PORT_F_PIN_4,
        .pinDirection = PORT_PIN_IN,
        .pinMode = Port_Pin_Mode_XXX_DIO,
        .pinInternalAttach = Port_PinInternalAttach_PullUp,
        .pinOutputCurrent = Port_PinOutputCurrent_NA,
    },

};

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
