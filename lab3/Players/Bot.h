//
// Created by Ta3ik on 08.12.2020.
//

#ifndef LAB3_BOT_H
#define LAB3_BOT_H

#include "Player.h"

class Bot : public Player {
public:
    Bot() = default;

    std::pair<int, int> move(GameModel &model) override;
};


#endif //LAB3_BOT_H
