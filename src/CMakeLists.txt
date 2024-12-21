add_subdirectory(SerialPort)

set(Target_List SerialPort)

if(STATIC_LINK)
  add_library(test_depend STATIC $<TARGET_OBJECTS:${Target_List}>)
else()
  add_library(test_depend SHARED $<TARGET_OBJECTS:${Target_List}>)
endif()

set_target_properties(test_depend PROPERTIES POSITION_INDEPENDENT_CODE ON)
