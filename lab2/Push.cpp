//
// Created by Ta3ik on 15.11.2020.
//

#include "Push.hpp"

void Push::execute(const std::list<std::string> &args, Context context) {
    if (args.size() != 1) {
        throw arg_command_error("wrong number of arguments");
    } else {
        std::string name = args.front();
        double arg;
        if(context.checkConst(name)){
            arg = context.getConst(name);
        }else{
            arg = std::stod(args.front());
        }
        context.pushStack(arg);
    }
}