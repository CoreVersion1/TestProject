#ifndef __RR_SOCKET_H__
#define __RR_SOCKET_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <netinet/in.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define AT_IPCBASE 0x80001234
extern const int kNoneModePort;
extern const int kStressTestPort;
extern const int kAtCmdTestPort;
extern const char kMasterIpAddress[];
extern const char kSlaveIpAddress[];

extern const long kDefaultIntMsgType;

#define IpcSendTo(func, id, payload) IpcSendBetween(__func__, func, id, payload);
#define IpcRecvFrom(func, id, payload, timeout) IpcRecvBetween(__func__, func, id, payload, timeout);
#define IpcClearQueueTo(func, id) IpcClearQueueBetween(__func__, func, id);

/// @brief One of the parameters of the MasterSlaveInit function, used to
///        identify different behavior in different modes
typedef enum UART_TEST_MODE_ {
    NONE_MODE = -1,
    STRESS_TEST_MODE,
    AT_CMD_MODE,
} UART_TEST_MODE;

/// @brief This enumeration is used to represent SLAVE's BIT test items and needs
///        to correspond one-to-one with the elements of slave_easy_bit_case_items
typedef enum BIT_ITEM_ {
    BIT_NONE = -1,
    BIT_TOF,
    BIT_RGB,
} BIT_ITEM;

#ifndef __cplusplus
typedef struct Socket_ {
    int sock_;
    struct sockaddr_in server_;
} Socket;
#endif

typedef struct msg_int_ {
    long msg_type;
    int32_t payload;
} msg_int;

typedef enum SLAVE_RET_ {
    SLAVE_OK = 0,
    SLAVE_FAIL,
    SLAVE_NO_TEST,
} SLAVE_RET;

bool Connect(Socket* sock, const char* host, int port);

bool Send(Socket* sock, const char* data, size_t data_size);

void Receive(Socket* sock, char* data, size_t size);

void ReceiveWithTimeout(Socket* sock, char* data, size_t size, int timeout_s, int* real_wait);

void Close(Socket* sock);

void Shutdown(Socket* sock, int how);

bool BindAndListen(Socket* sock, int port, int backlog);

Socket AccecptConnection(Socket* sock);

void SetNonBlock(Socket* sock);

void SetBlock(Socket* sock);

int convertToInt(const char* str, size_t size, int* result);

void MasterSlaveInit(Socket* sock, Socket* client, UART_TEST_MODE mode);

bool IpcClearQueue();

bool IpcSendInt(int payload);

/// @brief Receive IPC messages
/// @param payload result of IpcRecvInt
/// @param timeout The timeout time in seconds. If it's 0, it means it's always
///                waiting and won't time out, If IPC_NOWAIT indicates an
///                immediate return
bool IpcRecvInt(int* payload, int32_t timeout);

int AT_MasterCheckIfSlaveOK();

void AT_SlaveNotifyMaster(int payload);

bool isConnected();

/*
 * The following ipc function constructs an msgid from function names and ids to
 * achieve the purpose of sending ipc messages in a targeted manner. msgid is
 * obtained from two function names and ids spliced into a string and hashed,
 * with a very low probability of a hash conflict, so you can try adjusting the
 * ids to try if a similar situation arises.
*/
bool IpcClearQueueBetween(const char* func1, const char* func2, int id);

bool IpcSendBetween(const char* func1, const char* func2, int id, int payload);

bool IpcRecvBetween(const char* func1, const char* func2, int id, int* payload, int32_t timeout);

int GetSlaveAtCmdID(const char* at_cmd);

const char* GetSlaveAtCmdFuncStr(const char* at_cmd);

#ifdef __cplusplus
}
#endif

#endif  // __RR_SOCKET_H__