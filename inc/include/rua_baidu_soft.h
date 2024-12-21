#ifndef RUA_BAIDU_SOFT_H
#define RUA_BAIDU_SOFT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RR_DRV_SW_MIC
extern int get_sw_mic_language_name(char *language_name);
extern int get_dsp_version_for_ap(char *fw_version, int len);
extern int rua_authentication_baidu_encrypt_chip(void);
extern int rua_get_sw_mic_baidu_soft_filepath(char *file_path);
#endif

#ifdef __cplusplus
}
#endif

#endif
