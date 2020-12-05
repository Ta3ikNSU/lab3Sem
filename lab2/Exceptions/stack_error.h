//
// Created by Ta3ik on 05.12.2020.
//

#ifndef UNTITLED5_STACKERROR_H
#define UNTITLED5_STACKERROR_H

#include "../Exceptions/CalculatorException.h"

class stack_error : public CalculatorException{
public:
    stack_error(const std::string & _msg) : CalculatorException(_msg){};
};


#endif //UNTITLED5_STACKERROR_H
