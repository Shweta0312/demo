cmake_minimum_required(VERSION 3.26)
project(demo)

set(CMAKE_CXX_STANDARD 17)

add_executable(demo main.cpp
        functions.cpp
        car.cpp)
