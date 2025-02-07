#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

#include "roborock.symlink/rda_headers.h"

int main()
{
  auto ret = init_uart();
  if (ret != 0)
  {
    std::cout << "init_uart failed" << std::endl;
    return -1;
  }

  clean_uart();
  std::this_thread::sleep_for(std::chrono::seconds(1));

  McuOdoSpd_st spd_info = {1, 2};
  ret                   = sent_basic_cmd(CMD_SET_ODO_SPD_ID, sizeof(spd_info), &spd_info);

  return 0;
}
