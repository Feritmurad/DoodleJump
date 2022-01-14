//
// Created by ferit on 12/23/21.
//

#include "TempPlatform.h"

namespace DoodleJump {

void TempPlatform::update() { Platform::update(); }

void TempPlatform::updateScore()
{
        if (isMJumpedOn()) {
                ObserverEvent e(-100);
                notifyObservers(e);
        } else {
                ObserverEvent e(50);
                notifyObservers(e);
        }
}

} // namespace DoodleJump