/* =============================================================================
#     FileName: rua_carpet_dev.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2020-05-30 14:42:10
#      History: none
============================================================================= */


#ifndef __RUA_CARPET_DEV_H__
#define __RUA_CARPET_DEV_H__

#ifdef UART_API_HAVE_CARPET

#define UART_CARPET_POWER_ALWAYS_ON

#define UART_CARPET_IOCTL    0x56
#define UART_CARPET_IOCTL_SET_BUFFSER_SIZE _IOW(UART_CARPET_IOCTL, 0x10, int)

#define UART_SET_CARPET_POWER              _IOW(UART_CARPET_IOCTL, 0xc0, int)
#define UART_SET_ULTRA_POWER               _IOW(UART_CARPET_IOCTL, 0xc3, int)
#define UART_SET_CARPET_RESET              _IOW(UART_CARPET_IOCTL, 0xc5, int)

#define RUA_CARPET_TTY_DEVICE              UART_API_KERNEL_DEVICE_CARPET_NAME
#define RUA_CARPET_DEV_DEVICE              UART_API_KERNEL_DEVICE_MMAP_CARPET_NAME
#define RUA_CARPET_BAUDRATE                115200
#define RUA_CARPET_DATA_WIDTH              8
#define RUA_CARPET_PARITY                  'N'
#define RUA_CARPET_STOP_BIT                1
#define RUA_CARPET_LOCK_UART               1

#ifdef __cplusplus
extern "C" {
#endif

extern int rua_set_carpet_power(int on);

#ifdef __cplusplus
}
#endif

#endif //UART_API_HAVE_CARPET
#endif //__RUA_CARPET_DEV_H__

