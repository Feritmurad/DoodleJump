//
// Created by ferit on 12/23/21.
//

#ifndef JUMPGAME_VERTICALPLATFORM_H
#define JUMPGAME_VERTICALPLATFORM_H
#include "Platform.h"
#include "iostream"


namespace jumpgame {

    class VerticalPlatform : public Platform {

    public:

        explicit VerticalPlatform(const Coordinate &c,const double &Yvelocity = 0.2, const double &height = 0.4, const double &width = 1.2,
                                    const bool &jumped = false) : Platform(c, height, width, jumped) , m_velocity_Y(Yvelocity) {}

        void update() override;

        void move();

    private:
        double m_velocity_Y;
        const double m_minH = -3.0;
        const double m_maxH = 3.0;



    };

}


#endif //JUMPGAME_VERTICALPLATFORM_H
