//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED3_PLUS_H
#define UNTITLED3_PLUS_H

#include "../Interface/IOperation.h"

class Plus : public IOperation{
    void execute(std::list<std::string> &arg, Context & ctx) const override;
};


#endif //UNTITLED3_PLUS_H
