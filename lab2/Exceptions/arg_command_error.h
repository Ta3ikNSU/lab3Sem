//
// Created by Ta3ik on 06.12.2020.
//

#ifndef UNTITLED5_ARG_COMMAND_ERROR_H
#define UNTITLED5_ARG_COMMAND_ERROR_H

#include "../Exceptions/CalculatorException.h"

class arg_command_error : public CalculatorException {
public:
    arg_command_error(const std::string & _msg) : CalculatorException(_msg){};
};


#endif //UNTITLED5_ARG_COMMAND_ERROR_H
