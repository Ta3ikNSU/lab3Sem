//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED5_CONTEXT_H
#define UNTITLED5_CONTEXT_H

#include <string>
#include <map>
#include <stack>

class Context {

private:

    std::stack<double> stack;

    std::map<std::string, double> vars;

public:

    Context() = default;

    int stackSize() noexcept;

    double top() noexcept;

    double pop() noexcept;

    void pushStack(double & el) noexcept;

    void pushConst(std::string & name, double & el) noexcept;

    double getConst(std::string &name) ;

};

#endif //UNTITLED5_CONTEXT_H
