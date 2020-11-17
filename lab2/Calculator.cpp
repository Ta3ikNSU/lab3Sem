//
// Created by Ta3ik on 14.11.2020.
//

#include "Calculator.hpp"
#include "Context.hpp"
#include "IOperation.hpp"
#include "IOperationFactory.hpp"
#include <list>

void Calculator::calculate(std::istream &stream){
    Context context;
    std::string inputLine;
    while(std::getline(stream, inputLine)){

        std::string commandName;
        std::list<std::string> args;
        //parse arg;
        {
            std::size_t index = inputLine.find(' ');
            commandName = inputLine.substr(0,index);
            while(index != std::string::npos){
                std::size_t prevIndex = index;
                index = inputLine.find(' ');
                std::string newArg;
                if(index != std::string::npos) newArg = inputLine.substr(++prevIndex,index);
                else newArg = inputLine.substr(++prevIndex);
                args.push_back(newArg);
            }
        }
        IOperation* operation = IOperationFactory::getSample().getOperation(commandName);
        operation->execute(args, context);
        delete operation;
    }
}