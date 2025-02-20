#include <stdio.h>
#include <string>
#include <sstream>
#include <iomanip>

#pragma once

namespace TestProject {

int64_t GetTimestampMs(void);
std::string FormatTimestamp(const int64_t& time_ms);
void PrintTimestamp();
std::string HexToStr(const void* data, size_t size);

template <typename T>
std::string ArrToStr(const T* arr, int size, const std::string& name)
{
  std::ostringstream oss;
  oss << name << " = {";

  for (int i = 0; i < size; ++i)
  {
    if constexpr (std::is_same_v<T, char>)
    {
      oss << "'" << arr[i] << "'";
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
      oss << std::fixed << std::setprecision(4) << arr[i];
    }
    else
    {
      oss << arr[i];
    }

    if (i < size - 1)
    {
      oss << ", ";
    }
  }
  oss << "}";
  return oss.str();
}

}  // namespace TestProject
