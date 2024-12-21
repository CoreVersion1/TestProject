/* =============================================================================
#     FileName: upgrade_mcu.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-06-30 11:42:21
#      History:
============================================================================= */
#ifndef __UPGRADE_MCU_H__
#define __UPGRADE_MCU_H__

#include "rda_headers.h"
//#include "../../app/swd/def.h"

#ifdef __cplusplus
extern "C" {
#endif
#define UPDATE_SENT_RETRY 5
#define UPDATE_SENT_TIME_CONTRL
#define DELAY_FOR_MCU_UPGRADE 20 //ms

#define UPDATE_PACKAGE_LEN (2048)
#define FW_NAME_MAX_SIZE 1024

typedef enum {
    DOCK_OTA_STATE_IDLE = 0,
    DOCK_OTA_STATE_START,
    DOCK_OTA_STATE_CHECK_VER,
    DOCK_OTA_STATE_WAIT_INSTALL,
    DOCK_OTA_STATE_INSTALLING,
    DOCK_OTA_STATE_INSTALLED,
    DOCK_OTA_STATE_FAILED,
    DOCK_OTA_STATE_BUSY,
    DOCK_OTA_STATE_COMPLETE,
    DOCK_OTA_STATE_OVER,
    DOCK_OTA_STATE_MAX
} DockOtaState_e;

typedef enum {
    DOCK_OTA_ERR_CODE_UNKNOWN = 0,
    DOCK_OTA_ERR_CODE_SUCCESS = 1,
    DOCK_OTA_ERR_CODE_BASICINFO_ERROR = 2,
    DOCK_OTA_ERR_CODE_OTASTART_ERROR,
    DOCK_OTA_ERR_CODE_INSTALL_ERROR,
    DOCK_OTA_ERR_CODE_CRCCHECK_ERROR,
    DOCK_OTA_ERR_CODE_CRC_ERROR,
    DOCK_OTA_ERR_CODE_LOW_POWER,
} DockOtaErrCode_e;
typedef struct {
    int state;
    int err_code;
    int process;
} DockIrOta_st;

typedef int (*sp_dock_ota_state_cb)(DockIrOta_st *report);
typedef struct {
    sp_dock_ota_state_cb ota_state_cb;
} DockOtaUpdata_cb_t;

typedef struct {
    pthread_mutex_t mutex;
    DockOtaUpdata_cb_t cb;
    struct {
        uint8_t is_running;
        uint8_t stop_flag ;
        uint8_t ota_flag;
    } flag;
    int type;
} DockIrUpdataCtrl_t;

typedef struct {
    unsigned char  u8FwJtagType;
    unsigned char  u8FwGyroType;
    unsigned int  FwSize;
} FwCmpInfo_st;

typedef struct {
    int u32JtagId;
    int u32GyroId;
    int flashSize;
} McuCmpInfo_st;

#pragma pack(1)
typedef struct _dock_fmwinfo_data_ {
    uint8_t dock_platform_type;
    uint32_t firmware_size;
    uint32_t firmware_crc;
} dock_fmwinfo_data;
#pragma pack()

int GetBootVer(BootVer_st *stBootVer);
int upgrade_mcu(const char *fw_name, int force);
int upgrade_riscv_firmware(const char *file_name);
int riscv_fw_check_need_update(const char *fw_name);
int upgrade_mcu_if_not_match(const char *fw_name, FwInfo_st *Cur_FwInfo);
int ir_dock_upgrade(int type, const char *file_path);
int sp_dock_upgrade(int type, const char *file_path);
int sp_dock_upgrade_block(int type, const char *file_path);
int sp_dock_init(DockOtaUpdata_cb_t *cb);
int sp_dock_stop_upgrade(void);
uint8_t is_dock_ota_run(void);
int sp_dockpkg_ota(int type, const char *pkg_path);

int get_binfile_crc(const char *file_path, uint32_t *crc32);
int check_dock_fmw(uint32_t *now_crc, uint8_t *dock_type, uint8_t force);
int get_fwInfo_from_file(const char *file_name, FwInfo_st *pFwInfo,
                         uint32_t firmware_start_addr, uint32_t firmware_info_start_addr);
void free_tran_buf();
int find_match_firmware(ChipParams_st *pChipPara, char *fw_name);
int get_mcu_cmp_info_from_mcu(McuCmpInfo_st *pMcuInfo);
int get_mcu_fw_cmp_info(const char *fwname, FwCmpInfo_st *pFwInfo);
int get_mcu_m4_fw_cmp_info(const char *fwname, FwCmpInfo_st *pFwInfo);
int get_fwInfo_from_file(const char *file_name, FwInfo_st *pFwInfo,
                         uint32_t firmware_start_addr, uint32_t firmware_info_start_addr);
int get_gyro_version(ChipParams_st *pChipPara);
int is_chip_match(ChipParams_st *pChipPara, FwInfo_st stFwInfo);
int get_Gyro_id(uint8_t *pGyroID);
uint8_t getGyroVer(unsigned char u8GyroId);

#ifdef __cplusplus
}
#endif
#endif /*__UART_API_H__*/

