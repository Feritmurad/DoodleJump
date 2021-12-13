//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_OBSERVER_H
#define JUMPGAME_OBSERVER_H

namespace jumpgame {

    enum class Event{
        Score
    };

    class Observer {
        /**
         * virtual function that handles an event
         * @param update_amount: amount that has to be added to score
         */
        virtual void handleEvent(Event event) = 0;

    };

}


#endif //JUMPGAME_OBSERVER_H
