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

#ifndef __RPMSG_MCU_DEV_H__
#define __RPMSG_MCU_DEV_H__

#ifdef UART_API_HAVE_SIGMASTAR_RPMSG
#define     RPMSG_MCU_CTRL_DEV              "/dev/rpmsg_ctrl0"
#else
#define     RPMSG_MCU_CTRL_DEV              "/dev/rpmsg_ctrl-e907_rproc@1a00000"
#endif
#define     RPMSG_MCU_EPT_TX                "rr_rpmsg_mcu_tx"
#define     RPMSG_MCU_EPT_RX                "rr_rpmsg_mcu_rx"
#define     RPMSG_MCU_MMAP_DEVICE           "/dev/rpmsg_mcu"
#define     RPMSG_MCU_LOCK_EPT              1

#define RPMSG_UART_IOCTL    0x59
#define RPMSG_UART_IOCTL_SET_BUFFSER_SIZE _IOW(RPMSG_UART_IOCTL, 0x10, int)
#define RPMSG_UART_IOCTL_SET_DATA_TIMEOUT _IOW(RPMSG_UART_IOCTL, 0x11, int)

#ifdef __cplusplus
extern "C" {
#endif

extern int init_rpmsg(void);
extern void close_rpmsg(void);
extern int sent_raw_rpmsg(const char *buf, int len);
extern int get_raw_rpmsg(char *buf, int max_lengh);
extern void clean_rpmsg(void);
extern int is_rpmsg_ept_inited(void);
extern void set_wait_package_timeout_ms_rpmsg(ReadTimeOut_e E_timeout);
extern void clean_mmap_cache_rpmsg(void);
extern int isRpmsgMcuMmapBufferFull(void);

#ifdef __cplusplus
}
#endif

#endif
