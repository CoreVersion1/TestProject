/* =============================================================================
#     FileName: wifi_hal.c
#     Desc: Support wifi dongle device config and Store wifi connected info
#     Author: hezhifeng
#     Email: hezhifeng@roborock.com
#     HomePage: https://www.roborock.com
#     Version: 0.0.1
#     LastChange: 2021-02-15
#     History: N/A
============================================================================= */
#ifndef __RR_WIFI_STA_MANAGER_H__
#define __RR_WIFI_STA_MANAGER_H__
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _wifi_stamgr_s {
    wifi_ap_info_s ap_info;
    int start_udhdpc;
} wifi_stamgr_s;

#define WPA_LOG_PATH  "/var/log/syslog"
int wifi_sta_start_udhcpc(void);
int wifi_sta_start(wifi_stamgr_s *ap_info);
//-1:fail, 0:ok
int wifi_sta_wait_wpa_connect(void);
#ifdef __cplusplus
}
#endif

#endif  //__RR_WIFI_STA_MANAGER_H__

