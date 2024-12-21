#ifndef __RR_AP_MOTOR_H_
#define __RR_AP_MOTOR_H_

#if defined(__cplusplus)
extern "C" {
#endif

#define SET_MOTOR_BUFFSER_SIZE                              _IOW(0xbb, 0xF0, int)
#define SET_BATTERT_VOLTAGE                                 _IOW(0xbb, 0xF1, int)

#define SET_SWEEP_STRETCH_LIFT_STRETCH_OUT                  _IO(0xbb, 0x1)
#define SET_SWEEP_STRETCH_LIFT_PULL_BACK                    _IO(0xbb, 0x2)
#define SET_SWEEP_STRETCH_LIFT_RISE_UP                      _IO(0xbb, 0x3)
#define SET_SWEEP_STRETCH_LIFT_FALL_DOWN                    _IO(0xbb, 0x4)
#define SET_SWEEP_STRETCH_LIFT_STOP                         _IO(0xbb, 0x5)
#define SET_SWEEP_STRETCH_LIFT_PHASE_PWM_DUTY               _IOW(0xbb, 0x6, int)
#define SET_SWEEP_STRETCH_LIFT_MODE_PWM_DUTY                _IOW(0xbb, 0x7, int)
#define SET_SWEEP_STRETCH_LIFT_SENSOR_ENABLE                _IO(0xbb, 0x8)
#define SET_SWEEP_STRETCH_LIFT_SENSOR_DISABLE               _IO(0xbb, 0x9)
#define SET_SWEEP_STRETCH_LIFT_OC_VALUE                     _IOW(0xbb, 0xA, int)

#define SET_BRUSH_LIFT_RISE_UP                              _IO(0xbb, 0x10)
#define SET_BRUSH_LIFT_FALL_DOWN                            _IO(0xbb, 0x11)
#define SET_BRUSH_LIFT_STOP                                 _IO(0xbb, 0x12)
#define SET_BRUSH_LIFT_PHASE_PWM_DUTY                       _IOW(0xbb, 0x13, int)
#define SET_BRUSH_LIFT_MODE_PWM_DUTY                        _IOW(0xbb, 0x14, int)

#define SET_WASTE_WATER_PUMP                                _IO(0xbb, 0x20)
#define SET_WASTE_WATER_DRAIN                               _IO(0xbb, 0x21)
#define SET_WASTE_WATER_STOP                                _IO(0xbb, 0x22)
#define SET_WASTE_WATER_MOTOR_PHASE_PWM_DUTY                _IOW(0xbb, 0x23, int)
#define SET_WASTE_WATER_MOTOR_MODE_PWM_DUTY                 _IOW(0xbb, 0x24, int)

#define SET_LDS_LIFT_RISE_UP                                _IO(0xbb, 0x30)
#define SET_LDS_LIFT_FALL_DOWN                              _IO(0xbb, 0x31)
#define SET_LDS_LIFT_STOP                                   _IO(0xbb, 0x32)
#define SET_LDS_LIFT_PHASE_PWM_DUTY                         _IOW(0xbb, 0x33, int)
#define SET_LDS_LIFT_MODE_PWM_DUTY                          _IOW(0xbb, 0x34, int)
#define SET_LDS_LIFT_NEED_NEED_STEPS_AFTER_DET              _IOW(0xbb, 0x35, int)

#define SET_SIDEMOP_STRETCH_STRETCH_OUT                     _IO(0xbb, 0x40)
#define SET_SIDEMOP_STRETCH_PULL_BACK                       _IO(0xbb, 0x41)
#define SET_SIDEMOP_STRETCH_STOP                            _IO(0xbb, 0x42)
#define SET_SIDEMOP_STRETCH_PHASE_PWM_DUTY                  _IOW(0xbb, 0x43, int)
#define SET_SIDEMOP_STRETCH_MODE_PWM_DUTY                   _IOW(0xbb, 0x44, int)

#define SET_SIDEMOP_LIFT_RISE_UP                            _IO(0xbb, 0x50)
#define SET_SIDEMOP_LIFT_FALL_DOWN                          _IO(0xbb, 0x51)
#define SET_SIDEMOP_LIFT_STOP                               _IO(0xbb, 0x52)
#define SET_SIDEMOP_LIFT_PHASE_PWM_DUTY                     _IOW(0xbb, 0x53, int)
#define SET_SIDEMOP_LIFT_MODE_PWM_DUTY                      _IOW(0xbb, 0x54, int)
#define SET_SIDEMOP_LIFT_OC_VALUE                           _IOW(0xbb, 0x55, int)
#define SET_SIDEMOP_LIFT_OC_WARN_VALUE                      _IOW(0xbb, 0x56, int)

#define SET_ARM_DOOR_RISE_UP                                _IO(0xbb, 0x60)
#define SET_ARM_DOOR_FALL_DOWN                              _IO(0xbb, 0x61)
#define SET_ARM_DOOR_STOP                                   _IO(0xbb, 0x62)
#define SET_ARM_DOOR_PHASE_PWM_DUTY                         _IOW(0xbb, 0x63, int)
#define SET_ARM_DOOR_MODE_PWM_DUTY                          _IOW(0xbb, 0x64, int)

#define SET_RIGHT_WHEEL_LIFT_RISE_UP                        _IO(0xbb, 0x65)
#define SET_RIGHT_WHEEL_LIFT_FALL_DOWN                      _IO(0xbb, 0x66)
#define SET_RIGHT_WHEEL_LIFT_STOP                           _IO(0xbb, 0x67)
#define SET_RIGHT_WHEEL_RISE_UP_DUTY                        _IOW(0xbb, 0x68, int)
#define SET_RIGHT_WHEEL_FALL_DOWN_DUTY                      _IOW(0xbb, 0x69, int)

#define SET_UNIVERSAL_WHEEL_LIFT_RISE_UP                    _IO(0xbb, 0x6A)
#define SET_UNIVERSAL_WHEEL_LIFT_FALL_DOWN                  _IO(0xbb, 0x6B)
#define SET_UNIVERSAL_WHEEL_LIFT_STOP                       _IO(0xbb, 0x6C)
#define SET_UNIVERSAL_WHEEL_RISE_UP_DUTY                    _IOW(0xbb, 0x6D, int)
#define SET_UNIVERSAL_WHEEL_FALL_DOWN_DUTY                  _IOW(0xbb, 0x6E, int)

#define SET_BACKUNIVERSAL_WHEEL_LIFT_RISE_UP                _IO(0xbb, 0x70)
#define SET_BACKUNIVERSAL_WHEEL_LIFT_FALL_DOWN              _IO(0xbb, 0x71)
#define SET_BACKUNIVERSAL_WHEEL_LIFT_STOP                   _IO(0xbb, 0x72)
#define SET_BACKUNIVERSAL_WHEEL_LIFT_PHASE_PWM_DUTY         _IOW(0xbb, 0x73, int)
#define SET_BACKUNIVERSAL_WHEEL_LIFT_MODE_PWM_DUTY          _IOW(0xbb, 0x74, int)

#define SET_LEFT_WHEEL_LIFT_RISE_UP                         _IO(0xbb, 0x75)
#define SET_LEFT_WHEEL_LIFT_FALL_DOWN                       _IO(0xbb, 0x76)
#define SET_LEFT_WHEEL_LIFT_STOP                            _IO(0xbb, 0x77)
#define SET_LEFT_WHEEL_RISE_UP_DUTY                         _IOW(0xbb, 0x78, int)
#define SET_LEFT_WHEEL_FALL_DOWN_DUTY                       _IOW(0xbb, 0x79, int)

#define SET_SWEEP_RUN_FORWARD                               _IO(0xbb, 0x80)
#define SET_SWEEP_RUN_REVERSE                               _IO(0xbb, 0x81)
#define SET_SWEEP_STOP                                      _IO(0xbb, 0x82)
#define SET_SWEEP_PHASE_PWM_DUTY                            _IOW(0xbb, 0x83, int)
#define SET_SWEEP_MODE_PWM_DUTY                             _IOW(0xbb, 0x84, int)
#define GET_SWEEP_GET_HALL_I2C_VALUE                        _IOR(0xbb, 0x85, int)
#define GET_SWEEP_GET_HALL_MAX_VALUE                        _IOR(0xbb, 0x86, int)

#define SET_CLAMP_RISE_UP                                   _IO(0xbb, 0x90)
#define SET_CLAMP_FALL_DOWN                                 _IO(0xbb, 0x91)
#define SET_CLAMP_STOP                                      _IO(0xbb, 0x92)
#define SET_CLAMP_PHASE_PWM_DUTY                            _IOW(0xbb, 0x93, int)
#define SET_CLAMP_MODE_PWM_DUTY                             _IOW(0xbb, 0x94, int)

#ifdef UART_API_HAVE_AP_STEERING_MODULE
#define GET_STEER_WHEELS_LIFT_CALI_ANGLE                   _IOR(0xbb, 0x95, struct steering_calibrate_data)
#define SET_STEER_WHEELS_LIFT_DO_CALI                       _IOW(0xbb, 0x96, uint16_t)
#define GET_STEER_WHEELS_CALI_DATA                          _IOW(0xbb, 0x97, uint16_t)
//#define SET_STEER_WHEELS_LIFT_CALI_SYNC                   _IOW(0xbb, 0x97, struct steering_calibrate_data)
#define SET_SREER_REPORT_SELECT                             _IOW(0xbb, 0xB7, int)
#define GET_SREER_LEFT_WHEEL_ANGLE_ADC                      _IOR(0xbb, 0xB8, uint16_t)
#define GET_SREER_RIGHT_WHEEL_ANGLE_ADC                     _IOR(0xbb, 0xB9, uint16_t)
#define GET_SREER_UNIVER_WHEEL_ANGLE_ADC                    _IOR(0xbb, 0xBA, uint16_t)
#endif

#ifdef RR_DRV_HW_CPU_FAN
#define SET_CPU_FAN_DUTY                                    _IOW(0xbb, 0x98, int)
#define GET_CPU_FAN_DUTY                                    _IOW(0xbb, 0x99, int)
#endif

#define SET_CABINDOOR_RUN_CLOSE                             _IO(0xbb, 0xa0)
#define SET_CABINDOOR_RUN_OPEN                              _IO(0xbb, 0xa1)
#define SET_CABINDOOR_STOP                                  _IO(0xbb, 0xa2)
#define SET_CABINDOOR_PHASE_PWM_DUTY                        _IOW(0xbb, 0xa3, int)
#define SET_CABINDOOR_MODE_PWM_DUTY                         _IOW(0xbb, 0xa4, int)

#define SET_AT_LEFT_WHEEL_RISE_UP_DUTY                         _IOW(0xbb, 0xa5, int)
#define SET_AT_RIGHT_WHEEL_RISE_UP_DUTY                        _IOW(0xbb, 0xa6, int)
#define SET_AT_UNIVERSAL_WHEEL_RISE_UP_DUTY                    _IOW(0xbb, 0xa7, int)

#define SET_RAG_STRETCH_STRETCH_OUT                  _IO(0xbb, 0xB0)
#define SET_RAG_STRETCH_PULL_BACK                    _IO(0xbb, 0xB1)
#define SET_RAG_STRETCH_STOP                         _IO(0xbb, 0xB2)
#define SET_RAG_STRETCH_PHASE_PWM_DUTY               _IOW(0xbb, 0xB3, int)
#define SET_RAG_STRETCH_MODE_PWM_DUTY                _IOW(0xbb, 0xB4, int)
#define SET_RAG_STRETCH_SENSOR_ENABLE                _IO(0xbb, 0xB5)
#define SET_RAG_STRETCH_SENSOR_DISABLE               _IO(0xbb, 0xB6)



enum motor_id_e {
    MOTOR_ID_PULIC,
    MOTOR_ID_SWEEP_STRETCH_LIFT,
    MOTOR_ID_BRUSH_LIFT,
    MOTOR_ID_UNIVERSAL_WHEEL_LIFT,
    MOTOR_ID_BACKUNIVERSAL_WHEEL_LIFT,
    MOTOR_ID_LEFT_WHEEL_LIFT,
    MOTOR_ID_RIGHT_WHEEL_LIFT,
    MOTOR_ID_WASTE_WATER_RECYCLE,
    MOTOR_ID_SIDEMOP_LIFT,
    MOTOR_ID_SIDEMOP_STRETCH,
    MOTOR_ID_LDS_LIFT,
    MOTOR_ID_ARM_DOOR,
    MOTOR_ID_SWEEP,
    MOTOR_ID_CLAMP,
    MOTOR_ID_CABINDOOR,
    MOTOR_ID_RAG_STRETCH,
    MOTOR_ID_CPU_FAN_MOTOR,
    MOTOR_ID_MAX
};

#pragma pack(1)
struct steer_selfcal_resu_t {
    rua_id_t id;
    rua_st_t len;
    Answer_st data;
};
#pragma pack()

#pragma pack(1)
struct motor_info_t {
    rua_id_t id;
    rua_st_t len;
    Motor_st data;
};
#pragma pack()

#pragma pack(1)
struct steer_motor_info_t {
    rua_id_t id;
    rua_st_t len;
    Steering_st data;
};
#pragma pack()

#pragma pack(1)
struct steer_motor_calidata_t {
    rua_id_t id;
    rua_st_t len;
    SteeringCli_st data;
};
#pragma pack()

#pragma pack(1)
struct ap_motor_cmd_t {
    enum motor_id_e motor_id;
    int cmd;
    int *p_data;
};
#pragma pack()

struct motor_mmap_fifo_t {
    struct rua_fifo fifo;
#if defined(UART_API_HAVE_AP_STEERING_MODULE)
    struct rua_fifo steerfifo;
#endif
    int state_ready;
    int data_timeout;
};
#ifdef UART_API_HAVE_AP_STEERING_MODULE

typedef enum {
    STEERING_L_DOWN_ADC_INDEX = 0x0,
    STEERING_R_DOWN_ADC_INDEX = 0x1,
    STEERING_M_DOWN_ADC_INDEX = 0x2,
    STEERING_L_UP_ADC_INDEX = 0x3,
    STEERING_R_UP_ADC_INDEX = 0x4,
    STEERING_M_UP_ADC_INDEX = 0x5,
    STEERING_ADC_MAX_INDEX  = 0x6,
} SteeringAngle_e;

struct steering_calibrate_data {
    unsigned char data_sync;
    unsigned short g_u16steer_adc[STEERING_ADC_MAX_INDEX];
};
enum __tag_Test_Steer_Id__ {
    TEST_STEER_ID_L = 0,
    TEST_STEER_ID_R = 1,
    TEST_STEER_ID_M = 2,
    TEST_STEER_ID_MAX = 3,
};
typedef enum {
    STEERING_ANGLE_ID = 0,
    STEERING_DUTY_ID,
    SEERING_CLI_NUM,
} SteeringCli_e;
typedef enum {
    STEERING_LEFT = 0,
    STEERING_RIGHT = 1,
    STEERING_MID = 2,
    STEERING_NUM,
} steer_e;

typedef enum {
    STEER_CALI_DOWN_ANGLE = 0,
    STEER_CALI_DOWN_DUTY,
    STEER_CALI_UP_ANGLE,
    STEER_CALI_UP_DUTY,
    STEER_CALI_NUM,
} steering_cali_info_e;

#endif
int rr_ap_motor_init(enum motor_id_e dev_id);
void rr_ap_motor_exit(enum motor_id_e dev_id);
int rr_ap_motor_ioctl(enum motor_id_e dev_id, int cmd, void *p);

int ap_motor_get_pkgs(char *buf, int max_read);

#if defined(UART_API_HAVE_AP_STEERING_MODULE)
int ap_steering_module_get_pkgs(char *buf, int max_read);
int ap_steer_get_cal_pkgs(char *buf, int max_read);
int ap_steer_get_self_angle_cal_pkgs(char *buf, int max_read);
#endif

int ap_motor_set_brush_lift(const brushlist_cmd_t *dir_duty);
int rr_ap_sweep(MotorSpd_st *p_sweep_cmd_data);
int lift_lds_need_steps_after_det_set(int param);

#ifdef UART_API_HAVE_AP_STEERING_MODULE
int rr_ap_steer(SteeringCtr_st *p_steer_cmd_data);
int rr_ap_get_steer_self_cali_angle(void);
int rr_ap_get_steer_cali_data(SteeringCli_st *p_steer_clidata,
                              uint16_t rpt_cmd_id);
int open_create_cali_file(void);
int write_steer_angle_pwm_cali_file(unsigned int position, const char *p,
                                    unsigned int len);
int read_steer_angle_pwm_cali_file(unsigned int position, char *p,
                                   unsigned int len);
//int read_steer_cali_duty (uint8_t u8Id, uint8_t *u8DownDuty, uint8_t *u8DownAngle, uint8_t *u8UpDuty, uint8_t *u8UpAngle);
void steering_run_cmds(unsigned char u8Id, unsigned short u16LDuty,
                       unsigned short u16RDuty, unsigned short u16MDuty);
void at_steering_run_cmds(unsigned char u8Id, unsigned short u16LDuty,
                          unsigned short u16RDuty, unsigned short u16MDuty);
#endif

#ifdef UART_API_HAVE_AP_RAG_STRETCH_MOTOR
int rr_ap_stretch_rag(MotorSpd_st *p_stretch_rag_cmd_data);
#endif

int rr_ap_motor_config(ApParams_e id, int value);
#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif
