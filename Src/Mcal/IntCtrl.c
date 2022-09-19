/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
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
#include "IntCtrl_Cfg.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
    sint16 interruptID;
    uint8 interruptPri;
    uint8 interruptState;
    uint8 i, regIndex, bitIndex;

	/* Configure Grouping\SubGrouping System in APINT register in SCB*/
#if   defined(INTCTRL_GROUB_SUBGROUB_XXX) && INTCTRL_GROUB_SUBGROUB_XXX == 1
                /*VECTKEY*/
    SCB.AIRCR = 0x05FA0000|0x00000000; /* APINT */
#elif defined(INTCTRL_GROUB_SUBGROUB_XXY) &&  INTCTRL_GROUB_SUBGROUB_XXY == 1
    SCB.AIRCR = 0x05FA0000|0x00000500; /* APINT */
#elif defined(INTCTRL_GROUB_SUBGROUB_XYY) &&  INTCTRL_GROUB_SUBGROUB_XYY == 1
    SCB.AIRCR = 0x05FA0000|0x00000600; /* APINT */
#elif defined(INTCTRL_GROUB_SUBGROUB_YYY) &&  INTCTRL_GROUB_SUBGROUB_YYY == 1
    SCB.AIRCR = 0x05FA0000|0x00000700; /* APINT */
#else
#error "IntrCtrl Priority Groub and Subgroub is not defined"
#endif

    for (i = 0; i < INTCTRL_NUMBER_OF_ACTIVATED_INTERRUPTS; ++i) {
        interruptID = IntCtrl_ConfigContainer[i].interruptID;
        interruptPri = IntCtrl_ConfigContainer[i].interruptPri;
        interruptState = IntCtrl_ConfigContainer[i].interruptState;

        /* Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
        if (interruptID < 0) { /* Cortex-M4 Exceptions */
            SCB.SHP[interruptID + 15] = (uint8) (interruptPri << 5);
        } else { /* tm4c specific interrupts */
            NVIC.IP[interruptID] = (uint8) (interruptPri << 5);
        }

        /* Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
        if (interruptID < 0) { /* Cortex-M4 Exceptions */
            switch(interruptID) {
                case MemoryManagement_IRQn:
                    SCB.SHCSR.B.MEM = interruptState;
                    break;
                case BusFault_IRQn:
                    SCB.SHCSR.B.BUS = interruptState;
                    break;
                case UsageFault_IRQn:
                    SCB.SHCSR.B.USAGE = interruptState;
                    break;
                case SVCall_IRQn:
                    SCB.SHCSR.B.SVC = interruptState;
                    break;
                case DebugMonitor_IRQn:
                    SCB.SHCSR.B.MON = interruptState;
                    break;
                case PendSV_IRQn:
                    SCB.SHCSR.B.PNDSV = interruptState;
                    break;
                case SysTick_IRQn:
                    SCB.SHCSR.B.TICK = interruptState;
                    break;
                default :
                    break;
            }

        } else { /* tm4c specific interrupts */
            //regIndex = (uint8)((interruptID + 15) / 32);
            //bitIndex = (uint8)((interruptID + 15) % 32);
            regIndex = (uint8)(interruptID / 32);
            bitIndex = (uint8)(interruptID % 32);
            if (interruptState == InterruptStateDisable) {
                NVIC.ICER[regIndex] |= (uint32)1 << bitIndex;
            } else if (interruptState == InterruptStateEnable) {
                NVIC.ISER[regIndex] |= (uint32)1 << bitIndex;
            } else {
                /* Catch Error Here */
            }
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
