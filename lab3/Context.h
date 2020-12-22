//
// Created by Ta3ik on 18.12.2020.
//

#ifndef LAB3_CONTEXT_H
#define LAB3_CONTEXT_H

#include "GameFiles/GameModel.h"
#include "GameController/Controller.h"

class Context {
public:
    GameModel model;
    Controller controller;
    GameObserver observer;
};


#endif //LAB3_CONTEXT_H
