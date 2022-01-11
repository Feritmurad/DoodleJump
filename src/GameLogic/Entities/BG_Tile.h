//
// Created by ferit on 1/2/22.
//

#ifndef JUMPGAME_BG_TILE_H
#define JUMPGAME_BG_TILE_H
#include "Object.h"
#include "Bonus.h"
#include "iostream"

namespace DoodleJump {

    class BG_Tile : public Object {

    public:
        /**
         * Simple constructor
         * @param c: coordinate of the object
         * @param height: Height of the object
         * @param width: Width of the object
         */
        explicit BG_Tile(const Coordinate &c, const double &height = 9, const double &width = 7) : Object(c, height, width) {}

        /**
         * Default destructor
         */
        ~BG_Tile() override = default;

        /**
         * Update the object and notify observers
         */
        void update() override;
    };
}


#endif //JUMPGAME_BG_TILE_H
