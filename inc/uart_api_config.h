#ifndef __UART_API_CONFIG_H__
#define __UART_API_CONFIG_H__

/* uart_api version string */
/* #undef RR_PROJECT_CXXXX */
/* #undef RR_PROJECT_TOPAZ_SC */
/* #undef RR_PROJECT_ULTRON */
/* #undef RR_PROJECT_ULTRON_SPLUS */
/* #undef RR_PROJECT_PEARL_PLUS */
/* #undef RR_PROJECT_PEARL */
/* #undef RR_PROJECT_ULTRON_LITE */
/* #undef RR_PROJECT_ULTRON_E */
/* #undef RR_PROJECT_TANOS_SLITEPLUS */
/* #undef RR_PROJECT_ULTRON_SV */
/* #undef RR_PROJECT_ULTRON_SC */
/* #undef RR_PROJECT_PEARL_S */
/* #undef RR_PROJECT_PEARL_C */
/* #undef RR_PROJECT_CORAL */
/* #undef RR_PROJECT_PEARL_PLUSS */
/* #undef RR_PROJECT_BERYL */
/* #undef RR_PROJECT_VIVIAN */
/* #undef RR_PROJECT_R50 */
/* #undef RR_PROJECT_CORAL_PRO */
/* #undef RR_PROJECT_VERDELITE */
/* #undef RR_VIRTUAL_PROJECT_C91 */
/* #undef RR_PROJECT_B10003 */
/* #undef RR_PROJECT_VIVIAN_C */
/* #undef RR_PROJECT_TESSERACT */
/* #undef RR_PROJECT_B00002 */
/* #undef RR_PROJECT_PEARL_E */
/* #undef RR_PROJECT_VIVIAN_F */
/* #undef RR_PROJECT_PEARL_E_RISCV */
/* #undef RR_PROJECT_VIVIAN_S */
/* #undef RR_PROJECT_PEARL_EPRO */
/* #undef RR_PROJECT_VIVIAN_SC */
/* #undef RR_PROJECT_BUT */

#ifndef RR_PROJECT_BUT
#define RR_PROJECT_BUT
#define UART_API_PROJECT_NAME           "BUT"
#endif

//#define RR_ENABLE_COUPLE_PAIR

/* model will be sed by build.sh */
#define UART_API_PLATFORM_HOBOT_X5
#define UART_API_BUILD_TYPE_DEBUG
#define UART_API_ID_PROJECT_BASE 14

#ifdef RR_PROJECT_B00002
#undef UART_API_ID_PROJECT_BASE
#define UART_API_ID_PROJECT_BASE 14
#endif

#define UART_API_MAJOR_VERSION 6
#define UART_API_MINOR_VERSION 0
#define UART_API_BUILD_VERSION 0

/* RUBYS SPECIAL */
#if defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS) || defined(RR_PROJECT_GARNET)
#define UART_API_HAVE_RUBYS_BIT_ORDER
#if defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS)
#define UART_API_HAVE_RUBYS_FULLINFO
#define UART_API_HAVE_RUBYS_KEY
#endif
#elif defined(RR_PROJECT_TONOS_E)
#define UART_API_HAVE_TONOSE_FULLINFO
#endif

#if defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_PEARL_PLUS) || \
    defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_TANOS_SLITEPLUS)
#else
#define UART_API_HAVE_HW_CONFIG_JSON "/opt/rockrobo/cleaner/conf/hw_conf.json"
#endif

#if defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS) || defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYSLITE) || \
	defined(RR_PROJECT_RUBYS_C) || defined(RR_PROJECT_RUBYS_E) || defined(RR_PROJECT_TANOS_E) || defined(RR_PROJECT_TANOS_V) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#else
#define UART_API_AUTOBIT_TEST_RESET
#endif

#if defined(RR_PROJECT_RUBYS)
#define UART_API_HAVE_RUBYS_MT_ORDER
#define UART_API_HAVE_RUBYS_LDS
#endif

#if defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_VIVIAN_F)
#define UART_API_HAVE_WITHOUT_LDS
#endif

#if defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_TANOS)
#define UART_API_HAVE_STATION_SPECIAL
#endif

#ifndef RR_PROJECT_TANOS_V
#define UART_API_HAVE_WIFI_REMOVE_FILE
#endif

#if defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_RUBYS_C) || defined(RR_PROJECT_RUBYS_E) || defined(RR_PROJECT_RUBYPLUS) || \
    defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS) || defined(RR_PROJECT_TONOS_E)
#define UART_API_HAVE_FULLINFO_OLD
#endif

#if defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S)
#define RR_DRV_SW_SPINRAG_LIFE_TEST
#endif

/* MCU_VER*/
#define MCU_PROJECT_ID    1
#define KEYWORD_PROJECT_VALUE  UART_API_PROJECT_NAME
#if defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_GARNET) || defined(RR_PROJECT_ULTRON) || \
    defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_LITE) || \
    defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_MCU_ARCH_GD32F303ZET6
#if defined(RR_PROJECT_GARNET)
#define UART_API_MCU_ARCH_STM32F103ZET6
#endif

#if defined(RR_PROJECT_B10003)
#define UART_API_MCU_ARCH_GD32F303ZBT6
#endif
#endif

#if defined(RR_PROJECT_B10003)
#define RR_DRV_SW_MUTI_CORE_COMM
#endif

#if defined(RR_PROJECT_B10003) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define RR_DRV_SW_NV_PARTITION
#endif

#if defined(RR_PROJECT_B10003)

#else
#define RR_DRV_SW_SWD_CHECK_GYRO
#endif

#if defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define UART_API_HAVE_SIGMASTAR_RPMSG
#endif
/* MCU_VER END*/

#if defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define RR_DRV_SW_HAVE_ONLY_RISCV
#else
#define RR_DRV_SW_HAVE_MCU
#endif

/* key begin */
#if defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_PEARL_S) || \
    defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || \
    defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#else
#define UART_API_HAVE_KEY_SPOT
#endif /* key end */


/* led begin */
#define UART_API_HAVE_LED_TANOS
#if defined(RR_PROJECT_TANOS_S) || defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TOPAZ_SV_CV25) || \
    defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV)
#define UART_API_HAVE_FLOW_LED
#endif

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS)  || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_DRAG_LED
#endif

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_TESSERACT)
#define UART_API_HAVE_AP_MIC_LED
#endif

#if defined(RR_PROJECT_CORAL_PRO)
#define UART_API_HAVE_AP_GENERAL_LED
#endif

#if defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VERDELITE)
#define UART_API_WIFI_MIC_LED_INTEGRATION
#elif defined(RR_PROJECT_VIVIAN) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_MIC_LED_AS_DRAG_LED
#elif defined(RR_PROJECT_CORAL_PRO)
#define UART_API_WIFI_LED_AS_DRAG_LED
#define UART_API_GENERAL_LED_AS_MIC_LED
#elif defined(RR_PROJECT_VIVIAN_F)
#define UART_API_WIFI_LED_AS_DRAG_LED
#define UART_API_WIFI_MIC_LED_INTEGRATION
#else
    /*noting*/
#endif

#if defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_VIVIAN) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_MCU_CTRL_WIFI_LED
#endif

/* led end */


/* lds dock func */
#if defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_GARNET)
#define UART_API_HAVE_DOCK_SCORE
#endif /* key end */

/* brush */
#if defined(RR_PROJECT_RUBYSLITE)
#define UART_API_BRUSH_PWM_NORMAL    (71)
#define UART_API_BRUSH_PWM_SLOW      (45)
#elif defined(RR_PROJECT_GARNET)
#define UART_API_BRUSH_PWM_NORMAL    (70) //70 is max....
#define UART_API_BRUSH_PWM_SLOW	     (47)
#define UART_API_ROLLER_PWM_NORMAL   (-50)
#define UART_API_ROLLER_PWM_SLOW     (-50)
#else
#define UART_API_BRUSH_PWM_NORMAL    (70)
#define UART_API_BRUSH_PWM_SLOW      (30)
#endif

/* brushlift */
#if defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_ULTRON_SC) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_BUT)

#define UART_API_HAVE_BRUSHLIFT
#define UART_API_HAVE_AP_BRUSHLIFT
#if defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_BUT)
#define BRUSHLIFT_DET_ON_MIDDLE
#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_BUT)
#define BRUSHLIFT_DET_ON_MIDDLE_LIGHT_DET
#endif
#endif
#endif

/* ANALOG_5V controled by ap io*/
#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define AP_CONTROL_ANALOG_5V
#endif

#if defined(RR_PROJECT_R50)
#define UART_API_HAVE_AP_SWITCH_WHEEL_PWR_EN
#define UART_API_HAVE_AP_SWITCH_MECH_ARM_PWR_EN
#endif

#if defined(RR_PROJECT_R50)
#define UART_API_HAVE_AP_MOTOR_12V
#endif

#if defined(RR_PROJECT_TESSERACT)
#define UART_API_HAVE_AP_SWITCH_3V3C
#endif
/* sweep */
#ifndef RR_PROJECT_TESSERACT
#define RR_DRV_HW_HAVE_SWEEP
#endif
#if defined(RR_PROJECT_RUBYSLITE)
#define UART_API_SWEEP_PWM_NORMAL    (80)
#define UART_API_SWEEP_PWM_SLOW      (30)
#define UART_API_SWEEP_NEAR_DOCK     (20)
#elif defined(RR_PROJECT_TANOS_V) || defined(RR_PROJECT_TANOS_E)
#define UART_API_SWEEP_PWM_NORMAL    (81)
#define UART_API_SWEEP_PWM_SLOW      (32)
#define UART_API_SWEEP_NEAR_DOCK     (32)
#else
#define UART_API_SWEEP_PWM_NORMAL    (83)
#define UART_API_SWEEP_PWM_SLOW      (33)
#define UART_API_SWEEP_NEAR_DOCK     (20)
#endif

#if defined(RR_PROJECT_AMBER_E)
#define UART_API_HAVE_MOTOR_SEW
#endif

/* lds bumper begin */
#if defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_VIVIAN_F)
#else
#define UART_API_HAVE_BUMPER_TOP   //LDS_BUMPER
#endif

/* lds bumper choice begin */
#if defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_RUBYS_C) || defined(RR_PROJECT_RUBYS_E)
#define UART_API_HAVE_BUMPER_TOP_CHOICE
#endif

#if defined(RR_PROJECT_GARNET)
#define UART_API_HAVE_BUMPER_4
#endif


/* water box */
#if defined(RR_PROJECT_TANOS) || defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TANOS_S) || defined(RR_PROJECT_CXXXX) || \
    defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_S) || \
    defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || \
    defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_TOPAZ_SC) || \
    defined(RR_PROJECT_CORAL)
#define UART_HAVE_WATERBOX_SENSOR
#endif

#if defined (RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || \
    defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C)  || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_PEARL_E)|| \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_WATERBOX_BUILT_IN
#endif

/* rag board */
#if defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_TANOS_E) || defined(RR_PROJECT_TANOS_V) || defined(RR_PROJECT_TANOS_S) || \
    defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TANOSS_LITE) || defined(RR_PROJECT_TOPAZ_SV) || \
    defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_TOPAZ_SC) || \
    defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || \
    defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_WIPE_BOARD
#define UART_HAVE_WATER_CARRIAGE_SENSOR
#endif

#if defined (RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_B10003)
#define UART_API_HAVE_RAG_BUILT_IN
#endif

#if defined (RR_PROJECT_TANOSS_LITE)
#define UART_API_HAVE_WATER_DUSTIN_UNITY
#endif

/* water tank report struct */
#if defined(UART_HAVE_WATERBOX_SENSOR) || defined(UART_HAVE_WATER_CARRIAGE_SENSOR) || defined(UART_API_HAVE_WATERBOX_BUILT_IN) || defined(UART_API_HAVE_RAG_BUILT_IN)
#define UART_API_HAVE_WATERBOX
#endif

/* water level */
#if defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON_SPLUS) || \
    defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003)
    #define UART_API_HAVE_WATER_LEVEL
#endif

#if defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC)
#else
#define RR_HW_ENABLE_DOCK_IR_FRONT
#if defined (RR_PROJECT_VIVIAN_F)
#define RR_HW_ENABLE_DOCK_IR_FRONT_SINGLE_RIGHT
#endif
#endif

/* dock back bumper, ir, and ir communication */
#if defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TOPAZS_PLUS) ||\
    defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_SPLUS) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL)|| \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E)|| defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_PEARL_E_RISCV) || \
    defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_DOCK_IR_BACK
#define UART_API_HAVE_DOCK_IR_COMMUNICATION_BACK
#if defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || \
    defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_SPLUS) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_DOCK_BUMPER
#define UART_API_HAVE_AP_DOCK_BUMPER    /* UPPER: UART_API_HAVE_DOCK_BUMPER */
#endif
#endif

/*use rag L & R*/
#if defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_CORAL_PRO) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E)|| defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define UART_API_HAVE_RAG_L_R
#endif

#if defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_R50)
#define UART_API_HAVE_SPINRAG_HALL_MT8001
#endif

#if defined(RR_PROJECT_TESSERACT)
#define RR_DRV_SW_SLAVE_AP_TIME_SYNC
#define RR_DRV_HW_IR_CODE_EMITTER
#define RR_DRV_HW_CABIN_BUMPER
#endif

#if defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_LITE) || defined(RR_PROJECT_TANOSS_C) || \
    defined(RR_PROJECT_TANOSS_E) || defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || \
    defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || \
    defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define UART_API_HAVE_DOCK_IR_SINGLE_POWER
#endif

/*
 * water tank, rag board, water level, lds bumper, dock bumper, dust box in ap side macro.
 * do not use these macros in the upper layer except 'UART_API_HAVE_AP_SWITCHES'
*/
#if defined(RR_PROJECT_TANOS_S) || defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_S) || \
    defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV)  || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_CXXXX) || \
    defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || \
    defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define UART_API_HAVE_AP_SWITCHES

#if !defined(RR_PROJECT_CORAL_PRO) || !defined(RR_PROJECT_R50)
#define UART_API_HAVE_AP_WATER_TANK     /* UPPER: UART_HAVE_WATERBOX_SENSOR */
#endif
#define UART_API_HAVE_AP_LDS_BUMPER     /* UPPER: UART_API_HAVE_BUMPER_TOP */

#if defined(RR_PROJECT_BERYL)
#define UART_API_HAVE_AP_SEWAGE_TANK
#endif

#if defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_CORAL_PRO)
#else
#define UART_API_HAVE_AP_RAG            /* UPPER: UART_HAVE_WATER_CARRIAGE_SENSOR */
#endif

#define RR_DRV_HW_HAVE_DUSTBOX
#define RR_DRV_HW_HAVE_BRUSH

#if !defined(RR_PROJECT_R50)
#define UART_API_HAVE_AP_DUSTBOX        /* UPPER: default */
#endif

#if defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || \
    defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_CXXXX) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_B10003)
#define UART_API_HAVE_AP_WATER_LEVEL    /* UPPER: UART_API_HAVE_WATER_LEVEL */
#endif

#if defined(RR_PROJECT_TOPAZ_SV)  || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || \
    defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) ||\
    defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_AP_DOCK_IR_SINGLE_POWER
#endif

#endif

#if defined(RR_PROJECT_TESSERACT)
#define UART_API_HAVE_AP_SWITCHES
#define UART_API_HAVE_AP_DOCK_IR_SINGLE_POWER
#define RR_DRV_HW_MIXED_BUMPER_MCU
#define RR_DRV_SW_BUMPER_BRAKE_SWITCH_MCU
#define RR_DRV_SW_TOFCLIFF_BRAKE_SWITCH_MCU
#define UART_API_HAVE_DOCK_DUST_COLLECTION  // Building will report error if delete it
#define DOCK_IR_SENT_LEN     5             //
#endif


/*stretch sweep, universal wheel ,rag light l&r, wheel down l&r*/
#if defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_HAVE_AP_STRETCH_SWEEP_DET
#define UART_API_HAVE_AP_WHEEL_DET

#if defined(RR_PROJECT_VIVIAN_SC)
#define RR_DRV_HW_HAVE_ONLY_UNIVERSAL_WHEEL_DET
#endif
#endif

#if defined(RR_PROJECT_VIVIAN) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_HAVE_AP_RAG_LIGHT_DET
#endif

#if defined(RR_PROJECT_VIVIAN) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_C)
#define RR_DRV_TESTMODE_MT_DOCKMODE_FLAG
#endif

/* peristaltic pump*/
/*
 * tanoss has water pump too, but it shares the same motor as the mop module, so we started the mop module and started it
 */
#if defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_PEARL_PLUS) || \
    defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_PEARL_S) || \
    defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_EPRO)||defined(RR_PROJECT_PEARL_E_RISCV) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
// for compile in app, we have to define these 2 macros simutanuously.
#define UART_API_HAVE_WATER_PUMP
#define UART_API_HAVE_WATER_PUMP_V2
#endif

/* mop */
#if  defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON) ||  defined(RR_PROJECT_TOPAZ_SC) || \
     defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_SPLUS) ||  defined(RR_PROJECT_PEARL_PLUS) || \
     defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
     defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
     defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
     defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
     defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
     defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_MOP

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003)
#define UART_API_HAVE_MOP_SIDE
#endif

#if defined(RR_PROJECT_PEARL)
#define UART_API_HAVE_DOUBLE_SPIN_RAG
#endif

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_PEARL_S) || \
    defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || \
    defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || \
    defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_DOUBLE_CTRL_DOUBLE_SPIN_RAG
#endif

#if defined(UART_API_HAVE_DOUBLE_SPIN_RAG) || defined(UART_API_HAVE_DOUBLE_CTRL_DOUBLE_SPIN_RAG)
#define UART_API_MOP_PWM_NORMAL      (70)
#define UART_API_MOP_PWM_SLOW        (70)
#else
#define UART_API_MOP_PWM_NORMAL      (38)
#define UART_API_MOP_PWM_SLOW        (13)
#endif

#endif

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_STRECH_RAG
#endif

#if defined(RR_PROJECT_GARNET)
#define UART_API_TEMPER_COOKER
#endif

#if defined(RR_PROJECT_TANOS_V)
#define UART_API_LINK_LIBMBEDCRYPTO_2
#endif

#if defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TANOS_S) || defined(RR_PROJECT_GARNET) || defined(RR_PROJECT_CXXXX) || \
    defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_SV) || \
    defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_MAX) ||\
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || \
    defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
/*#define UART_API_HAVE_UPGRADE_MOTOR*/
#define UART_API_HAVE_CARPET
#endif

#if defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_CORAL)
#define UART_API_HAVE_MOUSE
#endif

/* cliff */
/* Project difference of cliff */
#if defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_RUBYS_C) || defined(RR_PROJECT_RUBYS_E) || \
    defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOSS_LITE) || defined(RR_PROJECT_TANOSS_C) || defined(RR_PROJECT_TANOSS_E) || \
    defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_PEARL_EPRO)||defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_HAVE_CLIFF_4
#define UART_API_HAVE_CLIFF 4
#elif defined(RR_PROJECT_PEARL_E)
#define UART_API_HAVE_CLIFF_3
#define UART_API_HAVE_CLIFF 3
#elif defined(RR_PROJECT_GARNET)
#define UART_API_HAVE_CLIFF_7
#define UART_API_HAVE_CLIFF 7
#elif defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
      defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VERDELITE) || \
      defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_CLIFF_5
#define UART_API_HAVE_CLIFF 5
#elif defined(RR_PROJECT_TESSERACT)
#define RR_DRV_HW_CLIFF_MCU_8
#define UART_API_HAVE_CLIFF 8
#else //  tanos, tanos_e, tanos_v, ruby2...
#define UART_API_HAVE_CLIFF_6
#define UART_API_HAVE_CLIFF 6
#endif

#if defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E)
#define UART_API_HAVE_DOCK_DUST_COLLECTION  //onyx1,  only collection garbage from dustbox
#define DOCK_IR_SENT_LEN     5
#elif defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_PEARL_PLUS) || \
    defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_ULTRON_SC) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || \
    defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_DOCK_CLEAN_MOPPING_CLOTH_AND_DUST_COLLECTION //support onyx2 (clean mopping cloth) and onyx1
#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define DOCK_IR_SENT_LEN     6
#else
#define DOCK_IR_SENT_LEN     5
#endif
#endif


#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_BUT)
#define UART_API_DOCK_IR_NEW_COMMUNACATION
#define DOCK_STATUS_CODE_NUM     5
#else
#define DOCK_STATUS_CODE_NUM     4
#endif

#if defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON)  || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON_SPLUS) || \
    defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E)
#define UART_API_HAVE_DOCK_IR_COMMUNICATION
#endif

// #if defined(RR_PROJECT_CORAL_PRO) ||defined(RR_PROJECT_VERDELITE)
#if defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50)
#define RR_DRV_SW_DOCK_UART
#endif


/* compass */
#if defined(RR_PROJECT_TANOS_V) || defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_RUBYS_C) ||\
    defined(RR_PROJECT_RUBYS_E) || defined(RR_PROJECT_TANOS_E) || defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS)
#define UART_API_HAVE_COMPASS
#define UART_API_HAVE_COMPASS_1
#if defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS)
#define UART_API_HAVE_COMPASS_2
#endif
#endif

/* wallsensor lighttouch*/
#if defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || \
    defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E)
#define UART_API_HAVE_LIGHT_TOUCH
#elif defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50)
#define RR_DRV_HW_VLINE_WALL_SENSOR
/* #undef RR_DRV_HAVE_AFTER_SALE_VLINE_WS_SELF_CALIBRATION_MODE */
#else /* rubyplus, ruby, tanos, tanosv, ruby2, tanose */
#if defined(RR_PROJECT_TESSERACT)
#else
#define UART_API_HAVE_WALLSENSOR
#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_PEARL_EPRO)||defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_LIGHT_TOUCH_3
#define UART_API_HAVE_SELF_LT3_CALIBRATION_MODE
#endif
#endif
#endif

/* ap-mcu time sync */
#if defined(RR_PROJECT_TANOS_V)
#define UART_API_MCU_TIME_HARD_SYNC
//#define UART_API_MCU_TIME_HARD_SYNC_TEST  /* uart_test -TT -pa */
#endif

/* audio begin*/
#define UART_API_HAVE_SPK

/* hardware only have lineout_right */
#if defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define RR_DRV_HW_ONLY_LINEOUT_RIGHT
#endif

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) ||defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define UART_API_USE_ALSA
#define UART_API_USE_ALSA_SOFT_VOL
#endif

#if defined(UART_API_PLATFORM_JLQ_JA308)
#define UART_API_HAVE_SPK_LIMIT_PERCENT 45
#else
#define UART_API_HAVE_SPK_LIMIT_PERCENT 100
#endif

#if defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS)
#else
#define UART_API_HAVE_SPK_OGG
#endif

#define USE_UART_AUDIO_API

#if defined(RR_PROJECT_TANOS_V)
#else
#define UART_API_HAVE_SPK_MULTI_TIMES_PLAY
#endif

/*upgrade voice packet*/
#if defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS) || defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_TANOS_V)
#else
#define UART_API_HAVE_VOICE_UPGRADE
#define UART_API_HAVE_CHECK_SOUND_INFO
#define UART_API_GET_CUR_LANGUAGE
#endif

/* testinfo begin */
#if defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_TOPAZS_PLUS) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON_LITE) || \
    defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || \
    defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC)  || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || \
    defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_PEARL_E_RISCV) || \
    defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_TESTINFO_V2
#endif

/* docktype define */
#if defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || \
    defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_E) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || \
    defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_NEW_CHARGE_DEF
#endif

/* testinfo end */

/* mic */
#if defined(RR_PROJECT_TANOS_V)
/*#define UART_API_HAVE_MIC*/
/*#define UART_API_HAVE_MIC_LED*/
/*#define UART_API_HAVE_MIC_7_CHANNEL*/
/*#define UART_API_HAVE_MIC_CHANNEL 7*/
#elif defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_B00002)
#define UART_API_HAVE_MIC
#define UART_API_HAVE_MIC_CHANNEL 2
#if defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_B00002)
#define UART_API_MIC_DEFAULT_GAIN_PGA1  100   //percent gain
#define UART_API_MIC_DEFAULT_GAIN_ADC1  100   //percent gain
#endif
#elif defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
        defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)

#if defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50)
#define BAIDU_AUTHENTICATION_CHIP_I2C_DEV_NAME "/dev/i2c-7"
#elif defined(RR_PROJECT_VIVIAN_F)
#define BAIDU_AUTHENTICATION_CHIP_I2C_DEV_NAME "/dev/i2c-3"
#elif defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
#define BAIDU_AUTHENTICATION_CHIP_I2C_DEV_NAME "/dev/i2c-4"
#elif defined(RR_PROJECT_BUT)
#define BAIDU_AUTHENTICATION_CHIP_I2C_DEV_NAME "/dev/i2c-0"
#endif

#define RR_DRV_SW_MIC
#define RR_DRV_SW_MIC_AI_BAIDU_WITHOUT_DSP     /* UPPER: RR_DRV_SW_MIC voice control*/
#define RR_DRV_HW_MIC_CHANNEL_NUM 6
#define RR_DRV_HW_MIC_CHANNEL_SEP
#endif

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003)
#define UART_API_HAVE_BAIDU_MIC

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_DSP_LOAD_BIN_FROM_AP
#endif

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT)
#define UART_API_DSP_REPORT_SPI_ERR_COUNT
#endif
#endif

//don't modify, only used for coral_pro&vivian
#if defined(RR_PROJECT_CORAL_PRO)
#define RR_DRV_HW_BAIDU_HONGHU_MIC
#if defined(RR_DRV_HW_BAIDU_HONGHU_MIC)
#define UART_API_HAVE_BAIDU_MIC
#define UART_API_DSP_REPORT_SPI_ERR_COUNT
#define UART_API_DSP_LOAD_BIN_FROM_AP
#else
#define BAIDU_AUTHENTICATION_CHIP_I2C_DEV_NAME "/dev/i2c-0"
#define RR_DRV_SW_MIC
#define RR_DRV_SW_MIC_AI_BAIDU_WITHOUT_DSP     /* UPPER: RR_DRV_SW_MIC voice control*/
#define RR_DRV_HW_MIC_CHANNEL_NUM 6
#define RR_DRV_HW_MIC_CHANNEL_SEP
#endif

#endif

/*mic end*/

/* camera begin*/
#if defined(RR_PROJECT_TANOS_V) || defined(RR_PROJECT_RUBY2) || defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_AMBER_E) || \
    defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || \
    defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || \
    defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define UART_API_HAVE_CAMERA
#if defined(RR_PROJECT_TANOS_V) || defined(RR_PROJECT_RUBY2) || defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TANOSS_PLUS) || \
	defined(RR_PROJECT_TOPAZ_SV_CV25) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || \
    defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || \
    defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_PEARL_PLUS) || \
    defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SC) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_BERYL) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_PEARL_E)
#define UART_API_HAVE_CAMERA_DISPLAY
#endif

/* Project difference of camera */
#if defined(RR_PROJECT_TANOS_V)
#define UART_API_HAVE_CAMERA_LED
#define UART_API_HAVE_QCOM_CAMERA
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_NUM 2
#define UART_API_CAMERA_COLOR_RGB
//#define UART_API_CAMERA_YUV_W 1280
//#define UART_API_CAMERA_YUV_H 960
#define UART_API_CAMERA_YUV_W 1600
#define UART_API_CAMERA_YUV_H 1200
#define UART_API_CAMERA_FPS_MAX 15
#define UART_API_CAMERA_FPS_MIN 15
//#define UART_API_CAMERA_COLOR_MONO
#elif defined(RR_PROJECT_TANOS_RUBY2)
#define UART_API_HAVE_CAMERA_1
#define UART_API_HAVE_CAMERA_NUM 1
#define UART_API_CAMERA_COLOR_MONO
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#elif defined(RR_PROJECT_CXXXX)
//#define UART_API_HAVE_JA308_CAMERA_TOF
//#define UART_API_HAVE_JA308_CAMERA
#define UART_API_HAVE_AW813_CAMERA_TOF
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_NUM 2
#define UART_API_HAVE_CAMERA_LED
// #define UART_API_AUTOBIT_TEST_CAMERA_LED
//#define UART_API_CAMERA_COLOR_RAW
//#define UART_API_CAMERA_RAW_W 320
//#define UART_API_CAMERA_RAW_H 240
//#define UART_API_CAMERA_YUV_W 320
//#define UART_API_CAMERA_YUV_H 240
#elif defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_MAX) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_SC)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_MODE_AUTO //driver auto contrl led on off directly, app doesn't neet to care
#define UART_API_HAVE_MR813_CAMERA_MONO
#define UART_API_HAVE_CAMERA_NUM    1
#define UART_API_SPLIT_FRAME        2
#define UART_API_CAMERA_COLOR_MONO
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#if defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_SC)
#define UART_API_HAVE_CAMERA_PWM_ADAPT
#endif
#if defined(RR_PROJECT_ULTRON_SC)
#define UART_API_HAVE_MR813_CAMERA_RESERVE_1C2L
#endif
#elif defined(RR_VIRTUAL_PROJECT_C91)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_CAMERA_LED_SINGLE
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_ONLY_IR
// #define UART_API_HAVE_CAMERA_LED_MODE_AUTO //driver auto contrl led on off directly, app doesn't neet to care
#define UART_API_HAVE_MR813_CAMERA_2
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
// #define UART_API_HAVE_CAMERA_2C1L
#define UART_API_HAVE_CAMERA_DUAL
#define UART_API_HAVE_MR813_CAMERA_THREAD
#define UART_API_HAVE_MR813_CAMERA_SERVER
#define UART_API_HAVE_CAMERA_NUM    1
//#define UART_API_SPLIT_FRAME        2
#define UART_API_CAMERA_COLOR_MONO
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#elif defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_CAMERA_LED_SINGLE
#define UART_API_HAVE_CAMERA_2
// #define UART_API_HAVE_CAMERA_LED_MODE_AUTO //driver auto contrl led on off directly, app doesn't neet to care
#define UART_API_HAVE_MR813_CAMERA_2
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C1L
#define UART_API_HAVE_CAMERA_DUAL
#define UART_API_HAVE_MR813_CAMERA_THREAD
#define UART_API_HAVE_MR813_CAMERA_SERVER
#define UART_API_HAVE_CAMERA_NUM    2
//#define UART_API_SPLIT_FRAME        2
#define UART_API_CAMERA_COLOR_MONO
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#elif defined(RR_PROJECT_TOPAZ_SV_CV25)
#define UART_API_HAVE_CAMERA_LED
#define UART_API_HAVE_CV25_CAMERA
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_NUM    2
#define UART_API_SPLIT_FRAME        2
//#define UART_API_CAMERA_COLOR_MONO
//#define UART_API_CAMERA_YUV_W 640
//#define UART_API_CAMERA_YUV_H 480
#elif defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_JA308_CAMERA
#define UART_API_HAVE_CAMERA_NUM    2
#define UART_API_SPLIT_FRAME        2
#elif defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E)
#define UART_API_HAVE_CAMERA_PWM_ADAPT
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_MODE_AUTO
#define UART_API_CAMERA_LED_SINGLE
#define UART_API_HAVE_R16_CAMERA
#define UART_API_HAVE_CAMERA_NUM    1

#if defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E)
#define RR_SLIGHT_VGA 1
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#endif

#ifdef RR_SLIGHT_VGA
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 250
#else
#define UART_API_CAMERA_YUV_W 320
#define UART_API_CAMERA_YUV_H 200
#endif
#elif defined(RR_PROJECT_ULTRON_SV)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_DISPLAY
// #define UART_API_HAVE_CAMERA_LED_MODE_AUTO //driver auto contrl led on off directly, app doesn't neet to care
#define UART_API_HAVE_MR527_CAMERA
#define UART_API_HAVE_MR527_CAMERA_THREAD
#define UART_API_HAVE_MR527_CAMERA_SERVER
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C2L
#define UART_API_HAVE_CAMERA_DUAL
#define UART_API_HAVE_CAMERA_NUM    2
//#define UART_API_SPLIT_FRAME        2
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define UART_API_CAMERA_RGB_W 800
#define UART_API_CAMERA_RGB_H 600
#define UART_API_CAMERA_RGB_RAW_W 800
#define UART_API_CAMERA_RGB_RAW_H 600
#elif  defined(RR_PROJECT_B10003)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_DISPLAY
// #define UART_API_HAVE_CAMERA_LED_MODE_AUTO //driver auto contrl led on off directly, app doesn't neet to care
#define UART_API_HAVE_MR536_CAMERA
#define UART_API_HAVE_MR536_CAMERA_THREAD
#define UART_API_HAVE_MR536_CAMERA_SERVER
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C2L
#define UART_API_HAVE_CAMERA_DUAL
#define UART_API_HAVE_CAMERA_NUM    2
//#define UART_API_SPLIT_FRAME        2
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define UART_API_CAMERA_RGB_W 800
#define UART_API_CAMERA_RGB_H 600
#define UART_API_CAMERA_RGB_RAW_W 800
#define UART_API_CAMERA_RGB_RAW_H 600
#elif defined(RR_PROJECT_CORAL)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_HAVE_MR527_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_MR527_TOF_RGB
#define RR_DRV_HW_HAVE_TOF_NUM 2
#define UART_API_HAVE_MR527_CAMERA_THREAD
#define UART_API_HAVE_MR527_CAMERA_SERVER
#define UART_API_HAVE_CAMERA_NUM    1  //JUST RGB
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define UART_API_CAMERA_RGB_W 800
#define UART_API_CAMERA_RGB_H 600
#define UART_API_CAMERA_RGB_RAW_W 800
#define UART_API_CAMERA_RGB_RAW_H 600
//#define UART_API_HAVE_TOF_CHAOFENG
#define UART_API_KERNEL_MODULE_VIN_V4L2_NAME        "vin_v4l2"
//#ifdef UART_API_HAVE_TOF_CHAOFENG
#define UART_API_KERNEL_MODULE_TOF_SLAVE_NAME_CHAOFENG       "vi4331_slave"
#define UART_API_KERNEL_MODULE_TOF_MASTER_NAME_CHAOFENG      "vi4331_master"
//#else
#define UART_API_KERNEL_MODULE_TOF_SLAVE_NAME_OMS       "irs2875c_slave"
#define UART_API_KERNEL_MODULE_TOF_MASTER_NAME_OMS      "irs2875c_master"
//#endif
#elif defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_R50)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_HAVE_MR527_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_MR527_TOF_RGB
#define RR_DRV_HW_HAVE_TOF_NUM 2
#define UART_API_HAVE_MR527_CAMERA_THREAD
#define UART_API_HAVE_MR527_CAMERA_SERVER
#define UART_API_HAVE_CAMERA_NUM    1 //JUST RGB
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define UART_API_CAMERA_RGB_W 800
#define UART_API_CAMERA_RGB_H 600
#define UART_API_CAMERA_SPLIT_VIDEO_NODE
#define UART_API_CAMERA_RGB_RAW_W 1600
#define UART_API_CAMERA_RGB_RAW_H 1200
//#define UART_API_HAVE_TOF_CHAOFENG
#define UART_API_KERNEL_MODULE_VIN_V4L2_NAME        "vin_v4l2"
//#ifdef UART_API_HAVE_TOF_CHAOFENG
#define UART_API_KERNEL_MODULE_TOF_SLAVE_NAME_CHAOFENG       "vi4331_slave"
#define UART_API_KERNEL_MODULE_TOF_MASTER_NAME_CHAOFENG      "vi4331_master"
//#else
#define UART_API_KERNEL_MODULE_TOF_SLAVE_NAME_OMS       "irs2875c_slave"
#define UART_API_KERNEL_MODULE_TOF_MASTER_NAME_OMS      "irs2875c_master"
#elif defined(RR_PROJECT_TESSERACT)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define RR_DRV_HW_AW_CAMERA
#define RR_DRV_SW_CAMERA_EEPROM_V3
#define RR_DRV_SW_CAMERA_REFACTOR
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C1L
#define RR_DRV_SW_TOF_REFACTOR
#define RR_DRV_SW_TOF_REFACTOR_CHAOFENG
#define RR_DRV_HW_MR527_CAMERA
#define UART_API_HAVE_MR527_CAMERA_THREAD
#define UART_API_HAVE_MR527_CAMERA_SERVER
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define UART_API_CAMERA_RGB_W 800
#define UART_API_CAMERA_RGB_H 600
#define UART_API_CAMERA_SPLIT_VIDEO_NODE
#define UART_API_CAMERA_RGB_RAW_W 1600
#define UART_API_CAMERA_RGB_RAW_H 1200
//#define UART_API_HAVE_TOF_CHAOFENG
#define UART_API_KERNEL_MODULE_VIN_V4L2_NAME        "vin_v4l2"
//#ifdef UART_API_HAVE_TOF_CHAOFENG
#define UART_API_KERNEL_MODULE_TOF_SLAVE_NAME_CHAOFENG       "vi4331_slave"
#define UART_API_KERNEL_MODULE_TOF_MASTER_NAME_CHAOFENG      "vi4331_master"
//#else
#define UART_API_KERNEL_MODULE_TOF_SLAVE_NAME_OMS       "irs2875c_slave"
#define UART_API_KERNEL_MODULE_TOF_MASTER_NAME_OMS      "irs2875c_master"
//#endif
#elif defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_VERDELITE)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_PWM_ADAPT
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_DISPLAY
// #define UART_API_HAVE_CAMERA_LED_MODE_AUTO //driver auto contrl led on off directly, app doesn't neet to care
#define UART_API_HAVE_MR527_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C3L
#define UART_API_HAVE_CAMERA_DUAL
#define UART_API_HAVE_MR527_CAMERA_THREAD
#define UART_API_HAVE_MR527_CAMERA_SERVER
#define UART_API_HAVE_CAMERA_NUM    2
//#define UART_API_SPLIT_FRAME        2
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define UART_API_CAMERA_RGB_W 800
#define UART_API_CAMERA_RGB_H 600
#define UART_API_CAMERA_SPLIT_VIDEO_NODE
#define UART_API_CAMERA_RGB_RAW_W 1600
#define UART_API_CAMERA_RGB_RAW_H 1200
#define RR_DRV_SW_CAMERA_ISP_AE_CONFIG
#elif defined(RR_PROJECT_B00002)
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_NUM 2
#define UART_API_HAVE_9383C_CAMERA
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_CAMERA_LED_SINGLE
#define UART_API_HAVE_CAMERA_2
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C1L
#define UART_API_HAVE_CAMERA_DUAL
#define UART_API_HAVE_9383C_CAMERA_THREAD
#define UART_API_HAVE_9383C_CAMERA_SERVER
#define UART_API_CAMERA_SPLIT_VIDEO_NODE
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#elif defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define UART_API_HAVE_CAMERA_NUM 1
#define UART_API_HAVE_9383C_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_ONLY_IR
#define UART_API_HAVE_9383C_CAMERA_THREAD
#define UART_API_HAVE_9383C_CAMERA_SERVER
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#elif defined(RR_PROJECT_VIVIAN_F)
#define UART_API_HAVE_CAMERA_NUM 1
#define RR_DRV_SW_CAMERA_REFACTOR
#define RR_DRV_HW_SIGMA_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_ONLY_IR
#define UART_API_HAVE_9383C_CAMERA_THREAD
#define UART_API_HAVE_9383C_CAMERA_SERVER
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_CAMERA_LED_SINGLE
#elif defined(RR_PROJECT_VIVIAN_S)
#define UART_API_HAVE_CAMERA_NUM 1
#define RR_DRV_SW_CAMERA_REFACTOR
#define RR_DRV_HW_SIGMA_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C1L
#define UART_API_HAVE_9383C_CAMERA_THREAD
#define UART_API_HAVE_9383C_CAMERA_SERVER
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define RR_DRV_SW_CAMERA_EEPROM_V3
// #define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_CAMERA_LED_SINGLE
#elif defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_HAVE_CAMERA_NUM 1
#define RR_DRV_SW_CAMERA_REFACTOR
#define RR_DRV_HW_SIGMA_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C1L
#define UART_API_HAVE_9383C_CAMERA_THREAD
#define UART_API_HAVE_9383C_CAMERA_SERVER
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define RR_DRV_SW_CAMERA_EEPROM_V3
// #define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_CAMERA_LED_SINGLE
#elif defined(RR_PROJECT_VIVIAN_C)
#define UART_API_HAVE_CAMERA_NUM 1
#define UART_API_HAVE_9383C_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_1C1L
#define UART_API_HAVE_9383C_CAMERA_THREAD
#define UART_API_HAVE_9383C_CAMERA_SERVER
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define RR_DRV_SW_CAMERA_EEPROM_V3
#define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define UART_API_HAVE_CAMERA_LED_AW
#define UART_API_CAMERA_LED_SINGLE
#elif defined(RR_PROJECT_BUT)
#define UART_API_HAVE_CAMERA_NUM 1
#define RR_DRV_SW_CAMERA_REFACTOR
#define RR_DRV_HW_HOBOT_CAMERA
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define UART_API_HAVE_CAMERA_2C1L
#define RR_DRV_SW_CAMERA_THREAD
#define RR_DRV_SW_CAMERA_SERVER
#define UART_API_CAMERA_RAW_W 640
#define UART_API_CAMERA_RAW_H 480
#define UART_API_CAMERA_YUV_W 640
#define UART_API_CAMERA_YUV_H 480
#define RR_DRV_SW_CAMERA_EEPROM_V3
// #define UART_API_AUTOBIT_TEST_CAMERA_LED
#define UART_API_HAVE_CAMERA_LED_2
#define RR_DRV_SW_CAMERA_LED
#define UART_API_CAMERA_LED_SINGLE
#endif

#if defined(UART_API_HAVE_MR527_CAMERA)
#define UART_API_HAVE_CAMERA_PWM_DUTY
#endif

#endif /* camera end*/

#if defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_TOPAZ_SV) || \
    defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || \
    defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL)|| \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || \
    defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define COOKER_LOOP_TOTAL_MS    40*60*1000
#else
#define COOKER_LOOP_TOTAL_MS    60*60*1000
#endif
#if defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TANOSS_MAX)
#define COOKER_MODE_DISABLE_MOP
#endif

#if defined(UART_API_PLATFORM_ALLWINNER_MR813)
#define UART_API_GPU_USE_OPENCL
#define UART_API_AUDIO
#endif

#if defined(UART_API_PLATFORM_SIGMASTAR_SSU9383C)
#define UART_API_AUDIO
#endif

#if defined(UART_API_PLATFORM_ALLWINNER_MR527) || defined(UART_API_PLATFORM_ALLWINNER_MR536)
#define UART_API_NPU_USE_VIPLITE
#define UART_API_GPU_USE_OPENCL
#define UART_API_RRNPU
#define UART_API_AUDIO
#define UART_API_HAVE_NEW_LED_DIRVER
#endif

#if defined(UART_API_PLATFORM_SIGMASTAR_SSU9383C)
#define UART_API_RRNPU
#endif

#if defined(UART_API_PLATFORM_ALLWINNER_MR536)
#define RR_DRV_SW_SEC_ROTPK_CHECK
#endif

#if defined(RR_PROJECT_VIVIAN) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_HAVE_NEW_LED_DIRVER
#endif

#if defined(RR_PROJECT_VERDELITE)
#define UART_API_HAVE_AW20XXX_LED_DRIVER
#endif

/* ReTread Mode */
#if defined(RR_PROJECT_TANOS) || defined(RR_PROJECT_RUBY) || defined(RR_PROJECT_RUBY2) || defined(RR_PROJECT_RUBYS) || \
	defined(RR_PROJECT_RUBYPLUS)
#else
#define UART_API_MCU_CAN_RST_INTO_RECOVERY
#endif

/* Energy Mode */
#if defined(RR_PROJECT_RUBY) || defined(RR_PROJECT_RUBY2) || defined(RR_PROJECT_RUBYS)
#else
#define UART_API_ENTER_ENERGY_MODE_BY_AP
#endif

/* platform */

#if defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_TANOS) || defined(RR_PROJECT_RUBYS)
#define BL_PARTITION_ABC_EN
#endif

/*
* UART_API_BL_SUPPORT_APP_SET_INVALID:
* set:
*	Watchdog(5 times retry) -> reboot(soft reboot) -> Watchdog(5 times retry) -> Watchdog(block & active hw dog) -> reboot(hw dog timeout reboot) -> part switch
* not:
*	Watchdog(5 times retry) -> reboot(soft reboot) -> Watchdog(5 times retry) -> reboot(soft reboot) -> Watchdog(block) -> reboot(hw dog timeout reboot)
*		-> Watchdog(1 times retry) -> reboot(soft reboot) -> Watchdog(block) -> reboot(hw dog timeout reboot)
*		-> Watchdog(1 times retry) -> reboot(soft reboot) -> Watchdog(block) -> reboot(hw dog timeout reboot) -> part switch
*/
#if defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || \
    defined(RR_PROJECT_TANOSS_MAX) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS)|| defined(RR_PROJECT_PEARL_PLUS) || \
    defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(UART_API_PLATFORM_SIGMASTAR_SSU9383C) || defined(UART_API_PLATFORM_HOBOT_X5)
#define UART_API_BL_SUPPORT_APP_SET_INVALID
#endif

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_BL_SUPPORT_BAIDU_DSP_TYPE
#endif

#define BOOTLOADER_FLAG_EFEX_STRINGS            "efex"
#define BOOTLOADER_FLAG_RECOVERY_STRINGS        "recovery"
#define BOOTLOADER_FLAG_RESTORE_STRINGS         "rstdft"
#define BOOTLOADER_FLAG_MISC_STRINGS            "rrmisc"
#define BOOTLOADER_FLAG_MAGIC                   "bootloader_message"

#define EMMC_SECTOR_SIZE                        (512)

#define BL_BASE_SIZE                            (600)      // Sectors
#define BL_COMMAND_SIZE                         (4)        // Sectors
#define BL_PARTITION_A_FLAG_SIZE                (4)        // Sectors
#define BL_PARTITION_B_FLAG_SIZE                (4)        // Sectors
#define BL_UPDATE_PROGRESS_FLAG_SIZE            (16)       // Sectors
#define BL_PARTITION_LAST_UPDATE_FLAG_SIZE      (4)        // Sectors
#define BL_PARTITION_CUR_FLAG_FLAG_SIZE         (4)        // Sectors
#define BL_PARTITION_FACTORY_FLAG_SIZE          (4)        // Sectors
#define BL_PARTITION_RETRY_BOOT_FLAG_SIZE       (4)        // Sectors
#define BL_PARTITION_RESTORE_DEFAULT_FLAG_SIZE  (4)        // Sectors
#define BL_PARTITION_RECOVERY_FLAG_SIZE         (4)        // Sectors
#define BL_PARTITION_RRMISC_FLAG_SIZE           (4)        // Sectors
#define BL_PARTITION_APPSET_INVALID_FLAG_SIZE   (4)        // Sectors
#define BL_PARTITION_BAIDU_DSP_TYPE_FLAG_SIZE   (4)        // Sectors

#define BL_PARTITION_COMMAND_OFFSET             (BL_BASE_SIZE)
#define BL_PARTITION_A_FLAG_OFFSET              (BL_PARTITION_COMMAND_OFFSET + BL_COMMAND_SIZE)
#define BL_PARTITION_B_FLAG_OFFSET              (BL_PARTITION_A_FLAG_SIZE + BL_PARTITION_A_FLAG_OFFSET)
#define BL_UPDATE_PROGRESS_FLAG_OFFSET          (BL_PARTITION_B_FLAG_SIZE + BL_PARTITION_B_FLAG_OFFSET)
#define BL_PARTITION_LAST_UPDATE_FLAG_OFFSET    (BL_UPDATE_PROGRESS_FLAG_SIZE + BL_UPDATE_PROGRESS_FLAG_OFFSET)
#define BL_PARTITION_CUR_FLAG_OFFSET            (BL_PARTITION_LAST_UPDATE_FLAG_SIZE + BL_PARTITION_LAST_UPDATE_FLAG_OFFSET)
#define BL_PARTITION_FACTORY_FLAG_OFFSET        (BL_PARTITION_CUR_FLAG_FLAG_SIZE + BL_PARTITION_CUR_FLAG_OFFSET)
#define BL_PARTITION_RETRY_BOOT_FLAG_OFFSET     (BL_PARTITION_FACTORY_FLAG_SIZE + BL_PARTITION_FACTORY_FLAG_OFFSET)
#define BL_PARTITION_RESTORE_DEFAULT_FLAG_OFFSET    (BL_PARTITION_RETRY_BOOT_FLAG_SIZE + BL_PARTITION_RETRY_BOOT_FLAG_OFFSET )
#define BL_PARTITION_RECOVERY_FLAG_OFFSET       (BL_PARTITION_RESTORE_DEFAULT_FLAG_SIZE + BL_PARTITION_RESTORE_DEFAULT_FLAG_OFFSET )

#if defined(BL_PARTITION_ABC_EN)
#undef BL_UPDATE_PROGRESS_FLAG_SIZE
#define BL_UPDATE_PROGRESS_FLAG_SIZE            (12)
/*
#undef BL_PARTITION_CUR_FLAG_OFFSET
#undef BL_PARTITION_FACTORY_FLAG_OFFSET
#undef BL_PARTITION_RETRY_BOOT_FLAG_OFFSET
*/
#undef BL_PARTITION_RESTORE_DEFAULT_FLAG_OFFSET
#define BL_PARTITION_RESTORE_DEFAULT_FLAG_OFFSET    (BL_UPDATE_PROGRESS_FLAG_SIZE + BL_UPDATE_PROGRESS_FLAG_OFFSET)
#define BL_PARTITION_RECOVERY_FLAG_OFFSET           (BL_PARTITION_RESTORE_DEFAULT_FLAG_SIZE + BL_PARTITION_RESTORE_DEFAULT_FLAG_OFFSET )
#endif

#define BL_PARTITION_RRMISC_FLAG_OFFSET             (BL_PARTITION_RECOVERY_FLAG_SIZE + BL_PARTITION_RECOVERY_FLAG_OFFSET)
#define BL_PARTITION_APPSET_INVALID_FLAG_OFFSET		(BL_PARTITION_RRMISC_FLAG_SIZE + BL_PARTITION_RRMISC_FLAG_OFFSET)
#define BL_PARTITION_BAIDU_DSP_TYPE_FLAG_OFFSET		(BL_PARTITION_APPSET_INVALID_FLAG_SIZE + BL_PARTITION_APPSET_INVALID_FLAG_OFFSET)

#define BL_PARTITION_CUR_FLAG_BOOT_A            0xf0
#define BL_PARTITION_CUR_FLAG_BOOT_B            0xf1

/* basic patition */
#define UART_API_PARTITION_DEFAULT_DIR          "/mnt/default"
#define UART_API_PARTITION_ROBOROCK_DIR         "/mnt/default/roborock"
#define UART_API_PARTITION_RESERVE_DIR          "/mnt/reserve"
#define UART_API_PARTITION_APP_DIR              "/opt/rockrobo"
#if defined(RR_PROJECT_RUBY2)
#define UART_API_PARTITION_DATA_DIR             "/data"
#else
#define UART_API_PARTITION_DATA_DIR             "/mnt/data"
#endif

/* boot flag part */
#if defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS)
#define UART_API_PARTITION_BOOTFLAG             "/dev/mmcblk0p5"
#elif defined(RR_PROJECT_TANOS_V)
#define UART_API_PARTITION_BOOTFLAG             "/dev/block/bootdevice/by-name/bootflag"
#elif defined(RR_PROJECT_RUBY2)
#define UART_API_PARTITION_BOOTFLAG             "/dev/disk/by-partlabel/bootflag"
#elif defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_RUBYS_C) || defined(RR_PROJECT_RUBYS_E) || defined(RR_PROJECT_TANOS_E) || \
	defined(RR_PROJECT_TANOS_S) || defined(RR_PROJECT_GARNET) || defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TANOSS_LITE) || \
    defined(RR_PROJECT_TANOSS_C) || defined(RR_PROJECT_TANOSS_E) || defined(RR_PROJECT_JADE) || \
    defined(RR_PROJECT_TOPAZS_POWER) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E)
#define UART_API_PARTITION_BOOTFLAG             "/dev/nanda"
#elif defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TOPAZ_SV_CV25) || \
    defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_MAX) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC)  || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)

#define UART_API_PARTITION_BOOTFLAG             "/dev/by-name/bootflag"
#endif

/* audio part */
#if defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS)
#define UART_API_PARTITION_SOUND_DIR            UART_API_PARTITION_APP_DIR"/resources/sounds"
#elif defined(RR_PROJECT_TANOS_V)
#define UART_API_PARTITION_SOUND_DIR            "/mnt/resource/sounds"
#elif defined(RR_PROJECT_RUBY2)
#else
#define UART_API_PARTITION_SOUND_DIR            "/mnt/resources"
#define UART_API_PARTITION_SOUND_BIT_DIR        "audio_bit"
#define UART_API_PARTITION_SOUND_DEFAULT_DIR    "audio_default"
#define UART_API_PARTITION_SOUND_CUSTOM_DIR     "audio_custom"
#if defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_RUBYS_C) || defined(RR_PROJECT_RUBYS_E) || defined(RR_PROJECT_TANOS_E) || \
	defined(RR_PROJECT_TANOS_S) || defined(RR_PROJECT_GARNET) || defined(RR_PROJECT_TOPAZ_S) || defined(RR_PROJECT_TANOSS_LITE) || \
    defined(RR_PROJECT_TANOSS_C) || defined(RR_PROJECT_TANOSS_E) || defined(RR_PROJECT_JADE) || \
    defined(RR_PROJECT_TOPAZS_POWER)
#define UART_API_PARTITION_SOUND_BIT_DEV        "/dev/nandh"
#define UART_API_PARTITION_SOUND_DEFAULT_DEV    "/dev/nandi"
#define UART_API_PARTITION_SOUND_CUSTOM_DEV     "/dev/nandj"
#define UART_API_PARTITION_SOUND_RECOVERY_DEV   "/dev/nandg"
#elif defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TOPAZ_SV_CV25) || \
    defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_MAX) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS)|| defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || \
    defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_PARTITION_SOUND_BIT_DEV        "/dev/by-name/audio_bit"
#define UART_API_PARTITION_SOUND_DEFAULT_DEV    "/dev/by-name/audio_default"
#define UART_API_PARTITION_SOUND_CUSTOM_DEV     "/dev/by-name/audio_custom"

#elif defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV)
#define UART_API_PARTITION_SOUND_BIT_DEV        "/dev/mmcblk0p5a"
#define UART_API_PARTITION_SOUND_DEFAULT_DEV    "/dev/mmcblk0p5a"
#define UART_API_PARTITION_SOUND_CUSTOM_DEV     "/dev/mmcblk0p5a"
#define UART_API_PARTITION_SOUND_RECOVERY_DEV   "/dev/mmcblk0p5a"
#else
#endif
#endif
#if defined(UART_API_PLATFORM_ALLWINNER_R16)
#define UART_API_PARTITION_SOUND_RECOVERY_DEV   "/dev/by-name/audio_recovery"
#elif defined(UART_API_PLATFORM_SIGMASTAR_SSU9383C)
#define UART_API_PARTITION_SOUND_RECOVERY_DEV   "/dev/by-name/misc"
#endif

#if defined(RR_PROJECT_R50)
#define RR_HW_ENABLE_ARM_JOINT
#define RR_HW_ENABLE_USB_CAMERA
#define UART_API_HAVE_TOF
#define UART_API_HAVE_TOF_NUM 2
#define RR_HW_ENABLE_ITOF_IRS2381
// #define RR_HW_ENABLE_AP_ARM_LED
#define RR_HW_ENABLE_AP_ARM_EMER_LED
#define UART_API_HAVE_CAMERA_EEPROM_SWP_WHOLE_ONLY
#define RR_DRV_HW_HAVE_ARM_BUMPER
#define RR_DRV_HW_HAVE_ARM_BUMPER_MCU
#define RR_DRV_HW_ARM_EMER
#define RR_DRV_HW_ARM_MCU_WDO
#endif

#if defined(RR_PROJECT_BUT)
#define RR_HW_ENABLE_ARM_JOINT
#define UART_API_KERNEL_DEVICE_ARM_JOINT_NAME   "/dev/ttyS3"
#endif



/* module, sounds dir */
#if defined(UART_API_PLATFORM_QCOM_APQ8053) //UART_API_PLATFORM_QCOM_APQ8053.....
/* /usr/lib/modules/3.18.71-perf/extra/  */
#define UART_API_KERNEL_MODULE_DIR_PRE          "/usr/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       "extra"

#define UART_API_KERNEL_MODULE_COMPASS_NAME     "compass"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/compass"
#define UART_API_KERNEL_MODULE_WIFI_NAME        "wlan"

#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyHS1"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyHS0"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000

#elif defined(UART_API_PLATFORM_RK_RK3326)
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""

#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS5"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyS1"

#elif defined(UART_API_PLATFORM_ALLWINNER_MR813)    //UART_API_PLATFORM_ALLWINNER_MR813....
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""

#define UART_API_KERNEL_MODULE_COMPASS_NAME     "compass"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/compass"
#if defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_TESSERACT)
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189es,ssv6x5x,bl602"
#else
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189fs,ssv6x5x,8189es"
#endif

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_BUT)
#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS1"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/null"
#else
#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS2"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/ttyS1"
#endif
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyS3"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000
#define UART_API_KERNEL_DEVICE_LINE_LASER_MODULE_NAME   "/dev/ttyS5"

#elif defined(UART_API_PLATFORM_JLQ_JA308)  //UART_API_PLATFORM_JLQ_JA308...

//for build,will be changed later.
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX    	""
#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS5"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyS3"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/ttyS4"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000
#define UART_API_KERNEL_DEVICE_LINE_LASER_MODULE_NAME   "/dev/ttyS5"

#if defined(UART_API_HAVE_COMPASS)
#define UART_API_KERNEL_MODULE_COMPASS_NAME     "st480"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/st480"
#endif
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189es,ssv6x5x"

#elif defined(UART_API_PLATFORM_AMBARELLA_CV25) //UART_API_PLATFORM_AMBARELLA_CV25...
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""

#define UART_API_KERNEL_MODULE_COMPASS_NAME     "compass"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/compass"
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189es"

#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS3"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyS1"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/ttyS2"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000

#elif defined(UART_API_PLATFORM_ALLWINNER_R16)  //UART_API_PLATFORM_ALLWINNER_R16...
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""
#define UART_API_ADBD_SERIAL_FILE               "/sys/class/android_usb/android0/iSerial"

#if defined(UART_API_HAVE_COMPASS)
#define UART_API_KERNEL_MODULE_COMPASS_NAME     "st480"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/st480"
#endif

#ifdef RR_SLIGHT_VGA
#define UART_API_KERNEL_MODULE_SC031IOT_NAME     "sc031iot"
#define UART_API_KERNEL_MODULE_VFE_V4L2_NAME     "vfe_v4l2"
#endif

#if defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_TANOS)
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189es"
#elif defined(RR_PROJECT_TANOS_E)
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189es,ssv6x5x"
#else
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189fs,ssv6x5x,hi3881"
#endif

#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS1"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyS2"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/ttyS3"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1152000

#elif defined(UART_API_PLATFORM_ALLWINNER_MR527)    //UART_API_PLATFORM_ALLWINNER_MR527...
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""

#define UART_API_KERNEL_MODULE_COMPASS_NAME     "compass"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/compass"

#if defined(RR_PROJECT_VERDELITE)
#define UART_API_KERNEL_MODULE_WIFI_NAME        "ssv6x5x,8189es,hi3881"
#else
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189fs,ssv6x5x,8189es,hi3881"
#endif

#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyAS7"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/null"
#if defined(RR_PROJECT_R50)
#define UART_API_KERNEL_DEVICE_WALL_SENSOR_NAME    "/dev/ttyAS3"
#elif defined(RR_PROJECT_VERDELITE)
#define UART_API_KERNEL_DEVICE_WALL_SENSOR_NAME    "/dev/ttyAS6"
#else
#define UART_API_KERNEL_DEVICE_WALL_SENSOR_NAME    "/dev/ttyAS1"
#endif
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyAS2"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000
#define UART_API_KERNEL_DEVICE_LINE_LASER_MODULE_NAME   "/dev/ttyAS1"
#if defined(RR_PROJECT_R50)
#define UART_API_KERNEL_DEVICE_ARM_JOINT_NAME   "/dev/ttyAS4"
#define UART_API_KERNEL_DEVICE_DOCK_NAME   "/dev/ttyAS6"
#else
#define UART_API_KERNEL_DEVICE_DOCK_NAME   "/dev/ttyAS4"
#endif
#define UART_API_KERNEL_DEVICE_ARM_WEIGHT_NAME   "/dev/ttyAS4"
#define UART_API_KERNEL_DEVICE_WEIGHT_BAUD         115200
#define UART_API_SWD_NEED_PERFORMANCE

#elif defined(UART_API_PLATFORM_ALLWINNER_MR536)
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""

#define UART_API_KERNEL_MODULE_COMPASS_NAME     "compass"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/compass"
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189fs,ssv6x5x,8189es,hi3881"

#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyAS3"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/null"
#define UART_API_KERNEL_DEVICE_WALL_SENSOR_NAME    "/dev/ttyAS1"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyAS2"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000
#define UART_API_KERNEL_DEVICE_LINE_LASER_MODULE_NAME   "/dev/ttyAS1"
#define UART_API_SWD_NEED_PERFORMANCE

#elif defined(UART_API_PLATFORM_SIGMASTAR_SSU9383C)
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
//#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""

#define UART_API_KERNEL_MODULE_COMPASS_NAME     "compass"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/compass"
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189fs,ssv6x5x,8189es,hi3881"

#if defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS8"
#else
#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS6"
#endif

#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/null"
#define UART_API_KERNEL_DEVICE_WALL_SENSOR_NAME    "/dev/ttyAS1"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyS9"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000
#define UART_API_KERNEL_DEVICE_LINE_LASER_MODULE_NAME   "/dev/ttyAS1"
#define UART_API_SWD_NEED_PERFORMANCE
#elif defined(UART_API_PLATFORM_HOBOT_X5)
#define UART_API_KERNEL_MODULE_DIR_PRE          "/lib/modules"
//#define UART_API_KERNEL_MODULE_DIR_HAS_KERNEL_VER
#define UART_API_KERNEL_MODULE_DIR_SUFFIX       ""

#define UART_API_KERNEL_MODULE_COMPASS_NAME     "compass"
#define UART_API_KERNEL_DEVICE_COMPASS_NAME     "/dev/compass"
#define UART_API_KERNEL_MODULE_WIFI_NAME        "8189fs,ssv6x5x,8189es,hi3881"
#define UART_API_KERNEL_DEVICE_LDS_NAME         "/dev/ttyS2"
#define UART_API_KERNEL_DEVICE_GPS_NAME         "/dev/ttyS5"
#define UART_API_KERNEL_DEVICE_CARPET_NAME      "/dev/null"
#define UART_API_KERNEL_DEVICE_WALL_SENSOR_NAME    "/dev/ttyS1"
#define UART_API_KERNEL_DEVICE_MCU_NAME         "/dev/ttyS7"
#define UART_API_KERNEL_DEVICE_MCU_BAUD         1500000
#define UART_API_KERNEL_DEVICE_LINE_LASER_MODULE_NAME   "/dev/ttyS6"
#define UART_API_SWD_NEED_PERFORMANCE

#else
#error FIXME: give me arch info

#endif

/* special file */
#define UART_API_KERNEL_DEVICE_MMAP_MCU_NAME    "/dev/uart_mcu"
#define UART_API_KERNEL_DEVICE_MMAP_LDS_NAME    "/dev/uart_lds"
#define UART_API_KERNEL_DEVICE_MMAP_GPS_NAME    "/dev/uart_gps"
#define UART_API_KERNEL_DEVICE_MMAP_WALL_SENSOR_NAME "/dev/uart_wall_sensor"
#define UART_API_KERNEL_DEVICE_MMAP_CARPET_NAME "/dev/uart_carpet"
#define UART_API_KERNEL_DEVICE_MMAP_LINE_LASER_MODULE_NAME  "/dev/uart_linelaser"
#define UART_API_KERNEL_DEVICE_MMAP_DOCK_NAME "/dev/uart_dock"
#define UART_API_OS_RELEASE_FILE                "/etc/rr-release"
#define UART_API_APP_BUILDNUMBER_FILE           UART_API_PARTITION_APP_DIR"/buildnumber"
#define UART_API_APP_RELEASE_FILE               UART_API_PARTITION_APP_DIR"/rr-release"
#define UART_API_RRLOG_DIR                      UART_API_PARTITION_DATA_DIR"/rockrobo/rrlog"
#define UART_API_NOUPLOAD_DIR                   UART_API_PARTITION_DATA_DIR"/rockrobo/noupload"
#define UART_API_LOG_DIR                        UART_API_RRLOG_DIR
#define BLACK_BOX_FILE1                         UART_API_PARTITION_RESERVE_DIR"/blackbox.db"
#define BLACK_BOX_FILE2                         UART_API_PARTITION_RESERVE_DIR"/rrBkBox.csv"
#define ANONYMOUSID_FILE                        UART_API_PARTITION_RESERVE_DIR"/anonymousid"
#define COOKER_FILE                             UART_API_PARTITION_RESERVE_DIR"/baoji.txt"
#define COOKER_MODE_FILE                        UART_API_PARTITION_DATA_DIR"/rockrobo/cooker_reservation.txt"
#define COOKER_MODE_FILE_TMP                    "/tmp/cooker_reservation.txt"
#define NOISE_MODE_FILE                         UART_API_PARTITION_DATA_DIR"/rockrobo/noise_mode_cfg.txt"
#define AP_CFG_PARA_FILE                        UART_API_PARTITION_DATA_DIR"/rockrobo/uartapi_cfg_para.txt"

#if defined(UART_API_HAVE_COMPASS)
#ifdef UART_API_HAVE_COMPASS_2
#define UART_API_KERNEL_MODULE_COMPASS2_NAME    UART_API_KERNEL_MODULE_COMPASS_NAME"_2"
#define UART_API_KERNEL_DEVICE_COMPASS2_NAME    UART_API_KERNEL_DEVICE_COMPASS_NAME"_2"
#endif
#endif

#define UART_API_HAVE_BUSYBOX


#if defined(RR_PROJECT_TANOS_V) || defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYS) || defined(RR_PROJECT_TANOS) || \
    defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_TANOSS_PLUS) || defined(RR_PROJECT_AMBER_E) || defined(RR_PROJECT_TOPAZ_SV_CV25) || \
    defined(RR_PROJECT_TOPAZ_SV) || defined(RR_PROJECT_TANOS_SV) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_TANOSS_MAX) || \
    defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || \
    defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_USE_PARTITION_EMMC
#else
#define UART_API_PARTITION_USE_NAND
#endif


// old project keep it's setting, new project do not
#if defined(RR_PROJECT_RUBYPLUS) || defined(RR_PROJECT_RUBYSLITE) || defined(RR_PROJECT_RUBYS_C) || defined(RR_PROJECT_RUBYS_E) || \
	defined(RR_PROJECT_RUBYS)
#define UART_API_AUTO_SET_NICE
#endif

#if defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003) || \
    defined(RR_PROJECT_R50) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || \
    defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_SELF_CALIBRATION_MODE
#if defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || \
    defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_SELF_CLIFF_CALIBRATION_MODE
#endif
#if defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_B10003) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_PEARL_E) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_SELF_CAMERA_CALIBRATION_MODE
#endif
#if defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_SELF_LDS_CALIBRATION_MODE
#endif
#if defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || \
    defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_ULTRON_SV) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || \
    defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_SELF_ACC_CALIBRATION_MODE
#endif
#if defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_TESSERACT)
#define UART_API_HAVE_SELF_TOF_CALIBRATION_MODE
#define UART_API_HAVE_AFTER_SALE_TOF_SELF_CALIBRATION_MODE
#define UART_API_HAVE_AFTER_SALE_MOUSE_SELF_CALIBRATION_MODE
#endif
#endif


//Choose one mcu.bin from 3*2 mcu.bins when swd/ota/upgrade
#if defined(RR_PROJECT_TANOS_S)
#define UART_API_GYRO_3_BINS_UPGRADE
#endif


#define UART_API_HAVE_BMI323      //for FacCaliInfo_st have member i16GyroOffGain[6]

#define UART_API_HAVE_GYRO_ODO_COM_ST   //for have GyroOdoCom_st and delete ts in GyroOdo_st

/* cpufreq */
#if defined(UART_API_PLATFORM_ALLWINNER_MR813) || defined(UART_API_PLATFORM_ALLWINNER_MR527) || defined(UART_API_PLATFORM_ALLWINNER_MR536)
#define UART_API_PLATFORM_CPU_FREQ_PREFIX           "/sys/devices/system/cpu/cpu"
#define UART_API_PLATFORM_CPU_FREQ_CUR_SUFFIX       "/cpufreq/cpuinfo_cur_freq"
#define UART_API_PLATFORM_CPU_FREQ_MIN_SUFFIX       "/cpufreq/cpuinfo_min_freq"
#define UART_API_PLATFORM_CPU_FREQ_MAX_SUFFIX       "/cpufreq/cpuinfo_max_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MIN_SUFFIX   "/cpufreq/scaling_min_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MAX_SUFFIX   "/cpufreq/scaling_max_freq"
#define UART_API_PLATFORM_CPU_FREQ_AVAILABLE_SUFFIX "/cpufreq/scaling_available_frequencies"
#define UART_API_PLATFORM_THERMAL_NODE_PREFIX       "/sys/devices/virtual/thermal/thermal_zone"
#define UART_API_PLATFORM_THERMAL_NODE_SUFFIX       "/temp"
#define UART_API_PLATFORM_CPU_THERMAL_NODE          "/sys/devices/virtual/thermal/thermal_zone0/temp"
#define CPU_TEMP_TO_DEGREES_CENTIGRADE(temp)        (temp/1000.0)
#elif defined(UART_API_PLATFORM_AMBARELLA_CV25)
#define UART_API_PLATFORM_CPU_FREQ_CAN_NOT_CHANGE
#elif defined(UART_API_PLATFORM_JLQ_JA308)
#define UART_API_PLATFORM_CPU_FREQ_PREFIX           "/sys/devices/system/cpu/cpu"
#define UART_API_PLATFORM_CPU_FREQ_CUR_SUFFIX       "/cpufreq/cpuinfo_cur_freq"
#define UART_API_PLATFORM_CPU_FREQ_MIN_SUFFIX       "/cpufreq/cpuinfo_min_freq"
#define UART_API_PLATFORM_CPU_FREQ_MAX_SUFFIX       "/cpufreq/cpuinfo_max_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MIN_SUFFIX   "/cpufreq/scaling_min_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MAX_SUFFIX   "/cpufreq/scaling_max_freq"
#define UART_API_PLATFORM_THERMAL_NODE_PREFIX       "/sys/devices/virtual/thermal/thermal_zone"
#define UART_API_PLATFORM_THERMAL_NODE_SUFFIX       "/temp"
#define UART_API_PLATFORM_CPU_THERMAL_NODE          "/sys/devices/virtual/thermal/thermal_zone5/temp"
#define CPU_TEMP_TO_DEGREES_CENTIGRADE(temp)        (temp)
#elif defined(UART_API_PLATFORM_ALLWINNER_R16)
#define UART_API_PLATFORM_CPU_FREQ_PREFIX           "/sys/devices/system/cpu/cpu"
#define UART_API_PLATFORM_CPU_FREQ_CUR_SUFFIX       "/cpufreq/cpuinfo_cur_freq"
#define UART_API_PLATFORM_CPU_FREQ_MIN_SUFFIX       "/cpufreq/cpuinfo_min_freq"
#define UART_API_PLATFORM_CPU_FREQ_MAX_SUFFIX       "/cpufreq/cpuinfo_max_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MIN_SUFFIX   "/cpufreq/scaling_min_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MAX_SUFFIX   "/cpufreq/scaling_max_freq"
#define UART_API_PLATFORM_THERMAL_NODE_PREFIX       "/sys/devices/virtual/thermal/thermal_zone"
#define UART_API_PLATFORM_THERMAL_NODE_SUFFIX       "/temp"
#define UART_API_PLATFORM_CPU_THERMAL_NODE          "/sys/devices/virtual/thermal/thermal_zone0/temp"
#define CPU_TEMP_TO_DEGREES_CENTIGRADE(temp)        (temp)
#elif defined(UART_API_PLATFORM_SIGMASTAR_SSU9383C)
#define UART_API_PLATFORM_CPU_FREQ_PREFIX           "/sys/devices/system/cpu/cpu"
#define UART_API_PLATFORM_CPU_FREQ_CUR_SUFFIX       "/cpufreq/cpuinfo_cur_freq"
#define UART_API_PLATFORM_CPU_FREQ_MIN_SUFFIX       "/cpufreq/cpuinfo_min_freq"
#define UART_API_PLATFORM_CPU_FREQ_MAX_SUFFIX       "/cpufreq/cpuinfo_max_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MIN_SUFFIX   "/cpufreq/scaling_min_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MAX_SUFFIX   "/cpufreq/scaling_max_freq"
#define UART_API_PLATFORM_CPU_FREQ_AVAILABLE_SUFFIX "/cpufreq/scaling_available_frequencies"
#define UART_API_PLATFORM_CPU_THERMAL_NODE          "/sys/devices/system/cpu/cpufreq/temp_out"
#define CPU_TEMP_TO_DEGREES_CENTIGRADE(temp)        (temp)
#elif defined(UART_API_PLATFORM_HOBOT_X5)
#define UART_API_PLATFORM_CPU_FREQ_PREFIX           "/sys/devices/system/cpu/cpu"
#define UART_API_PLATFORM_CPU_FREQ_CUR_SUFFIX       "/cpufreq/cpuinfo_cur_freq"
#define UART_API_PLATFORM_CPU_FREQ_MIN_SUFFIX       "/cpufreq/cpuinfo_min_freq"
#define UART_API_PLATFORM_CPU_FREQ_MAX_SUFFIX       "/cpufreq/cpuinfo_max_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MIN_SUFFIX   "/cpufreq/scaling_min_freq"
#define UART_API_PLATFORM_CPU_SET_FREQ_MAX_SUFFIX   "/cpufreq/scaling_max_freq"
#define UART_API_PLATFORM_CPU_FREQ_AVAILABLE_SUFFIX "/cpufreq/scaling_available_frequencies"
#define UART_API_PLATFORM_THERMAL_NODE_PREFIX       "/sys/devices/virtual/thermal/thermal_zone"
#define UART_API_PLATFORM_THERMAL_NODE_SUFFIX       "/temp"
#define UART_API_PLATFORM_CPU_THERMAL_NODE          "/sys/devices/virtual/thermal/thermal_zone0/temp"
#define CPU_TEMP_TO_DEGREES_CENTIGRADE(temp)        (temp/1000.0)
#endif

/* wifi led */
#if defined(UART_API_PLATFORM_JLQ_JA308)
#define WIFI_LED_DEV_PATH "/sys/bus/platform/devices/0.soc:rr_wifi_leds/rrleds"
#else
#define WIFI_LED_DEV_PATH "/sys/bus/platform/devices/rr_leds/rrleds"
#endif
#if defined(RR_PROJECT_TANOSS_E) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_VIVIAN_C)
#define UART_API_WIFI_LED_NEAR_START_KEY
#endif
/* wifi led end */

/* descreate board */
#if defined(UART_API_PLATFORM_JLQ_JA308)
#define UART_API_BOARD_HAS_DESCRETE_VERSION
#define UART_API_BOARD_DESCRETE_NODE          "/proc/cmdline"
#define UART_API_BOARD_DESCRETE_STR           "board=descrete"
#endif
/* descreate board */

/* rr secure start*/
#if defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_ULTRON_E) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E)
#define UART_API_HAVE_RR_WHEEL_SECURE_POLICY
#endif /* rr secure end */


#if defined(RR_PROJECT_TANOSS_MAX) || defined(UART_API_PLATFORM_JLQ_JA308) || defined(RR_PROJECT_TOPAZS_PLUS) || defined(RR_PROJECT_ULTRON) || \
    defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003)
#define UART_API_PLATFORM_CAMERA_THERMAL_NODE "/proc/rockrobo/ntc"
#define UART_API_COOKER_CAMERA_THERMAL_FILE   UART_API_PARTITION_DATA_DIR"/cooker_temp"
#elif defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
      defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || defined(RR_PROJECT_PEARL_S) || \
      defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_BUT)
#define UART_API_PLATFORM_CAMERA_THERMAL_MCU_NTC
#define UART_API_COOKER_CAMERA_THERMAL_FILE   UART_API_PARTITION_DATA_DIR"/cooker_temp"
#elif defined(RR_PROJECT_TOPAZ_SC)
#define UART_API_PLATFORM_CAMERA_THERMAL_NODE_WITH_MCU_NTC "/proc/rockrobo/ntc"
#define UART_API_COOKER_CAMERA_THERMAL_FILE   UART_API_PARTITION_DATA_DIR"/cooker_temp"
#endif

/* scure feature */
#define UART_API_SECURE_FEATURE_ENABLE


/* enable wifi support dual interface coexist and wifi dock pair */
#if defined(RR_PROJECT_ULTRON_SPLUS) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_ENABLE_COUPLE_PAIR) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_B10003)
#define UART_API_WIFI_FEATURE_DUAL_INTERFACE
#define UART_API_WIFI_FEATURE_DOCK_PAIR
/*enable ota pkg combine*/
#define UART_API_OTA_FEATURE_COMBINE_PKG
#endif

/* enable wifi start adapter, disable wifi_start.sh */
#define UART_API_WIFI_START_ADAPTER

/* disable wifi dongle HT40, keep HT20 mode */
#if defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E)
#define UART_API_WIFI_DISABLE_HT40_MODE
#endif

/* external storage */
#if defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define UART_API_HAVE_EXSTORAGE
#define UART_API_EXSTORAGE_EXT4_PATH    "/dev/mmcblk0"
#define UART_API_EXSTORAGE_CHECK        "/run/sd_check"
#endif

/* slight kernel */
#if defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_TANOS_SLITEPLUS) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E)
#define UART_API_HAVE_SLIGHT_KERNEL
#endif

#if defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_CORAL) || \
    defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_C) || \
    defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define UART_API_HAVE_NEW_MENU_AFTER_AUTOBIT
#endif

#ifndef RR_PROJECT_TESSERACT
#define RR_DRV_HW_HAVE_FAN
#define RR_DRV_HW_HAVE_DROP
#endif
#if defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VIVIAN_F)
#define UART_API_FAN_PA_ENABLE  15000   //15000 pa
#elif defined(RR_PROJECT_VIVIAN) || defined(RR_VIRTUAL_PROJECT_C91)
#define UART_API_FAN_PA_ENABLE  12000   //12000 pa
#elif defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CXXXX) || defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || \
      defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_PEARL_PLUSC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_B10003) || \
      defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || \
      defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_FAN_PA_ENABLE  10000   //10000 pa
#elif defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_PEARL_E)
#define UART_API_FAN_PA_ENABLE  7000   //7000 pa
#elif defined(RR_PROJECT_ULTRON) || defined(RR_PROJECT_ULTRON_SPLUS)
#define UART_API_FAN_PA_ENABLE  6000   //6000 pa
#elif defined(RR_PROJECT_TOPAZ_SC) || defined(RR_PROJECT_PEARL) || defined(RR_PROJECT_ULTRON_LITE) || defined(RR_PROJECT_ULTRON_E) || defined(RR_PROJECT_TANOS_SLITEPLUS)
#define UART_API_FAN_PA_ENABLE  5500    //real 5500pa
#else
#define UART_API_FAN_PA_ENABLE  2700
#endif

#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CXXXX) || \
    defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_CORAL_PRO) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_B00002) || defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_VIVIAN_F) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_VIVIAN_SC) || \
    defined(RR_PROJECT_BUT)
#define UART_API_FAN_BIT_DUTY 31
#else
#define UART_API_FAN_BIT_DUTY 50
#endif

/* power for stretch brush motor, dock_bumper, dustbox_det, lds_bumper. when need set power to 0, need this macro. */
#if defined(RR_PROJECT_PEARL_PLUS) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_SET_CLDO3_POWER
#endif

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_BERYL) || \
    defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_B10003) || defined(RR_PROJECT_R50) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_B00002) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_STRETCH_SWEEP_POS_DET
#endif

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_PEARL_PLUSC) || \
    defined(RR_PROJECT_PEARL_C) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_B10003) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_PEARL_E) || \
    defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_QIUNIU_LDS
#endif

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_ULTRON_SC) || defined(RR_PROJECT_BERYL) || defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_PROJECT_B10003) || defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC) || defined(RR_PROJECT_BUT)
#define UART_API_HAVE_STRETCH_SWEEP_RETRY_POLICY
#endif

#if defined(RR_PROJECT_CORAL) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_VERDELITE) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
    #define UART_API_HAVE_AP_BRAKE_DET
#endif

#if defined(RR_PROJECT_CORAL_PRO)
#define UART_API_HAVE_AP_MOP_POWER
#endif

#if defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_VIRTUAL_PROJECT_C91) || \
    defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S)
    #define UART_API_HAVE_STEERING_MODULE
    #define RR_DRV_SW_SELF_STEERING_CALIBRATION_MODE
#endif

#if defined(RR_PROJECT_VIVIAN_SC)
#define RR_DRV_HW_ONLY_UNIVERSAL_STEERING_MODULE
#endif

#if defined(RR_PROJECT_VIVIAN) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50) || \
    defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || \
    defined(RR_PROJECT_VIVIAN_SC)
    #define UART_API_HAVE_CLIFF_TOF_MODULE
#endif

#if defined(RR_PROJECT_TESSERACT)
#define RR_DRV_HW_HAVE_NO_SWEEP
#endif

#if defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_R50) || defined(RR_PROJECT_TESSERACT)
#define UART_API_HAVE_AP_MOTOR_SYSTEM

#ifndef RR_PROJECT_TESSERACT
#define RR_DRV_HW_HAVE_SWEEP
#define UART_API_HAVE_AP_SWEEP_STRETCH_LIFT_MOTOR
#define UART_API_HAVE_AP_STRETCH_SWEEP_DET
#define UART_API_COEFF_SWEEP_STRETCH_STRETCH_LIFT_MOTOR 0.266335f //(1.8v/4096)/1.1/1.5
#endif

#if defined(RR_PROJECT_VERDELITE)
#define UART_API_HAVE_AP_LDS_LIFT_MOTOR
#define UART_API_HAVE_AP_LDS_LIFT_DET
#define UART_API_HAVE_AP_SIDEMOP_LIFT_MOTOR
#define UART_API_HAVE_AP_SIDEMOP_DET
#define UART_API_COEFF_SIDEMOP_LIFT_MOTOR 0.266335f //(1800/4096)/1.1/1.5
#endif

#if defined(RR_PROJECT_R50)
#define UART_API_HAVE_AP_ARM_DOOR_MOTOR
#define UART_API_HAVE_AP_ARM_DOOR_DET
#define UART_API_HAVE_AP_SWEEP
#define UART_API_HAVE_AP_WHEEL_DET
#define UART_API_HAVE_AP_STEERING_MODULE
#define UART_API_HAVE_STEERING_MODULE
//#define UART_API_HAVE_AP_BACKUNIVERSAL_MOTOR
//#define UART_API_HAVE_AP_BACKUNIVERSAL_WHEEL_DET
#define RR_DRV_SW_SELF_STEERING_CALIBRATION_MODE
#define UART_API_HAVE_AP_CABINDOOR_MOTOR
#define UART_API_HAVE_AP_CABINDOOR_DET
#define UART_API_HAVE_AP_CABINDOOR_ONLY_OPEN_DET
#define RR_DRV_HW_CPU_FAN
/* TOP DTOF start */
// #define UART_API_HAVE_AP_TOP_DTOF
// #define RR_DRV_SW_HAVE_AP_TOP_DTOF_4
// #define RR_DRV_HW_DTOF_VI530X
/* TOP DTOF end */
#endif

#if defined(RR_PROJECT_TESSERACT)
/* TOP DTOF start */
#define UART_API_HAVE_AP_TOP_DTOF
#define RR_DRV_SW_HAVE_AP_DTOF_CLIFF
#define RR_DRV_HW_DTOF_VI530X
/* TOP DTOF end */
#endif

#if !defined(UART_API_PLATFORM_ALLWINNER_R16)
#define RR_DRV_SW_HAVE_STRESSAPPTEST
#endif

#endif

#if defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VIVIAN_F)
#define UART_API_HAVE_CAMSENSE_VIDAR
#endif

#if defined(RR_VIRTUAL_PROJECT_C91) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_TESSERACT) || \
    defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
#define RR_DRV_SW_ODO_TIMESTAMP
#endif

#if defined(RR_PROJECT_PEARL_E) || defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define RR_DRV_SW_CAMERA_LASERCAM
#endif

#if defined(RR_PROJECT_PEARL_E)
#define UART_API_CAMSENSE_LASERCAM_UARTPORT "/dev/ttyS3"
#endif

#if defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define UART_API_CAMSENSE_LASERCAM_UARTPORT "/dev/ttyS5"
#define RR_DRV_HW_MEM_LOW_VAL 128
#endif

#if defined(RR_PROJECT_VERDELITE)
/* TOP DTOF start */
#define UART_API_HAVE_AP_TOP_DTOF
#define RR_DRV_HW_DTOF_VI530X
/* TOP DTOF end */
#define RR_DRV_SW_BLUETOOTH
#endif

#if defined(RR_PROJECT_VIVIAN_F) || defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
/* TOP DTOF start */
#define UART_API_HAVE_AP_TOP_DTOF
#define RR_DRV_HW_DTOF_VI530X
#define RR_DRV_HW_DTOF_DA0301B1
/* TOP DTOF end */
#endif

#if defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
#define UART_API_HAVE_AP_LDS_LIFT_MOTOR
#define UART_API_HAVE_AP_LDS_LIFT_DET
#define UART_API_HAVE_AP_MOTOR_SYSTEM
#endif

#if defined(RR_PROJECT_VIVIAN_S) || defined(RR_PROJECT_VIVIAN_SC)
#define RR_DRV_HW_LDS_GIVEN_BAUDRATE   230400
#endif

#if defined(RR_PROJECT_VERDELITE)
#define RR_DRV_SW_AW20072_LED
#endif

#define UART_API_HAVE_RRTN
#define UART_API_RRTN_PATH  "/mnt/reserve/rrtn"

#ifdef ADAPT_QIUNIU_LDS_OLD_VERSION
#define UART_API_HAVE_QIUNIU_LDS_OLD_VERSION
#endif

#if defined(RR_PROJECT_ULTRON_SV) || defined(RR_PROJECT_VERDELITE) || defined(RR_PROJECT_VIVIAN) || \
    defined(RR_PROJECT_PEARL_PLUSS) || defined(RR_PROJECT_CORAL_PRO) || defined(RR_PROJECT_B10003) || \
    defined(RR_PROJECT_PEARL_S) || defined(RR_PROJECT_TESSERACT) || defined(RR_PROJECT_R50) || \
    defined(RR_PROJECT_VIVIAN_C) || defined(RR_PROJECT_BUT)
#define RR_DRV_SW_WPA3_IPV6
#endif

#if defined(RR_PROJECT_TESSERACT)
#define RR_DRV_HW_HAVE_NO_SWEEP
#define UART_API_HAVE_BAROMETER
#define UART_API_HAVE_AP_CABINDOOR_MOTOR
#define UART_API_HAVE_AP_CABINDOOR_DET
#define UART_API_HAVE_AP_CLAMP_MOTOR
#define UART_API_HAVE_AP_CLAMP_DET
#define RR_DRV_SW_USB_RNDIS
#define UART_API_HAVE_AP_WEIGHT
#define UART_API_HAVE_FRONT_SWING
#define UART_API_HAVE_BACK_SWING
#endif


#if defined(RR_PROJECT_VIVIAN_C)
#define UART_API_HAVE_AP_MOTOR_SYSTEM
#define UART_API_HAVE_AP_RAG_STRETCH_MOTOR
#define UART_API_HAVE_AP_RAG_STRETCH_DET
#endif

#if defined(RR_PROJECT_PEARL_E_RISCV) || defined(RR_PROJECT_PEARL_EPRO)
#define UART_API_HAVE_NO_FAN_ID
#endif
//#define UART_TEST_SUPPORT_ENERGY_MODE
//#define UART_TEST_SUPPORT_ENERGY_MODE_AP_ALIVE_FOR_DEBUG
//#define UART_API_SAVE_LOG_FOR_DEBUG
//#define UART_API_ENABLE_PRINTF_FOR_DEBUG
//#define UART_API_ALLOW_LOGIN_DEBUG

#if defined(RR_PROJECT_BUT)
#define RR_DRV_HW_GPS
#endif
#endif /* __UART_API_CONFIG_H__ */
//
