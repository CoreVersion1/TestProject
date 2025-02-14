#include "roborock.symlink/rda_headers.h"

#pragma once

namespace TestProject {
void PrintProtocolData(const int &id, const Sensor_u &sensor);
void PrintProtocolData(const int &id, const McuGyroOdo_st &mcu_info);
void PrintProtocolData(const int &id, const McuSensor_st &mcu_sensor);
void PrintProtocolData(const int &id, const McuKey_st &mcu_key);
void PrintProtocolData(const int &id, const McuState_st &mcu_state);
void PrintProtocolData(const int &id, const Key_st &key);

}  // namespace TestProject
