//
// Created by ferit on 12/29/21.
//

#include "SFMLJetpack.h"
namespace SFMLjumpgame{

    void SFMLJetpack::handleEvent(const jumpgame::ObserverEvent &event) {
        if(event.getMUpdateAmount() == 0 && event.getMBonusevent() == jumpgame::NoBonus){
            setC(event.getMCoordinate());
            draw();
        }

    }

    void SFMLJetpack::draw() {
        std::shared_ptr<Camera> camera = std::make_shared<Camera>();
        // transform to pixel
        // transform only if it is in geocoordintes
        if(getC().validCoordinate()){
            jumpgame::Coordinate tempc = camera->rescale(getC());
            sf::RectangleShape rectangle(sf::Vector2f(20.f, 20.f));
            rectangle.setFillColor(sf::Color::Red);
            rectangle.setPosition(tempc.getX(),tempc.getY());
            getWindow()->draw(rectangle);
        }
        jumpgame::Coordinate tempcoord;
        setC(tempcoord);
    }

}


