cmake_minimum_required(VERSION 3.22)

SET(EXEC_NAME MatrixGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set(CMAKE_BUILD_TYPE Debug)

project(MatrixGame)

find_package(EnTT CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

include_directories( ${EXEC_NAME} ${SDL2_INCLUDE_DIRS})

add_executable( ${EXEC_NAME} src/main.cpp)


target_link_libraries( ${EXEC_NAME} 
    PRIVATE
    EnTT::EnTT
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_ttf::SDL2_ttf-static
)

include(${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt)

# Ensure resource files are available by copying
add_custom_command(
    TARGET ${EXEC_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
    COMMAND ${CMAKE_COMMAND} -E echo "Copied resource directory to binary directory."
)

