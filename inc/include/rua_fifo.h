/* =============================================================================
#     FileName: rua_fifo.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2018-07-09 11:10:51
#      History:
============================================================================= */
#ifndef __RUA_FIFO_H__
#define __RUA_FIFO_H__

#ifdef __cplusplus
extern "C" {
#endif

struct rua_fifo {
    unsigned int    in;
    unsigned int    out;
    unsigned int    mask;
    unsigned int    esize;
    unsigned int    inited; /*kernel already inited*/
    unsigned int    data_alloced; /*fifo alloc data*/
    void        *kdata;  /*kernel space address*/
    void        *udata;  /*user space address*/
};
extern int rua_fifo_init(struct rua_fifo *fifo, void *buffer, unsigned int size,
                         unsigned int esize);
extern unsigned int rua_fifo_out(struct rua_fifo *fifo, void *buf,
                                 unsigned int len);
extern unsigned int rua_fifo_in(struct rua_fifo *fifo, const void *buf,
                                unsigned int len);

extern unsigned int rua_fifo_unused(struct rua_fifo *fifo);
extern unsigned int rua_fifo_used(struct rua_fifo *fifo);
extern void rua_fifo_clean(struct rua_fifo *fifo);
#ifndef __KERNEL__
extern int is_power_of_2(unsigned int n);
extern unsigned int roundup_pow_of_two(unsigned int x);
#endif

#ifdef __cplusplus
}
#endif
#endif

