//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED5_DEFINE_H
#define UNTITLED5_DEFINE_H

#include "../Interface/IOperation.h"

class Define : public IOperation{
    void execute(std::list<std::string> &arg, Context & ctx) const override;
};


#endif //UNTITLED5_DEFINE_H
