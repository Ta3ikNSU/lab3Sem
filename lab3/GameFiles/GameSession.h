//
// Created by Ta3ik on 18.12.2020.
//

#ifndef LAB3_GAMESESSION_H
#define LAB3_GAMESESSION_H

#include "../Context.h"
#include "../Players/Player.h"
#include "../Players/HumanPlayer.h"
#include "../Players/Bot.h"
#include "../GameFiles/GameField.h"
#include <memory>

class GameSession {
    Context ctx;

    std::shared_ptr<Player> defineTypePlayer();

public:
    void startGame();
};


#endif //LAB3_GAMESESSION_H
