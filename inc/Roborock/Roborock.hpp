#include "roborock.symlink/rda_headers.h"
#include <iostream>
#include <string>

#pragma once

namespace TestProject {

/**
 * @brief 打印协议ID+结构体名称
 *
 * @param id
 * @param name
 * @return std::string
 */
std::string PrintID(const int &id, const std::string &name);

/**
 * @brief 打印协议数据
 *
 * @tparam T
 * @param id
 * @param data
 */
template <typename T>
void PrintProtocolData(const int &id, const T &data);

/**
 * @brief 处理协议数据包
 *
 * @tparam T
 * @param id
 * @param structp
 * @param struct_size
 */
template <typename T>
void ProcessPackage(int id, const void *structp, size_t struct_size)
{
  if (struct_size == sizeof(T))
  {
    T data = {};
    memcpy(&data, structp, struct_size);
    PrintProtocolData(id, data);
  }
  else
  {
    using std::literals::operator""s;
    std::cout << "[error] " << PrintID(id, "unknown"s) << ": wrong size! data_size = " << struct_size
              << " --> target_size = " << sizeof(T) << std::endl;
  }
}

/**
 * @brief 处理协议数据
 *
 * @param id
 * @param data
 * @param size
 */
void HandleProtocolData(int id, const void *data, size_t size);

}  // namespace TestProject
