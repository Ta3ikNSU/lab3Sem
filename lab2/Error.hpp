//
// Created by Ta3ik on 15.11.2020.
//

#ifndef LAB3_ERROR_HPP
#define LAB3_ERROR_HPP

#include "CalculatorException.hpp"

class stack_error : public CalculatorException {
public:
    stack_error(const std::string & _msg) : CalculatorException(_msg){};

};

class arg_command_error : public CalculatorException {
public:
    arg_command_error(const std::string & _msg) : CalculatorException(_msg){};

};


#endif //LAB3_ERROR_HPP
