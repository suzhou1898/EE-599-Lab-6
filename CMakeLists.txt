cmake_minimum_required(VERSION 3.13)
project(Lab6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab6
        connection.cpp
        connection.h
        date.cpp
        date.h
        network.cpp
        network.h
        test_network.cpp)
