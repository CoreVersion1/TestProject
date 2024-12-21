/* =============================================================================
#     FileName: wifi_hal.h
#     Desc: wifi hardware adapter layer header file
#     Author: hezhifeng
#     Email: hezhifeng@roborock.com
#     HomePage: https://www.roborock.com
#     Version: 0.0.1
#     LastChange: 2022-02-25
#     History: N/A
============================================================================= */
#ifndef _RR_WIFI_HAL_H
#define _RR_WIFI_HAL_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define WIFI_HAL_DRV_ARG_MAX_LEN  (512)
#define WIFI_HAL_DEV_NAME_MAX_LEN (64)
#define WIFI_HAL_DRV_NAME_MAX_LEN (64)
#define WIFI_HAL_DEV_VID_PID_LEN  (16)
#define WIFI_IFNAME_LEN           (8)

/*
 * Defines for wifi_wait_for_driver_ready()
 * Specify durations between polls and max wait time
 */
#define POLL_DRIVER_DURATION_US (100000)
#define POLL_DRIVER_MAX_TIME_MS (10000)

#define WIFI_HWINFO_FILE "/proc/rockrobo/hwinfo"

#define AP_CONFLICT_DEFAULT_IP          "192.168.0.1"
#define AP_CONFLICT_DEFAULT_IP2          "192.168.1.1"

enum {
    WIFI_DEV_ID_ATBM6132BU = 0,
    WIFI_DEV_ID_RTW8189FS,
    WIFI_DEV_ID_SSV6X5X,
    WIFI_DEV_ID_HISI3881,
    WIFI_DEV_ID_RTW8189ES,
    WIFI_DEV_ID_BL602,
    WIFI_DEV_ID_RTL8723CS,
    WIFI_DEV_ID_AIC8800,
    WIFI_DEV_ID_RTL8733BS,
    WIFI_DEV_ID_MAX,
};

enum {
    EXTRA_DEV_ID_8723_HCI_UART = 0,
    EXTRA_DEV_ID_AIC8800_FDRV,
    EXTRA_DEV_ID_MAX,
};

enum {
    WIFI_MODE_STA = 0,
    WIFI_MODE_AP,
    WIFI_MODE_P2P,
    //add  above
    WIFI_MODE_MAX,
};

enum {
    WIFI_IF_STATUS_DOWN = 0,
    WIFI_IF_STATUS_UP = 1,
    WIFI_IF_STATUS_ERR = -1,
};

typedef struct _wifi_device {
    char wifi_name[WIFI_HAL_DEV_NAME_MAX_LEN];//64 bytes
    char wifi_vid_pid[WIFI_HAL_DEV_VID_PID_LEN];//16 bytes
} wifi_device;

typedef struct _wifi_driver {
    char wifi_module_name[WIFI_HAL_DEV_NAME_MAX_LEN];//64 bytes
    char wifi_drv_name[WIFI_HAL_DRV_NAME_MAX_LEN];//64 bytes
    char wifi_drv_cfg_name[WIFI_HAL_DRV_NAME_MAX_LEN];//64 bytes
} wifi_driver;

typedef struct _wifi_load_info {
    char wifi_module_name[WIFI_HAL_DEV_NAME_MAX_LEN];//64 bytes
    int  wifi_dev_id;
    int  is_wifi_nic_identify;
    int  wifi_mode;
} wifi_load_info;


/**
 * Load the Wi-Fi driver.
 *
 * @return 0 on success, < 0 on failure.
 */
int wifi_hal_load_driver(const int dev_id);


/**
 * Unload the Wi-Fi driver.
 *
 * @return 0 on success, < 0 on failure.
 */
int wifi_hal_unload_driver(const char *module_name);

/**
 * Check if the Wi-Fi driver is loaded.
 * Check if the Wi-Fi driver is loaded.

 * @return 0 on success, < 0 on failure.
 */
int is_wifi_driver_loaded(const char *module_name);
/**
 * Get the Wi-Fi mode.
 *
 * @return WIFI_MODE_STA/WIFI_MODE_AP.
 */

int wifi_hal_get_mode(void);
/**
 * Install wifi modules.
 *
 * @return NA .
 */
void wifi_hal_install_all_modules(void);
/**
 * uninstall wifi modules.
 *
 * @return -1:failure, 0:success .
 */
int wifi_hal_uninstall_all_modules(void);
/**
 * Get mac addr by socket
 *
 * @Input ifname(wlan0/ap0), mac_len
 * @Ouput: mac
 * @return -1:failure, 0:success .
 */
int wifi_hal_get_mac_by_socket(const char *ifname, unsigned char *mac,
                               int mac_len);
/**
 * Set Interface up/down
 *
 * @ Input ifname(wlan0/ap0)
 * @return -1:failure, 0:success .
 */
int wifi_hal_ifconfig_up(const char *ifname);
int wifi_hal_ifconfig_down(const char *ifname);
/**
 * Get Interface up/down status
 *
 * @Input ifname(wlan0/ap0)
 * @return -1:error, 1:up, 0 down
 */
int wifi_hal_get_if_status(const char *ifname);
/**
 * Wait Interface up,  times out after 5 seconds
 *
 * @Input ifname(wlan0/ap0)
 * @return -1:error, 1:up, 0 down
 */
int wifi_hal_wait_for_interface_up(const char *ifname);

/**
 * Get/Set ip addr
 *
 * @Input ifname(wlan0/ap0)
 * @return -1:failure, 0:success .
 */
int wifi_hal_set_ip(const char *ifname, const char *ip);
int wifi_hal_get_ip(const char *ifname, char *ip, int ip_len);

/**
 * Get/Set ip netmask
 *
 * @Input ifname(wlan0/ap0)
 * @return -1:failure, 0:success .
 */
int wifi_hal_get_netmask(const char *ifname, char *netmask, int netmask_len);

/**
 * HAL adatper init/deinit
 *
 * @Input WIFI_MODE_STA/WIFI_MODE_AP.
 * @return -1:failure, 0:success .
 */
int wifi_hal_init(int mode);
int wifi_hal_deinit(void);

int wifi_ble_hal_init();

/**
 * HAL ap/sta adatper stop
 *
 * @Input WIFI_MODE_STA/WIFI_MODE_AP.
 * @return -1:failure, 0:success .
 */
int wifi_hal_ap_stop(void);
int wifi_hal_sta_stop(void);

/**
 * Get ap/sta if name
 *
 * @Input  ifname/ifname len
 * @return -1:failure, 0:success .
 */
int wifi_get_ap_ifname(char *ifname, int ifname_len);
int wifi_get_sta_ifname(char *ifname, int ifname_len);

/**
 * Get wifi channel by frequency
 *
 * @Input  frequency:2407-2844
 * @return channel  1-14.
 */
int wifi_hal_freq_to_channel(int freq);

/**
 * Get wifi is/not support dual interface exist at same time
 *
 * @return 0-not support, 1-support
 */
int wifi_is_support_dual_iface(void);

/**
 * Get wifi dongle is/not support AP's channel follow STA's
 *
 * @return 0-not support, 1-support
 */
int wifi_is_support_channel_following(void);

/**
 * Get wifi is/not support dock pair
 *
 * @return 0-not support, 1-support
 */
int wifi_is_support_dock_pair(void);

int wifi_load_extra_driver(const int dev_id);

/// @brief modify driver log level for debug
/// @retval 0 modify success
int wifi_change_log_level();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* _RR_WIFI_HAL_H */
