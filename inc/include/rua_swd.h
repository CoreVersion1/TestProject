/* =============================================================================
#     FileName: rua_swd_main.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2021-03-18 15:36:05
#      History: none
============================================================================= */
#ifndef __RUA_SWD_H__
#define __RUA_SWD_H__
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    RUA_SWD_TYPE_MCU    = 0,
    RUA_SWD_TYPE_CARPET,
    RUA_SWD_TYPE_NUM,
}
RuaSwdType_E;

extern int rua_swd_read_chip_info(RuaSwdType_E eType, ChipInfo_st *pCI);
extern int rua_swd_flash_binary(char *pathname, int force, RuaSwdType_E eType);
extern int rua_swd_flash_multi_binary(char *pathname, int force,
                                      RuaSwdType_E eType, int upgradeType);


#ifdef __cplusplus
}
#endif
#endif

