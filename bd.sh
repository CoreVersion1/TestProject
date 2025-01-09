#!/bin/bash

# 判断是否为CMake项目的目录
if [ -f "CMakeLists.txt" ]; then
  mkdir -p ./build 
else
  echo "error, invalid CMake project path"
  exit 1
fi

# 判断是否输入参数
if [ "$#" -eq 0 ]; then
  # 没有参数时执行普通的编译命令
  cmake -B ./build -S . && cmake --build ./build -j
elif [ "$1" == "cross" ]; then
  # 输入参数为"cross"时执行交叉编译命令
  cmake -B ./build -S . -DCMAKE_TOOLCHAIN_FILE=./cmake/arm-cross-toolchain.cmake && cmake --build ./build -j
elif [ "$1" == "clean" ]; then
  # 输入参数为"clean"时清空build目录
  rm -rf ./build/*
  echo "Build directory cleaned."
  exit 0
elif [ "$1" == "-h" ]; then
  echo "Usage: $0 [cross|clean]"
  exit 0
else
  echo "invalid argument: $1"
  echo "Usage: $0 [cross|clean]"
  exit 1
fi

ls ./build/src ./build/app ./build/test
