//
// Created by ferit on 1/2/22.
//

#include "SFMLBG_Tile.h"
namespace SFMLDoodleJump{



void SFMLBG_Tile::draw() {
    std::shared_ptr<DoodleJump::Camera> camera = std::make_shared<DoodleJump::Camera>();
    DoodleJump::Coordinate tempc = camera->rescale(getC());


    sf::Texture playertexture;
    playertexture.loadFromFile("Sprites/BG.png");
    sf::Sprite m_playersprite(playertexture);
    m_playersprite.setPosition(sf::Vector2f(tempc.getX(),tempc.getY()));
    sf::Vector2f targetSize(700, 900);
    m_playersprite.setScale(targetSize.x/m_playersprite.getLocalBounds().width, targetSize.y/m_playersprite.getLocalBounds().height);
    getWindow()->draw(m_playersprite);

    DoodleJump::Coordinate tempcoord;
    setC(tempcoord);
}
}
