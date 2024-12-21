# 设置交叉编译的操作系统和架构
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 设置交叉编译工具链的路径
set(CMAKE_C_COMPILER /opt/toolchain/aarch64-mr527-linux-gnu/bin/aarch64-mr527-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /opt/toolchain/aarch64-mr527-linux-gnu/bin/aarch64-mr527-linux-gnu-g++)

# 设置目标平台的 sysroot（可选，如果有的话）
set(CMAKE_SYSROOT /opt/toolchain/aarch64-mr527-linux-gnu/aarch64-mr527-linux-gnu/sysroot/)

# 设置交叉编译工具链的查找路径
set(CMAKE_FIND_ROOT_PATH /opt/toolchain/aarch64-mr527-linux-gnu)

# 设置查找程序、库和头文件时的查找模式
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
