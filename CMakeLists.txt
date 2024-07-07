cmake_minimum_required(VERSION 3.28)
project(directx_hello_world)

set(CMAKE_CXX_STANDARD 17)

add_executable(directx_hello_world main.cpp
        include/test.h
        src/test.cpp)
