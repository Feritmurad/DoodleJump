//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_OBSERVER_H
#define JUMPGAME_OBSERVER_H
#include "ObserverEvent.h"

namespace DoodleJump {


    class Observer {
        /**
         * virtual function that handles an event
         */
    public:
        virtual void handleEvent(const ObserverEvent &event) = 0;

    };

}


#endif //JUMPGAME_OBSERVER_H
