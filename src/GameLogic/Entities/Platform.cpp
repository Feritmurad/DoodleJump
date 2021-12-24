//
// Created by ferit on 12/17/21.
//

#include "Platform.h"

namespace jumpgame {


    void Platform::update() {
        jumpgame::ObserverEvent observerevent(0,getC());
        notifyObservers(observerevent);
    }

    bool Platform::checkValid() {
        return getC().validCoordinate();
    }

    void Platform::setMJumpedOn(bool mJumpedOn) {
        m_jumpedOn = mJumpedOn;
    }

    bool Platform::isMJumpedOn() const {
        return m_jumpedOn;
    }

}