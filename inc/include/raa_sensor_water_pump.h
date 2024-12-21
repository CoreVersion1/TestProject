
#ifndef __WATER_PUMP_H__
#define __WATER_PUMP_H__

#ifdef __cplusplus
extern "C" {
#endif

struct water_pump_data_t {
    rua_id_t id;
    rua_st_t len;
    WaterPump_st data;
};

struct water_pump_dev_t {
    int dev_fd;
    int data_fd;
    int stop;
    pthread_t pthread_fd;
    struct rua_fifo fifo;
    void *data;
};

#define WATER_PUMP      0xF7
#define WATER_PUMP_IOCTL_SET_ENABLE_10MS        _IOW(WATER_PUMP, 0x10, int)


#define WATER_PUMP_DEV_NAME "/dev/rr_water_pump"
#define WATER_PUMP_DATA_NAME "rr_abs_input"

int ap_water_pump_init();
int ap_water_pump_uninit();
int ap_water_pump_get_pkgs(char *buf, int max_read);
int ap_water_pump_run(const unsigned int on_10ms);


#ifdef __cplusplus
}
#endif
#endif

