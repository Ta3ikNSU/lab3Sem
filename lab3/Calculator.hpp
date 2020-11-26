//
// Created by Ta3ik on 14.11.2020.
//

#ifndef LAB3_CALCULATOR_HPP
#define LAB3_CALCULATOR_HPP

#include "Context.hpp"
#include "IOperation.hpp"
#include "OperationFactory.hpp"
#include "IOperationMaker.hpp"
#include "OperationMaker.h"


#include <istream>

class Calculator {
public:
    void calculate(std::istream &stream);
};


#endif //LAB3_CALCULATOR_HPP
