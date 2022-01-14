//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_PLATFORM_H
#define JUMPGAME_PLATFORM_H
#include "Bonus.h"
#include "Object.h"
#include "iostream"

namespace DoodleJump {

class Platform : public Object
{
public:
        /**
         * Simple constructor
         * @param c: coordinate of the object
         * @param height: Height of the object
         * @param width: Width of the object
         * @param jumped: indicates if the player has jumped on this platform before
         */
        explicit Platform(const Coordinate& c, const double& height = 0.4, const double& width = 1,
                          const bool& jumped = false)
            : Object(c, height, width), m_jumpedOn(jumped), m_bonus(nullptr)
        {
        }

        /**
         * Default destructor
         */
        ~Platform() override = default;

        /**
         * Update the object and notify observers
         */
        void update() override;

        /**
         * Getter for m_jumpedOn
         * @return bool
         */
        bool isMJumpedOn() const;

        /**
         * Setter for m_jumpedOn
         * @param mJumpedOn
         */
        void setMJumpedOn(bool mJumpedOn);

        /**
         * Getter for m_bonus
         * @return : m_bonus
         */
        const std::shared_ptr<Bonus>& getMBonus() const;

        /**
         * Setter for m_bonus
         * @param mBonus
         */
        void setMBonus(const std::shared_ptr<Bonus>& mBonus);

        /**
         * virtual function that updates score
         */
        virtual void updateScore();

private:
        bool m_jumpedOn;

        std::shared_ptr<Bonus> m_bonus;
};

} // namespace DoodleJump

#endif // JUMPGAME_PLATFORM_H
