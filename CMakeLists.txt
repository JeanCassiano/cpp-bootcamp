# 1. Defining the cmake minimum version and the project name
cmake_minimum_required(VERSION 3.22.1)
project(CppBootcamp)

# 2. Force to use the modern C++ and turn on warnings 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# 3. Mapping executables
add_executable(pointers "src/function_pointers/main.cpp")
add_executable(templates "src/function_templates/main.cpp")
add_executable(raii "src/raii/main.cpp")
