#include "hal_data.h"

#define ENABLE_WRRITE_OPERATION  (0U)

memory_info_t stdboot_memory_info[4];

uint8_t firmare_read_data[2048];
uint32_t firmare_read_data_u32[256];

device_signature_info_t device_info;
device_lifecycle_management_state_t current_dlm_state;
trustzone_memory_boundary_info_t current_memory_boundary;
#if (ENABLE_WRRITE_OPERATION == 1U)
trustzone_memory_boundary_info_t request_memory_boundary;
#endif

void stdboot_example(void)
{
    fsp_err_t fsp_err = FSP_SUCCESS;

    /* Open driver */
    /* Note: IOPORT and SCI module drive must be opened before the stdboot driver starts */
    STDBOOT_Open(&g_stdboot0_ctrl, &g_stdboot0_cfg);

    /* Open serial command interface */
    STDBOOT_TargetBootModeEnter(&g_stdboot0_ctrl);
    R_BSP_SoftwareDelay(750, BSP_DELAY_UNITS_MILLISECONDS);

    fsp_err = STDBOOT_TargetSettingUp(&g_stdboot0_ctrl);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Send inquiry command */
    fsp_err = STDBOOT_InquiryCommandCheck(&g_stdboot0_ctrl, 1000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Read device signature infomation */
    fsp_err = STDBOOT_DeviceSignatureRead(&g_stdboot0_ctrl, &device_info, 1000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Read area information */
    fsp_err = STDBOOT_AreaInformationRead(&g_stdboot0_ctrl, &stdboot_memory_info[0], 2, 1000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Read current DLM state */
    if((g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33) || (g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33_RA4E1_RA6E1) || (g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33_RA6T2))
    {
        fsp_err = STDBOOT_DLMStateRead(&g_stdboot0_ctrl, &current_dlm_state, 1000);
        if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
    }

    /* Read tz memory boundary info */
    if((g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33) || (g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33_RA4E1_RA6E1) || (g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33_RA6T2))
    {
        fsp_err = STDBOOT_TrustZoneMemoryBoundaryRead(&g_stdboot0_ctrl, &current_memory_boundary, 1000);
        if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
    }

#if (ENABLE_WRRITE_OPERATION == 1U)
    /* Write tz memory boundary info */
    if((g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33) || (g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33_RA4E1_RA6E1) || (g_stdboot0_cfg.system_type == DEVICE_TYPE_RA_CM33_RA6T2))
    {
        request_memory_boundary.code_flash_secure_size       = 0x180000;
        request_memory_boundary.code_flash_secure_w_nsc_size = 0x200000;
        request_memory_boundary.data_flash_secure_size       = 0x1000;
        request_memory_boundary.sram_secure_size             = 0x40000;
        request_memory_boundary.sram_secure_w_nsc_size       = 0x60000;

        fsp_err = STDBOOT_TrustZoneMemoryBoundarySet(&g_stdboot0_ctrl, request_memory_boundary, 1000);
        if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
    }
#endif

    /* Read memory 0x0~1124B */
    fsp_err = STDBOOT_MemoryRead(&g_stdboot0_ctrl, 0x0, 1124, &firmare_read_data[0], 10000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
    memcpy(&firmare_read_data_u32[0], &firmare_read_data[0], 0x400);

#if (ENABLE_WRRITE_OPERATION == 1U)
    /* Erase program sections */
    fsp_err = STDBOOT_MemoryErase(&g_stdboot0_ctrl, <start addr>, <request size>, 10000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
#endif

#if (ENABLE_WRRITE_OPERATION == 1U)
    /* Program new firmware */
    fsp_err = STDBOOT_MemoryProgram(&g_stdboot0_ctrl, <start addr>, <request size>, <pointer to image strage>, 10000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
#endif

    /* Change UART baudrate */
    fsp_err = STDBOOT_UARTBaudRateChange(&g_stdboot0_ctrl, BAUD_RATE_1500000_BPS, 1000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Close serial command interface */
    STDBOOT_TargetBootModeExit(&g_stdboot0_ctrl);

    /* Close driver */
    STDBOOT_Close(&g_stdboot0_ctrl);
}

