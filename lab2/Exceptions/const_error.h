//
// Created by Ta3ik on 06.12.2020.
//

#ifndef UNTITLED5_CONST_ERROR_H
#define UNTITLED5_CONST_ERROR_H

#include "../Exceptions/CalculatorException.h"

class const_error : public CalculatorException {
public:
    const_error(const std::string & _msg) : CalculatorException(_msg){};
};


#endif //UNTITLED5_CONST_ERROR_H
