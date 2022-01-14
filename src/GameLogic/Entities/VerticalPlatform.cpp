//
// Created by ferit on 12/23/21.
//

#include "VerticalPlatform.h"

namespace DoodleJump {

VerticalPlatform::VerticalPlatform(const Coordinate& c, const double& Yvelocity, const double& height,
                                   const double& width, const bool& jumped)
    : Platform(c, height, width, jumped), m_velocity_Y(Yvelocity)
{
        m_minH = c.getY() - 3;

        m_maxH = c.getY();
}

void VerticalPlatform::update()
{
        move();
        Platform::update();
}

void VerticalPlatform::move()
{
        // std::cout << "before" << getC().getY() << std::endl;
        Coordinate c(getC().getX(),
                     getC().getY() + m_velocity_Y); // set y coord + velocity
        if (c.getY() < m_minH or c.getY() > m_maxH) {
                // std::cout << "IF " << std::endl;
                m_velocity_Y *= -1; // change to other side
                Coordinate tempc(getC().getX(), getC().getY() + m_velocity_Y);
                c = tempc;
        }
        setC(c);
}

double VerticalPlatform::getMMinH() const { return m_minH; }

void VerticalPlatform::updateMMinH(double mMinH) { m_minH += mMinH; }

double VerticalPlatform::getMMaxH() const { return m_maxH; }

void VerticalPlatform::updateMMaxH(double mMaxH) { m_maxH += mMaxH; }

void VerticalPlatform::updateScore()
{
        if (isMJumpedOn()) {
                ObserverEvent e(-100);
                notifyObservers(e);
        } else {
                ObserverEvent e(75);
                notifyObservers(e);
        }
}

} // namespace DoodleJump