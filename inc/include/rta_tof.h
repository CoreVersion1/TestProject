#ifndef __RCA_TOF_H__
#define __RCA_TOF_H__

#ifdef __cplusplus
extern "C"
{
#endif


#define RCA_MULTI_TOF_NUMS              UART_API_HAVE_TOF_NUM

#define VL53L8CX_RESOLUTION_4X4            ((uint8_t) 16U)
#define VL53L8CX_RESOLUTION_8X8            ((uint8_t) 64U)
#define VL53L8CX_NB_TARGET_PER_ZONE        1U
//#define VL53L8CX_RESOLUTION_4X4            16
//#define VL53L8CX_RESOLUTION_8X8            64
//#define VL53L8CX_NB_TARGET_PER_ZONE        1
/**
 * @brief Structure VL53L8CX_ResultsData contains the ranging results of
 * VL53L8CX. If user wants more than 1 target per zone, the results can be split
 * into 2 sub-groups :
 * - Per zone results. These results are common to all targets (ambient_per_spad
 * , nb_target_detected and nb_spads_enabled).
 * - Per target results : These results are different relative to the detected
 * target (signal_per_spad, range_sigma_mm, distance_mm, reflectance,
 * target_status).
 */

#if 0
typedef struct {
    /* Internal sensor silicon temperature */
    int8_t silicon_temp_degc;

    /* Ambient noise in kcps/spads */
#ifndef VL53L8CX_DISABLE_AMBIENT_PER_SPAD
    uint32_t ambient_per_spad[VL53L8CX_RESOLUTION_8X8];
#endif

    /* Number of valid target detected for 1 zone */
#ifndef VL53L8CX_DISABLE_NB_TARGET_DETECTED
    uint8_t nb_target_detected[VL53L8CX_RESOLUTION_8X8];
#endif

    /* Number of spads enabled for this ranging */
#ifndef VL53L8CX_DISABLE_NB_SPADS_ENABLED
    uint32_t nb_spads_enabled[VL53L8CX_RESOLUTION_8X8];
#endif

    /* Signal returned to the sensor in kcps/spads */
#ifndef VL53L8CX_DISABLE_SIGNAL_PER_SPAD
    uint32_t signal_per_spad[(VL53L8CX_RESOLUTION_8X8
                              *VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

    /* Sigma of the current distance in mm */
#ifndef VL53L8CX_DISABLE_RANGE_SIGMA_MM
    uint16_t range_sigma_mm[(VL53L8CX_RESOLUTION_8X8
                             *VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

    /* Measured distance in mm */
#ifndef VL53L8CX_DISABLE_DISTANCE_MM
    int16_t distance_mm[(VL53L8CX_RESOLUTION_8X8
                         *VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

    /* Estimated reflectance in percent */
#ifndef VL53L8CX_DISABLE_REFLECTANCE_PERCENT
    uint8_t reflectance[(VL53L8CX_RESOLUTION_8X8
                         *VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

    /* Status indicating the measurement validity (5 & 9 means ranging OK)*/
#ifndef VL53L8CX_DISABLE_TARGET_STATUS
    uint8_t target_status[(VL53L8CX_RESOLUTION_8X8
                           *VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

    /* Motion detector results */
#ifndef VL53L8CX_DISABLE_MOTION_INDICATOR
    struct {
        uint32_t global_indicator_1;
        uint32_t global_indicator_2;
        uint8_t     status;
        uint8_t     nb_of_detected_aggregates;
        uint8_t     nb_of_aggregates;
        uint8_t     spare;
        uint32_t motion[32];
    } motion_indicator;
#endif

} VL53L8CX_ResultsData;
#endif

typedef struct
{
	/* Internal sensor silicon temperature */
	int8_t silicon_temp_degc;

	/* Ambient noise in kcps/spads */
#ifndef VL53L8CX_DISABLE_AMBIENT_PER_SPAD
	uint32_t ambient_per_spad[VL53L8CX_RESOLUTION_8X8];
#endif

	/* Number of valid target detected for 1 zone */
#ifndef VL53L8CX_DISABLE_NB_TARGET_DETECTED
	uint8_t nb_target_detected[VL53L8CX_RESOLUTION_8X8];
#endif

	/* Number of spads enabled for this ranging */
#ifndef VL53L8CX_DISABLE_NB_SPADS_ENABLED
	uint32_t nb_spads_enabled[VL53L8CX_RESOLUTION_8X8];
#endif

	/* Signal returned to the sensor in kcps/spads */
#ifndef VL53L8CX_DISABLE_SIGNAL_PER_SPAD
	uint32_t signal_per_spad[(VL53L8CX_RESOLUTION_8X8
					*VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

	/* Sigma of the current distance in mm */
#ifndef VL53L8CX_DISABLE_RANGE_SIGMA_MM
	uint16_t range_sigma_mm[(VL53L8CX_RESOLUTION_8X8
					*VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

	/* Measured distance in mm */
#ifndef VL53L8CX_DISABLE_DISTANCE_MM
	int16_t distance_mm[(VL53L8CX_RESOLUTION_8X8
					*VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

	/* Estimated reflectance in percent */
#ifndef VL53L8CX_DISABLE_REFLECTANCE_PERCENT
	uint8_t reflectance[(VL53L8CX_RESOLUTION_8X8
					*VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

	/* Status indicating the measurement validity (5 & 9 means ranging OK)*/
#ifndef VL53L8CX_DISABLE_TARGET_STATUS
	uint8_t target_status[(VL53L8CX_RESOLUTION_8X8
					*VL53L8CX_NB_TARGET_PER_ZONE)];
#endif

	/* Motion detector results */
#ifndef VL53L8CX_DISABLE_MOTION_INDICATOR
	struct
	{
		uint32_t global_indicator_1;
		uint32_t global_indicator_2;
		uint8_t	 status;
		uint8_t	 nb_of_detected_aggregates;
		uint8_t	 nb_of_aggregates;
		uint8_t	 spare;
		uint32_t motion[32];
	} motion_indicator;
#endif

} VL53L8CX_ResultsData;

typedef struct {
    uint32_t integration_time_ms;   /* Using autonomous mode, the integration time can be updated (not possible
                                     * using continuous) */
    uint8_t resolution;             /* As others settings depend to this
                                     * one, it must be the first to use.
                                     */
    uint8_t frequency_hz;           /* Set ranging frequency
                                     * Using 4x4, min frequency is 1Hz and max is 60Hz
                                     * Using 8x8, min frequency is 1Hz and max is 15Hz
                                     */
    uint8_t sharpener_percent;
    uint8_t target_order;
    uint8_t ranging_mode;
} rtf_tof_info_st;

typedef enum {
    RTF_TOF_ID_0 = 0x1,
    RTF_TOF_ID_1 = 0x1 << 1,
    RTF_TOF_ID_ALL = RTF_TOF_ID_0 | RTF_TOF_ID_1,
} rft_tof_id_e;

typedef struct {
    rft_tof_id_e ids;
    uint8_t streamcount;
    VL53L8CX_ResultsData results;
} rtf_tof_header_data;

#define TOF_XTALK_BUFFER_SIZE      ((uint16_t)776U)

union rtf_tof_calib_block_header {
    uint32_t bytes;
    struct {
        uint32_t type : 4;
        uint32_t size : 12;
        uint32_t idx : 16;
    };
};

typedef struct {
    uint16_t reflectance_percent;
    uint8_t nb_samples;
    uint16_t distance_mm;
    uint8_t xtalk_data[TOF_XTALK_BUFFER_SIZE];
} rtf_tof_xtalk_calib_t;

typedef int (*rtf_tof_capture_callback)(rtf_tof_header_data *pdata);

int rtf_tof_init(rft_tof_id_e tof_id);
int rtf_tof_xtalk_calibration(rft_tof_id_e tof_id,
                              rtf_tof_xtalk_calib_t *xtalk_calib, int use_now);
int rtf_tof_set_parameter(rft_tof_id_e tof_id, rtf_tof_info_st *tof_info);
int rtf_tof_start_capture(rft_tof_id_e tof_id,
                          rtf_tof_capture_callback callback);
int rtf_tof_stop_capture(rft_tof_id_e tof_id);
int rtf_tof_exit(rft_tof_id_e tof_id);

#ifdef __cplusplus
}
#endif

#endif


