//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include "Object.h"
#include "iostream"

namespace jumpgame {
    enum PlayerState{Jumping,Onplatform};

    class Player : public Object {
        public:
            /**
             * Constructior with coordinate
             * @param c: coordinate of object
             */
            explicit Player(const Coordinate &c,const double &Yvelocity=0.0, const double &gravity=0.01,PlayerState state = Onplatform);

            void update() override;


        private:
            double m_velocity_Y;
            double m_gravity;
            PlayerState m_state;

    };
}


#endif //GAME_PLAYER_H
