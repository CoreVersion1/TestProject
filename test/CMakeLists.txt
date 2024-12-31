# 设置外部库的路径
set(EXTERNAL_LIBS_DIR "${CMAKE_SOURCE_DIR}/third_party/libs")

add_executable(utest_ap utest_ap.cpp)
target_link_directories(utest_ap PRIVATE ${EXTERNAL_LIBS_DIR}/roborock)
target_link_libraries(utest_ap PRIVATE uart_api)

add_executable(utest_tmp utest_tmp.cpp)
target_link_directories(utest_tmp PRIVATE ${EXTERNAL_LIBS_DIR}/roborock)
target_link_libraries(utest_tmp PRIVATE uart_api)
