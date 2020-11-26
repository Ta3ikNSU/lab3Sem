//
// Created by Ta3ik on 14.11.2020.
//

#ifndef LAB3_IOPERATIONFACTORY_HPP
#define LAB3_IOPERATIONFACTORY_HPP
#include "IOperation.hpp"
#include "IOperationMaker.hpp"

class OperationFactory {
    OperationFactory() = default;
    std::map<std::string, IOperationMaker* > makers;

public:
    OperationFactory(const OperationFactory&) = delete;

    static OperationFactory& getSample();

    IOperation * getOperation(const std::string & name) const;

    void RegisterMaker(const std::string & name, IOperationMaker * maker);
};


#endif //LAB3_IOPERATIONFACTORY_HPP
