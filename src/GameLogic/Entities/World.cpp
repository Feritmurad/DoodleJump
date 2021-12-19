//
// Created by ferit on 07/12/2020.
//

#include "World.h"

namespace jumpgame {

    void World::update() {
        checkPlayerPlatformCollision();
        m_player->update();
        for (const auto &platform: m_platforms) {
            platform->update();
        }

    }

    void World::makeWorld() {

        //make Player
        jumpgame::Coordinate coordinate(0, -2);
        auto player = std::make_shared<jumpgame::Player>(coordinate);
        m_player = player;


        //make Platform
        jumpgame::Coordinate coordinate1(-0.5, -1);
        auto platform = std::make_shared<jumpgame::Platform>(coordinate1);
        m_platforms.insert(platform);

    }

    const std::shared_ptr<Player> &World::getMPlayer() const {
        return m_player;
    }

    const std::set<std::shared_ptr<Platform>> &World::getMPlatforms() const {
        return m_platforms;
    }

    void World::checkPlayerPlatformCollision() {

        if(m_player->getMVstate() == Falling) {
            for (const auto &platform: m_platforms) {
                std::cout << m_player->getC().getX() << "," << m_player->getC().getY() << std::endl;
                std::cout << platform->getC().getX() << "," << platform->getC().getY() << std::endl;
                if (m_player->getC().getY() < platform->getC().getY() + platform->getMHeigth()
                &&m_player->getC().getY() + m_player->getMHeigth() > platform->getC().getY()
                &&m_player->getC().getX() < platform->getC().getX() + platform->getMWidth()
                  &&m_player->getC().getX() + m_player->getMWidth() > platform->getC().getX()) {
                    m_player->setMVstate(Collision);
                }
            }
        }
    }

    void World::playermove(Horizontalstate state) {
        m_player->setMHstate(state);
    }

}