#ifndef __RCA_CAMERA_REFACTOR_H__
#define __RCA_CAMERA_REFACTOR_H__

#include "rca_camera_common.h"

#if defined(UART_API_HAVE_CAMERA_2C1L)
#include "rca_camera_2C1L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_2C2L)
#include "rca_camera_2C2L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_2C3L)
#include "rca_camera_2C3L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_ONLY_IR)
#include "rca_camera_only_ir.h"
#endif

typedef enum {
    RCA_CAMERA_FUNC_TYPE_INVALID = 0,
    RCA_CAMERA_FUNC_TYPE_LASER,
    RCA_CAMERA_FUNC_TYPE_RGB,
    RCA_CAMERA_FUNC_TYPE_VIDEO,
    RCA_CAMERA_FUNC_TYPE_MAX,
} rca_camera_func_type_e;

typedef enum {
    RCA_CAMERA_LASER_TYPE_INVALID = 0,
    RCA_CAMERA_LASER_TYPE_1L,
    RCA_CAMERA_LASER_TYPE_2L,
    RCA_CAMERA_LASER_TYPE_3L,
    RCA_CAMERA_LASER_TYPE_1L_V,
    RCA_CAMERA_LASER_TYPE_MAX,
} rca_camera_laser_type_e;

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
extern int rca_camera_do_cal_crc32(unsigned char *buffer, unsigned int size);

int rca_tof_eeprom_check_crc32(unsigned char *buffer, unsigned int size);
int rca_tof_eeprom_check_check_sum(unsigned char *buffer, unsigned int size);
int rca_tof_eeprom_do_cal_crc32(unsigned char *buffer, unsigned int size);
int rca_camera_get_nums(void);
rca_camera_func_type_e rca_camera_id2type(rca_camera_id_e ids);
rca_camera_laser_type_e rca_camera_id2laser(rca_camera_id_e ids);

#endif
