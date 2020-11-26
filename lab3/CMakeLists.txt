cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp
        Calculator.hpp Calculator.cpp
        CalculatorException.hpp CalculatorException.cpp
        Context.cpp Context.hpp
        Error.hpp Error.cpp
        IOperation.hpp IOperation.cpp
        OperationFactory.hpp OperationFactory.cpp
        OperationMaker.cpp OperationMaker.h
        IOperationMaker.cpp IOperationMaker.hpp
        Plus.hpp Plus.cpp
        )