/* =============================================================================
#     FileName: rua_sp_dock_dev.h
#         Desc: serial port dock device
#       Author: yanbaoguang
#        Email: yanbaoguang@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#               2024-05-19
============================================================================= */

#ifndef __RUA_SP_DOCK_DEV_H__
#define __RUA_SP_DOCK_DEV_H__

#define UART_SP_DOCK_IOCTL    0x5A
#define UART_SP_DOCK_IOCTL_SET_BUFFSER_SIZE _IOW(UART_SP_DOCK_IOCTL, 0x10, int)
#define UART_SP_DOCK_IOCTL_SET_DATA_TIMEOUT _IOW(UART_SP_DOCK_IOCTL, 0x11, int)

#define     RUA_SP_DOCK_MMAP_DEVICE           UART_API_KERNEL_DEVICE_MMAP_DOCK_NAME
#define     RUA_SP_DOCK_TTY_DEVICE            UART_API_KERNEL_DEVICE_DOCK_NAME
#define     RUA_SP_DOCK_BAUDRATE              9600

#define     RUA_SP_DOCK_DATA_WIDTH            8
#define     RUA_SP_DOCK_PARITY                'N'
#define     RUA_SP_DOCK_STOP_BIT              1
#define     RUA_SP_DOCK_LOCK_UART             1

// Bootloader      12k      Bootloader
// Param_sector    4k+2k   bootflag,flash manage
// Firmware        110k    Firmware
// Download_sector 110k    New firmware
// Data_sector     18k     LOG & BB info

#define RR_DOCK_FLASH_BASE_ADDR             0x08000000
#define RR_DOCK_VERSION_OFFSET              0x2000

#define RR_DOCK_FLASH_BLD_START_ADDR        0x08000000
#define RR_DOCK_FLASH_BLD_END_ADDR          0x08002FFF
#define RR_DOCK_FLASH_BLD_SIZE              (RR_DOCK_FLASH_BLD_END_ADDR - RR_DOCK_FLASH_BLD_START_ADDR + 1)
#define RR_DOCK_FLASH_BLD_VER_ADDR          (RR_DOCK_FLASH_BLD_START_ADDR + RR_DOCK_VERSION_OFFSET)

#define RR_DOCK_FLASH_REG_START_ADDR        (RR_DOCK_FLASH_BLD_START_ADDR + RR_DOCK_FLASH_BLD_SIZE)
#define RR_DOCK_FLASH_REG_END_ADDR          0x080047FF
#define RR_DOCK_FLASH_REG_SIZE              (RR_DOCK_FLASH_REG_END_ADDR - RR_DOCK_FLASH_REG_START_ADDR + 1)

#define RR_DOCK_FLASH_FW_START_ADDR         0x08004800
#define RR_DOCK_FLASH_FW_END_ADDR           0x0801FFFF
#define RR_DOCK_FLASH_FW_SIZE               (RR_DOCK_FLASH_FW_END_ADDR - RR_DOCK_FLASH_FW_START_ADDR + 1)
#define RR_DOCK_FLASH_FW_VER_ADDR           (RR_DOCK_FLASH_FW_START_ADDR + RR_DOCK_VERSION_OFFSET)

#define RR_DOCK_FLASH_DOWNLOAD_START_ADDR   (RR_DOCK_FLASH_FW_START_ADDR + RR_DOCK_FLASH_FW_SIZE)
#define RR_DOCK_FLASH_DOWNLOAD_END_ADDR     0x0803B7FF
#define RR_DOCK_FLASH_DOWNLOAD_SIZE         (RR_DOCK_FLASH_DOWNLOAD_START_ADDR - RR_DOCK_FLASH_DOWNLOAD_END_ADDR + 1)
#define RR_DOCK_FLASH_DOWNLOAD_VER_ADDR     (RR_DOCK_FLASH_FW_START_ADDR + RR_DOCK_VERSION_OFFSET)

#define RR_DOCK_FLASH_DEF_VALUE             0xFFFFFFFF


#ifdef __cplusplus
extern "C" {
#endif

extern int init_dock_uart();
extern void close_dock_uart();

extern int rua_sp_dock_sent_raw(const char *buffer, int len);
extern int rua_sp_dock_get_raw(char *buffer, int max_lengh);
extern void rua_sp_dock_clean_uart();
extern int is_dock_tty_inited();
extern int isSpDockMmapBufferFull(void);

#ifdef __cplusplus
}
#endif

#endif
