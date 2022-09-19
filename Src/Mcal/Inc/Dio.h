/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: Dio.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __DIO_H__
#define __DIO_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Port.h"

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
* \Name            : Dio_ChannelType
* \Type            : uint
* \Range           : This is implementation specific but not all values may be valid within the type.  -- Shall cover all available DIO channels
* \Description     : Numeric ID of a DIO channel.
*******************************************************************************/
typedef uint32 Dio_ChannelType;

/******************************************************************************
* \Name            : Dio_PortType
* \Type            : uint
* \Range           : 0..<number of ports> -- Shall cover all available DIO Ports.
* \Description     : Numeric ID of a DIO port.
*******************************************************************************/
typedef uint32 Dio_PortType;

/******************************************************************************
* \Name            : Dio_ChannelGroupType
* \Type            : Structure
* \Element         : uint8/16/32 mask This element mask which defines the positions of the channel group.
*                    uint8 offset This element shall be the position of the Channel Group on the port, counted from the LSB.
*                    Dio_PortType port This shall be the port on which the Channel group is defined.
* \Description     : Type for the definition of a channel group, which consists of several adjoining channels within a port.
*******************************************************************************/
typedef struct {
    uint32 mask;
    uint32 offset;
    Dio_PortType port;
} Dio_ChannelGroupType;

/******************************************************************************
* \Name            : Dio_LevelType
* \Type            : uint8
* \Range           : STD_LOW  0x00 Physical state 0V
*                    STD_HIGH 0x01 Physical state 5V or 3.3V
* \Description     : These are the possible levels a DIO channel can have (input or output)
*******************************************************************************/
typedef uint8 Dio_LevelType;

/******************************************************************************
* \Name            : Dio_PortLevelType
* \Type            : uint
* \Range           : 0...xxx -- If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port
* \Description     : If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port.
*******************************************************************************/
typedef uint8 Dio_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId)
* \Description     : Returns the value of the specified DIO channel.
*                                                                                                   
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId ID of DIO channel
* \Parameters (out): None
* \Return value:   : Dio_LevelType STD_HIGH The physical level of the corresponding Pin is STD_HIGH
*                    STD_LOW The physical level of the corresponding Pin is STD_LOW
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID);

/******************************************************************************
* \Syntax          : void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level)
* \Description     : Service to set a level of a channel.
*                                                                                           
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId ID of DIO channel
* \Parameters (in) : Level Value to be written
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level);

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId)
* \Description     : Returns the level of all channels of that port.
*                                                                         
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId ID of DIO Port
* \Parameters (out): None
* \Return value:   : Dio_PortLevelType Level of all channels of that port
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID);

/******************************************************************************
* \Syntax          : void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level)
* \Description     : Service to set a value of the port.
*                                                                                      
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId ID of DIO Port
* \Parameters (in) : Level Value to be written
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level);

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr)
* \Description     : This Service reads a subset of the adjoining bits of a port.
*                                                                                                           
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelGroupIdPtr Pointer to ChannelGroup
* \Parameters (out): None
* \Return value:   : Dio_PortLevelType Level of a subset of the adjoining bits of a port
*******************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/******************************************************************************
* \Syntax          : void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
* \Description     : Service to set a subset of the adjoining bits of a port to a specified level.
*                                                                                                                        
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelGroupIdPtr Pointer to ChannelGroup
* \Parameters (in) : Level Value to be written
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

#if defined(DioVersionInfoApi)  && DioVersionInfoApi == TRUE
/******************************************************************************
* \Syntax          : void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo)
* \Description     : Service to get the version information of this module.
*                                                                                                  
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): VersionInfo Pointer to where to store the version information of this module.
* \Return value:   : None
*******************************************************************************/
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo);
#endif

#if defined(DioFlipChannelApi) && DioFlipChannelApi == TRUE
/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
* \Description     : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
*                                                                                                                                               
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId ID of DIO channel
* \Parameters (out): None
* \Return value:   : Dio_LevelType STD_HIGH The physical level of the corresponding Pin is STD_HIGH.
*                                  STD_LOW The physical level of the corresponding Pin is STD_LOW.
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelID);
#endif

#if defined(DioMaskedWritePortApi) && DioMaskedWritePortApi == TRUE
/******************************************************************************
* \Syntax          : void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
* \Description     : Service to set the value of a given port with required mask.
*                                                                                                                    
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId ID of DIO Port
*                    Level Value to be written
*                    Mask Channels to be masked in the port
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);
#endif


#endif  /* __DIO_H__*/

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
