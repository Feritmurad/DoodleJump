//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_SFMLPLATFORM_H
#define JUMPGAME_SFMLPLATFORM_H
#include "SFMLObject.h"

namespace SFMLDoodleJump {

    class SFMLPlatform : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLPlatform() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLPlatform(const std::shared_ptr<sf::RenderWindow> &window, const DoodleJump::Coordinate &c={0,0}) : SFMLObject(window,c) {}


        void draw() override;


    };

}


#endif //JUMPGAME_SFMLPLATFORM_H
