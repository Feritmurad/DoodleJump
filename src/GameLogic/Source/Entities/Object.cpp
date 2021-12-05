//
// Created by ferit on 03/08/2021.
//

#include "../../Include/Entities/Object.h"

namespace jumpgame {
    Object::Object() = default;

    Object::~Object() = default;

    Coordinate Object::getC() const {
        return c;
    }

    void Object::setC(Coordinate c) {
        Object::c = c;
    }

}