//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED5_POP_H
#define UNTITLED5_POP_H

#include "../Interface/IOperation.h"

class Pop : public IOperation {
    void execute(std::list<std::string> &arg, Context & ctx) const override;
};


#endif //UNTITLED5_POP_H
