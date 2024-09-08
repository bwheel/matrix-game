
add_library(ComponentsLib)
set_target_properties(ComponentsLib PROPERTIES LINKER_LANGUAGE CXX)

target_sources(ComponentsLib
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Appearance.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Position.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Velocity.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/RotationVelocity.hpp
)
target_include_directories(ComponentsLib
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)