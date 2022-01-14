//
// Created by ferit on 12/16/21.
//

#ifndef JUMPGAME_SFMLOBJECT_H
#define JUMPGAME_SFMLOBJECT_H
#include "../../GameLogic/Coordinate/Coordinate.h"
#include "SFMLEntity.h"

namespace SFMLDoodleJump {

class SFMLObject : public SFMLEntity, public DoodleJump::Observer
{
public:
        /**
         * default destructor
         */
        ~SFMLObject() override = default;

        /**
         * Constructor with coordinate
         * @param window: window
         * @param c: coordinate of object
         */
        explicit SFMLObject(const std::shared_ptr<sf::RenderWindow>& windowconst,
                            const DoodleJump::Coordinate& c = {0, 0});

public:
        /**
         * Getter for c
         */
        DoodleJump::Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(const DoodleJump::Coordinate& c);

        /**
         * Handles an ObserverEvent
         * @param event
         */
        void handleEvent(const DoodleJump::ObserverEvent& event) override;

        /**
         * Draws the object on the window
         */
        virtual void draw();

        /**
         * Virtual function that makes a rectangle
         * @param color: color of the rectangle
         * @return rectangle
         */
        virtual sf::RectangleShape makePlatformshape(const sf::Color& color);

private:
        DoodleJump::Coordinate m_c;
};

} // namespace SFMLDoodleJump

#endif // JUMPGAME_SFMLOBJECT_H
