cmake_minimum_required(VERSION 3.15)
project(MinesweeperGame LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Add executable
add_executable(MinesweeperGame ${SOURCES})

# Find and link SDL2 libraries (via vcpkg)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

target_link_libraries(MinesweeperGame PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)
