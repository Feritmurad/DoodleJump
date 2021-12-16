//
// Created by ferit on 19/12/2020.
//

#include "Player.h"

namespace jumpgame{

    Player::Player(const Coordinate &c,const double &Yvelocity, const double &gravity,PlayerState state) : Object(c), m_velocity_Y(Yvelocity), m_gravity(gravity), m_state(state) {

    }

    void Player::update() {
        std::cout<< this->getC().getY() << std::endl;
        if(this->getC().getY() <= -4){ //harcoded now have to check if there is platfrom under player
            m_state = Onplatform;
            m_velocity_Y = 0.4;
        }
        else{
            m_state = Jumping;
            m_velocity_Y -= 0.025;
        }
        m_velocity_Y += m_gravity;
        Coordinate c(this->getC().getX(),this->getC().getY()+m_velocity_Y);
        this->setC(c);
    }

}