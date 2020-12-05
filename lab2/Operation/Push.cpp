//
// Created by Ta3ik on 03.12.2020.
//

#include "../Factory/OperationMaker.h"

#include "Push.h"

#include "../Exceptions/arg_command_error.h"
#include "../Exceptions/const_error.h"

REGISTER_OPERATION(Push, PUSH);

void Push::execute(std::list<std::string> &arg, Context &ctx) const {
    if (arg.size() > 2 || arg.size() == 0)
        throw arg_command_error("command  need 1 or 2 arguments");
    else {
        char firstSymbol = arg.begin()->data()[0];
        if (firstSymbol >= '0' && firstSymbol <= '9' && arg.size() == 1) {
            double newVal = std::stod(arg.begin()->data());
            ctx.pushStack(newVal);
        } else {
            std::string nameOfVal = arg.begin()->data();
            double val = ctx.getConst(nameOfVal);
            ctx.pushStack(val);
        }
    }
}