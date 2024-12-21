
#ifndef __WEIGHT_H__
#define __WEIGHT_H__

#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
    scale_run = 0,//运行态，非锁定态
    scale_lock, //锁定态
    scale_lose, //秤台失联
} Scale_state_enum;
typedef struct {
    unsigned int weight_data;
    int scale_status;
} Weight_t;

#define WEIGHT_UNLOCK 0
#define WEIGHT_LOCK 1

typedef enum {
    WEIGHT_CMD_INVALID = 0,
    WEIGHT_CMD_START_GET_WEIGHT,
    WEIGHT_CMD_STOP_GET_WEIGHT,
    WEIGHT_CMD_CLEAR,
    WEIGHT_CMD_CAL,
    WEIGHT_CMD_MAX,
} Weight_cmd;
extern unsigned char g_have_get_ack[WEIGHT_CMD_MAX];
extern char g_weight_rcv_buf[128];
void start_get_weight(void);
void stop_get_weight(void);
void clean_weight_uart();
int init_weight(void);
int is_have_get_weight_data(void);
void clean_have_get_weight(void);
Weight_t get_weight_data(void);
int sent_weight_uart_raw(const char *buf, int len);
int SendClearOrSetzeroCmd(char cmdType);
void uninit_weight(void);
int  SendUserCalCmd(unsigned short calWeight, unsigned char calUnit);

#ifdef __cplusplus
}
#endif
#endif

