//
// Created by ferit on 12/29/21.
//

#include "SFMLSprings.h"

namespace SFMLDoodleJump {

void SFMLSprings::draw()
{
        std::shared_ptr<DoodleJump::Camera> camera = std::make_shared<DoodleJump::Camera>();
        // transform to pixel
        // transform only if it is in geocoordintes
        if (getC().validCoordinate()) {
                DoodleJump::Coordinate tempc = camera->rescale(getC());
                sf::Texture playertexture;
                playertexture.loadFromFile("Sprites/Jump.png");
                sf::IntRect rectSourceSprite(30, 100, 30, 50);
                sf::Sprite m_playersprite(playertexture, rectSourceSprite);
                m_playersprite.setPosition(sf::Vector2f(tempc.getX(), tempc.getY()));
                sf::Vector2f targetSize(50.f, 50.f);
                m_playersprite.setScale(targetSize.x / m_playersprite.getLocalBounds().width,
                                        targetSize.y / m_playersprite.getLocalBounds().height);
                getWindow()->draw(m_playersprite);
        }
        DoodleJump::Coordinate tempcoord;
        setC(tempcoord);
}

} // namespace SFMLDoodleJump