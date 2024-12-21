#pragma once

#include "uart_api_config.h"

#if defined(UART_API_HAVE_SLIGHT_KERNEL) && !defined(CLIP_OUT_SLIGHT_KERNEL)
#ifndef RR_SLIGHT_VGA
#define SEARCH_STEP 1
#define IMAGE_WIDTH_INIT 320
#define IMAGE_HEIGHT_INIT 200
#define IMAGE_SIZE_INIT IMAGE_WIDTH_INIT * IMAGE_HEIGHT_INIT
#define IMAGE_WIDTH 320
#define IMAGE_HEIGHT 200
#define IMAGE_SIZE IMAGE_WIDTH * IMAGE_HEIGHT
#else
#define SEARCH_STEP 1
#define IMAGE_WIDTH_INIT 640
#define IMAGE_HEIGHT_INIT 400
#define IMAGE_SIZE_INIT (IMAGE_WIDTH_INIT * IMAGE_HEIGHT_INIT + 4096)
#define IMAGE_WIDTH 320
#define IMAGE_HEIGHT 250
#define IMAGE_SIZE IMAGE_WIDTH * IMAGE_HEIGHT
#endif

#define PIXEL_RESULT_SIZE IMAGE_WIDTH/SEARCH_STEP

#define RR_SLIGHT_DEVICE  "/dev/rr_slight"

#define RR_SLIGHT_IOCTL    0x70
#define RR_SLIGHT_IOCTL_SET_BUFFSER_SIZE _IOW(RR_SLIGHT_IOCTL, 0x10, int)
#define RR_SLIGHT_IOCTL_SET_OFFSET _IOWR(RR_SLIGHT_IOCTL, 0x20, int)
#define RR_SLIGHT_IOCTL_SET_FLOOR_POINTS _IOWR(RR_SLIGHT_IOCTL, 0x21, int)
#define RR_SLIGHT_IOCTL_START_SLIGHT_KTHREAD _IOW(RR_SLIGHT_IOCTL, 0x30, int)
#define RR_SLIGHT_IOCTL_ENABLE_SLIGHT_PROCESS _IOW(RR_SLIGHT_IOCTL, 0x31, int)
#define RR_SLIGHT_IOCTL_SET_ROI_REGION _IOW(RR_SLIGHT_IOCTL, 0x41, int)

#ifdef __cplusplus
extern "C" {
#endif

enum RRSLightMode {
    RR_SLIGHT_MODE_NONE = 0,
    RR_SLIGHT_MODE_CALIBRATION = 10,
    RR_SLIGHT_MODE_MT = 11,
};

enum RRSLightDataType {
    RR_SLIGHT_TIMESTAMP = 1,
    RR_SLIGHT_OFFSET,
    RR_SLIGHT_SLDATA,
    RR_SLIGHT_MAX,
};

typedef struct SLPixel {
    uint16_t u;
    uint16_t v;
} SLPixel;

typedef struct SLightPixel {
    uint16_t u;
    uint32_t v;
    uint32_t v1;
    uint8_t intensity;
    uint8_t width;
    uint8_t valid;
} SLightPixel;

typedef struct RRMMapSLightData {
    int type;
    struct timeval light_ts;
    struct timeval no_light_ts;
    SLPixel floor_points[IMAGE_WIDTH];
    int offset[IMAGE_WIDTH];
    SLightPixel data[IMAGE_WIDTH];
    uint8_t confidence;
    uint8_t mode;
    uint16_t start;
    uint16_t end;
} RRMMapSLightData;

typedef struct {
    int dev_fd;
    long timestamp_timeout_ms;
    long sldata_timeout_ms;
    RRMMapSLightData *data;
    int mmap_data_size;
} RRStructLight_st;

int rr_slight_dev_init(long ts_timeout_ms, long sd_timeout_ms);

int rr_slight_set_floor_points(const int *points);

int rr_slight_wait_timestamp_ready(void);

int rr_slight_get_timestamp(struct timeval *light_ts,
                            struct timeval *no_light_ts);

int rr_slight_set_offset(int *offset);

int rr_slight_wait_sldata_ready();

int rr_slight_get_sldata(SLightPixel *data);

void rr_slight_dev_close();

int rr_slight_save_sldata_result();

int rr_slight_enable_slight_kthread(int slight_kthread_enabled);

int rr_slight_enable_slight_process(int slight_process_enabled);

int rr_slight_get_confidence(uint8_t *confidence);

int rr_slight_set_mode(int mode);

int rr_slight_set_roi_region(int start, int end);

#ifdef __cplusplus
}
#endif
#endif
