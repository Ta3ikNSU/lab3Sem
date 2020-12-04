//
// Created by Ta3ik on 04.12.2020.
//

#ifndef UNTITLED5_CALCULATOR_H
#define UNTITLED5_CALCULATOR_H

#include "../Context/Context.h"

#include "../Factory/OperationFactory.h"
#include "../Factory/OperationMaker.h"

#include "../Interface/IOperation.h"
#include "../Interface/IOperationMaker.h"

#include <iostream>
#include <fstream>

class Calculator {
public:
    Calculator ();
    double calculate (std::istream& stream);
private:
    Context context;
};


#endif //UNTITLED5_CALCULATOR_H
