/* =============================================================================
#     FileName: system_state.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-10-16 11:11:27
#      History:
============================================================================= */
#ifndef __SYSTEM_STATE_H_
#define __SYSTEM_STATE_H_
#ifdef __cplusplus
extern "C" {
#endif

extern int mcu_idle();
extern int mcu_wakeup();
extern void set_mcu_not_idle();
/**
 * @description: set system state for Dynamic-CPU-Usage-Compensation-Tool
 * @param {int} system state
 * @return {0} success
 */
extern int set_system_stat(int state);

#ifdef __cplusplus
}
#endif
#endif


