//
// Created by Ta3ik on 14.11.2020.
//

#include "Context.hpp"

int Context::stackSize() {
    return stack.size();
}

double Context::top() {
    return(stack.top());
}

void Context::pop() {
    stack.pop();
}

void Context::pushStack(double & el) {
    stack.push(el);
}

void Context::pushConst(std::string & name, double &el) {
    vars[name] = el;
}

bool Context::checkConst(std::string &name) {
    auto it = vars.find(name);
    if(it!=vars.end()) return true;
    return false;
}

bool Context::getConst(std::string & name) {
    auto it = vars.find(name);
    return it->second;
}
