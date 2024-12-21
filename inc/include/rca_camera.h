/* =============================================================================
#     FileName: rca_camera.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2018-07-24 15:05:29
#      History:
============================================================================= */
#ifndef __RCA_CAMERA_H__
#define __RCA_CAMERA_H__

#ifdef __cplusplus
extern "C"
{
#endif

#if !defined(RR_DRV_SW_CAMERA_REFACTOR)
#define CAMERA_INVALID_ID           0xFFFFFFFF
#define RCA_MULTI_CAMERA_NUMS           UART_API_HAVE_CAMERA_NUM
#endif

#if defined(UART_API_HAVE_MR813_CAMERA_2)
#include "rca_camera/rca_camera_aw813_2.h"
#endif

#if defined(UART_API_HAVE_MR527_CAMERA)
#include "rca_camera/rca_camera_mr527.h"
#endif

#if defined(RR_DRV_SW_CAMERA_REFACTOR)
#include "rca_camera/rca_camera_refactor.h"
#endif

#if defined(UART_API_HAVE_MR536_CAMERA)
#include "rca_camera/rca_camera_mr536.h"
#endif

#if defined(UART_API_HAVE_9383C_CAMERA)
#include "rca_camera/rca_camera_9383c.h"
#endif

#if defined(RR_DRV_SW_TOF_REFACTOR)
#include "rca_camera/rca_tof_refactor.h"
#endif

#if defined(UART_API_HAVE_QCOM_CAMERA) || defined(UART_API_HAVE_MR813_CAMERA_MONO) || defined(UART_API_HAVE_CV25_CAMERA) \
    || defined(UART_API_HAVE_JA308_CAMERA) || defined(UART_API_HAVE_R16_CAMERA)
#if defined(UART_API_HAVE_QCOM_CAMERA)

// For qcom
#define RCA_SINGLE_CAMERA_OV5695_YUV_WIDTH     1280
#define RCA_SINGLE_CAMERA_OV5695_YUV_HEIGHT    960
#define RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH     1600
#define RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT    1200
#define RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH_CROP     800
#define RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT_CROP    600

//current max camera size is ov8856, set ov8856 default size
#define RCA_CAMERA_MAX_SIZE             (RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH*2*RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT*2)

#elif defined(UART_API_HAVE_MR813_CAMERA_MONO)

#define RCA_SINGLE_CAMERA_YUV_WIDTH     UART_API_CAMERA_YUV_W
#define RCA_SINGLE_CAMERA_YUV_HEIGHT    UART_API_CAMERA_YUV_H
#define RCA_MULTI_CAMERA_YUV_WIDTH      (RCA_SINGLE_CAMERA_YUV_WIDTH)
#define RCA_MULTI_CAMERA_YUV_HEIGHT     (RCA_SINGLE_CAMERA_YUV_HEIGHT)

#define RCA_SINGLE_CAMERA_GRAY_SIZE     (RCA_SINGLE_CAMERA_YUV_HEIGHT*RCA_SINGLE_CAMERA_YUV_WIDTH)
#define RCA_SINGLE_CAMERA_YUV_SIZE      (RCA_SINGLE_CAMERA_GRAY_SIZE)

#define RCA_CAMERA_MAX_SIZE             (RCA_MULTI_CAMERA_YUV_WIDTH*RCA_MULTI_CAMERA_YUV_HEIGHT)

typedef enum {
    RCA_CAMERA_FRAME_LINE_L = 0,
    RCA_CAMERA_FRAME_CLOSE,
    RCA_CAMERA_FRAME_LINE_R,
    RCA_CAMERA_FRAME_IR,
    RCA_CAMERA_FRAME_MAX_NUM,
}
rca_camera_frame_id_e;

#elif defined(UART_API_HAVE_CV25_CAMERA) || defined(UART_API_HAVE_JA308_CAMERA)
#define RCA_SINGLE_CAMERA_OV7251_YUV_WIDTH     640
#define RCA_SINGLE_CAMERA_OV7251_YUV_HEIGHT    480
#define RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH     1600
#define RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT    1200
#define RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH_CROP     800
#define RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT_CROP    600

//current max camera size is ov8856, set ov8856 default size
#define RCA_SINGLE_CAMERA_LUMA_MAX_SIZE         (RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH*RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT)
#define RCA_SINGLE_CAMERA_MAX_SIZE              (RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH*RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT*2)
#define RCA_DUAL_CAMERA_MAX_SIZE                (RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH*2*RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT*2)

#define RCA_SINGLE_CAMERA_OV7251_GRAY_SIZE      (RCA_SINGLE_CAMERA_OV7251_YUV_HEIGHT*RCA_SINGLE_CAMERA_OV7251_YUV_WIDTH)
#define RCA_SINGLE_CAMERA_OV7251_YUV_SIZE       (RCA_SINGLE_CAMERA_OV7251_GRAY_SIZE)
#define RCA_SINGLE_CAMERA_OV8856_GRAY_SIZE      (RCA_SINGLE_CAMERA_OV8856_YUV_HEIGHT*RCA_SINGLE_CAMERA_OV8856_YUV_WIDTH)
#define RCA_SINGLE_CAMERA_OV8856_YUV_SIZE       (RCA_SINGLE_CAMERA_OV8856_GRAY_SIZE*3/2)

typedef enum {
    RCA_CAMERA_FRAME_LINE_L = 0,
    RCA_CAMERA_FRAME_CLOSE,
    RCA_CAMERA_FRAME_CLOSE2,
    RCA_CAMERA_FRAME_CLOSE3,
    RCA_CAMERA_FRAME_LINE_R,
    RCA_CAMERA_FRAME_MAX_NUM,
}
rca_camera_frame_id_e;
#elif defined(UART_API_HAVE_R16_CAMERA)

#define RCA_SINGLE_CAMERA_YUV_WIDTH     UART_API_CAMERA_YUV_W
#define RCA_SINGLE_CAMERA_YUV_HEIGHT    UART_API_CAMERA_YUV_H
#define RCA_MULTI_CAMERA_YUV_WIDTH      (RCA_SINGLE_CAMERA_YUV_WIDTH)
#define RCA_MULTI_CAMERA_YUV_HEIGHT     (RCA_SINGLE_CAMERA_YUV_HEIGHT)

#define RCA_SINGLE_CAMERA_GRAY_SIZE     (RCA_SINGLE_CAMERA_YUV_HEIGHT*RCA_SINGLE_CAMERA_YUV_WIDTH)
#define RCA_SINGLE_CAMERA_YUV_SIZE      (RCA_SINGLE_CAMERA_GRAY_SIZE)

#define RCA_CAMERA_MAX_SIZE             (RCA_MULTI_CAMERA_YUV_WIDTH*RCA_MULTI_CAMERA_YUV_HEIGHT)
typedef enum {
    RCA_CAMERA_FRAME_LINE = 0,
    RCA_CAMERA_FRAME_CLOSE,
    RCA_CAMERA_FRAME_MAX_NUM,
}
rca_camera_frame_id_e;
#endif
typedef enum {
    RCA_CAMERA_ID_0 = 0x1,
    RCA_CAMERA_ID_1 = 0x1 << 1,
    RCA_CAMERA_ID_ALL = RCA_CAMERA_ID_1 | RCA_CAMERA_ID_0,
}
rca_camera_id_e;

typedef enum {
    RCA_CAMERA_TYPE_IGN = 0,  // Don't use, just for test
    RCA_CAMERA_TYPE_BMP,      // Do not support
    RCA_CAMERA_TYPE_YUV,
    RCA_CAMERA_TYPE_RAW,      // Do not support
    RCA_CAMERA_TYPE_GRAY,     // YUV only y
    RCA_CAMERA_TYPE_VIDEO,    // not support now
    RCA_CAMERA_TYPE_SERVER,
    RCA_CAMERA_TYPE_READPARA,
    RCA_CAMERA_TYPE_WRITEPARA,
    RCA_CAMERA_TYPE_READOC,
    RCA_CAMERA_TYPE_EFUSEID,
    RCA_CAMERA_TYPE_AWB,
    RCA_CAMERA_TYPE_LSC,
    RCA_CAMERA_TYPE_READDEPTH,          //read module depth info
    RCA_CAMERA_TYPE_WRITEDEPTH,         //write module depth info
    RCA_CAMERA_TYPE_GETPARA,
    RCA_CAMERA_TYPE_GETDEPTH,
    RCA_CAMERA_TYPE_WRITE_FAC_FLAG,     //write machine factory calibrated flag
    RCA_CAMERA_TYPE_READ_FAC_FLAG,      //read machine factory calibrated flag
    RCA_CAMERA_TYPE_WRITE_CAL_METHOD,   //write machine factory calibrated method
    RCA_CAMERA_TYPE_READ_CAL_METHOD,    //read machine factory calibrated method
    RCA_CAMERA_TYPE_RGB888,
    RCA_CAMERA_TYPE_JPEG,
    RCA_CAMERA_TYPE_CRYPTED,
    RCA_CAMERA_TYPE_INVALID,
} rca_camera_type_e;

typedef enum {
    RCA_CAMERA_STATE_CLOSE = 0,
    RCA_CAMERA_STATE_OPEN,
    RCA_CAMERA_STATE_PREVIEW,
    RCA_CAMERA_STATE_STOP,

    RCA_CAMERA_STATE_INVALID,
} rca_camera_state_e;

typedef enum {
    RCA_CAMERA_PARA_SUB_AUTO_EXP_FRAME_AVG,
    RCA_CAMERA_PARA_SUB_AUTO_EXP_CENTER_WEIGHTED,
    RCA_CAMERA_PARA_SUB_AUTO_EXP_SPOT_METERING,
    RCA_CAMERA_PARA_SUB_AUTO_EXP_NUM,
} rca_camera_para_sub_type_auto_e;

typedef enum {
    RCA_CAMERA_PARA_SUB_MANUAL_EXP_TIME,
    RCA_CAMERA_PARA_SUB_MANUAL_EXP_GAIN,
    RCA_CAMERA_PARA_SUB_MANUAL_EXP_NUM,
} rca_camera_para_sub_type_manual_e;

typedef enum {
    RCA_CAMERA_PARA_TYPE_AUTO_EXP,
    RCA_CAMERA_PARA_TYPE_MANUAL_EXP,
} rca_camera_para_type_e;

//Should same as ../camera/rr_camera.h RrCameraInfo_st
typedef struct {
    long long manual_exp_time_min_ns;
    long long manual_exp_time_max_ns;
    long long manual_exp_gain_min;
    long long manual_exp_gain_max;
} rca_camera_info_st;

typedef struct CameraHeaderData {
    unsigned int image_timestamp;
    unsigned int channels;
    unsigned int single_size;
    unsigned int single_height;
    unsigned int single_width;
    unsigned char *datap[RCA_MULTI_CAMERA_NUMS];
    //pixel_type: 8U = 0, 8S = 1, 16U = 2, 16S = 3, 32S = 4, 32F = 5, 64F = 6
    unsigned int pixel_type;
    //img_flag: row-major = 0, col-major = 1, row-major-channel-last = 2, col-majo-channel-last = 3
    unsigned int img_flag;
    unsigned int frame_number;
    unsigned long long exposure_time;
    unsigned int sensitivity;
    rca_camera_type_e eType;
#ifdef UART_API_HAVE_JA308_CAMERA_TOF
    unsigned int tof_id;
#endif
#ifdef UART_API_HAVE_CAMERA_PWM_ADAPT
    unsigned int pwm_duty;
#endif
} rca_camera_header_data;

#define RCA_LUMA_INVALID        0xFFFF
#define RCA_LUMA_SHADOW_AREA    2
#define RCA_LUMA_LED_AREA       1
typedef struct CameraLumaInfo {
    unsigned int total_luma;
    unsigned int shadow_luma;
    unsigned int led_luma;
    unsigned int sub_shadow[RCA_LUMA_SHADOW_AREA];
} rca_camera_luma_st;

//add eeprom start
typedef void (*rca_camera_capture_callback)(rca_camera_header_data
        *pCameraHeaderData);

typedef void (*rca_camera_service_status_callback)(unsigned int
        *isRecordServiceDiedp);

typedef void (*rca_gradient_points_callback)(void *gradient_points_data);

#if defined(UART_API_HAVE_QCOM_CAMERA) || defined(UART_API_HAVE_MR813_CAMERA_MONO) || defined(UART_API_HAVE_R16_CAMERA)
#if defined(UART_API_HAVE_MR813_CAMERA_MONO) || defined(UART_API_HAVE_R16_CAMERA)
extern int rca_camera_close_hardisp(void);
extern int rca_camera_disable_auto_exp(void);
extern int rca_camera_enable_pattern(void);
extern int rca_camera_set_line_exp_gain(float exp_val, float gain_val);
extern int rca_camera_init_ids_org_resolution(rca_camera_id_e ids);
extern int rca_camera_start_capture_org_resolution(rca_camera_capture_callback
        cb,
        rca_camera_type_e eType);
#endif
extern int rca_camera_start_capture(rca_camera_capture_callback cb,
                                    rca_camera_type_e eType);
extern int rca_camera_start_capture_kthread(rca_camera_capture_callback cb,
        rca_camera_type_e eType);
extern int rca_camera_start_capture_calib_kthread(rca_camera_capture_callback
        cb,
        rca_gradient_points_callback gradient_points_cb,
        rca_camera_type_e eType);

extern int rca_camera_stop_capture();
extern int rca_camera_stop_capture_parallel_line();
extern rca_camera_state_e rca_camera_state();
#elif defined(UART_API_HAVE_CV25_CAMERA) || defined(UART_API_HAVE_JA308_CAMERA)
extern int rca_camera_init_ids_nowarp(rca_camera_id_e ids);
#if defined(UART_API_HAVE_CV25_CAMERA)
extern int rca_camera_start_capture(rca_camera_capture_callback cb,
                                    rca_camera_type_e eType,
                                    rca_camera_id_e ids);
#elif defined(UART_API_HAVE_JA308_CAMERA)
extern int rca_camera_start_capture(rca_camera_capture_callback cb_jpeg,
                                    rca_camera_capture_callback cb_yuv,
                                    rca_camera_capture_callback cb_rgb,
                                    rca_camera_type_e eType,
                                    rca_camera_id_e ids);
#endif
extern int rca_camera_dewarp_control(rca_camera_id_e ids,
                                     unsigned int enable);
extern int rca_camera_init_ids_org_resolution(rca_camera_id_e ids,
        rca_camera_type_e eType);
extern int rca_camera_start_capture_org_resolution(rca_camera_capture_callback
        cb,
        rca_camera_type_e eType,
        rca_camera_id_e ids);
extern int rca_camera_set_auto_ae(rca_camera_id_e ids, int enable_manual_ae,
                                  float exp_time, float gain);

extern int rca_camera_stop_capture(rca_camera_id_e ids);
extern rca_camera_state_e rca_camera_state(rca_camera_id_e ids);
extern int rca_camera_eeprom_operate(rca_camera_id_e ids,
                                     unsigned int start_addr,
                                     char  *data, unsigned int data_size, unsigned int read_flag);
#endif
#ifdef UART_API_HAVE_JA308_CAMERA_TOF
#define TOF_EEPROM_I2C_ADDRESS 0x56
int rca_camera_front_tof_exp_set(float exp_ms);
int rca_camera_back_tof_exp_set(float exp_ms);

int rca_camera_front_tof_get_reg_data(unsigned short i2c_addr,
                                      unsigned short reg_addr,
                                      unsigned short *reg_data);
int rca_camera_back_tof_get_reg_data(unsigned short i2c_addr,
                                     unsigned short reg_addr,
                                     unsigned short *reg_data);
int rca_camera_front_tof_set_reg_data(unsigned short i2c_addr,
                                      unsigned short reg_addr,
                                      unsigned short reg_data);
int rca_camera_back_tof_set_reg_data(unsigned short i2c_addr,
                                     unsigned short reg_addr,
                                     unsigned short reg_data);

int rca_camera_front_tof_get_eeprom_data(unsigned char *buf, int size,
        unsigned int offset);
int rca_camera_back_tof_get_eeprom_data(unsigned char *buf, int size,
                                        unsigned int offset);
int rca_camera_front_tof_set_eeprom_data(unsigned char *buf, int size,
        unsigned int offset);
int rca_camera_back_tof_set_eeprom_data(unsigned char *buf, int size,
                                        unsigned int offset);
#endif

extern rca_camera_type_e rca_camera_type();
extern void rca_camera_width_height(unsigned int *w, unsigned int *h);
extern const char *rca_camera_type2str(rca_camera_type_e eType);
extern const char *rca_camera_frametype2str(rca_camera_header_data *pCHD);

extern int rca_camera_get_param(rca_camera_para_type_e eType,
                                unsigned int subtype, long long *valuep);
extern int rca_camera_set_param(rca_camera_para_type_e eType,
                                unsigned int subtype, long long value);
extern int rca_camera_init_ids(rca_camera_id_e ids);
extern int rca_camera_merge_to_sidebyside(unsigned char *from, int channels,
        unsigned char *to, int single_w, int single_h, int single_size,
        rca_camera_type_e eType);
extern int rca_camera_data_to_yuv420p(const unsigned char *from,
                                      unsigned char *to,
                                      unsigned int w, unsigned int h, rca_camera_type_e eType);
extern int rca_camera_data_is_gray(int data_size, int w, int h);

extern int rr_videobuf_dev_get_luma(int id, rca_camera_luma_st *pluma_l,
                                    rca_camera_luma_st *pluma_c);
extern int rr_videobuf_dev_check_crc_set(int id, int *crc_set);
extern int rr_videobuf_dev_check_crc_get(int id, int *crc_get);
extern int rca_camera_luma(unsigned char *yuv, int w, int h,
                           rca_camera_luma_st *pluma);
extern int rca_camera_luma_cal_fac(unsigned char *yuv, int type, int w, int h,
                                   rca_camera_luma_st *pluma);
extern void rca_camera_avc_switch(int on);

extern int rca_get_current_sensor_type(int *sensor_type);

//Should call rca_camera_init_ids(RCA_CAMERA_ID_0|RCA_CAMERA_ID_1);

extern int rca_camera_init();

extern void rca_camera_exit();

extern int rca_camera_get_cur_fps(int *curFpsp);
extern int rca_camera_get_max_expinfo(unsigned long long *exposure_time,
                                      unsigned int *sensitivity);

extern int rca_camera_get_record_service_status(
    rca_camera_service_status_callback status_cb);

extern int rca_camera_frame_type(rca_camera_header_data *pCHD);
#endif

#if defined(UART_API_HAVE_AW813_CAMERA_TOF) || defined(UART_API_HAVE_MR813_CAMERA_MONO) || defined(UART_API_HAVE_R16_CAMERA)
#ifdef UART_API_HAVE_AW813_CAMERA_TOF

/*
 *  For standard V4l2 architecture, we can call the below interfaces as example
 *
 *  Example:
 *  CAMERA_INIT c;
 *  if (0 != rca_camera_init(&c)) {
 *      return ;
 *  }
 *
 *  // Get calibration
 *  CAMERA_I2C_OPS ops;
 *  ops.id = c[0].id;
 *  ops.id = e2prom_addr;
 *  ops.reg = 0x1122;
 *  ops.reg_len = 2;
 *  ops.data = &data[1024];
 *  ops.len = 1024;
 *  rca_camera_i2c_read(&ops);
 *
 *  void capture_cb(unsigned int cam_id, struct v4l2_buffer *buf) {
 *      if (cam_id == c[0].id) {
 *          // it might be come from left side
 *          // hard copy
 *          size = c[0].width * c[0].height;
 *          if (c[0].pixelformat == V4L2_PIX_FMT_Y16) {
 *              size *= 2;
 *          }
 *          // copyInBufQueue(left_queue, buf, size);
 *      } else {
 *          // right side
 *          // copy to right queue
 *          // copyInBufQueue(left_queue, buf, size);
 *      }
 *  }
 *
 *  rca_camera_start_capture(capture_cb);
 *
 *  // release resource
 *  rca_camera_stop_capture();
 *  rca_camera_exit();
 *
*/

// for aw813 interfaces
#define CAMERA_MAX_NUM              2

typedef struct _camera_init {
    unsigned int id[CAMERA_MAX_NUM];

    unsigned int width;
    unsigned int height;
    unsigned int pixelformat;
    unsigned int padding;           // bits was add for byte alignment
} CAMERA_INIT;

/*
 *  Create pipeline of 2 cameras.
 *  Param:
 *    init [out]: Actual output camera image parameters.
 *                CAMERA_INVALID_ID if camera isn't exist
 *  Return value:
 *    0 if success
 *  Note:
 *    It should be called before other rca_camera_xxx interfaces.
*/
extern int rca_camera_init(CAMERA_INIT *init);

extern void rca_camera_exit();

/*
 *  Captured image callback
 *  Param:
 *    id [in]: refered to "id" returned in CAMERA_INIT
 *    buf [out]: image buffer in struct v4l2_buffer
 *  Return value:
 *    0 if success
 *  Note:
 *    Handle buffer asap without blocking
*/
typedef void (*rca_camera_capture_callback)(
    unsigned int id, const void *buf, size_t length, struct timeval *t);

extern int rca_camera_start_capture(rca_camera_capture_callback cb);
extern int rca_camera_stop_capture();
//tof_id: 0 or 1
extern int rca_tof_power_on(unsigned int tof_id);
extern int rca_tof_power_off(unsigned int tof_id);

#elif defined(UART_API_HAVE_MR813_CAMERA_MONO)
#define CAMERA_MAX_NUM              1
#elif defined(UART_API_HAVE_R16_CAMERA)
#define CAMERA_MAX_NUM              1
#endif

typedef struct __camera_i2c_ops {
    unsigned int
    id;                    // camera's id responedint to subdev in media-ctl
    unsigned int
    i2c_addr;              // I2C slave 7bit address, such as sensor, flash, eeprom
    unsigned int reg;                   // register's address in i2c devices

    unsigned char *data;
    // data to be read or written, and each data in little endian.
    unsigned int
    data_size;             // byte size of total data to be read or written.
    unsigned int
    data_width;            // data width to be read or written, 1, 2 or 4
} CAMERA_I2C_OPS;
extern int rca_camera_i2c_write(CAMERA_I2C_OPS *ops);
extern int rca_camera_i2c_read(CAMERA_I2C_OPS *ops);

#endif

#ifdef __cplusplus
}
#endif

#include "rca_camera_led.h"
#include "rca_camera_eeprom.h"

#endif


