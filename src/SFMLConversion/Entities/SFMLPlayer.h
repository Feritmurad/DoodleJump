//
// Created by ferit on 05/12/2021.
//

#ifndef JUMPGAME_SFMLPLAYER_H
#define JUMPGAME_SFMLPLAYER_H
#include "SFMLEntity.h"
#include "../../GameLogic/Entities/Player.h"

namespace SFMLjumpgame {

class SFMLPlayer : public SFMLEntity , public jumpgame::Player {
        public:
            SFMLPlayer(const jumpgame::Coordinate &c,const std::shared_ptr<sf::RenderWindow> &window) : SFMLEntity(window), jumpgame::Player(c) {};

            void draw() override;

            void update() override;

        private:


    };

}


#endif //JUMPGAME_SFMLPLAYER_H
