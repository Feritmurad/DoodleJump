//
// Created by ferit on 12/17/21.
//

#include "SFMLPlatform.h"

namespace SFMLjumpgame{


    void SFMLPlatform::handleEvent(const jumpgame::ObserverEvent &event) {
        if(event.getMUpdateAmount() == 0){
            //std::cout << "Event1" << event.getMCoordinate().getX() << "," << event.getMCoordinate().getY() << std::endl;
            setC(event.getMCoordinate());
            draw();
        }

    }

    void SFMLPlatform::draw() {
        std::shared_ptr<Camera> camera = std::make_shared<Camera>();
        // transform to pixel
        // transform only if it is in geocoordintes
        if(getC().validCoordinate()){
            jumpgame::Coordinate tempc = camera->rescale(getC());
            sf::RectangleShape rectangle(sf::Vector2f(100.f, 20.f));
            rectangle.setPosition(tempc.getX(),tempc.getY());
            getWindow()->draw(rectangle);
        }
        jumpgame::Coordinate tempcoord;
        setC(tempcoord);
    }
}