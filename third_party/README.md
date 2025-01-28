# creat lib link

## 创建lib目录的软连接

```shell
# 根据实际路径，将所需的第三方库的include+lib目录生成软连接
ln -s ~/Work/Butchart-uart_api/opt/include/ ./third_party/inc/roborock.symlink
ln -s ~/Work/Butchart-uart_api/opt/rockrobo/cleaner/lib/ ./third_party/libs/roborock.symlink
```
