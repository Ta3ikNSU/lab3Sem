//
// Created by Ta3ik on 19.12.2020.
//

#ifndef LAB3_GAMEOBSERVER_H
#define LAB3_GAMEOBSERVER_H


#include "../GameFiles/GameModel.h"
#include <iostream>

class GameModel;

class GameObserver {
public:
    void printField(GameModel *model);
    void analyzer(GameModel &model);
};


#endif //LAB3_GAMEOBSERVER_H
