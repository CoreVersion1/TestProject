cmake_minimum_required(VERSION 3.15)

# 项目信息
project(MyProject VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 开启跨平台构建选项
if(CMAKE_TOOLCHAIN_FILE)
    message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
endif()

# 指定可执行文件的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 源文件
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# 添加可执行文件
add_executable(MyExecutable ${SOURCES})

# # 指定外部库路径
# set(EXTERNAL_LIBS_DIR "${CMAKE_SOURCE_DIR}/libs")
# set(EXTERNAL_LIBS "${EXTERNAL_LIBS_DIR}/external_lib.so")

# # 链接外部库
# target_link_libraries(MyExecutable PRIVATE ${EXTERNAL_LIBS})

# # 包含头文件路径
# target_include_directories(MyExecutable PRIVATE ${SRC_DIR})
