# cmake_minimum_required(VERSION <specify CMake version here>)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp
        GameFiles/GameModel.h GameFiles/GameModel.cpp
        GameFiles/GameField.h GameFiles/GameField.cpp
        GameFiles/GameObserver.h GameFiles/GameObserver.cpp
        GameFiles/GameSession.h GameFiles/GameSession.cpp
        Players/Bot.cpp Players/Bot.h
        Players/HumanPlayer.h Players/HumanPlayer.cpp
        Players/Player.h
        Context.h GameException/GameException.h GameException/empty_cell.h GameException/wrong_coord.h)