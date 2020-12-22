//
// Created by Ta3ik on 08.12.2020.
//

#include "GameField.h"
#include <stdexcept>
#include "../GameException/wrong_coord.h"

GameField::GameField() {
    field.resize(sizeField);
    for(int i = 0; i < sizeField; i++){
        field[i].resize(sizeField);
        for(auto j = 0; j < sizeField; j++){
            field[i][j].status = CellStatus::Empty;
        }
    }
}

CellStatus GameField::getCellStatus(int x, int y) {
    if(x >= sizeField || y>=sizeField){
        throw wrong_coord("Cord is wrong");
    }
    return field[x][y].status;
}

void GameField::setCellStatus(int x, int y, CellStatus newStatus) {
    if(x >= sizeField || y>=sizeField){
        throw wrong_coord("Cord is wrong");
    }
    field[x][y].status = newStatus;
}

CellStatus GameField::getCellStatus(std::pair<int, int> move) {
    if(move.first >= sizeField || move.second>=sizeField){
        throw wrong_coord("Cord is wrong");
    }
    return getCellStatus(move.first, move.second);
}

void GameField::setCellStatus(std::pair<int, int> move, CellStatus newStatus) {
    if(move.first >= sizeField || move.second>=sizeField){
        throw wrong_coord("Cord is wrong");
    }
    setCellStatus(move.first, move.second, newStatus);
}
