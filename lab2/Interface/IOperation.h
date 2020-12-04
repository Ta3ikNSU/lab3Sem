//
// Created by Ta3ik on 03.12.2020.
//
#include <list>
#include <string>

#ifndef UNTITLED3_IOPERATION_H
#define UNTITLED3_IOPERATION_H

#define REGISTER_OPERATION(T, NAME) static OperationMaker<T> maker(#NAME)

#include "../Context/Context.h"

class IOperation {
public:
    virtual void execute(std::list<std::string> &arg, Context & ctx) const = 0;

    virtual ~IOperation() = default;
};


#endif //UNTITLED3_IOPERATION_H
