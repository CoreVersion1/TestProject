#include <iostream>
#include <thread>

#include "roborock.symlink/rda_headers.h"
#include "Roborock/Roborock.hpp"

using namespace TestProject;

const int kTryCnt   = 100;
const int kBuffSize = 4096;

int main(int argc, char *argv[])
{
  bool loop_mode = false;

  // Parse command-line arguments
  for (int i = 1; i < argc; ++i)
  {
    std::string arg = argv[i];
    if (arg == "-l")
    {
      loop_mode = true;
    }
  }

  auto ret = init_uart();
  if (ret != 0)
  {
    std::cout << "init_uart failed" << std::endl;
    return -1;
  }

  clean_uart();
  std::this_thread::sleep_for(std::chrono::seconds(1));

  for (int idx = 0; loop_mode || (idx < kTryCnt); idx++)
  {
    static char read_buff[kBuffSize] = {0};

    ret = get_package(read_buff, sizeof(read_buff));
    if (ret <= 0)
    {
      std::cout << "[warn] get_package fail, try_idx = " << idx + 1 << "/" << kTryCnt << std::endl;
      std::this_thread::sleep_for(std::chrono::microseconds(1));
      continue;
    }

    std::cout << "[info] got package, size = " << ret << std::endl;
    int id        = 0;
    char *src     = read_buff;
    char *data    = nullptr;
    int data_size = 0;

    while ((id = get_next(&src, &ret, &data, &data_size)) > 0)
    {
      HandleProtocolData(id, data, data_size);
    }
  }

  return 0;
}
