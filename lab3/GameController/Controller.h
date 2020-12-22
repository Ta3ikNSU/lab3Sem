//
// Created by Ta3ik on 17.12.2020.
//

#ifndef LAB3_CONTROLLER_H
#define LAB3_CONTROLLER_H

#include "../GameFiles/GameModel.h"

class Controller {
public:
    void updateRequest(std::pair<int, int> move, GameModel *model, char sign);

};


#endif //LAB3_CONTROLLER_H
