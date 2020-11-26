//
// Created by Ta3ik on 14.11.2020.
//
#include <iostream>
#include "Calculator.hpp"
#include <fstream>

int main(int argc, char** argv){
//    OperationFactory::getSample().RegisterMaker("Plus", new OperationMaker<Plus>());
//    OperationFactory::getSample().RegisterMaker("Plus", new OperationMaker<Minus>());
//    OperationFactory::getSample().RegisterMaker("Plus", new OperationMaker<Multiplication>());
//    OperationFactory::getSample().RegisterMaker("Plus", new OperationMaker<Division>());
//    OperationFactory::getSample().RegisterMaker("Plus", new OperationMaker<Sqrt>());
//    OperationFactory::getSample().RegisterMaker("Plus", new OperationMaker<Print>());
//    OperationFactory::getSample().RegisterMaker("Plus", new OperationMaker<Define>());
    Calculator clk;
    if(argc > 1){
        std::string name = argv[1];
        std::ifstream fin;
        fin.open(name, std::ios::in);
        clk.calculate(fin);
    } else {
        clk.calculate(std::cin);
    }
    std::cout << "Hello, world" << std::endl;
}