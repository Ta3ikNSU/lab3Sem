//
// Created by Ta3ik on 08.12.2020.
//

#ifndef LAB3_HUMANPLAYER_H
#define LAB3_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer() = default;

    std::pair<int, int> move(GameModel &model) override;
};


#endif //LAB3_HUMANPLAYER_H
