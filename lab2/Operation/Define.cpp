//
// Created by Ta3ik on 03.12.2020.
//
#include <string>

#include "Define.h"
#include "../Factory/OperationMaker.h"

REGISTER_OPERATION(Define, DEFINE);

void Define::execute(std::list<std::string> &arg, Context & ctx) const {
    if (arg.size() != 2)
        throw std::logic_error("command need 2 arguments");
    else {
        std::string nameOfNewVal = arg.begin()->data();
        double newVal = std::stod((++(arg.begin()))->data());
        ctx.pushConst(nameOfNewVal, newVal);
    }
}
