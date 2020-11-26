//
// Created by Ta3ik on 25.11.2020.
//

#ifndef LAB2_OPERATIONMAKER_H
#define LAB2_OPERATIONMAKER_H
#include "IOperationMaker.hpp"
#include "OperationFactory.hpp"
#include "Plus.hpp"


template<typename T>
class OperationMaker : public IOperationMaker{
public:
    virtual IOperation * create() const{
        return new T();
    }

    OperationMaker(const std::string& key)
    {
        OperationFactory::getSample().RegisterMaker(key, this);
    }
};


#endif //LAB2_OPERATIONMAKER_H
