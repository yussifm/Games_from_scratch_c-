cmake_minimum_required(VERSION 3.15)
project(MinesweeperGame LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Add executable
add_executable(MinesweeperGame ${SOURCES})

# Find and link SDL2 libraries (via vcpkg)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

target_include_directories(MinesweeperGame PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(MinesweeperGame PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)


if (WIN32)
  target_link_libraries(
    MinesweeperGame PRIVATE SDL2::SDL2main
  )
endif()