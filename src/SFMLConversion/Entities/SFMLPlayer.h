//
// Created by ferit on 05/12/2021.
//

#ifndef JUMPGAME_SFMLPLAYER_H
#define JUMPGAME_SFMLPLAYER_H
#include "SFMLObject.h"

namespace SFMLDoodleJump {

    class SFMLPlayer : public SFMLObject{
        public:
        /**
         * Constructor with coordinate
         * @param window: window
         * @param c: coordinate of object
         */
        explicit SFMLPlayer(const std::shared_ptr<sf::RenderWindow> &window,const DoodleJump::Coordinate &c = {0,0});

        /**
         * Draws the object on the window
         */
        void draw() override;

        /**
         * Default destructor
         */
        ~SFMLPlayer() override = default;


    };

}


#endif //JUMPGAME_SFMLPLAYER_H
