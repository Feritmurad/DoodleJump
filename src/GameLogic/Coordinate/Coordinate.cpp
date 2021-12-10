//
// Created by ferit on 03/08/2021.
//

#include "Coordinate.h"

namespace jumpgame{
    double Coordinate::getX() const {
        return x;
    }

    void Coordinate::setX(double x) {
        Coordinate::x = x;
    }

    double Coordinate::getY() const {
        return y;
    }

    void Coordinate::setY(double y) {
        Coordinate::y = y;
    }
}