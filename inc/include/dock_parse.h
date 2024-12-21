/* *****************************************************************************
#     FileName: dock_parse.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-04-21 18:37:24
#      History:
***************************************************************************** */
#ifndef __DOCK_PARSE_H__
#define __DOCK_PARSE_H__

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SP_DOCK_HEADER  0xAA
#define DOCK_HEADER_SIZE            1
#define DOCK_PACKAGE_MAX_SIZE       4096
#define LOG_END_CHAR           '^'

typedef unsigned short  rua_dock_id_t;
typedef unsigned short rua_dock_st_t;
typedef int            rua_dock_err_t;
typedef unsigned short  rua_dock_size_t;
// typedef unsigned short tracking_data_id_t;

#define DOCK_LENGTH_SIZE            sizeof(rua_dock_size_t)
#define DOCK_HEADER_CRC_SIZE        sizeof(rua_crc8_t)
#define DOCK_STRUCT_LEN_SIZE        sizeof(rua_dock_st_t)
#define DOCK_ID_SIZE                sizeof(rua_dock_id_t)

#define DOCK_CRC_SIZE               sizeof(rua_crc16_t)

#define DOCK_HEADER_TOP_SIZE        (DOCK_HEADER_SIZE + DOCK_LENGTH_SIZE + DOCK_HEADER_CRC_SIZE)
#define DOCK_PACKAGE_MIN_SIZE       (DOCK_HEADER_TOP_SIZE + DOCK_ID_SIZE + DOCK_STRUCT_LEN_SIZE + DOCK_CRC_SIZE)
#define DOCK_SRC_MIN_SIZE           (DOCK_ID_SIZE + DOCK_STRUCT_LEN_SIZE)
#define DOCK_BUFFER_SIZE            ((DOCK_PACKAGE_MAX_SIZE + DOCK_HEADER_TOP_SIZE + DOCK_CRC_SIZE)<<1)

#define ADD_SYSID_DOCK_TO_BYTE(x) ((x) | 0x80)
#define ADD_SYSID_VACUUM_TO_BYTE(x) ((x) & 0x7F)

#define DOCK_PKG_LEN_LOW_ADDR   (1)
#define DOCK_PKG_LEN_HIGH_ADDR   (2)

#define DOCK_PKG_SYS_ID_4BIT(x) (((x) & 0x0F0) >> 4)
#define DOCK_PKG_LEN_LOW_4BIT(x) ((x) & 0x0F)
#define DOCK_PKG_LEN_HIGH_8BIT(x) ((x) << 4)

typedef enum {
    DOCK_COM_ID_PKGINDEXITEM    = 0x01,//index
    DOCK_COM_ID_SYS_RESET       = 0x02,
    DOCK_COM_ID_BASICINFO       = 0x03,
    DOCK_COM_ID_ANSWER          = 0x04,//index
    DOCK_COM_ID_CMD_FUNC        = 0x05,//old cmd
    DOCK_COM_ID_DOCK_STATE      = 0x06,//all dock state
    DOCK_COM_ID_CMD_WASH        = 0x07,//wash mop
    DOCK_COM_ID_CMD_DIRTY       = 0x08,//dirty det
    DOCK_COM_ID_CMD_COLLECT     = 0x09,//collect dust
    DOCK_COM_ID_CMD_DRY         = 0x0A,//dry
    DOCK_COM_ID_CMD_UVC         = 0x0B,//uvc led
    DOCK_COM_ID_CMD_CHGEN       = 0x0C,//charge en
    DOCK_COM_ID_CMD_CLEARERR    = 0x0D,//clear err and thr
    DOCK_COM_ID_CMD_TESTINFO    = 0x0E,//wr test info：7 station
    DOCK_COM_ID_CMD_DND         = 0x0F,//dont disturb
    DOCK_COM_ID_TS              = 0x10,//time stamp
    DOCK_COM_ID_MOP_REMOVER     = 0x11,//mop remover
    DOCK_COM_ID_WATER_TEMP      = 0x12,//hot water temp
    DOCK_COM_ID_FAC_TEST        = 0x20,//factory mode test

    DOCK_COM_ID_RPT_KEY         = 0x30,
    DOCK_COM_ID_RPT_ACOFF       = 0x31,

    DOCK_COM_ID_OTA_START       = 0x50,
    DOCK_COM_ID_OTA_PACKAGE,
    DOCK_COM_ID_OTA_CRC,

    DOCK_COM_ID_LOG_UPLOAD_START = 0x60,//log upload
    DOCK_COM_ID_LOG_UPLOAD_PKG,
    DOCK_COM_ID_LOG_UPLOAD_END,
    DOCK_COM_ID_BBOX_UPLOAD_FETCH,
    DOCK_COM_ID_BBOX_UPLOAD_START,
    DOCK_COM_ID_BBOX_UPLOAD_PKG,
    DOCK_COM_ID_BBOX_UPLOAD_END,

    DOCK_COM_ID_MAX,
} eRptDockPkgId_e;

#define LOG_PKG_LEN 128
typedef struct __stLogPkg__ {
    uint16_t logPkgIndex;
    uint8_t logPkg[LOG_PKG_LEN];
} LogPkg_st;

#define BBOX_PKG_LEN 128
typedef struct __stBBoxPkg__ {
    uint16_t bboxPkgIndex;
    uint8_t validLen;
    uint8_t bboxPkg[BBOX_PKG_LEN];
} BBoxPkg_st;

typedef enum {
    FAN_TYPE_100V = 0,
    FAN_TYPE_220V = 1,
    FAN_TYPE_MAX_ID,
} FAN_TYPE_ENUM;

typedef enum {
    DOCK_OTA_ANS_READY = 0,
    DOCK_OTA_ANS_CRC_ERR = -1,
    DOCK_OTA_ANS_FLASH_ERR = -2,
    DOCK_OTA_ANS_FLASH_DATA = -3,
    DOCK_OTA_ANS_MAGIC_ERR = -4,
    DOCK_OTA_ANS_INDEX_ERR = -5,
} DOCK_OTA_ANS_e;

//OTA ralated
#define RR_DOCK_OTA_START_MAGIC_BYTE        0x5A
#define RR_DOCK_OTA_PKG_LEN 128

typedef struct rptflag {
    /*
    Warning:  If you change this struct, Should modify report.c
    void save_pack_id(eCommId_e eId, RPTMsk_un *punRptPacked)
    switch(eId){
        ....
    };
    */
    uint32_t     bBumper     : 1;
    uint32_t     bDrop       : 1;
    uint32_t     bDock       : 1;
    uint32_t     bCliff      : 1;

    uint32_t     bSweep      : 1;
    uint32_t     bBrush      : 1;
    uint32_t     bFan        : 1;
    uint32_t     bKey        : 1;

} RPTFlg_st;

typedef union rptMask {
    RPTFlg_st       stBit;
    uint32_t             u32Mask;
} RPTMsk_un;

typedef struct WaitConfirm {
    RPTMsk_un   unWMask;
    int8_t          s8Value;
    uint8_t          u8Index;
    uint8_t          u8KeyValue;
    uint8_t          u8KeyIndex;
} WaitCnf_st;

enum  eBufTYpe {
    RPT_SEND_LATER = 0,
    RPT_SEND_FLUSH,
    RPT_SEND_POST
};

typedef struct BlackBoxMember {
    unsigned int charge;
    unsigned int discharge;
} BbMember_st;

typedef struct __led_st__ {
    uint16_t white: 4;
    uint16_t red: 4;
    uint16_t rsv: 8;
} Led_st;
typedef struct __stInlet__ {
    uint8_t en;
}  Inlet_st;
typedef struct __stWashRestock__ {
    uint8_t switch_valve;
    int8_t cleanpump;
    uint16_t timeout;
    //brush
}  WashRestock_st;
typedef struct __stPumpSewage__ {
    uint8_t en;
}  PumpSewage_st;
typedef struct __stDrain__ {
    uint8_t en;
}  Drain_st;
typedef struct __stAbluent__ {
    uint8_t en;
}  Abluent_st;
typedef struct __stSelfClean__ {
    int8_t pwm;
}  SelfClean_st;
typedef struct __stHotWater__ {
    uint8_t mode;
}  HotWater_st;
typedef struct __stDirty__ {
    uint8_t en;
}  Dirty_st;
typedef struct __stCollect__ {
    uint8_t en;
}  Collect_st;
typedef struct __stDry__ {
    uint8_t mode;
    uint16_t temp_low_thr;
    uint16_t temp_high_thr;
}  Dry_st;
typedef struct __stUvcLed__ {
    uint8_t mode;
}  UvcLed_st;
typedef struct __stChgEn__ {
    uint8_t mode;
}  ChgEn_st;
typedef struct __stTestInfo__ {
    uint8_t station  : 4;
    uint8_t result   : 4;
}  _TestInfo_st;
typedef struct __stDnd__ {
    uint8_t en;
}  Dnd_st;

typedef struct __stClearErr__ {
    uint8_t en;
}  ClearErr_st;

typedef struct __stOtaStart__ {
    uint8_t state;//静默/正常 升级
    uint8_t magic;
}  OtaStart_st;

#define RR_DOCK_OTA_PKG_LEN 128
typedef struct __stOtaPkg__ {
    uint16_t otaPkgIndex;
    uint8_t otaPkg[RR_DOCK_OTA_PKG_LEN];
}  OtaPkg_st;

typedef struct __stOtaChk__ {
    uint8_t en;
}  OtaChk_st;

typedef struct __stOtaAns__ {
    int8_t state;
} OtaAns_st;

//TODO:bootflag,如果B分区升级失败，crc与A分区crc不一致，此时不能搬运
typedef struct __stSysRst__ {
    uint8_t magic;
}  SysRst_st;

typedef struct __stComRptWash__ {
    uint32_t cleanTankErr    : 1;
    uint32_t sewTankErr      : 1;
    uint32_t washBoardOn     : 1;
    uint32_t abluentState    : 1;
    uint32_t selfCleanErr    : 1;
    uint32_t drainPumpErr    : 1;
    uint32_t drainValveErr   : 1;
    uint32_t drainValveOpen  : 1;
    uint32_t drainValveClose : 1;
    uint32_t hotWaterErr     : 1;
    uint32_t rsv             : 22;
} ComRptWash_st;
typedef struct __stComCollect__ {
    uint16_t acFanRun    : 1;
    uint16_t pressureErr : 1;
    uint16_t dryFanErr   : 1;
    uint16_t isDry       : 1;
    uint16_t bootflag    : 1;
    uint16_t rsv         : 11;
} ComRptCollect_st;
#define DIRTY_VALUE_NUM 12
typedef struct __stDirtyDet__ {
    uint16_t g_cali;
    uint16_t ir_cali;
    uint8_t sewPump;
    uint8_t validNum;
    uint16_t g[DIRTY_VALUE_NUM];
    uint16_t ir[DIRTY_VALUE_NUM];
} ComRptDirtyDet_st;

typedef struct __stComRptDockSta__ {
    uint32_t cleanTankErr    : 1;
    uint32_t sewTankErr      : 1;
    uint32_t washBoardOn     : 1;
    uint32_t abluentState    : 1;
    uint32_t selfCleanErr    : 1;
    uint32_t drainPumpErr    : 1;
    uint32_t drainValveErr   : 1;
    uint32_t drainValveOpen  : 1;
    uint32_t drainValveClose : 1;
    uint32_t hotWaterErr     : 1;
    uint32_t acFanRun        : 1;
    uint32_t pressureErr     : 1;
    uint32_t dryFanErr       : 1;
    uint32_t isDry           : 1;
    uint32_t bootflag        : 1;
    uint32_t rsv             : 17;
} ComRptDockSta_st;

#define PN_SN_MAX_LEN 20
#define THE_MAX_STATION 10
typedef struct __stBasicInfo__ {
    uint8_t acVolType;
    uint8_t dockType;
    uint8_t mcuType;
    uint8_t fwver[12];
    uint8_t sn[PN_SN_MAX_LEN];
    uint8_t tn[PN_SN_MAX_LEN];
    uint8_t pn[PN_SN_MAX_LEN];
    uint8_t testinfo[THE_MAX_STATION + 2];
} ComRptBasicInfo_st;

typedef struct __stDockComm__ {
    RPTMsk_un         unNeedAck;
    RPTMsk_un         unNeedReSend;

    ComRptWash_st wash;
    ComRptCollect_st collect;
    ComRptDirtyDet_st dirty;
    ComRptBasicInfo_st basicInfo;
    ComRptDockSta_st dockSta;
} DockComm_st;

/*cmd*/
typedef struct __stComCmdLed__ {
    uint8_t white : 4;
    uint8_t red   : 4;
} ComCmdLed_st;
typedef struct __stComCmdWash__ {
    ComCmdLed_st led;
    int8_t cleanPump;
    int8_t selfCleanPump;
    struct {
        uint16_t sewPump        : 1;
        uint16_t switchValve    : 1;
        uint16_t restoreTimeout : 4;
        uint16_t hotwater       : 1;
        uint16_t hotwaterMode   : 2;
        uint16_t abluent        : 1;
        uint16_t inlet          : 1;
        uint16_t outlet         : 1;
        uint16_t dirtyDet       : 1;
        uint16_t rsv            : 3;
    } cmd;
    uint8_t rsv;
} ComCmdWash_st;
typedef struct __stComCmdCollect__ {
    ComCmdLed_st led;
    struct {
        uint8_t acFan : 1;
        uint8_t rsv   : 7;
    } collect;
} ComCmdCollect_st;
typedef struct __stComCmdDry__ {
    uint8_t mode;
} ComCmdDry_st;
typedef struct __stComCmdUvc__ {
    uint8_t mode;
} ComCmdUvc_st;
typedef struct __stComCmdChgMode__ {
    uint8_t mode;
} ComCmdChgMode_st;
typedef struct __stComCmdClear__ {
    uint8_t en;
} ComCmdClear_st;
typedef struct __stComCmdDnd__ {
    uint8_t en;
} ComCmdDnd_st;
typedef struct __stComCmdTI__ {
    uint8_t value;
} ComCmdTI_st;

typedef struct __stComTS__ {
    uint64_t time;
} ComCmdTS_st;

typedef struct __stWaterTemp__ {
    uint8_t wash_hot;
    uint8_t wash_warm;
    uint8_t inject;
} ComWaterTemp_st;

typedef struct __stComCmd__ {
    ComCmdWash_st wash;
    ComCmdCollect_st collect;
    ComCmdDry_st dry;
    ComCmdUvc_st uvc;
    ComCmdChgMode_st chg;
    ComCmdClear_st clearErr;
    ComCmdDnd_st dnd;
    ComCmdTI_st testinfo;
} ComCmd_st;

extern DockComm_st     stDockComRpt;

extern RPTMsk_un   unRptMask;
extern WaitCnf_st  stWaitCnfPkg[];

int dockPackage2Src(const char *package, int size, char *src);
int dockSrc2Package(const char *src, int size, char *package);
extern int dock_get_next(char **raw_data, int *len, char **structp,
                         int *struct_size);

#ifdef __cplusplus
}
#endif

#endif
