//
// Created by Ta3ik on 15.11.2020.
//

#include "Minus.hpp"

void Minus::execute(const std::list<std::string> &args, Context context) {
    if (context.stackSize() < 2)
        throw stack_error("not enough arguments on the stack");
    else if(args.size() != 0)
        throw arg_command_error("command doesn't need additional arguments");
    else {
        double arg1 = context.top();
        context.pop();

        double arg2 = context.top();
        context.pop();

        double minus = arg1 - arg2;
        context.pushStack(minus);
    }
}