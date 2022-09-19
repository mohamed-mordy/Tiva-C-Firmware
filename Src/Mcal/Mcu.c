/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu.c
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
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

typedef enum {
    MCU_INITIALIZED,
    MCU_NOT_INITIALIZED
} Mcu_StatusType;

typedef enum {
    PERIPHERAL_PRESENT = 0,
    SOFTWARE_RESET,
    RCGC,
    SCGC,
    DCGC,
    PERIPHERAL_READY
} Mcu_PeripheralSetCtrlType;

static Mcu_StatusType g_Mcu_Status = MCU_NOT_INITIALIZED;

static const Mcu_ConfigType *g_Mcu_ConfigPtr;
static Mcu_RawResetType g_Mcu_ResetCause;
static uint32 g_Mcu_SystemCtrlBase = (uint32) SYSCTL_BASE;
static const uint32 g_Mcu_PeriphSetBlock[] = {
    0x300, /* Peripheral Present */
    0x500, /* Software Reset */
    0x600, /* Run Mode Clock Gating Control RCGCn */
    0x700, /* Sleep Mode Clock Gating Control SCGCn */
    0x800, /* Deep-Sleep Mode Clock Gating Control DCGCn */
    0xA00, /* Peripheral Ready */
};

static const uint32 g_Mcu_PeriphOffset[] = {
    0X00, /* WDT */
    0X04, /* GPT */
    0X08, /* GPIO */
    0X0C, /* UDMA */
    0X14, /* HIB */
    0X18, /* UART */
    0X1C, /* SSI */
    0X20, /* I2C */
    0X28, /* USB */
    0X34, /* CAN */
    0X38, /* ADC */
    0X3C, /* ACMP */
    0X40, /* PWM */
    0X44, /* QEI */
    0X58, /* EEPROM */
    0X5C, /* WGPT */
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
* \Syntax          : void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
* \Description     : This service initializes the MCU driver.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr Pointer to MCU driver configuration set.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
{
    // ASSERT(ConfigPtr);
    uint32 iter;
    uint32 offset;
    g_Mcu_Status = MCU_INITIALIZED;
    g_Mcu_ConfigPtr = ConfigPtr;
    for (iter = 0; iter < NUMBER_OF_CONFIGURED_PERIPHERALS; ++iter) {
        Mcu_PeripheralType lcl_peripheral   = g_Mcu_ConfigPtr -> configuredPeriphClocks[iter].peripheral;
        Mcu_PeripheralInstType lcl_instance = g_Mcu_ConfigPtr -> configuredPeriphClocks[iter].instance;
        offset = g_Mcu_PeriphSetBlock[RCGC] | g_Mcu_PeriphOffset[lcl_peripheral];
        (*((uint32 *)(g_Mcu_SystemCtrlBase | offset))) |= 1 << lcl_instance;
    }
}

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
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    uint32 *lcl_base;
    uint32 lcl_size;
    uint32 lcl_value;
    if (g_Mcu_Status != MCU_INITIALIZED || RamSection >= NUMBER_OF_CONFIGURED_RAMS_SECTIONS) {
        return E_NOT_OK;
    }
    lcl_base = g_Mcu_ConfigPtr->configuredRamSections[RamSection].base;
    lcl_size = g_Mcu_ConfigPtr->configuredRamSections[RamSection].size;
    lcl_value = g_Mcu_ConfigPtr->configuredRamSections[RamSection].value;
    while(lcl_size--) { /* Not --lcl_size */
        lcl_base[lcl_size] = lcl_value;
    }
    return E_OK;
}

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
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    /*
     * 0. Check that this function is called after the Mcu Module is initialized using Mcu_Init();
     * 1. Check that the input is a valid clock settings, otherwise return immediately with E_NOT_OK.
     * 2. Set Oscillator Source (OSCSRC)
     *      if Oscillator Source is MOSC, then set the xtal field with an appropriate value.
     * 3. Power Up PLL, if used.
     *      bypassed befor powered up.
     */
    Mcu_ClkSrcType lcl_clkSrc;
    Mcu_PllStateType lcl_pllState;
    Mcu_SysdivType lcl_sysdiv;
    if (g_Mcu_Status != MCU_INITIALIZED || ClockSetting >= NUMBER_OF_CLOCK_SETTINGS) {
        return E_NOT_OK;
    }
    lcl_clkSrc = g_Mcu_ConfigPtr -> configuredClockSettings[ClockSetting].clkSrc;
    lcl_pllState = g_Mcu_ConfigPtr -> configuredClockSettings[ClockSetting].pllState; 
    lcl_sysdiv = g_Mcu_ConfigPtr -> configuredClockSettings[ClockSetting].sysdiv;


    /* Configure SYSDIV */
    if (lcl_sysdiv.sysdivState == SYSDIV_USED) {
        SYSCTL.RCC.B.USESYSDIV = 1;
        SYSCTL.RCC.B.SYSDIV = lcl_sysdiv.sysdivValue;
    }
    
    /* Configure Clock Source */
    if (lcl_clkSrc == MOSC) {
        SYSCTL.RCC.B.MOSCDIS = 0;
        /* Configure XTAL */
        SYSCTL.RCC.B.XTAL = 0X15; /* The Crystal in tm4c123gh6pm is 16 MHz */
    }
    SYSCTL.RCC.B.OSCSRC = lcl_clkSrc;

    /* Configure PLL */
    if (lcl_pllState == PLL_ON) {
        SYSCTL.RCC.B.BYPASS = 1;
        SYSCTL.RCC.B.PWRDN = 0;
    }
    return E_OK;
}
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
Std_ReturnType Mcu_DistributePllClock(void)
{
    if (!SYSCTL.PLLSTAT.B.LOCK) { return E_NOT_OK; }
    SYSCTL.RCC2.B.BYPASS2 = 0;
    return E_OK;
}
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
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
#if defined (McuNoPll) && McuNoPll == TRUE
    return MCU_PLL_STATUS_UNDEFINED;
#endif
    if (g_Mcu_Status != MCU_INITIALIZED) {
        return MCU_PLL_STATUS_UNDEFINED;
    }
    return SYSCTL.PLLSTAT.B.LOCK ?  MCU_PLL_LOCKED : MCU_PLL_UNLOCKED;
}
 
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
Mcu_ResetType Mcu_GetResetReason(void)
{
#define MCU_RST_CAUSE_MOSCFAIL_RESET    ((uint32)1 << 16)
#define MCU_RST_CAUSE_WATCHDOG1_RESET   ((uint32)1 << 5 )
#define MCU_RST_CAUSE_SW_RESET          ((uint32)1 << 4 )
#define MCU_RST_CAUSE_WATCHDOG0_RESET   ((uint32)1 << 3 )
#define MCU_RST_CAUSE_BROWN_OUT_RESET   ((uint32)1 << 2 )
#define MCU_RST_CAUSE_POWER_ON_RESET    ((uint32)1 << 1 )
#define MCU_RST_CAUSE_EXT_RESET         ((uint32)1 << 0 )
    if (g_Mcu_Status != MCU_INITIALIZED) {
        return MCU_RESET_UNDEFINED;
    }
    if (g_Mcu_ResetCause != SYSCTL.RESC && SYSCTL.RESC != 0) {
        g_Mcu_ResetCause = SYSCTL.RESC;
        SYSCTL.RESC = 0; /* clear Reset Cause register to avoid having multiple reset reasons */
    }
    switch (g_Mcu_ResetCause) { /* break is omitted for obvious reasons */
        case MCU_RST_CAUSE_MOSCFAIL_RESET  :
            return MCU_MOSCFAIL_RESET;
        case MCU_RST_CAUSE_WATCHDOG1_RESET :
            return MCU_WATCHDOG1_RESET;
        case MCU_RST_CAUSE_SW_RESET        :
            return MCU_SW_RESET;
        case MCU_RST_CAUSE_WATCHDOG0_RESET :
            return MCU_WATCHDOG0_RESET;
        case MCU_RST_CAUSE_BROWN_OUT_RESET :
            return MCU_BROWN_OUT_RESET;
        case MCU_RST_CAUSE_POWER_ON_RESET  :
            return MCU_POWER_ON_RESET;
        case MCU_RST_CAUSE_EXT_RESET       :
            return MCU_EXT_RESET;
        default:
            return MCU_RESET_UNDEFINED;
    }
#undef MCU_RST_CAUSE_MOSCFAIL_RESET 
#undef MCU_RST_CAUSE_WATCHDOG1_RESET
#undef MCU_RST_CAUSE_SW_RESET       
#undef MCU_RST_CAUSE_WATCHDOG0_RESET
#undef MCU_RST_CAUSE_BROWN_OUT_RESET
#undef MCU_RST_CAUSE_POWER_ON_RESET 
#undef MCU_RST_CAUSE_EXT_RESET      
}

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
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
    if (g_Mcu_Status != MCU_INITIALIZED) {
        return 0XFFFFFFFF;
    }
    if (g_Mcu_ResetCause != SYSCTL.RESC && SYSCTL.RESC != 0) {
        g_Mcu_ResetCause = SYSCTL.RESC;
        SYSCTL.RESC = 0; /* clear Reset Cause register to avoid having multiple reset reasons */
    }
    return g_Mcu_ResetCause;
}

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
void Mcu_PerformReset(void)
{
    /* System Reset Request */
#define VECTKEY (uint32)0x05FA0000
    SCB.AIRCR = (SCB.AIRCR&0x0000ffff) | VECTKEY | (uint32)1 << 2;
#undef VECTKEY
}
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
void Mcu_SetMode(Mcu_ModeType McuMode)
{
    // TODO
    (void)McuMode;
}

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
void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    // TODO
    (void)versioninfo;
}
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
Mcu_RamStateType Mcu_GetRamState(void)
{
    // TODO
    return (Mcu_RamStateType)0;
}
#endif
 
/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
