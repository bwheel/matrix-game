
add_library(SystemsLib)

set_target_properties(SystemsLib PROPERTIES LINKER_LANGUAGE CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_sources(SystemsLib
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/ISystem.hpp

  ${CMAKE_CURRENT_SOURCE_DIR}/MovementSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MovementSystem.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/RotationSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/RotationSystem.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/ColorSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ColorSystem.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/RenderSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/RenderSystem.cpp

  # ${CMAKE_CURRENT_SOURCE_DIR}/BoundarySystem.hpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/BoundarySystem.cpp

  # ${CMAKE_CURRENT_SOURCE_DIR}/SpawnSystem.hpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/SpawnSystem.cpp
)

target_include_directories(SystemsLib
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  SystemsLib
  PRIVATE
  EnTT::EnTT
  SDL2::SDL2-static
  SDL2_ttf::SDL2_ttf-static
  ComponentsLib
)