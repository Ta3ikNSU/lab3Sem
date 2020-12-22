//
// Created by Ta3ik on 22.12.2020.
//

#ifndef LAB3_EMPTY_CELL_H
#define LAB3_EMPTY_CELL_H

#include "../GameException/GameException.h"

class empty_cell : public GameException{
public:
    empty_cell(const std::string &_msg) : GameException(_msg) {};
};


#endif //LAB3_EMPTY_CELL_H
