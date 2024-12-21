/* =============================================================================
#     FileName: rma_misc.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2022-04-16 15:42:49
#      History: none
============================================================================= */
#ifndef __RMA_MISC_H__
#define __RMA_MISC_H__
#include <sys/sysinfo.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern int rma_board_is_descrete(void);
extern int rma_is_log_save_support(struct sysinfo *psysinfo);

#ifdef __cplusplus
}
#endif
#endif // __RMA_MISC_H__
