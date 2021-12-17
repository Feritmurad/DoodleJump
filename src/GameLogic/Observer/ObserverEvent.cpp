//
// Created by ferit on 12/17/21.
//

#include "ObserverEvent.h"

const jumpgame::Coordinate &jumpgame::ObserverEvent::getMCoordinate() const {
    return m_coordinate;
}

int jumpgame::ObserverEvent::getMUpdateAmount() const {
    return m_update_amount;
}

