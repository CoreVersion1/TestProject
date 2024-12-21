#ifndef _RUA_FAN_ID_DETECT_H_
#define _RUA_FAN_ID_DETECT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    RUA_FAN_ID_DETECT = 0,
} fan_id_detect;

extern int rua_fan_id_read(fan_id_detect detect_type);

#ifdef __cplusplus
}
#endif

#endif
