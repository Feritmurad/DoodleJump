//
// Created by ferit on 12/23/21.
//

#include "HorizontalPlatform.h"

namespace DoodleJump {

void HorizontalPlatform::update()
{
        move();
        Platform::update();
}

void HorizontalPlatform::move()
{
        Coordinate c(getC().getX() + m_velocity_X, getC().getY());
        if (!c.validCoordinate2()) {
                m_velocity_X *= -1;
                Coordinate tempc(getC().getX() + m_velocity_X, getC().getY());
                c = tempc;
        }
        setC(c);
}

void HorizontalPlatform::updateScore()
{
        if (isMJumpedOn()) {
                ObserverEvent e(-100);
                notifyObservers(e);
        } else {
                ObserverEvent e(50);
                notifyObservers(e);
        }
}
} // namespace DoodleJump
