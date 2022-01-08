//
// Created by ferit on 1/1/22.
//

#include "Bonus.h"

namespace DoodleJump {

    bool Bonus::isMUsed() const {
        return m_used;
    }

    void Bonus::setMUsed(bool mUsed) {
        m_used = mUsed;
    }

    void Bonus::update() {
        ObserverEvent observerevent(0, getC());
        notifyObservers(observerevent);
    }

    event Bonus::bonustype() {
        return NoBonus;
    }
}