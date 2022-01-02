//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SPRINGS_H
#define JUMPGAME_SPRINGS_H

#include "Bonus.h"

namespace jumpgame {

    class Springs : public Bonus {
    public:
        explicit Springs(const Coordinate &c, const double &height = 0.5, const double &width = 0.5) : Bonus(c, height, width) {}

        ~Springs() = default;

        void update() override;

        event bonustype() override;



    private:


    };
}
#endif //JUMPGAME_SPRINGS_H
