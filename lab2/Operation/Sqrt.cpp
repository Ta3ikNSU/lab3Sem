//
// Created by Ta3ik on 03.12.2020.
//

#include "Sqrt.h"
#include <cmath>

#include "../Factory/OperationMaker.h"

#include "../Exceptions/arg_command_error.h"
#include "../Exceptions/stack_error.h"

REGISTER_OPERATION(Sqrt, SQRT);

void Sqrt::execute(std::list<std::string> &arg, Context & ctx) const {
    if (ctx.stackSize() < 1)
        throw stack_error("not enough arguments on the stack");
    else if (arg.size() != 0)
        throw arg_command_error("command doesn't need additional arguments");
    else {
        double arg1 = ctx.pop();

        double s = sqrt(arg1);
        ctx.pushStack(s);
    }
}