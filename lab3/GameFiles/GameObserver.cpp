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
