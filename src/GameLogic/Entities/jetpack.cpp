//
// Created by ferit on 12/29/21.
//

#include "jetpack.h"

namespace jumpgame {


    void Jetpack::update() {
        jumpgame::ObserverEvent observerevent(0,{0,0},Jetpackbonus);
        notifyObservers(observerevent);
        Bonus::update();
    }

    event Jetpack::bonustype() {
        return Jetpackbonus;
    }


}