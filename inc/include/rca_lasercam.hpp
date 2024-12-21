#ifndef _RR_RCA_LASERCAM_H_
#define _RR_RCA_LASERCAM_H_

typedef enum {
    TYPE_HC_F2YS = 0,
    TYPE_LD_20N2 = 1,
    TYPE_NOCAM = 2,
} lasercam_vendor_e;

typedef enum {
    STATUS_APP = 0,
    STATUS_BOOTLOADER,
    STATUS_NO_LASERCAM,
} lasercam_status_e;

typedef struct {
    lasercam_vendor_e vendor;
    lasercam_status_e status;
} CamStatus;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RR_DRV_SW_CAMERA_LASERCAM
extern int get_lasercam_vendor();
extern int update_Bin_api();
extern CamStatus get_status();
extern int update_Bin_LD_bootloader(const char *filePath);
extern int update_Bin_HC_bootloader(const char *filePath);
extern int update_vendor_info(int vendor);
#endif

#ifdef __cplusplus
}
#endif
#endif