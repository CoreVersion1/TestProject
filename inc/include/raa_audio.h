#ifndef __RAA_AUDIO_H__
#define __RAA_AUDIO_H__

#include "rda_headers.h"
#if defined(__cplusplus)
extern "C" {
#endif

struct raa_audio_pcm_st;   //declared inside parameter list will not be visible outside
typedef struct raa_audio_pcm_st raa_audio_pcm_st;

typedef struct {
    char *filename;
    unsigned char *pdata;
    unsigned int data_sz;
    unsigned int num_channels;
    unsigned int sample_rate;
    unsigned int bits_per_sample;
    unsigned int audio_index;
    unsigned int vol;
} raa_audio_format_st;

extern int raa_audio_format_init(raa_audio_format_st **ppAF,
                                 const char *filename,
                                 unsigned char *pdata, const unsigned int data_sz,
                                 const unsigned int num_channels,
                                 const unsigned int sample_rate, const unsigned int bits_per_sample);
extern void raa_audio_format_free(raa_audio_format_st **ppAF);
extern int raa_audio_play_status();
extern int raa_speaker_status_get(void);
extern void raa_speaker_status_set_stop(void);

extern int raa_speaker_play_one_file(const char *filename, int vol,
                                     int wait_pre_over);
extern int raa_speaker_play_pcm_buffer(raa_audio_format_st *inpAF, int vol, int wait_pre_over);
extern int raa_speaker_set_vol_only(int vol);
/*
 * char **args = malloc(nums+1);
 * args[0] = str1
 * args[2] = str1
 * ...
 */
extern int raa_speaker_play_multi_files(const char **strs, unsigned int nums,
                                        unsigned int vol, int wait_pre_over);

/*  for app api begin */
#if defined(USE_UART_AUDIO_API) || defined(RR_DRV_SW_MIC)
enum PLAY_STATUS {
    PLAY_MIN = 0,
    PLAY_IDLE = 1,
    PLAY_BUSY = 2,
    PLAY_STOP = 3,
    PLAY_ERROR,
    PLAY_MAX,
};
#define RAA_AUDIO_PLAY_MIN   PLAY_MIN
#define RAA_AUDIO_PLAY_IDLE  PLAY_IDLE
#define RAA_AUDIO_PLAY_BUSY  PLAY_BUSY
#define RAA_AUDIO_PLAY_STOP  PLAY_STOP
#define RAA_AUDIO_PLAY_ERROR PLAY_ERROR
#define RAA_AUDIO_PLAY_MAX   PLAY_MAX

//int play_wav(const char *fn, int vol);
static inline int play_wav(const char *fn, int vol)
{
    return raa_speaker_play_one_file(fn, vol, 1);
}
static inline int set_vol(int vol)
{
    return raa_speaker_set_vol_only(vol);
}
static inline void play_stop(void)
{
    return raa_speaker_status_set_stop();
}
static inline int audio_get_status(void)
{
    return raa_speaker_status_get();
}
/*  for app api end*/
#else

enum RAA_AUDIO_PLAY_STATUS {
    RAA_AUDIO_PLAY_MIN = 0,
    RAA_AUDIO_PLAY_IDLE = 1,
    RAA_AUDIO_PLAY_BUSY = 2,
    RAA_AUDIO_PLAY_STOP = 3,
    RAA_AUDIO_PLAY_ERROR,
    RAA_AUDIO_PLAY_MAX,
};

#if defined(UART_API_PLATFORM_QCOM_APQ8053)
/* Bit formats */
enum pcm_format {
    PCM_FORMAT_INVALID = -1,
    PCM_FORMAT_S16_LE = 0,  /* 16-bit signed */
    PCM_FORMAT_S32_LE,      /* 32-bit signed */
    PCM_FORMAT_S8,          /* 8-bit signed */
    PCM_FORMAT_S24_LE,      /* 24-bits in 4-bytes */
    PCM_FORMAT_S24_3LE,     /* 24-bits in 3-bytes */

    PCM_FORMAT_MAX,
};
#endif
#endif

#if defined(UART_API_HAVE_MIC) || defined(RR_DRV_SW_MIC)

#define RAA_MIC_CHANNEL_SINGLE_FLAG 0x80000000

typedef enum {
    RAA_MIC_DIG,
    RAA_MIC_PGA,
} raa_mic_gain_e;

#define RAA_MIC_DEFAULT_GAIN -1
#define RAA_MIC_ALL_CHANEL   -1
extern int raa_mic_set_gain(raa_audio_pcm_st *pAP, int gain, int ch, int type);
extern int raa_mic_init(raa_audio_pcm_st **ppAP, unsigned int channels,
                        unsigned int sample_rate, unsigned int bits_per_sample);
extern int raa_mic_read(raa_audio_pcm_st *pAP, unsigned char *buf,
                        unsigned int buf_size);
extern void raa_mic_exit(raa_audio_pcm_st **ppAP);
#endif

extern int raa_pcm_buf_to_bytes(raa_audio_pcm_st *pAP);
extern int raa_pcm_frame_to_bytes(raa_audio_pcm_st *pAP);
extern int raa_pcm_format_to_bits(raa_audio_pcm_st *pAP);
extern int raa_pcm_prepare(raa_audio_pcm_st *pAP);
extern int raa_speaker_init(raa_audio_pcm_st **ppAP, unsigned int channels,
                            unsigned int sample_rate, unsigned int bits_per_sample);
extern int raa_speaker_set_vol(raa_audio_pcm_st *pAP, int vol);
extern int raa_speaker_write(raa_audio_pcm_st *pAP, unsigned char *pdata,
                             unsigned int data_size);
extern void raa_speaker_exit(raa_audio_pcm_st **ppAP);

#if defined(RR_DRV_SW_MIC)
#define UART_API_HAVE_MIC_CHANNEL RR_DRV_HW_MIC_CHANNEL_NUM
#endif

#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif
