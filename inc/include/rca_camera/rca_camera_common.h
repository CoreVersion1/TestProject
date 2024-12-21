#ifndef __RCA_CAMERA_COMMON_H__
#define __RCA_CAMERA_COMMON_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    RCA_CAMERA_ID_0 = 0x1,
    RCA_CAMERA_ID_1 = 0x1 << 1,
    RCA_CAMERA_ID_ALL = RCA_CAMERA_ID_1 | RCA_CAMERA_ID_0,
    RCA_CAMERA_ID_2 = 0x1 << 2,
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
    RES_DEFALIT,
    RES_ORG,
    RES_MAX,
} camera_resolution_e;

#define RCA_LUMA_INVALID        0xFFFF
#define RCA_LUMA_SHADOW_AREA    2
#define RCA_LUMA_LED_AREA       1
typedef struct CameraLumaInfo {
    unsigned int total_luma;
    unsigned int shadow_luma;
    unsigned int led_luma;
    unsigned int sub_shadow[RCA_LUMA_SHADOW_AREA];
} rca_camera_luma_st;

typedef struct CameraHeaderData rca_camera_header_data;

//add eeprom start
typedef void (*rca_camera_capture_callback)(rca_camera_header_data
        *pCameraHeaderData);

typedef void (*rca_camera_service_status_callback)(unsigned int
        *isRecordServiceDiedp);

typedef void (*rca_gradient_points_callback)(void *gradient_points_data);

extern rca_camera_type_e rca_camera_type();
extern int rca_camera_set_line_exp_gain(rca_camera_id_e ids, float exp_val,
                                        float gain_val);
extern void rca_camera_width_height(unsigned int *w, unsigned int *h);
extern const char *rca_camera_type2str(rca_camera_type_e eType);
extern const char *rca_camera_frametype2str(rca_camera_header_data *pCHD);

extern int rca_camera_init_ids(rca_camera_id_e ids);
extern int rca_camera_merge_to_sidebyside(unsigned char *from, int channels,
        unsigned char *to, int single_w, int single_h, int single_size,
        rca_camera_type_e eType);
extern int rca_camera_data_to_yuv420p(const unsigned char *from,
                                      unsigned char *to,
                                      unsigned int w, unsigned int h, rca_camera_type_e eType);
extern int rca_camera_data_is_gray(int data_size, int w, int h);

extern int rca_camera_luma(unsigned char *yuv, int w, int h,
                           rca_camera_luma_st *pluma);

extern int rca_camera_luma_2(rca_camera_id_e ids, unsigned char *yuv, int w,
                             int h,
                             rca_camera_luma_st *pluma);
extern int rca_camera_luma_cal_fac(unsigned char *yuv, int type, int w, int h,
                                   rca_camera_luma_st *pluma);

extern void rca_camera_exit();
extern int rca_camera_frame_type(rca_camera_header_data *pCHD);
extern void rca_camera_avc_switch(int on);

#ifdef __cplusplus
}
#endif

#endif
