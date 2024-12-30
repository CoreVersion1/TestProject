# TestProject

测试工程，基于CMake、C/C++编写，用于测试功能

## 可选的编译选项

| 选项                  | 可选项 | 默认值 | 选项说明           |
| --------------------- | ------ | ------ | ------------------ |
| <b> USE_CROSS_COMPILE | ON/OFF | ON     | 是否使用交叉编译   |
| <b> STATIC_LINK       | ON/OFF | OFF    | 是否静态链接外部库 |

## 开始编译

```shell
# 在代码根目录建立build目录，后面的命令默认都在该路径下执行
mkdir -p ./build && cd ./build

# CMake + 编译
cmake .. && cmake --build . -j

# CMake + 交叉编译
cmake -DUSE_CROSS_COMPILE=ON .. && cmake --build . -j
```
