/* =============================================================================
#     FileName: rua_uart_common.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2018-08-07 15:30:28
#      History:
============================================================================= */
#ifndef __RUA_UART_COMMON_H__
#define __RUA_UART_COMMON_H__

#include <sys/ioctl.h>

#ifdef __cplusplus
extern "C" {
#endif
/* If you want to change RuaMmapFifo_st, you must change the drivers of all projects at the same time */
typedef struct {
    struct rua_fifo fifo;
    int state_ready;
    int data_timeout;
} RuaMmapFifo_st;
/* do not change end */

typedef struct {
    int tty_fd;
    int dev_fd; //same as mmap_fd;
    int dev_id; //mcu, lds, or carpet;
    int lock_tty;
    int timeout_ms;
    int use_mmap; //if use mmap, this value should be set to ioctrl_buffersize
    pthread_mutex_t tty_w_lock;
    unsigned int mmap_data_size;
    RuaMmapFifo_st *pfifo;
} RuaUart_st;

extern int rua_uart_init(RuaUart_st **ppU, const char *tty, const char *dev,
                         int baud, int width, char parity, int stop, int lock_tty,
                         int use_mmap, unsigned int mmap_size, int timeout_ms);
#if defined(UART_API_PLATFORM_ALLWINNER_MR813)
extern int rua_uart_init_with_rx_dma(RuaUart_st **ppU, const char *tty,
                                     const char *dev,
                                     int baud, int width, char parity, int stop, int lock_tty,
                                     int use_mmap, unsigned int mmap_size, int timeout_ms,
                                     int rx_dma_enable_flag);
#endif
extern void rua_uart_exit(RuaUart_st **ppU);

extern int  rua_uart_write(RuaUart_st *pU, const char *buf,
                           unsigned int buf_size);
extern int  rua_uart_read(RuaUart_st *pU, char *buf, unsigned int max_read,
                          int timeout_ms);
extern void rua_uart_set_timeout(RuaUart_st *pU, int timeout_ms);
extern void rua_uart_clean(RuaUart_st *pU);
extern int rua_uart_buffer_full(RuaUart_st *pU);

#ifdef __cplusplus
}
#endif

#endif


