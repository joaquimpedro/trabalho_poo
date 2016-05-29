cmake_minimum_required(VERSION 3.5)
project(poo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp list.cpp list.h nodelist.cpp nodelist.h pessoa.cpp pessoa.h)
add_executable(poo ${SOURCE_FILES})