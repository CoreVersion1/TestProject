/* =============================================================================
#     FileName: rda_rtc_api.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2024-09-27 17:01:44
#      History: none
============================================================================= */
#ifndef __RDA_RTC_API_H__
#define __RDA_RTC_API_H__

#include "rda_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(RR_DRV_SW_HAVE_ONLY_RISCV)
#include <time.h>
#include <sys/time.h>

extern int rda_rtc_set_utc_time(time_t set_time);
extern int rda_rtc_get_utc_time(time_t *get_time);

#define get_mcu_time rda_rtc_get_utc_time
#define set_mcu_time rda_rtc_set_utc_time
#define get_utc rda_rtc_get_utc_time
#define set_utc rda_rtc_set_utc_time
#endif /* RR_DRV_SW_HAVE_ONLY_RISCV */

#if defined(__cplusplus)
}  /* extern "C" */
#endif


#endif /* __RDA_RTC_API_H__ */

