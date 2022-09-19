/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __PORT_TYPES_H__
#define __PORT_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


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
    PORT_A_PIN_0, PORT_A_PIN_1, PORT_A_PIN_2, PORT_A_PIN_3,
    PORT_A_PIN_4, PORT_A_PIN_5, PORT_A_PIN_6, PORT_A_PIN_7,

    PORT_B_PIN_0, PORT_B_PIN_1, PORT_B_PIN_2, PORT_B_PIN_3,
    PORT_B_PIN_4, PORT_B_PIN_5, PORT_B_PIN_6, PORT_B_PIN_7,

    PORT_C_PIN_0, PORT_C_PIN_1, PORT_C_PIN_2, PORT_C_PIN_3,
    PORT_C_PIN_4, PORT_C_PIN_5, PORT_C_PIN_6, PORT_C_PIN_7,

    PORT_D_PIN_0, PORT_D_PIN_1, PORT_D_PIN_2, PORT_D_PIN_3,
    PORT_D_PIN_4, PORT_D_PIN_5, PORT_D_PIN_6, PORT_D_PIN_7,

    PORT_E_PIN_0, PORT_E_PIN_1, PORT_E_PIN_2, PORT_E_PIN_3,
    PORT_E_PIN_4, PORT_E_PIN_5, PORT_E_PIN_6, PORT_E_PIN_7,

    PORT_F_PIN_0, PORT_F_PIN_1, PORT_F_PIN_2, PORT_F_PIN_3,
    PORT_F_PIN_4, PORT_F_PIN_5, PORT_F_PIN_6, PORT_F_PIN_7
} Port_PinListing;

typedef enum {
    Port_Pin_Mode_XXX_DIO,

} Port_ModeListing;

typedef enum {
    Port_PinInternalAttach_Default,
    Port_PinInternalAttach_PullUp,
    Port_PinInternalAttach_PullDown,
    Port_PinInternalAttach_OpenDrain
} Port_PinInternalAttachType;

typedef enum {
    Port_PinOutputCurrent_2MA,
    Port_PinOutputCurrent_4MA,
    Port_PinOutputCurrent_8MA,
    Port_PinOutputCurrent_NA
} Port_PinOutputCurrentType;

typedef enum {
    Port_A, Port_B,
    Port_C, Port_D,
    Port_E, Port_F
} PortType;



#endif  /* __PORT_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/

