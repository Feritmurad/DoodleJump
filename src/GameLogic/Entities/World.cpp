//
// Created by ferit on 07/12/2020.
//

#include "World.h"

#include <utility>

namespace jumpgame {

    void World::update() {
        //std::cout << m_platforms.size() << std::endl;
        generateNewEntities();
        checkPlayerPlatformCollision();
        for (const auto &platform: allPlatforms()) {
            platform->update();
        }
        m_player->update();
        deletePlatforms();

    }

    void World::makeWorld() {

        jumpgame::Coordinate coordinate(0, -2);
        auto player = std::make_shared<jumpgame::Player>(coordinate);
        m_player = player;
        m_player->addObserver(m_factory->createPlayerView());


            auto Platformview = m_factory->createPlatformView();
            //make Platform
            jumpgame::Coordinate coordinate1(-1.5, 4);
            auto platform1 = std::make_shared<jumpgame::VerticalPlatform>(coordinate1);
            m_verticalplatforms.insert(platform1);
            platform1->addObserver(m_factory->getMPlatformview());

        /*
            jumpgame::Coordinate coordinate2(-1.9, -1.1);

            auto platform2 = std::make_shared<jumpgame::Platform>(coordinate2);
            if(checkValidPlatform(platform2)){
                m_platforms.insert(platform2);
                platform2->addObserver(Platformview);
            }
            */

        generateRandomStart();

    }

    const std::shared_ptr<Player> &World::getMPlayer() const {
        return m_player;
    }

    const std::set<std::shared_ptr<Platform>> &World::getMPlatforms() const {
        return m_platforms;
    }

    void World::checkPlayerPlatformCollision() {
        if(m_player->getMVstate() == Falling) {
            for (const auto &platform: allPlatforms()) {
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
                    platform->setMJumpedOn(true);
                }
            }
        }
    }

    void World::playermove(Horizontalstate state) {
        m_player->setMHstate(state);
    }

    void World::deletePlatforms() {
        auto it = m_platforms.begin();
        while(it != m_platforms.end()){
            if(!(*it)->checkValid()){
                it=m_platforms.erase(it);
            }
            else{
                it++;
            }
        }

        auto it2 = m_tempplatforms.begin();
        while(it2 != m_tempplatforms.end()){
            if(!(*it2)->checkValid() || (*it2)->isMJumpedOn()){
                it2=m_tempplatforms.erase(it2);
            }
            else{
                it2++;
            }
        }
    }

    const std::set<std::shared_ptr<HorizontalPlatform>> &World::getMHorizontalplatforms() const {
        return m_horizontalplatforms;
    }

    const std::set<std::shared_ptr<VerticalPlatform>> &World::getMVerticalplatforms() const {
        return m_verticalplatforms;
    }

    void World::generateRandomStart() {
        auto Platformobserver = m_factory->createPlatformView();
        for (int i = -3; i <= 3; i+=3) {
            Coordinate tempcoord(Random::getInstance()->makerandom(-3.0,3.0),i);
            auto platform = std::make_shared<Platform>(tempcoord);
            if(checkValidPlatform(platform)) {
                m_platforms.insert(platform);
                platform->addObserver(Platformobserver);
            }
            else{
                i-=3;
            }
        }
        int randomplatforms = Random::getInstance()->makerandom(6,10);
        for (int i = 0; i < randomplatforms ; ++i) {
            Coordinate randomcoord(Random::getInstance()->makerandom(-3.0,3.0),Random::getInstance()->makerandom(-3.0,4.0));
            auto newplatform = std::make_shared<Platform>(randomcoord);

            if(checkValidPlatform(newplatform)) {
                m_platforms.insert(newplatform);
                newplatform->addObserver(Platformobserver);
            }

            else{
                randomplatforms+=1;
            }
        }


    }

    bool World::checkValidPlatform(const std::shared_ptr<Platform>& nPlatform) {
        std::set<std::shared_ptr<Platform>> Platforms;
        Platforms.insert(m_platforms.begin(),m_platforms.end());
        Platforms.insert(m_tempplatforms.begin(),m_tempplatforms.end());
        for (const auto &platform: Platforms){ /**Check collision for platforms and tempplatforms **/
            if(checkCollision(platform,nPlatform)){
                return false;
            }
        }
        for (const auto &platform: m_verticalplatforms){ /**Check collision for vertical **/
            if(checkCollision(platform,nPlatform) || checkXCollision(platform,nPlatform)){ /** Check if there is another platform on the same x coord */
                return false;
            }
        }
        for (const auto &platform: m_horizontalplatforms){ /**Check collision for vertical **/
            if(checkCollision(platform,nPlatform) || checkYCollision(platform,nPlatform)){ /** Check if there is another platform on the same y coord */
                return false;
            }
        }
        return true;
    }

    bool World::checkCollision(const shared_ptr<Object> &obj1, const shared_ptr<Object> &obj2) { /**Check collision between 2 objects **/
        if(obj1->getC().getX() < obj2->getC().getX() + obj2->getMWidth() &&
                obj1->getC().getX() + obj1->getMWidth() > obj2->getC().getX() &&
                obj1->getC().getY() - obj1->getMHeigth() < obj2->getC().getY() &&
                obj1->getC().getY() > obj2->getC().getY() - obj2->getMHeigth()){
            return true;
        }
        return false;
    }

    bool World::checkXCollision(const shared_ptr<Object> &obj1, const shared_ptr<Object> &obj2) { /**Check collision for a vertical platform with another object **/
        if(obj1->getC().getX() < obj2->getC().getX() + obj2->getMWidth() &&
           obj1->getC().getX() + obj1->getMWidth() > obj2->getC().getX()){
            return true;
        }
        return false;
    }

    bool World::checkYCollision(const shared_ptr<Object> &obj1, const shared_ptr<Object> &obj2) { /**Check collision for a horizontal platform with another object **/
        if(obj1->getC().getY() - obj1->getMHeigth() < obj2->getC().getY() &&
           obj1->getC().getY() > obj2->getC().getY() - obj2->getMHeigth()){
            return true;
        }
        return false;
    }

    World::World(std::shared_ptr<AbstractEntityFactory> factory) : m_factory(factory) {

    }

    void World::generateNewEntities() {
    bool mustplatform = true;
        for (const auto &platform: allPlatforms()) {
            if(platform->getC().getY() > 1){
                mustplatform = false;
            }
        }
        if(mustplatform){
            Coordinate mustcoord(Random::getInstance()->makerandom(-3.0,3.0),4);
            auto platform = std::make_shared<Platform>(mustcoord);
            m_platforms.insert(platform);
            platform->addObserver(m_factory->getMPlatformview());
        }
    }

    std::set<std::shared_ptr<Platform>> World::allPlatforms() {
        std::set<std::shared_ptr<Platform>> Platforms;
        Platforms.insert(m_platforms.begin(),m_platforms.end());
        Platforms.insert(m_verticalplatforms.begin(),m_verticalplatforms.end());
        Platforms.insert(m_horizontalplatforms.begin(),m_horizontalplatforms.end());
        Platforms.insert(m_tempplatforms.begin(),m_tempplatforms.end());
        return Platforms;
    }



}