/* =============================================================================
#     FileName: data_parse.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-04-21 18:37:24
#      History:
============================================================================= */
#ifndef __RPMSG_MCU_COMMUNICATION_H__
#define __RPMSG_MCU_COMMUNICATION_H__

#include <time.h>
#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif

extern char volatile rpmsg_need_ack_buf[REQUEST_MAX_NUMS];

static inline void rpmsg_deal_answer(unsigned char index)
{
    int i;

    for (i = 0; i < REQUEST_MAX_NUMS; i++) {
        if (rpmsg_need_ack_buf[i] == index) {
            rpmsg_need_ack_buf[i] = 0;
        }
    }

    return;
}

static inline int rpmsg_is_answered(unsigned char index)
{
    int i;

    for (i = 0; i < REQUEST_MAX_NUMS; i++) {
        if (rpmsg_need_ack_buf[i] == index) {
            return 0;
        }
    }

    return 1;
}

static inline int rpmsg_set_request(unsigned char index)
{
    int i;

    for (i = 0; i < REQUEST_MAX_NUMS; i++) {
        if (!rpmsg_need_ack_buf[i]) {
            rpmsg_need_ack_buf[i] = index;
            return 0;
        }
    }

    return ERR_NO_SPACE;
}

int  rpmsg_sent_cmd(eRptPkgId_e ID, unsigned int struct_size, const void *addr,
                    int need_ack);

int rpmsg_get_package(char *buf, int max_lengh);

void rpmsg_deal_answer(unsigned char index);


#ifdef __cplusplus
}
#endif
#endif

