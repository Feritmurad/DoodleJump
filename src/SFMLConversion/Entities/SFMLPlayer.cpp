//
// Created by ferit on 05/12/2021.
//

#include "SFMLPlayer.h"

namespace SFMLjumpgame{

    void SFMLPlayer::draw(){
        std::shared_ptr<Camera> camera = std::make_shared<Camera>();
        if(getC().validCoordinate()){
            jumpgame::Coordinate tempc = camera->rescale(getC());
                    /*
            sf::Sprite m_playersprite;
            sf::Texture playertexture;
            if (!playertexture.loadFromFile("Sprites/Player.png")) {
                std::cout << "ERROR" << std::endl;
            }
            m_playersprite.setTexture(playertexture);
            m_playersprite.setPosition(sf::Vector2f(tempc.getX(),tempc.getY()));
            sf::Vector2f targetSize(60.f, 60.f);
            m_playersprite.setScale(targetSize.x/m_playersprite.getLocalBounds().width, targetSize.y/m_playersprite.getLocalBounds().height);

            getWindow()->draw(m_playersprite);
            */
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
            rectangle.setPosition(tempc.getX(),tempc.getY());
            getWindow()->draw(rectangle);



        }
        jumpgame::Coordinate tempcoord;
        setC(tempcoord);
    }

    void SFMLPlayer::handleEvent(const jumpgame::ObserverEvent &event) {
        // if update amount is 0 ( so no score update we have to change pos of player)
        if(event.getMUpdateAmount() == 0 && event.getMBonusevent() == jumpgame::NoBonus){
            setC(event.getMCoordinate());
            draw();
        }
    }

    SFMLPlayer::SFMLPlayer(const shared_ptr<sf::RenderWindow> &window, const jumpgame::Coordinate &c) : SFMLObject(window, c) {

    }


}