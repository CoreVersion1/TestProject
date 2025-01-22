#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

#include "Common/Common.hpp"
#include "roborock/rda_headers.h"

using namespace TestProject;

const int kTryCnt = 300;
const int kGetCnt = 50;
const int kBuffSize = 4096;

void print_McuGyroOdo_st(const McuGyroOdo_st &mcu_info) {
  std::ostringstream oss;

  // 输出时间戳
  oss << "info McuGyroOdo_st: " << __func__ << std::endl
      << "time_stamp = " << mcu_info.time_stamp << std::endl;

  // 输出加速度
  oss << "acc =";
  for (int i = 0; i < 3; ++i) {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.acc[i];
  }
  oss << std::endl;

  // 输出陀螺仪
  oss << "gyro =";
  for (int i = 0; i < 3; ++i) {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.gyro[i];
  }
  oss << std::endl;

  // 输出四元数
  oss << "quat =";
  for (int i = 0; i < 4; ++i) {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.quat[i];
  }
  oss << std::endl;

  // // 输出轮速
  // oss << "wheel = " << mcu_info.wheel[0] << ", " << mcu_info.wheel[1] <<
  // "\n";

  // // 输出里程计
  // oss << "odo = " << mcu_info.odo[0] << ", " << mcu_info.odo[1] <<std::endl;

  // 打印结果
  std::cout << oss.str() << std::endl;
}

void print_McuSensor_st(const McuSensor_st &mcu_sensor) {
  std::ostringstream oss;

  oss << "info McuSensor_st: " << __func__ << std::endl
      << "emergent_stop = " << mcu_sensor.emergent_stop << std::endl
      << "bumper_left = " << mcu_sensor.bumper_left << std::endl
      << "bumper_right = " << mcu_sensor.bumper_right << std::endl
      << "lift_left = " << mcu_sensor.lift_left << std::endl
      << "lift_right = " << mcu_sensor.lift_right << std::endl
      << "pose_tilt = " << mcu_sensor.pose_tilt << std::endl
      << "pose_flip = " << mcu_sensor.pose_flip << std::endl
      << "env_grass = " << mcu_sensor.env_grass << std::endl
      << "env_rain = " << mcu_sensor.env_rain << std::endl
      << "resv = " << mcu_sensor.resv << std::endl;

  std::cout << oss.str() << std::endl;
}

void print_McuKey_st(const McuKey_st &mcu_key) {
  std::ostringstream oss;

  oss << "info McuKey_st: " << __func__ << std::endl
      << "key = " << static_cast<uint32_t>(mcu_key.key) << std::endl
      << std::endl;

  std::cout << oss.str() << std::endl;
}

void print_McuState_st(const McuState_st &mcu_state) {
  std::ostringstream oss;

  oss << "info McuState_st: " << __func__ << std::endl
      << "state = " << mcu_state.state << std::endl
      << "battery_percent = "
      << static_cast<uint32_t>(mcu_state.battery_percent) << std::endl
      << "error = " << mcu_state.error << std::endl;

  std::cout << oss.str() << std::endl;
}

int main() {
  auto ret = init_uart();
  if (ret != 0) {
    std::cout << "init_uart failed" << std::endl;
    return -1;
  }

#if RR_DRV_HW_SERIAL_HALFDUPLEX
  // 半双工，需要启动线程，用于循环请求数据
  ret = rua_start_request_rs485();
  if (ret != 0) {
    std::cout << "rua_start_request_rs485 failed" << std::endl;
    return -1;
  }
#endif

  clean_uart();
  std::this_thread::sleep_for(std::chrono::seconds(1));

  char read_buff[kBuffSize] = {0};
  int j = 0;

  auto time_start = get_time_now_ms();
  for (int try_idx = 0, get_idx = 0; (try_idx < kTryCnt) && (get_idx < kGetCnt);
       try_idx++) {
    ret = get_package(read_buff, sizeof(read_buff));
    if (ret <= 0) {
      std::cout << "get_package fail, try_idx = " << try_idx + 1 << "/"
                << kTryCnt << ", get_idx = " << get_idx << std::endl;
      std::this_thread::sleep_for(std::chrono::microseconds(1));
      continue;
    }

    std::printf("%s:got package, size=%d\n", __func__, ret);
    char *src = read_buff;
    char *structp = nullptr;
    int struct_size = 0;

    while ((j = get_next(&src, &ret, &structp, &struct_size)) > 0) {
      if ((j == RPT_MCU_POSE_MOTOR_ID) &&
          (struct_size <= sizeof(McuGyroOdo_st))) {

        McuGyroOdo_st mcu_info = {0};
        memcpy(&mcu_info, structp, struct_size);

        auto time_now = get_time_now_ms();
        auto frq = (1 * 1000.0) / (time_now - time_start);
        time_start = time_now;
        std::printf("%s:Found response, ID=0x%x, size=%d, try_cnt=%d, "
                    "get_index=%d, frq=%.2fHz\n",
                    __func__, j, struct_size, try_idx, get_idx++, frq);

        print_time_stamp();
        print_McuGyroOdo_st(mcu_info);
        break;
      } else if (j == RPT_MCU_SENSOR_ID &&
                 struct_size <= sizeof(McuSensor_st)) {
        McuSensor_st mcu_sensor = {};
        memcpy(&mcu_sensor, structp, struct_size);
        print_McuSensor_st(mcu_sensor);
      } else if (j == RPT_MCU_KEY_ID && struct_size <= sizeof(McuKey_st)) {
        McuKey_st mcu_key = {};
        memcpy(&mcu_key, structp, struct_size);
        print_McuKey_st(mcu_key);
      } else if (j == RPT_MCU_STATE_ID && struct_size <= sizeof(McuState_st)) {
        McuState_st mcu_state = {};
        memcpy(&mcu_state, structp, struct_size);
        print_McuState_st(mcu_state);
      }

      continue;
    }
  }

#if RR_DRV_HW_SERIAL_HALFDUPLEX
  rua_stop_request_rs485();
#endif

  return 0;
}
