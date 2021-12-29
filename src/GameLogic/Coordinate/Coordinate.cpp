//
// Created by ferit on 03/08/2021.
//

#include "Coordinate.h"

namespace jumpgame{
    double Coordinate::getX() const {
        return x;
    }

    void Coordinate::setX(double xx) {
        Coordinate::x = xx;
    }

    double Coordinate::getY() const {
        return y;
    }

    void Coordinate::setY(double yy) {
        Coordinate::y = yy;
    }

    bool Coordinate::validCoordinate() const {
        if(x >= -3 && x <= 3 && y >= -4 && y <= 4){
            return true;
        }
        return false;
    }

    bool Coordinate::validHorizontally() const {
        if(x>=-3 && x<=3){
            return true;
        }
        return false;
    }

    bool Coordinate::operator>=(const Coordinate &c) const {
        return (x >= c.getX() && y >= c.getY());
    }

    bool Coordinate::operator>(const Coordinate &c) const {
        return (x > c.getX() || y > c.getY());
    }

    bool Coordinate::operator<(const Coordinate &c) const {
        return (x < c.getX() || y < c.getY());
    }

    bool Coordinate::operator==(const Coordinate &c) const {
        return (x == c.getX() && y == c.getY());
    }
}