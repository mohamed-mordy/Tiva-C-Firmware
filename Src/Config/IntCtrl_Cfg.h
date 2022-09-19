/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __INTCTRL_CFG_H__
#define __INTCTRL_CFG_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INTCTRL_GROUB_SUBGROUB_XXX                 1
#define INTCTRL_GROUB_SUBGROUB_XXY                 0
#define INTCTRL_GROUB_SUBGROUB_XYY                 0
#define INTCTRL_GROUB_SUBGROUB_YYY                 0

#define INTCTRL_NUMBER_OF_ACTIVATED_INTERRUPTS      1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const IntCtrl_ConfigType IntCtrl_ConfigContainer[INTCTRL_NUMBER_OF_ACTIVATED_INTERRUPTS];

 
#endif  /* __INTCTRL_CFG_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/