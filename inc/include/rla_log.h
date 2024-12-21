/* =============================================================================
#     FileName: rla_log.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2021-05-11 14:36:12
#      History: none
============================================================================= */
#ifndef __RLA_LOG_H__
#define __RLA_LOG_H__

#include "rda_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <syslog.h>
#include <pthread.h>

extern void pthread_mutex_unlock_no_warn(void *lock);

typedef enum {
    LOG_LEVEL_NONE = -1,
    LOG_LEVEL_F_RAW = 0,    /* force print without format */
    LOG_LEVEL_F,            /* force print with format    */
    LOG_LEVEL_C,            /* critical conditions        */
    LOG_LEVEL_E,            /* error conditions           */
    LOG_LEVEL_W,            /* warning conditions         */
    LOG_LEVEL_N,            /* normal but significant condition */
    LOG_LEVEL_I,            /* informational              */
    LOG_LEVEL_D,            /* debug-level messages       */
    LOG_LEVEL_S,            /* debug-level 2, for print uart raw data */
    LOG_LEVEL_NUMS,
} rla_log_level_e;

#define LOG_LEVEL_NONE   LOG_LEVEL_F_RAW
#define LOG_LEVEL_ALL    LOG_LEVEL_D

typedef enum {
    RLA_LOG_STYLE_NONE        = 0,      /* application text */
    RLA_LOG_STYLE_DATETIMEMS  = 0x1 << 0, /* YYYY-MM-DD hh:mm:ss.6ms */
    RLA_LOG_STYLE_JIFFIES     = 0x1 << 1, /* [%u] */
    RLA_LOG_STYLE_LOGLEVEL    = 0x1 << 2, /* log level <D/I/N> */
    RLA_LOG_STYLE_PID         = 0x1 << 3, /* pid %u */
    RLA_LOG_STYLE_FUNC_LINE   = 0x1 << 4, /* %s:%d */
    RLA_LOG_STYLE_COLOR       = 0x1 << 5, /* %s:%d */
} rla_log_style_e;

#define RLA_LOG_STD_STYLES_DEFAULT   (RLA_LOG_STYLE_PID|RLA_LOG_STYLE_LOGLEVEL|RLA_LOG_STYLE_JIFFIES)
#define RLA_LOG_FILE_STYLES_DEFAULT  (RLA_LOG_STD_STYLES_DEFAULT|RLA_LOG_STYLE_DATETIMEMS|RLA_LOG_STYLE_FUNC_LINE)

struct rla_log_st;
typedef struct rla_log_st rla_log_st;
extern rla_log_st *ps_rla_log;

extern int  rla_std_dup_file(void);
extern void rla_std_dup_fileno_init(void);
extern void rla_std_disable_for_background(void);
extern int  rla_std_printf(const char *fmt, ...);

extern int  rla_log_init(rla_log_st **ppg, const unsigned int log_level,
                         const char *filename);
extern void rla_log_exit(rla_log_st **g);

extern int  rla_log_set_to_file(rla_log_st *g, const char *log_pathfilename);
extern int  rla_log_set_styles(rla_log_st *g, const int log_styles);
extern int  rla_log_get_styles(rla_log_st *g);
extern int  rla_log_set_rotate(rla_log_st *g, const int rotate_size,
                               const int maxcount);
extern int  rla_log_level_set(rla_log_st *g, const unsigned int log_level);
extern int rla_mcu_log_level_get(void);
extern int  rla_log_level_get(rla_log_st *g);
extern int  rla_log_is_to_std(rla_log_st *g);
extern int rla_log_get_fd(rla_log_st *g);

extern int  rla_log_write(rla_log_st *g, const unsigned int log_level,
                          const char *func,
                          const unsigned int line, const char *fmt, ...);

//Please call rua_dump_print_hex, not rla_log_dump_hex directy
extern void rla_log_dump_hex(rla_log_st *g, const unsigned int log_level,
                             const char *data, const int len);
extern void rla_log_libuart_api_set_level(rla_log_level_e level);


typedef enum {
    TRACE_AUDIO = 0,   /* 0x001 */
    TRACE_CAMERA,
    TRACE_FLASH,
    TRACE_LOG,
    TRACE_MOTOR,       /* 0x010 */
    TRACE_SWD,
    TRACE_UART_API,
    TRACE_VERIFY,
    TRACE_CARPET,      /* 0x100 */
    TRACE_DOCK,
    TRACE_WIFI,
    TRACE_LED,
    TRACE_AP_MOTOR,
    TRACE_VIDAR,
    TRACE_RPMSG,
    TRACE_TOF,
    TRACE_MAX,
} Rla_Log_Trace;

extern unsigned int rla_log_trace_mask;
extern rla_log_level_e rla_log_level[TRACE_MAX];

#define LOG_UART_TEST_STD_FILE   UART_API_LOG_DIR"/drivers_uart_test_std.log"
#define UART_API_LOG_FILE UART_API_LOG_DIR"/drivers_uart_api.log"
#define RLA_LOG_TRACING  ((rla_log_trace_mask & (1 << TRACE_TAG)) != 0)
#define RLA_LOG_LEVEL   (rla_log_level[TRACE_TAG])

#ifdef UART_API_SAVE_LOG_FOR_DEBUG
#define LOG_LEVEL_DEFAULT LOG_LEVEL_W
#define UART_API_LOG_LEVEL_DEFAULT  LOG_LEVEL_DEFAULT
#else
#define LOG_LEVEL_DEFAULT LOG_LEVEL_C
#define UART_API_LOG_LEVEL_DEFAULT  LOG_LEVEL_ALL
//#define RLA_LOG_TRACING  1
#endif

#ifdef LIBUART_API_BUILD
#define rua_dump_print_hex(level, data, len, fmt, args...)  \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= level) {                                                  \
            if (data == NULL || len <= 0) {                 \
                break;                                      \
            }                                               \
            rla_log_write(ps_rla_log, level, __func__,__LINE__, "<dump>:size=%d " fmt"\n" ,len, ##args);    \
            rla_log_dump_hex(ps_rla_log, level, data, len); \
        }                                                   \
    } while (0)
#define ASSERT_LOG(fmt,args...)                             \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_C) {                                                  \
            rla_log_write(ps_rla_log, LOG_LEVEL_C, __func__, __LINE__, "should never reach here:" fmt ,##args); \
        }                                                   \
    } while (0)
#define UART_API_LOGF(fmt,args...)                          \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_F_RAW) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_F_RAW, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGHELP_TS(fmt,args...)                    \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_F) {                                  \
            rla_log_write(ps_rla_log, LOG_LEVEL_F, __func__, __LINE__, "<HELP>" fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGCTRL_TS(fmt,args...)                    \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_F) {                                  \
            rla_log_write(ps_rla_log, LOG_LEVEL_F, __func__, __LINE__, "<CTRL>" fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGSWITCH_TS(fmt,args...)                  \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_F) {                                 \
            rla_log_write(ps_rla_log, LOG_LEVEL_F, __func__, __LINE__, "<DEV>" fmt, ##args);   \
        }                                                   \
    } while (0)

#define UART_API_LOGC_TS(fmt,args...)                       \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_C) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_C, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGE_TS(fmt,args...)                       \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_E) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_E, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGW_TS(fmt,args...)                       \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_W) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_W, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGN_TS(fmt,args...)                       \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_N) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_N, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGI_TS(fmt,args...)                       \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_I) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_I, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGD_TS(fmt,args...)                       \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_D) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_D, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#define UART_API_LOGS_TS(fmt,args...)                       \
    do {                                                    \
        if (RLA_LOG_TRACING && RLA_LOG_LEVEL >= LOG_LEVEL_S) {                         \
            rla_log_write(ps_rla_log, LOG_LEVEL_S, __func__, __LINE__, fmt, ##args);   \
        }                                                   \
    } while (0)
#else
#define rua_dump_print_hex(level, data, len, fmt, args...)  \
    do {                                                    \
        if (data == NULL || len <= 0) {                 \
            break;                                      \
        }                                               \
        rla_log_write(ps_rla_log, level, __func__,__LINE__, "<dump>:size=%d " fmt"\n" ,len, ##args);    \
        rla_log_dump_hex(ps_rla_log, level, data, len); \
    } while (0)
#define ASSERT_LOG(fmt,args...)                             \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_C, __func__, __LINE__, "should never reach here:" fmt ,##args); \
    } while (0)
#define UART_API_LOGF(fmt,args...)                          \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_F_RAW, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#define UART_API_LOGHELP_TS(fmt,args...)                    \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_F, __func__, __LINE__, "<HELP>" fmt, ##args);   \
    } while (0)
#define UART_API_LOGCTRL_TS(fmt,args...)                    \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_F, __func__, __LINE__, "<CTRL>" fmt, ##args);   \
    } while (0)
#define UART_API_LOGSWITCH_TS(fmt,args...)                  \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_F, __func__, __LINE__, "<DEV>" fmt, ##args);   \
    } while (0)

#define UART_API_LOGC_TS(fmt,args...)                       \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_C, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#define UART_API_LOGE_TS(fmt,args...)                       \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_E, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#define UART_API_LOGW_TS(fmt,args...)                       \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_W, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#define UART_API_LOGN_TS(fmt,args...)                       \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_N, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#define UART_API_LOGI_TS(fmt,args...)                       \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_I, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#define UART_API_LOGD_TS(fmt,args...)                       \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_D, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#define UART_API_LOGS_TS(fmt,args...)                       \
    do {                                                    \
        rla_log_write(ps_rla_log, LOG_LEVEL_S, __func__, __LINE__, fmt, ##args);   \
    } while (0)
#endif


#define UART_API_LOGC UART_API_LOGC_TS
#define UART_API_LOGE UART_API_LOGE_TS
#define UART_API_LOGW UART_API_LOGW_TS
#define UART_API_LOGN UART_API_LOGN_TS
#define UART_API_LOGI UART_API_LOGI_TS
#define UART_API_LOGD UART_API_LOGD_TS
#define UART_API_LOGS UART_API_LOGS_TS

#define UART_TEST_LOGFILE_SIZE      (1024*1024)

#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif /* __RLA_LOG_H__ */

