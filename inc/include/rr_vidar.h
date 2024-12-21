#ifndef __RR_VIDAR_H__
#define __RR_VIDAR_H__

#ifdef __cplusplus
extern "C" {
#endif

#define VIDAR_IR_EEPROM_PARA_REG_ADDR         0x0E00
#define VIDAR_IR_EEPROM_PARA_DATASIZE         (0x48 + 0x28)    //sizeof(rrVidarHeadInfoSt) = 32 + 1 + 1 + 2 + 4; 4*3 + 4*5 + 4*10 + sizeof(rrVidarHeadInfoSt)
//Warning don't override 0x0EA3

typedef struct {
    char vidar_sn[32];
    unsigned char version;
    unsigned char dataId;
    unsigned short data_size;
    unsigned int crc;
} rrVidarIRHeadInfoSt;

typedef struct {
    float laser_robot_x_;
    float laser_robot_y_;
    float laser_robot_yaw_;
} nav_laser_param_t;

typedef struct {
    float pitch_self;
    float pitch;
    float roll;
    float height;
    float height_rmse;
} avoid_laser_param_t;

#pragma pack(1)
typedef struct {
    nav_laser_param_t nav_laser_param;
    avoid_laser_param_t avoid_laser_param;
    float reserved[10];
    rrVidarIRHeadInfoSt vidarHead;
} vidar_ir_calib_st;
#pragma pack()

#define VIDAR_IR_EEPROM_PARA_VER           0x01
#define VIDAR_IR_EEPROM_PARA_ID            0x01
#define VIDAR_IR_EEPROM_PARA_FILESIZE      0x48   //8+32*4


typedef enum {
    C91_MODE_DEFAULT = 0,
    C91_STROBE_IRQ,
    C91_STROBE_OUT_LOW,
    C91_STROBE_OUT_HIGH,
    C91_POWER_ON,
    C91_POWER_OFF,
} c91_mode_e;

int rr_vidar_set_mode(c91_mode_e mode);
void rr_vidar_update_record_data(int on);
int rr_vidar_ir_write_calib_data(vidar_ir_calib_st *vidar_calibp, char sn[32]);
int rr_vidar_ir_read_calib_data(vidar_ir_calib_st *vidar_calibp, char sn[32]);

#ifdef __cplusplus
}
#endif

#endif
