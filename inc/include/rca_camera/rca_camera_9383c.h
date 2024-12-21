#ifndef __RCA_CAMERA_9383C_H__
#define __RCA_CAMERA_9383C_H__

#include "rca_camera_common.h"

#if defined(UART_API_HAVE_CAMERA_2C1L)
#include "rca_camera_2C1L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_1C1L)
#include "rca_camera_1C1L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_ONLY_IR)
#include "rca_camera_only_ir.h"
#endif
extern int rca_camera_init_ids_org_resolution(rca_camera_id_e ids);
extern int rca_camera_start_capture_org_resolution(rca_camera_capture_callback
        cb,
        rca_camera_type_e eType);
extern int rca_camera_start_capture(rca_camera_capture_callback cb,
                                    rca_camera_type_e eType,
                                    rca_camera_id_e ids);

extern int rca_camera_stop_capture(rca_camera_id_e ids);
extern rca_camera_state_e rca_camera_state(rca_camera_id_e ids);

#endif
