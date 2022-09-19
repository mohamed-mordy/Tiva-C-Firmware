/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Adc.c
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
#include "Adc.h"

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
* \Syntax          : void Adc_Init(const Adc_ConfigType* ConfigPtr)
* \Description     : Initializes the Adc.hardware units and driver.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr Pointer to configuration set in Variant PB (Variant PC requires a NULL_PTR).
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_Init(const Adc_ConfigType* ConfigPtr)
{
    (void)ConfigPtr;
}

/******************************************************************************
* \Syntax          : Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, const Adc_ValueGroupType* DataBufferPtr)
* \Description     : Initializes ADC driver with the group specific result buffer start address where the
*                    conversion results will be stored. The application has to ensure that the application
*                    buffer, where DataBufferPtr points to, can hold all the conversion results of the
*                    specified group. The initialization with Adc_SetupResultBuffer is required after
*                    reset, before a group conversion can be started.                                                                                              
*
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested Adc.channel group.
* \Parameters (in) : DataBufferPtr pointer to result data buffer
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType E_OK: result buffer pointer initialized correctly
*                                   E_NOT_OK: operation failed or development error occured
*******************************************************************************/
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, const Adc_ValueGroupType* DataBufferPtr)
{
    (void)Group;
    (void)DataBufferPtr;
}

/******************************************************************************
* \Syntax          : void Adc_DeInit(void)
* \Description     : Returns all ADC HW Units to a state comparable to their power on reset state.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_DeInit(void)
{
	
	
}

/******************************************************************************
* \Syntax          : void Adc_StartGroupConversion(Adc_GroupType Group)
* \Description     : Starts the conversion of all channels of the requested ADC Channel group.
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StartGroupConversion(Adc_GroupType Group)
{
	(void)Group;
	
}

/******************************************************************************
* \Syntax          : void Adc_StopGroupConversion(Adc_GroupType Group)
* \Description     : Stops the conversion of the requested ADC Channel group.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StopGroupConversion(Adc_GroupType Group)
{
    (void)Group;
}

/******************************************************************************
* \Syntax          : Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
* \Description     : Reads the group conversion result of the last completed conversion round of the
*                    requested group and stores the channel values starting at the DataBufferPtr
*                    address. The group channel values are stored in ascending channel number order
*                    ( in contrast to the storage layout of the result buffer if streaming access is configured).
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested Adc.channel group.
* \Parameters (out): DataBufferPtr ADC results of all channels of the selected group are stored in the data buffer addressed with the pointer.
* \Return value:   : Std_ReturnType E_OK: results are available and written to the data buffer
*                                   E_NOT_OK: no results are available or development error occured
*******************************************************************************/
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
{
	(void)Group;
    (void)DataBufferPtr;	
}

/******************************************************************************
* \Syntax          : void Adc_EnableHardwareTrigger(Adc_GroupType Group)
* \Description     : Enables the hardware trigger for the requested ADC Channel group.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_EnableHardwareTrigger(Adc_GroupType Group)
{
	(void)Group;
	
}

/******************************************************************************
* \Syntax          : void Adc_DisableHardwareTrigger(Adc_GroupType Group)
* \Description     : Disables the hardware trigger for the requested ADC Channel group.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
	(void)Group;
	
}

/******************************************************************************
* \Syntax          : void Adc_EnableGroupNotification(Adc_GroupType Group)
* \Description     : Enables the notification mechanism for the requested ADC Channel group.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_EnableGroupNotification(Adc_GroupType Group)
{
	(void)Group;
	
}

/******************************************************************************
* \Syntax          : void Adc_DisableGroupNotification(Adc_GroupType Group)
* \Description     : Disables the notification mechanism for the requested ADC Channel group.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_DisableGroupNotification(Adc_GroupType Group)
{
	(void)Group;
	
}

/******************************************************************************
* \Syntax          : Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
* \Description     : Returns the conversion status of the requested ADC Channel group.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): None                                                      
* \Return value:   : Adc_StatusType Conversion status for the requested group.
*******************************************************************************/
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
{
	(void)Group;
	
}

/******************************************************************************
* \Syntax          : Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr)
* \Description     : Returns the number of valid samples per channel, stored in the result buffer.
*                    Reads a pointer, pointing to a position in the group result buffer. With the pointer
*                       position, the results of all group channels of the last completed conversion round
*                       can be accessed.
*                    With the pointer and the return value, all valid group conversion results can be
*                       accessed (the user has to take the layout of the result buffer into account).
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Group Numeric ID of requested ADC Channel group.
* \Parameters (out): PtrToSamplePtr Pointer to result buffer pointer.
* \Return value:   : Adc_StreamNumSampleType Number of valid samples per channel.
*******************************************************************************/
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr)
{
	(void)Group;
	(void)PtrToSamplePtr;
}

/******************************************************************************
* \Syntax          : void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo)
* \Description     : Returns the version information of this module.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): versioninfo Pointer to where to store the version information of this module.
* \Return value:   : None
*******************************************************************************/
void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	(void)versioninfo;
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType Adc_SetPowerState(dc_PowerStateRequestResultType* Result)
* \Description     : This API configures the Adc module so that it enters the already prepared power state,
*                    chosen between a predefined set of configured ones.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): Result If the API returns E_OK:                                                                             
*                               ADC_SERVICE_ACCEPTED: Power state change executed.                                               
*                           If the API returns E_NOT_OK:                                                                         
*                               ADC_NOT_INIT: ADC Module not initialized.                                                        
*                               ADC_SEQUENCE_ERROR: wrong API call sequence.                                                     
*                               ADC_HW_FAILURE: the HW module has a failure which prevents it to enter the required power state. 
*                            
* \Return value:   : Std_ReturnType E_OK: Power Mode changed
*                                   E_NOT_OK: request rejected
*******************************************************************************/
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType* Result)
{
	(void)Result;
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType* CurrentPowerState, Adc_PowerStateRequestResultType* Result)
* \Description     : This API returns the current power state of the ADC HW unit.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): CurrentPowerState The current power mode of the ADC HW Unit is returned in this parameter
* \Parameters (out): Result                                                                                    
*                    If the API returns E_OK:                                                                   
*                            ADC_SERVICE_ACCEPTED: Current power mode was returned.                             
*                    If the API returns E_NOT_OK:                                                               
*                            ADC_NOT_INIT: ADC Module not initialized.                                          
* \Return value:   : Std_ReturnType  E_OK: Mode could be read
*                                    E_NOT_OK: Service is rejected
*******************************************************************************/
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType* CurrentPowerState, Adc_PowerStateRequestResultType* Result)
{
	(void)CurrentPowerState;
    (void)Result;
	
}

/******************************************************************************
* \Syntax          : Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType* TargetPowerState, Adc_PowerStateRequestResultType* Result)
* \Description     : This API returns the Target power state of the ADC HW unit.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): TargetPowerState The Target power mode of the ADC HW Unit is returned in this parameter
* \Parameters (out): Result 
*                    If the API returns
*                        E_OK:
*                            ADC_SERVICE_ACCEPTED:Target power mode was returned.
*                    If the API returns E_NOT_OK:
*                            ADC_NOT_INIT: ADC Module not initialized.
* \Return value:   : Std_ReturnType  E_OK: Mode could be read
*                                    E_NOT_OK: Service is rejected
*******************************************************************************/
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType* TargetPowerState, Adc_PowerStateRequestResultType* Result)
{
	(void)TargetPowerState;
    (void)Result;	
}

/******************************************************************************
* \Syntax          : Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState, Adc_PowerStateRequestResultType* Result)
* \Description     : This API starts the needed process to allow the ADC HW module to enter the
*                     requested power state.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PowerState The target power state intended to be attained
* \Parameters (out): Result 
*                        If the API returns
*                        E_OK:
*                            ADC_SERVICE_ACCEPTED: ADC Module power state preparation was started.
*                        If the API returns 
*                        E_NOT_OK:
*                            ADC_NOT_INIT: ADC Module not initialized.
*                            ADC_SEQUENCE_ERROR: wrong API call sequence (Current Power State = Target Power State).
*                            ADC_POWER_STATE_NOT_SUPP: ADC Module does not support the requested power state.
*                            ADC_TRANS_NOT_POSSIBLE: ADC Module cannot transition directly from the current power state to 
*                                                     the requested power state or the HW peripheral is still busy.
* \Return value:   : Std_ReturnType  E_OK: Preparation process started
*                                    E_NOT_OK:Service is rejected
*******************************************************************************/
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState, Adc_PowerStateRequestResultType* Result)
{
	(void)PowerState;
	(void)Result;
}

/**********************************************************************************************************************
 *  END OF FILE: Adc.c
 *********************************************************************************************************************/
