//
// Created by Ta3ik on 17.12.2020.
//

#include "Controller.h"
#include <stdexcept>

void Controller::updateRequest(std::pair<int, int> move, GameModel *model, char sign) {
    CellStatus newStatus;
    if (sign == 'x') newStatus = CellStatus::Cross;
    else newStatus = CellStatus::Zero;
    try {
        model->setCellStatus(move, newStatus);
        model->update();
    } catch (const std::exception &ex) {

    }
}