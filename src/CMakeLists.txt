add_subdirectory(SerialPort)

add_library(test_depend SHARED $<TARGET_OBJECTS:SerialPort>)
set_target_properties(test_depend PROPERTIES POSITION_INDEPENDENT_CODE ON)
