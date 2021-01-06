//
// Created by Ta3ik on 08.12.2020.
//

#ifndef LAB3_PLAYER_H
#define LAB3_PLAYER_H

#include <utility>
#include <iostream>
#include "../GameFiles/GameModel.h"

class GameModel;

class Player {
protected:
    char sign;
public:
    void setSign(char newSign) {
        sign = newSign;
    }

    char getSign() {
        return (sign);
    }

    virtual std::pair<int, int> move(GameModel &model) = 0;
};


#endif //LAB3_PLAYER_H
