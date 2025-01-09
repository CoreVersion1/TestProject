cmake_minimum_required(VERSION 3.15)

# 静态链接外部库
option(STATIC_LINK "Static links to external libraries" ON)
if(STATIC_LINK)
  message(STATUS "INFO: STATIC_LINK = " ${STATIC_LINK})

  # 全局设置静态链接，体积会很大
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

# 项目信息
project(TestProject VERSION 1.0 LANGUAGES CXX)

# 添加编译选项
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加include路径
include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/third_party/inc)
# 添加源码子目录
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)
