//
// Created by ferit on 12/29/21.
//

#include "jetpack.h"

namespace jumpgame {


    void Jetpack::update() {
        jumpgame::ObserverEvent observerevent(0,{0,0},Jetpackbonus);
        notifyObservers(observerevent);
    }

    bool Jetpack::isUsed() const {
        return used;
    }

    void Jetpack::setUsed(bool used) {
        Jetpack::used = used;
    }
}