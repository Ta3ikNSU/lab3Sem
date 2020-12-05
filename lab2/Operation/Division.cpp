//
// Created by Ta3ik on 03.12.2020.
//

#include "Division.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Division, /);

#include "../Exceptions/arg_command_error.h"
#include "../Exceptions/operation_error.h"
#include "../Exceptions/stack_error.h"

void Division::execute(std::list<std::string> &arg, Context & ctx) const {
    if (ctx.stackSize() < 2)
        throw stack_error("not enough arguments on the stack");
    else if (arg.size() != 0)
        throw arg_command_error("command doesn't need additional arguments");
    else {

        double arg1 = ctx.pop();

        double arg2 = ctx.pop();

        if(arg2 == 0)
            throw operation_error("division by zero");

        double div = arg1 / arg2;
        ctx.pushStack(div);
    }
}