//
// Created by Ta3ik on 15.11.2020.
//

#include "Define.hpp"

void Define::execute(const std::list<std::string> &args, Context context) {
    if (args.size() != 1) {
        throw arg_command_error("wrong number of arguments");
    } else {
        auto it = args.begin();
        std::string name = it->data();
        it++;
        double arg = std::stod(it->data());

        context.pushConst(name, arg);
    }
}