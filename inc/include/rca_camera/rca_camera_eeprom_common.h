#ifndef __RCA_CAMERA_EEPROM_COMMON_H__
#define __RCA_CAMERA_EEPROM_COMMON_H__

#include "rca_camera_common.h"

#define CAM_TRULY_NAME      "TRULY"
#define CAM_SUNNY_NAME      "SUNNY"
#define CAM_UNIMAGE_NAME    "UNIMAGE"
#define CAM_TSP_NAME        "TSP"
#define CAM_LITEON_NAME     "LITEON"
#define CAM_QTECH_NAME      "QTECH"
#define CAM_OFILM_NAME      "OFILM"
#define CAM_AOCI_NAME       "AOCI"

#define CAM_TRULY_ID        0x01
#define CAM_SUNNY_ID        0x02
#define CAM_UNIMAGE_ID      0x03
#define CAM_TSP_ID          0x04
#define CAM_LITEON_ID       0x05
#define CAM_QTECH_ID        0x06
#define CAM_OFILM_ID        0x07
#define CAM_AOCI_ID         0x08

typedef struct {
    unsigned char version;
    unsigned char dataId;
    unsigned short data_size;
    unsigned int crc;
} rrCameraHeadInfoSt;

#pragma pack(1)
typedef struct {
    unsigned char main_version;
    unsigned char sub_version;
    unsigned char reserve_version[2];
    unsigned char reserve[8];
    unsigned int crc32;
} camera_version_st;
#pragma pack()

typedef struct {
    double fx;
    double fy;
    double u0;
    double v0;
    double skew;

} intrinsic_v1_st;

typedef struct {
    double k1;
    double k2;
    double p1;
    double p2;
    double k3;
} distortion_v1_st;

typedef struct {
    double k1;
    double k2;
    double p1;
    double p2;
    double k3;
    double k4;
    double k5;
    double k6;
} distortion_v2_st; //use for 3L

// ax + by + cz + d = 0;
typedef struct {
    float a, b, c, d;
} PlanePara;

// y = kx + b
typedef struct {
    float k, b;
} LineKb;

typedef struct {
    float pitch, yaw, roll;
    float height;
} SlightParams;

typedef struct {
    float pitch;
    float roll;
    float height;
} CamExtrinsic;

typedef struct  {
    float left, mid, right;
} CheckPosition;

#endif
