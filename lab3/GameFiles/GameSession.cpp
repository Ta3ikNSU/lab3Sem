//
// Created by Ta3ik on 18.12.2020.
//

#include "GameSession.h"


std::shared_ptr<Player> GameSession::defineTypePlayer(char &sign) {
    std::shared_ptr<Player> Player;
    std::string input;
    bool undefinedType = true;
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
    std::cout << "This player will play with " << sign << std::endl;
    std::cout << "Want to change its symbol? Y/N" << std::endl;
    std::getline(std::cin, input);
    if (input == "Y") {
        if (sign == 'x') {
            Player->setSign('o');
        } else {
            Player->setSign('x');
        }
    } else {
        Player->setSign(sign);
        sign = 'o';
    }
    return Player;
}

void GameSession::startGame() {
    std::cout << "Enter type of 1st Player" << std::endl;
    std::cout << "Human or Bot?" << std::endl;
    char freeSign = 'x';
    std::shared_ptr<Player> Player1st = defineTypePlayer(freeSign);
    std::cout << "Enter type of 2nd Player" << std::endl;
    std::cout << "Human or Bot?" << std::endl;
    std::shared_ptr<Player> Player2nd = defineTypePlayer(freeSign);


    ctx.model.addObserver(ctx.observer);
    std::shared_ptr<Player> curPlayer = Player1st;
    while (ctx.model.getGameStatus() == GameStatus::IN_PROCESS) {
        std::pair<int, int> curMove;
        std::cout << "Now " << curPlayer->getSign() << std::endl;
        curMove = curPlayer->move(ctx.model);
        ctx.controller.updateRequest(curMove, &ctx.model, curPlayer->getSign());
        if (curPlayer == Player1st) curPlayer = Player2nd;
        else curPlayer = Player1st;
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