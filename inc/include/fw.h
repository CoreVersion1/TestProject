/* =============================================================================
#     FileName: fw.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-06-26 13:59:23
#      History:
============================================================================= */
#ifndef __FW_H__
#define __FW_H__

#ifdef __cplusplus
extern "C" {
#endif


#define FW_MAGIC 0xa5a53ac6
#define RR_BOOTVER_MAGIC 0x5A5AC33D

#define FW_LEAVE    64
#define RR_FLASH_BASE_ADDR                      (0x08000000)
#define VERSION_OFFSET                0x4000

#define RR_FLASH_BLD_START_ADDR        0x08000000
#if defined(UART_API_MCU_ARCH_GD32F303ZBT6)
#define RR_FLASH_BLD_END_ADDR          0x080067FF
#else
#define RR_FLASH_BLD_END_ADDR          0x08007FFF
#endif
#define RR_FLASH_BLD_SIZE             (RR_FLASH_BLD_END_ADDR - RR_FLASH_BLD_START_ADDR + 1)
#define RR_FLASH_BLD_VER_ADDR         (RR_FLASH_BLD_START_ADDR + VERSION_OFFSET)

#if defined(UART_API_MCU_ARCH_GD32F303ZBT6)
#define RR_FLASH_FW_START_ADDR         0x08007800
#define RR_FLASH_FW_END_ADDR           0x0801FFFF
#else
#define RR_FLASH_FW_START_ADDR         0x0800C000
#define RR_FLASH_FW_END_ADDR           0x0803FFFF
#endif
#define RR_FLASH_FW_SIZE              (RR_FLASH_FW_END_ADDR - RR_FLASH_FW_START_ADDR + 1)
#define RR_FLASH_FW_VER_ADDR          (RR_FLASH_FW_START_ADDR + VERSION_OFFSET)

typedef enum {
    UPGRDAE_INFO_INDEX   = 0x0,
    //index define start from 0x1;
    UPGRDAE_INDEX0       = 0x1,
    UPGRDAE_INDEX1       = 0x2,
    UPGRDAE_INDEX2       = 0x3,
    UPGRDAE_INDEX3       = 0x4,
    UPGRDAE_INDEX4       = 0x5,
    UPGRDAE_INDEX5       = 0x6,
    UPGRDAE_INDEX6       = 0x7,
    UPGRDAE_INDEX7       = 0x8,
    UPGRDAE_INDEX8       = 0x9,
}
UpdateIndex_e;
#define UPGRADE_INDEX_SIZE 1

typedef struct {
    //magic should be FW_MAGIC_V2
    unsigned int u32FirmwareMagic;
    unsigned int u32FirmwareSize;
} FirmwareBase_st;

typedef struct {
    unsigned char bA;
    unsigned char bC;
    unsigned char bE;
    unsigned char bG;
    unsigned char bI;
    unsigned char bK;
    unsigned char bM;
    unsigned char bO;
    unsigned char bQ;
    unsigned char bS;
    unsigned char bU;
    unsigned char bW;
    unsigned char bY;
} Hardware_st;

typedef union {
    Hardware_st stHardware;
    unsigned char aHardware[13];
} Hardware_u;
typedef struct {
    unsigned int FirmwareTs;
    Hardware_u FirmwareHardware;
    char FirmwareProject;                           //new mapto
    unsigned char FirmwareVerMajor;
    unsigned char FirmwareVerMinor;
    unsigned char FirmwareVerBuild;
    char FirmwareBuidType;
    char FirmwareBuilder[10];
    char aReserved2[2];
} FirmwareVer_st;

//sizeof(FwInfo_st) should equal FW_LEAVE
typedef struct {
    FirmwareBase_st stFirmwareBase;
    FirmwareVer_st stFirmwareVer;
} FwInfo_st;

typedef struct {
    FwInfo_st fw_info;
    //we still sent total_size to mcu;
    char path_name[256];
    char *fw_data;
} FwInfoAndAddr_st;

typedef struct {
    unsigned int package_size;
    FwInfo_st fw_info;
} FwInfo2Mcu_st;
typedef struct {
    unsigned int  u32Magic;
    unsigned int  u32Ts;
    unsigned char u8Major;
    unsigned char u8Minor;
    unsigned char u8Build;
    unsigned char u8Type; //0:Debug, !0:Release
    unsigned int u32firmware_offset;
    unsigned int u32commit_id;
    unsigned char aReserved[8];
} BootVer_st;

#define CHIP_INFO_STM32_JTAG_ID      (0x41U)
#define CHIP_INFO_GD32_JTAG_ID       (0x7a3U)
#define CHIP_INFO_AT32_JTAG_ID       (0x477U)
#define CHIP_INFO_N32_JTAG_ID        (0x455U)
#define CHIP_INFO_N32G031_JTAG_ID    (0x031U)
#define CHIP_INFO_STM32F402_DEVICE_ID        (0x423U)
#define CHIP_INFO_HK32_JTAG_ID       (0x440U)
#define CHIP_INFO_HK32F103_JTAG_ID   (0x5abU)
#define CHIP_INFO_RISCV_JTAG_ID      (0xFFFFU)
#define CHIP_INFO_RISCV_FLASH_SIZE   (0x200U)
#define CHIP_INFO_FLAHS_SIZE_ADDR    (0x1FFFF7E0)
#define CHIP_INFO_FLAHS_M4_SIZE_ADDR (0x1FFF7A20)
#define CHIP_INFO_FLASH_SIZE_MASK    (0xFFFF)


#define CHIP_INFO_GD103_PID         (0x42435633)  //GD32F103VCT6
#define CHIP_INFO_GD303_PID         (0x46435633)  //GD32F303VCT6
//#define CHIP_INFO_GD32F103VET6_PID  ()          //GD32F103VET6
#define CHIP_INFO_GD32F303VET6_PID  (0x46455633)  //GD32F303VET6
#define CHIP_INFO_GD32F303ZET6_PID  (0x46455a33)  //GD32F303ZET6  for Garnet.
#define CHIP_INFO_GD32F303VGT6_PID  (0x46475633)  //GD32F303VGT6
#define CHIP_INFO_GD32F205VET6_PID  (0x43455635)
#define CHIP_INFO_GD32_PID_ADDR     (0x40022100)

typedef struct {
    unsigned int  u32JtagID;
    unsigned int  u32FlashSize;
    unsigned int  u32PriID;
    unsigned int  u32reserve2;
} ChipInfo_st;

typedef enum {
    DEVINFO_ARCH_INVALID        = -1,
    DEVINFO_ARCH_STM32          = 1,
    DEVINFO_ARCH_STM32F103VET6  = 1,   //same as default stm32
    DEVINFO_ARCH_GD32F103VCT6   = 2,
    DEVINFO_ARCH_STM32F103VCT6  = 3,
    DEVINFO_ARCH_STM32F103ZDT6  = 4,
    DEVINFO_ARCH_GD32F303VCT6   = 5,
    DEVINFO_ARCH_GD32F330F4P6   = 6,
    DEVINFO_ARCH_GD32F303VET6   = 7,
    DEVINFO_ARCH_GD32F303ZET6   = 8,
    DEVINFO_ARCH_STM32F103ZET6  = 9,
    DEVINFO_ARCH_GD32F330F8P6   = 10,
    DEVINFO_ARCH_AT32F421F4P7   = 11,
    DEVINFO_ARCH_AT32F421F8P7   = 12,
    DEVINFO_ARCH_AT32F403AVCT7  = 13,
    //DEVINFO_ARCH_AT32F403AVCT7  = 14,
    DEVINFO_ARCH_N32G455VEL7  = 14,

    DEVINFO_ARCH_GD32F103VET6  = 15,
    DEVINFO_ARCH_HK32F103VET6  = 16,
    DEVINFO_ARCH_HK32F030F4P6  = 17,
    DEVINFO_ARCH_STM32F402VCT6 = 18,
    DEVINFO_ARCH_GD32F303VGT6  = 19,
    DEVINFO_ARCH_GD32F205VET6  = 20,
    DEVINFO_ARCH_N32G031F8S7   = 21,

    DEVINFO_ARCH_STM32F103RB   = 22,
    DEVINFO_ARCH_N32L406RB     = 23,

    DEVINFO_ARCH_GD32F303ZBT6  = 24,
    DEVINFO_ARCH_RISCV         = 25,
} RR_Arch_e;

typedef struct {
    RR_Arch_e   rr_arch_id;
    const char  name[24];
    Hardware_u FirmwareKey;
    Hardware_u FirmwareKeyMask;
    ChipInfo_st info;
} ChipParams_st;


extern int fw_check(const char *buf, unsigned int len, FwInfo_st *fw_info);
extern int CalFirmwareBase(const char *buf, int len,
                           FirmwareBase_st *stFirmwareBaseTmp);
extern char *FwBase2Str(const FirmwareBase_st *stFirmwareBase);
extern char *FwVer2Str(const FirmwareVer_st *stFirmwareVer);
extern char *FwInfo2Str(const FwInfo_st *stFwInfo);
extern char *BootVer2Str(const BootVer_st *stBootVer);
extern char *FwInfo2SingleStr(const FwInfo_st *stFwInfo);
extern int Hardware2Str(const Hardware_u *uHardwarep, char *strp, int max_size);
extern const ChipParams_st *lookup_arch(const ChipInfo_st *stChipInfop);
extern const char *rua_arch_id_to_name(RR_Arch_e id);


#ifdef __cplusplus
}
#endif
#endif


