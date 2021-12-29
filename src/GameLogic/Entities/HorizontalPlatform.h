//
// Created by ferit on 12/23/21.
//

#ifndef JUMPGAME_HORIZONTALPLATFORM_H
#define JUMPGAME_HORIZONTALPLATFORM_H
#include "Platform.h"

namespace jumpgame {

    class HorizontalPlatform : public Platform {

    public:

        explicit HorizontalPlatform(const Coordinate &c,const double &Xvelocity = 0.05, const double &height = 0.4, const double &width = 1,
                              const bool &jumped = false) : Platform(c, height, width, jumped) , m_velocity_X(Xvelocity) {}

        void update() override;

        void move();

    private:
        double m_velocity_X;


    };

}


#endif //JUMPGAME_HORIZONTALPLATFORM_H
