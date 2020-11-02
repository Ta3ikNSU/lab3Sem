cmake_minimum_required(VERSION 3.17)
project(lab1_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1_test main.cpp LinkedList.cpp LinkedList.h iterator.cpp const_iterator.cpp _List.cpp catch.cpp catch.hpp)