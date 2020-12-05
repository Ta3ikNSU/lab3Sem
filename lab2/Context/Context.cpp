//
// Created by Ta3ik on 03.12.2020.
//

#include "Context.h"

#include "../Exceptions/const_error.h"
int Context::stackSize() noexcept {
    return stack.size();
}

double Context::top() noexcept {
    return(stack.top());
}

double Context::pop() noexcept {
    double temp = stack.top();
    stack.pop();
    return(temp);
}

void Context::pushStack(double & el) noexcept {
    stack.push(el);
}

void Context::pushConst(std::string & name, double &el) noexcept {
    vars[name] = el;
}


double Context::getConst(std::string & name) {
    auto it = vars.find(name);
    if(it!=vars.end())
        throw const_error("const not found");
    else return it->second;
}

