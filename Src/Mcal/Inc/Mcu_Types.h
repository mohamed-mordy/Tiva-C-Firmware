/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __MCU_TYPES_H__
#define __MCU_TYPES_H__

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
typedef enum {
    MOSC,
    PIOSC,
    PIOSC_DIV_4,
    LFOSC,
//  HOSC
} Mcu_ClkSrcType;

typedef enum {
    PLL_ON,
    PLL_OFF,
} Mcu_PllStateType;

typedef uint32 Mcu_SysdivValueType;

typedef enum {
    SYSDIV_USED,
    SYSDIV_NOT_USED
} Mcu_SysdivStateType;

typedef struct {
    Mcu_SysdivStateType sysdivState;
    Mcu_SysdivValueType sysdivValue;
} Mcu_SysdivType;

typedef enum {
    WDT = 0,
    GPT,
    GPIO,
    UDMA,
    HIB,
    UART,
    SSI,
    I2C,
    USB,
    CAN,
    ADC,
    ACMP,
    PWM,
    QEI,
    EEPROM,
    WGPT
} Mcu_PeripheralType;

typedef uint32 Mcu_PeripheralInstType;

typedef struct {
    Mcu_ClkSrcType clkSrc;
    Mcu_PllStateType pllState;
    Mcu_SysdivType sysdiv;
} Mcu_ClockSettingsType;

typedef struct {
    uint32 *base;
    uint32 size;
    uint32 value;
} Mcu_RamSectionConfigType;

typedef struct {
    Mcu_PeripheralType peripheral;
    Mcu_PeripheralInstType instance;
} Mcu_PeripheralClockConfigType;


 
#endif  /* __MCU_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Types.h
 *********************************************************************************************************************/
