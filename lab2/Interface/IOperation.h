//
// Created by Ta3ik on 03.12.2020.
//
#include <list>
#include <string>

#ifndef UNTITLED3_IOPERATION_H
#define UNTITLED3_IOPERATION_H

#define REGISTER_OPERATION(T, NAME) static OperationMaker<T> maker(#NAME)


class IOperation {
public:
    virtual void execute(std::list<std::string> &arg) const = 0;

    virtual ~IOperation() {};
};


#endif //UNTITLED3_IOPERATION_H
