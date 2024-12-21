file(GLOB SerialPort_SOURCE *.cpp)
add_library(SerialPort OBJECT ${SerialPort_SOURCE})
set_target_properties(SerialPort PROPERTIES POSITION_INDEPENDENT_CODE ON)
