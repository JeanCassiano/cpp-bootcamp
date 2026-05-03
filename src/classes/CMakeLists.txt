cmake_minimum_required(VERSION 3.10)

# Project Name
project(RPGOOPDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)

file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(rpg_demo ${SOURCES})

message(STATUS "Project configured to build rpg_demo with ${CMAKE_CXX_COMPILER_ID}")