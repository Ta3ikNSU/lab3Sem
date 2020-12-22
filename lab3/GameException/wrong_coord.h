//
// Created by Ta3ik on 22.12.2020.
//

#ifndef LAB3_WRONG_COORD_H
#define LAB3_WRONG_COORD_H

#include "../GameException/GameException.h"

class wrong_coord : public GameException {
public:
    wrong_coord(const std::string &_msg) : GameException(_msg) {};
};


#endif //LAB3_WRONG_COORD_H
