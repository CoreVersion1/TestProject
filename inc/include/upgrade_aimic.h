#ifndef UPGRADE_AIMIC_H
#define UPGRADE_AIMIC_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UART_API_HAVE_BAIDU_MIC
#define AIMIC_OTA_BIN "/usr/lib/baidu/firmware/b.bin"
#define ATMIC_SLAVE_LOAD_BIN_PATH "/opt/rockrobo/firmware/"
#define ATMIC_SLAVE_LOAD_BIN ATMIC_SLAVE_LOAD_BIN_PATH"baidu_dsp_prc.bin"

typedef struct dsp_info {
    char dsp_spi_dev_name[256];    //name of dsp spi device node
    unsigned int fw_spi_speed;
    unsigned int reset_gpio_num;                    //reset hh2 gpio num.
    unsigned int boot_gpio_num;
} dsp_info;
struct load_aimic_result {
    int  status;
    int language_is_support_aimic;   // 0 不支持， 1 支持。
};
enum load_aimic_status {
    Load_aimic_ok,
    Loading_aimic,
    Load_aimic_fail,
};
#define AIMIC_LOAD_READY "/tmp/load_aimic_ok"

extern int get_aimic_upgrade_filename(char *file_name);
extern int upgrade_aimic_if_not_match(const char *file_name);
extern int read_aimic_dsp_version(void);
extern int reset_aimic_dsp(void);
extern int get_dsp_info_from_json(dsp_info *p_data);
extern int load_dsp_bin(const char *file_name);
extern int get_dsp_version_for_ap(char *fw_version, int len);
extern int get_language_name(char *language_name);
#endif

#ifdef __cplusplus
}
#endif

#endif
