//
// Created by ferit on 1/2/22.
//

#ifndef JUMPGAME_SFMLBG_TILE_H
#define JUMPGAME_SFMLBG_TILE_H
#include "SFMLObject.h"

namespace SFMLDoodleJump {

class SFMLBG_Tile : public SFMLObject
{
public:
        /**
         * Default destructor
         */
        ~SFMLBG_Tile() override = default;

        /**
         * Constructor with coordinate
         * @param window: window
         * @param c: coordinate of object
         */
        explicit SFMLBG_Tile(const std::shared_ptr<sf::RenderWindow>& window, const DoodleJump::Coordinate& c = {0, 0})
            : SFMLObject(window, c)
        {
        }

        /**
         * Draws the object on the window
         */
        void draw() override;
};
} // namespace SFMLDoodleJump

#endif // JUMPGAME_SFMLBG_TILE_H
