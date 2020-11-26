//
// Created by Ta3ik on 20.11.2020.
//

#ifndef LAB2_IOPERATIONMAKER_HPP
#define LAB2_IOPERATIONMAKER_HPP
#include "IOperation.hpp"

class IOperationMaker {
public:
    virtual IOperation * create() const = 0;
    virtual ~IOperationMaker() = default;
};




#endif //LAB2_IOPERATIONMAKER_HPP
