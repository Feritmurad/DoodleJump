//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SFMLVERTICALPLATFORM_H
#define JUMPGAME_SFMLVERTICALPLATFORM_H
#include "SFMLObject.h"

namespace SFMLDoodleJump {

    class SFMLVerticalPlatform : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLVerticalPlatform() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLVerticalPlatform(const std::shared_ptr<sf::RenderWindow> &window, const DoodleJump::Coordinate &c={0,0}) : SFMLObject(window,c) {}

        void draw() override;

    };

}


#endif //JUMPGAME_SFMLVERTICALPLATFORM_H
