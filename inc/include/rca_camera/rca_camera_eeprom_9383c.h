#ifndef __RCA_CAMERA_EEPROM_SSC9383C_H__
#define __RCA_CAMERA_EEPROM_SSC9383C_H__

#include "rca_camera_eeprom_common.h"
#if defined(UART_API_HAVE_CAMERA_2C1L)
#include "rca_camera_eeprom_2C1L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_1C1L)
#include "rca_camera_eeprom_1C1L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_ONLY_IR) && defined(RR_DRV_SW_CAMERA_LASERCAM)
#include "rca_camera_eeprom_9383c_lasercam.h"
#elif defined(UART_API_HAVE_CAMERA_ONLY_IR)
#include "rca_camera_eeprom_only_ir.h"
#endif

#define MAX_DATA_SIZE   (1 << 10)


#define CAMERA0_EEPROM_I2C_ADDR             0xA0
#define CAMERA1_EEPROM_SC202CS_I2C_ADDR     0xA0
#define CAMERA1_EEPROM_OV8856_I2C_ADDR      0xA0
#define CAMERA_I2C_DATA_WIDTH               0x1


typedef struct __camera_i2c_ops {
    unsigned int
    id;                    // camera's id responedint to subdev in media-ctl
    unsigned int
    i2c_addr;              // I2C slave 7bit address, such as sensor, flash, eeprom
    unsigned int reg;                   // register's address in i2c devices

    unsigned char *data;
    // data to be read or written, and each data in little endian.
    unsigned int
    data_size;             // byte size of total data to be read or written.
    unsigned int
    data_width;            // data width to be read or written, 1, 2 or 4
} CAMERA_I2C_OPS;
extern int rca_camera_i2c_write(CAMERA_I2C_OPS *ops);
extern int rca_camera_i2c_read(CAMERA_I2C_OPS *ops);

#endif
