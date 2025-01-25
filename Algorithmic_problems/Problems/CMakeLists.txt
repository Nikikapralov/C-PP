cmake_minimum_required(VERSION 3.30)
project(Problems)

set(CMAKE_CXX_STANDARD 23)

add_executable(Problems main.cpp
        01_Two_sum/two_sum.h
        11_Container_to_hold_max_water/container_to_hold_max_water.h)
