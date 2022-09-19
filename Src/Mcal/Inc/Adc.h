/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Adc.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef __ADC_H__
#define __ADC_H__

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

/******************************************************************************
* \Name            : Adc_ConfigType
* \Type            : Structure
* \Range           : Implementation specific configuration data structure.
* \Description     : Data structure containing the set of configuration parameters required for
                      initializing the ADC Driver and ADC HW Unit(s).
*******************************************************************************/
typedef struct {
    uint32 configurations;
} Adc_ConfigType;

/******************************************************************************
* \Name            : Adc_ChannelType
* \Type            : uint
* \Range           : Implementation specific
* \Description     : Numeric ID of an Adc.channel.
*******************************************************************************/
typedef uint32 Adc_ChannelType;

/******************************************************************************
* \Name            : Adc_GroupType
* \Type            : uint
* \Range           : uC Specific
* \Description     : Numeric ID of an Adc.channel group.
*******************************************************************************/
typedef uint32 Adc_GroupType;

/******************************************************************************
* \Name            : Adc_ValueGroupType
* \Type            : int
* \Range           : Implementation specific
* \Description     : Type for reading the converted values of a channel group (raw, without further
*                       scaling, alignment according precompile switch ADC_RESULT_ALIGNMENT)
*******************************************************************************/
typedef uint32 Adc_ValueGroupType;

/******************************************************************************
* \Name            : Adc_PrescaleType
* \Type            : uint
* \Range           : uC Specific
* \Description     : Type of clock prescaler factor. (This is not an API type).
*******************************************************************************/
typedef uint32 Adc_PrescaleType;

/******************************************************************************
* \Name            : Adc_ConversionTimeType
* \Type            : uint
* \Range           : uC Specific
* \Description     : Type of conversion time, i.e. the time during which the sampled analogue value is
*                    converted into digital representation. (This is not an API type).
*******************************************************************************/
typedef uint32 Adc_ConversionTimeType;

/******************************************************************************
* \Name            : Adc_SamplingTimeType
* \Type            : uint
* \Range           : uC Specific
* \Description     : Type of sampling time, i.e. the time during which the value is sampled, (in clockcycles).
                     (This is not an API type).
*******************************************************************************/
typedef uint32 Adc_SamplingTimeType;

/******************************************************************************
* \Name            : Adc_ResolutionType
* \Type            : uint8
* \Range           : uC Specific
* \Description     : Type of channel resolution in number of bits. (This is not an API type).
*******************************************************************************/
typedef uint8 Adc_ResolutionType;

/******************************************************************************
* \Name            : Adc_StatusType
* \Type            : Enumeration
* \Range           : ADC_IDLE                - The conversion of the specified group has not been started.
*                                            - No result is available.
*
*                  : ADC_BUSY                - The conversion of the specified group has been started and is still going on.
*                                            - So far no result is available.
*                    
*                  : ADC_COMPLETED           - A conversion round (which is not the final one) of the specified group has been finished.
*                                            - A result is available for all channels of the group.
*                    
*                  : ADC_STREAM_COMPLETED    - The result buffer is completely filled
*                                            - For each channel of the selected group the number of samples to be acquired is available
* \Description     : Current status of the conversion of the requested ADC Channel group.
*******************************************************************************/
typedef enum {
    ADC_IDLE,
    ADC_BUSY,
    ADC_COMPLETED,
    ADC_STREAM_COMPLETED
} Adc_StatusType;

/******************************************************************************
* \Name            : Adc_TriggerSourceType
* \Type            : Enumeration
* \Range           : ADC_TRIGG_SRC_SW -- Group is triggered by a software API call.
*                  : ADC_TRIGG_SRC_HW -- Group is triggered by a hardware event.
* \Description     : Type for configuring the trigger source for an ADC Channel group
*******************************************************************************/
typedef enum {
    ADC_TRIGG_SRC_SW,
    ADC_TRIGG_SRC_HW
} Adc_TriggerSourceType;

/******************************************************************************
* \Name            : Adc_GroupConvModeType
* \Type            : Enumeration
* \Range           : ADC_CONV_MODE_ONESHOT
*                        Exactly one conversion of each channel in an
*                        Adc.channel group is performed after the
*                        configured trigger event.
*                        In case of 'group trigger source software', a
*                        started One-Shot conversion can be stopped by a
*                        software API call.
*                        In case of 'group trigger source hardware', a
*                        started One-Shot conversion can be stopped by
*                        disabling the trigger event (if supported by
*                        hardware).
*                  : ADC_CONV_MODE_CONTINUOUS
*                        Repeated conversions of each Adc.channel in an
*                        Adc.channel group are performed.
*                        'Continuous conversion mode' is only available for
*                        'group trigger source software'.
*                        A started 'Continuous conversion' can be stopped
*                        by a software API call.
* \Description     : Type for configuring the conversion mode of an ADC Channel group.
*******************************************************************************/
typedef enum {
    ADC_CONV_MODE_ONESHOT,
    ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/******************************************************************************
* \Name            : Adc_GroupPriorityType
* \Type            : uint8
* \Range           : 0..255
* \Description     : Priority level of the channel. Lowest priority is 0.
*******************************************************************************/
typedef uint8 Adc_GroupPriorityType;

/******************************************************************************
* \Name            : Adc_GroupDefType
* \Type            : implementation_specific
* \Range           : 
* \Description     : Type for assignment of channels to a channel group (this is not an API type).
*******************************************************************************/
typedef void Adc_GroupDefType; //TODO

/******************************************************************************
* \Name            : Adc_StreamNumSampleType
* \Type            : uint
* \Range           : uC Specific
* \Description     : Type for configuring the number of group conversions in streaming access mode
*                    (in single access mode, parameter is 1).
*******************************************************************************/
typedef uint32 Adc_StreamNumSampleType;

/******************************************************************************
* \Name            : Adc_StreamBufferModeType
* \Type            : Enumeration
* \Range           : ADC_STREAM_BUFFER_LINEAR -- The ADC Driver stops the conversion as soon
*                                                as the stream buffer is full (number of samples
*                                                reached).
*                  : ADC_STREAM_BUFFER_CIRCULAR -- The ADC Driver continues the conversion
*                                                  even if the stream buffer is full (number of
*                                                  samples reached) by wrapping around the
*                                                  stream buffer itself.
* \Description     : Type for configuring the streaming access mode buffer type.
*******************************************************************************/
typedef enum {
    ADC_STREAM_BUFFER_LINEAR,
    ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;

/******************************************************************************
* \Name            : Adc_GroupAccessModeType
* \Type            : Enumeration
* \Range           : ADC_ACCESS_MODE_SINGLE -- Single value access mode.
*                  : ADC_ACCESS_MODE_STREAMING -- Streaming access mode.
* \Description     : Type for configuring the access mode to group conversion results
*******************************************************************************/
typedef enum {
    ADC_ACCESS_MODE_SINGLE,
    ADC_ACCESS_MODE_STREAMING
} Adc_GroupAccessModeType;

/******************************************************************************
* \Name            : Adc_HwTriggerSignalType
* \Type            : Enumeration
* \Range           : ADC_HW_TRIG_RISING_EDGE -- React on the rising edge of the hardware trigger signal (only if supported by the Adc.hardware).
*                  : ADC_HW_TRIG_FALLING_EDGE -- React on the falling edge of the hardware trigger signal (only if supported by the Adc.hardware).
*                  : ADC_HW_TRIG_BOTH_EDGES -- React on both edges of the hardware trigger signal (only if supported by the Adc.hardware).
* \Description     : Type for configuring on which edge of the hardware trigger signal the driver should
*                     react, i.e. start the conversion (only if supported by the Adc.hardware).
*******************************************************************************/
typedef enum {
    ADC_HW_TRIG_RISING_EDGE,
    ADC_HW_TRIG_FALLING_EDGE,
    ADC_HW_TRIG_BOTH_EDGES
} Adc_HwTriggerSignalType;

/******************************************************************************
* \Name            : Adc_HwTriggerTimerType
* \Type            : uint
* \Range           : uC Specific
* \Description     : Type for the reload value of the ADC module embedded timer (only if supported by the Adc.hardware).
*******************************************************************************/
typedef uint32 Adc_HwTriggerTimerType;

/******************************************************************************
* \Name            : Adc_PriorityImplementationType
* \Type            : Enumeraion
* \Range           : ADC_PRIORITY_NONE -- priority mechanism is not available
*                  : ADC_PRIORITY_HW -- Hardware priority mechanism is available only
*                  : ADC_PRIORITY_HW_SW -- Hardware and software priority mechanism is available
* \Description     : Type for configuring the prioritization mechanism.
*******************************************************************************/
typedef enum {
    ADC_PRIORITY_NONE,
    ADC_PRIORITY_HW,
    ADC_PRIORITY_SW
} Adc_PriorityImplementationType;

/******************************************************************************
* \Name            : Adc_GroupReplacementType
* \Type            : Enumeration
* \Range           : ADC_GROUP_REPL_ABORT_RESTART -- Abort/Restart mechanism is used on
*                     group level, if a group is interrupted by a
*                     higher priority group. The complete
*                     conversion round of the interrupted group
*                     (all group channels)is restarted after the
*                     higher priority group conversion is
*                     finished. If the group is configured in
*                     streaming access mode, only the results
*                     of the interrupted conversion round are
*                     discarded. Results of previous
*                     conversion rounds which are already
*                     written to the result buffer are not
*                     affected.
*                  : ADC_GROUP_REPL_SUSPEND_RESUME -- Suspend/Resume mechanism is used on
*                     group level, if a group is interrupted by a
*                     higher priority group. The conversion
*                     round of the interrupted group is
*                     completed after the higher priority group
*                     conversion is finished. Results of
*                     previous conversion rounds which are
*                     already written to the result buffer are not
*                     affected.
* \Description     : Replacement mechanism, which is used on ADC group level, if a group conversion
*                     is interrupted by a group which has a higher priority.
*******************************************************************************/
typedef enum {
    ADC_GROUP_REPL_ABORT_RESTART,
    ADC_GROUP_REPL_SUSPEND_RESUME
} Adc_GroupReplacementType;

/******************************************************************************
* \Name            : Adc_ChannelRangeSelectType
* \Type            : Enumeration
* \Range           : ADC_RANGE_UNDER_LOW -- Range below low limit - low limit value included
*                  : ADC_RANGE_BETWEEN -- Range between low limit and high limit - high limit value included
*                  : ADC_RANGE_OVER_HIGH -- Range above high limit
*                  : ADC_RANGE_ALWAYS -- Complete range - independent from channel limit settings
*                  : ADC_RANGE_NOT_UNDER_LOW -- Range above low limit
*                  : ADC_RANGE_NOT_BETWEEN -- Range above high limit or below low limit - low limit value included
*                  : ADC_RANGE_NOT_OVER_HIGH -- Range below high limit - high limit value included
* \Description     : In case of active limit checking: defines which conversion values are taken into
*                     account related to the boardes defineed with AdcChannelLowLimit and
*                     AdcChannelHighLimit
*******************************************************************************/
typedef enum {
    ADC_RANGE_UNDER_LOW,
    ADC_RANGE_BETWEEN,
    ADC_RANGE_OVER_HIGH,
    ADC_RANGE_ALWAYS,
    ADC_RANGE_NOT_UNDER_LOW,
    ADC_RANGE_NOT_BETWEEN,
    ADC_RANGE_NOT_OVER_HIGH
} Adc_ChannelRangeSelectType;

/******************************************************************************
* \Name            : Adc_ResultAlignmentType
* \Type            : Enumeration
* \Range           : ADC_ALIGN_LEFT -- left alignment
* \Range           : ADC_ALIGN_RIGHT -- right alignment
* \Description     : Type for alignment of ADC raw results in ADC result buffer (left/right alignment).
*******************************************************************************/
typedef enum {
    ADC_ALIGN_LEFT,
    ADC_ALIGN_RIGHT
} Adc_ResultAlignmentType;

/******************************************************************************
* \Name            : Adc_PowerStateType
* \Type            : Enumeration
* \Range           : 1..255 -- power modes with decreasing power consumptions.
* \Range           : ADC_FULL_POWER 0 Full Power
* \Description     : Power state currently active or set as target power state.
*******************************************************************************/
typedef enum {
    ADC_FULL_POWER
} Adc_PowerStateType;

/******************************************************************************
* \Name            : Adc_PowerStateRequestResultType
* \Type            : Enumeration 
* \Range           : ADC_SERVICE_ACCEPTED 0 Power state change executed.
* \Range           : ADC_NOT_INIT 1 ADC Module not initialized.
* \Range           : ADC_SEQUENCE_ERROR 2 Wrong API call sequence.
* \Range           : ADC_HW_FAILURE 3 The HW module has a failure which prevents it to enter the required power state.
* \Range           : ADC_POWER_STATE_NOT_SUPP 4 ADC Module does not support the requested power state.
* \Range           : ADC_TRANS_NOT_POSSIBLE 5 ADC Module cannot transition directly from the current power state to the
*                                              requested power state or the HW peripheral is still busy.
* \Description     : Result of the requests related to power state transitions.
*******************************************************************************/
typedef enum {
    ADC_SERVICE_ACCEPTED,
    ADC_NOT_INIT,
    ADC_SEQUENCE_ERROR,
    ADC_HW_FAILURE,
    ADC_POWER_STATE_NOT_SUPP,
    ADC_TRANS_NOT_POSSIBLE
} Adc_PowerStateRequestResultType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void Adc_Init(const Adc_ConfigType* ConfigPtr);

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
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, const Adc_ValueGroupType* DataBufferPtr);

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
void Adc_DeInit(void);

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
void Adc_StartGroupConversion(Adc_GroupType Group);

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
void Adc_StopGroupConversion(Adc_GroupType Group);

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
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);

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
void Adc_EnableHardwareTrigger(Adc_GroupType Group);

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
void Adc_DisableHardwareTrigger(Adc_GroupType Group);

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
void Adc_EnableGroupNotification(Adc_GroupType Group);

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
void Adc_DisableGroupNotification(Adc_GroupType Group);

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
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);

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
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr);

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
void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo);

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
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType* Result);

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
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType* CurrentPowerState, Adc_PowerStateRequestResultType* Result);

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
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType* TargetPowerState, Adc_PowerStateRequestResultType* Result);

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
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState, Adc_PowerStateRequestResultType* Result);

 
#endif  /* __ADC_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Adc.h
 *********************************************************************************************************************/
