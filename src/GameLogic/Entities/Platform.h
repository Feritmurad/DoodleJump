//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_PLATFORM_H
#define JUMPGAME_PLATFORM_H
#include "Object.h"

namespace jumpgame {

    class Platform : public Object{
    public:
        explicit Platform(const Coordinate &c,const double &height=0.4,const double &width=1.2, const bool &jumped = false) : Object(c,height,width) , m_jumpedOn(jumped){}

        ~Platform() = default;

        void update() override;

        bool checkValid();

        bool isMJumpedOn() const;

        void setMJumpedOn(bool mJumpedOn);

    private:
        bool m_jumpedOn;

    };

}


#endif //JUMPGAME_PLATFORM_H
