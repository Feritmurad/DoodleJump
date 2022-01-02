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
            sf::Texture playertexture;
            playertexture.loadFromFile("Sprites/Jetpack.png");
            sf::Sprite m_playersprite(playertexture);
            m_playersprite.setPosition(sf::Vector2f(tempc.getX(),tempc.getY()));
            sf::Vector2f targetSize(50.f, 50.f);
            m_playersprite.setScale(targetSize.x/m_playersprite.getLocalBounds().width, targetSize.y/m_playersprite.getLocalBounds().height);

            getWindow()->draw(m_playersprite);
        }
        jumpgame::Coordinate tempcoord;
        setC(tempcoord);
    }

}


