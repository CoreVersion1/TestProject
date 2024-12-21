#ifndef __RR_FILE_COMBINE_H__
#define __RR_FILE_COMBINE_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "rda_headers.h"

#define COMB_FILE_NAME_MAX_LEN         (128)
#define COMB_FILE_PATH_MAX_LEN         (256)
#define COMB_BUF_MAX_LEN               (1024)//1K
#define COMB_MAGIC_HEADER              (0xCC67BB89)
#define COMB_MAGIC_ITEM                (0xDD34EEA1)
#define COMB_FILE_ITEM_NUM             (10)
#define COMB_FILE_TYPE_STR_LEN         (16)
/*********************Combine File Format************************************/
/*   | host file |comb_file1|...|comb_fileN|comb_item1|...|comb_itemN|comb_head_info| */
/* ************************************************************************/
typedef enum _rma_comb_file_type_e {
    RMA_COMB_FILE_TYPE_INVALID = 0,
    RMA_COMB_FILE_TYPE_DOCK_ONYX4,
    RMA_COMB_FILE_TYPE_MAX
} rma_comb_file_type_e;

typedef struct _rma_comb_file_item_s {
    uint32_t  magic;//4bytes
    uint32_t  type;//4bytes
    uint32_t  offset;//4bytes
    uint32_t  file_size;//4bytes
    char file_name[COMB_FILE_NAME_MAX_LEN];//128bytes
    char resv[32];
} rma_comb_file_item_s;

typedef struct _rma_comb_file_info_s {
    uint32_t  magic_head;//4bytes
    uint32_t  item_num;//4bytes
    uint32_t  chksum;//4 bytes
    char resv[16];
} rma_comb_file_info_s;

#define COMB_FILE_INFO_SIZE            sizeof(rma_comb_file_info_s)
#define COMB_FILE_ITEM_SIZE            sizeof(rma_comb_file_item_s)

/**
 *  Combine file1 with fil2 as rma_comb_file_item_s struct
 * @input:N/A
 * @return <0:failure, 0:success .
 */
int rma_combine_file(char *file1, char *file2);

/**
 *  Split file to split dir
 * @input:N/A
 * @return <0:failure, >=0 combine file nums .
 */
int rma_split_file(char *file, char *split_dir);

#ifdef __cplusplus
}
#endif
#endif
