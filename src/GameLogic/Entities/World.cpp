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
        checkPlatformsValid();

    }

    void World::makeWorld() {

        //make Player
        jumpgame::Coordinate coordinate(0, -2);
        auto player = std::make_shared<jumpgame::Player>(coordinate);
        m_player = player;


        //make Platform
        jumpgame::Coordinate coordinate1(-0.5, -1);
        auto platform1 = std::make_shared<jumpgame::Platform>(coordinate1);
        m_platforms.insert(platform1);

        jumpgame::Coordinate coordinate2(-1.5, 2);
        auto platform2 = std::make_shared<jumpgame::VerticalPlatform>(coordinate2);
        m_platforms.insert(platform2);

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
                if (m_player->getC().getY() - m_player->getMHeigth() < platform->getC().getY() && // lowest y coord of player is under highest y coord of platform
                m_player->getC().getY() - m_player->getMHeigth() > platform->getC().getY() - platform->getMHeigth() && // lowest y coord of player is over lowest y coord of plat
                (
                        (
                                m_player->getC().getX() > platform->getC().getX()
                        && m_player->getC().getX() < platform->getC().getX() + platform->getMWidth())
                ||
                        (
                        m_player->getC().getX() + m_player->getMWidth() > platform->getC().getX()
                && m_player->getC().getX() + m_player->getMWidth() < platform->getC().getX() + platform->getMWidth()
                        )
                )
                ) {
                    m_player->setMVstate(Collision);
                }
            }
        }
    }

    void World::playermove(Horizontalstate state) {
        m_player->setMHstate(state);
    }

    void World::checkPlatformsValid() {
        for (const auto &platform: m_platforms){
            if(!platform->checkValid()){
                m_platforms.erase(platform);
                std::cout << "Deleted" << std::endl;
            }
        }

    }

    const std::set<std::shared_ptr<HorizontalPlatform>> &World::getMHorizontalplatforms() const {
        return m_horizontalplatforms;
    }

    const std::set<std::shared_ptr<VerticalPlatform>> &World::getMVerticalplatforms() const {
        return m_verticalplatforms;
    }

}