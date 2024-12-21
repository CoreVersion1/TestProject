#ifndef __RCA_IMAGE_YUV2BMP_H__
#define __RCA_IMAGE_YUV2BMP_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

enum {
    RCA_IMAGE_YUV_I420,
    RCA_IMAGE_YUV_YV12,
    RCA_IMAGE_YUV_NV12,
    RCA_IMAGE_YUV_NV21,
    RCA_IMAGE_YUV_GRAY,
};

/* constants for the biCompression field */
#pragma pack(push)  /*tell gcc save default align*/
#pragma pack(1)  /* tell gcc align  1 byte*/
typedef struct tagBitmapFileHeader {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BitmapFileHeader;

typedef struct tagBitmapInfoHeader {
    unsigned int biSize;
    unsigned int biWidth;
    unsigned int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    unsigned int biXPelsPerMeter;
    unsigned int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BitmapInfoHeader;

typedef struct tagBitmapInfo {
    BitmapFileHeader bfHeader;
    BitmapInfoHeader biHeader;
} BitmapInfo;

typedef struct tagRGBQuad {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
} RGBQuad;
typedef RGBQuad RGBQUAD;

typedef union tagBitmapData {
    RGBQuad rgbQuad[0];
    unsigned char rgb[0];
} BitmapData;

typedef struct tagBitmap {
    BitmapInfo bInfo;
    BitmapData bData;
} Bitmap;
#pragma pack(pop)   /* tell gcc use default align*/


#define RCA_IMAGE_BMP_BIT_COUNT 8

/**
    Convert YUV raw data to RGB bitmap.
    @return: bitmap raw data or NULL if any error.
*/
//Bitmap *yuv2bmp(int format, unsigned char yuv[], int width, int height, int bitcount);
extern int rca_img_yuv2bmp(int format, unsigned char *yuv, int width,
                           int height,
                           int bitcount, unsigned char *bmpp);


#if 0
/**
    Convert YUV raw data to RGB bitmap and save to <file>.
    @return: bmp file size or 0 if any error.
*/
extern int yuv2bmpfile(int format, unsigned char yuv[], int width, int height,
                       int bitcount, const char *file);
#endif

extern int rca_img_cal_bmp_size(int width, int height, int bitcount);

#ifdef __cplusplus
}
#endif

#endif


