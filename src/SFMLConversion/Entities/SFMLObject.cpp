//
// Created by ferit on 12/16/21.
//

#include "SFMLObject.h"

namespace SFMLjumpgame {

    jumpgame::Coordinate SFMLObject::getC() const {
        return m_c;
    }

    void SFMLObject::setC(const jumpgame::Coordinate& c) {
        SFMLObject::m_c = c;
    }

    void SFMLObject::handleEvent(const jumpgame::ObserverEvent &event) {

    }

    SFMLObject::~SFMLObject() = default;


}