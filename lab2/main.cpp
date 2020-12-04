#include <iostream>
#include <istream>
#include "Calculator/Calculator.h"

int main(const int argc, const char **argv) {
    Calculator clk;
    if (argc > 1) {
        std::ifstream fin;
        fin.open(argv[1]);
        //if(!fin.is_open())
        std::istream &input = fin;
        std::cout << clk.calculate(input);
    } else {
        std::cout << clk.calculate(std::cin);
    }
}
