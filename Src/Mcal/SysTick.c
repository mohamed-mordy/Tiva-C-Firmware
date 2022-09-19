/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
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
#include "SysTick_Cfg.h"
#include "SysTick.h"
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
* \Syntax          : void SysTick_Init(SysTick_ReloadType Reload)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Reload   The value to be loaded into the reload register
* \Parameters (out): None                                                      
* \Return value    : void
*******************************************************************************/
void SysTick_Init(SysTick_ReloadType Reload)
{
    SysTick.LOAD = Reload;
    SysTick.VAL = 0;  /* any write to CurrentVal register clears it */

#if defined(SYSTICK_ENABLE_INTERRUPT) && SYSTICK_ENABLE_INTERRUPT == 1 
    SysTick.CTRL |= (uint32)1<<1;
#elif defined(SYSTICK_ENABLE_INTERRUPT) && SYSTICK_ENABLE_INTERRUPT == 0 
    SysTick.CTRL &= ~((uint32)1<<1);
#else
#error "SysTick interrupt status is not defined"
#endif

#if defined(SYSTICK_CLK_SRC) && defined(SYSTICK_CLK_SRC_PIOSC) &&  SYSTICK_CLK_SRC == SYSTICK_CLK_SRC_PIOSC 
    SysTick.CTRL &= ~((uint32)1<<2);
#elif defined(SYSTICK_CLK_SRC) && defined(SYSTICK_CLK_SRC_SYSTEM_CLK) &&  SYSTICK_CLK_SRC == SYSTICK_CLK_SRC_SYSTEM_CLK
    SysTick.CTRL |= (uint32)1<<2;
#else
#error "SysTick clock source is not defined"
#endif

}

/******************************************************************************
* \Syntax          : void SysTick_Handler(void)        
* \Description     : SysTick Interrupt Service Routine (ISR)
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Handler(void)
{

}

/******************************************************************************
* \Syntax          : void SysTick_Enable(void)
* \Description     : Enables SysTick Counter
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Enable(void)
{
    SysTick.CTRL |= (uint32)1;
}

/******************************************************************************
* \Syntax          : void SysTick_Disable(void)
* \Description     : Disables SysTick Counter
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Disable(void)
{
    SysTick.CTRL &= ~((uint32)1);
}

/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
