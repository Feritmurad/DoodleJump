//
// Created by ferit on 12/29/21.
//

#include "SFMLSprings.h"

namespace SFMLjumpgame{

    void SFMLSprings::handleEvent(const jumpgame::ObserverEvent &event) {
        if(event.getMUpdateAmount() == 0 && event.getMBonusevent() == jumpgame::NoBonus){
            //std::cout << "Event1" << event.getMCoordinate().getX() << "," << event.getMCoordinate().getY() << std::endl;
            setC(event.getMCoordinate());
            draw();
        }

    }

    void SFMLSprings::draw() {
        std::shared_ptr<Camera> camera = std::make_shared<Camera>();
        // transform to pixel
        // transform only if it is in geocoordintes
        if(getC().validCoordinate()){
            jumpgame::Coordinate tempc = camera->rescale(getC());
            sf::Texture playertexture;
            playertexture.loadFromFile("Sprites/Jump.png");
            sf::IntRect rectSourceSprite(30,100,30,50);
            sf::Sprite m_playersprite(playertexture,rectSourceSprite);
            m_playersprite.setPosition(sf::Vector2f(tempc.getX(),tempc.getY()));
            sf::Vector2f targetSize(50.f, 50.f);
            m_playersprite.setScale(targetSize.x/m_playersprite.getLocalBounds().width, targetSize.y/m_playersprite.getLocalBounds().height);

            getWindow()->draw(m_playersprite);
            //sf::RectangleShape rectangle(sf::Vector2f(20.f, 20.f));
            //rectangle.setFillColor(sf::Color::Yellow);
            //rectangle.setPosition(tempc.getX(),tempc.getY());
            //getWindow()->draw(rectangle);
        }
        jumpgame::Coordinate tempcoord;
        setC(tempcoord);
    }

}