#ifndef __RCA_CAMERA_MR536_H__
#define __RCA_CAMERA_MR536_H__

#include "rca_camera_common.h"

#if defined(UART_API_HAVE_CAMERA_2C2L)
#include "rca_camera_2C2L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_2C3L)
#include "rca_camera_2C3L.h"
#endif

#if defined(UART_API_HAVE_MR536_TOF_RGB)
#include "rca_camera_only_ir.h"
#endif

extern int rca_camera_init_ids_raw(rca_camera_id_e ids,
                                   camera_resolution_e res);
extern int rca_camera_init_ids_org_resolution(rca_camera_id_e ids);
extern int rca_camera_start_capture_org_resolution(rca_camera_capture_callback
        cb,
        rca_camera_type_e eType);
extern int rca_camera_start_capture(rca_camera_capture_callback cb,
                                    rca_camera_type_e eType,
                                    rca_camera_id_e ids);

extern int rca_camera_stop_capture(rca_camera_id_e ids);
extern rca_camera_state_e rca_camera_state(rca_camera_id_e ids);
extern int rca_tof_wp_enable(int tof_id);
extern int rca_tof_wp_disable(int tof_id);
extern int rca_camera_do_cal_crc32(unsigned char *buffer, unsigned int size);

#if defined(UART_API_HAVE_MR536_TOF_RGB)
#if defined(ENABLE_OMS_HDR)
#define TOF_FACES                (17)
#else
#define TOF_FACES                (9)
#endif


//#if defined(UART_API_HAVE_TOF_CHAOFENG)
#define TOF_WIDTH_CHAOFENG       6144
#define TOF_HEIGHT_CHAOFENG      960
#define TOF_PIXELFORMAT_CHAOFENG          V4L2_PIX_FMT_SBGGR10
#define CAMERA_TOF_LENSXYZ_BYTES            100
#define CAMERA_TOF_PILEUP_BYTES             23168
#define CAMERA_TOF_DNL_BYTES                704
#define CAMERA_TOF_TESTINFO_BYTES           16
#define CAMERA_TOF_TESTINFO_MAX_COUNT       16
#define CAMERA_TOF_MODULE_ADDRESS           0x00000
#define CAMERA_TOF_SLCRESULT_ADDRESS        0x01000
#define CAMERA_TOF_LENSXYZ_ADDRESS          0x02000
#define CAMERA_TOF_PILEUP_ADDRESS           0x024000
#define CAMERA_TOF_DNL_ADDRESS              0x030000
#define CAMERA_TOF_LENSXYZ_CRC_ADDRESS      0x02064
#define CAMERA_TOF_PILEUP_CRC_ADDRESS       0x029A80
#define CAMERA_TOF_DNL_CRC_ADDRESS          0x0302C0
#define CAMERA_TOF_TESTINFO_BASE_ADDRESS    0x04A000
#define SECTOR                              4096
#define CAMERA_TOF_MODULE_SECTOR            1//align by 4096 bytes sector
#define CAMERA_TOF_SLCRESULT_SECTOR         1//align by 4096 bytes sector
#define CAMERA_TOF_LENSXYZ_SECTOR           34//align by 4096 bytes sector
#define CAMERA_TOF_PILEUP_SECTOR            12//align by 4096 bytes sector
#define CAMERA_TOF_DNL_SECTOR               1//align by 4096 bytes sector
#define CAMERA_TOF_TESTINFO_SECTOR          1//align by 4096 bytes sectors
//#else
#define TOF_WIDTH                240
#define TOF_HEIGHT_100           (101*TOF_FACES)
#define TOF_HEIGHT_90            (91*TOF_FACES)
#define TOF_HEIGHT_40            (41*TOF_FACES)
#define TOF_HEIGHT_50            (51*TOF_FACES)
#define TOF_PIXELFORMAT_OMS          V4L2_PIX_FMT_SBGGR12
//#endif

#define TOF_PADDING              4
#define TOF_NUM                  (RR_DRV_HW_HAVE_TOF_NUM)
#define TOF_BUF_QUEUE_SIZE       (6)
#define DOUBLE_TX_TOF_VALUE      (0x14E)
#define SINGLE_TX_TOF_VALUE      (0x14F)
#define TOF_MODULE_ID_REG        (0xA841)
#define TOF_PROTECTION_REG       (0xA873)
#define TOF_PROTECTION1_REG      (0xA874)

#define TOF_FLASH_ADDRESS_BEGIN     0x66000
#define BACK_TOF_I2C       ("/dev/i2c-4")
#define FRONT_TOF_I2C      ("/dev/i2c-3")
#define FRONT_TOF_WP_GPIO  66 //PC2
//#define BACK_TOF_WP_GPIO   290 //PJ2 //mk6
#define BACK_TOF_WP_GPIO   143 //PE15 //MK8

#define TOF_DEV_VIDEO4_NAME "/dev/video4"
#define TOF_DEV_VIDEO12_NAME "/dev/video12"

#define FRONT_TOF_INIT_ERROR   (-1)
#define BACK_TOF_INIT_ERROR    (-2)

typedef enum {
    TOF_MASTER = 1,
    TOF_SLAVE,
} TOF_ID;

typedef struct _tof_init {
    unsigned int id[TOF_NUM];

    unsigned int width;
    unsigned int height;
    unsigned int pixelformat;
    unsigned int padding;           // bits was add for byte alignment
} TOF_INIT;

#pragma pack(1)
typedef struct {
    unsigned char main_version;
    unsigned char sub_version;
    unsigned char version3;
    unsigned char version4;
    unsigned char sn[16];
    unsigned char supplier;
    unsigned char lens_id;
    unsigned char reserve[15];
    unsigned char checksum;
} ModuleInfo;
#pragma pack()

#pragma pack(1)
/** @brief bin structure of each sensor's calib */
typedef struct tof_SLCResultBin {
    int32_t version;  ///< bin version
    int32_t sensor;       ///< sensor id
    float gnd[4];         ///< ground plane's formula in sensor's cs
    float yaw;            ///< sensor's yaw angle relative to odom cs
    float trans[2];       ///< sensor's translation relative to odom cs
    float gndRect[4];     ///< rectified ground plane's formula in sensor's cs
    float fov;
    int32_t spotStartRow;   //add for chaofeng module
    float reserve[8];    ///< reserve
} tof_SLCResultBin_st;
#pragma pack()

#pragma pack(1)
typedef struct {
    double lens_x;
    double lens_y;
    double lens_z;
} LENSXYZ;
#pragma pack()

#pragma pack(1)
typedef struct {
    //Internal parameter vector
    short lensxyz_main_ver;
    short lensxyz_sub_ver;
    float stretch_matrix[3];  //stretch_matrix
    float distortion_center[2];  //distortion_center
    float mapping_coefficients[4];  //mapping_coefficients
    float reserve_lensxyz[15]; // reserve for lensxyz
    int crc_lensxyz;
    //Ranging error
    short pileup_main_ver;
    short pileup_sub_ver;
    float pileup[4];   //The ranging error caused by the histogram accumulation process
    float FPPN[5760];  //Fixed ranging error per pixel
    float t0;          //Module temperature during calibration
    float opt_ref_t0;  //Optical reference for calibration
    float integral_number; //Number of points
    float tof_ref; //tof reference during calibration
    float peak_ref;    //Peak reference during calibration
    float k_temp;      //temperature compensation curve slope
    float opt_ref_peak;  //Optical reference peak for calibration
    float reserve_pileup[20];  // reserve for pileup
    int crc_pileup;
    //DNL compensation
    short dnl_main_ver;
    short dnl_sub_ver;
    float DNL_1[81];  //DNL1 compensation
    float DNL_2[81];  //DNL2 compensation
    float reserve_dnl[13];  // reserve for DNL
    int crc_dnl;
} InternalPara;
#pragma pack()

typedef struct _tof_paras {
    struct timeval t;
    unsigned int mipi_check_flag;
    //#if defined(UART_API_HAVE_TOF_CHAOFENG)
    unsigned int frame_number;
    unsigned short rx_temp; //rx_temp/10 is real temp
    unsigned short tx_temp; //tx_temp/10 is real temp
    unsigned char embd[64];
    //#endif
} TOF_PARAS;

typedef enum {
    TOF_READ_FLASH_OK = 0,
    TOF_READ_FLASH_FILE_OK = 1,
    TOF_READ_FLASH_UNKNOWN = 10,
    TOF_READ_FLASH_USERCASE_FLAG_UNKNOWN = 11,
} Tof_Read_Flash_Type_e;

//#if defined(ENABLE_OMS_HDR)
typedef struct {
    unsigned short expo1;
    unsigned short expo2;
    unsigned short expo3;
    unsigned short expo4;
} hdr_expo;

#define VIDIOC_VIN_SET_SPOT_HDR_EXPO_VALUE  _IOWR('R', 19, hdr_expo)
#define VIDIOC_VIN_SET_FLOOD_HDR_EXPO_VALUE _IOWR('R', 20, hdr_expo)
//#endif

#pragma pack(1)
typedef struct tof_oc_para {
    unsigned char reserve;
    float moudle_pitch;
    char spot_offset;
    char flood_offset;
    unsigned char compensation_flag;
    unsigned char cy_offset;
} tof_oc_para_st;
#pragma pack()

typedef void (*rca_tof_capture_callback)(
    unsigned int id, const void *buf, size_t length, TOF_PARAS *tof_paras);

extern int rca_tof_init(TOF_INIT *init);
extern int rca_tof_earse_flash_data(TOF_ID tof_id, unsigned int reg,
                                    unsigned int len);
extern int rca_tof_write_flash_data(TOF_ID tof_id, unsigned int reg,
                                    unsigned int len, unsigned char *data);
extern int rca_tof_read_flash_data(TOF_ID tof_id, unsigned int reg,
                                   unsigned int len, unsigned char *data);
extern int rca_tof_read_internal_para(TOF_ID tof_id, InternalPara *para);
extern void rca_tof_exit();
extern int rca_tof_start_capture(rca_tof_capture_callback cb);
extern int rca_tof_stop_capture();
extern int rca_get_spot_tof_reg(TOF_ID i2c_id, unsigned short reg);
extern int rca_set_tof_reg(TOF_ID i2c_id, unsigned short reg,
                           unsigned short val);
extern int rca_tof_write_mipi_rate_flag(int is_mipi_666); //0xaa: 1G ; 0xbb 666M
extern int rca_tof_read_flash_embd(TOF_ID tof_id, unsigned int reg,
                                   unsigned int len,
                                   unsigned char *data);
//#if defined(ENABLE_OMS_HDR)
extern int rca_set_front_spot_hdr_exp(hdr_expo exp);
extern int rca_set_front_flood_hdr_exp(hdr_expo exp);
extern int rca_set_back_spot_hdr_exp(hdr_expo exp);
//#else
extern int rca_set_front_spot_exp(int exp);
extern int rca_set_back_spot_exp(int exp);
extern int rca_set_front_flood_exp(int exp);
//#endif

//f_buf,f_len : front_tof; b_buf, b_len: back_tof
extern int rca_tof_read_calib(unsigned char *f_buf, unsigned int f_len,
                              unsigned char *b_buf, unsigned int b_len);
extern int rca_tof_write_calib(unsigned char *f_buf, unsigned int f_len,
                               unsigned char *b_buf, unsigned int b_len);
extern Tof_Read_Flash_Type_e rca_tof_flash_read_calib_data_retry_file(
    tof_SLCResultBin_st
    *cali_data0,
    tof_SLCResultBin_st *cali_data1);
extern int rca_tof_flash_read_internal_para_retry_file(
    InternalPara *InternalP_front,
    InternalPara *InternalP_back);
/**********************************
 0:close
 1:open
 * ********************************/
extern int rca_tof_ctl_v_illu_all(int value);
extern int rca_tof_flash_read_oc_paras(TOF_ID id, tof_oc_para_st *para);
#endif
#endif
