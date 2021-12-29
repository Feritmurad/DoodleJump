//
// Created by ferit on 12/29/21.
//

#include "Springs.h"

namespace jumpgame {


    void Springs::update() {
        jumpgame::ObserverEvent observerevent(0,{0,0},Springsbonus);
        notifyObservers(observerevent);
    }

    bool Springs::isUsed() const {
        return used;
    }

    void Springs::setUsed(bool used) {
        Springs::used = used;
    }
}