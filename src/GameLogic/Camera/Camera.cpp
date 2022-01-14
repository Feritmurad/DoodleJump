//
// Created by ferit on 15/12/2020.
//

#include "Camera.h"

namespace DoodleJump {

Coordinate Camera::rescale(Coordinate coordinate)
{
        double xscale = res_x / 7.0;
        double yscale = res_y / 9.0;

        double x = (coordinate.getX() + 3.0) * xscale;
        double y = ((-coordinate.getY()) + 4.0) * yscale;

        return {x, y};
}

void Camera::moveForward()
{

        Coordinate playercoordinates = m_world->getMPlayer()->getC();
        Coordinate zerocoordinates(-3, 0);

        if (m_world->getMPlayer()->getMVstate() == Jumping) {
                if (playercoordinates >= zerocoordinates) {
                        for (const auto& platform : m_world->allPlatforms()) {
                                Coordinate newcoord(platform->getC().getX(),
                                                    platform->getC().getY() - m_world->getMPlayer()->getMVelocityY());
                                platform->setC(newcoord);
                        }
                        for (const auto& bgtile : m_world->getMBgtile()) {
                                double bgtilecoord =
                                    bgtile->getC().getY() - m_world->getMPlayer()->getMVelocityY() / 128;
                                Coordinate newcoord(bgtile->getC().getX(), bgtilecoord);
                                bgtile->setC(newcoord);
                        }
                        for (const auto& platform : m_world->getMVerticalplatforms()) {
                                platform->updateMMaxH(-m_world->getMPlayer()->getMVelocityY());
                                platform->updateMMinH(-m_world->getMPlayer()->getMVelocityY());
                        }
                        Coordinate playercoord(m_world->getMPlayer()->getC().getX(), 0);
                        m_world->getMPlayer()->setC(playercoord);
                }
        }
}

} // namespace DoodleJump