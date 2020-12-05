//
// Created by Ta3ik on 03.12.2020.
//

#ifndef UNTITLED3_OPERATIONFACTORY_H
#define UNTITLED3_OPERATIONFACTORY_H

#include "../Interface/IOperation.h"
#include "../Interface/IOperationMaker.h"
#include <map>

class OperationFactory {
public:
    static OperationFactory &getInstance() noexcept;

    IOperation *create(const std::string &operationName) const;

    void RegisterMaker(const std::string &operationName, IOperationMaker *maker);

private:
    OperationFactory();
    std::map<std::string, IOperationMaker *> _makers;
};


#endif //UNTITLED3_OPERATIONFACTORY_H
