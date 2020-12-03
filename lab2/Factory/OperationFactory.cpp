//
// Created by Ta3ik on 03.12.2020.
//

#include "OperationFactory.h"

#include "../Exceptions/FactoryException.h"

OperationFactory &OperationFactory::getInstance() {
    static OperationFactory factory;
    return factory;
}

IOperation *OperationFactory::create(const std::string &operationName) const {
    auto i = _makers.find(operationName);
    if (i == _makers.end()) {
        throw std::logic_error("unknown operation name");
    }
    IOperationMaker *maker = i->second;
    return (maker->create(operationName));
}

void OperationFactory::RegisterMaker(const std::string &operationName, IOperationMaker *maker) {
    if (_makers.find(operationName) != _makers.end()) {
        throw std::logic_error("Block already exists" + operationName);
    }
    _makers[operationName] = maker;
}

OperationFactory::OperationFactory() = default;