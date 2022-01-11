;//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SFMLHORIZONTALPLATFORM_H
#define JUMPGAME_SFMLHORIZONTALPLATFORM_H
#include "SFMLObject.h"

namespace SFMLDoodleJump {

    class SFMLHorizontalPlatform : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLHorizontalPlatform() override = default;

        /**
         * Constructor with coordinate
         * @param window: window
         * @param c: coordinate of object
         */
        explicit SFMLHorizontalPlatform(const std::shared_ptr<sf::RenderWindow> &window, const DoodleJump::Coordinate &c={0,0}) : SFMLObject(window,c) {}

        /**
         * Draws the object on the window
         */
        void draw() override;

    };

}



#endif //JUMPGAME_SFMLHORIZONTALPLATFORM_H
