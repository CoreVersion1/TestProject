#ifndef __RUA_MODBUS_H__
#define __RUA_MODBUS_H__

#if defined(RR_HW_ENABLE_ARM_JOINT)

#ifdef __cplusplus
extern "C" {
#endif

// should be static assert > 7
// also joint index 0 is reserved
// and should not be used.
#define MAX_SLAVE_NUM (10)

// for angle set call, if any angle equals
// to the skip value, motor position should,
// not be changed
#define SLAVE_ANGLE_SKIP_VALUE (1000)

enum slave_id {
    MotorAll = 0,
    M1 = 1,
    M2,
    M3,
    M4,
    M5,
    M6,
    M7
};

typedef enum {
    ARM_NORMAL = 0x00,

    FaultHardOVCurrent = -999,    ///< 硬件过流
    FaultSoftOVCurrent = -998,    ///< 软件过流
    FaultOverVoltageDC = -997,    ///< 过压
    FaultUnderVoltageDC = -996,   ///< 欠压
    FaultPhaseLost = -995,        ///< 缺相
    FaultStall = -994,            ///< 堵转
    FaultStart = -993,            ///< 启动保护
    FaultOverTemperature = -992, ///< NTC过温保护
    FaultOverSpeed = -991,       ///< 堵转超速保护
    FaultLVW = -990,             ///< LVW
    FaultGetOffset = -989,       ///< 偏置电压保护
    FaultEmergency = -988,       ///< film switch triggerd
    FaultComm = -987,       ///< commmunication error
    FaultResetTimeout = -986,       ///< reset timeout

    // DATA_ABNORMAL = 0x33,
} ARM_JOINT_ERROR_CODE;

typedef enum {
    ARM_UPDATE_MOTOR_NONE = 0,
    ARM_UPDATE_MOTOR_1 = 1,
    ARM_UPDATE_MOTOR_2_3_FT = 2,
    ARM_UPDATE_MOTOR_2_3_GD = 3,
    ARM_UPDATE_MOTOR_4_FT = 4,
    ARM_UPDATE_MOTOR_5_6_GD = 5,
    ARM_UPDATE_MOTOR_4_5_6_GD = 6,
    ARM_UPDATE_MOTOR_MAX = 7,

    ARM_UPDATE_MOTOR_ALL = 0xFF,
} arm_update_motorId_e;

typedef enum {
    ARM_UPDATE_OK = 0,
    ARM_UPDATE_ERR_FLASH = -1,
    ARM_UPDATE_ERR_FILE_INVALID = -2,
} arm_update_err_e;

typedef enum {
    R50 = 0x55
} ARM_JOINT_MODLE;

typedef enum {
    ARM_POSITON_CURRENT_ELOCITY = 0x01,
    ARM_CURRENT_VELOCITY,
    ARM_CURRENT
} ARM_CTRL_MODE;

typedef struct {
    unsigned int interval; /* callback frequency; In milliseconds */
    void *reserved;        /* cancel event */
    void *call_data;
    void (*update)(void *call_data, float angles[MAX_SLAVE_NUM]);
} callback_args;

typedef struct {
    float k_value_m3;
    float k_value_m4;
    float reserve[28];
} arm_k_value_st;

typedef struct {
    int m1_time;
    int m2_time;
} time_report_st;

extern int rua_arm_set_callback(const callback_args
                                *cb); //call it after rua_arm_joint_init
extern int rua_arm_joint_init(ARM_JOINT_MODLE model);
extern int rua_arm_joint_exit();
extern int rua_arm_joint_angle_get(float *m1_angle, float *m3_angle,
                                   float *m4_angle);
extern int rua_arm_joint_angle_set(float m1_angle, float m3_angle,
                                   float m4_angle);
extern int rua_arm_joint_m6_distance_set(int distance); //0: close 35:open
extern int rua_arm_joint_common_angle_set(int slave_id, float angle);
extern int rua_arm_joint_angle_set_with_current(int slave_id, float angle);
extern int rua_arm_joint_angle_set_with_m3m4cur(int slave_id, float angle,
        uint16_t *cur_num, float curfbkM3[500], float curfbkM4[500]);
extern int rua_arm_joint_common_angle_get(int slave_id, float *angle);
extern int rua_arm_joint_out(time_report_st *time_report);
extern int rua_arm_joint_in(time_report_st *time_report);
extern int rua_common_set_zero(int slave_id);
extern int rua_current_protection(int slave_id, unsigned short current,
                                  unsigned short over_time);
extern int rua_temp_protection(int slave_id, unsigned char temp,
                               unsigned short over_time);
extern int rua_set_m6_speed(unsigned short speed);
extern int rua_get_m6_speed(void); //return M6 speed

extern int rua_arm_joint_current_get(int slave_id, float *current);
extern int rua_arm_joint_avg_current_get(int slave_id, float *avgCurrent,
        float *maxCurrent);
extern int rua_arm_joint_all_temp_get(unsigned short *m1_temp,
                                      unsigned short *m3_temp,
                                      unsigned short *m4_temp);

extern int rua_arm_joint_angle_async_set(float m1_angle, float m3_angle,
        float m4_angle);
extern int rua_arm_joint_common_angle_async_set(int slave_id, float angle);

extern void rua_arm_joint_set_m6_params(unsigned int grap_dis,
                                        unsigned int max_close_value); //call it after rua_arm_joint_init
extern unsigned int rua_arm_joint_get_m6_grap_max_dis(void);

extern int rua_motor_ctrl(int slave_id, int en);

extern int rua_set_arm_ctrlmode(ARM_CTRL_MODE mode, int slave_id);

extern int rua_set_arm_speed_limit(int slave_id, int speed); //speed: rpm

extern int rua_arm_joint_speed_get(int slave_id);

extern int rua_clear_motor_error(int slave_id);

//extern ARM_JOINT_ERROR_CODE rua_get_motor_errorcode(int slave_id);

extern int rua_set_arm_k_value(arm_k_value_st *k_value);

extern int rua_get_arm_k_value(arm_k_value_st *k_value);

extern int rua_arm_joint_fwver(int slave_id, uint16_t *plan,
                               uint32_t *build_time);
extern int rua_arm_joint_hall_get(uint16_t *hall_pos);

extern int rua_arm_joint_bte_get(int slave_id, uint16_t *bte);

extern int rua_arm_joint_runtime_get(int slave_id, uint16_t *run_time);

extern int rua_arm_update_firmware_fortior(uint8_t board_id,
        const unsigned char *data, unsigned int data_size, uint32_t cur_fwver);
extern int rua_arm_update_firmware_gd(uint8_t board_id,
                                      const unsigned char *data, unsigned int data_size, uint32_t cur_fwver);

extern int upgrade_arm_joint_dev(void);

extern int rua_arm_joint_calibration_write(int slave_id,
        uint16_t *calibration_data);
extern int rua_arm_joint_calibration_read(int slave_id,
        uint16_t *calibration_data);
extern int rua_arm_joint_common_m1m2m6_angle_set(int slave_id, float angle,
        uint16_t *bte, uint16_t *cur_num, uint16_t curfbk[1000]);

#ifdef __cplusplus
}
#endif

#endif
#endif
