//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED3_OPERATIONMAKER_H
#define UNTITLED3_OPERATIONMAKER_H

#include "../Interface/IOperationMaker.h"
#include "OperationFactory.h"

template <typename T>

class OperationMaker : public IOperationMaker{
public:
    OperationMaker(const std::string &blockName){
        OperationFactory::getInstance().RegisterMaker(blockName, this);
    }

    IOperation *create(const std::string &blockName) const override {
        return new T;
    }
};


#endif //UNTITLED3_OPERATIONMAKER_H
