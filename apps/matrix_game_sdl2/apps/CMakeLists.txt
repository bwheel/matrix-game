add_executable(matrix_game_sdl2 matrix_game_sdl2.cpp)

find_package(SDL2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_link_libraries(matrix_game_sdl2
  PRIVATE
  EnTT::EnTT
  SDL2::SDL2main
  SDL2::SDL2-static
  SDL2_ttf::SDL2_ttf-static
  ComponentsLib
  EntitiesLib
  SystemsLib
)

file(COPY ../resources/SpaceMono.ttf DESTINATION ${CMAKE_BINARY_DIR}/apps/resources)