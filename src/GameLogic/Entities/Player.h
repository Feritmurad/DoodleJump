//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include "Object.h"

namespace jumpgame {

    class Player : public Object {
        public:
            /**
             * Constructior with coordinate
             * @param c: coordinate of object
             */
            Player(const Coordinate &c) : Object(c) {}

    };
}


#endif //GAME_PLAYER_H
