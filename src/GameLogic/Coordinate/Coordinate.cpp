//
// Created by ferit on 03/08/2021.
//

#include "Coordinate.h"

namespace DoodleJump {
double Coordinate::getX() const { return x; }

void Coordinate::setX(double xx) { Coordinate::x = xx; }

double Coordinate::getY() const { return y; }

void Coordinate::setY(double yy) { Coordinate::y = yy; }

bool Coordinate::validCoordinate() const
{
        if (x >= -3 && x <= 3.99 && y >= -4.99 && y <= 4) {
                return true;
        }
        return false;
}

bool Coordinate::validCoordinate2() const
{
        if (x >= -3 && x <= 3 && y >= -4.99 && y <= 4) {
                return true;
        }
        return false;
}

bool Coordinate::validHorizontallyandTop() const
{
        if (x >= -3 && x <= 3.99 && y <= 4) {
                return true;
        }
        return false;
}

bool Coordinate::operator>=(const Coordinate& c) const { return (x >= c.getX() && y >= c.getY()); }

bool Coordinate::operator>(const Coordinate& c) const { return (x > c.getX() || y > c.getY()); }

bool Coordinate::operator<(const Coordinate& c) const { return (x < c.getX() || y < c.getY()); }

bool Coordinate::operator==(const Coordinate& c) const { return (x == c.getX() && y == c.getY()); }
} // namespace DoodleJump