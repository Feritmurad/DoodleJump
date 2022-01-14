//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_OBSERVEREVENT_H
#define JUMPGAME_OBSERVEREVENT_H
#include "../Coordinate/Coordinate.h"

namespace DoodleJump {
enum event
{
        Jetpackbonus,
        Springsbonus,
        NoBonus
};

class ObserverEvent
{

private:
        int m_update_amount;
        Coordinate m_coordinate;
        event m_bonusevent;

public:
        /**
         * Constructor
         * @param update_amount: update amount for score
         * @param coordinate: coordinate of object
         * @param bonusevent: bonustype
         */
        explicit ObserverEvent(int update_amount = 0, const Coordinate& coordinate = {0, 0}, event bonusevent = NoBonus)
            : m_update_amount(update_amount), m_coordinate(coordinate), m_bonusevent(bonusevent)
        {
        }

        /**
         * Getter for m_bonusevent
         * @return m_bonusevent
         */
        event getMBonusevent() const;

        /**
         * Getter for m_coordinate
         * @return m_coordinate
         */
        const Coordinate& getMCoordinate() const;

        /**
         * Getter for m_update_amount
         * @return m_update_amount
         */
        int getMUpdateAmount() const;
};
} // namespace DoodleJump

#endif // JUMPGAME_OBSERVEREVENT_H
