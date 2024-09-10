
add_library(ECS SHARED)

set_target_properties(ECS PROPERTIES LINKER_LANGUAGE CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_sources(ECS
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Components/Appearance.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Components/Position.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Components/RotationVelocity.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Components/Velocity.hpp

  ${CMAKE_CURRENT_SOURCE_DIR}/include/Entities/GlyphFactory.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Entities/GlyphFactory.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/include/Systems/ISystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Systems/ColorSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/ColorSystem.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Systems/MovementSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/MovementSystem.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Systems/RenderSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/RenderSystem.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Systems/RotationSystem.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/RotationSystem.cpp
)

target_include_directories(ECS
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  ECS
  PRIVATE
  EnTT::EnTT
  SDL2::SDL2-static
  SDL2_ttf::SDL2_ttf-static
)