/* =============================================================================
#     FileName: product_version_define.h
#         Desc:
#       Author: lijie
#        Email: lijie@roborock.com
#     HomePage:
#      Version: 0.0.1
#   LastChange: 2016-02-23 14:57:28
#      History:
============================================================================= */
#ifndef __PRODUCT_VERSION_DEFINE_H__
#define __PRODUCT_VERSION_DEFINE_H__

//Company name
#define COMPANY_STR                   "RR"

//Project
#define KEYWORD_PROJECT               "Project"
#define KEYWORD_PROJECT_VALUE_RUBY    "RUBY"
#define PROJECT_RUBY                  0x01

//Arch
#define KEYWORD_ARCH                  "ARCH"
#define KEYWORD_ARCH_VALUE_STM32      "STM32"
#define ARCH_STM32                    0x01

//Develpprocess or HardwareVersion
#define KEYWORD_DPS                   "DevelpProcess"
#define KEYWORD_DPS_VALUE_MOCKUP      "MOCKUP"
#define KEYWORD_DPS_VALUE_EVT         "EVT"
#define KEYWORD_DPS_VALUE_DVT         "DVT"
#define KEYWORD_DPS_VALUE_PVT         "PVT"
#define KEYWORD_DPS_VALUE_MP          "MP"
#define DPS_MASK_TYPE                 0xF0
#define DPS_MASK_NUM                  0x0F
#define DPS_MOCKUP                    0x30
#define DPS_EVT                       0x60
#define DPS_DVT                       0x90
#define DPS_PVT                       0xB0
#define DPS_MP                        0xE0

//Version
#define KEYWORD_VERMAJOR   "VersionMajor"
#define KEYWORD_VERMINOR   "VersionMinor"
#define KEYWORD_VERBUILD   "VersionBuild"

//Buidtype
#define KEYWORD_BUILDTYPE  "BuidType"
#define KEYWORD_BUILDTYPE_VALUE_RELEASE "RELEASE"
#define BUILDTYPE_RELEASE   0x1
#define KEYWORD_BUILDTYPE_VALUE_DEBUG   "DEBUG"
#define BUILDTYPE_DEBUG     0x0

//HardwareItem
#define KEYWORD_HARDWARE   "Hardware"





#endif


