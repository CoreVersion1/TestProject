
#ifndef __PAA5102_AP_MOUSE__
#define __PAA5102_AP_MOUSE__

#ifdef __cplusplus
extern "C" {
#endif

/********************************** reg *************************************/
#define PAA5102_REG_PID1                0x00
#define PAA5102_REG_PID2                0x01
#define PAA5102_REG_MOTION_STAT         0x02
#define PAA5102_REG_DELTA_XL            0x03
#define PAA5102_REG_DELTA_YL            0x04
#define PAA5102_REG_CONFIG              0x06
#define PAA5102_REG_WRITE_PROTECT       0x09
#define PAA5102_REG_DELTA_XH            0x11
#define PAA5102_REG_DELTA_YH            0x12
#define PAA5102_REG_SHUTTER             0x15
#define PAA5102_REG_PWM_ON              0x25
#define PAA5102_REG_RESET_EXP           0x5D
#define PAA5102_REG_LD_SRC              0x51
#define PAA5102_REG_CLOSE_ALL           0x53
#define PAA5102_REG_FRAME_AVG           0x61
#define PAA5102_REG_QRD                 0x6F
#define PAA5102_REG_IQH                 0x75
#define PAA5102_REG_IQL                 0x76
/********************************** reg val *************************************/
#define PAA5102_VAL_PID1                0x31
#define PAA5102_VAL_PID2                0x61
#define PAA5102_VAL_RESET               0x80
#define PAA5102_VAL_WP                  0x5A
#define PAA5102_VAL_LD                  0x06
#define PAA5102_VAL_PWR                 0x2E
#define PAA5102_VAL_RST1                0x3E
#define PAA5102_VAL_RST2                0x3F
#define PAA5102_VAL_CLOSE               0x01

/********************************** base set *************************************/
#define PAA5102_MOUSE_THREAD_NAME               "light_mouse_input"
#define PAA5102_MOUSE_DEV_NAME                  "/dev/spidev2.0"
#define PAA5102_MOUSE_PULLING_TIME              2
/********************************** gpio set *************************************/
/* GPIO_NUM = PIN_BASE + NUMBER, PH8->(32*7+8), sunxi-gpio.h */
#define PAA5102_GPIO_MOUSE_NCS                  (224+8)
#define PAA5102_GPIO_MOUSE_LED                  (224+7)

enum
{
    PAA5102_MOUSE_GRAB_READ_1ST = 1,
    PAA5102_MOUSE_GRAB_READ_MID = 2,
    PAA5102_MOUSE_GRAB_READ_NO_DATA = 3,
    PAA5102_MOUSE_GRAB_PARAM_ERR = 4,
};

typedef struct {
    signed short s16DeltaX;
    signed short s16DeltaY;
    unsigned short u16ImageQuality;    //s32AmplitudeVal
    unsigned char u8Shutter;
    unsigned char u8LTSrc;
    unsigned char u8FrameAvg;
    unsigned char u8Status;
    unsigned char u8Qrd;
    unsigned char u8Dirty;
    unsigned char mouse_valid_cnt;
} paa5102_optical_data_st;

uint8_t paa5102_optical_read_reg(uint8_t reg_addr);
Mouse_st *paa5102_get_mouse_data();
void paa5102_optical_pixel_grab_setting(void);
void paa5102_optical_pixel_grab_restore(void);
int paa5102_optical_pixel_grab_reading(uint8_t *buf);
void paa5102_optical_pixel_grab_read_reset(void);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* __PAA5102_AP_MOUSE__ */