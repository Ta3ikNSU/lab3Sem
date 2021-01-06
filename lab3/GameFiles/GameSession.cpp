//
// Created by Ta3ik on 18.12.2020.
//

#include "GameSession.h"
#include <map>

std::shared_ptr<Player> GameSession::defineTypePlayer() {
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
    return Player;
}

void GameSession::startGame() {
    std::map<char, std::shared_ptr<Player>> Players;
    std::cout << "Enter the type of player who will play with the cross" << std::endl;
    Players['x'] = defineTypePlayer();
    Players['x']->setSign('x');
    std::cout << "Enter the type of player who will play with the zero" << std::endl;
    Players['o'] = defineTypePlayer();
    Players['o']->setSign('o');


    ctx.model.addObserver(ctx.observer);
    std::shared_ptr<Player> curPlayer = Players['x'];

    while (ctx.model.getGameStatus() == GameStatus::IN_PROCESS) {
        std::pair<int, int> curMove;
        std::cout << "Now " << curPlayer->getSign() << std::endl;
        curMove = curPlayer->move(ctx.model);
        ctx.controller.updateRequest(curMove, &ctx.model, curPlayer->getSign());
        if (curPlayer->getSign() == 'x') curPlayer = Players['o'];
        else curPlayer = Players['x'];
    }
    if (ctx.model.getGameStatus() == GameStatus::x_WIN) {
        std::cout << "x - win \n GG";
    } else {
        if (ctx.model.getGameStatus() == GameStatus::o_WIN) {
            std::cout << "0 - win \n GG";
        } else {
            std::cout << "Draw";
        }
    }
}