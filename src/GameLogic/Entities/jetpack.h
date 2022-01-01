//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_JETPACK_H
#define JUMPGAME_JETPACK_H
#include "Bonus.h"
#include "iostream"

namespace jumpgame {

    class Jetpack : public Bonus {
    public:
        explicit Jetpack(const Coordinate &c, const double &height = 0.2, const double &width = 0.2) : Bonus(c, height, width) {}

        ~Jetpack() = default;

        void update() override;

        event bonustype() override;



    };
}

#endif //JUMPGAME_JETPACK_H
