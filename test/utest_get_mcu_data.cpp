#include <iostream>
#include <thread>
#include <unistd.h>

#include "roborock.symlink/rda_headers.h"
#include "Roborock/Roborock.hpp"

using namespace TestProject;

const int kBuffSize = 4096;

void usage(char *argv[])
{
  std::cout << "Usage: " << argv[0] << " [-l loop_cnt]" << std::endl
            << "example: " << argv[0] << std::endl
            << " " << argv[0] << " -l" << std::endl
            << " " << argv[0] << " -l 10" << std::endl;
}

struct Config
{
  bool loop_mode = false;
  int loop_cnt   = 0;
};

Config parse_arguments(int argc, char *argv[])
{
  Config config;
  const int kTryCnt = 100;
  config.loop_cnt   = kTryCnt;

  int opt;
  while ((opt = getopt(argc, argv, "hl::")) != -1)
  {
    switch (opt)
    {
      case 'h':
        usage(argv);
        exit(0);

      case 'l':
        if (optarg)
        {
          // 处理 -lnum
          config.loop_mode = false;
          config.loop_cnt  = std::stoi(optarg);
        }
        else if (argv[optind] && argv[optind][0] != '-')
        {
          // 处理 -l num
          config.loop_mode = false;
          config.loop_cnt  = std::stoi(argv[optind]);
          optind++;
        }
        else
        {
          // 处理 -l（无限循环）
          config.loop_mode = true;
        }
        break;

      case '?':
        std::cerr << "Unknown option: -" << static_cast<char>(optopt) << std::endl;
        usage(argv);
        exit(1);
    }
  }
  return config;
}

int main(int argc, char *argv[])
{
  Config cfg = parse_arguments(argc, argv);

  auto ret = init_uart();
  if (ret != 0)
  {
    std::cout << "init_uart failed" << std::endl;
    return -1;
  }

  clean_uart();
  std::this_thread::sleep_for(std::chrono::seconds(1));

  for (int idx = 0; cfg.loop_mode || (idx < cfg.loop_cnt); idx++)
  {
    static char read_buff[kBuffSize] = {0};

    ret = get_package(read_buff, sizeof(read_buff));
    if (ret <= 0)
    {
      std::cout << "[warn] get_package fail, try_idx = " << idx + 1 << "/" << cfg.loop_cnt << std::endl;
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
