/* =============================================================================
#     FileName: rua_mcu_dev.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2020-05-30 14:33:30
#      History: none
============================================================================= */

#ifndef __RUA_MCU_DEV_H__
#define __RUA_MCU_DEV_H__

#define     RUA_MCU_MMAP_DEVICE           UART_API_KERNEL_DEVICE_MMAP_MCU_NAME
#define     RUA_MCU_TTY_DEVICE            UART_API_KERNEL_DEVICE_MCU_NAME
#define     RUA_MCU_BAUDRATE              UART_API_KERNEL_DEVICE_MCU_BAUD

#define     RUA_MCU_DATA_WIDTH            8
#define     RUA_MCU_PARITY                'N'
#define     RUA_MCU_STOP_BIT              1
#define     RUA_MCU_LOCK_UART             1

#define MCU_STATE_IDLE 1
#define UART_MCU_IOCTL  0x58

#define UART_MCU_IOCTL_SET_BUFFSER_SIZE _IOW(UART_MCU_IOCTL, 0x10, int)

#define UART_MCU_IOCTL_SET_MCU_WAKE     _IOW(UART_MCU_IOCTL, 0xc0, int)
#define UART_MCU_IOCTL_SET_MCU_IDLE     _IOW(UART_MCU_IOCTL, 0xc3, int)
#define UART_MCU_IOCTL_GET_MCU_STATE    _IOW(UART_MCU_IOCTL, 0x33, int)

#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
    TIMEOUT_NONBLOCK   = 0, //not support now
    TIMEOUT_NORMAL     = 1,
    TIMEOUT_BLOCK      = 2,
}
ReadTimeOut_e;
//for swd only open dev file
extern int rua_swd_open_mcu_dev_file(void);
//for swd end
extern int set_mcu_state(int wakeup);
extern int get_mcu_state(void);
extern int init_uart();
extern void close_uart();
#if defined(UART_API_PLATFORM_ALLWINNER_MR813)
extern int reinit_init_mcu_with_rx_dma(int rx_dma_enable_flag);
#endif

extern int sent_raw(const char *buffer, int len);
extern int get_raw(char *buffer, int max_lengh);
extern void clean_uart();
extern int is_mcu_tty_inited();
extern void set_wait_package_timeout_ms(ReadTimeOut_e timeout);
extern void clean_mmap_cache(void);
extern int isMcuMmapBufferFull(void);

#ifdef __cplusplus
}
#endif

#endif
