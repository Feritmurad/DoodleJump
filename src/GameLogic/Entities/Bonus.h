//
// Created by ferit on 1/1/22.
//

#ifndef JUMPGAME_BONUS_H
#define JUMPGAME_BONUS_H
#include "Object.h"

namespace jumpgame {

    class Bonus : public Object {

    private:

        bool m_used;

    public:

        explicit Bonus(const Coordinate &c, const double &height=0.5, const double &width=0.5) : Object(c, height, width),m_used(false) {}

        ~Bonus() = default;

        bool isMUsed() const;

        void update() override;

        void setMUsed(bool mUsed);

        virtual event bonustype();
    };

}


#endif //JUMPGAME_BONUS_H
