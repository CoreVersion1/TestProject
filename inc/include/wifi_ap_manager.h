/* =============================================================================
#     FileName: wifi_hal.c
#     Desc: Support wifi dongle device config and Store wifi connected info
#     Author: hezhifeng
#     Email: hezhifeng@roborock.com
#     HomePage: https://www.roborock.com
#     Version: 0.0.1
#     LastChange: 2021-02-10
#     History: N/A
============================================================================= */
#ifndef __RR_WIFI_AP_MANAGER_H__
#define __RR_WIFI_AP_MANAGER_H__
#ifdef __cplusplus
extern "C"
{
#endif
#define HOSTAPD_CONF  "/tmp/hostapd.conf"
#define DNSMASQ_CONF  "/tmp/dnsmasq.conf"

#define AP_MAX_SSID_LEN     32    /* max length of AP's ssid */
#define AP_MAX_PSSWD_LEN    64    /* max length of password */
#define MIN_CHAN            1
#define MAX_CHAN            14
#define BEACON_INT_MAX      1000
#define BEACON_INT_MIN      33
#define DEFAULT_BEACON_INT  100
#define DEFAULT_CHANNEL     6

typedef struct _ip_range_s {
    unsigned int begin;
    unsigned int end;
} ip_range_s;

typedef struct _wifi_ap_mgr_s {
    char   ssid[AP_MAX_SSID_LEN + 1];    /* network's SSID */
    char   psswd[AP_MAX_PSSWD_LEN + 1];  /* network's password, if not OPEN mode */
    short  bw_bandwidth;                 /* set bandwidth, ie.BW20/40 */
    short  beacon_int;                   /* Beacon interval in kus (1.024 ms) (default: 100; range 15..65535) */
    short  channel;                      /* network's channel, usually 1/6/11 */
    short  hw_mode;                      /* set Operation mode, 11b/g/n */
    int    hidden_ssid;                  /* whether network hiddens it's SSID, default 0 */
    unsigned int if_addr;
    ip_range_s dhcp_range;
} wifi_ap_mgr_s;

int wifi_ap_start(wifi_ap_mgr_s *ap_cfg);

/*Add Extern APIs following */
extern int wifi_sta_get_connect_channel(void);
int wifi_ap_generate_essid(char *essid, size_t len);
int wifi_ap_open_connection(void);
void wifi_ap_close_connection(void);
int wifi_ap_check_if_status(void);
int wifi_ap_check_dnsmasq(void);
int wifi_ap_check_hostapd_connect(void);
int wifi_ap_check_status(void);
int wifi_ap_send_hostapd_cmd(char const *cmd, char *reply, size_t reply_len);
int wifi_ap_get_hidden_ssid_cfg(int *hidden_ssid);
int wifi_ap_start_hidden_mode(void);
int wifi_ap_check_ip_conflict(void);
int wifi_ap_check_sta_ip_conflict(void);
int wifi_ap_set_start_ip(void* ap_cfg,uint8_t is_next);
int wifi_ap_check_hostapd_enable(void);
#ifdef __cplusplus
}
#endif
#endif  //_RR_WIFI_AP_MANAGER_H