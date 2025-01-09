# TestProject

测试工程，基于CMake、C/C++编写，用于测试功能

## 可选的编译选项

| 选项                  | 可选项 | 默认值 | 选项说明           |
| --------------------- | ------ | ------ | ------------------ |
| <b> USE_CROSS_COMPILE | ON/OFF | ON     | 是否使用交叉编译   |
| <b> STATIC_LINK       | ON/OFF | OFF    | 是否静态链接外部库 |

## 开始编译

```shell
# 编译
bd.sh

# 交叉编译
bd.sh cross

# 清理编译目录
bd.sh clean
```
