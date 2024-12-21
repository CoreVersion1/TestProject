/* =============================================================================
#     FileName: rca_camera_eeprom.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2020-08-30 16:09:51
#      History: none
============================================================================= */

#ifndef __RCA_CAMERA_EEPROM_H__
#define __RCA_CAMERA_EEPROM_H__

#ifdef UART_API_HAVE_CAMERA

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(UART_API_HAVE_MR813_CAMERA_2)
#include "rca_camera/rca_camera_eeprom_aw813_2.h"
#endif

#if defined(UART_API_HAVE_MR527_CAMERA)
#include "rca_camera/rca_camera_eeprom_mr527.h"
#endif

#if defined(UART_API_HAVE_MR536_CAMERA)
#include "rca_camera/rca_camera_eeprom_mr536.h"
#endif

#if defined(UART_API_HAVE_9383C_CAMERA)
#include "rca_camera/rca_camera_eeprom_9383c.h"
#endif

#if defined(RR_DRV_SW_CAMERA_REFACTOR)
#include "rca_camera/rca_camera_eeprom_refactor.h"
#endif

#if defined(UART_API_HAVE_R16_CAMERA) && defined(RR_DRV_SW_CAMERA_LASERCAM)
#include "rca_camera/rca_camera_eeprom_r16_lasercam.h"
#endif

#if defined(UART_API_HAVE_QCOM_CAMERA)

#define MAX_POWER_CONFIG                12
#define MSM_EEPROM_MEMORY_MAP_MAX_SIZE  80
#define MSM_EEPROM_MAX_MEM_MAP_CNT      8
#define MAX_SENSOR_NAME                 32
#define GPIO_OUT_LOW                    (0 << 1)
#define GPIO_OUT_HIGH                   (1 << 1)
typedef unsigned int    uint32_t;
typedef unsigned short  uint16_t;
typedef unsigned char   uint8_t;

enum i2c_freq_mode_t {
    I2C_STANDARD_MODE,
    I2C_FAST_MODE,
    I2C_CUSTOM_MODE,
    I2C_FAST_PLUS_MODE,
    I2C_MAX_MODES,
};

enum camera_i2c_freq_mode {
    SENSOR_I2C_MODE_STANDARD,
    SENSOR_I2C_MODE_FAST,
    SENSOR_I2C_MODE_CUSTOM,
    SENSOR_I2C_MODE_FAST_PLUS,
    SENSOR_I2C_MODE_MAX,
};

enum eeprom_cfg_type_t {
    CFG_EEPROM_GET_INFO,
    CFG_EEPROM_GET_CAL_DATA,
    CFG_EEPROM_READ_CAL_DATA,
    CFG_EEPROM_WRITE_DATA,
    CFG_EEPROM_GET_MM_INFO,
    CFG_EEPROM_INIT,
    CFG_EEPROM_READ_DATA,
};

struct eeprom_get_t {
    uint32_t num_bytes;
};

struct eeprom_read_t {
    uint8_t *dbuffer;
    uint32_t num_bytes;
};

struct eeprom_write_t {
    uint8_t *dbuffer;
    uint32_t num_bytes;
};

struct eeprom_get_cmm_t {
    uint32_t cmm_support;
    uint32_t cmm_compression;
    uint32_t cmm_size;
};

enum msm_camera_i2c_reg_addr_type {
    MSM_CAMERA_I2C_BYTE_ADDR = 1,
    MSM_CAMERA_I2C_WORD_ADDR,
    MSM_CAMERA_I2C_3B_ADDR,
    MSM_CAMERA_I2C_ADDR_TYPE_MAX,
};

enum msm_camera_i2c_data_type {
    MSM_CAMERA_I2C_BYTE_DATA = 1,
    MSM_CAMERA_I2C_WORD_DATA,
    MSM_CAMERA_I2C_DWORD_DATA,
    MSM_CAMERA_I2C_SET_BYTE_MASK,
    MSM_CAMERA_I2C_UNSET_BYTE_MASK,
    MSM_CAMERA_I2C_SET_WORD_MASK,
    MSM_CAMERA_I2C_UNSET_WORD_MASK,
    MSM_CAMERA_I2C_SET_BYTE_WRITE_MASK_DATA,
    MSM_CAMERA_I2C_DATA_TYPE_MAX,
};

enum msm_sensor_power_seq_gpio_t {
    SENSOR_GPIO_RESET,
    SENSOR_GPIO_STANDBY,
    SENSOR_GPIO_AF_PWDM,
    SENSOR_GPIO_VIO,
    SENSOR_GPIO_VANA,
    SENSOR_GPIO_VDIG,
    SENSOR_GPIO_VAF,
    SENSOR_GPIO_FL_EN,
    SENSOR_GPIO_FL_NOW,
    SENSOR_GPIO_FL_RESET,
    SENSOR_GPIO_CUSTOM1,
    SENSOR_GPIO_CUSTOM2,
    SENSOR_GPIO_MAX,
};

enum msm_camera_i2c_operation {
    MSM_CAM_WRITE = 0,
    MSM_CAM_POLL,
    MSM_CAM_READ,
};

struct msm_camera_reg_settings_t {
    uint16_t reg_addr;
    enum msm_camera_i2c_reg_addr_type addr_type;
    uint16_t reg_data;
    enum msm_camera_i2c_data_type data_type;
    enum msm_camera_i2c_operation i2c_operation;
    uint16_t delay;
};

struct msm_eeprom_mem_map_t {
    int slave_addr;
    struct msm_camera_reg_settings_t
        mem_settings[MSM_EEPROM_MEMORY_MAP_MAX_SIZE];
    int memory_map_size;
};

struct msm_eeprom_memory_map_array {
    struct msm_eeprom_mem_map_t memory_map[MSM_EEPROM_MAX_MEM_MAP_CNT];
    uint32_t msm_size_of_max_mappings;
};

enum msm_sensor_power_seq_type_t {
    SENSOR_CLK,
    SENSOR_GPIO,
    SENSOR_VREG,
    SENSOR_I2C_MUX,
    SENSOR_I2C,
};

enum msm_camera_vreg_name_t {
    CAM_VDIG,
    CAM_VIO,
    CAM_VANA,
    CAM_VAF,
    CAM_V_CUSTOM1,
    CAM_V_CUSTOM2,
    CAM_VREG_MAX,
};

enum msm_sensor_clk_type_t {
    SENSOR_CAM_MCLK,
    SENSOR_CAM_CLK,
    SENSOR_CAM_CLK_MAX,
};

struct msm_sensor_power_setting {
    enum msm_sensor_power_seq_type_t seq_type;
    unsigned short seq_val;
    long config_val;
    unsigned short delay;
    void *data[10];
};

struct msm_sensor_power_setting_array {
    struct msm_sensor_power_setting  power_setting_a[MAX_POWER_CONFIG];
    struct msm_sensor_power_setting *power_setting;
    unsigned short size;
    struct msm_sensor_power_setting  power_down_setting_a[MAX_POWER_CONFIG];
    struct msm_sensor_power_setting *power_down_setting;
    unsigned short size_down;
};

struct msm_eeprom_info_t {
    struct msm_sensor_power_setting_array *power_setting_array;
    enum i2c_freq_mode_t i2c_freq_mode;
    struct msm_eeprom_memory_map_array *mem_map_array;
};

struct msm_eeprom_cfg_data {
    enum eeprom_cfg_type_t cfgtype;
    uint8_t is_supported;
    union {
        char eeprom_name[MAX_SENSOR_NAME];
        struct eeprom_get_t get_data;
        struct eeprom_read_t read_data;
        struct eeprom_write_t write_data;
        struct eeprom_get_cmm_t get_cmm_data;
        struct msm_eeprom_info_t eeprom_info;
    } cfg;
};

struct eeprom_write_read_t {
    uint32_t addr;
    uint8_t dbuffer[1024 * 4];
    uint32_t num_bytes;
};

struct msm_eeprom_cfg_data_rw {
    enum eeprom_cfg_type_t cfgtype;
    uint8_t is_supported;
    struct eeprom_write_read_t *write_read_data;
    union {
        char eeprom_name[MAX_SENSOR_NAME];
        struct eeprom_get_t get_data;
        struct eeprom_read_t read_data;
        struct eeprom_write_t write_data;
        struct eeprom_get_cmm_t get_cmm_data;
        struct msm_eeprom_info_t eeprom_info;
    } cfg;
};

typedef struct {
    unsigned char main_ver;
    unsigned char sub_ver;
    unsigned char reserve[2];
} eeprom_mod_ver_st;

typedef struct {
    double fx;
    double fy;
    double u0;
    double v0;
    double skew;

} intrinsic_v1_st;

typedef struct {
    double k1;
    double k2;
    double p1;
    double p2;
    double k3;

} distortion_v1_st;

typedef struct {
    double para[12];

} extrinsic_v1_st;

typedef struct {
    intrinsic_v1_st   intrinsic;
    distortion_v1_st  distortion;

} camera_para_v1_st;

//struct to write eeprom
typedef struct {
    camera_para_v1_st left;
    camera_para_v1_st right;
    extrinsic_v1_st extrinsic;
    unsigned int crc;
    unsigned int version;   //should be 1

} dual_camera_para_v1_st;

//struct for zhuangbei file
typedef struct {
    unsigned int version;   //should be 1
    camera_para_v1_st left;
    camera_para_v1_st right;
    extrinsic_v1_st extrinsic;

} dual_camera_para_v1_file_st;

typedef struct {
    uint8_t efuse_id[16];
} camera_module_EfuseID_st;

typedef struct {
    uint8_t supplier_id;
    uint8_t OC_flag;
    uint8_t OC_x_L;
    uint8_t OC_x_H;
    uint8_t OC_y_L;
    uint8_t OC_y_H;
    uint8_t checksum;
} camera_module_ID_OC_st;

typedef struct {
    uint8_t R_Gr_D50_L;
    uint8_t R_Gr_D50_H;
    uint8_t B_Gr_D50_L;
    uint8_t B_Gr_D50_H;
    uint8_t Gb_Gr_D50_L;
    uint8_t Gb_Gr_D50_H;
    uint8_t R_Gr_TL84_L;
    uint8_t R_Gr_TL84_H;
    uint8_t B_Gr_TL84_L;
    uint8_t B_Gr_TL84_H;
    uint8_t Gb_Gr_TL84_L;
    uint8_t Gb_Gr_TL84_H;
    uint8_t R_Gr_A_L;
    uint8_t R_Gr_A_H;
    uint8_t B_Gr_A_L;
    uint8_t B_Gr_A_H;
    uint8_t Gb_Gr_A_L;
    uint8_t Gb_Gr_A_H;
    uint8_t checksum;
} camera_module_AWB_st;

typedef struct {
    double floorpos;
    double focusshift;
    double imgang;
    double HFOV;
    double VFOV;
    double F;
    int version;
} camera_depth_para_st;

typedef struct {
    camera_depth_para_st camera_depth_para;
    unsigned int crc;
    unsigned int data_size;
    unsigned int dataID;
} left_camera_depth_para_st;

typedef struct {
    uint8_t factory_cal_flag;
    uint8_t checksum;
} factory_calibration_flag_st;

typedef struct {
    uint8_t index;
    uint8_t version;
    uint8_t checksum;
} factory_calibration_method_st;

typedef struct {
    uint8_t LSC_TL84[1768];
    uint8_t checksum;
} camera_module_LSC_st;

#define BASE_VIDIOC_PRIVATE 192     /* 192-255 are private */
#define VIDIOC_MSM_EEPROM_CFG \
    _IOWR('V', BASE_VIDIOC_PRIVATE + 8, struct msm_eeprom_cfg_data)

extern int rca_camera_eeprom_get_para_from_file(unsigned char *data,
        unsigned int *addr, unsigned int *data_size);
extern int rca_camera_eeprom_get_depth_para_from_file(unsigned char *data,
        unsigned int *addr, unsigned int *data_size);
extern void rca_camera_eeprom_power_setting_init(struct msm_eeprom_cfg_data_rw
        *cfg);
extern int rca_camera_eeprom_check_crc32(unsigned char *buffer,
        unsigned int size);
extern int rca_camera_get_calibration_data_from_eeprom(dual_camera_para_v1_st
        *camera_parap);
extern int rca_camera_write_para_to_eeprom(rca_camera_id_e cameraId,
        struct eeprom_write_read_t *write_read_datap);
extern int rca_camera_get_module_version_from_eeprom(rca_camera_id_e cameraId,
        eeprom_mod_ver_st *version);
extern int rca_camera_check_module_version_eeprom(eeprom_mod_ver_st *pver);
extern int rca_camera_get_RR_version_from_eeprom(rca_camera_id_e cameraId);
extern int rca_camera_get_module_ID_OC_from_eeprom(rca_camera_id_e cameraId,
        camera_module_ID_OC_st *camera_module_parap);
extern int rca_camera_get_module_EfuseID_from_eeprom(rca_camera_id_e cameraId,
        camera_module_EfuseID_st *camera_module_EfuseID_parap);
extern int rca_camera_get_module_AWB_from_eeprom(rca_camera_id_e cameraId,
        camera_module_AWB_st *camera_module_AWB_parap);
extern int rca_camera_get_module_LSC_from_eeprom(rca_camera_id_e cameraId,
        camera_module_LSC_st *camera_module_LSC_parap);
extern int rca_camera_get_depth_data_from_eeprom(left_camera_depth_para_st
        *left_camera_depth_parap);
extern int rca_camera_eeprom_get_factory_calibration_flag_addr(
    unsigned int *addr, unsigned int *data_size);
extern int rca_camera_get_factory_calibration_flag_from_eeprom(
    factory_calibration_flag_st *factory_calibration_flagp);
extern int rca_camera_eeprom_get_factory_calibration_method_addr(
    unsigned int *addr, unsigned int *data_size);
extern int rca_camera_get_factory_calibration_method_from_eeprom(
    factory_calibration_method_st *factory_calibration_methodp);

#elif defined(UART_API_HAVE_MR813_CAMERA_MONO)
typedef struct {
    unsigned char version;
    unsigned char dataId;
    unsigned short data_size;
    unsigned int crc;
} rrCameraHeadInfoSt;

typedef struct {
    double fx;
    double fy;
    double u0;
    double v0;
    double skew;

} intrinsic_v1_st;

typedef struct {
    double k1;
    double k2;
    double p1;
    double p2;
    double k3;

} distortion_v1_st;

#pragma pack(1)
typedef struct {
    unsigned int version;
    intrinsic_v1_st   intrinsic;
    distortion_v1_st  distortion;
    rrCameraHeadInfoSt cameraHead;
} camera_para_v1_st;
#pragma pack()

// ax + by + cz + d = 0;
typedef struct {
    float a, b, c, d;
} PlanePara;

// y = kx + b
typedef struct {
    float k, b;
} LineKb;

typedef struct {
    float pitch, yaw, roll;
    float height;
} SlightParams;

typedef struct {
    float pitch;
    float roll;
    float height;
} CamExtrinsic;

typedef struct {
    unsigned int version;
    PlanePara left, right, ground;
    SlightParams left_angs, right_angs;
    CamExtrinsic cam;
    LineKb left_slight_line_img, right_slight_line_img;
    float left_slight_grd_roll, right_slight_grd_roll;
    float reserve[7];
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
#if defined(UART_API_HAVE_MR813_CAMERA_RESERVE_1C2L)
#define CAMERA_EEPROM_BLOCK0_REG_ADDR       0x0800
#define CAMERA_EEPROM_BLOCK0_DATASIZE       0xA0
#define CAMERA_EEPROM_RESERVE_VER           0x01
#define CAMERA_EEPROM_RESERVE_ID            0x01
#define CAMERA_EEPROM_RESERVE_FILESIZE      0x88   //8+32*4
#define CAMERA_EEPROM_RESERVE_REG_ADDR      0x0810
#define CAMERA_EEPROM_RESERVE_OFFSET        (CAMERA_EEPROM_RESERVE_REG_ADDR - CAMERA_EEPROM_BLOCK0_REG_ADDR)
#define CAMERA_EEPROM_RESERVE_DATASIZE      (0x88 + 0x08)    //10*8+4 + sizeof(rrCameraHeadInfoSt)
#define CAMERA_EEPROM_VERSION_REG_ADDR      0x0800
#define CAMERA_EEPROM_VERSION_OFFSET        (CAMERA_EEPROM_VERSION_REG_ADDR - CAMERA_EEPROM_BLOCK0_REG_ADDR)
#define CAMERA_EEPROM_VERSION_DATASIZE      (0x10)

typedef enum {
    CAMERA_EEPROM_CHECK_NONE,
    CAMERA_EEPROM_CHECK_CRC32,
    CAMERA_EEPROM_CHECK_SUM,
} eeprom_check_type;

typedef enum {
    RESERVE_TYPE,
    SLIGHT_TYPE,
    PARA_TYPE,
    DEPTH_TYPE,
} eeprom_data_type;

#pragma pack(1)
typedef struct {
    unsigned char main_version;
    unsigned char sub_version;
    unsigned char reserve_version[2];
    unsigned char reserve[8];
    unsigned int crc32;
} camera_version_st;
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
    rrCameraHeadInfoSt cameraHead;
} camera_reserve_st;
#pragma pack()

extern int rca_camera_eeprom_read_reserve_data(rca_camera_id_e ids,
        camera_reserve_st *camera_reservep);
extern int rca_camera_eeprom_write_reserve_data(rca_camera_id_e ids,
        camera_reserve_st *camera_reservep);
#endif
extern int rca_camera_do_cal_crc32(unsigned char *buffer,
                                   unsigned int size);
extern int rca_camera_eeprom_check_crc32(unsigned char *buffer,
        unsigned int size);
extern int camera_eeprom_read_data(unsigned char *data,
                                   unsigned int start_addr,
                                   unsigned int data_size,
                                   unsigned int do_crc32_flag);
extern int rca_camera_eeprom_read_slight_data(CamSlightParams
        *camera_slight_parap);
extern int rca_camera_eeprom_read_para_data(camera_para_v1_st *camera_parap);
extern int rca_camera_eeprom_write_para_data(camera_para_v1_st *camera_parap);
extern int rca_camera_eeprom_write_slight_data(CamSlightParams
        *camera_slight_parap);
#elif defined(UART_API_HAVE_CV25_CAMERA) || defined(UART_API_HAVE_JA308_CAMERA)

typedef struct {
    unsigned char version;
    unsigned char dataId;
    unsigned short data_size;
    unsigned int crc;
} rrCameraHeadInfoSt;

typedef struct {
    double fx;
    double fy;
    double u0;
    double v0;
    double skew;

} intrinsic_v1_st;

typedef struct {
    double k1;
    double k2;
    double p1;
    double p2;
    double k3;

} distortion_v1_st;

#pragma pack(1)
typedef struct {
    unsigned int version;
    intrinsic_v1_st   intrinsic;
    distortion_v1_st  distortion;
    intrinsic_v1_st   rect_intrinsic;
    rrCameraHeadInfoSt cameraHead;
} camera_para_v2_st;
#pragma pack()
typedef camera_para_v2_st camera_para_v1_st;

typedef enum {
    RCA_CAMERA_EEPROM_PARA_ID = 0,
    RCA_CAMERA_EEPROM_SLITHT_ID,
    RCA_CAMERA_EEPROM_DEPTH_ID,
    RCA_CAMERA_EEPROM_MAX_ID,
}
rca_camera_eeprom_data_type_id_e;

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

// ax + by + cz + d = 0;
typedef struct {
    float a, b, c, d;
} PlanePara;

// y = kx + b
typedef struct {
    float k, b;
} LineKb;

typedef struct {
    float pitch, yaw, roll;
    float height;
} SlightParams;

typedef struct {
    float pitch;
    float roll;
    float height;
} CamExtrinsic;

typedef struct {
    unsigned int version;
    PlanePara left, right, ground;
    SlightParams left_angs, right_angs;
    CamExtrinsic cam;
    LineKb left_slight_line_img, right_slight_line_img;
    float left_slight_grd_roll, right_slight_grd_roll;
    float reserve[19];
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

#define CALIB_SUCCESS   (0)  /*!< 0, Return success*/
#define CALIB_EFAULT    (-1) /*!< -1, Bad address*/
#define CALIB_EINVALID  (-2) /*!< -2, Invalid arguement*/
#define CALIB_EPERM     (-3) /*!< -3, Operation not permitted*/
#define CAMERA_EEPROM_DISABLE_CHECK         0
#define CAMERA_EEPROM_ENABLE_CHECK_CRC32    1
#define CAMERA_EEPROM_ENABLE_CHECK_SUM      2

typedef unsigned int    uint32_t;
typedef unsigned short  uint16_t;
typedef unsigned char   uint8_t;

typedef struct eeprom_info {
    uint32_t dev_addr;     // device address
    uint32_t bus_id;       // bus id, depends on hardware
    uint32_t page_size;    // bytes
    uint32_t boundary;     // in Bytes.
    uint32_t slv_addr_len; // 2 bytes in ambarella demo
    uint32_t ten_bit;      // 0: 7bits, 1: 10bits
    uint32_t max_timeout;  // max write cycle in us.
    uint32_t reserved;
} eeprom_info_t;

typedef struct operate_param {
    int fd_i2c;
    struct timeval ready_time;
} op_param_t;

typedef struct calib_context {
    eeprom_info_t dev_eeprom_param;
    op_param_t op_param;
} eeprom_ctx_t;

extern int rca_camera_do_cal_crc32(unsigned char *buffer,
                                   unsigned int size);
extern int rca_camera_eeprom_check_crc32(unsigned char *buffer,
        unsigned int size);
extern int camera_eeprom_read_data(rca_camera_id_e cameraId,
                                   unsigned char *data,
                                   unsigned int start_addr,
                                   unsigned int data_size,
                                   unsigned int do_check_flag);
extern int camera_eeprom_write_data(unsigned int cameraId,
                                    unsigned char *data,
                                    unsigned int start_addr,
                                    unsigned int data_size);
extern int rca_camera_eeprom_read_slight_data(CamSlightParams
        *camera_slight_parap);
extern int rca_camera_eeprom_read_para_data(rca_camera_id_e cameraId,
        camera_para_v1_st *camera_parap);
extern int rca_camera_eeprom_read_depth_data(
    camera_depth_para_v2_st *camera_depth_parap_v2);
extern int rca_camera_eeprom_write_para_data(rca_camera_id_e cameraId,
        camera_para_v1_st *camera_parap);
extern int rca_camera_eeprom_write_slight_data(CamSlightParams
        *camera_slight_parap);
extern int rca_camera_eeprom_write_depth_data(camera_depth_para_v2_st
        *camera_depth_parap_v2);
extern int rca_camera_read_after_dewarp_info(rca_camera_id_e ids,
        camera_para_v1_st *camera_parap);
#elif defined(UART_API_HAVE_R16_CAMERA) && !defined(RR_DRV_SW_CAMERA_LASERCAM)

typedef struct {
    unsigned char version;
    unsigned char dataId;
    unsigned short data_size;
    unsigned int crc;
} rrCameraHeadInfoSt;

typedef struct {
    double fx;
    double fy;
    double u0;
    double v0;
    double skew;

} intrinsic_v1_st;

typedef struct {
    double k1;
    double k2;
    double p1;
    double p2;
    double k3;

} distortion_v1_st;


#pragma pack(1)
typedef struct {
    unsigned char main_version;
    unsigned char sub_version;
    unsigned char reserve_version[2];
    unsigned char reserve[8];
    unsigned int crc32;
} camera_version_st;
#pragma pack()

#pragma pack(1)
typedef struct {
    unsigned short major_version;
    unsigned short minor_version;
    unsigned short sub_version;
    unsigned short para_version;
    int slight_line_pwm_duty; // 线激光占空比
    int gain_register; // 摄像头标定增益的寄存值
    int laser_id;      // 0: 未指定线激光ID； 1: 100 mw 纵慧；2: 100 mw 睿熙；3: 180 mw 纵慧；4: 180 mw 睿熙
    float reserve[29];
    rrCameraHeadInfoSt cameraHead;
} camera_reserve_st;
#pragma pack()

#pragma pack(1)
typedef struct {
    unsigned int version;
    intrinsic_v1_st   intrinsic;
    distortion_v1_st  distortion;
    rrCameraHeadInfoSt cameraHead;
} camera_para_v1_st;
#pragma pack()

// ax + by + cz + d = 0;
typedef struct {
    float a, b, c, d;
} PlanePara;

// y = kx + b
typedef struct {
    float k, b;
} LineKb;

typedef struct {
    float pitch, yaw, roll;
    float height;
} SlightParams;

typedef struct {
    float pitch;
    float roll;
    float height;
} CamExtrinsic;

typedef struct  {
    float left, mid, right;
} CheckPosition;

#pragma pack(1)
typedef struct {
    int version;
    PlanePara slight_plane, ground_plane;
    SlightParams slight_angs;
    CamExtrinsic cam;
    float cam_lds_yaw;
    LineKb slight_line_img;
    CheckPosition grd, high;
    float reserve[4];
    rrCameraHeadInfoSt cameraHead;
} CamSlightParams;
#pragma pack()

typedef enum {
    CAMERA_EEPROM_CHECK_NONE,
    CAMERA_EEPROM_CHECK_CRC32,
    CAMERA_EEPROM_CHECK_SUM,
} eeprom_check_type;

extern int rca_camera_do_cal_crc32(unsigned char *buffer,
                                   unsigned int size);
extern int rca_camera_eeprom_check_crc32(unsigned char *buffer,
        unsigned int size);
extern int camera_eeprom_read_data(unsigned char *data,
                                   unsigned int start_addr,
                                   unsigned int data_size,
                                   unsigned int do_crc32_flag);

extern int rca_camera_eeprom_read_version_data(camera_version_st
        *camera_versionp);

extern int rca_camera_eeprom_read_otp_version_data(camera_version_st
        *camera_versionp);

extern int rca_camera_eeprom_read_reserve_data(camera_reserve_st
        *camera_reservep);
extern int rca_camera_eeprom_write_reserve_data(camera_reserve_st
        *camera_reservep);

extern int rca_camera_eeprom_read_para_data(camera_para_v1_st *camera_parap);
#ifdef RR_SLIGHT_VGA
extern int rca_camera_eeprom_read_para_data_org_resolution(
    camera_para_v1_st *camera_parap);
extern int rca_camera_check_dev_video_and_retry_insmod(void);
#endif
extern int rca_camera_eeprom_write_para_data(camera_para_v1_st *camera_parap);

extern int rca_camera_eeprom_read_slight_data(CamSlightParams
        *camera_slight_parap);
extern int rca_camera_eeprom_write_slight_data(CamSlightParams
        *camera_slight_parap);
extern int rca_camera_eeprom_write_swp(rca_camera_id_e ids,
                                       const unsigned char lock);

typedef enum {
    CAMERA_READ_EEPROM_OK = 0,
    CAMERA_READ_EEPROM_FILE_OK = 1,
    CAMERA_READ_EEPROM_UNKNOWN = 10,
} Camera_Read_Eeprom_Type_e;

extern int rca_camera_eeprom_read_reserve_data_retry_file(camera_reserve_st
        *camera_reservep);
extern int rca_camera_eeprom_read_para_data_retry_file(camera_para_v1_st
        *camera_parap);
extern int rca_camera_eeprom_read_slight_data_retry_file(CamSlightParams
        *camera_slight_parap);
#endif




#if defined(RR_HW_ENABLE_USB_CAMERA)
typedef enum {
    USBCAMERA_READ_EEPROM_OK = 0,
    USBCAMERA_READ_EEPROM_FILE_OK = 1,
    USBCAMERA_READ_EEPROM_UNKNOWN = 10,
} UsbCamera_Read_Eeprom_Type_e;

extern int rca_usb_camera_eeprom_write_reserve_data(camera_reserve_st
        *camera_reservep);
extern int rca_usb_camera_eeprom_read_reserve_data(camera_reserve_st
        *camera_reservep);
extern int rca_usb_camera_eeprom_read_depth_data(camera_depth_para_v2_st
        *camera_depth_parap_v2);
extern int rca_usb_camera_eeprom_write_depth_data(camera_depth_para_v2_st
        *camera_depth_parap_v2);
extern int rca_usb_camera_eeprom_read_para_data(camera_para_st *camera_parap);
extern int rca_usb_camera_eeprom_write_para_data(camera_para_st *camera_parap);
extern int rca_usb_camera_eeprom_read_otp_data(unsigned char *data);
extern int rca_usb_camera_eeprom_read_id_and_oc_data(unsigned char *data);
extern int rca_usb_camera_eeprom_read_awb_data(unsigned char *data);
extern int rca_usb_camera_eeprom_read_filtertype_data(unsigned char *data);
extern int usb_camera_eeprom_read_data(unsigned char *data,
                                       unsigned int start_addr,
                                       unsigned int data_size, eeprom_check_type check_type);
extern int rca_usb_camera_eeprom_write_swp(const unsigned char lock);
extern int rca_usb_camera_ctrl_led_at(unsigned short pwm_duty, int sleep_time);
extern int rca_usb_camera_ctrl_led(unsigned short pwm_duty);
extern int rca_usb_camera_eeprom_read_para_data_retry_file(camera_para_st *camera_parap);
extern int rca_usb_camera_eeprom_read_depth_data_retry_file(camera_depth_para_v2_st
        *camera_depth_parap_v2);
#endif

#ifdef __cplusplus
}
#endif


#endif
#endif
