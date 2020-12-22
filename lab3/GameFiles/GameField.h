//
// Created by Ta3ik on 08.12.2020.
//

#ifndef LAB3_GAMEFIELD_H
#define LAB3_GAMEFIELD_H

#include <vector>
#include <exception>

#define sizeField 3

enum class CellStatus {
    Empty,
    Zero,
    Cross
};

struct Cell {
    CellStatus status;
};

class GameField {
    std::vector<std::vector<Cell>> field;

public:
    GameField();

    CellStatus getCellStatus(std::pair<int, int> move);

    CellStatus getCellStatus(int x, int y);

    void setCellStatus(int x, int y, CellStatus newStatus);

    void setCellStatus(std::pair<int, int> move, CellStatus newStatus);

};


#endif //LAB3_GAMEFIELD_H
