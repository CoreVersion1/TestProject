#ifndef __MOUSE_H__
#define __MOUSE_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UART_API_HAVE_AP_MOUSE_PAA5102
#include "paa5102_ap_mouse.h"
#endif

struct mouse_dev_t {
    int dev_fd;
    int data_fd;
    int stop;
    pthread_t pthread_fd;
    struct rua_fifo fifo;
    void *data;
};

#define AP_LIGHT_MOUSE_LOGE  UART_API_LOGE_TS
#define AP_LIGHT_MOUSE_LOGD  UART_API_LOGD_TS
#define AP_LIGHT_MOUSE_LOGN  UART_API_LOGN_TS
#define AP_LIGHT_MOUSE_LOGI  UART_API_LOGI_TS

typedef int (* func_light_mouse_init)(void);
typedef void (* func_light_mouse_uninit)(void);
typedef int (* func_light_mouse_get_pkgs)(char *buf, int max_read);
typedef void (* func_light_mouse_switch)(int enable);
typedef int (* func_light_mouse_set_lightsrc)(int enable_led);

extern func_light_mouse_init cb_light_mouse_init;
extern func_light_mouse_uninit cb_light_mouse_uninit;
extern func_light_mouse_get_pkgs cb_light_mouse_get_pkgs;
extern func_light_mouse_switch cb_light_mouse_switch;
extern func_light_mouse_set_lightsrc cb_light_mouse_set_lightsrc;

int ap_light_mouse_init(void);
void ap_light_mouse_uninit(void);
int ap_light_mouse_get_pkgs(char *buf, int max_read);
void ap_light_mouse_switch(int enable);
int ap_light_mouse_set_light_src(int enable_led);
int set_mouse_gpio(unsigned int gpio, unsigned int value);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __MOUSE_H__ */