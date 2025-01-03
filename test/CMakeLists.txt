# 设置外部库的路径
set(EXTERNAL_LIBS_DIR "${CMAKE_SOURCE_DIR}/third_party/libs")

add_executable(utest_get_mcu_data utest_get_mcu_data.cpp)
target_link_directories(utest_get_mcu_data PRIVATE ${EXTERNAL_LIBS_DIR}/roborock)
target_link_libraries(utest_get_mcu_data PRIVATE test_depend uart_api)

add_executable(utest_set_odo utest_set_odo.cpp)
target_link_directories(utest_set_odo PRIVATE ${EXTERNAL_LIBS_DIR}/roborock)
target_link_libraries(utest_set_odo PRIVATE uart_api)
