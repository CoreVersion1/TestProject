/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Copyright (c) 2016, Linaro Ltd.
 */

#ifndef _RPMSG_COMMON_H_
#define _RPMSG_COMMON_H_

#include <linux/ioctl.h>
#include <linux/types.h>

#define RPMSG_DEV_NAME_MAX 16

/**
 * struct rpmsg_endpoint_info - endpoint info representation
 * @name: name of service
 * @src: local address
 * @dst: destination address
 */
struct rpmsg_endpoint_info {
    char name[32];
    __u32 src;
    __u32 dst;
};

/**
 * struct rpmsg_ctrl_msg - used by rpmsg_master.c
 * @name: user define
 * @id: update by driver
 * @cmd:only can RPMSG_*_IOCTL
 * */
struct rpmsg_ept_info {
    char name[32];
    uint32_t id;
};

typedef struct {
    int ept_rx_fd;
    int ept_rx_id;
    int ept_tx_fd;
    int ept_tx_id;
    int dev_fd; //mcu, lds, or carpet;
    int dev_id; //same as mmap_fd;
    int lock_ept;
    int timeout_ms;
    int use_mmap; //if use mmap, this value should be set to ioctrl_buffersize
    pthread_mutex_t ept_w_lock;
    unsigned int mmap_data_size;
    RuaMmapFifo_st *pfifo;
} RuaRpmsg_st;


int rpmsg_init(RuaRpmsg_st **ppR, const char *rpmsg_ctrl_dev,
               const char *ept_tx_name,
               const char *ept_rx_name, const char *dev,
               int lock_ept, int use_mmap, unsigned int mmap_size, int timeout_ms);

void rpmsg_exit(RuaRpmsg_st **ppR, const char *rpmsg_ctrl_dev);

void rpmsg_clean(RuaRpmsg_st *pR);

int rpmsg_read(RuaRpmsg_st *pR, char *buf, unsigned int max_read,
               int timeout_ms);

int rpmsg_write(RuaRpmsg_st *pR, const char *buf, unsigned int len);

void rpmsg_set_timeout(RuaRpmsg_st *pR, int timeout_ms);

int rpmsg_buffer_full(RuaRpmsg_st *pR);

#ifdef UART_API_HAVE_SIGMASTAR_RPMSG
int rpmsg_send_connect_info(RuaRpmsg_st *pR);
#endif
/**
 * RPMSG_CREATE_EPT_IOCTL:
 *     Create the endpoint specified by info.name,
 *     updates info.id.
 * RPMSG_DESTROY_EPT_IOCTL:
 *     Destroy the endpoint specified by info.id.
 * RPMSG_REST_EPT_GRP_IOCTL:
 *     Destroy all endpoint belonging to info.name
 * RPMSG_DESTROY_ALL_EPT_IOCTL:
 *     Destroy all endpoint
 */
// #define RR_RPMSG_CREATE_EPT_IOCTL   _IOW(0xb5, 0x10, struct rpmsg_ept_info)
// #define RR_RPMSG_DESTROY_EPT_IOCTL  _IO(0xb5, 0x11)
// #define RR_RPMSG_REST_EPT_GRP_IOCTL _IO(0xb5, 0x12)
// #define RR_RPMSG_DESTROY_ALL_EPT_IOCTL  _IO(0xb5, 0x13)

#define RR_RPMSG_CREATE_EPT_IOCTL   _IOW(0xb5, 0x1, struct rpmsg_endpoint_info)
#define RR_RPMSG_DESTROY_EPT_IOCTL  _IO(0xb5, 0x2)
#define RR_RPMSG_REST_EPT_GRP_IOCTL _IO(0xb5, 0x3)
#define RR_RPMSG_DESTROY_ALL_EPT_IOCTL  _IO(0xb5, 0x4)

#endif
