//
// Created by ferit on 05/12/2021.
//

#include "SFMLPlayer.h"

namespace SFMLjumpgame{

    void SFMLPlayer::draw(const std::shared_ptr<Camera> &camera){
        // transform to pixel
        //transform only if its in geocoordinates

        if(getC().validCoordinate()) {
            setC(camera->rescale(getC()));
        }
        // make shape
        sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
        rectangle.setFillColor(sf::Color::Red);
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