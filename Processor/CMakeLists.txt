cmake_minimum_required(VERSION 3.20.2)
project(Processor)

set(CMAKE_CXX_STANDARD 23)

add_executable(Processor main.cpp image_adjustments.cpp image_flip.cpp image_filter.cpp image_comparison.cpp)
