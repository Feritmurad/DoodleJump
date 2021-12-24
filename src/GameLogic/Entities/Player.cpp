//
// Created by ferit on 19/12/2020.
//

#include "Player.h"

namespace jumpgame{

    Player::Player(const Coordinate &c,const double &Yvelocity,const double &Xvelocity, const double &gravity,VerticalState state,const double &height,const double &width) :
    Object(c,height,width), m_velocity_Y(Yvelocity),m_velocity_X(Xvelocity), m_gravity(gravity), m_vstate(state) {

    }

    void Player::update() {
        jump();
        move();
        ObserverEvent observerevent(0,getC());
        notifyObservers(observerevent);

    }

    void Player::jump() {

        if(this->getC().getY() <= -3 or m_vstate == Collision){ //harcoded now have to check if there is platfrom under player
            m_velocity_Y = 0.25;
        }
        else{
            m_velocity_Y -= 0.015;
        }

        if(m_velocity_Y > 0){
            m_vstate = Jumping;
        }
        else{
            m_vstate = Falling;
        }

        m_velocity_Y += m_gravity;
        Coordinate c(getC().getX(),getC().getY()+m_velocity_Y);
        if(c.validCoordinate()){
            setC(c);
        }

    }

    void Player::move() {
        if(m_hstate == Left){
            m_velocity_X = -0.05;
        }
        else if(m_hstate == Right){
            m_velocity_X = 0.05;

        }
        else if(m_hstate == Static){
            m_velocity_X = 0;
        }
        Coordinate c(getC().getX()+m_velocity_X,getC().getY());
        if(!c.validCoordinate()){
            c.setX(-(c.getX()-m_velocity_X));
        }
        setC(c);
    }

    void Player::setMVstate(VerticalState mVstate) {
        m_vstate = mVstate;
    }

    VerticalState Player::getMVstate() const {
        return m_vstate;
    }

    void Player::setMHstate(Horizontalstate mHstate) {
        m_hstate = mHstate;
    }

    Horizontalstate Player::getMHstate() const {
        return m_hstate;
    }

    double Player::getMVelocityY() const {
        return m_velocity_Y;
    }


}