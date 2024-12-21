
#ifndef __RR_WIFI_MULT_CONF_H__
#define __RR_WIFI_MULT_CONF_H__

#ifdef __cplusplus
extern "C"
{
#endif
/*
* The format of wifi_mult.conf:
*   [section]
*   key = key_value
*   for example:
*  [wifi_ap1]
*  ssid = roborock
*  psk = 12341234
*  [wifi_ap1_gbk]
*  ssid = roborock_gbk
*  psk = 12341234
*  NOTE: SSID saved as escape string;
*  PSK saved as unescape string compatible with wifi_mult_conf.sh
*/

#define WIFI_MULT_CONF_GBK_CODE          (1)
#define WIFI_MULT_CONF_UTF8_CODE         (0)

#define WIFI_MULT_CONF_AP_MAX_NUM        (5)
#define WIFI_MULT_CONF_PRIORITY_MAX_NUM  (5)
#define WIFI_MULT_CONF_FILE_NAME         "/mnt/data/miio/wifi_mult.conf"
#define WIFI_WPA_CONF_FILE_PATH          "/mnt/data/wlan/wpa_supplicant.conf"
#define WIFI_MULT_CONF_INFO_SECTION      "information"
#define WIFI_MULT_CONF_AP_SECTION_HEAD   "wifi_ap"
#define WIFI_MULT_FAST_CONN_FILE         "/tmp/wifi_fast_conn"
#define WIFI_MULT_FAST_CONN_FILE_GBK     "/tmp/wifi_fast_conn.gbk"
#define WIFI_MULT_WPA_PSK_TMP_FILE       "/tmp/wifi_wpa_psk"
#define WIFI_CONF_FILE                   "/mnt/data/miio/wifi.conf"

enum {
    WIFI_MULT_CONF_EKY_AP_NUM = 0,
    WIFI_MULT_CONF_EKY_SSID,
    WIFI_MULT_CONF_KEY_PSK,
    WIFI_MULT_CONF_KEY_PRIORITY,
    WIFI_MULT_CONF_KEY_FASTCON_TIME,
    WIFI_MULT_CONF_KEY_LASTCON_TIME,

    //add  above
    WIFI_MULT_CONF_KEY_MAX,
};

typedef enum _WIFI_MULT_CONF_ACTION {
    WIFI_MULT_CONF_ACTION_ADD = 1,
    WIFI_MULT_CONF_ACTION_UPD,
    WIFI_MULT_CONF_ACTION_DEL,
    WIFI_MULT_CONF_ACTION_MAX,
} WIFI_MULT_CONF_ACTION;


typedef struct _wifi_ap_info_s {
    char ssid[SSID_MAX_LEN];
    char psk[PSK_MAX_LEN];
} wifi_ap_info_s;

typedef struct _wifi_prio_id_map_s {
    int priority;
    int section_id;
} wifi_prio_id_map_s;

typedef struct _wifi_ssid_s {
    int id;// 4 bytes
    char ssid[SSID_MAX_LEN];//128 bytes
} wifi_ssid_s;

typedef struct _wifi_ssid_list_s {
    int total_num;// 4 bytes
    wifi_ssid_s list[WIFI_MULT_CONF_AP_MAX_NUM];// 5*132
} wifi_ssid_list_s;

int is_wifi_config_present(void);
int wifi_mult_conf_init(void);
void wifi_mult_conf_deinit(void);
int wifi_mult_conf_read_config_file(const char *filename, wifi_config_s *cfg);
int wifi_mult_conf_write_config_file(wifi_config_s *cfg, const char *filename);
int wifi_mult_conf_get_ap_info(const char *filename, wifi_ap_info_s *ap_info);
int wifi_mult_conf_add_network(wifi_ap_info_s *ap_info);
int wifi_mult_conf_upd_network(const char *ssid);
int wifi_mult_conf_del_network(int id);
int wifi_mult_conf_get_retry_conn_ap_info(wifi_ap_info_s *retry_ap_info);
int wifi_mult_check_retry_conn_done(void);
int wifi_mult_conf_restore_retry_conn(int recover_flag);
int wifi_mult_conf_get_ssid_list(wifi_ssid_list_s *slist);
int wifi_mult_conf_get_ap_num_ex(void);
#ifdef __cplusplus
}
#endif
#endif//__RR_WIFI_MULT_CONF_H__
