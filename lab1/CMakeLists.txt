cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 main.cpp MyDll.cpp MyDll.h _List.cpp iterator.cpp const_iterator.cpp catch.cpp catch.hpp)