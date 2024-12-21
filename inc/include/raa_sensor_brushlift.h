
#ifndef __brushlift_SWITCHES_H__
#define __brushlift_SWITCHES_H__

#ifdef __cplusplus
extern "C" {
#endif

struct brushlift_dev_t {
    int dev_fd;
    int data_fd;
    int stop;
    pthread_t pthread_fd;
    struct rua_fifo fifo;
    // struct rua_fifo switch_fifo;
    void *data;
    void *switchdata;
};

#define SMOP_MOTOR      0xF8
#define SMOP_IOCTL_SET_UP_STOP_DELAY _IOW(SMOP_MOTOR, 0x10, int)
#define SMOP_IOCTL_SET_DOWN_STOP_DELAY _IOW(SMOP_MOTOR, 0x11, int)
#define SMOP_IOCTL_GET_BOARD_ID  _IOR(SMOP_MOTOR, 0x18, int)

#ifndef BRUSHLIFT_DET_ON_MIDDLE
#define SMOP_IOCTL_SET_UP_OVERCOUNT_OVTIME  _IOW(SMOP_MOTOR, 0x13, int)

#define EVENT_SHIFT 0
#define EVENT_LENGTH 4

#define DATA_1_SHIFT (EVENT_SHIFT+EVENT_LENGTH)
#define DATA_1_LENGTH 12

#define DATA_2_SHIFT (DATA_1_SHIFT+DATA_1_LENGTH)
#define DATA_2_LENGTH 12

#define BOARD_ID_SHIFT (DATA_2_SHIFT+DATA_2_LENGTH)
#define BOARD_ID_LENGTH 1

#define IS_CAL_FLAG_SHIFT (BOARD_ID_SHIFT+BOARD_ID_LENGTH)
#define IS_CAL_FLAG_LENGTH 1

#define SWITCH_STATUS_SHIFT (IS_CAL_FLAG_SHIFT+IS_CAL_FLAG_LENGTH)
#define SWITCH_STATUS_LENGTH 1
#endif

#define VOL_MAX 16800

#define SMOP_IOCTL_GET_UP_STOP_DELAY _IOW(SMOP_MOTOR, 0x20, int)
#define SMOP_IOCTL_GET_DOWN_STOP_DELAY _IOW(SMOP_MOTOR, 0x21, int)

#ifdef BRUSHLIFT_DET_ON_MIDDLE
#ifdef BRUSHLIFT_DET_ON_MIDDLE_LIGHT_DET
struct Cal_data {
    unsigned int down_adc_threshold;
    unsigned int down_ms_threshold;
    unsigned int up_adc_threshold;
    unsigned int up_ms_threshold;
};
#define SMOP_IOCTL_SET_CAl  _IOW(SMOP_MOTOR, 0x15, int)
#define SMOP_IOCTL_GET_CAL  _IOR(SMOP_MOTOR, 0x25, int)
#endif
#else
struct Cal_data {
    unsigned short param1;
    unsigned short param2;
};
#endif

#define BRUSHLIFTNORMAL (0)
#define BRUSHLIFTMIDDLE (1)
#define BRUSHLIFTSWITCHSTOP (2)
#define BRUSHLIFTBLOCKSTOP (3)
#define BRUSHLIFTUNKNOW (4)
#define PERIOD 83333
#define CURRENT_OPEN_CIRCUIT 6
#define CURRENT_SHORT_CIRCUIT 40
#define CURRENT_MAX 900

#define BRUSHLIFT_DEV_NAME "/dev/smop_motor"
#define brushlift_DATA_NAME "smop_input"

#define brushlift_CAL_FILE "/mnt/data/brushlift_cal"
#define BRUSHLIFT_CAL_FILE_ON_RESERVE "/mnt/reserve/brushlift_cal"

extern int get_brushlift_switch_status(int *gpio_status);
extern int ap_brushlift_init();
extern void ap_brushlift_uninit();
extern int ap_brushlift_get_pkgs(char *buf, int max_read);
extern int enable_brush_lift_motor(const brushlist_cmd_t *dir_duty);
extern int brush_lift_stop_delay_cmd(brushlist_stop_delay_t *delay_cmd);
extern int get_brushlift_switch_status(int *board_id);
extern int get_brushlift_board_id(int *board_id);

#ifdef __cplusplus
}
#endif
#endif

