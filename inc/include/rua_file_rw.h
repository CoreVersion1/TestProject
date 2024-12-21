/* =============================================================================
#     FileName: rua_file_rw.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2021-04-22 10:01:22
#      History: none
============================================================================= */
#ifndef __RUA_FILE_RW_H__
#define __RUA_FILE_RW_H__
#if defined(__cplusplus)
extern "C" {
#endif

//offset > 0 means from start,  < 0, means from end;
//size = 0, means read last all data
extern int rua_read_file_block(const char *filename, char **data, int offset,
                               unsigned int size);

#define rua_read_file(filename, ppdata) rua_read_file_block(filename, ppdata, 0, 0)
extern int rua_read_node(const char *filename, char *data, size_t max_size);

extern int rua_write_file(const char *FileName, const char *pdata,
                          unsigned int dsize, int append);
#define rua_touch_file(f) rua_write_file(f, NULL, 0, 1)

#if defined(__cplusplus)
}  /* extern "C" */
#endif
#endif

