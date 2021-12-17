//
// Created by ferit on 05/12/2021.
//

#include "SFMLPlayer.h"

namespace SFMLjumpgame{

    void SFMLPlayer::draw(const std::shared_ptr<Camera> &camera){
        // transform to pixel
        setC(camera->rescale(getC()));
        // make shape
        sf::RectangleShape rectangle(sf::Vector2f(40.f, 40.f));
        rectangle.setPosition(getC().getX(),getC().getY());
        // draw on window
        getWindow()->draw(rectangle);

    }

    void SFMLPlayer::handleEvent(const jumpgame::ObserverEvent &event) {
        // if update amount is 0 ( so no score update we have to change pos of player)
        if(event.getMUpdateAmount() == 0){
            setC(event.getMCoordinate());
        }
    }


}