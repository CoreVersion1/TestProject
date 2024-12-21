#ifndef __DTOF_DEV_H__
#define __DTOF_DEV_H__

#include <asm-generic/int-ll64.h>
#include <bits/stdint-uintn.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TOP_DTOF_MAX_NUMS 8

typedef enum MODULE_SUPPLIER_NUMBER {
    TOP_DTOF_1_SNUM = 0,
    TOP_DTOF_2_SNUM,
    TOP_DTOF_SUPPLIER_SUM,
} Module_SNUM_e;

typedef enum MODULE_SUPPLIER_TYPE {
    TOP_DTOF_TYPE_INVALID_MIN = 0,
    TOP_DTOF_1_VI530X,
    TOP_DTOF_2_DA0301B1,
    TOP_DTOF_TYPE_INVALID_MAX,
} Module_TYPE_e;

typedef struct top_dtof_xtalk_calib_data {
    int32_t s32XtalkPos;
    int32_t s32XtalkPeak;
    int32_t s32XtalkMaxrThr;
} TXC_data_st;

typedef struct top_dtof_offset_calib_data {
    int32_t s32OffsetCal;
    uint32_t u32OffsetPeak;
    uint32_t u32OffsetNoise;
    uint32_t u32OffsetIntegralTimes;
} TOC_data_st;

typedef struct all_calib_data {
    TXC_data_st stGXCData;
    TXC_data_st stSXCData;
    TOC_data_st stGOCData;
    TOC_data_st stSOCData;
    uint64_t u64TopDtofID;
    Module_TYPE_e eType;
} ALL_calib_data_st;

typedef struct top_dtof_Data {
    uint64_t   u64TimeUSec;
    uint32_t   u32Noise;
    uint32_t   u32Peak1;
    uint32_t   u32Peak2;
    uint32_t   u32PeakR1;
    uint32_t   u32PeakR2;
    int32_t    s32MaxRatioRT;
    uint32_t   u32IntegralTimes;
    uint16_t   u16XtalkCount;
    int16_t    s16Distance1;
    int16_t    s16Distance2;
    uint8_t    u32Confidence1;
    uint8_t    u32Confidence2;
    uint8_t    u8Num;
    uint8_t    u8Mode;        /*mixed mode: (0x55: general, 0xAA: short) */
    uint8_t    u8Status1;
    uint8_t    u8Status2;
} Top_dtof_st;

typedef enum TOP_DTOF_WORK_MODE {
    GENERAL_MODE = 0,
    SHORT_RANGE_MODE,
} Work_mode_e;

typedef enum VI530X_FIRMWARE_TYPE {
    VI530X_INVALID_FW_TYPE = 0,
    VI530X_GENERAL_MODE_FW,
    VI530X_SHORT_MODE_FW,
    VI530X_MIXED_MODE_FW,
    VI530X_AUTO_MODE_FW,
    VI530X_MULTI_MODE_FW,
} Firmware_type_e;

typedef enum VI530X_DTOF_NAME {
#if defined(RR_DRV_SW_HAVE_AP_DTOF_CLIFF)
    TOP_DTOF_LR = 0,
    TOP_DTOF_RR,
#elif defined(RR_DRV_SW_HAVE_AP_TOP_DTOF_4)
    TOP_DTOF_LR = 0,
    TOP_DTOF_LF,
    TOP_DTOF_RF,
    TOP_DTOF_RR,
#else
    TOP_DTOF_DEFAULT = 0,
#endif
    TOP_DTOF_NUMS,
} Dtof_name_e;

typedef void (*cb_no_parm_1)(void);
typedef int (*cb_no_parm_2)(void);
typedef int (*cb_1_parm_1)(Work_mode_e);
typedef int (*cb_1_parm_2)(Dtof_name_e);
typedef void (*cb_1_parm_3)(Dtof_name_e);
typedef int (*cb_2_parm_1)(Work_mode_e *, Dtof_name_e);
typedef int (*cb_2_parm_2)(Work_mode_e, Dtof_name_e);
typedef int (*cb_2_parm_3)(Firmware_type_e *, Dtof_name_e);
typedef int (*cb_2_parm_4)(Firmware_type_e, Dtof_name_e);
typedef int (*cb_2_parm_5)(ALL_calib_data_st *, Dtof_name_e);
typedef int (*cb_3_parm_1)(TXC_data_st *, Work_mode_e, Dtof_name_e);
typedef int (*cb_3_parm_2)(uint32_t *, uint32_t, Dtof_name_e);
typedef int (*cb_4_parm_1)(TOC_data_st *, Work_mode_e, Dtof_name_e, uint32_t);

typedef struct top_dtof_device {
    const char     *name;            //necessary
    cb_no_parm_2   nums;             //necessary
    cb_no_parm_2   is_exist;         //necessary
    cb_2_parm_2    init_one;         //necessary
    cb_1_parm_3    exit_one;         //necessary
    cb_1_parm_1    init_all;         //necessary
    cb_no_parm_1   exit_all;         //necessary
    cb_3_parm_1    xtalk_calib;      //necessary
    cb_4_parm_1    offset_calib;     //necessary
    cb_2_parm_5    get_calib_data;   //necessary

    cb_2_parm_3    get_fw_type;      //optional
    cb_2_parm_4    set_fw_type;      //optional
    cb_2_parm_1    get_work_mode;    //optional
    cb_2_parm_2    set_work_mode;    //optional
    cb_1_parm_2    data_err_reason;  //optional
    cb_3_parm_2    get_sn_id;        //optional
    const Module_TYPE_e type;        //necessary
} Top_dtof_dev_st;

#define RR_DTOF_IOCTL_START_CAPTURE    _IO('r', 0x01)
#define RR_DTOF_IOCTL_STOP_CAPTURE     _IO('r', 0x02)
#define RR_DTOF_IOCTL_SET_SINGLE_CAPTURE _IOW('r', 0x03, uint8_t)

extern uint8_t top_dtof_nums(void);
extern const char *top_dtof_name(void);
extern Module_TYPE_e top_dtof_type(void);
extern int top_dtof_init(Work_mode_e eWorkMode);
extern void top_dtof_exit(void);
extern int top_dtof_init_one(Work_mode_e eWorkMode, Dtof_name_e idtof);
extern void top_dtof_exit_one(Dtof_name_e idtof);
extern int top_dtof_xtalk_calibration(TXC_data_st *calib_data,
                                      Dtof_name_e idtof,
                                      Work_mode_e eWorkMode);
extern int top_dtof_offset_calibration(TOC_data_st *calib_data,
                                       Dtof_name_e idtof,
                                       Work_mode_e eWorkMode, uint32_t u32Distance);
extern int top_dtof_get_calibration_data(ALL_calib_data_st *pstACData,
        Dtof_name_e idtof);
extern int top_dtof_get_work_mode(Work_mode_e *eWorkMode, Dtof_name_e idtof);

/*
 * return value:
 * 1) negative number: err
 * 2) 0: success
 * 3) 1: the setting mode is the same as the current mode
 */
extern int top_dtof_switch_work_mode(Work_mode_e eWorkMode, Dtof_name_e idtof);
extern int top_dtof_get_firmware_type(Firmware_type_e *eFirmwareType,
                                      Dtof_name_e idtof,
                                      Module_SNUM_e *eMSNUM);
extern int top_dtof_set_firmware_type(Firmware_type_e eFirmwareType,
                                      Dtof_name_e idtof);

/*
 * return value:
 * 1) 0: success
 * 2) ERR_TIME_OUT(-8): read timeout, read agin
 * 3) ERR_NO_INIT(-2): reset by accident锛宔xit device锛宨nit agin
 * 4) other negative number: may be other hardware errors
*/
extern int top_dtof_get_all_data(Top_dtof_st *all_data, unsigned int max_read);
extern int top_dtof_get_one_data(Top_dtof_st *all_data, unsigned int max_read,
                                 Dtof_name_e idtof);

extern int top_dtof_get_sn_id(unsigned int *sn_id, unsigned int max_read,
                              Dtof_name_e idtof);
extern int top_dtof_single_capture(Dtof_name_e idtof);

extern int sysfs_node_write_value(char const *file, const char *value);
extern int sysfs_node_read_value(char const *file, char *value,
                                 unsigned int size);
extern int sysfs_node_write_entry(char const *file, int value);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __DTOF_DEV_H__ */
