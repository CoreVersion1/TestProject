add_subdirectory(SerialPort)
add_subdirectory(Common)

set(Objects_List
    $<TARGET_OBJECTS:SerialPort>
    $<TARGET_OBJECTS:Common>
)

if(STATIC_LINK)
  add_library(test_depend STATIC ${Objects_List})
else()
  add_library(test_depend SHARED ${Objects_List})
endif()

set_target_properties(test_depend PROPERTIES POSITION_INDEPENDENT_CODE ON)
