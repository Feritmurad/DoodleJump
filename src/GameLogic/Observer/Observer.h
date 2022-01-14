//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_OBSERVER_H
#define JUMPGAME_OBSERVER_H
#include "ObserverEvent.h"

namespace DoodleJump {

class Observer
{

public:
        /**
         * virtual function that handles an event
         */
        virtual void handleEvent(const ObserverEvent& event) = 0;

        /**
         * virtual default constructor
         */
        virtual ~Observer() = default;
        ;
};

} // namespace DoodleJump

#endif // JUMPGAME_OBSERVER_H
