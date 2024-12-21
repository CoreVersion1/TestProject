/* =============================================================================
#     FileName: rla_pcmd.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2021-05-18 11:16:44
#      History: none
============================================================================= */

#ifndef __RLA_PCMD_H__
#define __RLA_PCMD_H__

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum {
    RLA_PCMD_OUT_NONE    = 0,
    RLA_PCMD_OUT_STDOUT  = 1,
    RLA_PCMD_OUT_STDERR  = 2,
    RLA_PCMD_OUT_ALL     = RLA_PCMD_OUT_STDOUT | RLA_PCMD_OUT_STDERR,
}
rla_pcmd_output_e;

struct rla_pcmd_st;
typedef struct rla_pcmd_st rla_pcmd_st;

extern int _rla_pcmd_open(rla_pcmd_st *prp, int output, ...);
#define rla_pcmd_open(prp, output, args...) _rla_pcmd_open(prp, output, ##args, NULL)
extern int rla_pcmd_read(rla_pcmd_st *prp, char *buf, int max_size,
                         int timeout_ms);
extern int rla_pcmd_read_line(rla_pcmd_st *prp, char *buf, int max_size,
                              int timeout_ms);
extern void rla_pcmd_close(rla_pcmd_st *prp, int wait);
extern int _rla_pcmd_run(int output, ...);
#define rla_pcmd_run(output, args...) _rla_pcmd_run(output, ##args, NULL)

#if 0
#endif



#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif /* __RLA_PCMD_H__ */

