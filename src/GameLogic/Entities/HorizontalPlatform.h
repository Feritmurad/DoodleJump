//
// Created by ferit on 12/23/21.
//

#ifndef JUMPGAME_HORIZONTALPLATFORM_H
#define JUMPGAME_HORIZONTALPLATFORM_H
#include "Platform.h"

namespace DoodleJump {

class HorizontalPlatform : public Platform
{

public:
        /**
         * Constructor
         * @param c: coordinate of the object
         * @param Xvelocity: horizontal velocity
         * @param height: Height of the object
         * @param width: Width of the object
         * @param jumped: indicates if the player has jumped on this platform before
         */
        explicit HorizontalPlatform(const Coordinate& c, const double& Xvelocity = 0.05, const double& height = 0.4,
                                    const double& width = 1, const bool& jumped = false)
            : Platform(c, height, width, jumped), m_velocity_X(Xvelocity)
        {
        }

        /**
         * Default destructor
         */
        ~HorizontalPlatform() override = default;

        /**
         * Update the object and notify observers
         */
        void update() override;

        /**
         * Moves the horizontal platform
         */
        void move();

        /**
         * virtual function that updates score
         */
        void updateScore() override;

private:
        double m_velocity_X;
};

} // namespace DoodleJump

#endif // JUMPGAME_HORIZONTALPLATFORM_H
