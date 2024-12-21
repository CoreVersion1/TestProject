

#ifndef __SWITCHES_H__
#define __SWITCHES_H__

#ifdef __cplusplus
extern "C" {
#endif

#define AP_SWITCH_VALID_FLAG_OFFSET  15
/* max 15 devs: bit1-bit15, valid flag: bit16 - bit30, bit0 and bit31 is invalid */
enum switch_dev_e {
	AP_SWITCH_INVALID = 0,
	AP_SWITCH_WATER_TANK,
	AP_SWITCH_RAG,
	AP_SWITCH_LDS_BUMPER,
	AP_SWITCH_DUSTBOX,
	AP_SWITCH_WATER_LEVEL,
	AP_SWITCH_DOCK_BUMPER,
	AP_SWITCH_SEWAGE_TANK,
	AP_SWITCH_RAG_L,
	AP_SWITCH_RAG_R,
	AP_SWITCH_BRAKE_DET_L,
	AP_SWITCH_BRAKE_DET_M,
	AP_SWITCH_BRAKE_DET_R,
	AP_SWITCH_RAG_LIGHT_L,
	AP_SWITCH_RAG_LIGHT_R,

	AP_SWITCH2_INVALID,
	AP_SWITCH_ARM_BUMPER,
	AP_SWITCH_ARM_AP_EMER,
	AP_SWITCH_ARM_MCU_WDO,
    AP_SWITCH_CABIN_BUMPER,

    AP_SWITCH_ALL,

	/*Add other GPIOs that only output here */
	AP_SWITCH_DOCK_IR_POWER = 116,
	AP_SWITCH_ANALOG_5V,           //117
	AP_SWITCH_SENSOR_POWER,        //118
	AP_SWITCH_BRAKE_NOTIFY_MCU,    //119
	AP_SWITCH_MOP_POWER,           //120
	AP_SWITCH_FAN_POWER,           //121
	AP_SWITCH_MOTOR_POWER,         //122
	AP_SWITCH_WHEEL_PWR_EN,        //123
	AP_SWITCH_MECH_ARM_PWR_EN,     //124
	AP_SWITCH_3V3C_DOOR_EN,        //125
	AP_SWITCH_BPWR_EN,             //126
};

#define    MOTOR_SWITCH_VALID_FLAG_OFFSET 15
enum motor_switch_dev_e {
    MOTOR_SWITCH_INVALID = 0,
    MOTOR_SWITCH_SWEEP_BUMPER,
    MOTOR_SWITCH_SWEEP_STRETCH_OUT,
    MOTOR_SWITCH_SWEEP_PULL_BACK,
    MOTOR_SWITCH_SWEEP_RISE_UP,
    MOTOR_RESEVE1,
    MOTOR_RESEVE2,
    MOTOR_SWITCH_BACKUNIVERSAL_WHEEL_LIFT_FALL_DOWN,
    MOTOR_SWITCH_UNIVERSAL_WHEEL_LIFT_FALL_DOWN,
    MOTOR_SWITCH_LEFT_WHEEL_LIFT_FALL_DOWN,
    MOTOR_SWITCH_RIGHT_WHEEL_LIFT_FALL_DOWN,
    MOTOR_SWITCH_SIDEMOP_RESERVE,
    MOTOR_SWITCH_SIDEMOP_STRETCH_OUT,
    MOTOR_SWITCH_SIDEMOP_PULL_BACK,
    MOTOR_SWITCH_SIDEMOP_RISE_UP,
    //new status
    MOTOR_SWITCH2_INVALID = 15,
    MOTOR_SWITCH_LDS_LIFT_FAULT,
    MOTOR_SWITCH_LDS_LIFT_RISE_UP,
    MOTOR_SWITCH_LDS_LIFT_FALL_DOWN,
    MOTOR_SWITCH_CLAMP_FAULT,
    MOTOR_SWITCH_CLAMP_RISE_UP,
    MOTOR_SWITCH_CABINDOOR_CLOSE,
    MOTOR_SWITCH_CABINDOOR_OPEN,
    MOTOR_SWITCH_ARM_DOOR_FAULT = 27,
    MOTOR_SWITCH_ARM_DOOR_RISE_UP,
    MOTOR_SWITCH_MAX,
};

#define BIT_SWITCH_ID_HEAD          30
#define SWITCH_BANK_0  0x0
#define SWITCH_BANK_1  0x1
#define SWITCH_BANK_2  0x2
#define SWITCH_BANK_3  0x3


struct switch_dev_t {
    int dev_fd;
    int data_fd;
    int stop;
    pthread_t pthread_fd;
    struct rua_fifo fifo;
    void *data;
};

#pragma pack(1)
struct switch_data_t {
    rua_id_t id;
    rua_st_t len;
    Sensor_u data;
};
#pragma pack()

typedef struct {
    tracking_data_id_t id;
    unsigned int data;
} Tracking_data_st;

#pragma pack(1)
struct tracking_event_t {
    rua_id_t id;
    rua_st_t len;
    Tracking_data_st data;
};
#pragma pack()

/*!
 * @macros SET_BIT(x, n)
 * @brief set the (n)th bit of (x) to 1.
 */
#ifndef SET_BIT
#define SET_BIT(x, n) do {x = (x | (1 << (n)));} while(0);
#endif

/*!
 * @macros CLEAR_BIT(x, n)
 * @brief set the (n)th bit of (x) to 0.
 */
#ifndef CLEAR_BIT
#define CLEAR_BIT(x, n) do {x = (x & (~(1 << (n))));} while(0);
#endif

#define SWITCH_DEV_NAME "/dev/rr_switch"
#define SWITCH_DATA_NAME "rr_switch_input"

#define SWITCH_DEVS_IOCTL    0xf9
#define SWITCH_IOCTL_GET_ALL_STA               _IOR(SWITCH_DEVS_IOCTL, 0x10, int)
#define SWITCH_IOCTL_SET_ALL_ENABLE            _IOW(SWITCH_DEVS_IOCTL, 0x11, int)
#define SWITCH_IOCTL_GET_WATER_TANK_STA        _IOR(SWITCH_DEVS_IOCTL, 0x12, int)
#define SWITCH_IOCTL_SET_WATER_TANK_ENABLE     _IOW(SWITCH_DEVS_IOCTL, 0x13, int)
#define SWITCH_IOCTL_GET_LDS_BUMPER_STA        _IOR(SWITCH_DEVS_IOCTL, 0x14, int)
#define SWITCH_IOCTL_SET_LDS_BUMPER_ENABLE     _IOW(SWITCH_DEVS_IOCTL, 0x15, int)
#define SWITCH_IOCTL_GET_RAG_STA               _IOR(SWITCH_DEVS_IOCTL, 0x16, int)
#define SWITCH_IOCTL_SET_RAG_ENABLE            _IOW(SWITCH_DEVS_IOCTL, 0x17, int)
#define SWITCH_IOCTL_GET_DUSTBOX_STA           _IOR(SWITCH_DEVS_IOCTL, 0x18, int)
#define SWITCH_IOCTL_SET_DUSTBOX_ENABLE        _IOW(SWITCH_DEVS_IOCTL, 0x19, int)
#define SWITCH_IOCTL_GET_WATER_LEVEL_STA        _IOR(SWITCH_DEVS_IOCTL, 0x1a, int)
#define SWITCH_IOCTL_SET_WATER_LEVEL_ENABLE     _IOW(SWITCH_DEVS_IOCTL, 0x1b, int)
#define SWITCH_IOCTL_GET_DOCK_BUMPER_STA        _IOR(SWITCH_DEVS_IOCTL, 0x1c, int)
#define SWITCH_IOCTL_SET_DOCK_BUMPER_ENABLE     _IOW(SWITCH_DEVS_IOCTL, 0x1d, int)
// #define SWITCH_IOCTL_GET_DOCK_IR_POWER_STA            _IOW(SWITCH_DEVS_IOCTL, 0x1e, int)
#define SWITCH_IOCTL_SET_DOCK_IR_POWER_ENABLE         _IOW(SWITCH_DEVS_IOCTL, 0x1f, int)
#define SWITCH_IOCTL_GET_SPINRAG_L_STA          _IOR(SWITCH_DEVS_IOCTL, 0x20, int)
#define SWITCH_IOCTL_SET_SPINRAG_L_ENABLE       _IOW(SWITCH_DEVS_IOCTL, 0x21, int)
#define SWITCH_IOCTL_GET_SPINRAG_R_STA          _IOR(SWITCH_DEVS_IOCTL, 0x22, int)
#define SWITCH_IOCTL_SET_SPINRAG_R_ENABLE       _IOW(SWITCH_DEVS_IOCTL, 0x23, int)
// #define SWITCH_IOCTL_GET_ANALOG_5V_STA          _IOW(SWITCH_DEVS_IOCTL, 0x24, int)
#define SWITCH_IOCTL_SET_ANALOG_5V_ENABLE       _IOW(SWITCH_DEVS_IOCTL, 0x25, int)
#define SWITCH_IOCTL_SET_SENSOR_POWER_ENABLE    _IOW(SWITCH_DEVS_IOCTL, 0x26, int)

#define SWITCH_IOCTL_GET_SEWAGE_TANK_STA        _IOR(SWITCH_DEVS_IOCTL, 0x27, int)
#define SWITCH_IOCTL_SET_SEWAGE_TANK_ENABLE     _IOW(SWITCH_DEVS_IOCTL, 0x28, int)
#define SWITCH_IOCTL_GET_BRAKE_DET_STA          _IOR(SWITCH_DEVS_IOCTL, 0x29, int)
#define SWITCH_IOCTL_SET_BRAKE_DET_STA_ENABLE   _IOW(SWITCH_DEVS_IOCTL, 0x2A, int)
#define SWITCH_IOCTL_SET_BRAKE_DET_TRIGGER_ACTION_ENABLE   _IOW(SWITCH_DEVS_IOCTL, 0x2B, int)
#define SWITCH_IOCTL_SET_BRAKE_DET_TRIGGER_ACTION_DISABLE  _IOW(SWITCH_DEVS_IOCTL, 0x2C, int)

#define SWITCH_IOCTL_GET_RAG_LIGHT_STA          _IOR(SWITCH_DEVS_IOCTL, 0x2D, int)
#define SWITCH_IOCTL_SET_RAG_LIGHT_ENABLE       _IOW(SWITCH_DEVS_IOCTL, 0x2E, int)


#define SWITCH_IOCTL_GET_SWEEP_BUMPER_STA                    _IOR(SWITCH_DEVS_IOCTL, 0x40, int)
#define SWITCH_IOCTL_SET_SWEEP_BUMPER_ENABLE                 _IOW(SWITCH_DEVS_IOCTL, 0x41, int)
#define SWITCH_IOCTL_GET_BRUSH_LIFT_STA                      _IOR(SWITCH_DEVS_IOCTL, 0x42, int)
#define SWITCH_IOCTL_SET_BRUSH_LIFT_ENABLE                   _IOW(SWITCH_DEVS_IOCTL, 0x43, int)
#define SWITCH_IOCTL_GET_WHEEL_LIFT_STA                      _IOR(SWITCH_DEVS_IOCTL, 0x44, int)
#define SWITCH_IOCTL_SET_WHEEL_LIFT_ENABLE                   _IOW(SWITCH_DEVS_IOCTL, 0x45, int)
#define SWITCH_IOCTL_SET_MOP_POWER_ENABLE                    _IOW(SWITCH_DEVS_IOCTL, 0x46, int)
#define SWITCH_IOCTL_SET_SWITCH_MOTOR_POWER                  _IOW(SWITCH_DEVS_IOCTL, 0x47, int)
#define SWITCH_IOCTL_GET_SIDEMOP_BUMPER_STA                  _IOR(SWITCH_DEVS_IOCTL, 0x48, int)
#define SWITCH_IOCTL_SET_SIDEMOP_BUMPER_ENABLE               _IOW(SWITCH_DEVS_IOCTL, 0x49, int)
#define SWITCH_IOCTL_SET_FAN_POWER_ENABLE                    _IOW(SWITCH_DEVS_IOCTL, 0x4A, int)
#define SWITCH_IOCTL_GET_LDS_LIFT_STA                        _IOR(SWITCH_DEVS_IOCTL, 0x4B, int)
#define SWITCH_IOCTL_SET_LDS_LIFT_ENABLE                     _IOW(SWITCH_DEVS_IOCTL, 0x4C, int)
#define SWITCH_IOCTL_GET_ARM_DOOR_STA                        _IOR(SWITCH_DEVS_IOCTL, 0x4D, int)
#define SWITCH_IOCTL_SET_ARM_DOOR_ENABLE                     _IOW(SWITCH_DEVS_IOCTL, 0x4E, int)
#define SWITCH_IOCTL_SET_SWITCH_WHEEL_PWR_EN                 _IOW(SWITCH_DEVS_IOCTL, 0x4F, int)
#define SWITCH_IOCTL_SET_SWITCH_MECH_ARM_PWR_EN              _IOW(SWITCH_DEVS_IOCTL, 0x50, int)
#define SWITCH_IOCTL_GET_CLAMP_STA                           _IOR(SWITCH_DEVS_IOCTL, 0x51, int)
#define SWITCH_IOCTL_SET_CLAMP_ENABLE                        _IOW(SWITCH_DEVS_IOCTL, 0x52, int)
#define SWITCH_IOCTL_GET_CABINDOOR_STA                       _IOR(SWITCH_DEVS_IOCTL, 0x53, int)
#define SWITCH_IOCTL_SET_CABINDOOR_ENABLE                    _IOW(SWITCH_DEVS_IOCTL, 0x54, int)
#define SWITCH_IOCTL_SET_SWITCH_3V3C_DOOR_EN                 _IOW(SWITCH_DEVS_IOCTL, 0x55, int)
#define SWITCH_IOCTL_SET_SWITCH_BPWR_EN                      _IOW(SWITCH_DEVS_IOCTL, 0x56, int)
#define SWITCH_IOCTL_GET_ARM_BUMPER_STA                      _IOR(SWITCH_DEVS_IOCTL, 0x57, int)
#define SWITCH_IOCTL_SET_ARM_BUMPER_ENABLE                   _IOW(SWITCH_DEVS_IOCTL, 0x58, int)
#define SWITCH_IOCTL_GET_ARM_AP_EMER_STA                     _IOR(SWITCH_DEVS_IOCTL, 0x59, int)
#define SWITCH_IOCTL_SET_ARM_AP_EMER_ENABLE                  _IOW(SWITCH_DEVS_IOCTL, 0x5A, int)
#define SWITCH_IOCTL_GET_ARM_MCU_WDO_STA                     _IOR(SWITCH_DEVS_IOCTL, 0x5B, int)
#define SWITCH_IOCTL_SET_ARM_MCU_WDO_ENABLE                  _IOW(SWITCH_DEVS_IOCTL, 0x5C, int)
#define SWITCH_IOCTL_GET_CABIN_BUMPER_STA                    _IOW(SWITCH_DEVS_IOCTL, 0x5D, int)
#define SWITCH_IOCTL_SET_CABIN_BUMPER_ENABLE                 _IOW(SWITCH_DEVS_IOCTL, 0x5E, int)

extern int ap_switch_init();
extern void ap_switch_uninit();
extern int ap_switch_get_pkgs(char *buf, int max_read);
extern int ap_switch_get_status(enum switch_dev_e type);
extern int set_ap_switch_enable(enum switch_dev_e type, int en);
extern int ap_switch_enable_all(int en);
extern int set_dockir_signal_power(int en);

//The bumper triggers the brake
int set_ap_brake_det_trigger_action_enable(enum switch_dev_e type);

//The bumper triggers but does not brake
int set_ap_brake_det_trigger_action_disable(enum switch_dev_e type);

int ap_motor_switch_get_status(enum motor_switch_dev_e type);

#ifdef UART_API_HAVE_AP_BRUSH_LIFT_DET
void ap_motor_switch_get_brushlift_status(int *gpio_status);
#endif

#ifdef __cplusplus
}
#endif
#endif

