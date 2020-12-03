//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED5_PUSH_H
#define UNTITLED5_PUSH_H

#include "../Interface/IOperation.h"

class Push : public IOperation {
    void execute(std::list<std::string> &arg, Context & ctx) const override;
};


#endif //UNTITLED5_PUSH_H
