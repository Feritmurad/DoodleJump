//
// Created by ferit on 05/12/2021.
//

#ifndef JUMPGAME_SFMLPLAYER_H
#define JUMPGAME_SFMLPLAYER_H
#include "SFMLObject.h"

namespace SFMLDoodleJump {

class SFMLPlayer : public SFMLObject{
        public:
            explicit SFMLPlayer(const std::shared_ptr<sf::RenderWindow> &window,const DoodleJump::Coordinate &c = {0,0});

            void draw() override;



        private:

    };

}


#endif //JUMPGAME_SFMLPLAYER_H
