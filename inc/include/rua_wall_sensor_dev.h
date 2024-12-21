/* =============================================================================
#     FileName: rua_wall_sensor_dev.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2020-05-30 14:33:30
#      History: none
============================================================================= */

#ifndef __RUA_WALL_SENSOR_DEV_H__
#define __RUA_WALL_SENSOR_DEV_H__

#if defined(RR_DRV_HW_VLINE_WALL_SENSOR)

#define     RUA_WALL_SENSOR_BAUDRATE              (380400)

#define     RUA_WALL_SENSOR_DATA_WIDTH            8
#define     RUA_WALL_SENSOR_PARITY                'N'
#define     RUA_WALL_SENSOR_STOP_BIT              1
#define     RUA_WALL_SENSOR_LOCK_UART             1

#define UART_WALL_SENSOR_IOCTL    0x59
#define UART_WALL_SENSOR_IOCTL_SET_BUFFSER_SIZE _IOW(UART_WALL_SENSOR_IOCTL, 0x10, int)

#ifdef __cplusplus
extern "C" {
#endif

#define RUA_WALL_SENSOR_POINT_SIZE (100)
#define WALL_SENSOR_CAL_FILE UART_API_PARTITION_RESERVE_DIR"/wall_sensor_cal.ini"
#define WALL_SENSOR_GROUND_CAL_FILE UART_API_PARTITION_RESERVE_DIR"/wall_sensor_ground_cal.ini"
typedef struct wall_sensor_data {
    signed int x: 12;
    unsigned int y: 10;
    unsigned int valid: 1;
    unsigned int filter: 1;
    unsigned int luma: 8;
} wall_sensor_data_st;

typedef struct {
    unsigned short          header;                                     //size 2
    unsigned short          id: 2;                                      //size 1
    unsigned short          type: 6;                                    //size 1
    unsigned short          n_point: 8;
    unsigned int            ms;                                         //size 4
    wall_sensor_data_st
    data[RUA_WALL_SENSOR_POINT_SIZE];               //size 4 * 100
    unsigned char           reserved0;                                  //size 1
    unsigned char           reserved1;                                  //size 1
    unsigned short          check_sum;                                  //size 2
} RuaWallSensorAttributes_st;

typedef union {
    RuaWallSensorAttributes_st  wallSensor_attributes;
    unsigned char               data_octal[412];
    unsigned short              data_hex[206];
} RuaWallSensorInfo_u;

typedef struct _OverAllParam {
    float pitch;
    float roll;
    float yaw;
    float height;
    float dy;
} OverAllParam;

typedef enum {
    WS_DEV_NONE = 0,
    WS_DEV_HC,
    WS_DEV_LD,
} wall_sensor_dev;

typedef struct _GetAllParam {
    wall_sensor_dev dev_type;
    OverAllParam WsAllParam;
} GetWsAllParam;

typedef struct ground_calc_para {
    float para_1;
    float para_2;
} ground_calc_para_st;

typedef struct L3CS_Point3d1 {
    float x;
    float y;
    float z;
} L3CS_Point3d_st;

typedef struct L3CS_Point2d1 {
    float x;
    float y;
} L3CS_Point2d_st;

typedef struct vline_ws_dev_info {
    uint8_t len[2];
    uint8_t factoryInfo[2];
    uint8_t product[4];
    uint8_t ver[4];
    uint8_t sn[32];
    uint8_t reserve[4];
} vline_ws_dev_info;

typedef struct vline_ws_angle_para {
    uint16_t head;
    uint8_t id;
    uint8_t len;
    float pitch;
    float roll;
    float yaw;
    uint16_t pad;
    uint16_t checksum;
} vline_ws_angle_para_t;

typedef union {
    vline_ws_dev_info  info;
    unsigned char      data[48];
} vline_ws_dev_info_st;


#define MAGIC_GD_L2             0x324C4447// GDL2
#define HEAD_PKG                0x55
#define UPGRDE_PKG              0x0E
#define STOP_PKG                0x0d
#define ADDR_PKG                0x0a

// cmd
enum eUPDATE {
    UPDATE_CMD_START = 0,
    UPDATE_CMD_DATA_START = 1,
    UPDATE_CMD_DATA = 2,
    UPDATE_CMD_DATA_END = 3,
    UPDATE_CMD_REBOOT = 4
};

enum UPDATEErrorCode {
    //空闲
    IDLE = 0,
    //升级数据包校验和错误
    ERROR_UPDATE_CHECKSUM,
    //升级的固件不匹配
    ERROR_UPDATE_FILTER,
    //升级顺序错误
    ERROR_UPDATE_SEQ,
    //FW checksum is error
    ERROR_UPDATE_FW_CHECKSUM
};


//head
typedef struct {
    unsigned short head;// 0x0E55
    uint8_t id : 2;
    uint8_t err : 3;
    uint8_t update_cmd : 3;
    uint8_t seq_k;
} update_head;

//发送以及接受命令包结构
typedef struct {
    update_head pkg_head;               //包头
    unsigned int filter;                //升级匹配标准
    unsigned int descriptor;            //升级描述标准
    unsigned short fw_checksum;
    unsigned short pck_checksum;        // 包校验和
} UPGRDE_FARMWARE_PKG;

//数据发送命令包结构
typedef struct {
    update_head pkg_head;               //包头
    unsigned short valid_len;           //数据长度
    unsigned char data[2048];           //数据
    unsigned short pck_checksum;        //包校验和
} UPGRDE_DATA_PKG;

extern int upgrade_vline_wall_sensor_dev(void);
extern int upgrade_vline_wall_sensor_dev_force(void);

extern int rua_wall_sensor_uart_get_raw(char *buf, int max_lengh,
                                        int timeout_ms);
extern int get_vline_ws_dev_info(vline_ws_dev_info_st *pDevInfo);
extern int get_vline_ws_angle_para(vline_ws_angle_para_t *pDevInfo);
extern int rua_wall_sensor_init_uart();
extern void rua_wall_sensor_uart_close();
extern void rua_wall_sensor_uart_clean();
extern int get_wall_sensor_package(char *buf, int max_lengh);
extern uint16_t get_wall_sensor_data_checksum(unsigned char *data,
        uint16_t len);
extern int rua_wall_sensor_uart_sent_raw(const char *buf, int len);
extern int is_wall_sensor_tty_inited();
extern int rua_wall_sensor_write_cali_value(float pitch, float roll, float yaw,
        float hight, float dy);
extern int rua_wall_sensor_write_ground_cali_value(float para_1, float para_2);
extern int pointRegisterL3CS(L3CS_Point2d_st *pDstPoints,
                             wall_sensor_data_st *pSrcPoints, int size, wall_sensor_dev dev_type);
extern int get_calc_para(GetWsAllParam *pCalcPara);
extern int init_calc_para(OverAllParam *pCalcPara);
extern int start_wall_sensor(void);
extern int stop_wall_sensor(void);
#ifdef __cplusplus
}
#endif

#endif
#endif
