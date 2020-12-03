//
// Created by Ta3ik on 03.12.2020.
//

#include "Sqrt.h"
#include <cmath>

#include "../Factory/OperationMaker.h"


REGISTER_OPERATION(Sqrt, SQRT);

void Sqrt::execute(std::list<std::string> &arg, Context & ctx) const {
    if (ctx.stackSize() < 1)
        throw std::logic_error("not enough arguments on the stack");
    else if (arg.size() != 0)
        throw std::logic_error("command doesn't need additional arguments");
    else {
        double arg1 = ctx.top();
        ctx.pop();

        double s = sqrt(arg1);
        ctx.pushStack(s);
    }
}