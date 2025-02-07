#include <mutex>
#include <string>
#include <unistd.h>

#pragma once

namespace TestProject {

const int kBuffSize = 1024;

class SerialPort {
 public:
  SerialPort(const std::string &dev) : serial_dev_(dev) {}

  ~SerialPort()
  {
    Close();
  }

  void Config(int baud_rate = 115200, bool use_epoll = false);

  int Read(char *buf, int len, int timeout_ms = 1000);

  int Write(const char *buf, int len, int timeout_ms = 1000);

  void LoopRead();

  void LoopWrite();

 private:
  void Open();
  void Close();
  int SetTty(int fd, int baud_rate);
  int WaitData_Poll(int fd, int timeout_ms);
  int WaitData_Epoll(int fd, int timeout_ms);

 private:
  bool is_inited_          = false;
  std::string serial_dev_  = {};
  int serial_fd_           = {};  // File descriptor
  std::mutex output_mutex_ = {};
  bool use_epoll_          = false;
};

}  // namespace TestProject
