/* =============================================================================
#     FileName: rr_sha256.h
#         Desc: none
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage: https://www.roborock.com
#      Version: 0.0.1
#   LastChange: 2022-06-28 11:26:57
#      History: none
============================================================================= */

#ifndef __RR_SHA256_H__
#define __RR_SHA256_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rva_sha256_context {
    unsigned int total[2];          /*!< The number of Bytes processed.  */
    unsigned int state[8];          /*!< The intermediate digest state.  */
    unsigned char buffer[64];   /*!< The data block being processed. */
} rva_sha256_context;

extern void rva_sha256_init(rva_sha256_context *ctx);
extern int  rva_sha256_update(rva_sha256_context *ctx,
                              const unsigned char *input,
                              size_t ilen);
extern int  rva_sha256_finish(rva_sha256_context *ctx,
                              unsigned char output[32]);
extern void rva_sha256_free(rva_sha256_context *ctx);

#define RR_SHA256_LEN       32

#ifdef __cplusplus
}
#endif

#endif // __RR_SHA256_H__
