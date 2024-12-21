/* =============================================================================
#     FileName: rda_headers.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2019-03-05 10:21:00
#      History:
============================================================================= */
#ifndef __RR_DRIVERS_API_HEADERS_H__
#define __RR_DRIVERS_API_HEADERS_H__

#include <stdint.h>

/* uart_api_config.h must be the first include*/
#include "uart_api_config.h"

#include "rr_product_version_define.h"
#include "common_mcu.h"
#include "rla_log.h"
#include "rma_misc.h"

#include "rla_pcmd.h"
#include "rua_ini_rw.h"
#include "rua_file_rw.h"
#include "fw.h"
#include "data_parse.h"
#include "dock_parse.h"
#include "upgrade_mcu.h"
#include "system_state.h"
#include "mcu_communication.h"
#include "rpmsg_communication.h"
#include "rca_camera.h"
#include "rca_image_yuv2bmp.h"
#include "rua_fifo.h"
#include "rua_uart_common.h"
#include "rua_mcu_dev.h"
#include "rua_lds_dev.h"
#include "rua_sp_dock_dev.h"
#include "dock_communication.h"
#include "rua_arm_rx485_dev.h"
#include "rpmsg_dev.h"
#include "rua_wall_sensor_dev.h"
#include "rua_carpet_dev.h"
#include "rua_carpet_data_protocol.h"
#include "rua_line_laser_dev.h"
#include "rua_line_laser_data_protocol.h"
#include "rua_swd.h"
#include "rua_factory.h"

#include "raa_audio.h"
#include "rda_ap_led.h"
#include "raa_motor.h"

#include "verify.h"

#include "bl.h"
#include "rv_load.h"
#include "rua_temperature.h"
#include "rr_slight_dev.h"
#include "rr_slight_carpet_dev.h"
#include "rr_gradient_points_dev.h"
#include "raa_sensor_brushlift.h"
#include "raa_sensor_water_pump.h"

#ifdef UART_API_HAVE_AP_MOUSE
#include "mouse.h"
#endif

#ifdef UART_API_HAVE_BAIDU_MIC
#include "upgrade_aimic.h"
#endif

#ifdef RR_DRV_SW_MIC
#include "rua_baidu_soft.h"
#endif

#ifdef UART_API_HAVE_AP_SWITCHES
#include "raa_sensor_switches.h"
#endif

#ifdef RR_DRV_HW_CPU_FAN
#include "rr_cpu_fan.h"
#endif

#ifdef UART_API_HAVE_AP_TOP_DTOF
#include "dtof_dev.h"
#endif

#if defined(UART_API_HAVE_BAROMETER)
#include "raa_sensor_barometer.h"
#endif

#include "rr_ap_motor.h"

#include "rua_fan_id_detect.h"

#include "rva_verify_sign.h"
#include "rva_sha256.h"
#include "rva_base64.h"
#include "rma_file_combine.h"
#include "rma_coredump.h"
#include "rua_ap_cfg_para.h"
#include "rua_fan.h"

#include "wifi_hal.h"
#ifdef RR_DRV_SW_BLUETOOTH
#include "rr_ble.h"
#endif
#ifdef RR_HW_ENABLE_ARM_JOINT
#include "rua_modbus.h"
#endif
#ifdef RR_HW_ENABLE_USB_CAMERA
#include "rca_camera_usb.h"
#endif
#ifdef RR_DRV_SW_CAMERA_LASERCAM
#include "rca_lasercam.hpp"
#endif
#include "rta_tof.h"
#include "rr_slave.h"
#ifdef UART_API_HAVE_AP_WEIGHT
#include "rua_weight_dev.h"
#endif
#include "rda_rtc_api.h"
#endif /* __RR_DRIVERS_API_HEADERS_H__ */

