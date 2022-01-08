//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SFMLSPRINGS_H
#define JUMPGAME_SFMLSPRINGS_H
#include "SFMLObject.h"


namespace SFMLDoodleJump {

    class SFMLSprings: public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLSprings() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLSprings(const std::shared_ptr<sf::RenderWindow> &window, const DoodleJump::Coordinate &c={0,0}) : SFMLObject(window,c) {}


        void draw() override;

    };

}


#endif //JUMPGAME_SFMLSPRINGS_H
