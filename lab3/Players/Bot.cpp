//
// Created by Ta3ik on 08.12.2020.
//

#include "Bot.h"


std::pair<int, int> Bot::move(GameModel &model) {
    std::pair<int, int> curMove;
    for (int i = 0; i < sizeField; i++) {
        for (int j = 0; j < sizeField; j++) {
            if (model.getCellStatus(i, j) == CellStatus::Empty) {
                return {i, j};
            }
        }
    }
    return curMove;
}