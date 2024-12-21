#pragma once

#include "uart_api_config.h"
#include "rr_slight_dev.h"

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

#define GRADIENT_MAX_SIZE 4096

#define PIXEL_RESULT_SIZE IMAGE_WIDTH/SEARCH_STEP

#define RR_GRADIENT_POINTS_DEVICE  "/dev/rr_gradient_points"

#define RR_GRADIENT_POINTS_IOCTL    0x72
#define RR_GRADIENT_POINTS_IOCTL_ENABLE_GRADIENT_POINTS _IOW(RR_GRADIENT_POINTS_IOCTL, 0x31, int)
#define RR_GRADIENT_POINTS_IOCTL_SET_BUFFSER_SIZE _IOW(RR_GRADIENT_POINTS_IOCTL, 0x10, int)
#define RR_GRADIENT_POINTS_IOCTL_SET_SOBEL_THRESHOLD _IOW(RR_GRADIENT_POINTS_IOCTL, 0x11, int)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RRGradientPointsData {
    unsigned int image_timestamp;
    unsigned int frame_number;
    int size;
    SLPixel points[GRADIENT_MAX_SIZE];
    uint8_t gradient[IMAGE_SIZE_INIT];
    // uint8_t gradient_x[IMAGE_SIZE_INIT];
    // uint8_t gradient_y[IMAGE_SIZE_INIT];
} RRGradientPointsData;

typedef struct RRGradientPointsData_st {
    int dev_fd;
    long timeout_ms;
    RRGradientPointsData *data;
    int mmap_data_size;
} RRGradientPointsData_st;

int rr_gradient_points_dev_init(long timeout_ms);

int rr_gradient_points_wait_ready(RRGradientPointsData *data);

void rr_gradient_points_dev_close();

int rr_gradient_points_save_img();

int rr_gradient_points_save_result();

int enable_rr_gradient_points(int enable);

int set_soble_threshold(int threshold);

#ifdef __cplusplus
}
#endif
#endif
