/* =============================================================================
#     FileName: error_code.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-08-10 13:21:57
#      History:
============================================================================= */
#ifndef __COMMON_MCU_H__
#define __COMMON_MCU_H__


//#define USE_RR_LOG

//#define NDEBUG
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <linux/serial.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__GNUC__) && __GNUC__ >= 7
#define UART_API_FALLTHROUGH __attribute__ ((fallthrough))
#else
#define UART_API_FALLTHROUGH
#endif /* __GNUC__ >= 7 */

#ifndef likely
#define likely(x)  __builtin_expect(!!(x), 1)
#endif
#ifndef unlikely
#define unlikely(x)    __builtin_expect(!!(x), 0)
#endif

typedef enum  {
    MCU_SYNCED_TS_INVALID = 0, //do not change
    MCU_SYNCED_TS_RELOAD,
    MCU_SYNCED_TS_OK,
}
McuSyncedTs_State_e;

enum rua_error_define {
    ERR_AP_OK = 0,

    ERR_UNKNOWN                  = -1,
    ERR_NO_INIT                  = -2,
    ERR_TTY_SET                  = -3,
    ERR_TTY_OPEN                 = -4,
    ERR_MMAP                     = -5,
    ERR_WRITE                    = -7,
    ERR_TIME_OUT                 = -8,
    ERR_LOST_DATA                = -10,
    ERR_PACKAGE_NOT_FOUND        = -16,
    ERR_NO_SPACE                 = -17,
    ERR_NO_DATA                  = -18,
    ERR_CANT_GET                 = -19,
    ERR_VERSION_COMPATIBLE       = -20,
    ERR_VERSION_IMCOMPATIBLE     = -21,
    ERR_MCU_IN_UPGREADE_MODE     = -22,
    ERR_OPEN                     = -24,
    ERR_AGAIN                    = -25,
    ERR_READ                     = -26,
    ERR_ALLOC                    = -27,
    ERR_FILE                     = -28,
    ERR_IOCTL                    = -30,
    ERR_INIT                     = -31,
    ERR_BUSY                     = -32,
    ERR_VERIFY                   = -33,
    ERR_UNSUPPORT                = -56,
    ERR_RECOVERY                 = -94,
    ERR_FOUND_LOG                = -99,
    ERROR_END                    = -100,
};

typedef enum {
    RUA_UART_MCU = 0x0,
    RUA_UART_LDS,
#if defined(UART_API_HAVE_CARPET)
    RUA_UART_CARPET,
#endif
#if defined(UART_API_HAVE_LINE_LASER_MODULE)
    RUA_UART_LINE_LASER,
#endif
#if defined(RR_DRV_HW_VLINE_WALL_SENSOR)
    RUA_UART_WALL_SENSOR,
#endif
#if defined(RR_DRV_SW_DOCK_UART)
    RUA_UART_DOCK,
#endif
#ifdef UART_API_HAVE_AP_WEIGHT
    RUA_UART_WEIGHT,
#endif
    RUA_UART_NUMS,
} RuaUartDevice_e;

#define JIFFIES_IOCTL_ENABLE_PERIOD_TS   _IOW('J', 0x01, unsigned char)

typedef enum {
    RR_TS_INVALID_TYPE = 0,
    RR_TS_MASTER,
    RR_TS_SLAVE,
} RuaAPType_e;

typedef struct {
    unsigned int mcu_corrected_ts;
    unsigned int mcu_align_ms_by_irq;
    unsigned int premcu_align_ms_by_irq;
    unsigned int mcu_ts_rpt_from_uart;
    unsigned int mcu_align_unit; //default 1024 (ms)
    McuSyncedTs_State_e mcu_ts_state;
    //below for debug
    unsigned int adjust_catch_up_offset;
    unsigned int adjust_move_back_offset;
} mcu_synced_ts_st;

typedef struct {
    unsigned int gpio_irq_from_uart_nums;
    unsigned int gpio_irq_align_nums;
    unsigned int gpio_irq_nums;
    unsigned int ts_rpt_from_uart_record;
    unsigned int pre_align_by_irq_nums;
} mcu_ts_debug_st;

typedef struct {
    mcu_synced_ts_st ts_data;
    mcu_ts_debug_st ts_debug;
} mcu_ts_data_st;

typedef struct {
    unsigned int open_ts;
    unsigned int uart_device_id;
    char        tty_name[16];
    struct serial_icounter_struct open_icount;
    struct serial_icounter_struct cur_icount;
    unsigned int kern_rcv_bytes;
    unsigned int kern_throw_bytes;
    unsigned int usr_clean_times;
    unsigned int usr_clean_bytes;
    unsigned int usr_write_bytes;
    unsigned int usr_read_timeout_times;
    unsigned int usr_read_bytes;
    unsigned int usr_throw_bytes;
    unsigned int usr_parse_frames;
    unsigned int usr_parse_err_decoder;
    unsigned int usr_parse_err_crc;
} rua_uart_info_st;

extern unsigned int rua_ms_now();
extern uint64_t rua_us_now();
extern unsigned int rua_mcu_ms_now();
extern void rua_set_mcu_rpt_ms(unsigned int mcu_rpt_ms);
extern McuSyncedTs_State_e rua_mcu_ts_state();
extern int rua_get_mcu_ts_offset();
extern int rua_mcu_ts_adjust_time(unsigned int *catch_up_offset,
                                  unsigned int *move_back_offset);

#if defined (UART_API_HAVE_AP_TOP_DTOF)
extern int read_top_dtof_mmap_buffer(char *buf, int max_size);
#endif

extern int uart_api_print_level; //unused now, just for app not crash

extern const char *rua_errno2str(int);
extern void rua_dump_print_hex(int print_level, const char *data, int len,
                               const char *help);

extern void rua_uart_dbg_info_add_parse_err_crc(RuaUartDevice_e eUT);
extern void rua_uart_dbg_info_add_parse_err_decoder(RuaUartDevice_e eUT);
extern void rua_uart_dbg_info_add_parse_frames(RuaUartDevice_e eUT);
extern void rua_uart_dbg_info_add_read_timeout_times(RuaUartDevice_e eUT);
extern void rua_uart_dbg_info_add_throw_bytes(RuaUartDevice_e eUT, int bytes);
extern void rua_uart_dbg_info_add_read_bytes(RuaUartDevice_e eUT, int bytes);
extern void rua_uart_dbg_info_add_write_bytes(RuaUartDevice_e eUT, int bytes);
extern void rua_uart_dbg_info_add_clean_time_and_bytes(RuaUartDevice_e eUT,
        int bytes);
extern int rua_uart_dbg_info_read(RuaUartDevice_e eUT, rua_uart_info_st *pst);
extern void rua_uart_dbg_info_init(RuaUartDevice_e eUT);
extern int rua_uart_dbg_info_name2id(const char *ttyname);
extern void rua_uart_dbg_info_dump(RuaUartDevice_e eUT);

// read cpu id
extern int KI0a197ohEo5WkG(char *buf, int max_size);
extern int KI0a197ohEo5WkN(char *buf, int max_size);

extern int rua_ts_debug_data(mcu_ts_data_st *st_tran_data, int timeout_ms);
extern int rua_enable_period_ts(bool u8Enable);
extern int rua_is_ts_uart_inited();
extern int rua_ts_uart_init();
extern int rua_ts_uart_get_raw(char *buf, int max_lengh, int timeout_ms);
extern int rua_ts_uart_sent_raw(const char *buf, int len);
extern void rua_ts_uart_clean();
extern void rua_ts_uart_close();

extern int has_no_mcu();
extern int rua_mcu_get_rpt_ts_ms(unsigned int *rpt_ts_ms, int timeout_ms);

#ifdef __cplusplus
}
#endif
#endif /*__UART_API_H__*/

