//
// Created by Ta3ik on 03.12.2020.
//

#include "Print.h"

#include "../Factory/OperationMaker.h"

#include <iostream>


REGISTER_OPERATION(Print, PRINT);

void Print::execute(std::list<std::string> &arg, Context & ctx) const {
    if (ctx.stackSize() < 1)
        throw std::logic_error("not enough arguments on the stack");
    else if (arg.size() != 0)
        throw std::logic_error("command doesn't need additional arguments");
    else {
        std::cout << ctx.top() << std::endl;
    }
}