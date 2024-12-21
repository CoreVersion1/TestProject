#ifndef __BAROMETER_H__
#define __BAROMETER_H__

#ifdef __cplusplus
extern "C" {
#endif

enum eBMP5_Report_ID_e{
       MSC_INPUT_PRESSURE              = 0x01,
       MSC_INPUT_TEMPERATURE   = 0x02,
};

enum sensor_bar_dev_e{
    BMP581_POWERON,
    BMP581_POWEROFF,
    BMP581_START_WORK,
    BMP581_STOP_WORK,
    BMP581_SET_MODE,
    BMP581_GET_MODE,
};

struct sensor_dev_t {
    int dev_fd;
    int data_fd;
    int stop;
    pthread_t pthread_fd;
    struct rua_fifo fifo;
    void *data;
    void *reverse;
};

struct sensor_bar_data_t{
    enum eBMP5_Report_ID_e id;
    uint32_t data;
};

#pragma pack(1)
struct bar_data_t {
    rua_id_t id;
    rua_st_t len;
    struct sensor_bar_data_t data;
};
#pragma pack()

#define BAR_DEV_NAME "/dev/bmp5_barometer"
#define BAR_DATA_NAME  "bmp5_input"

#define BMP581_IOCTL_POWERON                   _IO('P',0X01)
#define BMP581_IOCTL_POWEROFF                  _IO('P',0X02)
#define BMP581_IOCTL_START_WORK                _IO('P',0X03)
#define BMP581_IOCTL_STOP_WORK                         _IO('P',0X04)
#define BMP581_IOCTL_SET_MODE                  _IOW('P',0X05,uint32_t)
#define BMP581_IOCTL_GET_MODE                  _IOR('P',0X06,uint32_t)

extern int ap_bar_init();
extern void ap_bar_uninit();
extern int set_ap_bar_enable(int en);
extern int ap_bar_get_pkgs(char *buf, int max_read);

#ifdef __cplusplus
}
#endif
#endif