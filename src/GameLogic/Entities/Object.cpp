//
// Created by ferit on 03/08/2021.
//

#include "Object.h"

namespace jumpgame {
    
    Coordinate Object::getC() const {
        return m_c;
    }

    void Object::setC(const Coordinate& m_c) {
        Object::m_c = m_c;
    }


    const double Object::getMWidth() const {
        return m_width;
    }

    const double Object::getMHeigth() const {
        return m_heigth;
    }
}