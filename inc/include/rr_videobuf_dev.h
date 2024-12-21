#ifndef __RR_VIDEOBUF_DEV_H__
#define __RR_VIDEOBUF_DEV_H__

#if defined(UART_API_HAVE_SLIGHT_KERNEL) && !defined(CLIP_OUT_SLIGHT_KERNEL)
#define RR_VIDEOBUF_DEVICE  "/dev/rr_videobuf"

#define MAX_RR_VIDEOBUF_NUM 30
#define RR_VIDEOBUF_IOCTL    0x71
#define RR_VIDEOBUF_IOCTL_SET_BUFFSER_SIZE  _IOW(RR_VIDEOBUF_IOCTL, 0x10, int)
#define RR_VIDEOBUF_IOCTL_DQBUF             _IOWR(RR_VIDEOBUF_IOCTL, 0x17, int)
#define RR_VIDEOBUF_IOCTL_IMAGE_LUMA        _IOR(RR_VIDEOBUF_IOCTL, 0x18, int)
#define RR_VIDEOBUF_IOCTL_IMAGE_CRC_SET     _IOW(RR_VIDEOBUF_IOCTL, 0x19, int)
#define RR_VIDEOBUF_IOCTL_IMAGE_CRC_GET     _IOR(RR_VIDEOBUF_IOCTL, 0x19, int)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RRVideobufData {
    int dev_fd;
    long timeout_ms;
    int mmap_data_size;
    void *data;
} RRVideobufData;

extern int rr_videobuf_dev_init(long timeout_ms);

extern void rr_videobuf_dev_close();

#ifdef __cplusplus
}
#endif

#endif

#endif
