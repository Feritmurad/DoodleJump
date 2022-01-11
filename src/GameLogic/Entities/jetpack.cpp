//
// Created by ferit on 12/29/21.
//

#include "jetpack.h"

namespace DoodleJump {


    void Jetpack::update() {

        ObserverEvent observerevent(0,{0,0},Jetpackbonus);
        notifyObservers(observerevent);
        Bonus::update();
    }

    event Jetpack::bonustype() {
        return Jetpackbonus;
    }

    void Jetpack::updateScore() {
        ObserverEvent e(375);
        notifyObservers(e);
    }


}