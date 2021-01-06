//
// Created by Ta3ik on 18.12.2020.
//

#include "GameObserver.h"

void GameObserver::printField(GameModel * model) {
    GameField field = model->getField();
    for (int i = 0; i < 3; i++) {
        std::cout << "-------------" << std::endl << "|";
        for (int j = 0; j < 3; j++) {
            CellStatus curStatus = field.getCellStatus(i, j);
            {
                if (curStatus == CellStatus::Zero) {
                    std::cout << " 0 |";
                } else {
                    if (curStatus == CellStatus::Cross) {
                        std::cout << " x |";
                    } else {
                        std::cout << "   |";
                    }
                }
            }

        }
        std::cout<<std::endl;
    }
    std::cout << "-------------";
    for(int i = 0; i < 5; i++){
        std::cout << std::endl;
    }
}

void GameObserver::analyzer(GameModel &model) {
    if (model.getGameStatus() == GameStatus::x_WIN) {
        std::cout << "x - win \n GG";
    } else {
        if (model.getGameStatus() == GameStatus::o_WIN) {
            std::cout << "0 - win \n GG";
        } else {
            std::cout << "Draw";
        }
    }
}
