//
// Created by Ta3ik on 15.11.2020.
//

#include "Sqrt.hpp"
#include <cmath>

void Sqrt::execute(const std::list<std::string> &args, Context context) {
    if (context.stackSize() < 1)
        throw stack_error("not enough arguments on the stack");
    else if(args.size() != 0)
        throw arg_command_error("command doesn't need additional arguments");
    else{
        double arg = context.top();
        context.pop();
        double sqrt = std::sqrt(arg);
        context.pushStack(sqrt);
    }
}