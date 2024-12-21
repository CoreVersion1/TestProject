/* =============================================================================
#     FileName: data_parse.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-04-21 18:37:24
#      History:
============================================================================= */
#ifndef __MCU_COMMUNICATION_H__
#define __MCU_COMMUNICATION_H__

#include <time.h>
#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * librrafm.so depends:
 * int  init_uart(void);
 * void close_uart(void);
 * int  check_version(struct fw_info*);
 * int  sent_basic_cmd(unsigned char, int, const void*);
 * int  get_package(unsigned char*,int);
 * int  get_next(unsigned char**, int*, unsigned char**, int*);
 * int  get_external_data(char*, int, void*);
 */

#ifdef RR_DRV_SW_MUTI_CORE_COMM
#define READ_WAIT_TIME 10
#else
#define READ_WAIT_TIME 23
#endif

#define REQUEST_MAX_NUMS 5
extern char volatile need_ack_buf[REQUEST_MAX_NUMS];
static inline void deal_answer(unsigned char index)
{
    int i;

    for (i = 0; i < REQUEST_MAX_NUMS; i++) {
        if (need_ack_buf[i] == index) {
            need_ack_buf[i] = 0;
        }
    }

    return;
}
static inline int is_answered(unsigned char index)
{
    int i;

    for (i = 0; i < REQUEST_MAX_NUMS; i++) {
        if (need_ack_buf[i] == index) {
            return 0;
        }
    }

    return 1;
}
static inline int set_request(unsigned char index)
{
    int i;

    for (i = 0; i < REQUEST_MAX_NUMS; i++) {
        if (!need_ack_buf[i]) {
            need_ack_buf[i] = index;
            return 0;
        }
    }

    return ERR_NO_SPACE;
}
extern int  get_package(char *buf, int max_lengh);
extern void deal_answer(unsigned char index);
extern void cal_time_offset(unsigned long long mcu_ts_ms);
extern int  check_version(FwInfo_st *fw_info);
extern int  sent_basic_package(const char *buffer, int len);
extern int  sent_cmd(eRptPkgId_e ID, unsigned int struct_size, const void *addr,
                     int need_ack);
extern int  sent_basic_cmd(eRptPkgId_e ID, unsigned int struct_size,
                           const void *addr);
extern int  sent_answer(unsigned char index);
#ifdef RR_DRV_SW_MUTI_CORE_COMM
extern int  sent_internal_mcu_answer(unsigned char index);
#endif
extern int  sent_package(const char *buffer, int len, int need_ack);
extern int  check_mcu_mode();
extern int  get_pn(Sn_st *stSN);
extern int  get_testinfo(TestInfoV1_st *stTestInfo);
#if ! defined(RR_DRV_SW_HAVE_ONLY_RISCV)
extern int  get_mcu_time(time_t *mcu_time);
extern int  set_mcu_time(time_t mcu_time);
extern int  get_utc(time_t *mcu_time); //old
extern int  set_utc(time_t mcu_time);  //old
#endif
extern time_t utc2mcutime(time_t utc);
extern time_t mcutime2utc(time_t mcutime);
extern int get_external_data(char *data, int len, void *pReserved);
extern int check_mcu_error(Err_st *mcu_err);
extern int disable_mcu_heartbeat();
extern int rua_keep_mcu_heartbeat(unsigned int timeout_seconds);
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
#if defined(UART_API_HAVE_TESTINFO_V2)
extern int rua_stationinfo_has_mt2(TestInfoV1_st *puInfo);
extern int rua_stationinfo_has_tedc(TestInfoV1_st *puInfo);
extern int rua_stationinfo_app_write(TestInfoV1_st *puInfo,
                                     TestV1Station_e estation, unsigned int result);
#endif
extern int get_data_from_mcu(void *data, int len, eRptPkgId_e cmd,
                             void *cmddata, int cmd_len, eRptPkgId_e request);
extern int rua_set_mcu_cfginfo(CfgInfo_st *stInfo);
extern int rua_get_mcu_cfginfo(CfgInfo_st *stInfo);
extern int rua_update_mcu_log_level();

int deal_log_data(char *log_start, int log_size, char *dest);
#ifdef __cplusplus
}
#endif
#endif

