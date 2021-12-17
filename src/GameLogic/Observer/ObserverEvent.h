//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_OBSERVEREVENT_H
#define JUMPGAME_OBSERVEREVENT_H
#include "../Coordinate/Coordinate.h"

namespace jumpgame {

    class ObserverEvent {
    private:
        int m_update_amount;

        Coordinate m_coordinate;

    public:
        /**
         * Getter for m_coordinate
         * @return m_coordinate
         */
        const Coordinate &getMCoordinate() const;

        /**
         * Getter for m_update_amount
         * @return m_update_amount
         */
        int getMUpdateAmount() const;

        explicit ObserverEvent(int update_amount=0, const Coordinate &coordinate={0,0}) : m_update_amount(update_amount), m_coordinate(coordinate) {}


    };

}


#endif //JUMPGAME_OBSERVEREVENT_H
