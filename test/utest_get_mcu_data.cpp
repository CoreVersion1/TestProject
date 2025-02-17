#include <iostream>
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
  int id                    = 0;

  auto time_start = GetTimestampMs();
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
    char *src     = read_buff;
    char *data    = nullptr;
    int data_size = 0;

    while ((id = get_next(&src, &ret, &data, &data_size)) > 0)
    {
      HandleProtocolData(id, data, data_size);

      // 计算频率
      if ((id == RPT_MCU_POSE_MOTOR_ID) && (data_size <= sizeof(McuGyroOdo_st)))
      {
        auto time_now = GetTimestampMs();
        auto frq      = (1 * 1000.0) / (time_now - time_start);
        time_start    = time_now;
        std::printf(
            "Found response, ID=0x%x, size=%d, try_cnt=%d, "
            "get_index=%d, frq=%.2fHz\n",
            id, data_size, try_idx, get_idx++, frq);

        PrintTimestamp();
      }
    }
  }

#if RR_DRV_HW_SERIAL_HALFDUPLEX
  rua_stop_request_rs485();
#endif

  return 0;
}
