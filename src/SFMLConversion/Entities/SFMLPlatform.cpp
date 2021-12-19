//
// Created by ferit on 12/17/21.
//

#include "SFMLPlatform.h"

namespace SFMLjumpgame{


    void SFMLPlatform::handleEvent(const jumpgame::ObserverEvent &event) {
        if(event.getMUpdateAmount() == 0){
            //std::cout << "Event1" << event.getMCoordinate().getX() << "," << event.getMCoordinate().getY() << std::endl;
            setC(event.getMCoordinate());
        }
    }

    void SFMLPlatform::draw(const std::shared_ptr<Camera> &camera) {
        // transform to pixel
        // transform only if it is in geocoordintes
        if(getC().validCoordinate()) {
            setC(camera->rescale(getC()));
        }
        // make shape
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 40.f));
        rectangle.setPosition(getC().getX(),getC().getY());

        // draw on window
        getWindow()->draw(rectangle);

    }
}