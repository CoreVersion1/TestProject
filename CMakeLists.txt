cmake_minimum_required(VERSION 3.15)

# 静态链接外部库
option(STATIC_LINK "Static links to external libraries" ON)
if(STATIC_LINK)
  message(STATUS "INFO: STATIC_LINK = " ${STATIC_LINK})

  # 全局设置静态链接，体积会很大
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

option(USE_CROSS_COMPILE "Use cross-compiled compiler" OFF)
if(USE_CROSS_COMPILE)
  message(STATUS "INFO: USE_CROSS_COMPILE = " ${USE_CROSS_COMPILE})
  include(cmake/arm-cross-toolchain.cmake)
endif()

# 项目信息
project(TestProject VERSION 1.0 LANGUAGES CXX)

# 添加编译选项
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加include路径
include_directories(inc)
include_directories(3rd_party/inc)
# 添加源码子目录
add_subdirectory(src)
add_subdirectory(app)
