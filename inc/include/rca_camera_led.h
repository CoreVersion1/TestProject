/* =============================================================================
#     FileName: rca_camera_led.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2020-08-30 16:06:41
#      History: none
============================================================================= */
#ifndef __RCA_CAMERA_LED_H__
#define __RCA_CAMERA_LED_H__


#ifdef UART_API_HAVE_CAMERA
#if defined(UART_API_HAVE_CAMERA_LED) || defined(UART_API_HAVE_CAMERA_LED_2)

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(UART_API_HAVE_CAMERA_LED_AW)
#include "rca_camera/rca_camera_led_2.h"
#endif

typedef enum {
    RCL_IR          = 0x1,
    RCL_LINE_L      = 0x1 << 1,
    RCL_LINE_R      = 0x1 << 2,
    RCL_LINE_M      = 0x1 << 3,
    RCL_LINE_T      = 0x1 << 4,
}
rca_camera_led_e;

typedef enum {
    RCL_OFF         = 0x0,
    RCL_ON          = 0x1,
    RCL_AUTO        = 0x2,
} rca_camera_led_mode_e;

extern int rca_camera_led_init();
extern int rca_camera_led_switch(int on);
extern int rca_camera_led_ctrl(rca_camera_led_e type, rca_camera_led_mode_e on);
extern int rca_camera_led_set_duty(rca_camera_led_e type, unsigned int duty);
extern int rca_camera_led_get_duty(rca_camera_led_e type, unsigned int *duty);
extern void rca_camera_led_exit();
extern int rca_camera_led_set_debug_log(int on);
extern int rca_camera_led_set_test_mode(int on);

#ifdef __cplusplus
}
#endif

#endif
#endif
#endif
