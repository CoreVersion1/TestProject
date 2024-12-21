#ifndef __RCA_CAMERA_LED_2_H__
#define __RCA_CAMERA_LED_2_H__

#define RCL_DEVICE          "/dev/camera_led"
#define RCL_CTL             0x58

#define RCL_CTL_IR_ON       _IOW(RCL_CTL, 0x10, int)
#define RCL_CTL_IR_OFF      _IOW(RCL_CTL, 0x11, int)
#define RCL_CTL_IR_AUTO     _IOW(RCL_CTL, 0x12, int)
#define RCL_CTL_IR_DUTY     _IOW(RCL_CTL, 0x13, int)
#define RCL_CTL_LINE_L_ON   _IOW(RCL_CTL, 0x14, int)
#define RCL_CTL_LINE_L_OFF  _IOW(RCL_CTL, 0x15, int)
#define RCL_CTL_LINE_R_ON   _IOW(RCL_CTL, 0x16, int)
#define RCL_CTL_LINE_R_OFF  _IOW(RCL_CTL, 0x17, int)
#define RCL_CTL_LINE_AUTO   _IOW(RCL_CTL, 0x18, int)
#define RCL_CTL_LINE_DUTY   _IOW(RCL_CTL, 0x19, int)
#define RCL_CTL_LINE_R_DUTY         _IOW(RCL_CTL, 0x1a, int)
#define RCL_CTL_GET_LINE_R_DUTY     _IOW(RCL_CTL, 0x1b, int)
#define RCL_CTL_LINE_L_AUTO _IOW(RCL_CTL, 0x20, int)
#define RCL_CTL_LINE_R_AUTO _IOW(RCL_CTL, 0x21, int)
#define RCL_CTL_TEST_MODE   _IOW(RCL_CTL, 0x22, int)
#define RCL_CTL_GET_LINE_DUTY   _IOW(RCL_CTL, 0x23, int)
#define RCL_CTL_GET_IR_DUTY _IOW(RCL_CTL, 0x24, int)
#define RCL_CTL_LED_DEBUG   _IOW(RCL_CTL, 0x25, int)
#define RCL_CTL_LINE_M_ON   _IOW(RCL_CTL, 0x26, int)
#define RCL_CTL_LINE_M_OFF  _IOW(RCL_CTL, 0x27, int)
#define RCL_CTL_LINE_M_AUTO _IOW(RCL_CTL, 0x28, int)
#define RCL_CTL_LINE_M_DUTY _IOW(RCL_CTL, 0x29, int)
#define RCL_CTL_GET_LINE_M_DUTY _IOW(RCL_CTL, 0x2a, int)
#define RCL_CTL_LINE_L_DUTY         RCL_CTL_LINE_DUTY
#define RCL_CTL_GET_LINE_L_DUTY     RCL_CTL_GET_LINE_DUTY
#endif
