
/* =============================================================================
#     FileName: wifi_adapter.h
#     Desc: Start wifi dongle ap or sta adatper
#     Author: hezhifeng
#     Email: hezhifeng@roborock.com
#     HomePage: https://www.roborock.com
#     Version: 0.0.1
#     LastChange: 2021-02-25
#     History: N/A
============================================================================= */
#ifndef __RR_WIFI_ADAPTER_H__
#define __RR_WIFI_ADAPTER_H__
#ifdef __cplusplus
extern "C"
{
#endif
typedef enum _wifi_adapter_mode_e {
    WIFI_ADAPTER_MODE_AP   = 0,
    WIFI_ADAPTER_MODE_STA  = 1,
    WIFI_ADAPTER_MODE_STOP = 2,
    WIFI_ADAPTER_MODE_MAX
} wifi_adapter_mode;

int wifi_adapter_ap_start(void *ap_cfg);
int wifi_adapter_ap_stop(void);
int wifi_adapter_sta_start(void *sta_info);
int wifi_adapter_sta_stop(void);
int wifi_adapter_connect_ap(char *ssid, char *psk);
int wifi_adapter_stop(void);
int wifi_adapter_retry_conn(void);
//1:regenerate wpa conf, -1:error, 0--normal(not regenerate wpa conf)
int wifi_adapter_upd_lastconn_time(const char *ssid);
int wifi_adapter_restore_retry_conn(int recover_flag);
int wifi_adapter_start(int mode, void *arg);
void wifi_adatper_destory(void);
int wifi_adapter_get_running_flag(int mode);
int wifi_adapter_set_running_flag(int mode, int val);
int wifi_adapter_set_disable_ap_flag(int val);
int wifi_adapter_get_disable_ap_flag(void);
int wifi_adatper_clear_running_flag(void);
int wifi_adapter_check_ip_conflict(void);

void wifi_adapter_set_adbd_flag_on();
void wifi_adapter_set_adbd_flag_off();

#ifdef __cplusplus
}
#endif
#endif  //__RR_WIFI_ADAPTER_H__

