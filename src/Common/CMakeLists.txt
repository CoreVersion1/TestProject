file(GLOB Common_SOURCE *.cpp)
add_library(Common OBJECT ${Common_SOURCE})
set_target_properties(Common PROPERTIES POSITION_INDEPENDENT_CODE ON)
