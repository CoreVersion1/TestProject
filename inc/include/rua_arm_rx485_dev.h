/* =============================================================================
#     FileName: rua_arm_rx485_dev.h
#         Desc: serial port arm rx485 device
#       Author: yanbaoguang
#        Email: yanbaoguang@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#               2024-09-20
============================================================================= */

#ifndef __RUA_ARM_RX485_DEV_H__
#define __RUA_ARM_RX485_DEV_H__

#ifdef __cplusplus
extern "C" {
#endif

extern int init_arm_rx485_uart();
extern void close_arm_rx485_uart();

extern int rua_arm_rx485_sent_raw(char *buffer, int len);
extern int rua_arm_rx485_get_raw(char *buffer, int max_lengh, int timeout_ms);
extern void rua_arm_rx485_clean_uart();
extern int is_arm_rx485_inited();
extern int isArm485MmapBufferFull(void);
extern uint16_t rua_arm_rx485_CRC_cal(uint16_t len, char *rxbuff);

#ifdef __cplusplus
}
#endif

#endif
