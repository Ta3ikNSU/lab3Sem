//
// Created by Ta3ik on 04.12.2020.
//
#include <memory>

#include "Calculator.h"


Calculator::Calculator() {
    Context context;
}

double Calculator::calculate(std::istream &stream) {
    std::string inputLine;
    while(std::getline(stream, inputLine)){
        std::string commandName;
        std::list<std::string> args;
        //parse arg;
        {
            std::size_t index = inputLine.find(' ');
            commandName = inputLine.substr(0,index);
            while(index != std::string::npos){
                inputLine = inputLine.substr(++index, inputLine.length());
                index = inputLine.find(' ');
                std::string newArg;
                if(index != std::string::npos) newArg = inputLine.substr(0,index);
                else newArg = inputLine.substr(0);
                if(newArg != "") args.push_back(newArg);
            }
        }
        try {
            std::unique_ptr<IOperation> operation(OperationFactory::getInstance().create(commandName));
            operation->execute(args, context);
        } catch (const std::exception &ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
    return context.top();
}

