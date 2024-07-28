cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(MatrixGame)

find_package(EnTT CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.cpp)


target_link_libraries(${PROJECT_NAME} 
    PRIVATE
    EnTT::EnTT
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_ttf::SDL2_ttf-static
)

# You will need to install Xorg dependencies to use feature x11:

# sudo apt install libx11-dev libxft-dev libxext-dev libwayland-dev libxkbcommon-dev libegl1-mesa-dev libibus-1.0-dev -y
