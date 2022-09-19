/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  Header file register definitions
 *  
 *********************************************************************************************************************/
#ifndef __MCU_HW_H__
#define __MCU_HW_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 


/* Internal Peripherals Types */

/* structure type to access the System Control and ID Register not in the SCB. */
typedef struct {
   uint32 RESERVED0[1U];
   uint32 ICTR;                   /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register */
   uint32 ACTLR;                  /*!< Offset: 0x008 (R/W)  Auxiliary Control Register */
} SCnSCB_Type;

/* structure type to access the System Timer (SysTick). */
typedef struct {
    uint32 CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
    uint32 LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
    uint32 VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
    uint32 CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;


typedef struct {
    uint32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    uint32 RESERVED0[24U];
    uint32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
    uint32 RESERVED1[24U];
    uint32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
    uint32 RESERVED2[24U];
    uint32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
    uint32 RESERVED3[24U];
    uint32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
    uint32 RESERVED4[56U];
    uint8  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
    uint32 RESERVED5[644U];
    uint32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;


typedef struct {
    uint32 CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    uint32 ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    uint32 VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
    uint32 AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
    uint32 SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
    uint32 CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    uint8  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
    //uint32 SHCSR;
    union {                        /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
        uint32 R;
        struct {
            uint32 MEMA   :1;
            uint32 BUSA   :1;
            uint32        :1;
            uint32 USGA   :1;
            uint32        :3;
            uint32 SVCA   :1;
            uint32 MON    :1;
            uint32        :1;
            uint32 PNDSV  :1;
            uint32 TICK   :1;
            uint32 USAGEP :1;
            uint32 MEMP   :1;
            uint32 BUSP   :1;
            uint32 SVC    :1;
            uint32 MEM    :1;
            uint32 BUS    :1;
            uint32 USAGE  :1;
            uint32        :13;
            /* the rest is padding */
        } B;
    } SHCSR;
    uint32 CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
    uint32 HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
    uint32 DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
    uint32 MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
    uint32 BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
    uint32 AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
    uint32 PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
    uint32 DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
    uint32 ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
    uint32 MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
    uint32 ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
    uint32 RESERVED0[5U];
    uint32 CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} SCB_Type;


/* Structure type to access the Memory Protection Unit (MPU).  */
typedef struct
{
    uint32 TYPE;                   /*!< Offset: 0x000 (R/ )  MPU Type Register */
    uint32 CTRL;                   /*!< Offset: 0x004 (R/W)  MPU Control Register */
    uint32 RNR;                    /*!< Offset: 0x008 (R/W)  MPU Region RNRber Register */
    uint32 RBAR;                   /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register */
    uint32 RASR;                   /*!< Offset: 0x010 (R/W)  MPU Region Attribute and Size Register */
    uint32 RBAR_A1;                /*!< Offset: 0x014 (R/W)  MPU Alias 1 Region Base Address Register */
    uint32 RASR_A1;                /*!< Offset: 0x018 (R/W)  MPU Alias 1 Region Attribute and Size Register */
    uint32 RBAR_A2;                /*!< Offset: 0x01C (R/W)  MPU Alias 2 Region Base Address Register */
    uint32 RASR_A2;                /*!< Offset: 0x020 (R/W)  MPU Alias 2 Region Attribute and Size Register */
    uint32 RBAR_A3;                /*!< Offset: 0x024 (R/W)  MPU Alias 3 Region Base Address Register */
    uint32 RASR_A3;                /*!< Offset: 0x028 (R/W)  MPU Alias 3 Region Attribute and Size Register */
} MPU_Type;

/****************************************************************************/
/*                Device Specific Peripheral registers structures           */
/****************************************************************************/

/*----------       System Controller (SYSCTL)                     ----------*/
typedef struct {
    uint32 DID0;             // Device identification register 0
    uint32 DID1;             // Device identification register 1
    uint32 DC0;              // Device capabilities register 0
    uint8  RESERVED1[4];
    uint32 DC1;              // Device capabilities register 1
    uint32 DC2;              // Device capabilities register 2
    uint32 DC3;              // Device capabilities register 3
    uint32 DC4;              // Device capabilities register 4
    uint32 DC5;              // Device capabilities register 5
    uint32 DC6;              // Device capabilities register 6
    uint32 DC7;              // Device capabilities register 7
    uint32 DC8;              // Device capabilities register 8
    uint32 PBORCTL;          // POR/BOR reset control register
    uint32 LDOPCTL;          // LDO power control register
    uint8  RESERVED3[8];
    uint32 SRCR0;            // Software reset control reg 0
    uint32 SRCR1;            // Software reset control reg 1
    uint32 SRCR2;            // Software reset control reg 2
    uint8  RESERVED4[4];
    uint32 RIS;              // Raw interrupt status register
    uint32 IMC;              // Interrupt mask/control register
    uint32 MISC;             // Interrupt status register
    uint32 RESC;             // Reset cause register
    union {
        uint32 R;
        struct {
            uint32 MOSCDIS  :1;
            uint32          :3;
            uint32 OSCSRC   :2;
            uint32 XTAL     :5;
            uint32 BYPASS   :1;
            uint32          :1;
            uint32 PWRDN    :1;
            uint32          :3;
            uint32 PWMDIV   :3;
            uint32 USEPWMDIV:1;
            uint32          :1;
            uint32 USESYSDIV:1;
            uint32 SYSDIV   :4;
            uint32 ACG      :1;
            uint32          :4;
        } B;
    } RCC;                   // Run-mode clock config register
    uint32 PLLCFG;           // PLL configuration register
    uint8  RESERVED5[4];
    uint32 GPIOHSCTL;        // GPIO High Speed Control
    union {
        uint32 R;
        struct {
            uint32           :4;
            uint32 OSCSRC2   :3;
            uint32           :4;
            uint32 BYPASS2   :1;
            uint32           :1;
            uint32 PWRDN2    :1;
            uint32 USBPWRDN  :1;
            uint32           :7;
            uint32 SYSDIV2LSB:1;
            uint32 SYSDIV2   :6;
            uint32           :1;
            uint32 DIV400    :1;
            uint32 USERCC2   :1;
        } B;
    } RCC2;                  // Run-mode clock config register 2
    uint8  RESERVED6[8];
    uint32 MOSCCTL;          // Main Oscillator Control
    uint8  RESERVED7[128];
    uint32 RCGC0;            // Run-mode clock gating register 0
    uint32 RCGC1;            // Run-mode clock gating register 1
    uint32 RCGC2;            // Run-mode clock gating register 2
    uint8  RESERVED8[4];
    uint32 SCGC0;            // Sleep-mode clock gating reg 0
    uint32 SCGC1;            // Sleep-mode clock gating reg 1
    uint32 SCGC2;            // Sleep-mode clock gating reg 2
    uint8  RESERVED9[4];
    uint32 DCGC0;            // Deep Sleep-mode clock gate reg 0
    uint32 DCGC1;            // Deep Sleep-mode clock gate reg 1
    uint32 DCGC2;            // Deep Sleep-mode clock gate reg 2
    uint8  RESERVED10[24];
    uint32 DSLPCLKCFG;       // Deep Sleep-mode clock config reg
    uint8  RESERVED11[36];
    union {
        uint32 R;
        struct {
            uint32 LOCK :1;
            uint32      :31;
        } B;
    } PLLSTAT;                // PLL Status register
} SYSCTL_Type;

typedef struct {
    uint32 DATA_Bits[255];   // Bit specific data registers
    uint32 DATA;  /* only 8 bits used */            // Data register.
    uint32 DIR;              // Data direction register.
    uint32 IS;               // Interrupt sense register.
    uint32 IBE;              // Interrupt both edges register.
    uint32 IEV;              // Interrupt event register.
    uint32 IM;               // Interrupt mask register.
    uint32 RIS;              // Raw interrupt status register.
    uint32 MIS;              // Masked interrupt status reg.
    uint32 ICR;              // Interrupt clear register.
    uint32 AFSEL;            // Mode control select register.
    uint8  RESERVED1[220];
    uint32 DR2R;             // 2ma drive select register.
    uint32 DR4R;             // 4ma drive select register.
    uint32 DR8R;             // 8ma drive select register.
    uint32 ODR;              // Open drain select register.
    uint32 PUR;              // Pull up select register.
    uint32 PDR;              // Pull down select register.
    uint32 SLR;              // Slew rate control enable reg.
    uint32 DEN;              // Digital input enable register.
    uint32 LOCK;             // Lock register.
    uint32 CR;               // Commit register.
    uint32 AMSEL;            // Analog Mode Select
    uint32 PCTL;             // Port Control
    uint32 ADCCTL;           // ADC Control
    uint32 DMACTL;           // DMA Control
} GPIO_Type;

/*----------       Watchdog Timer (WDT)                           ----------*/
typedef struct {
    uint32 LOAD;             // Load register
    uint32 VALUE;            // Current value register
    union {
        uint32 R;
        struct {
            uint32 INTEN  :1;
            uint32 RESEN  :1;
            uint32 INTTYPE:1;
            uint32        :28;
            uint32 WRC    :1;
        } B;
    } CTL;                   // Control register
    uint32 ICR;              // Interrupt clear register
    union {
        uint32 R;
        struct {
            uint32 WDTRIS:1;
            uint32       :31;
        } B;
    } RIS;                   // Raw interrupt status register
    union {
        uint32 R;
        struct {
            uint32 WDTMIS:1;
            uint32       :31;
        } B;
    } MIS;                   // Masked interrupt status register
    uint8  RESERVED0[1024];
    union {
        uint32 R;
        struct {
            uint32      :8;
            uint32 STALL:1;
            uint32      :23;
        } B;
    } TEST;                  // Test register
    uint8  RESERVED1[2020];
    uint32 LOCK;             // Lock register
    /* Write value of 0x1ACCE551 unlocks the WDT */
    /* Write value of any value locks the WDT */
} WDT_Type;

/*----------       General Purpose Timer (TIMER)                 -----------*/
typedef struct {
    uint32 CFG;              // Configuration register
    union {
        uint32 R;
        struct {
            uint32 TAMR   :2;
            uint32 TACMR  :1;
            uint32 TAAMS  :1;
            uint32 TACDIR :1;
            uint32 TAMIE  :1;
            uint32 TAWOT  :1;
            uint32 TASNAPS:1;
            uint32 TAILD  :1;
            uint32 TAPWMIE:1;
            uint32 TAMRSU :1;
            uint32 TAPLO  :1;
            uint32        :20;
        } B;
    } TAMR;                  // TimerA mode register
    union {
        uint32 R;
        struct {
            uint32 TBMR   :2;
            uint32 TBCMR  :1;
            uint32 TBAMS  :1;
            uint32 TBCDIR :1;
            uint32 TBMIE  :1;
            uint32 TBWOT  :1;
            uint32 TBSNAPS:1;
            uint32 TBILD  :1;
            uint32 TBPWMIE:1;
            uint32 TBMRSU :1;
            uint32 TBPLO  :1;
            uint32        :20;
        } B;
    } TBMR;                  // TimerB mode register
    union {
        uint32 R;
        struct {
            uint32 TAEN   :1;
            uint32 TASTALL:1;
            uint32 TAEVENT:2;
            uint32 RTCEN  :1;
            uint32 TAOTE  :1;
            uint32 TAPWML :1;
            uint32        :1;
            uint32 TBEN   :1;
            uint32 TBSTALL:1;
            uint32 TBEVENT:2;
            uint32        :1;
            uint32 TBBOTE :1;
            uint32 TBPWML :1;
            uint32        :17;
        } B;                 // Control register
    } CTL;                   // Control register
    union {
        uint32 R;
        struct {
            uint32 SYNCT0 :2;
            uint32 SYNCT1 :2;
            uint32 SYNCT2 :2;
            uint32 SYNCT3 :2;
            uint32 SYNCT4 :2;
            uint32 SYNCT5 :2;
            uint32 SYNCWT0:2;
            uint32 SYNCWT1:2;
            uint32 SYNCWT2:2;
            uint32 SYNCWT3:2;
            uint32 SYNCWT4:2;
            uint32 SYNCWT5:2;
            uint32        :8;
        } B;
    } SYNC;  // Sync register. Implemented on GPTM module 0 only.
    uint8  RESERVED0[4];
    union {
        uint32 R;
        struct {
            uint32 TATOIM:1;
            uint32 CAMIM :1;
            uint32 CAEIM :1;
            uint32 RTCIM :1;
            uint32 TAMIM :1;
            uint32       :3;
            uint32 TBTOIM:1;
            uint32 CBMIM :1;
            uint32 CBEIM :1;
            uint32 TBMIM :1;
            uint32       :4;
            uint32 WUEIM :1;
            uint32       :15;
        } B;
    } IMR;                   // Interrupt mask register
    union {
        uint32 R;
        struct {
            uint32 TATORIS :1;
            uint32 CAMRIS  :1;
            uint32 CAERIS  :1;
            uint32 RTCRIS  :1;
            uint32 TAMRIS  :1;
            uint32         :3;
            uint32 TBTORIS :1;
            uint32 CBMRIS  :1;
            uint32 CBERIS  :1;
            uint32 TBMRIS  :1;
            uint32         :4;
            uint32 WUERIS  :1;
            uint32         :15;
        } B;
    }  RIS;                  // Interrupt status register
    union {
        uint32 R;
        struct {
            uint32 TATOMIS :1;
            uint32 CAMMIS  :1;
            uint32 CAEMIS  :1;
            uint32 RTCMIS  :1;
            uint32 TAMMIS  :1;
            uint32         :3;
            uint32 TBTOMIS :1;
            uint32 CBMMIS  :1;
            uint32 CBEMIS  :1;
            uint32 TBMMIS  :1;
            uint32         :4;
            uint32 WUEMIS  :1;
            uint32         :15;
        } B;
    } MIS;                   // Masked interrupt status reg.
    union {
        uint32 R;
        struct {
            uint32 TATOCINT:1;
            uint32 CAMCINT :1;
            uint32 CAECINT :1;
            uint32 RTCCINT :1;
            uint32 TAMCINT :1;
            uint32         :3;
            uint32 TBTOCINT:1;
            uint32 CBMCINT :1;
            uint32 CBECINT :1;
            uint32 TBMCINT :1;
            uint32         :4;
            uint32 WUECINT :1;
            uint32         :15;
        } B;
    } ICR;                   // Interrupt clear register
    uint32 TAILR;            // TimerA interval load register
    uint32 TBILR;            // TimerB interval load register
    uint32 TAMATCHR;         // TimerA match register
    uint32 TBMATCHR;         // TimerB match register
    uint32 TAPR;             // TimerA prescale register
    uint32 TBPR;             // TimerB prescale register
    uint32 TAPMR;            // TimerA prescale match register
    uint32 TBPMR;            // TimerB prescale match register
    uint32 TAR;              // TimerA register
    uint32 TBR;              // TimerB register
    uint32 TAV;              // TimerA value
    uint32 TBV;              // TimerB value
    uint32 RTCPD;            // RTC Predivide
    uint32 TAPS;             // TimerA prescale snapshot
    uint32 TBPS;             // TimerB prescale snapshot
    uint32 TAPV;             // TimerA prescale value
    uint32 TBPV;             // TimerB prescale value
} TIMER_Type;

    /* Memory mapping of Core Peripherals */
#define SCS_BASE            ((uint32)0xE000E000)

#define SCnSCB_BASE         ((SCnSCB_Type  *)SCS_BASE)
#define SysTick_BASE        ((SysTick_Type *)(SCS_BASE + (uint32)0x0010))
#define NVIC_BASE           ((NVIC_Type    *)(SCS_BASE + (uint32)0x0100))
#define SCB_BASE            ((SCB_Type     *)(SCS_BASE + (uint32)0x0D00))
#define MPU_BASE            ((MPU_Type     *)(SCS_BASE + (uint32)0x0D90))                   
#define FPU_BASE            ((FPU_Type     *)(SCS_BASE + (uint32)0x0F30))

   /* Core Peripherals Declarations */
#define SCnSCB              (*SCnSCB_BASE )
#define SysTick             (*SysTick_BASE)
#define NVIC                (*NVIC_BASE   )
#define SCB                 (*SCB_BASE    )
#define MPU                 (*MPU_BASE    )
#define FPU                 (*FPU_BASE    )     


    /* Memory mapping of Platform Peripherals */
#define          SYSCTL_BASE       ((SYSCTL_Type *)0x400FE000)

#define           PORT_A_APB_BASE  ((GPIO_Type *)0x40004000) 
#define           PORT_B_APB_BASE  ((GPIO_Type *)0x40005000)
#define           PORT_C_APB_BASE  ((GPIO_Type *)0x40006000)
#define           PORT_D_APB_BASE  ((GPIO_Type *)0x40007000)
#define           PORT_E_APB_BASE  ((GPIO_Type *)0x40024000)
#define           PORT_F_APB_BASE  ((GPIO_Type *)0x40025000)
                                   
#define           PORT_A_AHB_BASE  ((GPIO_Type *)0x40058000)
#define           PORT_B_AHB_BASE  ((GPIO_Type *)0x40059000)
#define           PORT_C_AHB_BASE  ((GPIO_Type *)0x4005A000)
#define           PORT_D_AHB_BASE  ((GPIO_Type *)0x4005B000)
#define           PORT_E_AHB_BASE  ((GPIO_Type *)0x4005C000)
#define           PORT_F_AHB_BASE  ((GPIO_Type *)0x4005D000)

#define           WDT0_BASE        ((WDT_Type *)0x40000000)
#define           WDT1_BASE        ((WDT_Type *)0x40001000)

#define           TIMER0_BASE      ((TIMER_Type *) 0x40030000)
#define           TIMER1_BASE      ((TIMER_Type *) 0x40031000)
#define           TIMER2_BASE      ((TIMER_Type *) 0x40032000)
#define           TIMER3_BASE      ((TIMER_Type *) 0x40033000)
#define           TIMER4_BASE      ((TIMER_Type *) 0x40034000)
#define           TIMER5_BASE      ((TIMER_Type *) 0x40035000)

#define           TIMER0_WIDE_BASE      ((TIMER_Type *) 0x40036000)
#define           TIMER1_WIDE_BASE      ((TIMER_Type *) 0x40037000)
#define           TIMER2_WIDE_BASE      ((TIMER_Type *) 0x4004C000)
#define           TIMER3_WIDE_BASE      ((TIMER_Type *) 0x4004D000)
#define           TIMER4_WIDE_BASE      ((TIMER_Type *) 0x4004E000)
#define           TIMER5_WIDE_BASE      ((TIMER_Type *) 0x4004F000)

   /* Platform Peripherals Declarations */
#define           SYSCTL           (*SYSCTL_BASE)

#define           PORT_A_APB       (*PORT_A_APB_BASE) 
#define           PORT_B_APB       (*PORT_B_APB_BASE)
#define           PORT_C_APB       (*PORT_C_APB_BASE)
#define           PORT_D_APB       (*PORT_D_APB_BASE)
#define           PORT_E_APB       (*PORT_E_APB_BASE)
#define           PORT_F_APB       (*PORT_F_APB_BASE)

#define           PORT_A_AHB       (*PORT_A_AHB_BASE)
#define           PORT_B_AHB       (*PORT_B_AHB_BASE)
#define           PORT_C_AHB       (*PORT_C_AHB_BASE)
#define           PORT_D_AHB       (*PORT_D_AHB_BASE)
#define           PORT_E_AHB       (*PORT_E_AHB_BASE)
#define           PORT_F_AHB       (*PORT_F_AHB_BASE)

#define           WDT0             (*WDT0_BASE)
#define           WDT1             (*WDT1_BASE)

#define           TIMER0           (*TIMER0_BASE) 
#define           TIMER1           (*TIMER1_BASE) 
#define           TIMER2           (*TIMER2_BASE) 
#define           TIMER3           (*TIMER3_BASE) 
#define           TIMER4           (*TIMER4_BASE) 
#define           TIMER5           (*TIMER5_BASE) 

#define           TIMER0_WIDE           (*TIMER0_WIDE_BASE) 
#define           TIMER1_WIDE           (*TIMER1_WIDE_BASE) 
#define           TIMER2_WIDE           (*TIMER2_WIDE_BASE) 
#define           TIMER3_WIDE           (*TIMER3_WIDE_BASE) 
#define           TIMER4_WIDE           (*TIMER4_WIDE_BASE) 
#define           TIMER5_WIDE           (*TIMER5_WIDE_BASE) 

#endif  /* __MCU_HW_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
