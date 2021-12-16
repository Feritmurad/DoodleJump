//
// Created by ferit on 12/16/21.
//

#include "SFMLObject.h"

namespace SFMLjumpgame {

    jumpgame::Coordinate SFMLObject::getC() const {
        return m_c;
    }

    void SFMLObject::setC(const jumpgame::Coordinate& m_c) {
        SFMLObject::m_c = m_c;
    }

    void SFMLObject::handleEvent() {

    }

    SFMLObject::~SFMLObject() = default;


}