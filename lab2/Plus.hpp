//
// Created by Ta3ik on 15.11.2020.
//

#ifndef LAB3_PLUS_HPP
#define LAB3_PLUS_HPP

#include "IOperation.hpp"
#include "Error.hpp"

class Plus : public IOperation  {
public:
    void execute(const std::list<std::string> &args, Context context);
};


#endif //LAB3_PLUS_HPP
