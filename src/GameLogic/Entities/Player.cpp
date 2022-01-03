//
// Created by ferit on 19/12/2020.
//

#include "Player.h"

namespace jumpgame{

    Player::Player(const Coordinate &c,const double &reachedheight,const double &Yvelocity,const double &Xvelocity, const double &gravity,VerticalState state,const double &height,const double &width) :
    Object(c,height,width), m_velocity_X(Xvelocity), m_velocity_Y(Yvelocity),m_gravity(gravity), m_reachedheight(height), m_vstate(state), m_bonusstate(NoBonus) {

    }

    void Player::update() {
        jump();
        move();
        ObserverEvent observerevent(0,getC());
        notifyObservers(observerevent);

    }

    void Player::jump() {
        if(m_bonusstate == Jetpackbonus){
            m_velocity_Y = 1;
            m_jetpackreachheight = m_reachedheight+75;
            m_bonusstate = NoBonus;
        }

        if(m_jetpackreachheight <= m_reachedheight){
            if (m_vstate == None or m_vstate == Collision) {
                m_velocity_Y = 0.25;
                if(m_bonusstate == Springsbonus){
                    m_velocity_Y = 0.25 * 5;
                    m_bonusstate = NoBonus;
                }
            } else {
                m_velocity_Y -= 0.015;
            }
            m_velocity_Y += m_gravity;
        }
        if(m_velocity_Y > 0){
            reachingnewheight = false;
            if(getC().getY() >= 0){
                m_reachedheight += m_velocity_Y;
                ObserverEvent o(5);
                notifyObservers(o);
                reachingnewheight = true;
            }
            m_vstate = Jumping;
        }
        else{
            reachingnewheight = false;
            m_vstate = Falling;
        }
        Coordinate c(getC().getX(),getC().getY()+m_velocity_Y);
        if(c.validHorizontallyandTop()){
            setC(c);
        }
    }

    void Player::move() {
        if(m_hstate == Left){
            m_velocity_X = -0.1;
        }
        else if(m_hstate == Right){
            m_velocity_X = 0.1;

        }
        else if(m_hstate == Static){
            m_velocity_X = 0;
        }
        Coordinate c(getC().getX()+m_velocity_X,getC().getY());
        if(c.getX() > 3.99){
            c.setX(-3);
        }
        else if(c.getX() < -3){
            c.setX(3.99);
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

    double Player::getMReachedheight() const {
        return m_reachedheight;
    }

    void Player::updateMReachedheight(double mReachedheight) {
        m_reachedheight += mReachedheight;
    }

    void Player::setMVelocityY(double mVelocityY) {
        m_velocity_Y = mVelocityY;
    }

    bool Player::isReachingnewheight() const {
        return reachingnewheight;
    }

    event Player::getMBonusstate() const {
        return m_bonusstate;
    }

    void Player::setMBonusstate(event mBonusstate) {
        m_bonusstate = mBonusstate;
    }


}