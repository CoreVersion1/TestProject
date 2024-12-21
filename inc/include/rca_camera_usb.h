#ifndef __RCA_CAMERA_USB_H__
#define __RCA_CAMERA_USB_H__

#ifdef __cplusplus
extern "C"
{
#endif


/*******************************************************************************
#             uvccapture: USB UVC Video Class Snapshot Software                #
#This package work with the Logitech UVC based webcams with the mjpeg feature  #
#                                                                              #
#       Orginally Copyright (C) 2005 2006 Laurent Pinchart &&  Michel Xhaard   #
#       Modifications Copyright (C) 2006 Gabriel A. Devenyi                    #
#                                                                              #
# This program is free software; you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by         #
# the Free Software Foundation; either version 2 of the License, or            #
# (at your option) any later version.                                          #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# GNU General Public License for more details.                                 #
#                                                                              #
# You should have received a copy of the GNU General Public License            #
# along with this program; if not, write to the Free Software                  #
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA    #
#                                                                              #
*******************************************************************************/

#define NB_BUFFER 6

#define USB_CAMERA_WIDTH    (1600)
#define USB_CAMERA_HEIGHT   (1200)

#define SONIX_VIDPID  "0c45636b"

/*typedef int bool;
typedef int BOOL;
typedef long LONG;
typedef unsigned long ULONG;
typedef unsigned char BYTE;
typedef unsigned short USHORT;
typedef unsigned int DWORD;*/

typedef enum {
    SFT_UNKNOW,
    SFT_MXIC,
    SFT_ST,
    SFT_SST,
    SFT_ATMEL_AT25F,
    SFT_ATMEL_AT25FS,
    SFT_ATMEL_AT45DB,
    SFT_WINBOND,
    SFT_PMC,
    SFT_MXIC_LIKE,
    SFT_AMIC,
    SFT_EON,
    SF_ESMT,
    SFT_GIGA,
    SFT_FENTECH,
    SFT_UC,             //UCUNDATA
    SFT_BY,
    SFT_FM,             //Shanghai Fudan
    SFT_ZB,             //ZBIT Confidential
    SFT_COUNT,
} SERIAL_FLASH_TYPE;

typedef void(*SonixCam_SetProgress)(void *ptrClass, float fProcess);

typedef struct UsbCameraHeaderData {
    unsigned int image_timestamp;
    unsigned int single_size;
    unsigned int single_height;
    unsigned int single_width;
    unsigned char *datap;
    unsigned int frame_number;
} rca_usb_camera_header_data;

typedef enum JpegDecodeScaleDownRatio {
    JPEG_DECODE_SCALE_DOWN_1      = 0, /*no scale down*/
    JPEG_DECODE_SCALE_DOWN_2      = 1, /*scale down 1/2*/
    JPEG_DECODE_SCALE_DOWN_4      = 2, /*scale down 1/4*/
    JPEG_DECODE_SCALE_DOWN_8      = 3, /*scale down 1/8*/
} JpegDecodeScaleDownRatio;
typedef enum JpegDecodeOutputDataType {
    JpegDecodeOutputDataNV21 = 1,
    JpegDecodeOutputDataNV12 = 2,
    JpegDecodeOutputDataYU12 = 3,
    JpegDecodeOutputDataYV12 = 4,
    JpegDecodeOutputDataRGB565 = 5,
} JpegDecodeOutputDataType;

typedef struct ImgFrame {
    uint32_t mWidth;                    //the width which contains aligned buffer
    uint32_t mHeight;                  //the height which contains aligned buffer
    uint32_t mDisplayWidth;       //the actural frame width
    uint32_t mDisplayHeight;     //the actural frame height
    uint32_t mYuvSize;              // Number of bytes in mYuvData
    uint8_t *mYuvData;            // Actual yuv data
    uint32_t mRGB565Size;            // Number of bytes in mRGB565Data
    uint8_t *mRGB565Data;            // Actual RGB565 data
    int32_t  mRotationAngle;   // rotation angle, clockwise
} ImgFrame;

typedef void *JpegDecoder;

typedef void (*rca_usb_camera_capture_callback)(rca_usb_camera_header_data
        *pCHD);

extern int rca_usb_camera_init(void);
extern void rca_usb_camera_exit();
extern int rca_usb_camera_start_capture(rca_usb_camera_capture_callback cb);
extern int rca_usb_camera_stop_capture();
extern int rca_burn_usb_camera_fw(char *vidpid, unsigned char *pFwBuffer,
                                  unsigned int fw_size);
extern int rca_usbcamera_decode_init();
extern int rca_usbcamera_decode_oneframe(char *outbuf,
        unsigned int out_buf_size, char *in_buf,
        unsigned int in_buf_size); //out_buf_size 1600*1200*3/2
extern void rca_usbcamera_decode_exit();
extern int rca_usb_camera_get_fw_version(unsigned char *strVer, int len);
extern int rca_usb_camera_yuy2_init(void);
extern int rca_XU_ReadFromASIC(unsigned short addr, unsigned char *pValue);
extern int rca_XU_WriteToASIC(unsigned short, unsigned char value);
extern int rca_XU_CstmWriteToI2C(unsigned char slaveId, unsigned int addr,
                             unsigned short addrBytes, unsigned char data[], unsigned int dataLen);
extern int rca_XU_CstmReadFromI2C(unsigned char slaveId, unsigned int addr,
                              unsigned short addrBytes, unsigned char data[], unsigned int dataLen);
extern int rca_XU_Read(unsigned char pData[], unsigned int length, unsigned char unitID, unsigned char cs);
#ifdef __cplusplus
}
#endif

#endif
