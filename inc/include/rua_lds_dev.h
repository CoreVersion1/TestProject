/* =============================================================================
#     FileName: rua_lds_dev.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2020-05-30 14:40:35
#      History: none
============================================================================= */

#ifndef __RUA_LDS_DEV_H__
#define __RUA_LDS_DEV_H__

#ifndef UART_API_HAVE_WITHOUT_LDS

#define UART_LDS_IOCTL    0x57
#define UART_LDS_IOCTL_SET_BUFFSER_SIZE _IOW(UART_LDS_IOCTL, 0x10, int)

#ifdef __cplusplus
extern "C" {
#endif


#define RUA_LDS_TTY_DEVICE            UART_API_KERNEL_DEVICE_LDS_NAME

#if defined(RR_DRV_HW_LDS_GIVEN_BAUDRATE)
#define RUA_LDS_BAUDRATE              RR_DRV_HW_LDS_GIVEN_BAUDRATE
#else
#define RUA_LDS_BAUDRATE              115200
#endif

#define RUA_LDS_DATA_WIDTH            8
#define RUA_LDS_PARITY                'N'
#define RUA_LDS_STOP_BIT              1
#define RUA_LDS_LOCK_UART             1


#define RUA_RUA_LDS_INFO_START            0xAA

#define RUA_LDS_MIN_NORMAL_RPM        270
#define RUA_LDS_MAX_NORMAL_RPM        330

#define RUA_LEDONG_60BF_LDS_MIN_NORMAL_RPM        570
#define RUA_LEDONG_60BF_LDS_MAX_NORMAL_RPM        630

#define RUA_LDS_BYTE_START            0xFA
#define RUA_LDS_ROUND_START_INDEX     0xA0
#define RUA_LDS_ROUND_END_INDEX       0xF9
#define RUA_LDS_COUNT_DATA            4
#define RUA_LDS_COUNT_INDEX           (360/RUA_LDS_COUNT_DATA)

#define RUA_LDS_FLAG_DATA_INVALID     0x8000
#define RUA_LDS_FLAG_DATA_INFINITY    0x4000
#define RUA_LDS_STRENGTH_WARNING      0x4000
#define RUA_LDS_FLAG_COVER_FILTER     0x2000
#define RUA_LDS_FLAG_SPEED_WARNING    0x1000
#define RUA_LDS_FLAG_MASK             0xf000
#define RUA_LDS_LEDONG_SPEED_UNSTABLE 0x4000

#define RUA_LDS_INFO_UID_SIZE         18
#define RUA_LDS_INFO_DSP_VERSION_SIZE 12
#define RUA_LDS_CALI_TABLE_SIZE       10


#define VI4302_PEAK_THRESHOLD_NEAR    6000 //Close distance threshold
#define VI4302_PEAK_THRESHOLD1_MID    6000 //8000 Strict threshold for middle distance
#define VI4302_PEAK_THRESHOLD2_MID    300  //1000 Loose threshold for mid-range
#define VI4302_PEAK_THRESHOLD_FAR     160  //long distance

#define VI4302_DIS_TOF_THRESHOLD 170     //mm, mid range and near range borders
#define VI4302_DIS_TOF_THRESHOLD1 1000   //mm, mid-range and long-range borders
// #if defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC)
// #define FLAG1_ANGLE      90
// #define FLAG2_ANGLE      228
// #define FLAG3_ANGLE      313

// #elif defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC)

// #define FLAG1_ANGLE      50
// #define FLAG2_ANGLE      146
// #define FLAG3_ANGLE      278
// #endif

#define RANGE_ANGLE      10  //Sphere of influence


typedef union {
    struct {
        unsigned char start_flag;
        unsigned char index;
        unsigned short speed;
        struct {
            union {

                struct {
                    unsigned short distance : 14;
                    unsigned short strength_warning : 1;
                    unsigned short invalid_data : 1;
                };

                unsigned short distance_holder;
            };
            unsigned short signal_strength;
        } data[4];
        unsigned short check_sum;
    } raw;
    unsigned char bytes[22];
} RuaLdsPacket_u;



#define RUA_CAMSENSE_HEADER_1  0x55
#define RUA_CAMSENSE_HEADER_2  0xAA
#define RUA_CAMSENSE_LDS_ANGLE_BEGIN 0xA000
#define RUA_CAMSENSE_LDS_ANGLE_END 0xF9FF


typedef union {
    struct {
        uint8_t header1;
        uint8_t header2;
        uint8_t info;
        uint8_t dn;
        uint16_t speed;
        uint16_t first_angle;
        struct __attribute__((packed))
        {
            union {
                struct {
                    uint16_t distance : 14;
                    uint16_t reserved : 1;
                    uint16_t invalid_data : 1;
                };
                uint16_t distance_holder;
            } distance;
            uint8_t reserved[2];
        } data[12];
        uint16_t last_angle;
        uint16_t check_sum;
    } raw;
    uint8_t bytes[60];
    uint16_t words[30];
} RuaCamsenseLDS_Packet;

typedef union {
    struct {
        uint8_t header1;
        uint8_t header2;
        uint8_t info;
        uint8_t dn;
        uint16_t speed;
        uint16_t first_angle;
        struct __attribute__((packed))
        {
            union {
                struct {
                    uint16_t distance : 14;
                    uint16_t unstable_speed : 1;
                    uint16_t invalid_data : 1;
                };
                uint16_t distance_holder;
            } distance;
            uint8_t reserved;
        } data[8];
        uint16_t last_angle;
        uint16_t check_sum;
    } raw;
    uint8_t bytes[36];
    uint16_t words[18];
} RuaLedongLDS_Packet;


typedef struct {
    unsigned short      word_0;
    unsigned short      word_1;
    unsigned short      word_2;
    unsigned short      word_3;
    unsigned short      word_4;
    unsigned short      word_5;
} RuaLdsDSPType_st;

typedef struct {
    unsigned short      distance;
    unsigned short      strength;
} RuaCaliTable_st;
#pragma pack(1)
typedef struct {
    unsigned char pitch_offset1: 6;
    unsigned char pitch_offset2: 6;
    unsigned char pitch_offset3: 6;
    unsigned char pitch_offset4: 6;
    unsigned char pitch_offset5: 6;
    unsigned char reserve: 2;
} Lds_pitch_offset_st;
#pragma pack()

typedef struct {
    unsigned short      packet_size;  //size 2
    unsigned short      software_version; //size 2
    unsigned short      uid_size; //size 2
    char                uid[RUA_LDS_INFO_UID_SIZE]; //size 18
    short               angle_offset; //size 2
    char                dsp_type[RUA_LDS_INFO_DSP_VERSION_SIZE]; //size 12
#ifdef UART_API_HAVE_AP_LDS_LIFT_MOTOR
    Lds_pitch_offset_st lds_pitch_angle_data; //size 4
#else
    unsigned short      light_plane; //size 2
    unsigned short      ld_power; //size 2
#endif
    RuaCaliTable_st     calibration_table[RUA_LDS_CALI_TABLE_SIZE]; //size 40
    unsigned short      check_sum; //size 2
} RuaLdsAttributes_st;

typedef union {
    RuaLdsAttributes_st lds_attributes;
    unsigned char       data_octal[84];
    unsigned short      data_hex[42];
} RuaLdsInfo_u;

enum lds_product_type {
    LDS_TYPE_INVALID_MIN        = 0,
    LDS_ASIA_OPTICAL_DEFAULT    = 1,
    LDS_ROBOROCK_EAGLE          = 2,
    LDS_CAMSENSE_X1S            = 3,
    LDS_ASIA_OPTICAL_G_1        = 4,
    LDS_ROBOROCK_QIUNIU         = 5,
    LDS_ROBOROCK_QIUNIU_R       = 6,
    LDS_CAMSENSE_D2S            = 7,
    LDS_CAMSENSE_UNICORN        = 8,
    LDS_LEDONG_STL26N           = 9,
    LDS_UNICORN2                = 10,
    //......
    LDS_TYPE_INVALID_MAX,
};

#define LDS_CAL_FILE UART_API_PARTITION_RESERVE_DIR"/lds_cal.ini"

/*  For Version Compatible Begin
 *  init_lds_mmap()                   --> rua_lds_uart_init()
 *  exit_lds_mmap()                   --> rua_lds_uart_close()
 *  clean_lds_mmap_cache()            --> rua_lds_uart_clean()
 *  read_lds_mmap_buf(buf, max_lengh) --> rua_lds_uart_get_raw(buf, max_read, 23)
 */
extern int init_lds_mmap();
extern void exit_lds_mmap();
extern void clean_lds_mmap_cache();
extern int read_lds_mmap_buf(char *buf, unsigned int max_read);
/*  For Version Compatible End  */


extern int rua_lds_uart_init();
extern void rua_lds_uart_close();
extern void rua_lds_uart_clean();

extern int rua_lds_uart_get_raw(char *buf, int max_lengh, int timeout_ms);
extern int rua_lds_uart_sent_raw(const char *buf, int len);
extern int rua_is_lds_inited();
/*******
 * para: //default block mode
 * -1: BLOCK
 * 0:  NOBLOCK
 * >0: BLOCK_TIMEOUT
******/
#define RUA_LDS_UART_BLOCK -1
#define RUA_LDS_UART_NOBLOCK 0
extern void rua_lds_uart_set_timeout_ms(int timeout);


#define RUA_LDS_PWM_DEVICE            "/dev/lds_motor"
#define RUA_LDS_PWM_IOCTL_MGIC        0xF8
#define RUA_LDS_PWM_IOCTL_SET_STD_SPEED    _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x10, int)
#define RUA_LDS_PWM_IOCTL_GET_STD_SPEED    _IOR(RUA_LDS_PWM_IOCTL_MGIC, 0x11, int)
#define RUA_LDS_PWM_IOCTL_SET_CUR_SPEED    _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x12, int)

#define RUA_LDS_PWM_IOCTL_SET_START        _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x13, int)
#define RUA_LDS_PWM_IOCTL_SET_STOP         _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x14, int)

#define RUA_LDS_PWM_IOCTL_SET_KP           _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x15, int)
#define RUA_LDS_PWM_IOCTL_SET_KI           _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x16, int)
#define RUA_LDS_PWM_IOCTL_SET_KD           _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x17, int)

#define RUA_LDS_PWM_IOCTL_SET_INIT_DUTY    _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x18, int)
#define RUA_LDS_PWM_IOCTL_SET_UPDATE_FREQ  _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x19, int)

#define RUA_LDS_PWM_IOCTL_GET_CUR_DUTY     _IOR(RUA_LDS_PWM_IOCTL_MGIC, 0x20, int)
#define RUA_LDS_PWM_IOCTL_SET_DUTY         _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x24, int)

#define RUA_LDS_PWM_IOCTL_SET_MODE         _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x23, int)
#define RUA_LDS_PWM_IOCTL_SET_CTRL_V       _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x25, int)

#define RUA_LDS_PWM_SET_PRODUCT_TYPE       _IOW(RUA_LDS_PWM_IOCTL_MGIC, 0x26, int)

extern int rua_lds_pwm_init();
extern void rua_lds_pwm_close();
extern int rua_is_pwm_inited();

extern int rua_lds_pwm_set_start(int speed);
extern int rua_lds_pwm_set_stop();
extern int rua_lds_pwm_set_speed(int speed);
extern int rua_lds_pwm_pid_set_pid(int kp, int ki, int kd);
extern int rua_lds_pwm_set_cur_speed(int speed);
extern int rua_lds_pwm_set_duty(int duty);
#ifdef UART_API_HAVE_RUBYS_LDS
extern int rua_lds_pwm_set_ctl_v(int value);
extern int rua_lds_pwm_set_mode(int value);
#endif

int rua_lds_uart_set_start(void);
int rua_lds_uart_set_stop(void);

extern int rua_lds_pwm_set_product_id(enum lds_product_type id);
extern int rua_lds_get_pid_from_uid(char uid);
extern int rua_lds_yaw_cal(char *uid, char *yaw, char *yaw_compensation,
                           char *yaw_range);
extern int rua_lds_check_yaw_cal_support_pid(int pid);

/*
    angle1 = (lds_conf.cover_filter.data[0] + lds_conf.cover_filter.data[1]) / 2;
    angle2 = (lds_conf.cover_filter.data[2] + lds_conf.cover_filter.data[3]) / 2;
    angle3 = (lds_conf.cover_filter.data[4] + lds_conf.cover_filter.data[5]) / 2;
*/
extern void rua_lds_set_qiuniu_cover_angle(short angle1, short angle2,
        short angle3);
/**
 * @brief  Check the validity of QIUNIU LDS data near retaining ribs
 * @param  [raw_tof] Ranging value
 * @param  [raw_peak] intensity value
 * @param  [raw_angle] Angle value
 * @return Valid is 1, invalid is 0
 */
extern unsigned int rua_lds_data_validity_check(unsigned int raw_tof,
        unsigned int raw_peak, unsigned int raw_angle);

#ifdef __cplusplus
}
#endif
#endif

#endif
