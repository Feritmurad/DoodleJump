//
// Created by ferit on 05/12/2021.
//

#ifndef JUMPGAME_SFMLPLAYER_H
#define JUMPGAME_SFMLPLAYER_H
#include "SFMLObject.h"

namespace SFMLjumpgame {

class SFMLPlayer : public SFMLObject{
        public:
            explicit SFMLPlayer(const std::shared_ptr<sf::RenderWindow> &window,const jumpgame::Coordinate &c = {0,0}) : SFMLObject(window,c) {};

            void draw(const std::shared_ptr<Camera> &camera);

            void handleEvent(const jumpgame::ObserverEvent &event) override;

        private:


    };

}


#endif //JUMPGAME_SFMLPLAYER_H
