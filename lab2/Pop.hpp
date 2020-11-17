//
// Created by Ta3ik on 15.11.2020.
//

#ifndef LAB3_POP_HPP
#define LAB3_POP_HPP
#include "IOperation.hpp"
#include "Error.hpp"

class Pop : public IOperation  {
public:
    void execute(const std::list<std::string> &args, Context context);
};


#endif //LAB3_POP_HPP
