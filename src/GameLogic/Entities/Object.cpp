//
// Created by ferit on 03/08/2021.
//

#include "Object.h"

namespace jumpgame {
    Object::Object() = default;

    Object::~Object() = default;

    Coordinate Object::getC() const {
        return m_c;
    }

    void Object::setC(Coordinate m_c) {
        Object::m_c = m_c;
    }

}