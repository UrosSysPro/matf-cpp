cmake_minimum_required(VERSION 3.28)
project(dijkstra_data_structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(dijkstra_data_structures main.cpp
        ../dijkstra/main.cpp)