/* =============================================================================
#     FileName: rua_uart_lds.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2018-08-07 15:37:30
#      History:
============================================================================= */

#ifndef __RUA_UART_CARPET_H__
#define __RUA_UART_CARPET_H__
#ifdef __cplusplus
extern "C" {
#endif

#ifdef UART_API_HAVE_CARPET

#define RUA_CARPET_DATA_EACH_TIMEMS      20

typedef enum {
    RUA_CARPET_BOOTREASON_POWER_ON = 0x1,
    RUA_CARPET_BOOTREASON_PIN_RST  = 0x2,
    RUA_CARPET_BOOTREASON_WDT_RST  = 0x4,
    RUA_CARPET_BOOTREASON_SOFT_RST = 0x8,
}
RuaCarpetBootReason_e;

#pragma pack(1)

/* when carpet mcu bootup, it will sent info 10 times(no delay), then send data every 20ms. */
typedef struct {
    unsigned char  Type;              //0x56 means info
    unsigned char  BootReason;        //bootreason
    unsigned int   SoftwareCRC;       //firmwere crc
    unsigned int   JtagId;
    unsigned int   MCUDensity;        //flash info
    unsigned short SoftwareVersion;   //version
} RuaCarpetInfo_st;

typedef struct {
    unsigned short Start;             //0xFAFA
    RuaCarpetInfo_st Info;
    unsigned short
    CheckSum;          //info crc: from Type to SoftwareVersion, checksum += data;
} RuaCarpetInfoF_st;                  //this struct is used for drivers, not rrloader plugin


typedef struct {
    unsigned short PeakNum;           //peak num
    unsigned short SampleNum;         //100
    unsigned short PeakIndex[20];
    unsigned short PeakSample[20];
    unsigned int   SampleSum;
    unsigned short SampleMax;
    unsigned short Padding[3];        //unused, only for data aes encryto align
} RuaCarpetData_st;

typedef struct {
    unsigned char  Index;             //[0,255]
    RuaCarpetData_st Data;
} RuaCarpetFrame_st;

// this struct is @firmware end - sizeof(), swd will read it for check current firmware if equal
typedef struct  {
    unsigned short version;
    unsigned char  arch;
    unsigned char  reserve;
    unsigned int
    firmware_crc; //because carpet firmware has self check code, so at last has this crc
} RuaCarpetVersion_st;

#pragma pack()

extern int  rua_carpet_uart_get_frame(RuaCarpetFrame_st *pF,
                                      unsigned int max_lengh, int timeout_ms);
extern int rua_get_carpet_decode_data(RuaCarpetFrame_st *pF,
                                      RuaCarpetMessage_st *carpet_buff, unsigned int lengh);


extern RR_Arch_e rua_carpet_uart_info_to_arch(RuaCarpetInfo_st *pI);
extern unsigned int rua_carpet_pre_ts;
extern unsigned int rua_carpet_pre_got_data_ts;
#endif

#ifdef __cplusplus
}
#endif
#endif /*__UART_API_H__*/

