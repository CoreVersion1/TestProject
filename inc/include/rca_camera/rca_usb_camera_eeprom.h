#ifndef __RCA_USB_CAMERA_EEPROM__H__
#define __RCA_USB_CAMERA_EEPROM_H__

#define  USB_CAMERA_EEROM_ADDR  (0x50)

#define ASIC_DATA  0x20
#define ASIC_ADDR  0x8100

#define R_SIZE_OFFSET   3
#define W_SIZE_OFFSET   1

/*#define USB_CAMERA_EEPROM_BLOCK1_REG_ADDR       0x0EA3
#define USB_CAMERA_IDS0_EEPROM_BLOCK1_DATASIZE       0x154
#define USB_CAMERA_IDS1_EEPROM_BLOCK1_DATASIZE       0xc4

#define USB_CAMERA_EEPROM_PARA_REG_ADDR         0x0EA3
#define USB_CAMERA_EEPROM_PARA_OFFSET           (USB_CAMERA_EEPROM_PARA_REG_ADDR - USB_CAMERA_EEPROM_BLOCK1_REG_ADDR)
#define USB_CAMERA_EEPROM_PARA_DATASIZE         (0x54 + 0x08)    //10*8+4 + sizeof(rrCameraHeadInfoSt)

#define USB_CAMERA_EEPROM_DEPTH_REG_ADDR        0x0EFF
#define USB_CAMERA_EEPROM_DEPTH_OFFSET         (USB_CAMERA_EEPROM_DEPTH_REG_ADDR - USB_CAMERA_EEPROM_BLOCK1_REG_ADDR)
#define USB_CAMERA_EEPROM_DEPTH_DATASIZE       (0x60 + 0x08)    //24*4 + sizeof(rrCameraHeadInfoSt)*/

extern int rca_camera_do_cal_crc32(unsigned char *buffer, unsigned int size);

#endif