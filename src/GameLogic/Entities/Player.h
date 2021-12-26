//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include "Object.h"
#include "iostream"

namespace jumpgame {
    enum VerticalState{Jumping,Falling,Collision,None};
    enum Horizontalstate{Static,Left,Right};

    class Player : public Object {
        public:
            /**
             * Constructior with coordinate
             * @param c: coordinate of object
             */

            explicit Player(const Coordinate &c,const double &reachedheight=0.0,const double &Yvelocity=0.0,const double &Xvelocity=0.0, const double &gravity=0.005,VerticalState state = None,const double &height=0.5,const double &width=0.5);


            void jump();

            void move();

            void update() override;

            VerticalState getMVstate() const;

            void setMVstate(VerticalState mVstate);

            Horizontalstate getMHstate() const;

            void setMHstate(Horizontalstate mHstate);

            double getMVelocityY() const;

            double getMReachedheight() const;

            void setMReachedheight(double mReachedheight);

    private:
        double m_velocity_Y;
        double m_velocity_X;
        double m_gravity;
        double m_reachedheight;
        VerticalState m_vstate;
        Horizontalstate m_hstate;




    };
}


#endif //GAME_PLAYER_H
