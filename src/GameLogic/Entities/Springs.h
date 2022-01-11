//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SPRINGS_H
#define JUMPGAME_SPRINGS_H

#include "Bonus.h"

namespace DoodleJump {

    class Springs : public Bonus {
    public:

        /**
         * Simple constructor
         * @param c: coordinate of the object
         * @param height: Height of the object
         * @param width: Width of the object
         */

        explicit Springs(const Coordinate &c, const double &height = 0.5, const double &width = 0.5) : Bonus(c, height, width) {}
        /**
         * Default destructor
         */

        ~Springs() override = default;
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
}
#endif //JUMPGAME_SPRINGS_H
