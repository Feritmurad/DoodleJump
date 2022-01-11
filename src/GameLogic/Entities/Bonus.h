//
// Created by ferit on 1/1/22.
//

#ifndef JUMPGAME_BONUS_H
#define JUMPGAME_BONUS_H
#include "Object.h"

namespace DoodleJump {

    class Bonus : public Object {

    private:
        bool m_used;

    public:
        /**
         * Simple constructor
         * @param c: coordinate of the object
         * @param height: Height of the object
         * @param width: Width of the object
         */
        explicit Bonus(const Coordinate &c, const double &height=0.5, const double &width=0.5) : Object(c, height, width),m_used(false) {}
        /**
         * Default destructor
         */
        ~Bonus() override = default;

        bool isMUsed() const;

        /**
         * Update the object and notify observers
         */
        void update() override;

        /**
         * Setter for m_used
         * @param mUsed
         */
        void setMUsed(bool mUsed);

        /**
         * virtual function that returns the type of bonus
         * @return @enum event
         */
        virtual event bonustype();

        /**
         * virtual function that updates score
         */
        virtual void updateScore();
    };
}


#endif //JUMPGAME_BONUS_H
