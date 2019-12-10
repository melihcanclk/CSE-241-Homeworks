cmake_minimum_required(VERSION 3.15)
project(5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(5
        AbstractClass.cpp
        AbstractClass.h
        BoardArray1D.cpp
        BoardArray1D.h
        BoardVector.cpp
        BoardVector.h
        main.cpp)
