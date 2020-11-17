//
// Created by Ta3ik on 14.11.2020.
//

#include "IOperationFactory.hpp"

IOperationFactory& IOperationFactory::getSample() {
    static IOperationFactory factory;
    return factory;
}

IOperation * IOperationFactory::getOperation(const std::string & name) const{
    if(name == "+") return new Plus();
    else if(name == "-") return new Minus();
    else if(name == "*") return new Multiplication();
    else if(name == "\\") return new Division();
    else if(name == "PRINT") return new Print();
    else if(name == "DEFINE") return new Define();
    else if(name == "PUSH") return new Push();
    else if(name == "POP") return new Pop();
}