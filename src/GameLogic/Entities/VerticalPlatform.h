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

        explicit VerticalPlatform(const Coordinate &c,const double &Yvelocity = -0.1, const double &height = 0.4, const double &width = 1,
                                    const bool &jumped = false);

        void update() override;

        void move();

        double getMMinH() const;

        void updateMMinH(double mMinH);

        double getMMaxH() const;

        void updateMMaxH(double mMaxH);

    private:
        double m_velocity_Y;
        double m_minH;
        double m_maxH;



    };

}


#endif //JUMPGAME_VERTICALPLATFORM_H
