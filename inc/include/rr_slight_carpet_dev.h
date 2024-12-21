#ifndef __RR_SLIGHT_CARPET_DEV_H__
#define __RR_SLIGHT_CARPET_DEV_H__

#if defined(UART_API_HAVE_SLIGHT_KERNEL) && !defined(CLIP_OUT_SLIGHT_KERNEL)
#define RR_SLIGHT_CARPET_DEVICE  "/dev/rr_slight_carpet"

#define MAX_RR_SLIGHT_CARPET_NUM 4
#define MAX_RR_SLIGHT_CARPET_POINTS 64000
#define SLIGHT_CARPET_SMALL_WIDTH 112
#define SLIGHT_CARPET_SMALL_HEIGHT 112
#define SLIGHT_CARPET_IMAGE_SIZE (SLIGHT_CARPET_SMALL_WIDTH * SLIGHT_CARPET_SMALL_HEIGHT)

#define RR_SLIGHT_CARPET_IOCTL    0x73
#define RR_SLIGHT_CARPET_IOCTL_SET_BUFFSER_SIZE  _IOW(RR_SLIGHT_CARPET_IOCTL, 0x10, int)
#define RR_SLIGHT_CARPET_IOCTL_ENABLE_SLIGHT_CARPET  _IOW(RR_SLIGHT_CARPET_IOCTL, 0x11, int)
#define RR_SLIGHT_CARPET_IOCTL_SET_CARPET_ROI_POS  _IOW(RR_SLIGHT_CARPET_IOCTL, 0x12, int)
#define RR_SLIGHT_CARPET_IOCTL_DQBUF             _IOWR(RR_SLIGHT_CARPET_IOCTL, 0x17, int)

typedef struct RRMMapSLightCarpetData {
    struct timeval ts;
    int points_num;
    struct SLPixel points[MAX_RR_SLIGHT_CARPET_POINTS];
    struct SLPixel carpet_position;
    uint8_t data[SLIGHT_CARPET_IMAGE_SIZE];
} RRMMapSLightCarpetData;

typedef struct RRMMapSLightCarpetQueue {
    int front;
    int rear;
    RRMMapSLightCarpetData data[MAX_RR_SLIGHT_CARPET_NUM];
} RRMMapSLightCarpetQueue;

typedef struct RRSlightCarpetQueue {
    int dev_fd;
    long timeout_ms;
    int mmap_data_size;
    RRMMapSLightCarpetQueue *data;
} RRSlightCarpetQueue;

#ifdef __cplusplus
extern "C" {
#endif

enum RRCarpetRoiPatchPos {
    RR_CARPET_ROI_MID = 0,
    RR_CARPET_ROI_LEFT = 1,
    RR_CARPET_ROI_RIGHT = 2,
};

extern int rr_slight_carpet_dev_wait_image();

extern int rr_slight_carpet_dev_get_image(RRMMapSLightCarpetData *data);

extern int rr_slight_carpet_dev_init(long timeout_ms);

extern void rr_slight_carpet_dev_close();

extern int rr_slight_carpet_enable(int enable);

extern int rr_slight_carpet_set_roi_pos(int pos);

extern int rr_slight_carpet_save_image(RRMMapSLightCarpetData *data);

#ifdef __cplusplus
}
#endif

#endif

#endif
