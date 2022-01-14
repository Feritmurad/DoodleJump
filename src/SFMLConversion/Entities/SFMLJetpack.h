//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SFMLJETPACK_H
#define JUMPGAME_SFMLJETPACK_H
#include "SFMLObject.h"

namespace SFMLDoodleJump {

class SFMLJetpack : public SFMLObject
{
public:
        /**
         * default destructor
         */
        ~SFMLJetpack() override = default;

        /**
         * Constructor with coordinate
         * @param window: window
         * @param c: coordinate of object
         */
        explicit SFMLJetpack(const std::shared_ptr<sf::RenderWindow>& window, const DoodleJump::Coordinate& c = {0, 0})
            : SFMLObject(window, c)
        {
        }

        /**
         * Draws the object on the window
         */
        void draw() override;
};

} // namespace SFMLDoodleJump

#endif // JUMPGAME_SFMLJETPACK_H
