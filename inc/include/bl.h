#ifndef __BL_H__
#define __BL_H__

#ifdef __cplusplus
extern "C" {
#endif

#define BOOTLOADER_FLAG_STRINGS_MAX_LENGTH    32

typedef struct bl_rrmisc_flag {
    char misc_magic[BOOTLOADER_FLAG_STRINGS_MAX_LENGTH];
    char quiet_upgrade;
    char audio_en;
    char audio_vol;
    unsigned char led_brightness;
    unsigned char led_breath_interval;
    unsigned char led_effect;
    char reserve[13];
} bl_rrmisc_flag_t;

typedef struct bl_baidu_dsp_type_flag {
    int valid_flag;
    int voice_id;
    char type[16];
} bl_baidu_dsp_type_flag_t;

extern int rr_read_bootloader_flag(char *partition, int flag_offset,
                                   char *valuep, int size);
extern int rr_write_bootloader_flag(char *partition, int flag_offset,
                                    char *valuep, int size);
extern int bl_get_quiet_upgrade_status(void);
extern int bl_set_quiet_upgrade(int en);
extern int bl_set_recovery_audio(int en);
extern int bl_get_midnight_reset_status(void);
extern int bl_set_midnight_reset(int en);

/**
 * @brief  Save LED brightness information before shutdown to flash
 * @param  [brightness] birightness LED before shutdown.
 * @return [int] 0 when success and negative number when fail
 */
extern int bl_set_led_brightness(unsigned char brightness);
/**
 * @brief  Save LED information about breathing lighting effects before shutdown to flash
 * @param  [breath_interval]Interval of led breath effect before shutdown.
            Don't need to set it if effect is not breath!
 * @return [int] 0 when success and negative number when fail
 */
extern int bl_set_led_breath_interval(unsigned char breath_interval);
/**
 * @brief  Save LED working mode information before shutdown to flash
 * @param  [effect] LED working mode before shutdown.
           RDA_MIC_LED_STATE_OFF or RDA_MIC_LED_STATE_ON etc.
 * @return [int] 0 when success and negative number when fail
 */
extern int bl_set_led_effect(unsigned char effect);

#ifdef __cplusplus
}
#endif
#endif
