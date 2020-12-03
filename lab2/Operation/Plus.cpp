//
// Created by Ta3ik on 03.12.2020.
//

#include "Plus.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Plus, PLUS);

void Plus::execute(std::list<std::string> &arg, Context & ctx) const {
    if (ctx.stackSize() < 2)
        throw std::logic_error("not enough arguments on the stack");
    else if (arg.size() != 0)
        throw std::logic_error("command doesn't need additional arguments");
    else {
        double arg1 = ctx.top();
        ctx.pop();

        double arg2 = ctx.top();
        ctx.pop();

        double sum = arg1 + arg2;
        ctx.pushStack(sum);
    }
}