add_library(Core SHARED)

set_target_properties(Core PROPERTIES LINKER_LANGUAGE CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_sources(Core
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Utils/Alphabet.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Alphabet.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/include/Services/FontCache.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Services/FontCache.cpp
)

target_include_directories(Core
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  Core
  PRIVATE
  EnTT::EnTT
  SDL2::SDL2-static
  SDL2_ttf::SDL2_ttf-static
  ECS
)