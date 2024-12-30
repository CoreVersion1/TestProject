#include <chrono>
#include <iostream>
#include <thread>

#include "roborock/rda_headers.h"

const int kBuffSize = 4096;

int main() {
  auto ret = init_uart();
  if (ret != 0) {
    std::cout << "init_uart failed" << std::endl;
    return -1;
  }

  ret = rua_start_request_rs485();
  if (ret != 0) {
    std::cout << "rua_start_request_rs485 failed" << std::endl;
    return -1;
  }

  clean_uart();
  std::this_thread::sleep_for(std::chrono::seconds(1));

  McuGyroOdo_st mcu_info = {0};
  char read_buff[kBuffSize] = {0};
  int j = 0;

  for (int i = 0; i < 100; i++) {
    ret = get_package(read_buff, sizeof(read_buff));
    if (ret <= 0) {
      continue;
    }

    std::printf("%s:got package, size=%d\n", __func__, ret);
    char *src = read_buff;
    char *structp = nullptr;
    int struct_size = 0;

    while ((j = get_next(&src, &ret, &structp, &struct_size)) > 0) {
      if (j == RPT_MOTOR_MCU_ID) {
        if (struct_size <= sizeof(McuGyroOdo_st)) {
          memcpy(&mcu_info, structp, struct_size);
          std::printf("%s:Found response, ID=0x%x, size=%d\n", __func__, j,
                      struct_size);

          std::printf(
              "info McuGyroOdo_st: %s\n, time_stamp = %d\n, acc = %f, %f, "
              "%f\n gyro "
              "= %f, %f, %f\n quat = %f, %f, %f\n wheel = %d, %d\n odo = "
              "%f, %f\n",
              __func__, mcu_info.time_stamp, mcu_info.acc[0], mcu_info.acc[1],
              mcu_info.acc[2], mcu_info.gyro[0], mcu_info.gyro[1],
              mcu_info.gyro[2], mcu_info.quat[0], mcu_info.quat[1],
              mcu_info.quat[2], mcu_info.wheel[0], mcu_info.wheel[1],
              mcu_info.odo[0], mcu_info.odo[1]);
          break;
        }
      }

      continue;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(10));
  }
  rua_stop_request_rs485();

  return 0;
}
