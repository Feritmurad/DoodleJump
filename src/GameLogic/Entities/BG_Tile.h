//
// Created by ferit on 1/2/22.
//

#ifndef JUMPGAME_BG_TILE_H
#define JUMPGAME_BG_TILE_H
#include "Object.h"
#include "Bonus.h"
#include "iostream"

namespace jumpgame {

    class BG_Tile : public Object {
    public:
        explicit BG_Tile(const Coordinate &c, const double &height = 9, const double &width = 7) : Object(c, height, width) {}

        ~BG_Tile() = default;

        void update() override;
    };
}


#endif //JUMPGAME_BG_TILE_H
