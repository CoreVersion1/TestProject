/*=============================================================================
#     FileName: rua_line_laser_dev.h
#         Desc:
#       Author: zhaoshuai
#        Email: zhaoshuai@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2022-05-05 14:45:02
#      History:
=============================================================================*/


#ifndef __RUA_LINE_LASER_DEV_H__
#define __RUA_LINE_LASER_DEV_H__

#ifdef UART_API_HAVE_LINE_LASER_MODULE

#define UART_LINE_LASER_POWER_ALWAYS_ON

#define UART_LINE_LASER_IOCTL    0x59
#define UART_LINE_LASER_IOCTL_SET_BUFFSER_SIZE _IOW(UART_LINE_LASER_IOCTL, 0x10, int)

#define UART_SET_LINE_LASER_POWER              _IOW(UART_LINE_LASER_IOCTL, 0xc0, int)
#define UART_SET_LINE_LASER_RESET              _IOW(UART_LINE_LASER_IOCTL, 0xc5, int)

#define RUA_LINE_LASER_TTY_DEVICE              UART_API_KERNEL_DEVICE_LINE_LASER_MODULE_NAME
#define RUA_LINE_LASER_DEV_DEVICE              UART_API_KERNEL_DEVICE_MMAP_LINE_LASER_MODULE_NAME
#define RUA_LINE_LASER_BAUDRATE                921600
#define RUA_LINE_LASER_DATA_WIDTH              8
#define RUA_LINE_LASER_PARITY                  'N'
#define RUA_LINE_LASER_STOP_BIT                1
#define RUA_LINE_LASER_LOCK_UART               1

#define RUA_LINE_LASER_READ_TIMEOUT             200

#ifdef __cplusplus
extern "C" {
#endif

extern int  rua_linelaser_uart_init(void);
extern int  rua_is_linelaser_inited(void);
extern void rua_linelaser_uart_close(void);
extern int  rua_linelaser_dev_soft_reset(int cleandata);
extern void rua_linelaser_uart_clean(void);
extern int  rua_linelaser_uart_get_raw(char *buf, int max_lengh,
                                       int timeout_ms);
extern int  rua_linelaser_uart_sent_raw(const char *buf, int len);
//extern int  rua_linelaser_uart_data_size();

#ifdef __cplusplus
}
#endif

#endif //UART_API_HAVE_LINE_LASER_MODULE
#endif //__RUA_LINE_LASER_DEV_H__

