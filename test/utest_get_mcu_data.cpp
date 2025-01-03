#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>

#include "roborock/rda_headers.h"
#include "Common/Common.hpp"

using namespace TestProject;

const int kTryCnt = 100;
const int kBuffSize = 4096;

void print_mcu_info(const McuGyroOdo_st &mcu_info) {
  std::ostringstream oss;

  // 输出时间戳
  oss << "info McuGyroOdo_st: " << __func__ << "\n"
      << "time_stamp = " << mcu_info.time_stamp << "\n";

  // 输出加速度
  oss << "acc =";
  for (int i = 0; i < 3; ++i) {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.acc[i];
  }
  oss << "\n";

  // 输出陀螺仪
  oss << "gyro =";
  for (int i = 0; i < 3; ++i) {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.gyro[i];
  }
  oss << "\n";

  // 输出四元数
  oss << "quat =";
  for (int i = 0; i < 3; ++i) {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.quat[i];
  }
  oss << "\n";

  // 输出轮速
  oss << "wheel = " << mcu_info.wheel[0] << ", " << mcu_info.wheel[1] << "\n";

  // 输出里程计
  oss << "odo = " << mcu_info.odo[0] << ", " << mcu_info.odo[1] << "\n";

  // 打印结果
  std::cout << oss.str() << std::endl;
}

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

  for (int i = 0; i < kTryCnt; i++) {
    ret = get_package(read_buff, sizeof(read_buff));
    if (ret <= 0) {
      continue;
    }

    std::printf("%s:got package, size=%d\n", __func__, ret);
    char *src = read_buff;
    char *structp = nullptr;
    int struct_size = 0;

    while ((j = get_next(&src, &ret, &structp, &struct_size)) > 0) {
      if ((j == RPT_MOTOR_MCU_ID) && (struct_size <= sizeof(McuGyroOdo_st))) {
        memcpy(&mcu_info, structp, struct_size);
        std::printf("%s:Found response, ID=0x%x, size=%d\n", __func__, j,
                    struct_size);

        print_time_stamp();
        print_mcu_info(mcu_info);
        break;
      }

      continue;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(10));
  }
  rua_stop_request_rs485();

  return 0;
}
