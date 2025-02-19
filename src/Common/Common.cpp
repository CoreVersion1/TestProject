#include "Common/Common.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace TestProject {

long long GetTimestampMs(void)
{
  auto now = std::chrono::system_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
}

void PrintTimestamp()
{
  // 获取当前时间点
  auto now = std::chrono::system_clock::now();

  // 转换为 time_t 类型以获得秒级时间
  std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

  // 转换为毫秒
  auto duration = now.time_since_epoch();
  auto millis   = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() % 1000;

  // 格式化输出时间戳
  std::cout << std::put_time(std::localtime(&now_time_t), "%Y-%m-%d %H:%M:%S") << "."
            << std::setfill('0') << std::setw(3) << millis << std::endl;
}

std::string HexToString(const void* data, size_t size)
{
  std::stringstream ss;
  for (size_t i = 0; i < size; i++)
  {
    ss << std::uppercase << std::hex << std::setfill('0') << std::setw(2)
       << static_cast<uint32_t>(static_cast<const uint8_t*>(data)[i]) << " ";
  }

  return ss.str();
}

}  // namespace TestProject
