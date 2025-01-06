#include <mutex>
#include <string>
#include <unistd.h>

#pragma once

namespace TestProject {

class SerialPort {
public:
  SerialPort() : serial_fd_(-1) {}

  ~SerialPort() {
    if (serial_fd_ >= 0) {
      close(serial_fd_);
    }
  }

  void openPort(const std::string &device);

  void configure(int baud_rate = 115200);

  void ReadData();

  void WriteData();

private:
  int serial_fd_ = {}; // File descriptor
  std::mutex output_mutex_ = {};
};

} // namespace TestProject
