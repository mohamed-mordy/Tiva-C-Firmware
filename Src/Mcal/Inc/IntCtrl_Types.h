/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __INTCTRL_TYPES_H__
#define __INTCTRL_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* Copied from tm4c123_cmsis.h */
typedef enum {
/******  Cortex-M4 Processor Exceptions Numbers *****************************/
    Reset_IRQn = -15,               /*!< -15 Reset Vector                   */ /* Does NOT have configurable priority */
    NonMaskableInt_IRQn,            /*!< -14 Non Maskable Interrupt         */ /* Does NOT have configurable priority */
    HardFault_IRQn,                 /*!< -13 Cortex-M3 Hard Fault Int       */ /* Does NOT have configurable priority */
    MemoryManagement_IRQn,          /*!< -12 Cortex-M3 Memory Management    */
    BusFault_IRQn,                  /*!< -11 Cortex-M3 Bus Fault Int        */
    UsageFault_IRQn,                /*!< -10 Cortex-M3 Usage Fault Int      */
    Reserved1_IRQn,
    Reserved2_IRQn,
    Reserved3_IRQn,
    Reserved4_IRQn,
    SVCall_IRQn,                    /*!< -5 Cortex-M3 SV Call Interrupt     */
    DebugMonitor_IRQn,              /*!< -4 Cortex-M3 Debug Monitor Int     */
    Reserved5_IRQn,
    PendSV_IRQn,                    /*!< -2 Cortex-M3 Pend SV Interrupt     */
    SysTick_IRQn,                   /*!< -1 Cortex-M3 System Tick Interrupt */

/******  TM4C Specific Interrupt Numbers ************************************/
    GPIOPortA_IRQn,                 /*!< GPIO Port A                        */
    GPIOPortB_IRQn,                 /*!< GPIO Port B                        */
    GPIOPortC_IRQn,                 /*!< GPIO Port C                        */
    GPIOPortD_IRQn,                 /*!< GPIO Port D                        */
    GPIOPortE_IRQn,                 /*!< GPIO Port E                        */
    UART0_IRQn,                     /*!< UART0                              */
    UART1_IRQn,                     /*!< UART1                              */
    SSI0_IRQn,                      /*!< SSI0                               */
    I2C0_IRQn,                      /*!< I2C0                               */
    PWMFault_IRQn,                  /*!< PWM Fault                          */
    PWMGen0_IRQn,                   /*!< PWM Generator 0                    */
    PWMGen1_IRQn,                   /*!< PWM Generator 1                    */
    PWMGen2_IRQn,                   /*!< PWM Generator 2                    */
    QEI0_IRQn,                      /*!< Quadrature Encoder 0               */
    ADCSeq0_IRQn,                   /*!< ADC Sequence 0                     */
    ADCSeq1_IRQn,                   /*!< ADC Sequence 1                     */
    ADCSeq2_IRQn,                   /*!< ADC Sequence 2                     */
    ADCSeq3_IRQn,                   /*!< ADC Sequence 3                     */
    Watchdog_IRQn,                  /*!< Watchdog                           */
    Timer0A_IRQn,                   /*!< Timer 0A                           */
    Timer0B_IRQn,                   /*!< Timer 0B                           */
    Timer1A_IRQn,                   /*!< Timer 1A                           */
    Timer1B_IRQn,                   /*!< Timer 1B                           */
    Timer2A_IRQn,                   /*!< Timer 2A                           */
    Timer2B_IRQn,                   /*!< Timer 2B                           */
    Comp0_IRQn,                     /*!< Comp 0                             */
    Comp1_IRQn,                     /*!< Comp 1                             */
    Comp2_IRQn,                     /*!< Comp 2                             */
    SysCtrl_IRQn,                   /*!< System Control                     */
    FlashCtrl_IRQn,                 /*!< Flash Control                      */
    GPIOPortF_IRQn,                 /*!< GPIO Port F                        */
    GPIOPortG_IRQn,                 /*!< GPIO Port G                        */
    GPIOPortH_IRQn,                 /*!< GPIO Port H                        */
    USART2_IRQn,                    /*!< UART2 Rx and Tx                    */
    SSI1_IRQn,                      /*!< SSI1 Rx and Tx                     */
    Timer3A_IRQn,                   /*!< Timer 3 subtimer A                 */
    Timer3B_IRQn,                   /*!< Timer 3 subtimer B                 */
    I2C1_IRQn,                      /*!< I2C1 Master and Slave              */
    QEI1_IRQn,                      /*!< Quadrature Encoder 1               */
    CAN0_IRQn,                      /*!< CAN0                               */
    CAN1_IRQn,                      /*!< CAN1                               */
    CAN2_IRQn,                      /*!< CAN2                               */
    Ethernet_IRQn,                  /*!< Ethernet                           */
    Hibernate_IRQn,                 /*!< Hibernate                          */
    USB0_IRQn,                      /*!< USB0                               */
    PWMGen3_IRQn,                   /*!< PWM Generator 3                    */
    uDMAST_IRQn,                    /*!< uDMA Software Transfer             */
    uDMAError_IRQn,                 /*!< uDMA Error                         */
    ADC1Seq0_IRQn,                  /*!< ADC1 Sequence 0                    */
    ADC1Seq1_IRQn,                  /*!< ADC1 Sequence 1                    */
    ADC1Seq2_IRQn,                  /*!< ADC1 Sequence 2                    */
    ADC1Seq3_IRQn,                  /*!< ADC1 Sequence 3                    */
    I2S0_IRQn,                      /*!< I2S0                               */
    EBI0_IRQn,                      /*!< External Bus Interface 0           */
    GPIOPortJ_IRQn,                 /*!< GPIO Port J                        */
    GPIOPortK_IRQn,                 /*!< GPIO Port K                        */
    GPIOPortL_IRQn,                 /*!< GPIO Port L                        */
    SSI2_IRQn,                      /*!< SSI2 Rx and Tx                     */
    SSI3_IRQn,                      /*!< SSI3 Rx and Tx                     */
    UART3_IRQn,                     /*!< UART3 Rx and Tx                    */
    UART4_IRQn,                     /*!< UART4 Rx and Tx                    */
    UART5_IRQn,                     /*!< UART5 Rx and Tx                    */
    UART6_IRQn,                     /*!< UART6 Rx and Tx                    */
    UART7_IRQn,                     /*!< UART7 Rx and Tx                    */
    Reserved6_IRQn,
    Reserved7_IRQn,
    Reserved8_IRQn,
    Reserved9_IRQn,
    I2C2_IRQn,                      /*!< I2C2 Master and Slave              */
    I2C3_IRQn,                      /*!< I2C3 Master and Slave              */
    Timer4A_IRQn,                   /*!< Timer 4 subtimer A                 */
    Timer4B_IRQn,                   /*!< Timer 4 subtimer B                 */
    Reserved10_IRQn,
    Reserved11_IRQn,
    Reserved12_IRQn,
    Reserved13_IRQn,
    Reserved14_IRQn,
    Reserved15_IRQn,
    Reserved16_IRQn,
    Reserved17_IRQn,
    Reserved18_IRQn,
    Reserved19_IRQn,
    Reserved20_IRQn,
    Reserved21_IRQn,
    Reserved22_IRQn,
    Reserved23_IRQn,
    Reserved24_IRQn,
    Reserved25_IRQn,
    Reserved26_IRQn,
    Reserved27_IRQn,
    Reserved28_IRQn,
    Reserved29_IRQn,
    Timer5A_IRQn,                   /*!< Timer 5 subtimer A                 */
    Timer5B_IRQn,                   /*!< Timer 5 subtimer B                 */
    WideTimer0A_IRQn,               /*!< Wide Timer 0 subtimer A            */
    WideTimer0B_IRQn,               /*!< Wide Timer 0 subtimer B            */
    WideTimer1A_IRQn,               /*!< Wide Timer 1 subtimer A            */
    WideTimer1B_IRQn,               /*!< Wide Timer 1 subtimer B            */
    WideTimer2A_IRQn,               /*!< Wide Timer 2 subtimer A            */
    WideTimer2B_IRQn,               /*!< Wide Timer 2 subtimer B            */
    WideTimer3A_IRQn,               /*!< Wide Timer 3 subtimer A            */
    WideTimer3B_IRQn,               /*!< Wide Timer 3 subtimer B            */
    WideTimer4A_IRQn,               /*!< Wide Timer 4 subtimer A            */
    WideTimer4B_IRQn,               /*!< Wide Timer 4 subtimer B            */
    WideTimer5A_IRQn,               /*!< Wide Timer 5 subtimer A            */
    WideTimer5B_IRQn,               /*!< Wide Timer 5 subtimer B            */
    FPU_IRQn,                       /*!< FPU                                */
    PECI0_IRQn,                     /*!< PECI 0                             */
    LPC0_IRQn,                      /*!< LPC 0                              */
    I2C4_IRQn,                      /*!< I2C4 Master and Slave              */
    I2C5_IRQn,                      /*!< I2C5 Master and Slave              */
    GPIOPortM_IRQn,                 /*!< GPIO Port M                        */
    GPIOPortN_IRQn,                 /*!< GPIO Port N                        */
    QEI2_IRQn,                      /*!< Quadrature Encoder 2               */
    Fan0_IRQn,                      /*!< Fan 0                              */
    Reserved30_IRQn,
    GPIOPortP0_IRQn,                /*!< GPIO Port P (Summary or P0)        */
    GPIOPortP1_IRQn,                /*!< GPIO Port P1                       */
    GPIOPortP2_IRQn,                /*!< GPIO Port P2                       */
    GPIOPortP3_IRQn,                /*!< GPIO Port P3                       */
    GPIOPortP4_IRQn,                /*!< GPIO Port P4                       */
    GPIOPortP5_IRQn,                /*!< GPIO Port P5                       */
    GPIOPortP6_IRQn,                /*!< GPIO Port P6                       */
    GPIOPortP7_IRQn,                /*!< GPIO Port P7                       */
    GPIOPortQ0_IRQn,                /*!< GPIO Port Q (Summary or Q0)        */
    GPIOPortQ1_IRQn,                /*!< GPIO Port Q1                       */
    GPIOPortQ2_IRQn,                /*!< GPIO Port Q2                       */
    GPIOPortQ3_IRQn,                /*!< GPIO Port Q3                       */
    GPIOPortQ4_IRQn,                /*!< GPIO Port Q4                       */
    GPIOPortQ5_IRQn,                /*!< GPIO Port Q5                       */
    GPIOPortQ6_IRQn,                /*!< GPIO Port Q6                       */
    GPIOPortQ7_IRQn,                /*!< GPIO Port Q7                       */
    GPIOPortR_IRQn,                 /*!< GPIO Port R                        */
    GPIOPortS_IRQn,                 /*!< GPIO Port S                        */
    PWM1Gen0_IRQn,                  /*!< PWM 1 Generator 0                  */
    PWM1Gen1_IRQn,                  /*!< PWM 1 Generator 1                  */
    PWM1Gen2_IRQn,                  /*!< PWM 1 Generator 2                  */
    PWM1Gen3_IRQn,                  /*!< PWM 1 Generator 3                  */
    PWM1Fault_IRQn                  /*!< PWM 1 Fault                        */
} IntCtrl_InterruptType;

typedef enum {
    InterruptPriorityLevel0,
    InterruptPriorityLevel1,
    InterruptPriorityLevel2,
    InterruptPriorityLevel3,
    InterruptPriorityLevel4,
    InterruptPriorityLevel5,
    InterruptPriorityLevel6,
    InterruptPriorityLevel7
} IntCtrl_InterruptPriorityType;

typedef enum {
    InterruptStateDisable,
    InterruptStateEnable
} IntCtrl_InterruptStateType;

typedef struct {
    IntCtrl_InterruptType interruptID;
    IntCtrl_InterruptPriorityType interruptPri;
    IntCtrl_InterruptStateType interruptState;
} IntCtrl_ConfigType;

 
#endif  /* __INTCTRL_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
