//
// Created by ferit on 15/12/2020.
//

#ifndef GAME_TRANSFORMATION_H
#define GAME_TRANSFORMATION_H
#include "../Coordinate/Coordinate.h"
#include "../Entities/World.h"

namespace DoodleJump {

    class Camera {
    private:
        int res_x = 700;
        int res_y = 900;
        std::shared_ptr<DoodleJump::World> m_world;

    public:
        /**
         * Default constructor
         */
        Camera() = default;

        /**
         *
         */
         explicit Camera(const std::shared_ptr<World> &world) : m_world(world) {}

        /**
         * function that will make coordinates into pixel
         * @param coordinate: coordinates of entity that will be rescaled
         */
        Coordinate rescale(Coordinate coordinate);

        void moveForward();

    };

}

#endif //GAME_TRANSFORMATION_H
