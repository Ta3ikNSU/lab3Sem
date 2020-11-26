//
// Created by Ta3ik on 14.11.2020.
//

#ifndef LAB3_IOPERATION_HPP
#define LAB3_IOPERATION_HPP
#include "Context.hpp"
#include <list>
#include <exception>
#include "OperationMaker.h"


class IOperation {
public:
    virtual void execute(const std::list<std::string> &args, Context &context) = 0;
    virtual ~IOperation() = default;
};


#endif //LAB3_IOPERATION_HPP
