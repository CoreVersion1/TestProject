/* =============================================================================
#     FileName: rua_line_laser_data_protocol.h
#         Desc:
#       Author: zhangzhanzhi
#        Email: zhangzhanzhi@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2022-06-02 15:59:34
#      History:
============================================================================= */

#ifndef __RUA_UART_LINELASER_H__
#define __RUA_UART_LINELASER_H__
#ifdef __cplusplus
extern "C" {
#endif

#ifdef UART_API_HAVE_LINE_LASER_MODULE

#define RUA_LINELASER_START_1               0xAA
#define RUA_LINELASER_START_2               0xAA
#define RUA_LINELASER_START_3               0xAA
#define RUA_LINELASER_START_4               0xAA
#define RUA_LINELASER_START                 0xAAAAAAAA

#define RUA_LINELASER_CALI_PARA_SIZE        0x8E
#define RUA_LINELASER_DATA_PARA_SIZE        0x144
#define RUA_LINELASER_ACK_SIZE              0x0D
#define RUA_LINELASER_VERSION_SIZE          0x34
#define RUA_LINELASER_PACK_GET_DISTANCE_CMD     0x02
#define RUA_LINELASER_PACK_SOFTRESET_CMD        0x0D
#define RUA_LINELASER_PACK_STOP_CMD             0x0F
#define RUA_LINELASER_PACK_ACK_CMD              0x10
#define RUA_LINELASER_PACK_GET_COE_CMD          0x12
#define RUA_LINELASER_PACK_GET_VER_CMD          0x14
#define RUA_LINELASER_PACK_TRIGER_MODE_CMD      0x26

#pragma pack(1)

/* when linelaser mcu bootup, it will sent info 10 times(no delay), then send data every 20ms. */
typedef struct {
    unsigned char  Type;              //0x56 means info
    unsigned char  BootReason;        //bootreason
    unsigned int   SoftwareCRC;       //firmwere crc
    unsigned int   JtagId;
    unsigned int   MCUDensity;        //flash info
    unsigned short SoftwareVersion;   //version
} RuaLinelaserInfo_st;

typedef struct {
    unsigned short Start;       //0xFAFA
    RuaLinelaserInfo_st Info;
    unsigned char
    CheckSum;     //info crc: from Type to SoftwareVersion, checksum += data;
} RuaLinelaserInfoF_st;         //this struct is used for drivers, not rrloader plugin

typedef struct {
    unsigned int Start;             //0xAAAAAAAA
    unsigned char DevAddr;
    unsigned char CmdCode;
    unsigned short PackOffsetAddr;
    unsigned short DataLen;
} RuaLinelaserFrameHead_st;         //this struct is used for drivers, not rrloader plugin

typedef struct {
    unsigned int Start;
    unsigned char DevAddr;
    unsigned char CmdCode;
    unsigned short PackOffsetAddr;
    unsigned short DataLen;
    unsigned char CheckSum;
} RuaLinelaserFrameSend_st;

typedef struct {
    RuaLinelaserFrameHead_st Head;
    unsigned int coe[35];
    unsigned short FramePointCount;
    unsigned char CheckSum;         //crc: from DevAddr to data, checksum += data;
} RuaLinelaserCoe_st;

//typedef struct {
//    unsigned short CaliParaLimit     : 3;    //1~6
//    unsigned short Intensity         : 3;    //max_pixel/7, 0~255
//    unsigned short RealDistance      : 10;   //0~1023mm
//} RuaLinelaserDistacePoint_st;
typedef struct {
    unsigned short DistancePara;
} RuaLinelaserDistacePoint_st;

typedef struct {
    RuaLinelaserFrameHead_st Head;
    unsigned char DoubletIndex;
    unsigned char DobuletFrameNum;
    unsigned char Reserve[2];
    RuaLinelaserDistacePoint_st DistancePoint[(RUA_LINELASER_DATA_PARA_SIZE - 4) /
                                               2];
    unsigned char CheckSum;         //crc: from DevAddr to data, checksum += data;
} RuaLinelaserDataPara_st;

typedef struct {
    float Angle;
    unsigned short Distance;
    unsigned char Confidence;
} RuaLinelaserDistacePointCali_st;

typedef struct {
    RuaLinelaserFrameHead_st Head;
    unsigned int SoftVersion;
    unsigned int HardwareVersion;
    unsigned char Reserve[44];
    unsigned char CheckSum;         //crc: from DevAddr to data, checksum += data;
} RuaLinelaserVersion_st;

typedef struct {
    RuaLinelaserDistacePointCali_st DistancePointCali[(RUA_LINELASER_DATA_PARA_SIZE
            - 4) /
            2];
    unsigned int CoeFlag;
    unsigned int TotalFrameNumCount;
    unsigned long long Timestamp;
    unsigned char RrCheckSum;
} RuaLinelaserFrame_rr_st;

#pragma pack()

extern int rua_linelaser_uart_get_distance(RuaLinelaserFrame_rr_st *pF,
        int timeout_ms);
extern int rua_linelaser_uart_get_coe(RuaLinelaserCoe_st *pCoe, int timeout_ms);
extern int rua_linelaser_uart_get_version(RuaLinelaserVersion_st *pV,
        int timeout_ms);
extern void rua_linelaser_set_triger_mode_flag(int flag);
extern int rua_linelaser_uart_send_cmd(unsigned char CmdType);
extern int rua_linelaser_uart_check_ack(unsigned char cmd_type);
extern int rua_linelaser_uart_read_enough_data(char *buf, int size,
        int timeout_ms);

extern unsigned int rua_linelaser_pre_ts;
extern unsigned int rua_linelaser_pre_got_data_ts;
#endif

#ifdef __cplusplus
}
#endif
#endif /*__RUA_UART_LINELASER_H__*/

