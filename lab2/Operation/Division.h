//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED5_DIVISION_H
#define UNTITLED5_DIVISION_H

#include "../Interface/IOperation.h"

class Division : public IOperation {
    void execute(std::list<std::string> &arg, Context & ctx) const override;
};

#endif //UNTITLED5_DIVISION_H
