/* =============================================================================
#     FileName: rda_ap_led.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2021-04-20 19:48:21
#      History: none
============================================================================= */

#ifndef __RDA_AP_LED_H__
#define __RDA_AP_LED_H__

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum {
    RDA_AP_LED_ID_WIFI = 0,
    RDA_AP_LED_ID_MIC,
    RDA_AP_LED_ID_GENERAL0,
    RDA_AP_LED_ID_GENERAL1,
    RDA_AP_LED_ID_GENERAL2,
    RDA_AP_LED_ID_GENERAL3,
    RDA_AP_LED_ID_EMER,
    RDA_AP_LED_ID_ARM,
    RDA_AP_LED_ID_MAX,
}
rda_ap_led_id_e;

typedef enum {
    RDA_AP_LED_STATE_OFF = 0,
    RDA_AP_LED_STATE_ON,
    RDA_AP_LED_STATE_BLINK_FLOW,
    RDA_AP_LED_STATE_BLINK_QUIK,
    RDA_AP_LED_STATE_BLINK_DOUBLE,
#ifdef UART_API_HAVE_NEW_LED_DIRVER
    RDA_AP_LED_STATE_BREATH,
#endif
    RDA_AP_FLOWLED_STATUS_1_1,
    RDA_AP_FLOWLED_STATUS_1_2,
    RDA_AP_FLOWLED_STATUS_2_1,
    RDA_AP_FLOWLED_STATUS_2_2,
    RDA_AP_FLOWLED_STATUS_3_1,
    RDA_AP_FLOWLED_STATUS_3_2,
    RDA_AP_LED_STATE_MAX
} rda_ap_led_state_e;

/**
 * @brief  open led dev
 */
int rda_ap_led_init(void);
/**
 * @brief  release led dev
 */
void rda_ap_led_exit(void);
/**
 * @brief  Set LED lighting effects
 * @param  [id] RDA_AP_LED_ID_WIFI or RDA_AP_LED_ID_MIC etc.
 * @param  [st] RDA_MIC_LED_STATE_OFF or RDA_MIC_LED_STATE_ON etc.
 * @return [int] 0 when success and negative number when fail
 */
int rda_set_ap_led_effect(rda_ap_led_id_e id, rda_ap_led_state_e st);

/*Only for 527 platform use*/
#ifdef UART_API_HAVE_NEW_LED_DIRVER

/**
 * @brief  set max brightness for lighting effect
 * @param  [id] RDA_AP_LED_ID_WIFI or RDA_AP_LED_ID_MIC etc.
 * @param  [brightness] range in 0 ~ 255
 * @return [int] Returns the number of bytes written when success and negative number when fail
 */
int rda_set_ap_led_brightness(rda_ap_led_id_e id, unsigned char brightness);

/**
 * @brief  Set the granularity of the brightness change of the breathing light effect
 * @param  [id] RDA_AP_LED_ID_WIFI or RDA_AP_LED_ID_MIC etc.
 * @param  [interval] range in 1 ~ 255
 * @return [int] Returns the number of bytes written when success and negative number when fail
 */
int rda_set_ap_led_breath_brightness_interval(rda_ap_led_id_e id,
        unsigned char interval);

#endif

/**
 * @brief  Get the maximum brightness of the current lighting effect
 * @param  [id] RDA_AP_LED_ID_WIFI or RDA_AP_LED_ID_MIC etc.
 * @param  [*brightness] range in 1 ~ 255
 * @return [int] 0 when success and negative number when fail
 */
int rda_get_ap_led_brightness(rda_ap_led_id_e id, unsigned char *brightness);

/**
 * @brief  Set the special lighting effect repeat times
 * @param  [id] RDA_AP_LED_ID_WIFI or RDA_AP_LED_ID_MIC etc.
 * @param  [*brightness] range in 0 ~ 255 ; 0(default) & 255 equal forever
 * @return [int] 0 when success and negative number when fail
 */
int rda_set_ap_led_special_lighting_cycle(rda_ap_led_id_e id,
        unsigned char cycles);

#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif