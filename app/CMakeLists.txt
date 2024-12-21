# 创建可执行文件
add_executable(test_serial test_serial.cpp)
# target_link_libraries(oht_device PRIVATE oht_depend)

# # 指定外部库路径
# set(EXTERNAL_LIBS_DIR "${CMAKE_SOURCE_DIR}/libs")
# set(EXTERNAL_LIBS "${EXTERNAL_LIBS_DIR}/external_lib.so")

# # 链接外部库
# target_link_libraries(test_serial PRIVATE ${EXTERNAL_LIBS})

# # 包含头文件路径
# target_include_directories(test_serial PRIVATE ${SRC_DIR})
