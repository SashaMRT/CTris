# CMakeLists.txt for CTris Project

cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(CTris VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(CTris ../main.c ../tetrimino.c)

# Include directories
include_directories(..)

# Find the ncurses package
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Link libraries
target_link_libraries(CTris ${CURSES_LIBRARIES})

# Optionally, add other libraries like SDL for enhanced graphics
# find_package(SDL2 REQUIRED)
# target_link_libraries(CTris ${SDL2_LIBRARIES})

# Add custom build instructions or additional configurations here
