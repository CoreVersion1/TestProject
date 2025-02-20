#include "Common/TimeImpl.hpp"

#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace TestProject {

int64_t TimeImpl::Now()
{
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

std::string TimeImpl::NowStr()
{
  using namespace std::chrono;
  auto now             = system_clock::now();
  std::time_t now_time = system_clock::to_time_t(now);
  std::tm tm           = *std::localtime(&now_time);

  std::stringstream ss;
  ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
  return ss.str();
}

void TimeImpl::SetTimeRecord(int64_t time_ms)
{
  last_time_ = time_ms;
}

int64_t TimeImpl::GetTimeRecord()
{
  return last_time_;
}

void TimeImpl::ClearTimeRecord()
{
  last_time_ = 0;
}

float TimeImpl::GetFreq(int64_t last_time_ms, int64_t now_time_ms)
{
  if (now_time_ms <= last_time_ms)
  {
    throw std::invalid_argument("Current time must be greater than last time.");
  }

  // Frequency in Hz (1 / time difference in seconds)
  return 1000.0f / (now_time_ms - last_time_ms);
}

float TimeImpl::GetFreq(int64_t now_time_ms)
{
  auto last_time_ms = last_time_;
  last_time_        = now_time_ms;
  return GetFreq(last_time_ms, now_time_ms);
}

float TimeImpl::GetFreq()
{
  int64_t now_time_ms = Now();
  return GetFreq(now_time_ms);
}

std::string TimeImpl::GetFreqStr(int64_t last_time_ms, int64_t now_time_ms)
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << GetFreq(last_time_ms, now_time_ms) << "Hz";
  return oss.str();
}

std::string TimeImpl::GetFreqStr(int64_t time_ms)
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << GetFreq(time_ms) << "Hz";
  return oss.str();
}

std::string TimeImpl::GetFreqStr()
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << GetFreq() << "Hz";
  return oss.str();
}
}  // namespace TestProject
