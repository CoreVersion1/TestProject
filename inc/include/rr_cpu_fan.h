/* =============================================================================
#     FileName: rr_cpu_fan.h
#         Desc: none
#       Author: wanchaojie
#        Email: wanchaojie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.01
#   LastChange: 2024-11-05 09:34:56
#      History: none
============================================================================= */
#ifndef _RR_CPU_FAN_H__
#define _RR_CPU_FAN_H__

#ifdef RR_DRV_HW_CPU_FAN

#ifdef __cplusplus
extern "C" {
#endif

extern int rr_get_cpu_thermal(float *bigcore, float *littlecore);
extern int rr_set_cpu_fan(int onoff, unsigned int pwm);

#ifdef __cplusplus
}
#endif

#endif

#endif