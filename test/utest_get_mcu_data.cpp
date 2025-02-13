#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

#include "Common/Common.hpp"
#include "roborock.symlink/rda_headers.h"
#include "Roborock/Roborock.hpp"

using namespace TestProject;

const int kTryCnt   = 300;
const int kGetCnt   = 50;
const int kBuffSize = 4096;

int main(int argc, char *argv[])
{
  bool loop_mode = false;

  // Parse command-line arguments
  for (int i = 1; i < argc; ++i)
  {
    std::string arg = argv[i];
    if (arg == "-l")
    {
      loop_mode = true;
    }
  }

  auto ret = init_uart();
  if (ret != 0)
  {
    std::cout << "init_uart failed" << std::endl;
    return -1;
  }

#if RR_DRV_HW_SERIAL_HALFDUPLEX
  // 半双工，需要启动线程，用于循环请求数据
  ret = rua_start_request_rs485();
  if (ret != 0)
  {
    std::cout << "rua_start_request_rs485 failed" << std::endl;
    return -1;
  }
#endif

  clean_uart();
  std::this_thread::sleep_for(std::chrono::seconds(1));

  char read_buff[kBuffSize] = {0};
  int j                     = 0;

  auto time_start = get_time_now_ms();
  for (int try_idx = 0, get_idx = 0; loop_mode || (try_idx < kTryCnt) && (get_idx < kGetCnt);
       try_idx++)
  {
    ret = get_package(read_buff, sizeof(read_buff));
    if (ret <= 0)
    {
      std::cout << "get_package fail, try_idx = " << try_idx + 1 << "/" << kTryCnt
                << ", get_idx = " << get_idx << std::endl;
      std::this_thread::sleep_for(std::chrono::microseconds(1));
      continue;
    }

    std::printf("%s:got package, size=%d\n", __func__, ret);
    char *src       = read_buff;
    char *structp   = nullptr;
    int struct_size = 0;

    while ((j = get_next(&src, &ret, &structp, &struct_size)) > 0)
    {
      if ((j == RPT_STATUS_BUMPER_ID) && struct_size <= sizeof(Sensor_u))
      {
        Sensor_u sensor = {};
        memcpy(&sensor, structp, struct_size);
        print_Sensor_u(j, sensor);
      }
      else if ((j == RPT_STATUS_DROP_ID) && struct_size <= sizeof(Sensor_u))
      {
        Sensor_u sensor = {};
        memcpy(&sensor, structp, struct_size);
        print_Sensor_u(j, sensor);
      }
      else if ((j == RPT_MCU_POSE_MOTOR_ID) && (struct_size <= sizeof(McuGyroOdo_st)))
      {
        McuGyroOdo_st mcu_info = {0};
        memcpy(&mcu_info, structp, struct_size);

        auto time_now = get_time_now_ms();
        auto frq      = (1 * 1000.0) / (time_now - time_start);
        time_start    = time_now;
        std::printf(
            "%s:Found response, ID=0x%x, size=%d, try_cnt=%d, "
            "get_index=%d, frq=%.2fHz\n",
            __func__, j, struct_size, try_idx, get_idx++, frq);

        print_time_stamp();
        print_McuGyroOdo_st(j, mcu_info);
        break;
      }
      else if (j == RPT_MCU_SENSOR_ID && struct_size <= sizeof(McuSensor_st))
      {
        McuSensor_st mcu_sensor = {};
        memcpy(&mcu_sensor, structp, struct_size);
        print_McuSensor_st(j, mcu_sensor);
      }
      else if (j == RPT_MCU_KEY_ID && struct_size <= sizeof(McuKey_st))
      {
        McuKey_st mcu_key = {};
        memcpy(&mcu_key, structp, struct_size);
        print_McuKey_st(j, mcu_key);
      }
      else if (j == RPT_MCU_STATE_ID && struct_size <= sizeof(McuState_st))
      {
        McuState_st mcu_state = {};
        memcpy(&mcu_state, structp, struct_size);
        print_McuState_st(j, mcu_state);
      }
      else if ((j == RPT_KEY_ID) && (struct_size <= sizeof(Key_st)))
      {
        Key_st key = {};
        memcpy(&key, structp, struct_size);
        print_Key_st(j, key);
      }
      else
      {
        std::cout << "[warn] unrecognized ID=" << std::showbase << std::uppercase << std::hex << j
                  << std::endl;
      }
    }
  }

#if RR_DRV_HW_SERIAL_HALFDUPLEX
  rua_stop_request_rs485();
#endif

  return 0;
}
