file(GLOB Roborock_SOURCE *.cpp)
add_library(Roborock OBJECT ${Roborock_SOURCE})
set_target_properties(Roborock PROPERTIES POSITION_INDEPENDENT_CODE ON)
