//
// Created by Ta3ik on 14.11.2020.
//

#ifndef LAB3_CONTEXT_HPP
#define LAB3_CONTEXT_HPP
#include <string>
#include <map>
#include <stack>

class Context {
    std::stack<double> stack;
    std::map<std::string, double> vars;
public:
    Context() = default;
    int stackSize();
    double top();
    void pop();
    void pushStack(double & el);
    void pushConst(std::string & name, double & el);
    bool checkConst(std::string & name);

    bool getConst(std::string &name);
};


#endif //LAB3_CONTEXT_HPP
