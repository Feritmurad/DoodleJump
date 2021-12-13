//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_OSERVABLE_H
#define JUMPGAME_OSERVABLE_H

#include "Observer.h"
#include "vector"
#include "memory"

namespace jumpgame {

    class Observable {


    public:
        /**
         * function to add a observer to the list
         * @param observer: the observer that is going to be added to the list
         */
        void addObserver(std::shared_ptr<Observer> observer);

        /**
         * function to remove a observer from the list
         * @param observer: the observer that is going to be removed from the list
         */
        void removeObserver(std::shared_ptr<Observer> observer);

        /**
         * function that notifies all the observers
         */
        void virtual notifyObservers(Event event) = 0;



    private:
        /*
         * vector that contains all the Observers
         */
        std::vector <std::shared_ptr<Observer>> observers;

    };

}


#endif //JUMPGAME_OSERVABLE_H
