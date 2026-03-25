cmake_minimum_required(VERSION 3.28)
project(DSA26_RideRadar_P2)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA26_RideRadar_P2
        DatasetLoader.cpp
        Filter.cpp
        Filter.h
)