//
// Created by ferit on 15/12/2020.
//

#ifndef GAME_TRANSFORMATION_H
#define GAME_TRANSFORMATION_H
#include "../../GameLogic/Coordinate/Coordinate.h"

namespace SFMLjumpgame {

    class Camera {
    private:
        int res_x = 1280;
        int res_y = 720;

    public:
        /**
         * Default constructor
         */
        Camera() = default;

        /**
         * function that will make coordinates into pixel
         * @param coordinate: coordinates of entity that will be rescaled
         */
        jumpgame::Coordinate rescale(jumpgame::Coordinate coordinate);

    };

}

#endif //GAME_TRANSFORMATION_H
