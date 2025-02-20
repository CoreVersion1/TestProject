#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <functional>

#include "Common/Common.hpp"
#include "roborock.symlink/rda_headers.h"
#include "Roborock/Roborock.hpp"
#include "Common/TimeImpl.hpp"

namespace TestProject {

std::string IdToStr(const int &id, const std::string &name)
{
  std::ostringstream oss;
  oss << "id = 0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(4) << id
      << std::dec << ", " << name;
  return oss.str();
}

template <>
void PrintProtocolData(const int &id, const Key_st &key)
{
  static TimeImpl time_impl{};
  std::ostringstream oss;

  oss << "[info] " << IdToStr(id, "Key_st") << ", freq = " << time_impl.GetFreqStr()
      << ": b6Val = " << static_cast<uint32_t>(key.b6Val)
      << ", b2Index = " << static_cast<uint32_t>(key.b2Index) << std::endl;

  std::cout << oss.str() << std::endl;
}

template <>
void PrintProtocolData(const int &id, const Bat_st &bat)
{
  static TimeImpl time_impl{};
  std::ostringstream oss;

  oss << "[info] " << IdToStr(id, "Bat_st") << ", freq = " << time_impl.GetFreqStr()
      << ": u16VolVal = " << static_cast<uint32_t>(bat.u16VolVal)
      << ", u16IVal = " << static_cast<uint32_t>(bat.u16IVal)
      << ", u8Soc = " << static_cast<uint32_t>(bat.u8Soc)
      << ", u8ChrgStatus = " << static_cast<uint32_t>(bat.u8ChrgStatus)
      << ", u8VolStatus = " << static_cast<uint32_t>(bat.u8VolStatus)
      << ", u8TmpStatus = " << static_cast<uint32_t>(bat.u8TmpStatus)
      << ", u8CurrStatus = " << static_cast<uint32_t>(bat.u8CurrStatus)
      << ", u8ChgTempStatus = " << static_cast<uint32_t>(bat.u8ChgTempStatus) << std::endl;

  std::cout << oss.str() << std::endl;
}

template <>
void PrintProtocolData(const int &id, const BatCap_st &bat_cap)
{
  static TimeImpl time_impl{};
  std::ostringstream oss;

  oss << "[info] " << IdToStr(id, "BatCap_st") << ", freq = " << time_impl.GetFreqStr()
      << ": u8Capx100mAh = " << static_cast<uint32_t>(bat_cap.u8Capx100mAh)
      << ", reserved = " << static_cast<uint32_t>(bat_cap.reserved) << std::endl;

  std::cout << oss.str() << std::endl;
}

template <>
void PrintProtocolData(const int &id, const Sensor_u &sensor)
{
  static TimeImpl time_impl{};
  std::ostringstream oss;

  oss << "[info] " << IdToStr(id, "Key_st") << ", freq = " << time_impl.GetFreqStr()
      << ", Sensor_u: "
      << "u16Val = " << static_cast<uint32_t>(sensor.u16Val) << std::endl;

  std::cout << oss.str() << std::endl;
}

template <>
void PrintProtocolData(const int &id, const McuGyroOdo_st &mcu_info)
{
  static TimeImpl time_impl{};
  static TimeImpl time_impl_mcu{};
  std::ostringstream oss;

  // 输出时间戳
  oss << "[info] " << IdToStr(id, "McuGyroOdo_st") << ", freq = " << time_impl.GetFreqStr()
      << ", freq_mcu = " << time_impl_mcu.GetFreqStr(mcu_info.time_stamp)
      << ": time_stamp = " << mcu_info.time_stamp;

  // 输出加速度
  oss << ", acc = [";
  for (int i = 0; i < 3; ++i)
  {
    oss << std::fixed << std::setprecision(4) << mcu_info.acc[i] << ",";
  }
  oss << "]";

  // 输出陀螺仪
  oss << ", gyro = [";
  for (int i = 0; i < 3; ++i)
  {
    oss << std::fixed << std::setprecision(4) << mcu_info.gyro[i] << ",";
  }
  oss << "]";

  // 输出四元数
  oss << ", quat = [";
  for (int i = 0; i < 4; ++i)
  {
    oss << std::fixed << std::setprecision(4) << mcu_info.quat[i] << ",";
  }
  oss << "]";

  // 打印结果
  std::cout << oss.str() << std::endl;
}

template <>
void PrintProtocolData(const int &id, const McuSensor_st &mcu_sensor)
{
  static TimeImpl time_impl{};
  std::ostringstream oss;

  oss << "[info] " << IdToStr(id, "McuSensor_st") << ", freq = " << time_impl.GetFreqStr()
      << ": cut_state = "
      << ", pose_tilt = " << mcu_sensor.pose_tilt << ", pose_flip = " << mcu_sensor.pose_flip
      << ", env_grass = " << mcu_sensor.env_grass << ", env_rain = " << mcu_sensor.env_rain
      << ", resv = " << mcu_sensor.resv << std::endl;

  std::cout << oss.str() << std::endl;
}

template <>
void PrintProtocolData(const int &id, const McuKey_st &mcu_key)
{
  static TimeImpl time_impl{};
  std::ostringstream oss;

  oss << "[info] " << IdToStr(id, "McuKey_st") << ", freq = " << time_impl.GetFreqStr()
      << ": key = " << static_cast<uint32_t>(mcu_key.key) << std::endl;

  std::cout << oss.str() << std::endl;
}

template <>
void PrintProtocolData(const int &id, const McuState_st &mcu_state)
{
  static TimeImpl time_impl{};
  std::ostringstream oss;

  oss << "[info] " << IdToStr(id, "McuState_st") << ", freq = " << time_impl.GetFreqStr()
      << ": state = " << mcu_state.state << ", error = " << mcu_state.error << std::endl;

  std::cout << oss.str() << std::endl;
}

void HandleProtocolData(int id, const void *data, size_t size)
{
  static std::unordered_map<int, std::function<void()>> handler_map = {
      {RPT_KEY_ID, [&]() { ProcessPackage<Key_st>(id, data, size); }},
      {RPT_BATTERY_INFO_ID, [&]() { ProcessPackage<Bat_st>(id, data, size); }},
      {RPT_BAT_CAP_ID, [&]() { ProcessPackage<BatCap_st>(id, data, size); }},
      {RPT_STATUS_BUMPER_ID, [&]() { ProcessPackage<Sensor_u>(id, data, size); }},
      {RPT_STATUS_DROP_ID, [&]() { ProcessPackage<Sensor_u>(id, data, size); }},
      {RPT_MCU_POSE_MOTOR_ID, [&]() { ProcessPackage<McuGyroOdo_st>(id, data, size); }},
      {RPT_MCU_SENSOR_ID, [&]() { ProcessPackage<McuSensor_st>(id, data, size); }},
      {RPT_MCU_KEY_ID, [&]() { ProcessPackage<McuKey_st>(id, data, size); }},
      {RPT_MCU_STATE_ID, [&]() { ProcessPackage<McuState_st>(id, data, size); }},
  };

  // 查找并执行处理函数
  auto it = handler_map.find(id);
  if (it != handler_map.end())
  {
    it->second();  // 调用相应的处理函数
  }
  else
  {
    std::cout << "[warn] unknown ID = 0x" << std::uppercase << std::hex << id << std::dec
              << std::endl;
  }
}

}  // namespace TestProject
