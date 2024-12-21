#ifndef __RVA_BASE64_H__
#define __RVA_BASE64_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define RVA_BASE64_ENC     1 /* encryption. */
#define RVA_BASE64_DEC     0 /* decryption. */

extern int rva_base64_crypt(int mode, unsigned char *dst, size_t dlen,
                            const unsigned char *src, size_t slen);

#ifdef __cplusplus
}
#endif

#endif /* __RVA_BASE64_H__ */

