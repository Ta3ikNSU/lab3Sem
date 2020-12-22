#ifndef LAB3_GAMEMODEL_H
#define LAB3_GAMEMODEL_H

#include "../GameFiles/GameObserver.h"
#include "../GameFiles/GameField.h"
#include <list>

class GameObserver;

enum class GameStatus {
    IN_PROCESS,
    x_WIN,
    o_WIN,
    DRAW
};

struct Status {
    GameStatus status;
};

class GameModel {
    GameField field;

    void gameAnalysis();

    void checkLine(int index);

    void checkRow(int index);

    void checkDiagonal();

    bool checkDraw();

public:
    Status curGameStatus;
    std::list<GameObserver> observers;

    GameStatus getGameStatus();

    GameField &getField();

    void update();

    void addObserver(GameObserver newObserver);

    void setCellStatus(std::pair<int, int> move, CellStatus newStatus);

    CellStatus getCellStatus(std::pair<int, int> move);

    void setCellStatus(int x, int y, CellStatus newStatus);

    CellStatus getCellStatus(int x, int y);

};

#endif //LAB3_GAMEMODEL_H
