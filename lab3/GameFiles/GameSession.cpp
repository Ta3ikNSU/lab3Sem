//
// Created by Ta3ik on 18.12.2020.
//

#include "GameSession.h"
#include <map>

std::shared_ptr<Player> GameSession::defineTypePlayer(char sign) {
    std::shared_ptr<Player> Player;
    std::string input;
    bool undefinedType = true;
    std::cout << "Human or Bot?" << std::endl;
    while (undefinedType) {
        std::getline(std::cin, input);
        if (input == "BOT" || input == "Bot" || input == "bot") {
            Player = std::make_shared<Bot>();
            undefinedType = false;
        } else {
            if (input == "HUMAN" || input == "Human" || input == "human") {
                Player = std::make_shared<HumanPlayer>();
                undefinedType = false;
            } else {
                std::cout << "Unknown player type. Try again" << std::endl;
            }
        }
    }
    Player->setSign(sign);
    return Player;
}

void GameSession::startGame() {
    std::cout << "Enter the type of player who will play with the cross" << std::endl;
    ctx.model.addPlayer('x',defineTypePlayer('x'));
    std::cout << "Enter the type of player who will play with the zero" << std::endl;
    ctx.model.addPlayer('o',defineTypePlayer('o'));

    ctx.model.addObserver(ctx.observer);
    char curSign = 'x';

    while (ctx.model.getGameStatus() == GameStatus::IN_PROCESS) {
        std::cout << "Now " << curSign << std::endl;
        moveStatus rc = ctx.model.doMove(curSign);
        while(MOVE_IS_CORRECT != rc){
            rc = ctx.model.doMove(curSign);
        }
        if (curSign == 'x') curSign = 'o';
        else curSign = 'x';
    }
    ctx.observer.analyzer(ctx.model);
}