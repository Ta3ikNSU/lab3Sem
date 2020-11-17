cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp
        Calculator.hpp Calculator.cpp
        CalculatorException.hpp CalculatorException.cpp
        Context.cpp Context.hpp
        Define.hpp Define.cpp
        Division.hpp Division.cpp
        Error.hpp Error.cpp
        IOperation.hpp IOperation.cpp
        IOperationFactory.hpp IOperationFactory.cpp
        Minus.hpp Minus.cpp
        Multiplication.hpp Multiplication.cpp
        Plus.hpp Plus.cpp
        Pop.hpp Pop.cpp
        Print.hpp Print.cpp
        Push.hpp Push.cpp
        Sqrt.hpp Sqrt.cpp
        )