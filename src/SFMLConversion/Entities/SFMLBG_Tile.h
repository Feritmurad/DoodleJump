//
// Created by ferit on 1/2/22.
//

#ifndef JUMPGAME_SFMLBG_TILE_H
#define JUMPGAME_SFMLBG_TILE_H
#include "SFMLObject.h"


namespace SFMLDoodleJump {

    class SFMLBG_Tile : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLBG_Tile() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLBG_Tile(const std::shared_ptr<sf::RenderWindow> &window, const DoodleJump::Coordinate &c = {0, 0}) : SFMLObject(window,c) {}


        void draw() override;

    };
}

#endif //JUMPGAME_SFMLBG_TILE_H
