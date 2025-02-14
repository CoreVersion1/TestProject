#include "roborock.symlink/rda_headers.h"

#pragma once

namespace TestProject {

template <typename T>
void PrintProtocolData(const int &id, const T &data);

template <typename T>
void process_data(int j, const void *structp, size_t struct_size)
{
  if (struct_size <= sizeof(T))
  {
    T data = {};
    memcpy(&data, structp, struct_size);
    PrintProtocolData(j, data);
  }
}

void handle_protocol_data(int id, const void *data, size_t size);

}  // namespace TestProject
