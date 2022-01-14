//
// Created by ferit on 05/12/2021.
//

#include "SFMLPlayer.h"

namespace SFMLDoodleJump {

void SFMLPlayer::draw()
{
        std::shared_ptr<DoodleJump::Camera> camera = std::make_shared<DoodleJump::Camera>();
        if (getC().validCoordinate()) {
                DoodleJump::Coordinate tempc = camera->rescale(getC());
                sf::Texture playertexture;
                playertexture.loadFromFile("Sprites/Player.png");
                sf::Sprite m_playersprite(playertexture);
                m_playersprite.setPosition(sf::Vector2f(tempc.getX(), tempc.getY()));
                sf::Vector2f targetSize(50.f, 50.f);
                m_playersprite.setScale(targetSize.x / m_playersprite.getLocalBounds().width,
                                        targetSize.y / m_playersprite.getLocalBounds().height);
                getWindow()->draw(m_playersprite);
        }
        DoodleJump::Coordinate tempcoord;
        setC(tempcoord);
}

SFMLPlayer::SFMLPlayer(const shared_ptr<sf::RenderWindow>& window, const DoodleJump::Coordinate& c)
    : SFMLObject(window, c)
{
}

} // namespace SFMLDoodleJump