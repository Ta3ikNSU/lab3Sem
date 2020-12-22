//
// Created by Ta3ik on 22.12.2020.
//

#ifndef LAB3_GAMEEXCEPTION_H
#define LAB3_GAMEEXCEPTION_H

#include <string>
#include <stdexcept>

class GameException : public std::exception {

    std::string _msg_error;

protected:

    GameException() = default;

    explicit GameException(const std::string &msg_error) {
        _msg_error = msg_error;
    };

public:

    const char *what() const noexcept {
        return _msg_error.c_str();
    }
};


#endif //LAB3_GAMEEXCEPTION_H
