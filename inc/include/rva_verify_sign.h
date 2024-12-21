#ifndef __RUA_VERIFY_SIGN_H__
#define __RUA_VERIFY_SIGN_H__

#ifdef __cplusplus
extern "C"
{
#endif

extern int rva_verify_ubrs(const unsigned char *key);
#ifdef RR_DRV_SW_SEC_ROTPK_CHECK
extern int rva_secureboot_state(char *status);
#else
extern int rva_secureboot_state(void);
#endif

#if defined(UART_API_HAVE_RR_WHEEL_SECURE_POLICY)
extern int uqEJo(void *pdata);
extern int p9s_mQ(void *pdata);
#define rva_secure_genkey1(...) uqEJo(__VA_ARGS__)
#define rva_secure_gendata(...) p9s_mQ(__VA_ARGS__)

#endif
#ifdef __cplusplus
}
#endif

#endif

