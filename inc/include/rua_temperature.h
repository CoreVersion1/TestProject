#ifndef _RUA_TEMPERATURE_H_
#define _RUA_TEMPERATURE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _temp_type_ {
    RTA_TEMP_CAMERA = 0,
    RTA_TEMP_CAMERA1,
}
temp_type;

extern float rta_temp_read(temp_type type);
extern int rta_temp_ap_ntc_valid();

#ifdef __cplusplus
}
#endif


#endif