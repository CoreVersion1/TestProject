#include <cstdlib>
#include <iostream>
#include <thread>

#include "SerialPort/SerialPort.hpp"

using namespace TestProject;

int main(int argc, char *argv[]) {
  std::string serial_dev{};
  std::string mode{};
  int baud_rate = 115200; // 默认波特率

  // Parse command-line arguments
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "-d" && i + 1 < argc) {
      serial_dev = argv[++i];
    } else if (arg == "-l" || arg == "-r" || arg == "-t") {
      mode = arg;
    } else if (arg == "-b" && i + 1 < argc) {
      try {
        baud_rate = std::stoi(argv[++i]); // 更新波特率
      } catch (const std::exception &e) {
        std::cerr << "Invalid baud rate value: " << argv[i] << std::endl;
        return EXIT_FAILURE;
      }
    }
  }

  // 检查必要参数是否存在
  if (serial_dev.empty() || mode.empty()) {
    std::cerr << "Usage: " << argv[0]
              << " -d <serial_device> <-l|-r|-t> [-b <baud_rate>]" << std::endl;
    std::cerr << "Example: " << argv[0] << " -d /dev/ttyUSB0 -l -b 115200"
              << std::endl;
    return EXIT_FAILURE;
  }

  SerialPort serial;
  serial.OpenPort(serial_dev);

  // 配置波特率
  try {
    serial.Config(baud_rate); // 使用指定或默认波特率
  } catch (const std::exception &e) {
    std::cerr << "Error configuring serial port: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Serial port " << serial_dev
            << " opened and configured with baud rate " << baud_rate << "."
            << std::endl;

  std::thread readerThread;
  std::thread writerThread;

  if (mode == "-l" || mode == "-r") {
    readerThread = std::thread(&SerialPort::LoopRead, &serial);
  }

  if (mode == "-l" || mode == "-t") {
    writerThread = std::thread(&SerialPort::LoopWrite, &serial);
  }

  if (writerThread.joinable()) {
    writerThread.join();
  }
  if (readerThread.joinable()) {
    readerThread.join();
  }

  std::cout << "Serial port closed." << std::endl;

  return EXIT_SUCCESS;
}
