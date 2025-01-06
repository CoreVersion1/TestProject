#include "SerialPort/SerialPort.hpp"

#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <termios.h>
#include <thread>
#include <unistd.h>

namespace TestProject {

void SerialPort::openPort(const std::string &device) {
  serial_fd_ = open(device.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
  if (serial_fd_ < 0) {
    perror("Error opening serial port");
    exit(EXIT_FAILURE);
  }
}

void SerialPort::configure(int baud_rate) {
  struct termios tty;
  if (tcgetattr(serial_fd_, &tty) != 0) {
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
}

void SerialPort::ReadData() {
  char buffer[256] = {};
  while (true) {
    int bytes_read = read(serial_fd_, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
      buffer[bytes_read] = '\0';
      std::lock_guard<std::mutex> lock(output_mutex_);
      std::cout << "\nRx: " << buffer << "\nTx: " << std::flush;
    } else if (bytes_read == -1) {
      perror("Error reading from serial port");
    }
  }
}

void SerialPort::WriteData() {
  while (true) {
    {
      std::lock_guard<std::mutex> lock(output_mutex_);
      std::cout << "Tx: " << std::flush;
    }
    std::string input;
    std::getline(std::cin, input);

    if (write(serial_fd_, input.c_str(), input.size()) == -1) {
      perror("Error writing to serial port");
    }
  }
}

} // namespace TestProject
