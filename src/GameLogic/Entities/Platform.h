//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_PLATFORM_H
#define JUMPGAME_PLATFORM_H
#include "Object.h"
#include "Bonus.h"
#include "iostream"

namespace jumpgame {

    class Platform : public Object{
    public:
        explicit Platform(const Coordinate &c,const double &height=0.4,const double &width=1, const bool &jumped = false) : Object(c,height,width) , m_jumpedOn(jumped), m_bonus(nullptr){}

        ~Platform() = default;

        void update() override;


        bool isMJumpedOn() const;

        void setMJumpedOn(bool mJumpedOn);

        const std::shared_ptr<Bonus> &getMBonus() const;

        void setMBonus(const std::shared_ptr<Bonus> &mBonus);

    private:
        bool m_jumpedOn;

        std::shared_ptr<Bonus> m_bonus;


    };

}


#endif //JUMPGAME_PLATFORM_H
