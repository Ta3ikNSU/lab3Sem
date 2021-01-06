#ifndef LAB3_GAMEMODEL_H
#define LAB3_GAMEMODEL_H

#include "../GameFiles/GameObserver.h"
#include "../GameFiles/GameField.h"
#include "../Players/Player.h"
#include <list>
#include <memory>
#include <map>

class GameObserver;
class Player;

enum moveStatus{
    MOVE_IS_CORRECT,
    MOVE_IS_WRONG
};

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

    std::map<char, std::shared_ptr<Player>> Players;

    GameField field;

    void gameAnalysis();

    void checkLine(int index);

    void checkRow(int index);

    void checkDiagonal();

    bool checkDraw();

public:
    GameModel();

    Status curGameStatus;

    std::list<GameObserver> observers;

    GameStatus getGameStatus();

    GameField &getField();

    void notify();

    void addObserver(GameObserver newObserver);

    void setCellStatus(std::pair<int, int> move, CellStatus newStatus);

    CellStatus getCellStatus(std::pair<int, int> move);

    void setCellStatus(int x, int y, CellStatus newStatus);

    CellStatus getCellStatus(int x, int y);

    void addPlayer(char sign, std::shared_ptr<Player> newPlayer);

    moveStatus doMove(char playersSign);
};

#endif //LAB3_GAMEMODEL_H
