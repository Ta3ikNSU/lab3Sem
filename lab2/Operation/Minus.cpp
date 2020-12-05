//
// Created by Ta3ik on 03.12.2020.
//

#include "Minus.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Minus, -);

#include "../Exceptions/arg_command_error.h"
#include "../Exceptions/stack_error.h"

void Minus::execute(std::list<std::string> &arg, Context & ctx) const {
    if (ctx.stackSize() < 2)
        throw stack_error("not enough arguments on the stack");
    else if (arg.size() != 0)
        throw arg_command_error("command doesn't need additional arguments");
    else {

        double arg1 = ctx.pop();

        double arg2 = ctx.pop();

        double min = arg1 - arg2;
        ctx.pushStack(min);
    }
}