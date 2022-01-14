//
// Created by ferit on 12/29/21.
//

#include "Springs.h"

namespace DoodleJump {

void Springs::update()
{
        ObserverEvent observerevent(0, {0, 0}, Springsbonus);
        notifyObservers(observerevent);
        Bonus::update();
}

event Springs::bonustype() { return Springsbonus; }

void Springs::updateScore()
{
        ObserverEvent e(150);
        notifyObservers(e);
}
} // namespace DoodleJump