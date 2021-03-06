//
// Created by ferit on 10/12/2021.
//

#include "Observable.h"

namespace DoodleJump {

void Observable::addObserver(std::shared_ptr<Observer> observer) { observers.emplace_back(observer); }

void Observable::removeObserver(std::shared_ptr<Observer> observer)
{
        std::vector<std::shared_ptr<Observer>>::iterator it;
        for (it = observers.begin(); it != observers.end(); it++) {
                if (*it == observer) {
                        observers.erase(it);
                        return;
                }
        }
}

void Observable::notifyObservers(const ObserverEvent& event)
{
        for (const auto& i : observers) {
                i->handleEvent(event);
        }
}

const std::vector<std::shared_ptr<Observer>>& Observable::getObservers() const { return observers; }

} // namespace DoodleJump