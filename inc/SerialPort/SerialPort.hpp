#include <mutex>
#include <string>
#include <unistd.h>

#pragma once

namespace TestProject {

const int kBuffSize = 1024;

class SerialPort {
public:
  SerialPort() : serial_fd_(-1) {}

  ~SerialPort() {
    ClosePort();
  }

  void OpenPort(const std::string &device);

  void ClosePort();

  void configure(int baud_rate = 115200);

  void ReadData();

  void WriteData();

private:
  int serial_fd_ = {}; // File descriptor
  std::mutex output_mutex_ = {};
};

} // namespace TestProject
