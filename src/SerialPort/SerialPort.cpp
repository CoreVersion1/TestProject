#include "SerialPort/SerialPort.hpp"

#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <mutex>
#include <poll.h>
#include <string>
#include <sys/epoll.h>
#include <termios.h>
#include <thread>
#include <unistd.h>

namespace TestProject {

void SerialPort::Config(int baud_rate, bool use_epoll) {
  Open();
  SetTty(serial_fd_, baud_rate);
  use_epoll_ = use_epoll;
  is_inited_ = true;
}

int SerialPort::Read(char *buf, int len, int timeout_ms) {
  if (!is_inited_) {
    std::cerr << "Serial port not initialized" << std::endl;
    return -1;
  }

  int ret = 0;
  if (use_epoll_) {
    ret = WaitData_Epoll(serial_fd_, 1000);
  } else {
    ret = WaitData_Poll(serial_fd_, 1000);
  }

  if (ret < 0) {
    std::cerr << "Error waiting for data" << std::endl;
    return ret;
  } else if (ret == 0) {
    return ret;
  }

  return read(serial_fd_, buf, len - 1);
}

int SerialPort::Write(const char *buf, int len, int timeout_ms) {
  if (!is_inited_) {
    std::cerr << "Serial port not initialized" << std::endl;
    return -1;
  }

  return write(serial_fd_, buf, len);
}

void SerialPort::LoopRead() {
  char buffer[kBuffSize] = {};
  while (true) {
    auto bytes_read = Read(buffer, sizeof(buffer), 1000);
    if (bytes_read > 0) {
      buffer[bytes_read] = '\0';
      std::lock_guard<std::mutex> lock(output_mutex_);
      std::cout << "\nRx: " << buffer << "\nTx: " << std::flush;
    } else if (bytes_read == -1) {
      perror("Error reading from serial port");
    }
  }
}

void SerialPort::LoopWrite() {
  while (true) {
    {
      std::lock_guard<std::mutex> lock(output_mutex_);
      std::cout << "Tx: " << std::flush;
    }
    std::string input;
    std::getline(std::cin, input);

    if (Write(input.c_str(), input.size(), 1000) < 0) {
      perror("Error writing to serial port");
    }
  }
}

void SerialPort::Open() {
  serial_fd_ = open(serial_dev_.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
  if (serial_fd_ < 0) {
    perror("Error opening serial port");
    exit(EXIT_FAILURE);
  }
}

void SerialPort::Close() {
  if (serial_fd_ >= 0) {
    close(serial_fd_);
    serial_fd_ = -1;
  }
}

int SerialPort::SetTty(int fd, int baud_rate) {
  struct termios tty;
  if (tcgetattr(fd, &tty) != 0) {
    perror("Error getting terminal attributes");
    exit(EXIT_FAILURE);
  }

  speed_t baud;
  switch (baud_rate) {
  case 9600:
    baud = B9600;
    break;
  case 19200:
    baud = B19200;
    break;
  case 38400:
    baud = B38400;
    break;
  case 57600:
    baud = B57600;
    break;
  case 115200:
    baud = B115200;
    break;
  case 230400:
    baud = B230400;
    break;
  case 460800:
    baud = B460800;
    break;
  case 500000:
    baud = B500000;
    break;
  case 576000:
    baud = B576000;
    break;
  case 921600:
    baud = B921600;
    break;
  case 1000000:
    baud = B1000000;
    break;
  case 1152000:
    baud = B1152000;
    break;
  case 1500000:
    baud = B1500000;
    break;
  case 2000000:
    baud = B2000000;
    break;
  case 2500000:
    baud = B2500000;
    break;
  case 3000000:
    baud = B3000000;
    break;
  case 3500000:
    baud = B3500000;
    break;
  case 4000000:
    baud = B4000000;
    break;
  default:
    std::cerr << "Unsupported baud rate: " << baud_rate << std::endl;
    exit(EXIT_FAILURE);
  }

  // Set baud rate (e.g., 115200)
  cfsetospeed(&tty, baud);
  cfsetispeed(&tty, baud);

  // Configure 8N1 mode: 8 data bits, no parity, 1 stop bit
  tty.c_cflag &= ~(CSIZE | CSTOPB | PARENB | INPCK);
  tty.c_cflag |= (CS8 | CLOCAL | CREAD);
  tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
  tty.c_oflag &= ~(OPOST | ONLCR | OCRNL);
  tty.c_iflag &= ~(IGNBRK | ICRNL | INLCR | IXON | IXOFF | IXANY);
  tty.c_cc[VMIN] = 1;
  tty.c_cc[VTIME] = 0;

  if (tcsetattr(serial_fd_, TCSANOW, &tty) != 0) {
    perror("Error setting terminal attributes");
    exit(EXIT_FAILURE);
  }

  return 0;
}

int SerialPort::WaitData_Poll(int fd, int timeout_ms) {
  struct pollfd pfd = {fd, POLLIN, 0}; // POLLIN 表示等待可读事件
  return poll(&pfd, 1, timeout_ms);    // 等待timeout_ms毫秒
}

int SerialPort::WaitData_Epoll(int fd, int timeout_ms) {
  int epoll_fd = epoll_create1(0); // 创建 epoll 实例
  if (epoll_fd == -1) {
    perror("epoll_create1 failed");
    return -1;
  }

  struct epoll_event event;
  event.events = EPOLLIN; // 等待可读事件
  event.data.fd = fd;     // 添加串口文件描述符

  if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1) {
    perror("epoll_ctl failed");
    close(epoll_fd);
    return -1;
  }

  struct epoll_event events[1];
  int ret = epoll_wait(epoll_fd, events, 1, timeout_ms); // 等待timeout_ms毫秒
  close(epoll_fd);                                       // 关闭 epoll 实例
  return ret; // 返回epoll_wait的结果，用于判断是否有数据
}

} // namespace TestProject
