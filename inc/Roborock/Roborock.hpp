#include "roborock.symlink/rda_headers.h"

#pragma once

namespace TestProject {
void print_Sensor_u(const int &id, const Sensor_u &sensor);
void print_McuGyroOdo_st(const int &id, const McuGyroOdo_st &mcu_info);
void print_McuSensor_st(const int &id, const McuSensor_st &mcu_sensor);
void print_McuKey_st(const int &id, const McuKey_st &mcu_key);
void print_McuState_st(const int &id, const McuState_st &mcu_state);
void print_Key_st(const int &id, const Key_st &key);

}  // namespace TestProject
