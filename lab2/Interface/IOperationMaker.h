//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED3_IOPERATIONMAKER_H
#define UNTITLED3_IOPERATIONMAKER_H

#include "IOperation.h"

class IOperationMaker {

public:
    virtual IOperation *create(const std::string &operationName) const = 0;
};


#endif //UNTITLED3_IOPERATIONMAKER_H
