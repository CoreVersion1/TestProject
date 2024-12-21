#ifndef __RCA_CAMERA_EEPROM_REFACTOR_H__
#define __RCA_CAMERA_EEPROM_REFACTOR_H__

#include "rca_camera_eeprom_common.h"

#if defined(UART_API_HAVE_CAMERA_2C1L)
#include "rca_camera_eeprom_2C1L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_2C2L)
#include "rca_camera_eeprom_2C2L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_2C3L)
#include "rca_camera_eeprom_2C3L.h"
#endif

#if defined(UART_API_HAVE_CAMERA_ONLY_IR)
#include "rca_camera_eeprom_only_ir.h"
#endif

#define MAX_DATA_SIZE   (1 << 10)


#define CAMERA0_EEPROM_I2C_ADDR             0xA0
#define CAMERA1_EEPROM_SC202CS_I2C_ADDR     0xA0
#define CAMERA1_EEPROM_OV8856_I2C_ADDR      0xA2
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

extern int rca_camera_write_flash_data(rca_camera_id_e ids, unsigned addr,
                                       unsigned int reg, unsigned char *data, unsigned int len);
extern int rca_camera_read_flash_data(rca_camera_id_e ids, unsigned addr,
                                      unsigned int reg, unsigned char *data, unsigned int len);

#endif
