//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_PLATFORM_H
#define JUMPGAME_PLATFORM_H
#include "Object.h"

namespace jumpgame {

    class Platform : public Object{
    public:
        explicit Platform(const Coordinate &c) : Object(c) {}

        ~Platform() = default;

        void update() override;


    };

}


#endif //JUMPGAME_PLATFORM_H
