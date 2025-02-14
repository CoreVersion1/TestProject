#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

#include "Common/Common.hpp"
#include "roborock.symlink/rda_headers.h"

namespace TestProject {

std::string PrintID(const int &id, const std::string &name)
{
  std::ostringstream oss;
  oss << "id = 0x" << std::hex << std::setfill('0') << std::setw(2) << id << std::oct << ", "
      << name;
  return oss.str();
}

void PrintProtocolData(const int &id, const Sensor_u &sensor)
{
  std::ostringstream oss;

  oss << "info " << PrintID(id, "Key_st") << ", Sensor_u: "
      << "u16Val = " << static_cast<uint32_t>(sensor.u16Val) << std::endl;

  std::cout << oss.str() << std::endl;
}

void PrintProtocolData(const int &id, const McuGyroOdo_st &mcu_info)
{
  std::ostringstream oss;

  // 输出时间戳
  oss << "info " << PrintID(id, "McuGyroOdo_st") << ": time_stamp = " << mcu_info.time_stamp
      << std::endl;

  // 输出加速度
  oss << "acc =";
  for (int i = 0; i < 3; ++i)
  {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.acc[i];
  }
  oss << std::endl;

  // 输出陀螺仪
  oss << "gyro =";
  for (int i = 0; i < 3; ++i)
  {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.gyro[i];
  }
  oss << std::endl;

  // 输出四元数
  oss << "quat =";
  for (int i = 0; i < 4; ++i)
  {
    oss << " " << std::fixed << std::setprecision(4) << mcu_info.quat[i];
  }
  oss << std::endl;

  // 打印结果
  std::cout << oss.str() << std::endl;
}

void PrintProtocolData(const int &id, const McuSensor_st &mcu_sensor)
{
  std::ostringstream oss;

  oss << "info " << PrintID(id, "McuSensor_st") << ": emergent_stop = " << mcu_sensor.emergent_stop
      << ", bumper_left = " << mcu_sensor.bumper_left
      << ", bumper_right = " << mcu_sensor.bumper_right << ", lift_left = " << mcu_sensor.lift_left
      << ", lift_right = " << mcu_sensor.lift_right << ", pose_tilt = " << mcu_sensor.pose_tilt
      << ", pose_flip = " << mcu_sensor.pose_flip << ", env_grass = " << mcu_sensor.env_grass
      << ", env_rain = " << mcu_sensor.env_rain << ", resv = " << mcu_sensor.resv << std::endl;

  std::cout << oss.str() << std::endl;
}

void PrintProtocolData(const int &id, const McuKey_st &mcu_key)
{
  std::ostringstream oss;

  oss << "info " << PrintID(id, "McuKey_st") << ": key = " << static_cast<uint32_t>(mcu_key.key)
      << std::endl;

  std::cout << oss.str() << std::endl;
}

void PrintProtocolData(const int &id, const McuState_st &mcu_state)
{
  std::ostringstream oss;

  oss << "info " << PrintID(id, "McuState_st") << ": state = " << mcu_state.state
      << ", battery_percent = " << static_cast<uint32_t>(mcu_state.battery_percent)
      << ", error = " << mcu_state.error << std::endl;

  std::cout << oss.str() << std::endl;
}

void PrintProtocolData(const int &id, const Key_st &key)
{
  std::ostringstream oss;

  oss << "info " << PrintID(id, "Key_st") << ": b6Val = " << static_cast<uint32_t>(key.b6Val)
      << ", b2Index = " << static_cast<uint32_t>(key.b2Index) << std::endl;

  std::cout << oss.str() << std::endl;
}

}  // namespace TestProject
