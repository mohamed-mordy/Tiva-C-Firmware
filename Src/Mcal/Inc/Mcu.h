/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __MCU_H__
#define __MCU_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Types.h"
#include "Mcu_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/******************************************************************************
* \Name            : Mcu_PllStatusType
* \Type            : Enumeration
* \Range           : MCU_PLL_LOCKED           0x00 PLL is locked
*                  : MCU_PLL_UNLOCKED         0x01 PLL is unlocked
*                  : MCU_PLL_STATUS_UNDEFINED 0x02 PLL Status is unknown
* \Description     : This is a status value returned by the function Mcu_GetPllStatus of the MCU module.
*******************************************************************************/
typedef enum {
    MCU_PLL_LOCKED,
    MCU_PLL_UNLOCKED,
    MCU_PLL_STATUS_UNDEFINED 
} Mcu_PllStatusType;

/******************************************************************************
* \Name            : Mcu_ClockType
* \Type            : Type Derived from uint
* \Range           : 0..<number of clock settings>- 1 --
*                    The range is dependent on the number of different clock
*                    settings provided in the configuration structure. The type shall
*                    be chosen depending on MCU platform for best performance.
* \Description     : Specifies the identification (ID) for a clock setting, which is configured in the
*                    configuration structure
*******************************************************************************/
typedef uint32 Mcu_ClockType;

/******************************************************************************
* \Name            : Mcu_ResetType
* \Type            : Enumeration
* \Range           : MCU_MOSCFAIL_RESET   0x00 Main Oscilator reset
*                  : MCU_WATCHDOG1_RESET  0x01 Watchdog 1 reset
*                  : MCU_SW_RESET         0x02 Software Reset
*                  : MCU_WATCHDOG0_RESET  0x03 Watchdog 0 reset
*                  : MCU_BROWN_OUT_RESET  0x04 Brown-out reset
*                  : MCU_POWER_ON_RESET   0x05 Power-on reset
*                  : MCU_EXT_RESET        0x06 External reset
*                  : MCU_RESET_UNDEFINED  0x07 Reset is undefined
* \Description     : This is the type of the reset enumerator containing the subset of reset types.
*                    It is not required that all reset types are supported by hardware.
*******************************************************************************/
typedef enum {
    MCU_MOSCFAIL_RESET,
    MCU_WATCHDOG1_RESET,
    MCU_SW_RESET,
    MCU_WATCHDOG0_RESET,
    MCU_BROWN_OUT_RESET,
    MCU_POWER_ON_RESET,
    MCU_EXT_RESET,
    MCU_RESET_UNDEFINED 
} Mcu_ResetType;

/******************************************************************************
* \Name            : Mcu_RawResetType
* \Type            : Type Derived from uint
* \Range           : MCU dependent register value -- The type shall be chosen depending on MCU platform for best performance.
* \Description     : This type specifies the reset reason in raw register format read from a reset status register.
*******************************************************************************/
typedef uint32 Mcu_RawResetType;

/******************************************************************************
* \Name            : Mcu_ModeType
* \Type            : Type Derived from uint
* \Range           : 0..<number of MCU modes>-1 --
*                    The range is dependent on the number of MCU modes
*                    provided in the configuration structure. The type shall be
*                    chosen depending on MCU platform for best performance.
* \Description     : This type specifies the identification (ID) for a MCU mode, which is configured in the
*                    configuration structure.
*******************************************************************************/
typedef uint32 Mcu_ModeType;

/******************************************************************************
* \Name            : Mcu_RamSectionType
* \Type            : Type Derived from uint
* \Range           : 0..< number of RAM sections>-1 --
*                    The range is dependent on the number of RAM sections
*                    provided in the configuration structure. The type shall be
*                    chosen depending on MCU platform for best performance.
* \Description     : This type specifies the identification (ID) for a RAM section, which is configured in the
*                    configuration structure.
*******************************************************************************/
typedef uint32 Mcu_RamSectionType;

/******************************************************************************
* \Name            : Mcu_RamStateType
* \Type            : Enumeration
* \Range           : MCU_RAMSTATE_INVALID 0x00 Ram content is not valid or unknown (default).
*                  : MCU_RAMSTATE_VALID   0x01 Ram content is valid:
* \Description     : This is the Ram State data type returned by the function Mcu_GetRamState of the
*                    Mcu module. It is not required that all RAM state types are supported by the hardware.
*******************************************************************************/
typedef enum {
    MCU_RAMSTATE_INVALID,
    MCU_RAMSTATE_VALID   
} Mcu_RamStateType;

/******************************************************************************
* \Name            : Mcu_ConfigType
* \Type            : Structure
* \Range           : Hardware dependent structure
* \Description     : A pointer to such a structure is provided to the MCU initialization routines for configuration.
*******************************************************************************/
typedef struct {
    Mcu_ClockSettingsType configuredClockSettings[NUMBER_OF_CLOCK_SETTINGS];
    Mcu_RamSectionConfigType configuredRamSections[NUMBER_OF_CONFIGURED_RAMS_SECTIONS];
    Mcu_PeripheralClockConfigType configuredPeriphClocks[NUMBER_OF_CONFIGURED_PERIPHERALS];
} Mcu_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
* \Description     : This service initializes the MCU driver.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr Pointer to MCU driver configuration set.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init(const Mcu_ConfigType* ConfigPtr);

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
* \Description     : This service initializes the RAM section wise.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : RamSection Selects RAM memory section provided in configuration set
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK: command has been accepted
*                                    E_NOT_OK: command has not been accepted e.g. due to parameter error
*******************************************************************************/
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);

#if defined(McuInitClockApi) && McuInitClockApi == TRUE
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
* \Description     : This service initializes the PLL and other MCU specific clock options.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting Clock setting
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK: Command has been accepted
*                                    E_NOT_OK: Command has not been accepted
*******************************************************************************/
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);
#endif
 
#if defined (McuNoPll) && McuNoPll == FALSE
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock(void)
* \Description     : This service activates the PLL clock to the MCU clock distribution.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK: Command has been accepted
*                                    E_NOT_OK: Command has not been accepted
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void);
#endif
 
/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)
* \Description     : This service provides the lock status of the PLL.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType PLL Status
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void);
 
/******************************************************************************
* \Syntax          : Mcu_ResetType Mcu_GetResetReason(void)
* \Description     : The service reads the reset type from the hardware, if supported.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : Mcu_ResetType
*******************************************************************************/
Mcu_ResetType Mcu_GetResetReason(void);
 
#if defined(McuPerformResetApi) && McuPerformResetApi == TRUE
/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)
* \Description     : The service performs a microcontroller reset.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_PerformReset(void);
#endif
 
/******************************************************************************
* \Syntax          : void Mcu_SetMode(Mcu_ModeType McuMode)
* \Description     : This service activates the MCU power modes.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : McuMode Set different MCU power modes configured in the configuration set
* \Parameters (out): None                                                      
* \Return value    : None
*******************************************************************************/
void Mcu_SetMode(Mcu_ModeType McuMode);
 
#if defined(McuVersionInfoApi) && McuVersionInfoApi == TRUE
/******************************************************************************
* \Syntax          : void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo)
* \Description     : This service returns the version information of this module.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): versioninfo Pointer to where to store the version information of this module.
* \Return value:   : None
*******************************************************************************/
void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
 
#if defined(McuGetRamStateApi) && McuGetRamStateApi == TRUE
/******************************************************************************
* \Syntax          : Mcu_RamStateType Mcu_GetRamState(void)
* \Description     : This service provides the actual status of the microcontroller Ram. (if supported)
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RamStateType Status of the Ram Content
*******************************************************************************/
Mcu_RamStateType Mcu_GetRamState(void);
#endif
 
/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)
* \Description     : The service reads the reset type from the hardware register, if supported.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType Reset raw value
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void);
 
#endif  /* __MCU_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/
