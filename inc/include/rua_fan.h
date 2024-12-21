#ifndef _RUA_FAN_H_
#define _RUA_FAN_H_

#ifdef __cplusplus
extern "C" {
#endif

extern int convert_fan_value(int s8Val);
extern int init_fan_para(void);
extern unsigned char  get_fan_id(void);

#ifdef __cplusplus
}
#endif

#endif

