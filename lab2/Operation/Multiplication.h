//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED5_MULTIPLICATION_H
#define UNTITLED5_MULTIPLICATION_H

#include "../Interface/IOperation.h"

class Multiplication : public IOperation {
    void execute(std::list<std::string> &arg, Context & ctx) const override;
};


#endif //UNTITLED5_MULTIPLICATION_H
