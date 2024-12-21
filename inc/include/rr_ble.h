#ifndef _RR_BLE_H
#define _RR_BLE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

int hci0_up(void);
int hci0_down(void);

int create_dbus_conn(void);

int create_dbus_client(void);

int create_mainloop_thread(void);

void system_alias(const char *new_name);

//0-off, 1-on
int advertise(int cmd);
void advertise_name(const char *name);
int register_service(char *uuid);
int register_characteristic(char *uuid, char *flags);
int register_app(char *uuid);
void power(int cmd);

/// @brief enable dbus and bluetoothd
/// @return 0 is success, otherwise failure
/// @note This function must be executed before enable_ble()
int enable_bluetoothd();

/// @brief enable bluetooth
/// @return 0 is success, otherwise failure
int enable_ble();

/// @brief disable bluetooth
/// @return 0 is success, otherwise failure
int disable_ble();

// void ad_advertise_manufacturer();

// void ad_advertise_local_name(const char *name);

// void ad_advertise_uuids(char **uuids);

// int ad_register();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* _RR_BLE_H */