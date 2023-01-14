#include "hal_data.h"

memory_info_t stdboot_memory_info[4];

uint8_t firmare_read_data[2048];
uint32_t firmare_read_data_u32[256];

void hal_entry(void)
{
    fsp_err_t fsp_err;

    /* Open driver */
    /* Note: IOPORT and SCI module must be initialized before the boot firmware driver open */ 
    STDBOOT_Open(&g_stdboot0_ctrl, &g_stdboot0_cfg);

    /* Open serial command interface */
    STDBOOT_TargetBootModeEnter(&g_stdboot0_ctrl);
    R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);

    fsp_err = STDBOOT_TargetSettingUp(&g_stdboot0_ctrl);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Send inquiry command */
    fsp_err = STDBOOT_InquiryCommandCheck(&g_stdboot0_ctrl, 1000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Read area information */
    fsp_err = STDBOOT_AreaInformationRead(&g_stdboot0_ctrl, &stdboot_memory_info[0], 2, 1000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}

    /* Read memory 0x0~1124B */
    fsp_err = STDBOOT_MemoryRead(&g_stdboot0_ctrl, 0x0, 1124, &firmare_read_data[0], 10000);
    if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
    memcpy(&firmare_read_data_u32[0], &firmare_read_data[0], 0x400);

    /* Read current DLM state */
    if((g_stdboot0_cfg.system_type == SYSTEM_TYPE_RA_CM33) || (g_stdboot0_cfg.system_type == SYSTEM_TYPE_RA_CM33_ENTRY))
    {
        device_lifecycle_management_state_t current_dlm_state;
        fsp_err = STDBOOT_DLMStateRead(&g_stdboot0_ctrl, &current_dlm_state, 1000);
        if(FSP_SUCCESS != fsp_err){ __BKPT(0);}
    }

    /* Close serial command interface */
    STDBOOT_TargetBootModeExit(&g_stdboot0_ctrl);

    /* Close driver */
    STDBOOT_Close(&g_stdboot0_ctrl);

    while(1);
}

