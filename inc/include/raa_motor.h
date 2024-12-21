#ifndef __RAA_MOTOR_H__
#define __RAA_MOTOR_H__


#ifdef UART_API_HAVE_UPGRADE_MOTOR
#if defined(__cplusplus)
extern "C" {
#endif



typedef enum {
    MT_LEFT_WHEEL = 0,
    MT_RIGHT_WHEEL,
    MT_BRUSH,
    MT_SWEEP,
}
motor_u;


int rr_motor(motor_u mode, unsigned char *pathfile);





#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif

#endif


