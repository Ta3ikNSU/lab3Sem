//
// Created by Ta3ik on 06.12.2020.
//

#ifndef UNTITLED5_OPERATION_ARROR_H
#define UNTITLED5_OPERATION_ARROR_H

#include "../Exceptions/CalculatorException.h"

class operation_error : public CalculatorException {
public:
    operation_error(const std::string & _msg) : CalculatorException(_msg){};
};


#endif //UNTITLED5_OPERATION_ARROR_H
