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
}