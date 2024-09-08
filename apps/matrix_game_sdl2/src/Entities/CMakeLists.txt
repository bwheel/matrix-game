
add_library(EntitiesLib)

set_target_properties(EntitiesLib PROPERTIES LINKER_LANGUAGE CXX)

find_package(EnTT CONFIG REQUIRED)

target_sources(EntitiesLib
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/GlyphFactory.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GlyphFactory.cpp
)

target_include_directories(EntitiesLib
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(
  EntitiesLib
  PRIVATE
  EnTT::EnTT
  ComponentsLib
)