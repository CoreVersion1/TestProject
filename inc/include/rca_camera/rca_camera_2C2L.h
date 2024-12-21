#ifndef __RCA_CAMERA_2C2L_H__
#define __RCA_CAMERA_2C2L_H__

#include "rca_camera_eeprom_common.h"

struct CameraHeaderData {
    unsigned int image_timestamp;
    unsigned int channels;
    unsigned int single_size;
    unsigned int single_height;
    unsigned int single_width;
    unsigned char *datap[1];
    //pixel_type: 8U = 0, 8S = 1, 16U = 2, 16S = 3, 32S = 4, 32F = 5, 64F = 6
    unsigned int pixel_type;
    //img_flag: row-major = 0, col-major = 1, row-major-channel-last = 2, col-majo-channel-last = 3
    unsigned int img_flag;
    unsigned int frame_number;
    unsigned long long exposure_time;
    unsigned int sensitivity;
    rca_camera_type_e eType;
    unsigned int pwm_duty;
};
#define RCA_SINGLE_CAMERA_YUV_WIDTH     UART_API_CAMERA_YUV_W
#define RCA_SINGLE_CAMERA_YUV_HEIGHT    UART_API_CAMERA_YUV_H
#define RCA_MULTI_CAMERA_YUV_WIDTH      (RCA_SINGLE_CAMERA_YUV_WIDTH)
#define RCA_MULTI_CAMERA_YUV_HEIGHT     (RCA_SINGLE_CAMERA_YUV_HEIGHT)

#define RCA_SINGLE_CAMERA_GRAY_SIZE     (RCA_SINGLE_CAMERA_YUV_HEIGHT*RCA_SINGLE_CAMERA_YUV_WIDTH)
#define RCA_SINGLE_CAMERA_YUV_SIZE      (RCA_SINGLE_CAMERA_GRAY_SIZE)

#define RCA_CAMERA_MAX_SIZE             (RCA_MULTI_CAMERA_YUV_WIDTH*RCA_MULTI_CAMERA_YUV_HEIGHT)
#define CAMERA_MAX_NUM                  2
typedef enum {
    RCA_CAMERA_FRAME_LINE_L = 0,
    RCA_CAMERA_FRAME_CLOSE2,
    RCA_CAMERA_FRAME_CLOSE,
    RCA_CAMERA_FRAME_CLOSE3,
    RCA_CAMERA_FRAME_LINE_R,
    RCA_CAMERA_FRAME_MAX_NUM,
} rca_camera_frame_id_e;

#pragma pack(1)
typedef struct {
    unsigned int version;
    intrinsic_v1_st   intrinsic;
    distortion_v1_st  distortion;
    rrCameraHeadInfoSt cameraHead;
} camera_para_v1_st;
#pragma pack()

#pragma pack(1)
typedef struct {
    unsigned int version;
    PlanePara left, right, ground;
    SlightParams left_angs, right_angs;
    CamExtrinsic cam;
    LineKb left_slight_line_img, right_slight_line_img;
    float left_slight_grd_roll, right_slight_grd_roll;
    float delta_pitch_sl_cam;
    float reserve[6];
    float left_slight_line_avg_width_factory;
    float right_slight_line_avg_width_factory;
    int subversion; // subversion ==1 启用 left_slight_line_avg_width_factory/right_slight_line_avg_width_factory
    float dact_lds_20_yaw_rad;  // DACT LDS扫20cm板距离
    float cal_ambient_temp;     // LCRT 外参标定温度
    float cal_cpu_temp;         // LCRT 外参标定cpu温度
    float cal_battery_temp;     // LCRT 外参标定电池温度
    float dact_left_40_err;     // DACT 40cm 左线激光于LDS误差
    float dact_right_40_err;    // DACT 40cm 右线激光于LDS误差
    float dact_left_20_err;     // DACT 20cm 左线激光于LDS误差
    float dact_right_20_err;    // DACT 20cm 右线激光于LDS误差
    float dact_lds_20_dis;      // DACT LDS扫20cm板距离
    float ambient_temp;
    float cpu_temp;
    float battery_temp;
    float dact_left_distance;
    float dact_right_distance;
    float preheat_min;
    float slight_line_pwm_duty;
    float left_slight_line_avg_light_factory;
    float right_slight_line_avg_light_factory;
    float ir_gain_factory;
    float cam_yaw;
    rrCameraHeadInfoSt cameraHead;
} CamSlightParams;
#pragma pack()

typedef struct {
    int slight_line_pwm_duty; // 线激光占空比
    int gain_register; // 摄像头标定增益的寄存值
    int laser_id;      // 0: 未指定线激光ID； 1: 100 mw 纵慧；2: 100 mw 睿熙；3: 180 mw 纵慧；4: 180 mw 睿熙
    int expo_register; // 摄像头标定曝光时间 us
    int laser_grd_end_left_x; // 地线可见范围左端点 图像x坐标
    int laser_grd_end_left_y; // 地线可见范围左端点 图像y坐标
    int laser_grd_end_right_x; // 地线可见范围右端点 图像x坐标
    int laser_grd_end_right_y; // 地线可见范围右端点 图像y坐标
    int dark_laser_grd_end_left_x; // 第二阈值地线可见范围左端点 图像x坐标
    int dark_laser_grd_end_left_y; // 第二阈值地线可见范围左端点 图像y坐标
    int dark_laser_grd_end_right_x; // 第二阈值地线可见范围右端点 图像x坐标
    int dark_laser_grd_end_right_y; // 第二阈值地线可见范围右端点 图像y坐标
    int temperature_compensate_info; // 温度补偿信息
    float reserve[19];
} camera_reserve_ids0;

typedef struct {
    int led_cal_pwm_duty;     // 补光灯工厂标定占空比
    int led_refurbished_flag; // 售后更换补光灯标志  (逻辑同 bug 96826)
    float reserve[30];
} camera_reserve_ids1;

#pragma pack(1)
typedef struct {
    unsigned short major_version;
    unsigned short minor_version;
    unsigned short sub_version;
    unsigned short para_version;
    union {
        camera_reserve_ids0 ids0;
        camera_reserve_ids1 ids1;
    } reserve_data;
    rrCameraHeadInfoSt cameraHead;
} camera_reserve_st;
#pragma pack()

typedef struct {
    int version;
    float floorpos;
    float focusshift;
    float pitch;
    float roll;
    float yaw;
    float extrinsic_para[12];
    float reserve[2];
    float led_default_light;
    float led_default_img_light;
    int led_refurbished_flag;
    int led_cal_pwm_duty;
    rrCameraHeadInfoSt cameraHead;
} camera_depth_para_v2_st;

typedef enum {
    RESERVE_TYPE,
    SLIGHT_TYPE,
    PARA_TYPE,
    DEPTH_TYPE,
} eeprom_data_type;

typedef enum {
    CAMERA_EEPROM_CHECK_NONE,
    CAMERA_EEPROM_CHECK_CRC32,
    CAMERA_EEPROM_CHECK_SUM,
} eeprom_check_type;

#define RCA_CAMERA_FRAME_START          RCA_CAMERA_FRAME_LINE_L
#define RCA_CAMERA_FRAME_END            RCA_CAMERA_FRAME_LINE_R

#define camera_para_st camera_para_v1_st

int rca_camera_eeprom_read_para_data(rca_camera_id_e ids,
                                     camera_para_st *camera_parap);
int rca_camera_eeprom_write_para_data(rca_camera_id_e ids,
                                      camera_para_st *camera_parap);
int rca_camera_eeprom_read_reserve_data(rca_camera_id_e ids,
                                        camera_reserve_st *camera_reservep);
int rca_camera_eeprom_write_reserve_data(rca_camera_id_e ids,
        camera_reserve_st *camera_reservep);
int rca_camera_eeprom_write_swp(rca_camera_id_e ids, const unsigned char lock);
int rca_camera_eeprom_read_otp_data(rca_camera_id_e ids, unsigned char *data);

int rca_camera_eeprom_read_slight_data(CamSlightParams *camera_slight_parap);
int rca_camera_eeprom_read_depth_data(camera_depth_para_v2_st
                                      *camera_depth_parap_v2);
int rca_camera_eeprom_write_slight_data(CamSlightParams *camera_slight_parap);
int rca_camera_eeprom_write_depth_data(camera_depth_para_v2_st
                                       *camera_depth_parap_v2);
int rca_camera_init_ids_org_resolution(rca_camera_id_e ids);
int rca_camera_start_capture_org_resolution(rca_camera_capture_callback
        cb,
        rca_camera_type_e eType);
int rca_camera_start_capture(rca_camera_capture_callback cb,
                             rca_camera_type_e eType,
                             rca_camera_id_e ids);
int rca_camera_stop_capture(rca_camera_id_e ids);
rca_camera_state_e rca_camera_state(rca_camera_id_e ids);
int camera_eeprom_read_data(rca_camera_id_e ids, unsigned char *data,
                            unsigned int start_addr, unsigned int data_size, eeprom_check_type check_type);
int rca_camera_get_max_expinfo(unsigned long long *exposure_time,
                               unsigned int *sensitivity);
#endif
