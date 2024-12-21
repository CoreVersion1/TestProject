/* *****************************************************************************
#     FileName: data_parse.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-04-21 18:37:24
#      History:
***************************************************************************** */
#ifndef __DATA_PARSE_H__
#define __DATA_PARSE_H__

#include <time.h>

typedef unsigned short rua_id_t;
typedef unsigned char  rua_st_t;
typedef unsigned char  rua_crc8_t;
typedef unsigned short rua_crc16_t;
typedef int            rua_err_t;
typedef unsigned char  rua_size_t;
typedef unsigned short tracking_data_id_t;

// package data structure (cancel data coding and decoding)
#ifdef UART_API_HAVE_AP_COMM_CRC8
// HEADER(1B) + size(1B, data size) + header crc(1B, crc(HEADER + size)) + data(size B) + crc(1B)
#else
// HEADER(1B) + size(1B, data size) + header crc(1B, crc(HEADER + size)) + data(size B) + crc(2B)
#endif
#define HEADER                 0xAA
#define HEADER_SIZE            1
#define PACKAGE_MAX_SIZE       128
#define LOG_END_CHAR           '^'

#define LENGTH_SIZE            sizeof(rua_size_t)
#define HEADER_CRC_SIZE        sizeof(rua_crc8_t)
#define STRUCT_LEN_SIZE        sizeof(rua_st_t)
#define ID_SIZE                sizeof(rua_id_t)
#ifdef UART_API_HAVE_AP_COMM_CRC8
#define CRC_SIZE               sizeof(rua_crc8_t)
#else
#define CRC_SIZE               sizeof(rua_crc16_t)
#endif
#define HEADER_TOP_SIZE        (HEADER_SIZE+LENGTH_SIZE+HEADER_CRC_SIZE)
#define PACKAGE_MIN_SIZE       (HEADER_TOP_SIZE+ID_SIZE+STRUCT_LEN_SIZE+CRC_SIZE)
#define SRC_MIN_SIZE           (ID_SIZE+STRUCT_LEN_SIZE)
#define BUFFER_SIZE            ((PACKAGE_MAX_SIZE+HEADER_TOP_SIZE+CRC_SIZE)<<1)

#define UART_API_ID_RESERVE    0xff
#define UART_API_ID_BASE       (UART_API_ID_PROJECT_BASE + UART_API_ID_RESERVE)

/** the old cmd will be delete later **/
typedef enum {
    PACKAGE_START_ID                                   = 0x00, //NC

    COMM_PKGINDEXITEM_ID                               = 0x01,
    COMM_ANSWER_ID                                     = 0x02,
    COMM_SYS_MODE_ID                                   = 0x03,
    COMM_TS_ID                                         = 0x04,
    COMM_HEART_BEAT_ID                                 = 0x05,
    COMM_BOOT_VER_ID                                   = 0x06,
    COMM_CHIP_INFO_ID                                  = 0x07,
    COMM_FW_INFO_ID                                    = 0x08,
    COMM_DEV_INFO_ID                                   = 0x09,
    CMD_SET_RESET_ID                                   = 0x0A,
    UPGRADE_ID                                         = 0x0B,
    SPECIAL_FACTORY_ID                                 = 0x0C,
    RPT_LOG_ID                                         = 0x0D,
    RPT_LOG_TS_ID                                      = 0x0E,

    SPECIAL_LOG_ID                                     = 0x0F, //only for old build, never used
    SPECIAL_LOG_WITH_TS_ID                             = 0x10, //only for old build, never used
    SPECIAL_LOG_SAVE_ID                                = RPT_LOG_ID,
    SPECIAL_LOG_SAVE_WITH_TS_ID                        = RPT_LOG_TS_ID,

    CMD_GET_FW_INFO_ID                                 = COMM_FW_INFO_ID,
    RPT_FW_INFO_ID                                     = COMM_FW_INFO_ID,
    RPT_DEV_INFO_ID                                    = COMM_DEV_INFO_ID,
    CMD_GET_DEV_INFO_ID                                = COMM_DEV_INFO_ID,
    RPT_SYS_MODE_ID                                    = COMM_SYS_MODE_ID,
    CMD_SET_SYS_MODE_ID                                = COMM_SYS_MODE_ID,

    RPT_INTERNAL_SYS_MODE_ID                           = 0x1b,
    RPT_INTERNAL_MCU_LOG_ID                            = 0x1c,
    RPT_INTERNAL_MCU_LOG_TS_ID                         = 0x1d,
    COMM_ANSWER_INTERNAL_MCU_ID                        = 0x1e,
    SPECIAL_FACTORY_INTERNAL_MCU_ID                    = 0x1f,

    RPT_SN_ID                                          = UART_API_ID_BASE,
    RPT_ERROR_ID                                       = UART_API_ID_BASE + 0x04,
    // available                                       = UART_API_ID_BASE + 0x05,
    RPT_KEY_ID                                         = UART_API_ID_BASE + 0x06,
    RPT_GYRO_ODO_ID                                    = UART_API_ID_BASE + 0x07,
    RPT_BATTERY_INFO_ID                                = UART_API_ID_BASE + 0x08,
    RPT_SWITCH_ENABLED_MASK_ID                         = UART_API_ID_BASE + 0x09,
    RPT_TEST_INFO_ID                                   = UART_API_ID_BASE + 0x0a,
    RPT_BLACKBOX_ID                                    = UART_API_ID_BASE + 0x0b,
    RPT_PN_ID                                          = UART_API_ID_BASE + 0x0c,
    // available                                       = UART_API_ID_BASE + 0x0d,
    RPT_RTC_ID                                         = UART_API_ID_BASE + 0x0e,
    RPT_DOCK_VOL_ID                                    = UART_API_ID_BASE + 0x0f,

    RPT_NAV_CACHE_DATA_ID                              = UART_API_ID_BASE + 0x10,
    RPT_AP_CACHE_BUFF_ID                               = UART_API_ID_BASE + 0x11,
    RPT_CHARGING_CYCLE_ID                              = UART_API_ID_BASE + 0x12,
    RPT_DOCK_IR_ID                                     = UART_API_ID_BASE + 0x13,
    RPT_MOTOR_THRESHOLD_ID                             = UART_API_ID_BASE + 0x14,
    RPT_TN_ID                                          = UART_API_ID_BASE + 0x15,
    RPT_BAT_CAP_ID                                     = UART_API_ID_BASE + 0x16,
    RPT_MOTOR_NTC_ID                                   = UART_API_ID_BASE + 0x17,
    RPT_PUMP_ID                                        = UART_API_ID_BASE + 0x18,
    RPT_GYRO_OFF_ID                                    = UART_API_ID_BASE + 0x19,
    RPT_VADPT_INFO_ID                                  = UART_API_ID_BASE + 0x1a,
    // available                                       = UART_API_ID_BASE + 0x1b,
    // available                                       = UART_API_ID_BASE + 0x1c,
    RPT_BAR_INFO_ID                                    = UART_API_ID_BASE + 0x1d,
    RPT_CLIFFVAL_ID                                    = UART_API_ID_BASE + 0x1e,
    RPT_LIGHT_MOUSE_ID                                 = UART_API_ID_BASE + 0x1f,

    RPT_STATUS_DOCK_ID                                 = UART_API_ID_BASE + 0x20,
    RPT_STATUS_BUMPER_ID                               = UART_API_ID_BASE + 0x21,
    RPT_STATUS_DROP_ID                                 = UART_API_ID_BASE + 0x22,
    RPT_STATUS_CLIFF_ID                                = UART_API_ID_BASE + 0x23,
    RPT_STATUS_DUSTIN_ID                               = UART_API_ID_BASE + 0x24,
    RPT_STATUS_LDS_BUMPER_ID                           = UART_API_ID_BASE + 0x25,
    RPT_STATUS_WATERBOX_ID                             = UART_API_ID_BASE + 0x26,
    RPT_STATUS_RAG_L_R_DET_ID                          = UART_API_ID_BASE + 0x27,
    RPT_STATUS_MOPPOS_ID                               = UART_API_ID_BASE + 0x28,
    RPT_STATUS_DOCK_IR_RX_ID                           = UART_API_ID_BASE + 0x29,
    RPT_STATUS_WATER_LEVEL_ID                          = UART_API_ID_BASE + 0x2a,
    RPT_STATUS_DOCK_BUMPER_ID                          = UART_API_ID_BASE + 0x2b,
    RPT_STATUS_STRECT_RAG_POS_ID                       = UART_API_ID_BASE + 0x2c,
    RPT_STATUS_GYRO_REINIT_ID                          = UART_API_ID_BASE + 0x2d,
    RPT_STATUS_TOP_BUMPER_ID                           = UART_API_ID_BASE + 0x2e,
    RPT_TRACKING_EVENT_ID                              = UART_API_ID_BASE + 0x2f,
    //for riscv
    RPT_REG_ITEM_ID                                    = UART_API_ID_BASE + 0x30,
    RPT_BIT_LED_MODE_ID                                = UART_API_ID_BASE + 0x31,
    /*
       available                                       = UART_API_ID_BASE + 0x32,
         .                                                          .
         .                                                          .
         .                                                          .
       available                                       = UART_API_ID_BASE + 0x3f,
    */
    CMD_SET_V_M_ID                                    = UART_API_ID_BASE + 0x37,

    RPT_RANGE_WALL_ID                                  = UART_API_ID_BASE + 0x40,
    RPT_RANGE_ULTRA_ID                                 = UART_API_ID_BASE + 0x41,
    RPT_RANGE_LIGHTTOUCH_ID                            = UART_API_ID_BASE + 0x42,
    RPT_STATUS_SWEEP_POS_ID                            = UART_API_ID_BASE + 0x43,
    RPT_STATUS_SEWAGE_TANK_ID                          = UART_API_ID_BASE + 0x44,
    RPT_STATUS_BRAKE_DET_ID                            = UART_API_ID_BASE + 0x45,
    RPT_STATUS_STRETCH_SWEEP_DET_ID                    = UART_API_ID_BASE + 0x46,
    RPT_STATUS_UNIVERSAL_WHEEL_DET_ID                  = UART_API_ID_BASE + 0x47,
    // RPT_STATUS_RAG_LIGHT_DET_ID                        = UART_API_ID_BASE + 0x48,
    RPT_STATUS_WHEEL_DOWN_DET_ID                       = UART_API_ID_BASE + 0x49,
    RPT_STATUS_SIDEMOP_DET_ID                          = UART_API_ID_BASE + 0x4A,
    RPT_STATUS_LDS_LFIT_POS_ID                         = UART_API_ID_BASE + 0x4B,
    RPT_STATUS_ARM_DOOR_POS_ID                         = UART_API_ID_BASE + 0x4C,
    RPT_STATUS_BACKUNIVERSAL_WHEEL_DET_ID              = UART_API_ID_BASE + 0x4D,
    RPT_STATUS_CLAMP_POS_ID                            = UART_API_ID_BASE + 0x4E,
    RPT_STATUS_CABINDOOR_POS_ID                        = UART_API_ID_BASE + 0x4F,

    RPT_MOTOR_FAN_INFO_ID                              = UART_API_ID_BASE + 0x50,
    RPT_MOTOR_WHEEL_INFO_ID                            = UART_API_ID_BASE + 0x51,
    RPT_MOTOR_BRUSH_INFO_ID                            = UART_API_ID_BASE + 0x52,
    RPT_MOTOR_SWEEP_INFO_ID                            = UART_API_ID_BASE + 0x53,
    RPT_MOTOR_MOP_INFO_ID                              = UART_API_ID_BASE + 0x54,
    RPT_MOTOR_SEW_INFO_ID                              = UART_API_ID_BASE + 0x55,
    RPT_STATUS_GET_CFGINFO_ID                          = UART_API_ID_BASE + 0x56,
    RPT_STATUS_GET_CARPET_DATA_ID                      = UART_API_ID_BASE + 0x57,
    RPT_STATUS_BRUSHLIFT_MOTOR_ID                      = UART_API_ID_BASE + 0x58,
    // RPT_STATUS_BRUSHLIFT_SWITCH_ID                     = UART_API_ID_BASE + 0x59,
    RPT_MOTOR_STRECH_RAG_INFO_ID                       = UART_API_ID_BASE + 0x5A,
    RPT_DOCKIR_BOOTCMD_ID                              = UART_API_ID_BASE + 0x5B,
    RPT_GYRO_BIAS_ID                                   = UART_API_ID_BASE + 0x5C,
    RPT_STATUS_STEERING_INFO_ID                        = UART_API_ID_BASE + 0x5D,
    RPT_CLIFF_TOF_ERROR_STATUS_ID                      = UART_API_ID_BASE + 0x5E,
    RPT_STEERING_CLI_ID                                = UART_API_ID_BASE + 0x5F,

    RPT_SWEEP_STRETCH_LIFT_INFO_ID                     = UART_API_ID_BASE + 0x60,
    RPT_SIDEMOP_LIFT_INFO_ID                           = UART_API_ID_BASE + 0x61,
    RPT_SIDEMOP_STRETCH_INFO_ID                        = UART_API_ID_BASE + 0x62,
    RPT_LDS_LIFT_INFO_ID                               = UART_API_ID_BASE + 0x63,
    RPT_ARM_DOOR_INFO_ID                               = UART_API_ID_BASE + 0x64,
    RPT_BACKUNIVERSAL_WHEEL_LIFT_INFO_ID               = UART_API_ID_BASE + 0x65,
    RPT_UNIVERSAL_WHEEL_LIFT_INFO_ID                   = UART_API_ID_BASE + 0x66,
    RPT_LEFT_WHEEL_LIFT_INFO_ID                        = UART_API_ID_BASE + 0x67,
    RPT_RIGHT_WHEEL_LIFT_INFO_ID                       = UART_API_ID_BASE + 0x68,
    RPT_CLAMP_INFO_ID                                  = UART_API_ID_BASE + 0x69,
    RPT_CABINDOOR_INFO_ID                              = UART_API_ID_BASE + 0x6a,
    RPT_STATUS_BAR_PRESSURE_ID                         = UART_API_ID_BASE + 0x6b,
    RPT_STATUS_BAR_TEMPERATURE_ID                      = UART_API_ID_BASE + 0x6c,
    RPT_STEERING_CLI_ANG_ID                            = UART_API_ID_BASE + 0x6d,
    RPT_STATUS_SWEEP_DOWN_POS_ID                       = UART_API_ID_BASE + 0x6e,
    RPT_STATUS_SWEEP_UP_POS_ID                         = UART_API_ID_BASE + 0x6f,
    RPT_STATUS_SPINRAG_HALL_POS_ID                     = UART_API_ID_BASE + 0x70,

    RPT_STATUS_FRONT_SWING_INFO_ID                     = UART_API_ID_BASE + 0x71,
    RPT_STATUS_BACK_SWING_INFO_ID                      = UART_API_ID_BASE + 0x72,

    RPT_STATUS_ARM_AP_EMER_ID                          = UART_API_ID_BASE + 0x73,
    RPT_STATUS_ARM_MCU_WDO_ID                          = UART_API_ID_BASE + 0x74,
    RPT_STATUS_SWING_BUMPER_ID                         = UART_API_ID_BASE + 0x75,
    RPT_STATUS_SPINRAG_HALL_STATE_ID                   = UART_API_ID_BASE + 0x76,
    RPT_STATUS_CABIN_BUMPER_ID                         = UART_API_ID_BASE + 0x77,
    RPT_STATUS_SPINRAG_REMOVE_ID                       = UART_API_ID_BASE + 0x78,
    RPT_STATUS_MCU_ARM_BUMPER_ID                       = UART_API_ID_BASE + 0x79,
    RPT_STATUS_ARM_BUMPER_ID                           = UART_API_ID_BASE + 0x7a,
    RPT_STATUS_MCU_ARM_HEARTBEAT_ID                    = UART_API_ID_BASE + 0x7b,
    /*
       available                                       = UART_API_ID_BASE + 0x77,
         .                                                          .
         .                                                          .
         .                                                          .
       available                                       = UART_API_ID_BASE + 0x7f,
    */

    /*CMD id define*/
    // available                                       = UART_API_ID_BASE + 0x80,
    CMD_GET_SYS_MODE_ID                                = UART_API_ID_BASE + 0x81,
    CMD_GET_ALL_STATUS_ID                              = UART_API_ID_BASE + 0x82,
    CMD_GET_SN_ID                                      = UART_API_ID_BASE + 0x83,
    CMD_GET_BAT_INFO_ID                                = UART_API_ID_BASE + 0x84,
    CMD_GET_SWITCH_ENABLED_MASK_ID                     = UART_API_ID_BASE + 0x85,
    CMD_GET_TEST_INFO_ID                               = UART_API_ID_BASE + 0x86,
    CMD_GET_PN_ID                                      = UART_API_ID_BASE + 0x87,
    // available                                       = UART_API_ID_BASE + 0x88,
    CMD_GET_RTC_ID                                     = UART_API_ID_BASE + 0x89,
    CMD_GET_NAV_CACHE_DATA_ID                          = UART_API_ID_BASE + 0x8a,
    CMD_GET_AP_CACHE_BUFF_ID                           = UART_API_ID_BASE + 0x8b,
    CMD_GET_ERROR_ID                                   = UART_API_ID_BASE + 0x8c,
    CMD_GET_MOTOR_THRESHOLD_ID                         = UART_API_ID_BASE + 0x8d,
    CMD_GET_TN_ID                                      = UART_API_ID_BASE + 0x8e,
    CMD_GET_BAT_CAP_ID                                 = UART_API_ID_BASE + 0x8f,

    CMD_GET_STATUS_DOCK_ID                             = UART_API_ID_BASE + 0x90,
    CMD_GET_STATUS_BUMPER_ID                           = UART_API_ID_BASE + 0x91,
    CMD_GET_STATUS_DROP_ID                             = UART_API_ID_BASE + 0x92,
    CMD_GET_STATUS_CLIFF_ID                            = UART_API_ID_BASE + 0x93,
    CMD_GET_STATUS_DUSTIN_ID                           = UART_API_ID_BASE + 0x94,
    CMD_GET_STATUS_LDS_BUMPER_ID                       = UART_API_ID_BASE + 0x95,
    CMD_GET_STATUS_WATERBOX_ID                         = UART_API_ID_BASE + 0x96,
    CMD_GET_PUMP_ID                                    = UART_API_ID_BASE + 0x97,
    CMD_GET_STATUS_STRECHPOS_ID                        = UART_API_ID_BASE + 0x98,
    CMD_GET_STATUS_MOPPOS_ID                           = UART_API_ID_BASE + 0x99,
    CMD_GET_STATUS_WATER_LEVEL_ID                      = UART_API_ID_BASE + 0x9a,
    CMD_GET_STATUS_DOCK_BUMPER_ID                      = UART_API_ID_BASE + 0x9b,
    CMD_GET_GYRO_OFFSET_ID                             = UART_API_ID_BASE + 0x9c,
    CMD_GET_SPINRAG_L_ID                               = UART_API_ID_BASE + 0x9d,
    CMD_GET_SPINRAG_R_ID                               = UART_API_ID_BASE + 0x9e,
    CMD_GET_STATUS_ARM_BUMPER_ID                       = UART_API_ID_BASE + 0x9f,

    CMD_GET_MOTOR_FAN_INFO_ID                          = UART_API_ID_BASE + 0xa0,
    CMD_GET_MOTOR_WHEEL_INFO_ID                        = UART_API_ID_BASE + 0xa1,
    CMD_GET_MOTOR_BRUSH_INFO_ID                        = UART_API_ID_BASE + 0xa2,
    CMD_GET_MOTOR_SWEEP_INFO_ID                        = UART_API_ID_BASE + 0xa3,
    CMD_GET_MOTOR_MOP_INFO_ID                          = UART_API_ID_BASE + 0xa4,
    CMD_GET_MOTOR_NTC_ID                               = UART_API_ID_BASE + 0xa5,
    CMD_GET_CFGINFO_ID                                 = UART_API_ID_BASE + 0xa6,
    CMD_GET_STATUS_BRUSHLIFTSWITCH_ID                  = UART_API_ID_BASE + 0xa7,
    CMD_GET_STATUS_SWEEP_POS_ID                        = UART_API_ID_BASE + 0xa8,
    CMD_GET_STATUS_SEWAGE_TANK_ID                      = UART_API_ID_BASE + 0xa9,
    CMD_GET_STATUS_TOP_BUMPER_ID                       = UART_API_ID_BASE + 0xaa,
    CMD_GET_VACUUMPUMP_ID                              = UART_API_ID_BASE + 0xab,
    CMD_GET_STATUS_AP_BRAKE_DET_ID                     = UART_API_ID_BASE + 0xac,
    CMD_GET_STATUS_UNIVERSAL_WHEEL_DET_ID              = UART_API_ID_BASE + 0xad,
    CMD_GET_STATUS_WHEEL_DOWN_DET_ID                   = UART_API_ID_BASE + 0xae,
    CMD_GET_STATUS_SIDEMOP_POS_ID                      = UART_API_ID_BASE + 0xaf,

    CMD_SET_DEV_BACKIR_MASK_ID                         = UART_API_ID_BASE + 0xb0,
    CMD_SET_DEV_SWITCH_ID                              = UART_API_ID_BASE + 0xb1,
    CMD_SET_MOUSE_LIGHT_SRC                            = UART_API_ID_BASE + 0xb2,
    CMD_SET_LED_MODE_ID                                = UART_API_ID_BASE + 0xb3,
    CMD_SET_ODO_CLEAN_ID                               = UART_API_ID_BASE + 0xb4,
    CMD_SENT_MAINBOARD_TEMP_ID                         = UART_API_ID_BASE + 0xb6,
    CMD_SET_CHARGE_ID                                  = UART_API_ID_BASE + 0xb7,
    CMD_SET_MOBILITY_RESULT_ID                         = UART_API_ID_BASE + 0xb8,
    CMD_SET_TEST_INFO_ID                               = CMD_SET_MOBILITY_RESULT_ID,
    CMD_SET_RTC_ID                                     = UART_API_ID_BASE + 0xb9,
    CMD_SET_PIDPARA_ID                                 = UART_API_ID_BASE + 0xba,
    CMD_SET_LED_LEVEL_ID                               = UART_API_ID_BASE + 0xbb,
    CMD_SET_NAV_CACHE_DATA_ID                          = UART_API_ID_BASE + 0xbc,
    CMD_SET_AP_CACHE_BUFF_ID                           = UART_API_ID_BASE + 0xbd,
    CMD_SET_MOTOR_THRESHOLD_ID                         = UART_API_ID_BASE + 0xbe,
    CMD_SET_WATERPUMP_ID                               = UART_API_ID_BASE + 0xbf,

    CMD_SET_MOTOR_WHEEL_SPD_ID                         = UART_API_ID_BASE + 0xc0,
    CMD_SET_MOTOR_FAN_SPD_ID                           = UART_API_ID_BASE + 0xc1,
    CMD_SET_FAN_SPD_CHECK_ID                           = UART_API_ID_BASE + 0xc2,
    CMD_SET_MOTOR_BRUSH_PARA_ID                        = UART_API_ID_BASE + 0xc3,
    CMD_SET_MOTOR_SWEEP_PARA_ID                        = UART_API_ID_BASE + 0xc4,
    CMD_SET_MOTOR_MOP_PARA_ID                          = UART_API_ID_BASE + 0xc5,
    CMD_SET_CHARGING_MODE_ID                           = UART_API_ID_BASE + 0xc6,
    CMD_SET_FLOW_LED_ID                                = UART_API_ID_BASE + 0xc7,
    CMD_SET_CARPET_STATE_ID                            = UART_API_ID_BASE + 0xc8,
    CMD_SET_MOTOR_SEW_PARA_ID                          = UART_API_ID_BASE + 0xc9,
    CMD_SET_DOCK_IR_TX_ID                              = UART_API_ID_BASE + 0xca,
    CMD_SET_MOP_SWITCH_ID                              = UART_API_ID_BASE + 0xcb,
    CMD_SET_CFGINFO_ID                                 = UART_API_ID_BASE + 0xcc,
    CMD_SET_CLEAR_PID_PARAM                            = UART_API_ID_BASE + 0xcd,
    CMD_SET_DOCK_IR_TXPART_ID                          = UART_API_ID_BASE + 0xce,
    CMD_SET_DEBUG_ID                                   = UART_API_ID_BASE + 0xcf,
    CMD_COMMON_WHEEL_SECURE_ID                         = UART_API_ID_BASE + 0xd0,
    CMD_SET_STRECH_RAG_SPD_ID                          = UART_API_ID_BASE + 0xd1,
    CMD_SET_CLIFF_RATIO_FUNC_ID                        = UART_API_ID_BASE + 0xd3,
    CMD_SET_MIDNIGHT_RESET_ID                          = UART_API_ID_BASE + 0xd4,
    COMM_CALI_INFO_ID                                  = UART_API_ID_BASE + 0xd5,
    CMD_SET_MOTOR_FAN_TYPE_ID                          = UART_API_ID_BASE + 0xd6,
    CMD_SET_BRUSHLIFT_MOTOR_ID                         = UART_API_ID_BASE + 0xd7,
    CMD_SET_BRUSHLIFT_INIT_ID                          = UART_API_ID_BASE + 0xd8,
    CMD_SET_BRUSHLIFT_UNINIT_ID                        = UART_API_ID_BASE + 0xd9,
    CMD_GET_RRDATA_SIZE                                = UART_API_ID_BASE + 0xda,
    CMD_BACKUP_RRDATA                                  = UART_API_ID_BASE + 0xdb,
    CMD_RESTORE_RRDATA                                 = UART_API_ID_BASE + 0xdc,
    CMD_BRUSHLIFT_STOP_DELAY_ID                        = UART_API_ID_BASE + 0xdd,
    CMD_SET_BAROMETER_START_ID                         = UART_API_ID_BASE + 0xde,
    CMD_SET_VACUUMPUMP_ID                              = UART_API_ID_BASE + 0xdf,
    CMD_SET_BRAKE_TIRGGER_ACTION_ENABLE_ID             = UART_API_ID_BASE + 0xe0,
    CMD_SET_BRAKE_TIRGGER_ACTION_DISABLE_ID            = UART_API_ID_BASE + 0xe1,
    CMD_SET_STEERING_PARA_ID                           = UART_API_ID_BASE + 0xe2,
    CMD_SET_MASKDROP_PARA_ID                           = UART_API_ID_BASE + 0xe3,
    CMD_GET_STEERING_CLI_DATA_ID                       = UART_API_ID_BASE + 0xe4,
    CMD_GET_STATUS_LDS_LFIT_POS_ID                     = UART_API_ID_BASE + 0xe5,
    CMD_GET_STATUS_ARM_DOOR_POS_ID                     = UART_API_ID_BASE + 0xe6,
    CMD_GET_STATUS_BACKUNIVERSAL_WHEEL_POS_ID          = UART_API_ID_BASE + 0xe7,
    CMD_GET_STATUS_CLAMP_POS_ID                        = UART_API_ID_BASE + 0xe8,
    CMD_GET_STATUS_CABINDOOR_POS_ID                    = UART_API_ID_BASE + 0xe9,
    CMD_SET_STEERING_CLI_DATA_ID                       = UART_API_ID_BASE + 0xea,
    CMD_SET_STEERING_ANGL_CALI_ID                      = UART_API_ID_BASE + 0xeb,

    CMD_SET_BIT_LED_MODE_ID                            = UART_API_ID_BASE + 0xec,
    CMD_SET_AP_MOTOR_INIT_ID                           = UART_API_ID_BASE + 0xed,
    CMD_SET_AP_MOTOR_IOCTL_ID                          = UART_API_ID_BASE + 0xee,
    CMD_SET_AP_MOTOR_UNINT_ID                          = UART_API_ID_BASE + 0xef,
    CMD_GET_AP_STATUS_STRETCH_RAG_POS_ID               = UART_API_ID_BASE + 0xf0,

    CMD_GET_STATUS_ARM_AP_EMER_ID                      = UART_API_ID_BASE + 0xf1,
    CMD_GET_STATUS_ARM_MCU_WDO_ID                      = UART_API_ID_BASE + 0xf2,
    CMD_GET_STATUS_CABINBUMPER_ID                      = UART_API_ID_BASE + 0xf3,
    CMD_SET_MOTOR_FRONT_SWING_SPD_ID                   = UART_API_ID_BASE + 0xf4,
    CMD_SET_MOTOR_BACK_SWING_SPD_ID                    = UART_API_ID_BASE + 0xf5,
    CMD_SET_IR_CODE_STATUS_ID                          = UART_API_ID_BASE + 0xf6,
    CMD_SET_CLIFF_BRAKE_ID                             = UART_API_ID_BASE + 0xf7,
    CMD_SET_BUMPER_BRAKE_ID                            = UART_API_ID_BASE + 0xf8,
    CMD_GET_MCU_ARM_BUMPER_STATUS_ID                   = UART_API_ID_BASE + 0xf9,
    CMD_SET_RAG_BOARD_INFO                             = UART_API_ID_BASE + 0xfa,
    SPECIAL_SECRET_CODE3_ID                            = UART_API_ID_BASE + 0xfb,
    SPECIAL_SECRET_CODE2_ID                            = UART_API_ID_BASE + 0xfc,
    SPECIAL_SECRET_CODE_ID                             = UART_API_ID_BASE + 0xfd,
#ifdef RR_AUTO_TEST
    RR_AT_SET_PSEUDO_ADC                               = UART_API_ID_BASE + 0xFD,
#endif
    // available                                       = UART_API_ID_BASE + 0xfe,
    // available                                       = UART_API_ID_BASE + 0xff,

    COMM_RS485_ID                                      = UART_API_ID_BASE + 0x100,


    RUA_ID_MAX_NUM,
} eRptPkgId_e;
typedef enum {
    LIFT_LDS_FAULT_DET,
    LIFT_LDS_UP_DET,
    LIFT_LDS_DOWN_DET,
} lift_lds_switch_offset;

typedef enum {
    ARM_DOOR_FAULT_DET,
    ARM_DOOR_UP_DET,
} arm_door_switch_offset;

typedef enum {
    CLAMP_FAULT_DET,
    CLAMP_UP_DET,
} clamp_switch_offset;

typedef enum {
    TRACKING_EVENT_INVALID                             = 0x00,
    TRACKING_EVENT_TOP_BUMPER_ID                       = 0x01,
} eRptTEId_e;

typedef struct _rrdata_cmd_ctx_ {
    eRptPkgId_e cmdId;
    uint8_t ready_flag;
    char data_buf[128];
    int data_size;
} rrdata_cmd_ctx;

typedef struct __rr_data_segment_head {
    unsigned short index;
    char result;
    char reserved;
} RRDATA_SEGMENT_HEAD;

#define RR_DATA_SEGMENT_SIZE    64
typedef struct __rr_data_segment {
    RRDATA_SEGMENT_HEAD head;
    char segment[RR_DATA_SEGMENT_SIZE];
} RRDATA_SEGMENT;


typedef enum {
    LOG_LEVEL_DEBUG  = 128,   // debug messages
    LOG_LEVEL_INFO,     // Informational messages that require no action.
    LOG_LEVEL_NOTICE,   // Normal, but significant events.
    LOG_LEVEL_WARNING,  // Warning conditions that should be taken care of.
    LOG_LEVEL_ERR,      // Noncritical error conditions.
    LOG_LEVEL_CRIT,     // Critical conditions
    LOG_LEVEL_ALERT,    // Actions that must be taken care of immediately.
    LOG_LEVEL_EMERG     // The system is unusable.
} LogLevel_e;

typedef enum {
    ERR_CRC                                            = -880,
    ERR_LOCATE                                         = -881,
    ERR_OVER_SIZE                                      = -882,
    ERR_CODER_OVER_SIZE                                = -883,
    ERR_DECODER_OVER_SIZE                              = -884,
    ERR_DECODER_DATA                                   = -885,
    ERR_DATA                                           = -886,
    ERR_PARA                                           = -887,
    ERR_TAIL                                           = -888,
} DataParseErr_e;

typedef enum {
    BBEVENTMCU_CHARGE,
    BBEVENTMCU_DISCHARGE,
} McuBlackBox_e;

typedef struct {
    unsigned char u8Id;
    unsigned int u32Ts;
} McuBlackBox_st;

typedef struct {
    unsigned short u16Vol;    //mV
} DockVol_st;

#if defined(UART_API_HAVE_CLIFF_TOF_MODULE)
#if defined (RR_DRV_HW_CLIFF_MCU_8)
typedef struct {
    //测试距离
    int16_t correction_tof;
    //置信度
    uint8_t confidence;
    //超过6个cliff时剩下的数据删除不上传，8*20>160 导致buff超了128,会导致MCU重启
} VI530x_MEASURE_TypeDef;
#else
typedef struct {
    //测试距离
    int16_t correction_tof;
    //置信度
    uint8_t confidence;
    //积分次数
    uint32_t intecounts;
    //Peak
    uint32_t peak;
    //Noise
    uint32_t noise;
    //xtalk_count
    uint16_t xtalk_count;
} VI530x_MEASURE_TypeDef;
#endif

typedef struct {
    VI530x_MEASURE_TypeDef stTof_LF;
    VI530x_MEASURE_TypeDef stTof_RF;
    VI530x_MEASURE_TypeDef stTof_LB;
#if (UART_API_HAVE_CLIFF == 4)
    VI530x_MEASURE_TypeDef stTof_RB;
#endif
#if (UART_API_HAVE_CLIFF == 5)
    VI530x_MEASURE_TypeDef stTof_RB;
    VI530x_MEASURE_TypeDef stTof_LB2;
#endif
#if (UART_API_HAVE_CLIFF == 6)
    VI530x_MEASURE_TypeDef stTof_RB;
    VI530x_MEASURE_TypeDef stTof_LB2;
    VI530x_MEASURE_TypeDef stTof_RB2;
#endif
#if (UART_API_HAVE_CLIFF == 8)
    VI530x_MEASURE_TypeDef stTof_RB;
    VI530x_MEASURE_TypeDef stTof_LB2;
    VI530x_MEASURE_TypeDef stTof_RB2;
    VI530x_MEASURE_TypeDef stTof_RR;
    VI530x_MEASURE_TypeDef stTof_RL;
#endif
} CliffVal_st;
#else
typedef struct {
    unsigned short u16LF;
    unsigned short u16RF;
    unsigned short u16LB;
#if (UART_API_HAVE_CLIFF == 4)
    unsigned short u16RB;
#endif
#if (UART_API_HAVE_CLIFF == 5)
    unsigned short u16RB;
    unsigned short u16LB2;
#endif
#if (UART_API_HAVE_CLIFF == 6)
    unsigned short u16RB;
    unsigned short u16LB2;
    unsigned short u16RB2;
#endif
#if (UART_API_HAVE_CLIFF == 7)
    unsigned short u16RB;
    unsigned short u16LB2;
    unsigned short u16RB2;
    unsigned short u16RR;
#endif
#if (UART_API_HAVE_CLIFF == 8)
    unsigned short u16RB;
    unsigned short u16LB2;
    unsigned short u16RB2;
    unsigned short u16RR;
    unsigned short u16RL;
#endif
} CliffVal_st;
#endif

typedef struct {
    unsigned char u8State;
} CarpetState_st;

#if defined (RR_DRV_SW_TOFCLIFF_BRAKE_SWITCH_MCU)
/*
    CLIFF_TYPE_LF  ---  bit 0, //机身左后 -LF
    CLIFF_TYPE_RF  ---  bit 1, //左前臂   -RF
    CLIFF_TYPE_LB  ---  bit 2, //机身左前 -LM
    CLIFF_TYPE_RB  ---  bit 3, //右前臂   -RM
    CLIFF_TYPE_LB2 ---  bit 4, //左后臂   -LB
    CLIFF_TYPE_RB2 ---  bit 5, //机身右后 -RB
    CLIFF_TYPE_RR  ---  bit 6, //机身右前 -RR
    CLIFF_TYPE_RL  ---  bit 7, //右后臂   -RL
*/
typedef struct TofcliffBrakeSwitch {
    unsigned int u32Mask;
} TofcliffBrakeSwitch_st;
#endif

typedef struct {
    unsigned char u8Data;
} MouseSrc_st;

typedef struct {
    unsigned short on_10ms : 14;
    unsigned short isFault : 1;
    unsigned short reserved : 1;
} WaterPump_st;

typedef struct {
    signed short s16Val_t1;
    signed short s16Val_t2;
    signed short s16Val_t3;
    signed short s16Val_t4;
    signed short s16Val_t5;
    signed short s16Val_t6;
    signed short s16Val_t7;
    signed short s16Val_t8;
} NTC_st;

#if defined(UART_API_HAVE_WATERBOX)
#define UART_API_WATERBOX_DATA_MASK 0x1
#define UART_API_RAG_DATA_MASK      0x2
#if defined(UART_API_HAVE_RAG_L_R)
#define UART_API_RAG_L_DATA_MASK      0x4
#define UART_API_RAG_R_DATA_MASK      0x8
#endif
#endif

typedef struct {
    unsigned char u8Level;             //0~100
} LedLightLevel_st;

/* flow led */
typedef enum {
    FLOW_LED_EFFECT_ALL_OFF      = 0x00,
    FLOW_LED_EFFECT_ALL_ON       = 0x01,
    FLOW_LED_EFFECT_EDGE         = 0x02,              //only for at and bit
    FLOW_LED_EFFECT_SWEEP        = 0x03,
    FLOW_LED_EFFECT_MOP          = 0x04,
    FLOW_LED_EFFECT_BLINK        = 0x05,
    FLOW_LED_EFFECT_BREATH       = 0x06,
    FLOW_LED_EFFECT_WATERLESS    = 0x07,
    FLOW_LED_EFFECT_WARMUP       = 0x08,
    FLOW_LED_EFFECT_BLINK_FAST   = 0x09,
    FLOW_LED_EFFECT_BOOTRING     = 0x0A,
    FLOW_LED_EFFECT_ALL_RED      = 0x0B,
    FLOW_LED_EFFECT_ALL_GREEN    = 0x0C,
    FLOW_LED_EFFECT_ALL_BLUE     = 0x0D,
    FLOW_LED_EFFECT_CHARGE       = 0x0E,
    FLOW_LED_EFFECT_SWEEP_WEAK   = 0x0F,
    FLOW_LED_EFFECT_SWEEP_STRONG = 0x10,
    FLOW_LED_EFFECT_MOP_WEAK     = 0x11,
    FLOW_LED_EFFECT_MOP_STRONG   = 0x12,
    FLOW_LED_EFFECT_COLLECT      = 0x13,
    FLOW_LED_EFFECT_ERROR        = 0x14,
    FLOW_LED_EFFECT_GO_HOME      = 0x15,
    FLOW_LED_EFFECT_CHARGING     = 0x15, // CHARGING and GO HOME are same
    FLOW_LED_EFFECT_CHARGE_00    = 0x16,
    FLOW_LED_EFFECT_CHARGE_20    = 0x17,
    FLOW_LED_EFFECT_CHARGE_40    = 0x18,
    FLOW_LED_EFFECT_CHARGE_60    = 0x19,
    FLOW_LED_EFFECT_CHARGE_80    = 0x1B,
    FLOW_LED_EFFECT_CHARGE_100   = 0x1C,
    FLOW_LED_EFFECT_VIDEO        = 0x1D,
    FLOW_LED_EFFECT_CHAT         = 0x1E,
    FLOW_LED_EFFECT_GO_WASH      = 0x1F,
    FLOW_LED_EFFECT_WASH         = 0x20,
    FLOW_LED_EFFECT_DEFEND_START = 0x21,
    FLOW_LED_EFFECT_DEFEND_FIND  = 0x22,
    FLOW_LED_EFFECT_DEFEND_SUCCESS = 0x23,
    FLOW_LED_EFFECT_DEFEND_SUCCESS_FAST = 0x24,

    FLOW_LED_EFFECT_NUM,
} FlowLEDEffect_e;

typedef struct {
    unsigned char u8Effect;
} FlowLedEffect_st;

#define BOOTRING_MASK 0x8000
typedef struct {
    unsigned short delay_ms; /* 0~32768 ms*/
} FlowLedBootringDelay_st;

/*             led             */
typedef enum {
    LED_TYPE_START_WHITE = 0,
    LED_TYPE_START_RED   = 1,
    LED_TYPE_HOME        = 2,
    LED_TYPE_SPOT        = 3,
#if defined(UART_API_HAVE_DRAG_LED)
    LED_TYPE_DRAG        = 4,
#endif
    LED_TYPE_NUM,
} LEDType_e;

typedef enum {
    LED_EFFECT_OFF              = 0,
    LED_EFFECT_ON               = 1,
    //Breath
    LED_EFFECT_BREATH           = 2,
    LED_EFFECT_DEEP_BREATH      = 3,
    //Blink: the larger the number is, the faster the LED blinks
    LED_EFFECT_BLINK_1          = 4,
    LED_EFFECT_BLINK_SLOW       = 5,
    LED_EFFECT_BLINK_MEDIUM     = 6,
    LED_EFFECT_BLINK_4          = 7,
    LED_EFFECT_BLINK_FAST       = 8,
    //Dual Blink
    LED_EFFECT_DUAL_BLINK       = 9,
    //Constant Brightness
    LED_EFFECT_NUM,
} LEDEffect_e;

#define LED_ALWAYS_REPEAT    0xFFFF

typedef struct {
    struct {
        unsigned char eEffect          : 7;
        unsigned char bAlternate       : 1;
    };
    struct {
        unsigned char eRepeatEffect    : 7;
        unsigned char bRepeatAlternate : 1;
    };
    unsigned short u16CycleNum; //Always repeating if the value >= 65535
} LEDEffectPara_st;

typedef struct {
    LEDEffectPara_st astLEDEffect[LED_TYPE_NUM];
} CmdLed_st;

#ifdef RR_DRV_HW_IR_CODE_EMITTER
typedef enum ir_emit_status {
    STATUS_DOCK_IR = 0x0,
    STATUS_PARKING,
    STATUS_DRIVE_OUT,
    STATUS_STANDBY,
    STATUS_PARA_MAX
} DockIREmitSta_e;

typedef struct ir_code_type {
    unsigned char type;  //from DockIREmitSta_e
} IrCodeType_st;

#endif
/*sn*/
#define SN_MAX_LEN          (32)
typedef struct {
    char as8SN[SN_MAX_LEN];
} Sn_st;

/*error*/
typedef enum {
    ERR_FACTEST                                        = 0,
} Error_e;

typedef enum {
    RANGE_SUCCESS          = 0,
    RANGE_ERR_I2C          = 1,
    RANGE_ERR_BOOT_TIMEOUT = 2,
    RANGE_ERR_ID           = 3,
} RangeError_e;

typedef struct {
    unsigned int bFacTestErr    : 1;
    unsigned int bImuSpiErr     : 1;
    unsigned int bChgIcI2cErr   : 1;
    unsigned int bNvramErr      : 1;
    unsigned int bRangeErr      : 2;
    unsigned int Rsvd           : 26;
} Err_st;

/*ts*/
#define MCU_IRQ_ALIGN_TIME_MS 1024
typedef struct {
    unsigned long long ts;
} McuTs_st;

typedef struct {
    unsigned int ts;
} McuRTC_st;

typedef struct {
    uint8_t enable;
} FunctionEnable_st;

typedef struct {
    uint8_t data[UART_API_HAVE_CLIFF];
} CliffCaliValue;

/**** for CMD_GET_DEV_INFO_ID / RPT_DEV_INFO_ID ****/
enum _DEVINFO_ {
    DEVINFO_INVALID             = 0,

    DEVINFO_WS_SHARP            = 1,
    DEVINFO_WS_ST               = 2,
    DEVINFO_WS_KODENSHI         = 3,

    DEVINFO_GYRO_BOSCH_BMI160   = 1,
    DEVINFO_GYRO_INV_ICM40607   = 2,
    DEVINFO_GYRO_BOSCH_BMI270   = 3,
    DEVINFO_GYRO_INV_ICM42670   = 4,
    DEVINFO_GYRO_QST_QMI8658    = 5,
    DEVINFO_GYRO_BOSCH_BMI055   = 6,
    DEVINFO_GYRO_BOSCH_BMI323   = 7,
    DEVINFO_GYRO_BOSCH_BMI088   = 8,
    DEVINFO_GYRO_MAX_ID,

    DEVINFO_BATT_DSY_PA         = 1,
    DEVINFO_BATT_DSY_LG         = 2,
    DEVINFO_BATT_SWD_PA         = 3,
    DEVINFO_BATT_SWD_LG         = 4,
    DEVINFO_BATT_SAMSUNG        = 5,
    DEVINFO_BATT_LG_M26         = 6,
    DEVINFO_BATT_SANYO          = 7,
    DEVINFO_BATT_DOMESTIC       = 8,
    DEVINFO_BATT_SDI35E         = 9,
    DEVINFO_BATT_LIPO_8339C1    = 10,
    DEVINFO_BATT_BAK            = 11,
    DEVINFO_BATT_LISHEN         = 12,
    DEVINFO_BATT_ATL5130        = 13,
    DEVINFO_BATT_DEPWR_26P      = 14,
    DEVINFO_BATT_SCUD           = 15,
    DEVINFO_BATT_DEPWR_LISHEN   = 16,
    DEVINFO_BATT_DEPWR_TIANPENG = 17,
    DEVINFO_BATT_DSY_YIWEI      = 18,
    DEVINFO_BATT_SCUD_TIANPENG  = 19,
    DEVINFO_BATT_MAX_ID,

    DEVINFO_CHRIC_BQ24773       = 1,
    DEVINFO_CHRIC_BD99954       = 2,
    DEVINFO_CHRIC_SC8886        = 3,
    DEVINFO_CHRIC_BQ25713       = 4,
    DEVINFO_CHRIC_BQ25721       = 5,
    DEVINFO_CHRIC_SGM41573      = 6,
    DEVINFO_CHRIC_MAX_ID,

    DEVINFO_FAN_NIDEC           = 1,
    DEVINFO_FAN_DAOJING         = 2,
    DEVINFO_FAN_NIDEC_4200      = 3,
    DEVINFO_FAN_KWT_4200        = 4,
    DEVINFO_FAN_DAOJIN_4200     = 5,
    DEVINFO_FAN_ROHM            = 6,
    DEVINFO_FAN_KELIER_4200     = 7,
    DEVINFO_FAN_XDS_4200        = 8,//CDS-WA70-0001
    DEVINFO_FAN_MAX_ID,

    DEVINFO_LDS_V1              = 1,     /* only for rubys old version */
    DEVINFO_LDS_V2              = 2,     /* ruby, tanos... used */

    DEVINFO_FLOWLED_ISSI        = 1,
    DEVINFO_FLOWLED_AWINIC      = 2,

    DEVINFO_MOP_FORTIOR         = 1,
    DEVINFO_MOP_TOSHIBA         = 2,
    DEVINFO_MOP_LINKO           = 3,

};

typedef enum {
    DEVINFO_TYPE_NONE           = 0,
    DEVINFO_TYPE_WS             = 1,
    DEVINFO_TYPE_GYRO           = 2,
    DEVINFO_TYPE_BATTERY        = 3,
    DEVINFO_TYPE_CHARGER        = 4,
    DEVINFO_TYPE_MCU            = 5,
    DEVINFO_TYPE_BOARD          = 6,
    DEVINFO_TYPE_FAN            = 7,
    DEVINFO_TYPE_LDS            = 8,
    DEVINFO_TYPE_FLOWLED        = 9,
    DEVINFO_TYPE_MOP            = 10,
} DevInfoType_e;

typedef struct {
    unsigned char u8WSType;
    unsigned char u8GyroType;
    unsigned char u8BattType;
    unsigned char u8ChrIcType;
    unsigned char u8McuId;
    unsigned char u8BoardId;
    unsigned char u8FanType;
    unsigned char u8LdsId;
    unsigned char u8FlowLedId;
    unsigned char u8MopId;
    unsigned char u8SubGyroId;
    unsigned char reserved[5];
} DevInfo_st;

/***** end of DEV_INFO_ID *****/
#ifdef UART_API_HAVE_RUBYS_KEY

//becareful, old key st only support key val 0x0 ~ 0x3f, because it's 6 bit
typedef enum {
    KEY_NONE                                           = 0,
    START_STOP_SHORT                                   = 1,
    START_STOP_LONG                                    = 2,
    DOCK_BACK_SHORT                                    = 3,
    DOCK_BACK_LONG                                     = 4,
    COMPOSITE_LONG                                     = 6,
    KEY_RPT_DOWN                                       = 8,
    KEY_HOME_START_DOWN                                = 9,

    KEY_RPT_SPOT_SHORT                                 = 11,
    KEY_RPT_SPOT_LONG                                  = 12,
    KEY_RPT_HOME_LONG_10                               = 14,
    COMPOSITE_START_HOME_SPOT_SHORT                    = 15,
    COMPOSITE_START_HOME_SPOT_LONG                     = 16,
    KEY_RPT_UP                                         = 17,
#if defined(UART_API_HAVE_KEY_SPOT)
    COMPOSITE_START_HOME_SHORT                         = 18,
    COMPOSITE_START_HOME_LONG                          = 19,
#else
    COMPOSITE_START_HOME_LONG                          = COMPOSITE_LONG,
#endif

    KEY_INVALID                                        = 0xff,
} KeyAction_e;

typedef struct {
    unsigned char b6Val   : 6;
    unsigned char b2Index : 2;
} Key_st;

#else


/*key*/
typedef enum {
    KEY_NONE                                           = 0,
    /* single key short begin (0x1 ~ 0x1f) */
    START_STOP_SHORT                                   = 0x1,
    DOCK_BACK_SHORT                                    = 0x2,
    KEY_RPT_SPOT_SHORT                                 = 0x3,
    KEY_RPT_EMER_SHORT                                  = 0x4,

    /* single key long begin (0x20 ~ 0x3f) */
    SINGLE_KEY_BASE                                    = 0x20, /*will never rpt base*/
    START_STOP_LONG                                    = SINGLE_KEY_BASE | START_STOP_SHORT,
    DOCK_BACK_LONG                                     = SINGLE_KEY_BASE | DOCK_BACK_SHORT,
    KEY_RPT_SPOT_LONG                                  = SINGLE_KEY_BASE | KEY_RPT_SPOT_SHORT,
    KEY_RPT_EMER_LONG                                  = SINGLE_KEY_BASE | KEY_RPT_EMER_SHORT,

    /* composite key short begin (0x40 ~ 0x5f) */
    COMPOSITE_KEY_SHORT_BASE                           = 0x40, /*will never rpt base*/
    COMPOSITE_SHORT                                    = COMPOSITE_KEY_SHORT_BASE + 0,
    COMPOSITE_START_HOME_SPOT_SHORT                    = COMPOSITE_KEY_SHORT_BASE + 1,
    COMPOSITE_START_SPOT_SHORT                         = COMPOSITE_KEY_SHORT_BASE + 2,
#if defined(UART_API_HAVE_KEY_SPOT)
    COMPOSITE_START_HOME_SHORT                         = COMPOSITE_KEY_SHORT_BASE + 3,
#endif
    COMPOSITE_START_EMERGENCY_SHORT = COMPOSITE_KEY_SHORT_BASE + 4,
    COMPOSITE_BACK_EMERGENCY_SHORT = COMPOSITE_KEY_SHORT_BASE + 5,

    /* composite key long begin (0x60 ~ 0x7f) */
    COMPOSITE_KEY_LONG_BASE                            = 0x60, /*will never rpt base*/
    COMPOSITE_LONG                                     = COMPOSITE_KEY_LONG_BASE | COMPOSITE_SHORT,
    COMPOSITE_START_HOME_SPOT_LONG                     = COMPOSITE_KEY_LONG_BASE | COMPOSITE_START_HOME_SPOT_SHORT,
    COMPOSITE_START_SPOT_LONG                          = COMPOSITE_KEY_LONG_BASE | COMPOSITE_START_SPOT_SHORT,
#if defined(UART_API_HAVE_KEY_SPOT)
    COMPOSITE_START_HOME_LONG                          = COMPOSITE_KEY_LONG_BASE | COMPOSITE_START_HOME_SHORT,
#else
    COMPOSITE_START_HOME_LONG                          = COMPOSITE_LONG,
#endif
    COMPOSITE_START_EMERGENCY_LONG = COMPOSITE_KEY_LONG_BASE | COMPOSITE_START_EMERGENCY_SHORT,
    COMPOSITE_BACK_EMERGENCY_LONG = COMPOSITE_KEY_LONG_BASE | COMPOSITE_BACK_EMERGENCY_SHORT,

    /* special key begin (0x80 ~ 0xee) */
    KEY_RPT_DOWN                                       = 0x80,
    KEY_RPT_HOME_LONG_10                               = 0x81,
    KEY_HOME_START_DOWN                                = 0x82,
    KEY_RPT_START_3_TIMES                              = 0x83,

    KEY_START_EMER_DOWN                                = 0x84,
    KEY_HOME_EMER_DOWN                                 = 0x85,
    KEY_RPT_START_2_TIMES                              = 0x86,
    KEY_EMER_RPT_DOWN                                  = 0x87,

    KEY_RPT_UP                                         = 0xa0,

    KEY_RESERVE_BASE                                   = 0xf0,
    KEY_INVALID                                        = 0xff,
} KeyAction_e;

typedef struct {
    unsigned char
    b6Val;    /* b6Val real is u8Val, keep this name just for build compatible */
    unsigned char
    b2Index;  /* b2Index real is u8Index, keep this name just for build compatible */
} Key_st;
#endif

typedef union {
    Key_st        stKey;
    unsigned char u8RptKeyVal;
} Key_u;

typedef struct mouse_data {
    int s32XVal;
    int s32YVal;
    unsigned short u16ImageQuality; //s32AmplitudeVal
    unsigned char  u8Shutter;
    unsigned char  u8LTSrc;
    unsigned char  u8InitOK;
    unsigned char  u8FrameAvg;
    unsigned char  u8Qrd;
    unsigned char  u8Dirty;
    int mouse_valid_cnt;
    int mouse_delta_raw[2];
} Mouse_st;

#if defined(UART_API_HAVE_AP_MOUSE)
#pragma pack(1)
struct mouse_data_t {
    rua_id_t id;
    rua_st_t len;
    Mouse_st stmousedata;
};
#pragma pack()
#endif

/*gyro*/
typedef struct {
    float   acc[3];
    float   gyro[3];
    float   quat[4];
    int     odo[2];
    float   actual_VL;
    char IMUErrorFlag;
#if defined(UART_API_HAVE_MOUSE)
    Mouse_st  mouse;
#endif
} GyroOdo_st;

typedef struct gyro_odo_com {
    signed short int acc[3];
    signed short int gyro[3];
    signed short int quat[4];
    int              odo[2];
    signed short int actual_VL;
    char             IMUErrorFlag;
#if defined(UART_API_HAVE_MOUSE)
    Mouse_st  mouse;
#endif
#if defined(RR_DRV_SW_ODO_TIMESTAMP)
    uint64_t         msTick;
#endif
} GyroOdoCom_st;
typedef struct gyro_offset {
    signed short        i16OffsetOrigin[3];
    signed short        i16OffsetCurrent[3];
    unsigned int        u32UpdateCnt;
} GyroOffset_st;

typedef struct gyro_bias {
    float fGyroBias[3];
} GyroBias_st;

typedef struct gyro_reinit_sta {
    uint8_t u8GyroReinitSta;   //0,means normal && reinit success, 1 means start reinit, 2 means reinit fail
    uint8_t u8DetailInfo;      //reserved
} GyroReInitSta_st;

/**/
typedef enum {
    RANGE_NORMAL                                       = 0,
    RANGE_ERROR                                        = 1,
} RangeStatus_e;

#define ChrgStatus_ERR_ADPT_VOLTAGE   ((uint8_t)0x01)// dock voltage error
#define ChrgStatus_ERR_ADPT_CURRENT   ((uint8_t)0x02)// dock current error
#define ChrgStatus_ERR_CHG_VOLTAGE    ((uint8_t)0x04)// charge voltage error
#define ChrgStatus_ERR_CHG_CURRENT    ((uint8_t)0x08)// charge current error
#define ChrgStatus_ERR_I2C_TO_CHG     ((uint8_t)0x10)// IC error
#define ChrgStatus_ERR_RESERVED_0     ((uint8_t)0x20)// RFU
#define ChrgStatus_ERR_RESERVED_1     ((uint8_t)0x40)// RFU
#define ChrgStatus_ERR_RESERVED_2     ((uint8_t)0x80)// RFU

typedef enum {
    BAT_TEMP_NO_ERR = 0,
    BAT_TEMP_HIGH_ERR = 1,
    BAT_TEMP_LOW_ERR = 2,
} BatTempState_e;

typedef struct {
    unsigned short  u16VolVal;       /* mV   for Battery aging*/
    unsigned short  u16IVal;         /* mA   for Battery aging*/
    unsigned char   u8Soc;           /*0-100*/
    unsigned char   u8ChrgStatus;    /*0: ok, 1: error*/
    unsigned char   u8VolStatus;     /*0: ok, 1: error*/
    unsigned char   u8TmpStatus;      /*0: ok, 1: high temp error, 2: low temp err*/
    unsigned char   u8CurrStatus;    /*0: ok, 1: error*/
    unsigned char   u8ChgTempStatus;  /*0: ok, 1: high temp error, 2: low temp err*/
} Bat_st;

typedef struct {
    unsigned char u8Capx100mAh;   /* value x100mAh, 52: 5200mAh*/
    unsigned char reserved;
} BatCap_st;

typedef enum {
    ADAP_CUR_OK = 0,
    ADAP_CUR_DOWN = 1,
    ADAP_CUR_RECOVER = 2,
    ADAP_CUR_ERR = 3,
} AdapCurState_e;

typedef enum {
    BAT_CUR_LEVEL_0A5 = (0x01 << 0),
    BAT_CUR_LEVEL_1A0 = (0x01 << 1),
    BAT_CUR_LEVEL_1A5 = (0x01 << 2),
} BatCurLevel_e;

typedef struct adp_info {
    unsigned short u16AdpVol; // mV
    unsigned short u16AdpCur; // mA
    unsigned char u8CurState; //upgrade or downgrade state
    unsigned char u8BatCurLevel;
} Adapt_st;

/* sensors event strcut*/
typedef enum {
    STATUS_NORMAL                                      = 0x0,
    STATUS_TRIGGER                                     = 0x1,
    STATUS_DISABLE                                     = 0x2,
} SensorStatus_e;

/* top bumper for braking*/
typedef enum {
    BRAKE_BUMPER_LEFT                                  = (0x01 << 0),
    BRAKE_BUMPER_MIDDLE                                = (0x01 << 1),
    BRAKE_BUMPER_RIGHT                                 = (0x01 << 2),
} BrakeBumper_e;

typedef struct {
    BrakeBumper_e BrakeBumperId;
} BrakeBumper_st;

#if defined(RR_DRV_SW_BUMPER_BRAKE_SWITCH_MCU)
/*
//这里对应的是下面 u32Mask 中的每一位，一位代表一个bumper，0为不刹车，1为需要刹车
typedef enum BumpBrakeSwitch_id
{
    F_BUMPER_SWITCH    = (0x1 << 0),//机身前
    B_BUMPER_SWITCH    = (0x1 << 1),//机身后
    FL_F_BUMPER_SWITCH = (0x1 << 2),//FL_F_BUMPER 左前臂-前
    FL_M_BUMPER_SWITCH = (0x1 << 3),//FL_BUMPER   左前臂-中外侧
    FL_B_BUMPER_SWITCH = (0x1 << 4),//FL_B_BUMPER 左前臂-后
    FR_F_BUMPER_SWITCH = (0x1 << 5),//FR_F_BUMPER 右前臂-前
    FR_M_BUMPER_SWITCH = (0x1 << 6),//FR_BUMPER   右前臂-中外侧
    FR_B_BUMPER_SWITCH = (0x1 << 7),//FR_B_BUMPER 右前臂-后
    BL_F_BUMPER_SWITCH = (0x1 << 8),//BL_F_BUMPER 左后臂-前
    BL_M_BUMPER_SWITCH = (0x1 << 9),//BL_BUMPER   左后臂-中外侧
    BL_B_BUMPER_SWITCH = (0x1 << 10),//BL_B_BUMPER 左后臂-后
    BR_F_BUMPER_SWITCH = (0x1 << 11),//BR_F_BUMPER 右后臂-前
    BR_M_BUMPER_SWITCH = (0x1 << 12),//BR_BUMPER   右后臂-中外侧
    BR_B_BUMPER_SWITCH = (0x1 << 13),//BR_B_BUMPER 右后臂臂-后
}BmpId_e;
*/
typedef struct BumpBrakeSwitch {
    unsigned int u32Mask;
} BumpBrakeSwitch_st;
#endif

typedef struct Sensor16 {
    unsigned short bit0 : 1;
    unsigned short bit1 : 1;
    unsigned short bit2 : 1;
    unsigned short bit3 : 1;
    unsigned short bit4 : 1;
    unsigned short bit5 : 1;
    unsigned short bit6 : 1;
    unsigned short bit7 : 1;
    unsigned short bit8 : 1;
    unsigned short bit9 : 1;
    unsigned short bit10 : 1;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short bit13 : 1;
    unsigned short bit14 : 1;
    unsigned short bit15 : 1;
} Sensor16_st;

typedef struct Sensor8 {
    unsigned short u2LB2: 2;
    unsigned short u2RB2: 2;
    unsigned short u2LB : 2;
    unsigned short u2RB : 2;
    unsigned short u2LF : 2;
    unsigned short u2RF : 2;
    unsigned short u2RR : 2;
    unsigned short u2RL : 2;
} Sensor8_st;

typedef struct {
    unsigned short u4LB : 4;
    unsigned short u4RB : 4;
    unsigned short u4LF : 4;
    unsigned short u4RF : 4;
} Sensor4_st;

typedef struct {
    unsigned short u8L : 8;
    unsigned short u8R : 8;
} Sensor2_st;

typedef struct {
    unsigned short u16Val;
} Sensor1_st;

typedef union {
    Sensor1_st      S1;
    Sensor2_st      S2;
    Sensor4_st      S4;
    Sensor8_st      S8;
    Sensor16_st     S16;
    unsigned short  u16Val;
} Sensor_u;

#if defined(RR_DRV_HW_MIXED_BUMPER_MCU)
typedef struct {
    uint32_t u2FL_F : 2;//FL_F_BUMPER 左前臂-前
    uint32_t u2FL_M   : 2;//FL_BUMPER   左前臂-中外侧
    uint32_t u2FL_B : 2;//FL_B_BUMPER 左前臂-后
    uint32_t u2FR_F : 2;//FR_F_BUMPER 右前臂-前
    uint32_t u2FR_M   : 2;//FR_BUMPER   右前臂-中外侧
    uint32_t u2FR_B : 2;//FR_B_BUMPER 右前臂-后
    uint32_t u2BL_F : 2;//BL_F_BUMPER 左后臂-前
    uint32_t u2BL_M   : 2;//BL_BUMPER   左后臂-中外侧
    uint32_t u2BL_B : 2;//BL_B_BUMPER 左后臂-后
    uint32_t u2BR_F : 2;//BR_F_BUMPER 右后臂-前
    uint32_t u2BR_M   : 2;//BR_BUMPER   右后臂-中外侧
    uint32_t u2BR_B : 2;//BR_B_BUMPER 右后臂臂-后
    uint32_t RESERVED1 : 2;
    uint32_t RESERVED2 : 2;
    uint32_t RESERVED3 : 2;
    uint32_t RESERVED4 : 2;
} Sensors_16_st;
typedef union {
    Sensors_16_st S16;
    uint32_t u32Val;
} Sensor_32_u;
#endif

typedef struct {
    uint32_t pressure;
    int32_t temperature;
} Sensor_bar_s;

/*dock*/
typedef enum {
    STATUS_DOCK_DC_OFF                                 = 0x0,
    STATUS_DOCK_IN                                     = 0x1,
    STATUS_DOCK_AC_OFF                                 = 0x2,
    STATUS_DOCK_CONNECT                                = 0x3,
    STATUS_DOCK_ERROR                                  = 0x4,
} DockStatus_e;

/*distance   use for wall/ultra*/
typedef struct {
    unsigned short u16Distance;
#if defined(UART_API_HAVE_LIGHT_TOUCH_3)
    unsigned short data1;
    unsigned short data2;
#endif
} Distance_st;

typedef struct {
    unsigned short u16ADCVal;
} LightTouch_st;

/*motors*/
typedef enum {
    MOTOR_NORMAL                                       = 0x0,      //0x00
    MOTOR_CUR_LOW                                      = (0x1 << 1), //0x02
    MOTOR_CUR_WARN                                     = (0x1 << 2), //0x04
    MOTOR_CUR_HIGH                                     = (0x1 << 3), //0x08
    MOTOR_OC_TIMEOUT                                   = (0x1 << 4), //0x10
    MOTOR_SHORT_CIRCUIT                                = (0x1 << 5), //0x20
    MOTOR_OPEN_CIRCUIT                                 = (0x1 << 6), //0x40
    MOTOR_CUR_MEDIUM                                   = (0x1 << 7), //0x80
    MOTOR_REVERSE_TIMEOUT                              = 0x81,
    MOTOR_STALL                                        = 0x82,
    MOTOR_HARD_OC                                      = 0x83,
    MOTOR_LOSSPHASE                                    = 0x84,
    MOTOR_TEMP_HIGH                                    = 0x85,
    MOTOR_DRV_FAULT                                    = 0x86,
    MOTOR_STOP_TOO_FAST                                = 0x87,
    MOTOR_STOP_TOO_SLOW                                = 0x88,
    MOTOR_OPEN_STOP_SWITCH                             = 0x89,
    MOTOR_CLOSE_STOP_SWITCH                            = 0x90,
    MOTOR_BLOCK                                        = 0x91,
} Motor_e;



typedef enum {
    INV_MOTOR_SPD                                      = -1,
} InvalidVal_e;

typedef struct {
    unsigned short     u16LIVal;
    unsigned short     u16RIVal;
    signed   char      s8LDuty;                           /*-100 ~ 100*/
    signed   char      s8RDuty;                           /*-100 ~ 100*/
    unsigned char      u8LStatus;
    unsigned char      u8RStatus;
#if defined(RR_DRV_SW_ODO_TIMESTAMP)
    uint64_t           msTick;
#endif
} Wheel_st;

typedef struct {
    signed   short     s16Spd;
    unsigned short     u16IVal;
    unsigned char      u8MotorStatus;
    signed   char      s8Duty;                           /*-100 ~ 100*/
} Motor_st;
typedef enum {
    MOTOR_STOP = 0,
    MOTOR_MIDDLE = 1,
    CAL_GET_SWITCH_TIMEOUT = 1,
    MOTOR_SWITCHSTOP = 2,
#ifndef BRUSHLIFT_DET_ON_MIDDLE
    UPOVERCURRENTSTOP = 2,
#endif
    //MOTOR_OVERCONTSTOP = 3,
    MOTOR_SMOPTIMEOUTSTOP = 3,
#ifndef BRUSHLIFT_DET_ON_MIDDLE
    SWITCH_0_TO_1_TIMEOUT = 4,
    SWITCH_1_TO_0_TIMEOUT = 5,
    SWITCH2_0_TO_1_TIMEOUT = 6,
    CAL_LEAVE_SWITCH_TIMEOUT = 7,
#endif
    SMOPUNKNOW,
} brushlift_st;

enum motor_board_id {
    BRUSH_STEP_MOTOR_DET_UP,
    BRUSH_DC_MOTOR_DET_DOWN,
};
#pragma pack(1)
struct event_status {
    unsigned int event: 4;
    unsigned int data1: 12;
    unsigned int data2: 12;
    unsigned int board_id: 1;
    unsigned int is_cal: 1;
    unsigned int switch_status: 1;
    unsigned int reserve: 1;
};
#pragma pack()

typedef union event_status_union {
    struct event_status report_event;
    int report_envent_intager;
} event_status_union;
typedef enum {
    DIR_CLOSE,
    DIR_OPEN,
} cabindoor_dirction;

#define BRUSHLIFT_STATUS_UP 0
#define BRUSHLIFT_STATUS_DWON 1
#define BRUSHLIFT_STATUS_SHIFT 3
typedef enum {
    CMD_MOTOR_STOP,
    CMD_MOTOR_UP,
    CMD_MOTOR_DOWN,
    CMD_MOTOR_CAL,
    CMD_MOTOR_UNKNON,
} brushlift_direction;
typedef enum {
    BL_UNKNOWN_STATUS = 0,
    BL_UP_STATUS = 1,
    BL_DOWN_STATUS = 2,
} brushlift_status;
typedef enum {
    BL_ONLY_MIDDLE = 0x01,
    BL_ONLY_STOP = 0x02,
    BL_ONLY_OVERCOUNT_STOP = 0x03,
    BL_WORK_STOP = 0x12,
    BL_WORK_OVERCOUNT_STOP = 0x13,
} brushlift_response;
typedef enum {
    SET_UP_STOP_DELAY,
    SET_DOWN_STOP_DELAY,
    GET_UP_STOP_DELAY,
    GET_DOWN_STOP_DELAY,
} brushlift_stop_delay_cmd;
typedef struct brushlist_cmd_t {
    int direction;
    int duty;
    unsigned short u16VolVal;
} brushlist_cmd_t;
typedef struct brushlist_stop_delay_t {
    int cmd;
    int value;
} brushlist_stop_delay_t;

#ifdef BRUSHLIFT_DET_ON_MIDDLE

#ifdef BRUSHLIFT_DET_ON_MIDDLE_LIGHT_DET
#define BRUSHLIFT_UP_DUTY 45
#else
#define BRUSHLIFT_UP_DUTY 40
#endif

#else
#define BRUSHLIFT_UP_DUTY 45
#define BRUSHLIFT_STEP_DET 1
#define BRUSHLIFT_STEP_NO_DET 2
#endif

#define BRUSHLIFT_DOWN_DUTY 35
#define BRUSHLIFT_DUTY_DEFAULT -1
#pragma pack(1)
struct brushlift_data_t {
    rua_id_t id;
    rua_st_t len;
    Motor_st stbrushliftmotor;
};

struct brushliftswitch_data_t {
    rua_id_t id;
    rua_st_t len;
    Sensor_u data;
};
#pragma pack()
/*define for system mode*/
typedef enum {
    SYS_MODE_NORMAL                                    = 0x0,    /*working mode*/
    SYS_MODE_IDLE                                      = 0x1,    /*sleep*/
    SYS_MODE_FACTORY                                   = 0x2,    /*factory*/
    SYS_MODE_BIT                                       = 0x3,    /*BIT*/
    SYS_MODE_AUTO_BIT                                  = 0x4,    /*AUTOBIT*/
    SYS_MODE_APP_TEST                                  = 0x5,    /*MOBILITY*/
    SYS_MODE_SHUTDOWN                                  = 0x6,    /*shutdown*/
    SYS_MODE_RESET                                     = 0x7,    /*Reset*/
    SYS_MODE_ENERGY_EFFICIENCY                         = 0x8,
    SYS_MODE_RETREAD                                   = 0x9,
    SYS_MODE_SELF_CALIBRATION                          = 0xa,

    SYS_MODE_PWRON_STARTKEY_ONLY                       = 0x20,    /*StartKey pwron*/
    SYS_MODE_RESET_WDT_ONLY                            = 0x21,    /*WDG reset*/
    SYS_MODE_RESET_KEY_ONLY                            = 0x22,    /*Key reset*/
    SYS_MODE_RESET_SOFT_ONLY                           = 0x23,    /*SoftWare reset*/

    SYS_MODE_PWRON_DOCK_ONLY                           = 0x40,    /*DOCK pwron*/
    SYS_MODE_RESET_WDT_WITH_DOCK                       = 0x41,    /*WDT reset & DOCK*/
    SYS_MODE_RESET_KEY_WITH_DOCK                       = 0x42,    /*KEY reset & DOCK*/
    SYS_MODE_RESET_SOFT_WITH_DOCK                      = 0x43,    /*SOFT reset & DOCK*/

    SYS_MODE_MCU_RESET_AP                              = 0x44,    /* Force reset AP by MCU, used to notify AP the reboot reason */
    SYS_MODE_END
} SysMode_e;

#define SYS_MODE_MAGIC           "sys_md"
#define SYS_MODE_MAGIC_FORCE     "sys_fc"
#define SYS_MODE_MAGIC_MAX_LEN   (7)
typedef struct {
    //magic should be "sys_md" or "sys_fc"
    char  au8Magic[SYS_MODE_MAGIC_MAX_LEN];
    unsigned char  u8Mode;
} SysMode_st;

#ifdef RR_DRV_SW_MUTI_CORE_COMM
/*
 * u8Mode:
 * 0->bit_led_testing()
 * 1->led_real_time_indicate (bool Enable)
 * 2->led_ret_indicate (s32 s32Flag)
 */
typedef enum {
    LED_MODE_TESTING = 0,
    LED_MODE_REAL_TIME = 1,
    LED_MODE_RET = 2,
} LedMode_e;
typedef struct led_mode {
    unsigned char u8Mode;
    uint32_t param;
} LedMode_st;
#endif

typedef enum {
    MOP_POS_TOP                                        = 0x0,
    MOP_POS_GROUND                                     = 0x1,
} MopPos_e;

typedef enum {
    STRECH_RAG_POS_B = 0,
    STRECH_RAG_POS_F = 1,
    STRECH_RAG_POS_M = 2,
    STRECH_RAG_ERROR = 3,
    STRECH_RAG_DISABLE = 4,
} Strech_rag_Pos_e;

/**dev en/dis able bit field from ap**/
typedef enum {
    //MCU_DEVID_BANK0
    SWITCH_ACTION                                      = (0x1U << 0),
    SWITCH_BUMPER                                      = (0x1U << 1),
    SWITCH_ULTRASONIC                                  = (0x1U << 2),
    SWITCH_CLIFF                                       = (0x1U << 3),
    SWITCH_WALL                                        = (0x1U << 4),
    SWITCH_DROP                                        = (0x1U << 5),
    SWITCH_DUSTIN                                      = (0x1U << 6),
    SWITCH_BRUSH                                       = (0x1U << 7),
    SWITCH_SWEEP                                       = (0x1U << 8),
    SWITCH_FAN                                         = (0x1U << 9),
    SWITCH_WHEEL_ODO                                   = (0x1U << 10),
    SWITCH_GYRO                                        = (0x1U << 11),
    SWITCH_BAT                                         = (0x1U << 12),
    SWITCH_DOCK_IR                                     = (0x1U << 13),
    SWITCH_WATERBOX                                    = (0x1U << 14),
    SWITCH_WATERPUMP                                   = (0x1U << 15),
    SWITCH_MOP                                         = (0x1U << 16),
    SWITCH_LT                                          = (0x1U << 17),
    SWITCH_CARPET                                      = (0x1U << 18),
    SWITCH_MOUSE                                       = (0x1U << 19),
    SWITCH_STRECH_RAG                                  = (0x1U << 20),
    SWITCH_VACUUMPUMP                                  = (0x1U << 22),
    SWITCH_BRAKE_DET                                   = (0x1U << 23),
    SWITCH_STEER                                       = (0x1U << 24),
    SWITCH_AP_STEP_BRUSHLIFT_POWER                     = (0x1U << 25),
    SWITCH_AP_ARM_DOOR_POWER                           = (0x1U << 26),
    SWITCH_AP_ARM_WHEEL_PWR_EN                         = (0x1U << 27),
    SWITCH_AP_MECH_ARM_PWR_EN                          = (0x1U << 28),
    SWITCH_AP_SWITCH_3V3C_DOOR_EN                      = (0x1U << 29),
    SWITCH_AP_SWITCH_BACKUNIVERSAL_EN                  = (0x1U << 30),
    SWITCH_SWEEP_STRETCH_LIFT                          = (0x1U << 31),

    //MCU_DEVID_BANK1
    SWITCH_FRONT_SWING                                 = (0x1U << 1),
    SWITCH_BACK_SWING                                  = (0x1U << 2),
    SWITCH_SIDEMOP_LIFT                                = (0x1U << 3),
    SWITCH_LDS_LIFT                                    = (0x1U << 4),
    SWITCH_CPU_FAN                                     = (0x1U << 5),
    SWITCH_IR_CODE_EMITTER                             = (0x1U << 6),
    SWITCH_CABINDOOR_DET                               = (0x1U << 7),
} DevId_e;

typedef enum McuDev_bank {
    MCU_DEVID_BANK0,
    MCU_DEVID_BANK1,
    MCU_DEVID_BANK2,
    MCU_DEVID_BANK3,
} DevIdBank_e;

#if defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_VIVIAN_SPRO)
#define LDS_POWER_SWITCH_DEVICES (SWITCH_BUMPER | SWITCH_WALL | SWITCH_MOP | SWITCH_SWEEP)
#elif defined(RR_PROJECT_CORAL_PRO)
#define LDS_POWER_SWITCH_DEVICES (SWITCH_BUMPER | SWITCH_WALL | SWITCH_SWEEP | SWITCH_SWEEP_STRETCH_LIFT)
#elif defined(RR_PROJECT_TESSERACT)
#define LDS_POWER_SWITCH_DEVICES (SWITCH_BUMPER)
#define POWER_SWITCH2_DEVICES (SWITCH_FRONT_SWING | SWITCH_BACK_SWING | SWITCH_IR_CODE_EMITTER)
#elif defined (RR_PROJECT_R50)
#define LDS_POWER_SWITCH_DEVICES (SWITCH_BUMPER | SWITCH_WALL | SWITCH_MOP | SWITCH_SWEEP | SWITCH_AP_SWITCH_BACKUNIVERSAL_EN | SWITCH_SWEEP_STRETCH_LIFT)
#define POWER_SWITCH2_DEVICES (SWITCH_CABINDOOR_DET)
#define RR_DRV_SW_AP_MOTOR_POWER (SWITCH_AP_STEP_BRUSHLIFT_POWER | SWITCH_AP_ARM_DOOR_POWER | SWITCH_STEER | SWITCH_AP_SWITCH_BACKUNIVERSAL_EN)
#define RR_DRV_SW_AP_WHEEL_POWER (SWITCH_AP_ARM_WHEEL_PWR_EN | SWITCH_WHEEL_ODO)
#else
#define LDS_POWER_SWITCH_DEVICES (SWITCH_BUMPER | SWITCH_WALL | SWITCH_MOP)
#endif

typedef struct McuDevSwitch {
    unsigned int u32Mask;
    unsigned char u8Bank;
} DevSwitch_st;

/* TESTINFO */
typedef enum {
    TESTINFO_RESULT_UNINIT    = 0x0,
    TESTINFO_RESULT_TESTING   = 0x1,
    TESTINFO_RESULT_FAIL      = 0x2,
    TESTINFO_RESULT_SUCCESS   = 0x3,
    TESTINFO_RESULT_NUM,
} TestResult_e;

/* testinfo old */
typedef enum {
#ifdef UART_API_HAVE_STATION_SPECIAL
    TESTINFO_STATION_AMT   = 0,
    TESTINFO_STATION_GYROCAL,
    TESTINFO_STATION_CLIFFCAL,
    TESTINFO_STATION_BIT,
    TESTINFO_STATION_MT,
    TESTINFO_STATION_MC,
    TESTINFO_STATION_RESERVE1,
    TESTINFO_STATION_RESERVE2,
#else
    TESTINFO_STATION_1   = 0,
    TESTINFO_STATION_2,
    TESTINFO_STATION_3,
    TESTINFO_STATION_4,
    TESTINFO_STATION_RESET,
    TESTINFO_STATION_BIT,
    TESTINFO_STATION_MT,
    TESTINFO_STATION_MC,
#endif
    TESTINFO_STATION_MAX_NUM
} TestStation_e;

typedef struct {
    unsigned char u8Info[TESTINFO_STATION_MAX_NUM];
} TestInfo_st;

#if defined(UART_API_HAVE_TESTINFO_V2)
#define TI_STA_BUF_SIZE     20
#define TI_STA_HEADER_BITS  5
#else
#define TI_STA_BUF_SIZE     8
#define TI_STA_HEADER_BITS  4
#endif
#define TI_STA_NUM_SUPPORT_MAX  ((TI_STA_BUF_SIZE-sizeof(TestInfoHeaer_st)) * 8/TI_VER_1_BITS)
#define TI_VER_BASE      8  //start from 8, not 1,  Do not change
#define TI_VER_1         (TI_VER_BASE + 1)
#define TI_VER_1_BITS    2

typedef enum {
    TESTINFO_V1_STATION_RESET = TESTINFO_STATION_MAX_NUM + 1,
    TESTINFO_V1_STATION_BIT,
    TESTINFO_V1_STATION_MT,
    TESTINFO_V1_STATION_MC,
    TESTINFO_V1_STATION_COOKER,
#if defined(UART_API_HAVE_TESTINFO_V2)
    TESTINFO_V1_STATION_MT2,
    TESTINFO_V1_STATION_TEDC,
#endif
} TestV1Station_e;

#pragma pack(1)
typedef struct {
    unsigned char version  : 4;
#if defined(UART_API_HAVE_TESTINFO_V2)
    unsigned char ver_dummy: 1;
    unsigned char total    : 5;
    unsigned char reset    : 5;
    unsigned char bit      : 5;
    unsigned char mt       : 5;
    unsigned char cooker   : 5;
    unsigned char mt2      : 5;
    unsigned char tedc     : 5;

    unsigned char reserve1 : 5;
    unsigned char reserve2 : 5;
    unsigned char reserve3 : 5;
    unsigned char reserve4 : 5;
    unsigned char reserve5 : 5;
    unsigned char reserve6 : 5;
    unsigned char reserve7 : 5;
    unsigned char reserve8 : 5;

#else

    unsigned char total    : 4; //V1 only support max 16 station

    unsigned char reset    : 4;
    unsigned char bit      : 4;

    unsigned char mt       : 4;
    unsigned char cooker   : 4;
#endif

} TestInfoHeaer_st;
#pragma pack()

typedef struct {
    unsigned char data[TI_STA_BUF_SIZE - sizeof(TestInfoHeaer_st)];
} TestInfoData_st;

typedef struct {
    TestInfoHeaer_st    stHeader;
    TestInfoData_st     stData;
} TestInfoV1_st;

typedef struct {
    unsigned char u8Result;
} MobilityResult_st;

#define TESTINFO_ACTION_WRITE 1
#define TESTINFO_ACTION_INIT  0
// do not change, this struct size should < 4
typedef struct {
    unsigned char           action;
    union un_data {
        struct result_st {
            unsigned char u8Station;
            unsigned char u8Result;
        } Result_st;
        TestInfoHeaer_st    stHeader;
    } data;
} TestInfoCmd_st;

/*             motor             */
typedef struct {
    float fLineSpd;
    float fAngularSpd;
    int   s32Force;        //bit16-31:reserved  bit8-15:(0,vw_mode  1,vv_mode) bit0-7:(0,not force  1,force)
} WheelSpd_st;

typedef struct {
    int16_t leftSpd;        // degree/s
    int16_t rightSpd;       // degree/s
    int16_t pitchTarget;    // multi 100
    int16_t pitchRange;     // multi 100
    unsigned char u8Mode;   // 0: speed mode, 1: contact mode
    unsigned char u8Force;  // 1 force
} SwingArmCtrl_st;

typedef struct {
    unsigned short left_pose;  // degree * 10
    unsigned short right_pose; // degree * 10
    unsigned short left_current;
    unsigned short right_current;
    unsigned char left_motor_state;
    unsigned char right_motor_state;
    unsigned char contact_state;
} SwingStatus_st;

typedef enum {
    MOTOR_MODE_NORMAL       = 0x0,
    MOTOR_MODE_FORCE        = 0x1,
    MOTOR_MODE_MAX_NUM,
} MotorSpdMode_e;

/*   fan level   */
#define FAN_LEVEL_GO_HOME         (101)
#define FAN_LEVEL_QUIET           (102)
#define FAN_LEVEL_STANDARD        (103)
#define FAN_LEVEL_TURBO           (104)
#define FAN_LEVEL_COLLECT_DUST    (-105)
#define FAN_LEVEL_CARPET          (106)
#define FAN_LEVEL_MAX             (107)

#define CABINDOOR_MOTOR_DUTY 24

typedef struct {
    // used for fan/brush/sweep;
    // + or - means direction
    signed char s8Value;           //-100 ~ +100
    signed char s8Force;           // 0, normal; 1, force;
} MotorSpd_st;

typedef enum {
    STEERING_L = 0x1 << 0, //left steering
    STEERING_R = 0x1 << 1, //right steering
    STEERING_M = 0x1 << 2, //middle steering
} Steering_e;

#if defined(RR_DRV_HW_ONLY_UNIVERSAL_STEERING_MODULE)
#define STEERING_ID_MAP (STEERING_M)
#else
#define STEERING_ID_MAP (STEERING_L | STEERING_R | STEERING_M)
#endif

typedef struct {
    // used for steering;
    //     // only +
    unsigned char id;
    unsigned char isAngl;
    unsigned short u16LDuty; //0 ~ +1000
    unsigned short u16RDuty;
    unsigned short u16MDuty;
    signed short s16LAngl; //0 ~ +1000
    signed short s16RAngl;
    signed short s16MAngl;
} SteeringCtr_st;

typedef struct {
    unsigned short u16LIValue;
    unsigned short u16RIValue;
    unsigned short u16MIValue;
    unsigned char u8LSteerStatus;
    unsigned char u8RSteerStatus;
    unsigned char u8MSteerStatus;
    unsigned short u16LDuty; //0 ~ +1000
    unsigned short u16RDuty;
    unsigned short u16MDuty;
    short u16LAngl;
    short u16RAngl;
    short u16MAngl;
} Steering_st;

typedef struct {
    unsigned char id;
    unsigned short u16DownAngl;
    unsigned short u16DownDuty; //0 ~ +1000
    unsigned short u16UpAngl;
    unsigned short u16UpDuty;
} SteeringCli_st;

typedef struct {
    unsigned char u8Flag;
} MaskDrop_st;

typedef enum {
    CLIFF_TOF_OK      = 0x0000,
    CLIFF_TOF_ERROR   = 0x0010,
} CliffStatus_e;

typedef struct {
    unsigned char u8Id;
    unsigned short u16Status;
} CliffStatus_st;
typedef struct cmd_fan_spd_check {
    unsigned char u8Flag;
} FanSpdCheck_st;

typedef struct {
    unsigned short u16Value;
} MotorThreshold_st;

typedef struct {
    unsigned char u8Id;
} FanIdType_st;

typedef enum RR_DOCK_TYPE {
    RR_DOCK_TYPE_COMMON = 1,
    RR_DOCK_TYPE_O1,
    RR_DOCK_TYPE_O2,
    RR_DOCK_TYPE_O3,
    RR_DOCK_TYPE_O6,
    RR_DOCK_TYPE_SHELL3S,
    RR_DOCK_TYPE_NUM
} RR_DOCK_TYPE;

#ifdef UART_API_NEW_CHARGE_DEF
typedef enum RR_MAX_CURRENT {
    RR_DOCK_STOP = 0,
    RR_DOCK_MAX_CURRENT_0A = 1,  // POWERWAY_ADAPTOR_NO_CHARGE
    RR_DOCK_MAX_CURRENT_1A = 2,
    RR_DOCK_MAX_CURRENT_1A2 = 3,
    RR_DOCK_MAX_CURRENT_1A5 = 4,
    RR_DOCK_MAX_CURRENT_2A5 = 5,
    RR_DOCK_MAX_CURRENT_3A = 6,
    RR_DOCK_MAX_CURRENT_NUM = 7,
} RR_MAX_CURRENT;

typedef struct cmd_charge {
    unsigned short u16DockType;
    unsigned short u16Current;
} Charge_st;
#else
typedef struct {
    unsigned char u8Enable;
} Charge_st;
#endif

typedef struct cmd_charge_mode {
    unsigned char u8Soc;
} Charge_mode_st;


typedef enum {
    DEBUG_CLOSE_ALL                     = 0x0,        //0x00
    DEBUG_CLIFF                         = (0x1 << 1), //0x02
    DEBUG_MOTORS                        = (0x1 << 2), //0x04
    DEBUG_FAN_SPD                       = (0x1 << 3), //0x08
    DEBUG_DOCK                          = (0x1 << 4), //0x10
} DebugSwitch_e;

typedef struct {
    unsigned int u32Mask;
} DebugPara_st;


/*             comm             */
typedef struct {
    unsigned char      u8Request;
    unsigned char      u8Index;
} PKGItem_st;
#define PKG_IDX_SIZE           (SRC_MIN_SIZE + sizeof(PKGItem_st))

typedef struct {
    unsigned char u8Index;
} Answer_st;
typedef struct {
    char vP;
    char vI;
    char vD;
    char wP;
    char wI;
    char wD;
} PidTune_st;

#if defined(UART_API_HAVE_DOCK_DUST_COLLECTION)
typedef struct {
    unsigned short LeftVal;
    unsigned short SideVal;
    unsigned short RightVal;
    unsigned char  LeftStat[DOCK_STATUS_CODE_NUM];
    unsigned char  RightStat[DOCK_STATUS_CODE_NUM];
    unsigned char  SideStat[DOCK_STATUS_CODE_NUM];
    uint32_t rpt_tick;
} DockIR_st;

typedef struct {              //zero means none
    char as8Array[DOCK_IR_SENT_LEN];
} DockIRTx_st;
#elif defined(UART_API_HAVE_DOCK_CLEAN_MOPPING_CLOTH_AND_DUST_COLLECTION)
typedef struct {
    unsigned int LeftVal;
    unsigned int SideVal;
    unsigned int RightVal;
    unsigned int LeftBackVal;
    unsigned int RightBackVal;
    unsigned char LeftStat[DOCK_STATUS_CODE_NUM];
    unsigned char RightStat[DOCK_STATUS_CODE_NUM];
    unsigned char SideStat[DOCK_STATUS_CODE_NUM];
    unsigned char LeftBackStat[DOCK_STATUS_CODE_NUM];
    unsigned char RightBackStat[DOCK_STATUS_CODE_NUM];
    uint32_t rpt_tick;
} DockIR_st;

typedef struct {              //zero means none
    char as8Array[DOCK_IR_SENT_LEN];
} DockIRTx_st;
#else
typedef struct {
    unsigned char u8LeftVal;
    unsigned char u8SideVal;
    unsigned char u8RightVal;
    unsigned char u8Reserved;
    uint32_t rpt_tick;
} DockIR_st;
#endif

typedef enum {
    DOCK_INFO_TYPE_WIFI_PAIR            = 0x01,
    DOCK_INFO_TYPE_SN                   = 0x02,
} eDockIRTxInfoType;

#define DOCK_IR_INFO_LENTH      (64-1)
typedef struct __DOCKIRTXINFO_ST__  {
    unsigned char InfoType;
    unsigned char Info[DOCK_IR_INFO_LENTH];
} DockIRTxInfo_st;

typedef struct {
    char u8MopSwitchMode;
    char u8MopWSDis;
    char u8SwitchSPD;
} MopSwitch_st;

#define RUA_MCU_HEATBEAT_DISABLE (~0)
typedef struct {
    unsigned int u32HeartBeatInterval;
} HeartBeat_st;

/*fowllowing structure for xxx_NAV_CACHE_DATA_ID
   used to back up Navigation data
*/
typedef struct {
    float f32NavX;      //set by ap, just to save it
    float f32NavY;      //set by ap, just to save it
    float f32NavYaw;    //set by ap, just to save it
    float f32DetaYaw;   //unit: degree, start accumulate deta Yaw from 0 each time AP set new data here
} NavCacheData_st;
/*end of xxx_NAV_CACHE_DATA_ID */

/* for xxx_AP_CACHE_BUFF_ID */
#define AP_CACHE_SIZE   (16)
typedef struct {
    unsigned char u8CacheOffset;
    unsigned char u8Size;     // size in bytes
    /* followed by u8sSize bytes data, AP_CACHE_SIZE bytes in maxium */
} APCache_st;
/* end of xxx_AP_CACHE_BUFF_ID */

typedef struct {
    unsigned short u16Times;
} ChargingCycle_st;


typedef enum {
    RESET_ACTION_NONE                   = 0x0,
    RESET_ACTION_UPGRADE                = 0x1,
    RESET_ACTION_RECOVERY               = 0x2,
    RESET_ACTION_WATCHDOG               = 0x3,
    RESET_ACTION_AP                     = 0x4, //restart ap
} ResetAction_e;

typedef struct {
    unsigned short u8Action;
} ResetAction_st;

/* cali info */
typedef struct {
    unsigned short u16CliffThreshold[UART_API_HAVE_CLIFF];
    float f32WSCali;
    float f32GyroSensRatio;
    signed int s32AccCali[3];
    signed short i16GyroOffGain[6]; //for bmi323 self calibration result
} FacCaliInfo_st;

typedef struct {
    unsigned short int clr_pid_cmd;
} ClearPidPara_st;

/*             upgrade             */
typedef enum {
    UPGRADE_RESET                                      = 0x40,
    UPGRADE_PREPARE                                    = 0x41,
    UPGRADE_INFO                                       = 0x42,
    UPGRADE_READY                                      = 0x43,
    UPGRADE_SENT_OVER                                  = 0x44, //sent to mcu:
    UPGRADE_CONFIRM                                    = 0x45,

    UPGRADE_QUIET_RESET                                = 0x60,
} Upgrade_e;
#define UPGRADE_MAGIC "upgrade"
#define UPGRADE_MAGIC_MAX_LEN   (7)

typedef struct {
    //magic should be: "upgrade"
    char  magic[UPGRADE_MAGIC_MAX_LEN];
    unsigned char  u8Val;   /* Upgrade_e */
} Upgrade_st;

#define FACTORY_PARA_MAXSIZE     256
#define SECRET_CODE_PARA_MAXSIZE 100


#ifdef RR_AUTO_TEST
enum __rr_at_channel {
    RR_AT_CHANNEL_BAT_TEMP = 0x0,
    RR_AT_CHANNEL_BAT_WAIT_TIME = 0x1,
    RR_AT_CHANNEL_MAX,
};
#define RR_AT_INFO_INVALID_VALUE        0xFFFF

typedef struct __rr_at_info {
    unsigned short channel;
    unsigned short value;
    unsigned short isVolatile;
} RR_AT_INFO;

#endif

typedef struct {
    int s32Value;
    struct {
        unsigned short cfg_item;
        unsigned short flags;
    } ctrl;
} CfgInfo_st;

/*ap set mcu info item*/
typedef enum {
    BRUSH_F_OC_HF_ID              = 0x01,
    BRUSH_B_OC_HF_ID              = 0x02,
    BRUSH_OC_WARN_ID              = 0x03,
    BRUSH_MEDIUM_THRESHOLD_ID     = 0x04,
    MCU_LOG_LEVEL_ID              = 0x05,
    SPIN_RAG_OC_ID                = 0x06,//Unit: mA
    SPIN_RAG_OC_DUR_ID            = 0x07,//Unit: ms
    SPIN_RAG_OC_WARN_ID           = 0x08,//Unit: mA
    SPIN_RAG_OC_WARN_DUR_ID       = 0x09,//Unit: min
    SPIN_RAG_OC_WASH_WARN_ID      = 0x0A,//Unit: mA
#ifdef UART_API_HAVE_CFG_PARAM_DEBUG
    SWEEP_OC_HIGH_FAST_ID         = 0x33,//Unit: mA
    SWEEP_OC_HIGH_SLOW_ID         = 0x34,//Unit: mA
    SWEEP_OC_DUR_ID               = 0x35,//Unit: ms
    SPIN_RAG_STEP_F_DUR_ID        = 0x36, //Unit: ms
    SPIN_RAG_STEP_B_DUR_ID        = 0x37, //Unit: ms
    MOP_POS_ANTI_SHAKE_TIMES_UP_ID = 0x38, //Unit: ms
    MOP_OC_MAX_ID                  = 0x39, //Unit: ms
#endif
    PARAM_CFG_INFO_COUNT
} CfgInfo_e;

typedef enum {
    FAN_LEVEL_GO_HOME_PWM_ID      = 0x00,
    FAN_LEVEL_QUIET_PWM_ID        = 0x01,
    FAN_LEVEL_STANDARD_PWM_ID     = 0x02,
    FAN_LEVEL_TURBO_PWM_ID        = 0x03,
    FAN_LEVEL_COLLECT_DUST_PWM_ID = 0x04,
    FAN_LEVEL_CARPET_PWM_ID       = 0x05,
    FAN_LEVEL_MAX_PWM_ID          = 0x06,
#ifdef UART_API_HAVE_CFG_PARAM_DEBUG
    MOTOR_PARAM_BASE_ID               = 0x10,
    MOTOR_PARAM_SIDEMOP_OC_ID         = 0x11,
    MOTOR_PARAM_SIDEMOP_OC_WARN_ID    = 0x12,
    MOTOR_PARAM_MAX_ID                = 0x13,
#endif
    AP_PARAMS_CFG_INFO_COUNT
} ApParams_e;


#define RUA_CARPET_FRAME_SIZE    97
typedef struct  {
    unsigned char Data_buff[RUA_CARPET_FRAME_SIZE];
} RuaCarpetMessage_st;


#define  RUA_WHEEL_SECURE_STATE_INVALID 0x4d5ac898
#define  RUA_WHEEL_SECURE_STATE_OK      0xe1176a1f
#define  RUA_WHEEL_SECURE_MAGIC         0x79c75cfe

typedef union {
    unsigned char data[16];
    struct {
        unsigned int ts;
        unsigned int utc;
        unsigned int reserve;
        unsigned int state;
    } st;
} RuaWheelSecure_st;

typedef struct {
    char to_external_mcu : 1;
    char to_internal_mcu : 1;
} FlagSendDst_st;


/**************************/

#ifdef __cplusplus
extern "C" {
#endif
extern int package2src(const char *package, int size, char *src);
extern int src2package(const char *src, int size, char *package);
extern unsigned char crc8(const char *ptr, unsigned int len,
                          unsigned char crc_srand);
unsigned short crc16(const char *ptr, unsigned int len,
                     unsigned short crc_srand);

#define rua_comm_crc8 crc8
#define rua_comm_crc16 crc16
extern int get_next(char **raw_data, int *len, char **structp,
                    int *struct_size);
extern void ConverGyroOdo(GyroOdo_st *ptGyroOdo, GyroOdoCom_st *ptGyroOdoCom);
extern int rda_set_mcu_led(const CmdLed_st *stLeds, int need_ack);
extern int rda_set_mcu_led_light_level(int level, int need_ack);
extern const char *rua_devinfo_to_name(DevInfo_st *pD, DevInfoType_e eType);
extern const char *rua_motor_spd_mode_to_str(MotorSpdMode_e eMode);
extern int is_dock_ir_seperate_from_wallsensor();
#ifdef __cplusplus
}
#endif
#endif

