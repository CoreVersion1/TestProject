#include <stdio.h>
#include <string>

#pragma once

namespace TestProject {

long long GetTimestampMs(void);
void PrintTimestamp();
std::string HexToString(const void* data, size_t size);
}  // namespace TestProject
