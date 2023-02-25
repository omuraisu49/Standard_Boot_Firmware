# Standrd Boot Firmware
This library shows usage example of standard boot firmware.

# Referenced document
- Renesas RA Family "System Specifications for Standard Boot Firmware" (R01AN5372)
- Renesas RA Family "System Specifications for Standard Boot Firmware" (R01AN6347)
- Renesas RA Family "Standard Boot Firmware for the RA family MCUs Based on Arm® Cortex®-M33" (R01AN5562)

# API List
| Name | RA CM4 | RA CM23 | RA CM33 <br> RA4M2/RA4M3 <br> RA6M4/RA6M5 | RA CM33 <br> RA4E1/RA6E1 | RA CM33 <br> RA6T2 | Support Status <br> (Version0.9.3) |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|
| [STDBOOT_Open](#STDBOOT_Open)                                               | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_Close](#STDBOOT_Close)                                             | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_TargetReset](#STDBOOT_TargetReset)                                 | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_TargetBootModeEnter](#STDBOOT_TargetBootModeEnter)                 | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_TargetBootModeExit](#STDBOOT_TargetBootModeExit)                   | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_TargetSettingUp](#STDBOOT_TargetSettingUp)                         | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_UARTBaudRateChange](#STDBOOT_UARTBaudRateChange)                   | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_InquiryCommandCheck](#STDBOOT_InquiryCommandCheck)                 | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_DeviceSignatureRead](#STDBOOT_DeviceSignatureRead)                 | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_AreaInformationRead](#STDBOOT_AreaInformationRead)                 | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_MemoryErase](#STDBOOT_MemoryErase)                                 | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_MemoryRead](#STDBOOT_MemoryRead)                                   | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_MemoryProgram](#STDBOOT_MemoryProgram)                             | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_MemoryCRCValueGet](#STDBOOT_MemoryCRCValueGet)                     | \- | \- | ✓ | ✓ | ✓ | △ |
| [STDBOOT_DLMStateRead](#STDBOOT_DLMStateRead)                               | \- | \- | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_DLMStateInitialize](#STDBOOT_DLMStateInitialize)                   | \- | \- | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_DLMStateTransit](#STDBOOT_DLMStateTransit)                         | \- | \- | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_DLMAuthKeySet](#STDBOOT_DLMAuthKeySet)                             | \- | \- | ✓ | ✓ | ✓ | △ |
| [STDBOOT_DLMAuthKeyVerify](#STDBOOT_DLMAuthKeyVerify)                       | \- | \- | ✓ | ✓ | ✓ | △ |
| [STDBOOT_DLMAuthentication](#STDBOOT_DLMAuthentication)                     | \- | \- | ✓ | ✓ | ✓ | \- |
| [STDBOOT_IDAuthentication](#STDBOOT_IDAuthentication)                       | ✓ | ✓ | \- | \- | \- | ✓ |
| [STDBOOT_UserKeySet](#STDBOOT_UserKeySet)                                   | \- | \- | ✓ | \- | ✓ | △ |
| [STDBOOT_UserKeyVerify](#STDBOOT_UserKeyVerify)                             | \- | \- | ✓ | \- | ✓ | △ |
| [STDBOOT_TrustZoneMemoryBoundaryRead](#STDBOOT_TrustZoneMemoryBoundaryRead) | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_TrustZoneMemoryBoundarySet](#STDBOOT_TrustZoneMemoryBoundarySet)   | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_DirectPinControl](#STDBOOT_DirectPinControl)                       | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_DirectCommadSend](#STDBOOT_DirectCommadSend)                       | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| [STDBOOT_WaitReadComplete](#STDBOOT_WaitReadComplete)                       | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |

✓ : Supported, \- : Not supported, △ : Untested

# API Description
## STDBOOT_Open
```
fsp_err_t STDBOOT_Open (stdboot_ctrl_t* p_ctrl, stdboot_cfg_t* p_cfg);
```
Configures the STDBOOT driver based on the input configuration.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_cfg: Pointer to stdboot configuration block.
- Return values
    - FSP_SUCCESS: Driver opened successfully.
- Notes
    - None

## STDBOOT_Close
```
fsp_err_t STDBOOT_Close (stdboot_ctrl_t* p_ctrl);
```
Aborts previous session and revert the callback configuration to old one. Clears driver open flag.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
- Return values
    - FSP_SUCCESS: Driver closed successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
- Notes
    - None

## STDBOOT_TargetReset
```
fsp_err_t STDBOOT_TargetReset (stdboot_ctrl_t* p_ctrl);
```
Attempt to reset the target device. The reset pin, acvive level and hold time are based on the STDBOOT configuration.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
- Return values
    - FSP_SUCCESS: Target reset attempted successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
- Notes
    - None

## STDBOOT_TargetBootModeEnter
```
fsp_err_t STDBOOT_TargetBootModeEnter (stdboot_ctrl_t* p_ctrl);
```
Attempt to enter the target device to SCI boot mode.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
- Return values
    - FSP_SUCCESS: Target boot mode entering attempted successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
- Notes
    - The MD pin will be kept the hold state after API return.

## STDBOOT_TargetBootModeExit
```
fsp_err_t STDBOOT_TargetBootModeExit (stdboot_ctrl_t* p_ctrl);
```
Attempt to exit SCI boot mode for target device.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
- Return values
    - FSP_SUCCESS: Target boot mode exiting attempted successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
- Notes
    - None

## STDBOOT_TargetSettingUp
```
fsp_err_t STDBOOT_TargetSettingUp (stdboot_ctrl_t* p_ctrl);
```
Attempt to starting up the SCI boot mode in target device.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
- Return values
    - FSP_SUCCESS: The SCI boot interface in target device opened successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
- Notes
    - None

## STDBOOT_UARTBaudRateChange
```
fsp_err_t STDBOOT_UARTBaudRateChange (stdboot_ctrl_t* p_ctrl, baud_rate_option_t option, uint32_t timeout_ms);
```
Changes UART baud rate with provided rate option. API sets the baud rate to target device first, and then change the baud rate on HOST side.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - option: Baud rate selection. Available options are:
        - BAUD_RATE_9600_BPS
        - BAUD_RATE_115200_BPS
        - BAUD_RATE_500000_BPS
        - BAUD_RATE_1000000_BPS
        - BAUD_RATE_1500000_BPS
        - BAUD_RATE_2000000_BPS
        - BAUD_RATE_4000000_BPS
        - BAUD_RATE_6000000_BPS
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: UART baudrate changed successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: Invalid parameter received.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_InquiryCommandCheck
```
fsp_err_t STDBOOT_InquiryCommandCheck (stdboot_ctrl_t* p_ctrl, uint32_t timeout_ms);
```
Checks inquiry command operation.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Inquiry command operation done successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_DeviceSignatureRead
```
fsp_err_t STDBOOT_DeviceSignatureRead (stdboot_ctrl_t* p_ctrl, device_signature_info_t* p_info, uint32_t timeout_ms);
```
Reads the device signature infomation.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_info: Pointer to output buffer.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Device signature read successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_AreaInformationRead
```
fsp_err_t STDBOOT_AreaInformationRead (stdboot_ctrl_t* p_ctrl, memory_info_t* p_info, uint8_t request_num, uint32_t timeout_ms);
```
Reads the area information.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_info: Pointer to output buffer.
    - request_num: Number of area to request.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Area information read successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_MemoryErase
```
fsp_err_t STDBOOT_MemoryErase (stdboot_ctrl_t* p_ctrl, uint32_t start_addr, uint32_t size, uint32_t timeout_ms);
```
Configures the STDBOOT driver based on the input configuration.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - start_addr: Start address of erase area.
    - request_size: Request size of erase area.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Memory eraseed successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - The erase start address must be on the flash block boundary.
    - The erase size must be integral multiple of erase block size.

## STDBOOT_MemoryRead
```
fsp_err_t STDBOOT_MemoryRead (stdboot_ctrl_t* p_ctrl, uint32_t start_addr, uint32_t request_size, void* p_buff, uint32_t timeout_ms);
```
Reads flash memory.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - start_addr: Start address of read area.
    - request_size: Request size of read area.
    - p_buff: Pointer to output buffer.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Memory read successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_MemoryProgram
```
fsp_err_t STDBOOT_MemoryProgram (stdboot_ctrl_t* p_ctrl, uint32_t start_addr, uint32_t request_size, cosnt void* p_buff, uint32_t timeout_ms);
```
Programs flash memory.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - start_addr: Start address of write area.
    - request_size: Request size of write area.
    - p_buff: Pointer to souce data buffer.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Memory programed successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - The program start address must be aligned with flash write size.
    - The program size must be integral multiple of flash write size.

## STDBOOT_MemoryCRCValueGet
```
fsp_err_t STDBOOT_MemoryCRCValueGet (stdboot_ctrl_t* p_ctrl, uint32_t start_addr, uint32_t request_size, void* p_buff, uint32_t timeout_ms);
```
Gets CRC value of specified flash memory.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - start_addr: Start address of read area.
    - request_size: Request size of read area.
    - p_buff: Pointer to output buffer.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Memory CRC value received successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_DLMStateRead
```
fsp_err_t STDBOOT_DLMStateRead (stdboot_ctrl_t* p_ctrl, device_lifecycle_management_state_t* p_output, uint32_t timeout_ms);
```
Read current DLM state in target device.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_output: Pointer to outout variable.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: DLM state read successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_DLMStateInitialize
```
fsp_err_t STDBOOT_DLMStateInitialize (stdboot_ctrl_t* p_ctrl, device_lifecycle_management_state_t current_state, uint32_t timeout_ms);
```
Initialize DLM state, DPL=>SSD, NSECSD=>SSD, SSD=>SSD. The flash controler erases flash memory duing state initialization.
- Input parameters
    - p_ctrl: Pointer to stdboot control block
    - current_state: Current DLM state.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: DLM state initialized successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - After DLM state initialization, there may be no response from target device. Therefore the API may return with a timeout.

## STDBOOT_DLMStateTransit
```
fsp_err_t STDBOOT_DLMStateTransit (stdboot_ctrl_t* p_ctrl, device_lifecycle_management_state_t current_state, device_lifecycle_management_state_t next_state, uint32_t timeout_ms);
```
Transits DLM state, CM=>SSD, SSD=>NSECSD, NSECSD=>DPL, SSD/NSECSD/DPL=>LCK_DBG, LCK_DBG=>LCK_BOOT.
- Input parameters
    - p_ctrl: Pointer to stdboot control block
    - current_state: Current DLM state.
    - next_state: DLM state you want to transit to.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: DLM state transit successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_DLMAuthKeySet
```
fsp_err_t STDBOOT_DLMAuthKeySet (stdboot_ctrl_t* p_ctrl, dlm_auth_key_type_t key_type, key_data_info_t key_data_info, uint32_t timeout_ms);
```
Installs DLM authentication key.
- Input parameters
    - p_ctrl: Pointer to stdboot control block
    - key_type: DLM key Type to be installed. 
    - key_data_info: Infomation of key data buffer.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: DLM auth key installed successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_DLMAuthKeyVerify
```
fsp_err_t STDBOOT_DLMAuthKeyVerify (stdboot_ctrl_t* p_ctrl, dlm_auth_key_type_t key_type, uint8_t* result, uint32_t timeout_ms);
```
Verifis the DLM authentication key.
- Input parameters
    - p_ctrl: Pointer to stdboot control block
    - key_type: DLM key Type to be installed. 
    - p_result: Pointer to result variable.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: DLM auth key verification done successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_DLMAuthentication
```
fsp_err_t STDBOOT_DLMAuthentication (stdboot_ctrl_t* p_ctrl, device_lifecycle_management_state_t current_state, device_lifecycle_management_state_t next_state, uint8_t* p_key_data, uint32_t key_length, uint32_t timeout_ms);
```
Attempt to DLM authentication, to transit the DLM state, NSECSD=>SSD, DPL=>NSECSD, DPL=>RMA_REQ, RMA_REQ=>RMA_ACK, SSD=>RMA_REQ.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - current_state: Current DLM state.
    - next_state: DLM state you want to transit to.
    - p_key_data: Pointer to key data.
    - key_length: Length of key data.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: DLM authentication done successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_IDAuthentication
```
fsp_err_t STDBOOT_IDAuthentication (stdboot_ctrl_t* p_ctrl, uint8_t* p_id_code, uint32_t timeout_ms);
```
Attempt to ID code authentication.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_id_code: Pointer to ID code data.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: ID code authentication done successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - The ID code data must be passed in big-endian style.

## STDBOOT_UserKeySet
```
fsp_err_t STDBOOT_UserKeySet (stdboot_ctrl_t* p_ctrl, uint32_t key_address, user_key_type_t key_type, key_data_info_t key_data_info, uint32_t timeout_ms);
```
Installs user key.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - key_address: Address of key installation location.
    - key_type: DLM key type to be installed. 
    - key_data_info: Infomation of key data buffer.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: User key installed successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_UserKeyVerify
```
fsp_err_t STDBOOT_UserKeyVerify (stdboot_ctrl_t* p_ctrl, uint32_t key_address, user_key_type_t key_type, uint8_t* p_result, uint32_t timeout_ms);
```
Verifies the user key.
- Input parameters
    - p_ctrl: Pointer to stdboot control block
    - key_address: Address of target key location 
    - key_type: DLM key Type to be installed. 
    - p_result: Pointer to result variable.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: User key verification done successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_TrustZoneMemoryBoundaryRead
```
fsp_err_t STDBOOT_TrustZoneMemoryBoundaryRead (stdboot_ctrl_t* p_ctrl, trustzone_memory_boundary_info_t* p_info, uint32_t timeout_ms);
```
Reads TrustZone® memory boundary information.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_info: Pointer to output info variable.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: TrustZone® memory boundary read successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_TrustZoneMemoryBoundarySet
```
fsp_err_t STDBOOT_TrustZoneMemoryBoundarySet (stdboot_ctrl_t* p_ctrl, trustzone_memory_boundary_info_t info, uint32_t timeout_ms);
```
Set TrustZone® memory boundary information.
- Input parameters
    - p_ctrl: Pointer to stdboot control block
    - info: Information of TZ memory boundary to be set.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: TrustZone® memory boundary set successfully.
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_UNSUPPORTED: API not available for selected target device type.
    - FSP_ERR_INVALID_SIZE: Invalid memory boundary received.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
    - (Status code of STDBOOT standard)
- Notes
    - None

## STDBOOT_DirectPinControl
```
void STDBOOT_DirectPinControl (bsp_io_port_pin_t pin, bsp_io_level_t level);
```
Controls level for the specified pin.
- Input parameters
    - pin: Pin selection.
    - level: Level selection.
- Return values
    - None
- Notes
    - None

## STDBOOT_DirectCommadSend
```
fsp_err_t STDBOOT_DirectCommadSend (stdboot_ctrl_t* p_ctrl, control_packet_t* p_packet);
```
Sends STDBOOT standarded pacekt data to target device.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_packet: Pointer to packet information.
- Return values
    - FSP_SUCCESS: Direct comamnd sent successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
- Notes
    - This API executes blocking operation. The API may not return for up to 500ms.

## STDBOOT_ModuleRead
```
fsp_err_t STDBOOT_ModuleRead (stdboot_ctrl_t* p_ctrl, uint8_t* p_buff, uint32_t reuqest_size, uint8_t request_packet);
```
Reads the data from target device.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - p_buff: Pointer to output buffer if STDBOOT packet data is not reuqested. 
    - request_size: Request size if STDBOOT packet data is not requested.
    - request_packet: Indicates if requests STDBOOT standard packet data. 0: Normal data, 1: STDBOOT standard packet data.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: Module read successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
- Notes
    - This API executes non-blocking operation. STDBOOT_WaitReadComplete API should be used to indicate the current operation status. 

## STDBOOT_WaitReadComplete
```
fsp_err_t STDBOOT_WaitReadComplete (stdboot_ctrl_t* p_ctrl, uint32_t timeout_ms);
```
Checks read complete/error flags to indicate current operation status. If not asserted, wait for provided time.
- Input parameters
    - p_ctrl: Pointer to stdboot control block.
    - timout_ms: Timeout value in millisecond.
- Return values
    - FSP_SUCCESS: UART RX completed successfully
    - FSP_ERR_NOT_OPEN: Driver not opened.
    - FSP_ERR_INTERNAL: Low layer module error occurred. Please check the error code in *stddboot config->uart_internal_error_code*.
    - FSP_ERR_TIMEOUT: No response from target device in timeout period. 
    - FSP_ERR_INVALID_DATA: Invalid data received from target device.
- Notes
    - None