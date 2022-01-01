//
// Created by ferit on 1/1/22.
//

#include "Bonus.h"

bool jumpgame::Bonus::isMUsed() const {
    return m_used;
}

void jumpgame::Bonus::setMUsed(bool mUsed) {
    m_used = mUsed;
}

void jumpgame::Bonus::update() {
    jumpgame::ObserverEvent observerevent(0,getC());
    notifyObservers(observerevent);
}

jumpgame::event jumpgame::Bonus::bonustype() {
    return jumpgame::NoBonus;
}
