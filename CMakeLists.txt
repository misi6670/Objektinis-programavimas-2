cmake_minimum_required(VERSION 3.10)

project(v1.0 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(v1.0 v1.0.cpp klaidos.h listai.h testavimas.h vektoriai.h klaidos.cpp listai.cpp testavimas.cpp vektoriai.cpp)
