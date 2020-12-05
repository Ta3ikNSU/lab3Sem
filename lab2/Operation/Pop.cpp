//
// Created by Ta3ik on 03.12.2020.
//

#include "Pop.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Pop, POP);

#include "../Exceptions/arg_command_error.h"
#include "../Exceptions/stack_error.h"

void Pop::execute(std::list<std::string> &arg, Context & ctx) const {
    if (arg.size() != 0)
        throw arg_command_error("command doesn't need additional arguments");
    else {
        if(ctx.stackSize() > 0) ctx.pop();
        else throw stack_error("stack is empty");
    }
}