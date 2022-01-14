//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_JETPACK_H
#define JUMPGAME_JETPACK_H
#include "Bonus.h"
#include "iostream"

namespace DoodleJump {

class Jetpack : public Bonus
{
public:
        /**
         * Simple constructor
         * @param c: coordinate of the object
         * @param height: Height of the object
         * @param width: Width of the object
         */
        explicit Jetpack(const Coordinate& c, const double& height = 0.5, const double& width = 0.5)
            : Bonus(c, height, width)
        {
        }

        /**
         * Default destructor
         */
        ~Jetpack() override = default;

        /**
         * Update the object and notify observers
         */
        void update() override;

        /**
         * virtual function that returns the type of bonus
         * @return @enum event
         */
        event bonustype() override;

        /**
         * virtual function that updates score
         */
        void updateScore() override;
};
} // namespace DoodleJump

#endif // JUMPGAME_JETPACK_H
