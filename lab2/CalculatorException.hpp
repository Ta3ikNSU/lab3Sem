//
// Created by Ta3ik on 15.11.2020.
//

#ifndef LAB3_CALCULATOREXCEPTION_HPP
#define LAB3_CALCULATOREXCEPTION_HPP
#include <stdexcept>
#include <string>

class CalculatorException : public std::exception {

    std::string _msg_error;

protected:

    explicit CalculatorException(const std::string & msg_error){
        _msg_error = msg_error;
    };

public:
    CalculatorException() = default;

    const char * what() const noexcept override {
        return _msg_error.c_str();
    }
};


#endif //LAB3_CALCULATOREXCEPTION_HPP
