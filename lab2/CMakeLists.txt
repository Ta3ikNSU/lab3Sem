cmake_minimum_required(VERSION 3.17)
project(untitled5)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled5 main.cpp
        Calculator/Calculator.h Calculator/Calculator.cpp
        Context/Context.cpp Context/Context.h
        Exceptions/FactoryException.cpp Exceptions/FactoryException.h
        Factory/OperationMaker.h Factory/OperationFactory.cpp Factory/OperationFactory.h
        Interface/IOperation.h Interface/IOperationMaker.h
        Operation/Plus.h Operation/Plus.cpp
        Operation/Push.h Operation/Push.cpp
        Operation/Print.h Operation/Print.cpp
        Operation/Minus.h Operation/Minus.cpp
        Operation/Define.h Operation/Define.cpp
        Operation/Division.h Operation/Division.cpp
        Operation/Multiplication.h Operation/Multiplication.cpp
        Operation/Pop.h Operation/Pop.cpp
        Operation/Sqrt.h Operation/Sqrt.cpp
        )