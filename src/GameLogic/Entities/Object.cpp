//
// Created by ferit on 03/08/2021.
//

#include "Object.h"

namespace DoodleJump {
    
    Coordinate Object::getC() const {
        return m_c;
    }

    void Object::setC(const Coordinate& m_c) {
        Object::m_c = m_c;
    }


    double Object::getMWidth() const {
        return m_width;
    }

    double Object::getMHeigth() const {
        return m_heigth;
    }

    bool Object::checkValid() {
        return getC().validCoordinate();
    }

}