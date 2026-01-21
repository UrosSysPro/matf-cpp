cmake_minimum_required(VERSION 3.28)
project(random)

set(CMAKE_C_STANDARD 99)

add_executable(random
        main.c
        LinkedList.h
        LinkedList.c
)
