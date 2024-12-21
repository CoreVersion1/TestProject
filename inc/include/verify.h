/* =============================================================================
#     FileName: fw.h
#         Desc:
#       Author: joseph_lee
#        Email: joseph_lee2633@163.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2015-06-26 13:59:23
#      History:
============================================================================= */
#ifndef __VERIFY_H__
#define __VERIFY_H__

#ifdef __cplusplus
extern "C" {
#endif

#define LOCALE_CONFIG_FILE    "/mnt/default/roborock.conf"
#define LOCALE_CONFIG_SIGN    LOCALE_CONFIG_FILE".sign"

#define SHADOW_FILE           "/mnt/default/shadow"
#define SHADOW_SIGN           SHADOW_FILE".sign"


extern int verify_conf();
extern int do_shadow(const char *syspwd);
extern int do_syspwd(const char *syspwd, char *dir);
extern int verify_shadow(const char *syspwd);
extern int verify_env(void);

#ifdef __cplusplus
}
#endif
#endif


