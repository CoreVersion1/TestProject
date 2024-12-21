cmake_minimum_required(VERSION 3.15)

# 项目信息
project(MyProject VERSION 1.0 LANGUAGES CXX)

option(USE_CROSS_COMPILE "Use cross-compiled compiler" OFF)
if(USE_CROSS_COMPILE)
  include(cmake/arm-cross-toolchain.cmake)
endif()

# 添加编译选项
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加include路径、源码子目录
include_directories(inc)
# add_subdirectory(src)
add_subdirectory(app)
