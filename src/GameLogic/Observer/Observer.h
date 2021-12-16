//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_OBSERVER_H
#define JUMPGAME_OBSERVER_H

namespace jumpgame {


    class Observer {
        /**
         * virtual function that handles an event
         * @param update_amount: amount that has to be added to score
         */
    public:
        virtual void handleEvent() = 0;

    };

}


#endif //JUMPGAME_OBSERVER_H
