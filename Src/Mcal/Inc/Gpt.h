/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __GPT_H__
#define __GPT_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Gpt_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MAX_TIMERS_CHANNEL_NUMBER  12

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef void (*CallBackFuncPtr) (void);  /* A pointer to a callback function type */

typedef enum {
    GPT_CH_MODE_CONTINUOUS,
    GPT_CH_MODE_ONESHOT
} Gpt_ChannelModeType;

//typedef uint8 Gpt_ChannelType;  /* Numeric Id of a GPT Channel */
typedef enum {
    GPT_TIMER_00_32BIT,
    GPT_TIMER_01_32BIT,
    GPT_TIMER_02_32BIT,
    GPT_TIMER_03_32BIT,
    GPT_TIMER_04_32BIT,
    GPT_TIMER_05_32BIT,
    GPT_TIMER_06_64BIT,
    GPT_TIMER_07_64BIT,
    GPT_TIMER_08_64BIT,
    GPT_TIMER_09_64BIT,
    GPT_TIMER_10_64BIT,
    GPT_TIMER_11_64BIT
} Gpt_ChannelType;

typedef uint32 Gpt_ValueType;

typedef enum {
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
} Gpt_ModeType;

typedef enum {
    GPT_PREDEF_TIMER_1US_16BIT,      /* 0x00 GPT Predef Timer with tick duration 1µs and range 16bit*/   
    GPT_PREDEF_TIMER_1US_24BIT,      /* 0x01 GPT Predef Timer with tick duration 1µs and range 24bit*/     
    GPT_PREDEF_TIMER_1US_32BIT,      /* 0x02 GPT Predef Timer with tick duration 1µs and range 32bit*/     
    GPT_PREDEF_TIMER_100US_32BIT     /* 0x03 GPT Predef Timer with tick duration 100µs and range 32bit*/     
} Gpt_PredefTimerType;

typedef struct {
    Gpt_ChannelType      channelId;
    Gpt_ChannelModeType  channelMode;
    Gpt_ValueType        tickFrequency;
    Gpt_ValueType        tickFrequencyMax;
    CallBackFuncPtr      notificationFuncPtr;
} Gpt_ChannelConfigType;

typedef struct {
    Gpt_ChannelConfigType configuredChannels[GPT_NUMBER_OF_USED_CHANNELS];
} Gpt_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

extern TIMER_Type *const timers_base[MAX_TIMERS_CHANNEL_NUMBER];

extern CallBackFuncPtr notification_array[MAX_TIMERS_CHANNEL_NUMBER];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
* \Description     : Returns version information of this module.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : versionInfoPtr   Pointer to where to store version info.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);

/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
* \Description     : Initializes the GPT driver.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr);

/******************************************************************************
* \Syntax          : void Gpt_DeInit(void)
* \Description     : DeInitializes the GPT driver
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_DeInit(void);

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
* \Description     : Returns the time already elapsed
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt.channel
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  Elabsed timer value (in number of ticks)
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
* \Description     : Returns the remaining time.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt.channel
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  Remaining timer value (in number of ticks)
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);

/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
* \Description     : Starts a timer channel.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt channel
* \Parameters (in) : Value   Target time in number of ticks.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel)
* \Description     : Stops a timer channel
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt channel
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel);

/******************************************************************************
* \Syntax          : void Gpt_EnableNotification(Gpt_ChannelType Channel)
* \Description     : Enable the interrupt notification for a channel
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt channel
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel);

/******************************************************************************
* \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType Channel)
* \Description     : Disable the interrupt notification for a channel
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt channel
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel);

/******************************************************************************
* \Syntax          : void Gpt_SetMode(Gpt_ModeType Mode)
* \Description     : Sets the operation mode of the GPT.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Mode   the mode to be set for the timer
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_SetMode(Gpt_ModeType Mode);

/******************************************************************************
* \Syntax          : void Gpt_DisableWakeup(Gpt_ChannelType Channel)
* \Description     : Disables the wakeup interrupt of a channel
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt channel
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_DisableWakeup(Gpt_ChannelType Channel);

/******************************************************************************
* \Syntax          : void Gpt_EnableWakeup(Gpt_ChannelType Channel)
* \Description     : Enables the wakeup interrupt of a channel
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the Gpt channel
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_EnableWakeup(Gpt_ChannelType Channel);

#ifdef ECU_STATE_MANAGER
/******************************************************************************
* \Syntax          : void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
* \Description     : Checks if a wakeup capable Gpt.channel is the source for a wakeup event and
*                       calls the ECU state manager service EcuM_SetWakeupEvent in case of a valid
*                       Gpt.channel wakeup event.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : WakeupSource   Information on wakeup source to be checked. The associated GPT
*                                   channel can be determined from configuration data.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif

/******************************************************************************
* \Syntax          : Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
* \Description     : Delivers the current value of the desired GPT Predef Timer.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PredefTimer   GPT predef timer
* \Parameters (in) : TimeValuePtr   Pointer to time value destination data in ram
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);

 
#endif  /* __GPT_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/

