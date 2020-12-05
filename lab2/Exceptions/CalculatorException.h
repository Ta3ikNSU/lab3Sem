//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED3_FACTORYEXCEPTION_H
#define UNTITLED3_FACTORYEXCEPTION_H

#include <string>
#include <stdexcept>

class CalculatorException : public std::exception {

    std::string _msg_error;

protected:

    CalculatorException() = default;
    explicit CalculatorException(const std::string & msg_error){
        _msg_error = msg_error;
    };

public:

    const char * what() const noexcept {
        return _msg_error.c_str();
    }
};


#endif //UNTITLED3_FACTORYEXCEPTION_H
