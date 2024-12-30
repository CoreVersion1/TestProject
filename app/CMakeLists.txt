# 创建可执行文件
add_executable(test_serial test_serial.cpp)
target_link_libraries(test_serial PRIVATE test_depend)

add_executable(test_ap test_ap.cpp)

set(EXTERNAL_LIBS_DIR "${CMAKE_SOURCE_DIR}/third_party/libs")
target_link_directories(test_ap PRIVATE ${EXTERNAL_LIBS_DIR}/roborock)
target_link_libraries(test_ap PRIVATE uart_api)
