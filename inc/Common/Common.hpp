#include <stdio.h>
#include <string>

#pragma once

namespace TestProject {

int64_t GetTimestampMs(void);
std::string FormatTimestamp(const int64_t& time_ms);
void PrintTimestamp();
std::string HexToString(const void* data, size_t size);
}  // namespace TestProject
