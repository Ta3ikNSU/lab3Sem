//
// Created by Ta3ik on 03.12.2020.
//

#include "Pop.h"
#include "../Factory/OperationMaker.h"

void Pop::execute(std::list<std::string> &arg, Context & ctx) const {
    if (arg.size() != 0)
        throw std::logic_error("command doesn't need additional arguments");
    else {
        ctx.top();
    }
}