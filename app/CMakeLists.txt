add_executable(run_serial run_serial.cpp)
target_link_libraries(run_serial PRIVATE test_depend pthread)
