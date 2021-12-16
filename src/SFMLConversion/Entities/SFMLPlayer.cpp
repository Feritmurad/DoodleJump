//
// Created by ferit on 05/12/2021.
//

#include "SFMLPlayer.h"

namespace SFMLjumpgame{

    void SFMLPlayer::draw(){
        jumpgame::Coordinate sfmlc;
        Camera cam;

        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        getWindow()->draw(rectangle);

    }

    void SFMLPlayer::handleEvent() {
        std::cout << "Player" << std::endl;
    }


}