#ifndef __RCA_TOF_REFACTOR_H__
#define __RCA_TOF_REFACTOR_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define TOF_MAX_NUM   2

typedef enum {
    RCA_TOF_ID_INVALID = -1,
    RCA_TOF_ID_0 = 0,
    RCA_TOF_ID_1,
    RCA_TOF_ID_MAX,
} rca_tof_id_e;

typedef enum {
    RCA_TOF_VENDOR_TYPE_INVALID = -1,
    RCA_TOF_VENDOR_TYPE_CHAOFENG = 0,
    RCA_TOF_VENDOR_TYPE_OMS = 0,
    RCA_TOF_VENDOR_TYPE_MAX,
} rca_tof_vendor_type_e;

typedef enum {
    RCA_TOF_POS_INVALID = -1,
    RCA_TOF_POS_FRONT_0 = 0,
    RCA_TOF_POS_BACK_0,
} rca_tof_pos_e;

typedef enum {
    RCA_TOF_MS_INVALID = -1,
    RCA_TOF_MS_MASTER_0 = 0,
    RCA_TOF_MS_SLAVE_0,
} rca_tof_ms_e;

enum {
    RCA_TOF_GET_TEMP = 0,
    RCA_TOF_GET_BIT_RESULT,
};

enum {
    WORK_MODE_MASTER = 0,
    WORK_MODE_SLAVE = 1,
};

enum {
    RCA_TOF_SET_WORK_MODE = 0,
};

// typedef enum {
//     RCA_TOF_EEPROM_ID_LENSXYZ = 0,
//     RCA_TOF_EEPROM_ID_PILEUP = 1,
//     RCA_TOF_EEPROM_ID_DNL = 2,
// }


// typedef struct {
//     int id;
//     unsigned int lens;
//     char* buf;
// } rca_tof_eeprom_data_t;

typedef struct {
    struct timeval t;
    unsigned int mipi_check_flag;
    //#if defined(UART_API_HAVE_TOF_CHAOFENG)
    unsigned int frame_number;
    unsigned short rx_temp; //rx_temp/10 is real temp
    unsigned short tx_temp; //tx_temp/10 is real temp
    unsigned char embd[64]; //need remove
    unsigned int single_size;
    unsigned int single_height;
    unsigned int single_width;
    unsigned char *datap;
    unsigned long long exposure_time;
    unsigned int sensitivity;
} rca_tof_data_t;

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
typedef struct tof_oc_para {
    unsigned char reserve;
    float moudle_pitch;
    char spot_offset;
    char flood_offset;
    unsigned char compensation_flag;
    unsigned char cy_offset;
} tof_oc_para_st;
#pragma pack()

typedef void (*rca_tof_capture_callback)(rca_tof_id_e tof_id,
        rca_tof_data_t *p_tof_data);

typedef struct {
    char name[32];
    rca_tof_vendor_type_e vendor_type;
    rca_tof_pos_e pos;
    rca_tof_ms_e ms;
    rca_tof_id_e id;
} rca_tof_board_info_t;

int rca_tof_init(rca_tof_id_e tof_id);
void rca_tof_exit(rca_tof_id_e tof_id);
int rca_tof_start_capture(rca_tof_id_e tof_id, rca_tof_capture_callback cb);
int rca_tof_stop_capture(rca_tof_id_e tof_id);
int rca_tof_ctl_get(rca_tof_id_e tof_id, int cmd, void *data);
int rca_tof_ctl_set(rca_tof_id_e tof_id, int cmd, void *data);

int rca_tof_earse_flash_data(rca_tof_id_e tof_id, unsigned int reg,
                             unsigned int len);
int rca_tof_write_flash_data(rca_tof_id_e tof_id, unsigned int reg,
                             unsigned char *data, unsigned int len);
int rca_tof_read_flash_data(rca_tof_id_e tof_id, unsigned int reg,
                            unsigned char *data, unsigned int len);
int rca_tof_read_internal_para(rca_tof_id_e tof_id, unsigned char *buf,
                               unsigned int len, int retry_from_file);
int rca_tof_read_calib(rca_tof_id_e tof_id, unsigned char *buf,
                       unsigned int len, int retry_from_file);
int rca_tof_write_calib(rca_tof_id_e tof_id, unsigned char *buf,
                        unsigned int len);

int rca_tof_get_nums(int *nums);
int rca_tof_get_board_info(rca_tof_board_info_t *info,
                           int nums); //杩斿洖鍊间负杩斿洖鐨刬nfo鏁伴噺

rca_tof_pos_e rca_tof_id2pos(rca_tof_id_e tof_id);
rca_tof_id_e rca_tof_pos2id(rca_tof_pos_e tof_pos);
int rca_tof_id2index(rca_tof_id_e tof_id);
rca_tof_id_e rca_tof_index2id(int index);
int rca_tof_index2node(int index);
rca_tof_vendor_type_e rca_tof_index2vendor(int index);
int rca_tof_eeprom_check_crc32(unsigned char *buffer, unsigned int size);
int rca_tof_eeprom_check_check_sum(unsigned char *buffer, unsigned int size);
int rca_tof_eeprom_do_cal_crc32(unsigned char *buffer, unsigned int size);
#ifdef __cplusplus
}
#endif

#endif
