#include <iostream>
#include <thread>

#include "SerialPort/SerialPort.hpp"

using namespace TestProject;

int main(int argc, char *argv[]) {
  std::string serial_dev{};
  std::string mode{};

  // Parse command-line arguments
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "-d" && i + 1 < argc) {
      serial_dev = argv[++i];
    } else if (arg == "-l" || arg == "-r" || arg == "-t") {
      mode = arg;
    }
  }

  if (serial_dev.empty() || mode.empty()) {
    std::cerr << "Usage: " << argv[0] << " -d <serial_device> <-l|-r|-t>"
              << std::endl;
    std::cerr << "Example: " << argv[0] << " -d /dev/ttyUSB0 -l" << std::endl;
    return EXIT_FAILURE;
  }

  SerialPort serial;
  serial.openPort(serial_dev);
  serial.configure();

  std::cout << "Serial port " << serial_dev << " opened and configured."
            << std::endl;

  std::thread readerThread;
  std::thread writerThread;

  if (mode == "-l" || mode == "-r") {
    readerThread = std::thread(&SerialPort::ReadData, &serial);
  }

  if (mode == "-l" || mode == "-t") {
    writerThread = std::thread(&SerialPort::WriteData, &serial);
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
