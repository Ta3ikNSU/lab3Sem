//
// Created by Ta3ik on 14.11.2020.
//

#ifndef LAB3_IOPERATIONFACTORY_HPP
#define LAB3_IOPERATIONFACTORY_HPP
#include "IOperation.hpp"
#include "Plus.hpp"
#include "Minus.hpp"
#include "Multiplication.hpp"
#include "Division.hpp"
#include "Print.hpp"
#include "Define.hpp"
#include "Push.hpp"
#include "Pop.hpp"

class IOperationFactory {
    IOperationFactory() = default;

public:
    IOperationFactory(const IOperationFactory&) = delete;

    static IOperationFactory& getSample();

    IOperation * getOperation(const std::string & name) const;
};


#endif //LAB3_IOPERATIONFACTORY_HPP
