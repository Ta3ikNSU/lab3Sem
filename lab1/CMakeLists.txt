cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp MyDLL.cpp MyDLL.h _List.cpp iterator.cpp const_iterator.cpp catch.hpp catch.cpp)