//
// Created by ferit on 12/23/21.
//

#include "VerticalPlatform.h"

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
