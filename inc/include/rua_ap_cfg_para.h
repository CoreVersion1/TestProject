/* =============================================================================
#     FileName: rua_ap_cfg_para.h
#         Desc: none
#       Author: lzy
#        Email: laizhangyong@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2022-11-24 14:33:30
#      History: none
============================================================================= */

#ifndef __RUA_AP_CFG_PARA_H__
#define __RUA_AP_CFG_PARA_H__

#ifdef UART_API_HAVE_CFG_PARAM_DEBUG

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    E_TYPE_CFG_INVALID = 0,
    E_TYPE_CFG_MCU,
    E_TYPE_CFG_AP,
}
TypeCfg_e;

typedef struct ap_cfg_para_case {
    TypeCfg_e type;
    unsigned short element_id;
    int value;
} ap_cfg_para_case_st;


extern int rua_ap_init_para(void);
extern int rua_ap_set_para(void);

#ifdef __cplusplus
}
#endif

#endif

#endif

