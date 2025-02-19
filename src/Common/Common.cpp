#include "Common/Common.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace TestProject {

int64_t GetTimestampMs(void)
{
  auto now = std::chrono::system_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
}

std::string FormatTimestamp(const int64_t& time_ms)
{
  // 将毫秒数转换为秒和毫秒
  std::time_t seconds = time_ms / 1000;
  int millis          = time_ms % 1000;

  // 将秒转换为本地时间
  std::tm local_time = *std::localtime(&seconds);

  // 格式化输出时间戳
  std::ostringstream oss;
  oss << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S") << "." << std::setfill('0') << std::setw(3)
      << millis;

  return oss.str();
}

void PrintTimestamp()
{
  // 格式化输出时间戳
  std::cout << FormatTimestamp(GetTimestampMs()) << std::endl;
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
