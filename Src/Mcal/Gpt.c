/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
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
#include "Mcu_Hw.h"
#include "Gpt.h"
#include "Gpt_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MAX_TIMERS_CHANNEL_NUMBER 12


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
TIMER_Type *const timers_base[MAX_TIMERS_CHANNEL_NUMBER] = {
    TIMER0_BASE,
    TIMER1_BASE,
    TIMER2_BASE,
    TIMER3_BASE,
    TIMER4_BASE,
    TIMER5_BASE,
    TIMER0_WIDE_BASE,
    TIMER1_WIDE_BASE,
    TIMER2_WIDE_BASE,
    TIMER3_WIDE_BASE,
    TIMER4_WIDE_BASE,
    TIMER5_WIDE_BASE
};

CallBackFuncPtr notification_array[MAX_TIMERS_CHANNEL_NUMBER];

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
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
* \Description     : Initializes the GPT driver.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
    Gpt_ChannelType lclChannelId;
    Gpt_ValueType lclTickFrequency;
    Gpt_ValueType lclTickFrequencyMax;
    Gpt_ChannelModeType lclChannelMode;
    CallBackFuncPtr lclNotificationFuncPtr;
    uint32 i;
    for (i = 0; i < GPT_NUMBER_OF_USED_CHANNELS; ++i) {
        lclChannelId           = ConfigPtr->configuredChannels[i].channelId;
        lclTickFrequency       = ConfigPtr->configuredChannels[i].tickFrequency;
        lclTickFrequencyMax    = ConfigPtr->configuredChannels[i].tickFrequencyMax;
        lclChannelMode         = ConfigPtr->configuredChannels[i].channelMode;
        lclNotificationFuncPtr = ConfigPtr->configuredChannels[i].notificationFuncPtr;
        // (prerequisite) The Clock for the current Timer must be enabled
        // (1) Disable the timer before making anychanges to it
        timers_base[lclChannelId]->CTL.B.TAEN = 0;
        // (2) Write the (GPTMCFG) with a value of 0x0 to select 32-bit mode or 64-bit mode for wide timers
        timers_base[lclChannelId]->CFG = 0x0;
        // (3) Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
        //      a. Write a value of 0x1 for One-Shot mode.
        //      b. Write a value of 0x2 for Periodic mode
        switch (lclChannelMode) {
            case GPT_CH_MODE_CONTINUOUS:
                timers_base[lclChannelId]->TAMR.B.TAMR = 0x2;
                break;
            case GPT_CH_MODE_ONESHOT:
                timers_base[lclChannelId]->TAMR.B.TAMR = 0x1;
                break;
            default:
                // catch errors here
                break;
        }
        // (4) Configure Count Direction in (GPTMTnMR)
        timers_base[lclChannelId]->TAMR.B.TACDIR = 0x0; // Count-Down by default (non-configurable for now)
        // (5) Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).
        // the case of 64-bit timer is not managed yet i.e., TODO
        timers_base[lclChannelId]->TAILR = lclTickFrequency;
        // (6) If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register(GPTMIMR).
        // Here I will populate the notifications_array, and the enabling and disabling of notification will be done using the Gpt_EnableNotification() and Gpt_DisableNotification()
        notification_array[lclChannelId] = lclNotificationFuncPtr;
        // (xxx) interrupt priority and enable must be done in corresponding NVIC registers
        // (7) Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
        // this will be done using Gpt_StartTimer()
        //timers_base[lclChannelId]->CTL.B.TAEN = 1;
        
        // (8) Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
        //         the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
        //         Register (GPTMICR).

    }
}

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
void Gpt_DeInit(void)
{
	
}

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
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    return (timers_base[Channel]->TAILR) - (timers_base[Channel]->TAR);
}

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
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    return timers_base[Channel]->TAR;
}

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
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    timers_base[Channel]->TAILR = Value;
    timers_base[Channel]->CTL.B.TAEN = 1;
}

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
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    timers_base[Channel]->CTL.B.TAEN = 0;
}

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
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    timers_base[Channel]->IMR.B.TATOIM = 1;  // enable interrupts in Interrupt Mask Register
}

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
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    timers_base[Channel]->IMR.B.TATOIM = 0;   // disable interrupts in Interrupt Mask Register
}

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
void Gpt_SetMode(Gpt_ModeType Mode)
{
    // TODO
	(void)Mode;
	
}

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
void Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
    // TODO
	(void)Channel;
}

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
void Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
    // TODO
	(void)Channel;
}

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
void Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    // TODO
	(void)WakeupSource;
	
}
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
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
	(void)PredefTimer;
    (void)TimeValuePtr;
}

/******************************************************************************
* \Syntax          : void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
* \Description     : Returns version information of this module.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : versionInfoPtr Pointer to where to store version info.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr)
{
    (void)VersionInfoPtr;
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/

