# creat lib link

## 创建lib目录的软连接

```shell
# 根据实际路径，将所需的第三方库的include+lib目录生成软连接
ln -s ~/Work/uart_api-Butchart/opt/include/ ./3rd_party/inc/roborock
ln -s ~/Work/uart_api-Butchart/opt/rockrobo/cleaner/lib/ ./3rd_party/lib/roborock
```
