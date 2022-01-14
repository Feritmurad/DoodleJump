//
// Created by ferit on 15/12/2020.
//

#ifndef GAME_TRANSFORMATION_H
#define GAME_TRANSFORMATION_H
#include "../Coordinate/Coordinate.h"
#include "../Entities/World.h"

namespace DoodleJump {

class Camera
{
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
         * Simple constructor
         * @param world: World with all its entities
         */
        explicit Camera(const std::shared_ptr<World>& world) : m_world(world) {}

        /**
         * Transforms coordinates to pixels
         * @param coordinate: coordinates of entity that will be rescaled
         */
        Coordinate rescale(Coordinate coordinate);

        /**
         * Makes sure the camera follows the player when the player reaches new height
         */
        void moveForward();
};

} // namespace DoodleJump

#endif // GAME_TRANSFORMATION_H
