//
// Created by Ta3ik on 03.12.2020.
//

#include "OperationFactory.h"

#include "../Exceptions/const_error.h"
#include "../Exceptions/arg_command_error.h"
#include "../Exceptions/operation_error.h"
#include "../Exceptions/stack_error.h"

OperationFactory &OperationFactory::getInstance() noexcept {
    static OperationFactory factory;
    return factory;
}

IOperation *OperationFactory::create(const std::string &operationName) const {
    auto i = _makers.find(operationName);
    if (i == _makers.end()) {
        throw operation_error("unknown operation name");
    }
    IOperationMaker *maker = i->second;
    return (maker->create(operationName));
}

void OperationFactory::RegisterMaker(const std::string &operationName, IOperationMaker *maker) {
    if (_makers.find(operationName) != _makers.end()) {
        throw operation_error("Operation already exists" + operationName);
    }
    _makers[operationName] = maker;
}

OperationFactory::OperationFactory() = default;