# 指定交叉编译器
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 交叉编译工具链路径
set(TOOLCHAIN_PATH /path/to/cross-compiler)

# 指定交叉编译器
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/bin/arm-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/bin/arm-linux-gnueabi-g++)
