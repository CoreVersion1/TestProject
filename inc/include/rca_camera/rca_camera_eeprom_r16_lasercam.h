#if defined(UART_API_HAVE_R16_CAMERA) && defined(RR_DRV_SW_CAMERA_LASERCAM)

#define MAX_DATA_SIZE   (1 << 10)
#define CAMERA_EEPROM_SLIGHT_FILESIZE         0x54    //10*8+4=84
#define CAMERA_EEPROM_SLIGHT_FILE_NAME  "/mnt/reserve/LaserCam_slight.bin"

typedef struct {
    float plane[4];
    float translation[3];
    float quaternion[4];
    float reserved[10];
} camera_extrinsics_t;

extern int rca_camera_read_slight_data(camera_extrinsics_t
        *camera_slight_parap);
extern int rca_camera_write_slight_data(unsigned char *data);
#endif