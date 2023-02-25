cmake_minimum_required(VERSION 3.21)
project(s)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(s
        intmatrix2.cpp
        intmatrix2.h
        intmatrixtest2.cpp)
