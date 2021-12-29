//
// Created by ferit on 12/23/21.
//

#include "VerticalPlatform.h"

jumpgame::VerticalPlatform::VerticalPlatform (const Coordinate &c,const double &Yvelocity, const double &height, const double &width,const bool &jumped) :
Platform(c, height, width, jumped) , m_velocity_Y(Yvelocity){
    m_minH = c.getY()-3;
    m_maxH = c.getY();
}

void jumpgame::VerticalPlatform::update() {
    move();
    Platform::update();
}

void jumpgame::VerticalPlatform::move() {
    //std::cout << "before" << getC().getY() << std::endl;
    Coordinate c(getC().getX(),getC().getY()+m_velocity_Y);// set y coord + velocity
   if(c.getY() < m_minH or c.getY() > m_maxH){
       //std::cout << "IF " << std::endl;
       m_velocity_Y *=-1; // change to other side
       Coordinate tempc(getC().getX(),getC().getY()+m_velocity_Y);
       c=tempc;
   }
    setC(c);
}

double jumpgame::VerticalPlatform::getMMinH() const {
    return m_minH;
}

void jumpgame::VerticalPlatform::updateMMinH(double mMinH) {
    m_minH += mMinH;
}

double jumpgame::VerticalPlatform::getMMaxH() const {
    return m_maxH;
}

void jumpgame::VerticalPlatform::updateMMaxH(double mMaxH) {
    m_maxH += mMaxH;
}
