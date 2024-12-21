/* =============================================================================
#     FileName: rma_coredump.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2023-01-30 19:21:13
#      History: none
============================================================================= */

#ifndef __RMA_COREDUMP_H__
#define __RMA_COREDUMP_H__

#ifdef __cplusplus
extern "C"
{
#endif
#define RMA_COREDUMP_FLAG_KEEP_ENV (255)
extern int rma_force_coredump(pid_t pid, int flag, const char *pattern);

#ifdef __cplusplus
}
#endif
#endif
