//
// Created by Ta3ik on 08.12.2020.
//

#include "HumanPlayer.h"

std::pair<int, int> HumanPlayer::move(GameModel &model) {
    std::pair<int, int> curMove;
    std::cin >> curMove.first >> curMove.second;
    curMove.first--;
    curMove.second--;
    return curMove;
}