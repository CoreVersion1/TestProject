# 设置外部库的路径
set(EXTERNAL_LIBS_DIR "${CMAKE_SOURCE_DIR}/third_party/libs")

if (CMAKE_CROSSCOMPILING)
add_executable(utest_get_mcu_data utest_get_mcu_data.cpp)
target_link_directories(utest_get_mcu_data PRIVATE ${EXTERNAL_LIBS_DIR}/roborock.symlink)
target_link_libraries(utest_get_mcu_data PRIVATE test_depend uart_api)
endif()

if (CMAKE_CROSSCOMPILING)
add_executable(utest_set_mcu_data utest_set_mcu_data.cpp)
target_link_directories(utest_set_mcu_data PRIVATE ${EXTERNAL_LIBS_DIR}/roborock.symlink)
target_link_libraries(utest_set_mcu_data PRIVATE uart_api)
endif()
