//
// Created by ferit on 15/12/2020.
//

#ifndef GAME_TRANSFORMATION_H
#define GAME_TRANSFORMATION_H
#include "../../GameLogic/Coordinate/Coordinate.h"

namespace SFMLjumpgame {

    class Camera {
    private:
        int res_x = 0;
        int res_y = 0;
        /**
         * Stored instance
         */
        static Camera *instance;

        /**
         * Private constructor
         */
        Camera() = default;

    public:
        /**
         * Static access method
         */
        static Camera *getInstance();

        /**
         * Delete copy constructor
         */
        Camera(const Camera &obj) = delete;

        /**
         * Delete copy assignment
         */
        Camera &operator=(const Camera &) = delete;

        /**
         *
         */
        jumpgame::Coordinate rescale(jumpgame::Coordinate coordinate);

    };

}

#endif //GAME_TRANSFORMATION_H
