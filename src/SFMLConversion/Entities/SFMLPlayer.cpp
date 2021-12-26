//
// Created by ferit on 05/12/2021.
//

#include "SFMLPlayer.h"

namespace SFMLjumpgame{

    void SFMLPlayer::draw(){
        std::shared_ptr<Camera> camera = std::make_shared<Camera>();
        if(getC().validCoordinate()){
            jumpgame::Coordinate tempc = camera->rescale(getC());
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
            rectangle.setPosition(tempc.getX(),tempc.getY());
            getWindow()->draw(rectangle);
        }
        jumpgame::Coordinate tempcoord;
        setC(tempcoord);
    }

    void SFMLPlayer::handleEvent(const jumpgame::ObserverEvent &event) {
        // if update amount is 0 ( so no score update we have to change pos of player)
        if(event.getMUpdateAmount() == 0){
            setC(event.getMCoordinate());
            draw();
        }
    }


}