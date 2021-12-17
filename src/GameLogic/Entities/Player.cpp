//
// Created by ferit on 19/12/2020.
//

#include "Player.h"

namespace jumpgame{

    Player::Player(const Coordinate &c,const double &Yvelocity, const double &gravity,PlayerState state) : Object(c), m_velocity_Y(Yvelocity), m_gravity(gravity), m_state(state) {

    }

    void Player::update() {
        jump();

    }

    void Player::jump() {
        if(this->getC().getY() <= -3){ //harcoded now have to check if there is platfrom under player
            m_state = Onplatform;
            m_velocity_Y = 0.25;
        }
        else{
            m_state = Jumping;
            m_velocity_Y -= 0.015;
        }
        m_velocity_Y += m_gravity;
        Coordinate c(getC().getX(),getC().getY()+m_velocity_Y);
        setC(c);
    }
}