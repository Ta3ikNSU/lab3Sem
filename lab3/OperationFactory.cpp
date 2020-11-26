//
// Created by Ta3ik on 14.11.2020.
//

#include "OperationFactory.hpp"

OperationFactory& OperationFactory::getSample() {
    static OperationFactory factory;
    return factory;
}

IOperation * OperationFactory::getOperation(const std::string & name) const{
    auto i = makers.find(name);
    if (i == makers.end())
    {
        throw new std::logic_error("Unrecognized object type!");
    }
    IOperationMaker* maker = i->second;
    return maker->create();
}

void OperationFactory::RegisterMaker(const std::string &name, IOperationMaker *maker) {
    if (makers.find(name) != makers.end())
    {
        throw new std::logic_error("Multiple makers for given key!");
    }
    makers[name] = maker;
}
