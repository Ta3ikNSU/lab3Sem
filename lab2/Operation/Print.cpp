//
// Created by Ta3ik on 03.12.2020.
//

#include "Print.h"
#include "../Factory/OperationMaker.h"

#include "../Exceptions/arg_command_error.h"
#include "../Exceptions/stack_error.h"

#include <iostream>


REGISTER_OPERATION(Print, PRINT);

void Print::execute(std::list<std::string> &arg, Context & ctx) const {
    if (ctx.stackSize() < 1)
        throw stack_error("not enough arguments on the stack");
    else if (arg.size() != 0)
        throw arg_command_error("command doesn't need additional arguments");
    else {
        std::cout.precision(10);
        std::cout << ctx.top() << std::endl;
    }
}