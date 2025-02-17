#include "roborock.symlink/rda_headers.h"
#include <iostream>

#pragma once

namespace TestProject {

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
 * @param j 
 * @param structp 
 * @param struct_size 
 */
template <typename T>
void ProcessPackage(int j, const void *structp, size_t struct_size)
{
  if (struct_size == sizeof(T))
  {
    T data = {};
    memcpy(&data, structp, struct_size);
    PrintProtocolData(j, data);
  }
  else
  {
    std::cout << "[error] wrong size! data_size = " << struct_size
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
