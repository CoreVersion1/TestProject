/*************************************************************************
 * Copyright (c) 2023 Baidu.com, Inc. All Rights Reserved
 *
 ************************************************************************/

#ifndef BD_HONGHU_DSP_SLAVE_BOOT_H
#define BD_HONGHU_DSP_SLAVE_BOOT_H

#if defined(__cplusplus)
extern "C" {
#endif

void *bd_dsp_slave_boot_init(const char *spi_name, int spi_speed);

int bd_dsp_slave_boot_uninit(void *p_handle);

int bd_dsp_slave_boot_load_bin(void *p_handle,
                               const char *file_name);

#if defined(__cplusplus)
}
#endif

#endif

