//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_OSERVABLE_H
#define JUMPGAME_OSERVABLE_H

#include "Observer.h"
#include "memory"
#include "vector"

namespace DoodleJump {

class Observable
{

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
        virtual void notifyObservers(const DoodleJump::ObserverEvent& event);

        /**
         * Getter for observers
         * @return observers
         */
        const std::vector<std::shared_ptr<Observer>>& getObservers() const;

private:
        std::vector<std::shared_ptr<Observer>> observers;
};

} // namespace DoodleJump

#endif // JUMPGAME_OSERVABLE_H
