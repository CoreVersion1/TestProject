/* =============================================================================
#     FileName: dock communication.h
#         Desc:
#       Author: yanbaoguang
#        Email: yanbaoguang@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2025-05-21
#      History:
============================================================================= */
#ifndef __DOCK_COMMUNICATION_H__
#define __DOCK_COMMUNICATION_H__

#include <time.h>
#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int  dock_get_package(char *buf, int max_lengh);
extern void dock_deal_answer(unsigned char index);
extern void cal_time_offset(unsigned long long mcu_ts_ms);
extern int  dock_check_version(FwInfo_st
                               *fw_info); //TODO: check dock version too large
extern int  dock_sent_basic_package(const char *buffer, int len);
extern int  dock_sent_cmd(eRptDockPkgId_e ID, unsigned int struct_size,
                          const void *addr,
                          int need_ack);
extern int  dock_sent_basic_cmd(eRptDockPkgId_e ID, unsigned int struct_size,
                                const void *addr);
extern int  dock_sent_package(const char *buffer, int len, int need_ack);
extern int  check_dock_mode();
extern int  dock_get_pn(Sn_st *stSN);
extern int dock_send_reset(void);
#if 0
extern int  dock_sent_answer(unsigned char index);
extern int  get_mcu_time(time_t *mcu_time);
extern int  set_mcu_time(time_t mcu_time);
extern time_t utc2mcutime(time_t utc);
extern time_t mcutime2utc(time_t mcutime);
extern int check_mcu_error(Err_st *mcu_err);

extern int rua_read_cpuid(char *cpuid_str, int buf_size);
extern int rua_read_flashid(char *id_str, int buf_size);
extern int rua_stationinfo_clear(TestInfoV1_st *stInfo, int station);
extern int rua_stationinfo_get(TestInfoV1_st *stInfo, int station,
                               unsigned char *result);
extern int rua_stationinfo_set(TestInfoV1_st *stInfo, unsigned int station,
                               unsigned int result);
extern int rua_stationinfo_header_to_str(TestInfoV1_st *stInfo, char *str,
        int max_size);
extern int rua_stationinfo_data_to_str(TestInfoV1_st *stInfo, char *str,
                                       int max_size);
extern int rua_stationinfo_new_ver(TestInfoV1_st *stInfo);
extern int rua_stationinfo_header_invalid(TestInfoHeaer_st *stHeader);
extern int rua_stationinfo_pre_not_passed(TestInfoV1_st *stInfo,
        TestStation_e station);
extern int rua_stationinfo_to_black_box_str(TestInfoV1_st *stInfo, char *str,
        int max_size);
extern int rua_stationinfo_has_cooker(TestInfoV1_st *stInfo);
extern int rua_set_mcu_cfginfo(CfgInfo_st *stInfo);
extern int rua_get_mcu_cfginfo(CfgInfo_st *stInfo);
extern int rua_update_dock_log_level();
#endif
extern int get_data_from_dock(void *data, int len, eRptDockPkgId_e cmd,
                              void *cmddata, int cmd_len, eRptDockPkgId_e request);
extern int get_data_from_dock_no_block(void *data, int len, eRptDockPkgId_e cmd,
                       void *cmddata, int cmd_len, eRptDockPkgId_e request);
#ifdef __cplusplus
}
#endif
#endif

