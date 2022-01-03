//
// Created by ferit on 1/2/22.
//

#include "SFMLBG_Tile.h"
namespace SFMLjumpgame{

void SFMLBG_Tile::handleEvent(const jumpgame::ObserverEvent &event) {
    if(event.getMUpdateAmount() == 0 && event.getMBonusevent() == jumpgame::NoBonus){
        //std::cout << "Event1" << event.getMCoordinate().getX() << "," << event.getMCoordinate().getY() << std::endl;
        setC(event.getMCoordinate());
        draw();
    }
}

void SFMLBG_Tile::draw() {
    std::shared_ptr<Camera> camera = std::make_shared<Camera>();
    std::cout << getC().getX() << "," << getC().getY() << std::endl;
    jumpgame::Coordinate tempc = camera->rescale(getC());
    std::cout << "tempc" <<tempc.getX() << "," << tempc.getY() << std::endl;


    sf::Texture playertexture;
    playertexture.loadFromFile("Sprites/BG.png");
    sf::Sprite m_playersprite(playertexture);
    m_playersprite.setPosition(sf::Vector2f(tempc.getX(),tempc.getY()));
    sf::Vector2f targetSize(700, 900);
    m_playersprite.setScale(targetSize.x/m_playersprite.getLocalBounds().width, targetSize.y/m_playersprite.getLocalBounds().height);
    getWindow()->draw(m_playersprite);

    jumpgame::Coordinate tempcoord;
    setC(tempcoord);
}
}
