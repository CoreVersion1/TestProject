#!/bin/sh
set -e

# 检查参数
if [ $# -ne 1 ]; then
  echo "Usage: $0 gpio_num"
  exit 1
fi

# 清理函数
cleanup() {
    if [ -n "$GPIO" ]; then
        echo $GPIO > /sys/class/gpio/unexport 2>/dev/null || true
    fi
}

# 捕获退出信号（EXIT、INT、TERM）并执行清理函数
trap cleanup EXIT INT TERM

gpio_test(){
    GPIO=$1
    echo $GPIO > /sys/class/gpio/export
    echo out > /sys/class/gpio/gpio${GPIO}/direction 
    for i in $(seq 1 3)
    do
    echo 0 > /sys/class/gpio/gpio${GPIO}/value
    sleep 1
    echo 1 > /sys/class/gpio/gpio${GPIO}/value
    sleep 1
    done
    echo $GPIO > /sys/class/gpio/unexport
}

gpio_test $1
