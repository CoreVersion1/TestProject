
/* =============================================================================
#     FileName: wifi_dock.h
#     Desc: Support host wifi softap and dock connect
#     Author: hezhifeng
#     Email: hezhifeng@roborock.com
#     HomePage: https://www.roborock.com
#     Version: 0.0.1
#     LastChange: 2021-06-08
#     History: N/A
============================================================================= */
#ifndef __RR_WIFI_DOCK_H__
#define __RR_WIFI_DOCK_H__
#ifdef __cplusplus
extern "C"
{
#endif

typedef unsigned int    uint32_t;
typedef unsigned short  uint16_t;
typedef unsigned char   uint8_t;

#ifndef AES_KEY_LEN
#define AES_KEY_LEN (16)
#endif

#ifndef MAX_ESSID_LEN
#define MAX_ESSID_LEN (32)
#endif

//this ssid len not include "roborock-"
#define DOCK_PAIR_ESSID_LEN (24)

/*dock SN*/
#define DOCK_SN_MAX_LEN  (20)

/*dock PN*/
#define DOCK_PN_MAX_LEN  (20)

/*dockTN*/
#define DOCK_TN_MAX_LEN  (20)

/*Version*/
#define DOCK_VER_MAX_LEN  (12)

/*TestInfo*/
#define DOCK_TESTINFO_MAX_LEN  (12)

#define DOCK_OTA_PKG_NAME_MAX_LEN  (128)
#define DOCK_OTA_PKG_PATH_MAX_LEN  (256)
#define DOCK_FILE_PATH_MAX_LEN     (256)
#define MAX_SW_VER_LEN  (16)
#define DOCK_OTA_PKG_MAX_SIZE      (3*1024*1024)//3M
#define DOCK_MODEL_MAX_SIZE        (4)//v1 or v5
//#define DOCK_RECV_MSG_POLL_TIME_MS (1000) //ms
#define DOCK_RECV_MSG_POLL_TIME_MS (300) //ms
#define DOCK_LAN_CHECK_PERIOD      (30) //30sec
#define DOCK_MSG_MAX_TTL           (30) // SEC  5->30
#define DOCK_BIND_MSG_MAX_TTL      (1) // SEC 
#define DOCK_OTA_RETRY_PERIOD      (20) //20s
#define DOCK_OTA_CHECK_PERIOD      (5*60) //5min

#define STR_WITH_PREFIX(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)
#define STR_EQUAL(s1, s2) (strcmp(s1, s2) == 0)
#define STR_INCLUDE(s1, s2) (strstr(s1, s2) != NULL)

#define RD_BE16(ptr) (*(ptr) << 8 | *((ptr) + 1))
#define RD_BE32(ptr) (*(ptr) << 24 | *((ptr) + 1) << 16 | *((ptr) + 2) << 8 | *((ptr) + 3))
#define WR_BE16(val, ptr)   \
    do                      \
    {                       \
        *(ptr) = (val) >> 8;  \
        *((ptr) + 1) = (val); \
    } while (0)
#define WR_BE32(val, ptr)         \
    do                            \
    {                             \
        *(ptr) = (val) >> 24;       \
        *((ptr) + 1) = (val) >> 16; \
        *((ptr) + 2) = (val) >> 8;  \
        *((ptr) + 3) = (val);       \
    } while (0)

#define ARRAY_LEN(arr) (sizeof(arr)/sizeof((arr)[0]))
#define MALLOC(size) malloc(size)
#define FREE(ptr)   \
    do              \
    {               \
        free(ptr);  \
        ptr = NULL; \
    } while (0)

#define MIN_BUF_SIZE_FOR_AES128_ECB_ENC(len) (((len) / 16 + 1) * 16)
#define MIN_BUF_SIZE_FOR_AES128_ECB_DEC(len) (len)


#define WIFI_DOCK_PROCESS_NAME "dock_wifi_pair"
#define WIFI_DOCK_RECV_FILE_PROCESS_NAME "dock_wifi_recv_file"
#define WIFI_DOCK_PAIR_INFO_CONF_PATH   "/mnt/data/wlan/dock_pair_info.conf"
#define WIFI_DOCK_BIND_INFO_CONF_PATH   "/mnt/data/wlan/dock_bind_info.conf"
#define WIFI_DOCK_PAIR_SSID_HEAD        "roborock-"
#define WIFI_DOCK_OTA_PACKAGE_DIR       "/mnt/data/.dock_update"

#define MIN_BUF_SIZE_FOR_AES128_CBC_ENC(len) (((len) / 16 + 1) * 16)
#define MIN_BUF_SIZE_FOR_AES128_CBC_DEC(len) (len)

//frame type
#define DOCK_FRAME_TYPE_LEN_FIELD_OFFSET 11
#define DOCK_FRAME_PAYLOAD_LEN_FIELD_OFFSET 13
#define DOCK_FRAME_PAYLOAD_FIELD_OFFSET 15
#define DOCK_FRAME_HEADER_LEN_WITHOUT_PAYLOAD 19
#define DOCK_FRAME_CRC_FIELD_LEN 4
#define DOCK_FRAME_MAX_LEN (2*1024)//fame header + payload + crc32
#define DOCK_FRAME_MAX_PAYLOAD_LEN ((DOCK_FRAME_MAX_LEN/16 - 1)*16 - DOCK_FRAME_HEADER_LEN_WITHOUT_PAYLOAD)
#define DOCK_FRAME_VER_1_0 "1.0"

//msg type
#define DOCK_MSG_LEN_FIELD_OFFSET 4
#define DOCK_MSG_HEADER_LEN_WITHOUT_PAYLOAD 8
#define DOCK_MSG_MAX_PAYLOAD_LEN 256
#define DOCK_MSG_MAX_LEN   (DOCK_MSG_HEADER_LEN_WITHOUT_PAYLOAD + DOCK_MSG_MAX_PAYLOAD_LEN)
#define DOCK_MSG_OK       "ok"
#define DOCK_MSG_FAIL     "fail"

//ota
#define DOCK_OTA_MAX_DOWNLOAD_LEN 2048


#define WIFI_DOCK_PORT_1        (22063)
#define WIFI_DOCK_PORT_2        (22066)
#define WIFI_DOCK_PORT_3        (22069)

#define WIFI_DOCK_LISTEN_PORT_NUM  (3)
#define MAX_CLIENT_COUNT         (2)
#define MAX_POLLFD_COUNT         (5)

#define CLOSE_FD_SAFELY(fd) \
    {                         \
        if (fd >= 0)            \
        {                       \
            close(fd);            \
            fd = -1;              \
        }                       \
    }                         \
    while (0)

typedef struct _dock_basic_info_t {
    uint8_t
    u8DockACVolMin;                         //桩集尘风机工作的最低电压 1v; 100:ACVolMin=100v
    uint8_t
    u8DockACVolMax_Min;                     //桩集尘风机工作的最高电压与最低电压差值 1v;50:ACVolMax=ACVolMin+50v
    uint8_t
    u8DockType;                             //桩类型  bit8:0_国内 1_海外
    uint8_t     u8DockMCUType;                          //桩mcu型号
    char        u8DockVersion[DOCK_VER_MAX_LEN];        //桩版本号
    char        u8DockSN[DOCK_SN_MAX_LEN];              //桩SN
    char        u8DockTN[DOCK_TN_MAX_LEN];              //桩TN
    char        u8DockPN[DOCK_PN_MAX_LEN];              //桩PN
    char        u8DockTestInfo[DOCK_TESTINFO_MAX_LEN];  //桩TESTINFO
} dock_basic_info_t;

typedef struct _dock_param_set_cmd_t {
    uint8_t u8DryNTCTempCmdLow;  //烘干温度低阈值设置1℃
    uint8_t u8DryNTCTempCmdHigh; //烘干温度高阈值设置1℃
    uint8_t bsDockLedsCmd;  //高4bit:红灯灯效控制低4bit:白灯灯效控制
    char    s8DockMopDuty;  //清洁滚刷占空比 -95~+95
    union {
        struct {
            uint8_t bDockWastePumpOn    : 1; //污水泵开关
            uint8_t bDockValueOn        : 1; //电磁阀开关
            uint8_t bDockMopGotoMid     : 1; //归中位开关
            uint8_t bAMPInletOn         : 1; //AM+进水阀开关
            uint8_t bAMPOutletValueOn   : 1; //AM+排水阀开关
            uint8_t bAMPOutletPumpOn    : 1; //AM+排水泵开关
            uint8_t bUsrAbntConfig      : 2; //清洁液投放用户设置
        } cmd;
        uint8_t value;
    } c1;

    union {
        struct {
            uint8_t bDockDryFanOn        : 2; //烘干开关
            uint8_t bDockErrTOClear      : 1; //清除超时和过流
            uint8_t bDockCollectFanOn    : 1; //集尘风机开关
            uint8_t bDockSilentMode      : 1; //勿扰模式开关
            uint8_t bDockStopIRSend      : 1; //停发寻桩码开关
            uint8_t bDockIgnoreIRErrEn   : 1; //忽略IR超时错误开关
            uint8_t bDockPwrOnRecordClr  : 1; //清除上/掉电重启记录开关
        } cmd;
        uint8_t value;
    } c2;

    uint8_t u8DockAbntDuty;                   //清洁液泵占空比
    uint8_t u8DockCleanPumpDuty;              //清水泵占空比
    uint8_t u8DockWifiCMDComTO;               //Wifi通信下发命令间隔超时时间, 单位: 1s/1
    uint8_t u8CmdReserved2;
} dock_param_set_cmd_t;

typedef struct _dock_threshold_ctrl_cmd_t {
    uint8_t u8DockMopOverCurValue; //桩滚刷过流阈值 10ma
    uint8_t u8DockInletWaterTO;    //桩给主机水箱补水超时时间 s/1
    uint8_t u8DockOutletWaterTO;   //桩抽污水超时时间 1s
    uint8_t u8DockCollectFanTO;    //桩集尘超时时间 1s
    uint8_t u8DockDryFanTO;        //烘干超时时间:10min/1 10:10*10=100min
} dock_threshold_ctrl_cmd_t;

typedef enum _dock_ctrl_cmd_e {
    DOCK_SUB_CMD_INVALID          = 0x00,
    DOCK_SUB_CMD_PARAM_SET        = 0x01,
    DOCK_SUB_CMD_THRESHOLD_CTRL   = 0x02,
    DOCK_SUB_CMD_REBOOT           = 0x03,
    DOCK_SUB_CMD_LOG_ENABLE       = 0x04,
    DOCK_SUB_CMD_UTC_SET          = 0x05,

    DOCK_SUB_CMD_MAX,
} dock_ctrl_cmd_e;


typedef struct _dock_state_t {
    uint8_t  u8DockACVol; //电网电压减掉50v ,0:低于50v;50:100v;170:220v
    uint8_t  u8DockMopCur;//桩滚刷电流 10ma/1单位
    uint16_t u16DryNTCTempNow;//烘干NTC温度 0.1℃/1单位
    union {
        struct {
            uint8_t bDockIsLBumperOn        : 1; //桩左到位
            uint8_t bDockIsMBumperOn        : 1; //桩中到位
            uint8_t bDockIsRBumperOn        : 1; //桩右到位
            uint8_t bDockIsFilterErr        : 1; //桩水槽滤网异常
            uint8_t bDockIsCleanTankErr     : 1; //桩清水箱异常
            uint8_t bDockIsWasteTankErr     : 1; //桩污水箱异常
            uint8_t bDockIsAbntErr          : 1; //桩清洁液异常
            uint8_t bDockIsMopOverCur       : 1; //桩滚刷过流
        } wash_state;
        uint8_t value;
    } s1;
    union {
        struct {
            uint8_t bDockIsCleanPumpErr     : 1; //桩清水泵异常
            uint8_t bDockIsWastePumpErr     : 1; //桩污水泵异常
            uint8_t bDockIsDustTankErr      : 1; //桩集尘桶异常
            uint8_t bDockIsPressureErr      : 1; //桩集尘压力阀异常
            uint8_t bDockIsCollectFanOn     : 1; //桩在集尘
            uint8_t bDockIsDryFanErr        : 1; //烘干风机异常
            uint8_t bDockIsDryFanOn         : 1; //在烘干
            uint8_t bAmIsCleanTankFull      : 1; //AM+清水箱满
        } state;
        uint8_t value;
    } s2;
    union {
        struct {
            uint8_t  bsDockRedLedState        : 4; //红灯灯效命令
            uint8_t  bsDockWhiteLedState      : 4; //白灯灯效命令
        } leds_state;
        uint8_t value;
    } s3;
    union {
        struct {
            uint8_t  bAMPIsInplace             : 1; //AM+在位
            uint8_t  bAMPComErr                : 1; //AM+通信异常
            uint8_t  bAMPSewagePumpErr         : 1; //AM+排水泵异常
uint8_t  bDockAbntVer              :
            1; //桩清洁液泵版本 0:不带清洁液   1:带清洁液
uint8_t  bDockPwrOnRecord          :
            1; //桩上/掉电重启记录 0:未上/掉电重启 1:上/掉电重启
            uint8_t  bAMPSewageValveDet1       : 1; //AM+污水阀光遮检测1
            uint8_t  bAMPSewageValveDet2       : 1; //AM+污水阀光遮检测2
            uint8_t  bReserved                 : 1; //保留
        } amp;
        uint8_t value;
    } s4;
    uint8_t  u8ProtocolVer;    //协议版本，当前值100(V1.0.0)
    char     s8MopDuty;        //滚刷占空比
    uint16_t u16MopOdo;        //Odo
    uint8_t  u8Reserved[4];
} dock_state_t;

typedef struct _dock_bind_info_t {
    uint32_t randomN;// 4 bytes
    char sn[DOCK_SN_MAX_LEN]; //桩SN
} dock_bind_info_t;

typedef struct _dock_bind_request_msg_t {
    dock_bind_info_t bind_info;
    dock_basic_info_t basic_info;
} dock_bind_request_msg_t;

typedef struct _wifi_dock_pair_info_t {
    char  essid[DOCK_PAIR_ESSID_LEN];//24 bytes
    uint8_t  key1[AES_KEY_LEN];//16 bytes
    uint32_t randomN;// 4 bytes
    uint16_t port;// 2 bytes
    uint16_t resved;// 2 bytes
} wifi_dock_pair_info_t;


typedef struct _wifi_dock_pair_conf_t {
    wifi_dock_pair_info_t pair_info;
    dock_bind_info_t bind_info;
} wifi_dock_pair_conf_t;

typedef enum _dock_msg_e {
    DOCK_MSG_INVALID = 0,
    DOCK_MSG_STATES = 0x01,//mcu states
    DOCK_MSG_BASIC_INFO = 0x02,//mcu basic info
    DOCK_MSG_SYS_STATE  = 0x03,//system state
    DOCK_MSG_WASHER = 0x04, //washer
    DOCK_MSG_DIRTY_PARA = 0x05, //dirty calibration params
    DOCK_MSG_MAX
} dock_msg_e;

typedef struct _dock_msg_t {
    uint32_t id;// 4 bytes
    uint32_t payload_len;// 4 bytes
    uint8_t payload[DOCK_MSG_MAX_PAYLOAD_LEN];//256 bytes
} dock_msg_t;

#pragma pack(1)
typedef struct _washer_msg_t {
    uint8_t id;// 4 bytes
    uint16_t payload_len;// 4 bytes
} washer_msg_t;
#pragma pack()

typedef enum _dock_disconnect_code_e {
    SERVER_ABORT                = 0x01,
    CLIENT_CLOSE,
    CLIENT_HEART_BEAT_LOSS,
    CLIENT_REACH_MAX,
    SOFTAP_STOP,
} dock_disconnect_code_e;

typedef enum _dock_ota_state_e {
    OTA_STATE_IDLE,
    OTA_STATE_DOWNLOADING,
    OTA_STATE_DOWNLOADED,
    OTA_STATE_WAIT_INSTALL,
    OTA_STATE_INSTALLING,
    OTA_STATE_INSTALLED,
    OTA_STATE_FAILED,
    OTA_STATE_BUSY,
    OTA_STATE_COMPLETE,
    OTA_STATE_MAX
} dock_ota_state_e;

typedef enum _dock_ota_err_code_e {
    OTA_ERR_CODE_SUCCESS = 0,
    OTA_ERR_CODE_CUSTOMIZED_ERROR = 0,
    OTA_ERR_CODE_DOWNLOAD_ERROR,
    OTA_ERR_CODE_DNS_ERROR,
    OTA_ERR_CODE_CONNECTION_ERROR,
    OTA_ERR_CODE_DISCONNECTED,
    OTA_ERR_CODE_INSTALL_ERROR,
    OTA_ERR_CODE_CANCELLED,
    OTA_ERR_CODE_LOW_POWER,
    OTA_ERR_CODE_UNKNOWN,
} dock_ota_err_code_e;

typedef enum _dock_ota_type_e {
    DOCK_OTA_TYPE_MANUAL = 0,
    DOCK_OTA_TYPE_SILENT = 1,
    DOCK_OTA_TYPE_FORCE = 2,
    DOCK_OTA_TYPE_MAX
} dock_ota_type_e;

//vacuum->dock
typedef struct _dock_ota_req_t {
    char ver[MAX_SW_VER_LEN];
    uint32_t size;
    uint32_t ota_type;
} dock_ota_req_t;

//dock->vacuum
typedef struct _dock_ota_rsq_t {
    uint32_t read_offset;
    uint32_t read_size;
} dock_ota_rsq_t;

typedef struct _dock_ota_report_t {
    int state;
    int err_code;
    int process;
} dock_ota_report_t;

typedef struct _dock_ota_ctrl_t {
    FILE *ota_fp;
    uint32_t ota_file_size;
    uint32_t ota_timeout_cnt;
} dock_ota_ctrl_t;

typedef enum _dock_file_send_state_e {
    FILE_SEND_STATE_IDLE = 0,
    FILE_SEND_STATE_READY,
    FILE_SEND_STATE_DOWNLOADING,
    FILE_SEND_STATE_DOWNLOADED,
    FILE_SEND_STATE_MAX
} dock_file_send_state_e;

typedef struct _dock_file_info_t {
    FILE *fp;//4 bytes
    char file_name[DOCK_FILE_PATH_MAX_LEN + 8];//.temp
    uint32_t file_size;//4 bytes
    uint32_t file_offset;//4 bytes
} dock_file_info_t;

typedef struct _dock_send_file_ctrl_t {
    uint32_t filename_len;//4 bytes
    uint32_t file_size;//4 bytes
    uint32_t file_offset;//4 bytes
    uint32_t data_len;//4 bytes
    char *buf;//filename+data
} dock_send_file_ctrl_t;

typedef struct _dock_sys_state_t {
    uint32_t is_reboot;//1:is rebooting, 0:normal
    uint32_t boot_reason;
    uint32_t uptime;
} dock_sys_state_t;

//callback type
//back dock pair,sn etc info
typedef void (*dock_wifi_connected_cb)(dock_basic_info_t *basic_info);
typedef int (*dock_wifi_disconnected_cb)(dock_disconnect_code_e code);
typedef int (*dock_ota_state_cb)(dock_ota_report_t *report);
typedef void (*dock_msg_cb)(dock_msg_t *msg);

// all in big endian
typedef struct _dock_frame_t {
    char ver[3]; // '1.0'
    uint32_t seq; //4bytes
    uint32_t nonce;//4bytes
    uint16_t type; //2bytes
    uint16_t payload_len;//2bytes
    uint8_t *payload;
    uint32_t crc;//4bytes
} dock_frame_t;

typedef enum _dock_frame_type_e {
    DOCK_FRAME_TYPE_INVALID = 0,
    //bind
    DOCK_FRAME_TYPE_BIND_REQ = 0x0001,//dock->vacuum
    DOCK_FRAME_TYPE_BIND_RSP = 0x0002,//vacuum->dock
    //ping
    DOCK_FRAME_TYPE_PING_REQ = 0x0010,//dock ->vacuum
    DOCK_FRAME_TYPE_PING_RSP = 0x0011,//vacuum->dock
    //dock ota
    DOCK_FRAME_TYPE_OTA_REQ  = 0x0020,//vacuum->dock
    DOCK_FRAME_TYPE_OTA_RSP  = 0x0021,//dock ->vacuum
    DOCK_FRAME_TYPE_OTA_DATA_SEND = 0x0022,//vacuum->dock
    DOCK_FRAME_TYPE_OTA_STATE_REPORT = 0x0023,//dock ->vacuum
    //dock status/info
    DOCK_FRAME_TYPE_QUERY_MSG_REQ  = 0x0030,//vacuum->dock
    DOCK_FRAME_TYPE_QUERY_MSG_RSP  = 0x0031,//dock ->vacuum
    //ctrl cmd
    DOCK_FRAME_TYPE_CTRL_CMD_SEND  = 0x0040,//vacuum->dock
    DOCK_FRAME_TYPE_CTRL_CMD_ACK   = 0x0041,//dock-->vacuum
    //disconnect
    DOCK_FRAME_TYPE_DISCONNECT     = 0x0050,//vacuum->dock
    //file trans
    DOCK_FRAME_TYPE_FILE_RECV     = 0x0060,//dock->vacuum
    DOCK_FRAME_TYPE_FILE_SEND     = 0x0061,//vacuum->dock
    //file trans
    DOCK_FRAME_TYPE_WASHER_RECV   = 0x0070,//washer->vacuum
    DOCK_FRAME_TYPE_WASHER_SEND   = 0x0071,//vacuum->washer
} dock_frame_type_e;

enum {
    WASHER_2_DOCK_SUBCMD_BASE = 0x80,
    WASHER_2_DOCK_SUBCMD_ECHOSTR = WASHER_2_DOCK_SUBCMD_BASE,

    DOCK_2_WASHER_SUBCMD_BASE = 0xC0,
    DOCK_2_WASHER_SUBCMD_ECHOSTR = DOCK_2_WASHER_SUBCMD_BASE,
};


typedef struct _wifi_dock_pair_cb_t {
    dock_wifi_connected_cb conn_cb;
    dock_wifi_disconnected_cb disconn_cb;
    dock_ota_state_cb ota_state_cb;
    dock_msg_cb msg_cb;
} wifi_dock_pair_cb_t;


/**
 * Get dock wifi bind status
 *
 * @return 0:unbinded, 1:binded .
 */
int wifi_dock_get_bind_status(void);

/**
 * Get dock wifi bind info
 * @Ouput: bind dock sn
 * @return 0:unbinded, 1:binded .
 */

/**
 * Get dock wifi bind info
 * @Ouput: pair_info
 * @return -1:failure, 0:success .
 */
int wifi_dock_get_bind_info(dock_bind_info_t *bind_info);

/**
 * Get dock wifi pair info
    1. read pair info  conf; 2. generate pair info
 * @Ouput: pair_info
 * @return -1:failure, 0:success .
 */
int wifi_dock_get_pair_info(wifi_dock_pair_info_t *pair_info);

/**
 * Get dock wifi pair and bind info from conf
 * @Ouput: wifi_dock_pair_conf_t *conf
 * @return N/A
 */
void wifi_dock_load_pair_conf(wifi_dock_pair_conf_t *conf);

/**
 *  Register callback and Init pair env
 * @Iuput: dock register callback
 * @return -1:failure, 0:success .
 */
int wifi_dock_pair_init(wifi_dock_pair_cb_t *callback);
/**
 *   dock wifi unpair, stop softap
 * @return -1:failure, 0:success .
 */
int wifi_dock_pair_deinit(void);

/**
 *  start pair thread
 * input:wifi_dock_pair_info_t *pair_info
 * @return -1:failure, 0:success .
 */
int wifi_dock_start_pair(wifi_dock_pair_info_t *pair_info);

/**
 *  disconnect dock and stop pair thread
 * @return -1:failure, 0:success .
 */
int wifi_dock_stop_pair(void);

/**
 *  disconnect dock, stop pair thread and remove pair conf
 * @return -1:failure, 0:success .
 */
int wifi_dock_destory_pair(void);

/**
 *  Send control cmd to dock
 * @input: dock_ctrl_cmd_e cmd_id ,
                cmd, for example:dock_param_set_cmd_t
                cmd_len (less than DOCK_MSG_MAX_PAYLOAD_LEN :256)
 * @return -1:failure, 0:success .
 */
int wifi_dock_ctrl_send_cmd(dock_ctrl_cmd_e cmd_id, void *cmd,
                            uint32_t data_len);
int wifi_dock_washer_send_cmd(uint8_t cmd_id, void *data, uint32_t data_len);
int wifi_dock_acked();

/**
 *  Send cmd to query dock status
 *  input :dock_msg_e msg_id
 * @return -1:failure, 0:success .
 */
int wifi_dock_msg_query_async(dock_msg_e msg_id);


/**
 *  Dock upgrade
 * @input: ota pkg file name
 * @return <0:failure, 0:success .
 */
int wifi_dock_upgrade(char filename[DOCK_OTA_PKG_NAME_MAX_LEN + 1]);
/**
 *  Dock upgrade
 * @input: param1: ota pkg file name, param2: ota type
 * @return <0:failure, 0:success .
 */
int wifi_dock_upgrade_ex(char filename[DOCK_OTA_PKG_NAME_MAX_LEN + 1],
                         dock_ota_type_e ota_type);

/**
 *  Get Dock ota state
 * @input: ota pkg file path
 * @return dock_ota_state_e ota_state .
 */
int wifi_dock_get_ota_state(void);

/**
 *  Get server running state
 * @input: void
 * @return 1:running, 0: not running;
 */
int wifi_dock_get_server_is_running(void);


/**
 *  One key start connect and pair server, not register callback, just for test
 * @input:N/A
 * @return -1:failure, 0:success .
 */
int wifi_dock_one_key_pair(void);

//Test send  cmd
int dock_wifi_set_cmd_test(void);

#ifdef __cplusplus
}
#endif
#endif  //__RR_WIFI_DOCK_H__

