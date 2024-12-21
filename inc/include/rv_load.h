#ifndef __RV_LOAD_H__
#define __RV_LOAD_H__

#ifdef __cplusplus
extern "C" {
#endif
#define ITEM_LEN 512
#define MAX_ITEM_COUNT 100
typedef struct _regItemHead {
    unsigned short size;
    unsigned char id;
    unsigned char magic;
} REG_ITEM_HEAD;

typedef struct _regItem {
    REG_ITEM_HEAD head;
    unsigned char data[ITEM_LEN - sizeof(REG_ITEM_HEAD)];
} REG_ITEM;
typedef struct _regTableHead {
    unsigned int magic;
    unsigned int index;
} REG_TABLE_HEAD;
#define IS_VALID_REG_ITEM_ID(id)                      \
    ((id < MAX_ITEM_COUNT) ? 1 : 0)
#define RR_FLASH_REG_ITEM_MAGIC                       0xcd
#define IS_VALID_REG_ITEM_MAGIC(magic)                \
    ((magic == RR_FLASH_REG_ITEM_MAGIC) ? 1 : 0)
#define RR_FLASH_REG_TABLE_MAGIC                      0x12345678
#define IS_VALID_REG_TABLE_MAGIC(magic)               \
    ((magic == RR_FLASH_REG_TABLE_MAGIC) ? 1 : 0)
#define IS_VALID_REG_ITEM_SIZE(size)                  \
    ((size <= (ITEM_LEN - sizeof(REG_ITEM_HEAD))) ? 1 : 0)

int write_data_to_rv(REG_ITEM *pdata);
#ifdef __cplusplus
}
#endif
#endif
