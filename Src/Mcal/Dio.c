
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file  Dio.c
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
#include "Dio.h"

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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID)
{
    uint8 channelIndex = ChannelID %  MAX_NUMBER_OF_PINS_PER_PORT;
    uint8 portIndex = ChannelID % MAX_NUMBER_OF_GPIO_PORTS;
    return ((Ports_APB_Base[portIndex]->DATA_Bits[channelIndex]) >> channelIndex) ? STD_HIGH : STD_LOW;
}

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
void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level)
{
    uint8 channelIndex = ChannelID %  MAX_NUMBER_OF_PINS_PER_PORT;
    uint8 portIndex = ChannelID % MAX_NUMBER_OF_GPIO_PORTS;
    Ports_APB_Base[portIndex]->DATA_Bits[channelIndex] = ((uint32)Level)<<channelIndex;
}

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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)
{
    return (Ports_APB_Base[PortID]->DATA & 0xff);
}

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
void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)
{
    Ports_APB_Base[PortID]->DATA = Level;
}

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
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
    (void)ChannelGroupIdPtr;
    return (Dio_PortLevelType)0;
}

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
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    (void)ChannelGroupIdPtr;
    (void)Level;
}

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
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo)
{
    (void)VersionInfo;
}
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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelID)
{
    uint8 channelIndex = ChannelID %  MAX_NUMBER_OF_PINS_PER_PORT;
    uint8 portIndex = ChannelID % MAX_NUMBER_OF_GPIO_PORTS;
    return ((Ports_APB_Base[portIndex]->DATA ^= 1 << channelIndex) >> channelIndex) ?
        STD_HIGH : STD_LOW;
}
#endif

#if defined(DioMaskedWritePortApi) && DioMaskedWritePortApi == TRUE
/******************************************************************************
* \Syntax          : void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
* \Description     : Service to set the value of a given port with required mask.
*                                                                                                                    
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId ID of DIO Port
* \Parameters (in) : Level Value to be written
* \Parameters (in) : Mask Channels to be masked in the port
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Dio_MaskedWritePort( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
    Ports_APB_Base[PortId]->DATA_Bits[Mask] = Level;
}
#endif

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/

