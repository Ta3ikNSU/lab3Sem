//
// Created by Ta3ik on 18.12.2020.
//

#include "../GameFiles/GameModel.h"
#include "../GameException/empty_cell.h"
#include "../GameException/wrong_coord.h"
GameField &GameModel::getField() {
    return field;
}

GameStatus GameModel::getGameStatus() {
    return curGameStatus.status;
}

void GameModel::addObserver(GameObserver newObserver) {
    observers.push_back(newObserver);
}

void GameModel::setCellStatus(std::pair<int, int> move, CellStatus newStatus) {
    if(move.first >= sizeField || move.second>=sizeField){
        throw wrong_coord("Cord is wrong. Try again");
    }
    if (field.getCellStatus(move) != CellStatus::Empty) {
        throw empty_cell("Cell not empty");
    } else {
        field.setCellStatus(move.first, move.second, newStatus);
    }
}

void GameModel::setCellStatus(int x, int y, CellStatus newStatus) {
    if(x >= sizeField || y>=sizeField){
        throw wrong_coord("Cord is wrong. Try again");
    }
    if (field.getCellStatus(x, y) != CellStatus::Empty) {
        throw empty_cell("Cell not empty");
    } else {
        field.setCellStatus(x, y, newStatus);
    }
}

CellStatus GameModel::getCellStatus(std::pair<int, int> move) {
    if(move.first >= sizeField || move.second>=sizeField){
        throw wrong_coord("Cord is wrong. Try again");
    }
    return field.getCellStatus(move.first, move.second);
}

CellStatus GameModel::getCellStatus(int x, int y) {
    if(x >= sizeField || y>=sizeField){
        throw wrong_coord("Cord is wrong. Try again");
    }
    return field.getCellStatus(x, y);
}


void GameModel::notify() {
    for (GameObserver observer: observers) {
        observer.printField(this);
    }
    gameAnalysis();
}


void GameModel::gameAnalysis() {
    checkDiagonal();
    if (curGameStatus.status == GameStatus::IN_PROCESS) {
        for (int i = 0; i < sizeField; i++) {
            checkLine(i);
            checkRow(i);
            if (curGameStatus.status != GameStatus::IN_PROCESS) break;
        }
    }
    if (checkDraw()) curGameStatus.status = GameStatus::DRAW;
}

void GameModel::checkLine(int index) {
    if ((field.getCellStatus(index, 0) == CellStatus::Cross) &&
        (field.getCellStatus(index, 1) == CellStatus::Cross) &&
        (field.getCellStatus(index, 2) == CellStatus::Cross))
        curGameStatus.status = GameStatus::x_WIN;
    if ((field.getCellStatus(index, 0) == CellStatus::Zero) &&
        (field.getCellStatus(index, 1) == CellStatus::Zero) &&
        (field.getCellStatus(index, 2) == CellStatus::Zero))
        curGameStatus.status = GameStatus::o_WIN;
}

void GameModel::checkRow(int index) {
    if ((field.getCellStatus(0, index) == CellStatus::Cross) &&
        (field.getCellStatus(1, index) == CellStatus::Cross) &&
        (field.getCellStatus(2, index) == CellStatus::Cross))
        curGameStatus.status = GameStatus::x_WIN;
    if ((field.getCellStatus(0, index) == CellStatus::Zero) &&
        (field.getCellStatus(1, index) == CellStatus::Zero) &&
        (field.getCellStatus(2, index) == CellStatus::Zero))
        curGameStatus.status = GameStatus::o_WIN;
}

void GameModel::checkDiagonal() {
    if ((field.getCellStatus(0, 0) == CellStatus::Cross) &&
        (field.getCellStatus(1, 1) == CellStatus::Cross) &&
        (field.getCellStatus(2, 2) == CellStatus::Cross))
        curGameStatus.status = GameStatus::x_WIN;
    if ((field.getCellStatus(0, 2) == CellStatus::Cross) &&
        (field.getCellStatus(1, 1) == CellStatus::Cross) &&
        (field.getCellStatus(2, 0) == CellStatus::Cross))
        curGameStatus.status = GameStatus::x_WIN;
    if ((field.getCellStatus(0, 2) == CellStatus::Zero) &&
        (field.getCellStatus(1, 1) == CellStatus::Zero) &&
        (field.getCellStatus(2, 0) == CellStatus::Zero))
        curGameStatus.status = GameStatus::o_WIN;
    if ((field.getCellStatus(0, 0) == CellStatus::Zero) &&
        (field.getCellStatus(1, 1) == CellStatus::Zero) &&
        (field.getCellStatus(2, 2) == CellStatus::Zero))
        curGameStatus.status = GameStatus::o_WIN;
}

bool GameModel::checkDraw() {
    for (int i = 0; i < sizeField; i++) {
        for (int j = 0; j < sizeField; j++) {
            if (field.getCellStatus(i, j) == CellStatus::Empty) {
                return false;
            }
        }
    }
    return true;
}

GameModel::GameModel() {
    curGameStatus.status = GameStatus::IN_PROCESS;
}

void GameModel::addPlayer(char sign, std::shared_ptr<Player> newPlayer) {
    Players[sign] = newPlayer;
}

moveStatus GameModel::doMove(char playersSign) {
    std::pair<int, int> curMove;
    curMove = Players[playersSign]->move(*this);
    CellStatus newStatus;
    if (playersSign == 'x') newStatus = CellStatus::Cross;
    else newStatus = CellStatus::Zero;
    try {
        this->setCellStatus(curMove, newStatus);
        this->notify();
        return MOVE_IS_CORRECT;
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return MOVE_IS_WRONG;
    }
}



