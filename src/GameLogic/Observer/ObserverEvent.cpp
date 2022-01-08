//
// Created by ferit on 12/17/21.
//

#include "ObserverEvent.h"

namespace DoodleJump {

    const Coordinate &ObserverEvent::getMCoordinate() const {
        return m_coordinate;
    }

    int ObserverEvent::getMUpdateAmount() const {
        return m_update_amount;
    }

    event ObserverEvent::getMBonusevent() const {
        return m_bonusevent;
    }
}
