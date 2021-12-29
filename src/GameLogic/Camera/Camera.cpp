//
// Created by ferit on 15/12/2020.
//

#include "Camera.h"

namespace SFMLjumpgame {

    jumpgame::Coordinate Camera::rescale(jumpgame::Coordinate coordinate){
        double xscale = res_x /7.0;
        double yscale = res_y /9.0;


        double x = (coordinate.getX()+3.0) * xscale;
        double y = ((-coordinate.getY())+4.0) * yscale;

        return {x,y};
    }

    void Camera::moveForward() {

        jumpgame::Coordinate playercoordinates = m_world->getMPlayer()->getC();
        jumpgame::Coordinate zerocoordinates(-3,0);



        if(m_world->getMPlayer()->getMVstate() == jumpgame::Jumping){
            if(playercoordinates >= zerocoordinates) {
                for (const auto &platform: m_world->allPlatforms()) {
                    jumpgame::Coordinate newcoord(platform->getC().getX(),
                                                  platform->getC().getY() - m_world->getMPlayer()->getMVelocityY());
                    platform->setC(newcoord);
                }
                for (const auto &platform: m_world->getMVerticalplatforms()) {
                    platform->updateMMaxH(- m_world->getMPlayer()->getMVelocityY());
                    platform->updateMMinH(- m_world->getMPlayer()->getMVelocityY());
                }
                jumpgame::Coordinate playercoord(m_world->getMPlayer()->getC().getX(),0);
                m_world->getMPlayer()->setC(playercoord);
                m_world->getMPlayer()->updateMReachedheight(m_world->getMPlayer()->getMVelocityY());
            }

        }
    }

}