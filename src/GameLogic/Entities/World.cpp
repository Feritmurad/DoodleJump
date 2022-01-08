//
// Created by ferit on 07/12/2020.
//

#include "World.h"

#include <utility>

namespace DoodleJump {

    void World::update() {
        generateNewEntities();
        checkBackground();
        checkPlayerPlatformCollision();
        for (const auto &bgtile: m_bgtile) {
            bgtile->update();
        }
        for (const auto &platform: allPlatforms()) {
            platform->update();
        }
        m_player->update();
        deletePlatforms();

    }

    void World::makeWorld() {

        m_Playerview = m_factory->createPlayerView();
        m_Platformview = m_factory->createPlatformView();
        m_TempPlatformview = m_factory->createTempPlatformView();
        m_VerticalPlatformview = m_factory->createVerticalPlatformView();
        m_HorizontalPlatformview = m_factory->createHorizontalPlatformView();
        m_Jetpackview = m_factory->createJetpackView();
        m_Springsview = m_factory->createSpringsView();
        m_Score = std::make_shared<Score>();
        m_bgtileview = m_factory->createBGtileView();
        Coordinate bgtilecoord(-3,4);
        auto bgtile = std::make_shared<BG_Tile>(bgtilecoord);

        bgtile->addObserver(m_bgtileview);
        m_bgtile.insert(bgtile);

        Coordinate bgtilecoord2(-3,13);
        auto bgtile2 = std::make_shared<BG_Tile>(bgtilecoord2);
        bgtile2->addObserver(m_bgtileview);
        m_bgtile.insert(bgtile2);



        Coordinate coordinate(0, -2);
        auto player = std::make_shared<Player>(coordinate);
        m_player = player;
        m_player->addObserver(m_Playerview);
        m_player->addObserver(m_Score);
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
                    platform->updateScore();
                    platform->setMJumpedOn(true);
                    if(platform->getMBonus() != nullptr){
                        if(checkCollision(m_player,platform->getMBonus())){
                            m_player->setMBonusstate(platform->getMBonus()->bonustype());
                            platform->setMBonus(nullptr);
                        }
                    }
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
        auto it3 = m_verticalplatforms.begin();
        while(it3 != m_verticalplatforms.end()){
            if(!(*it3)->checkValid()){
                it3=m_verticalplatforms.erase(it3);
            }
            else{
                it3++;
            }
        }
        auto it4 = m_horizontalplatforms.begin();
        while(it4 != m_horizontalplatforms.end()){
            if(!(*it4)->checkValid()){
                it4= m_horizontalplatforms.erase(it4);
            }
            else{
                it4++;
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
        for (int i = -3; i <= 3; i+=3) {
            Coordinate tempcoord(Random::getInstance()->makerandom(-3.0,3.0),i);
            auto platform = std::make_shared<Platform>(tempcoord);
            if(checkValidPlatform(platform)) {
                m_platforms.insert(platform);
                platform->addObserver(m_Platformview);
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
                newplatform->addObserver(m_Platformview);
            }

            else{
                randomplatforms+=1;
            }
        }


    }

    bool World::checkValidPlatform(const shared_ptr<VerticalPlatform> &nPlatform) {
        std::set<std::shared_ptr<Platform>> Platforms;
        Platforms.insert(m_platforms.begin(), m_platforms.end());
        Platforms.insert(m_tempplatforms.begin(), m_tempplatforms.end());
        for (const auto &platform: Platforms) { /**Check collision for platforms and tempplatforms **/
            if (checkCollision(platform, nPlatform) || checkXCollision(nPlatform,platform)) {
                return false;
            }
        }
        checkHVValidPlatform(nPlatform);
        return true;
    }

    bool World::checkValidPlatform(const shared_ptr<HorizontalPlatform> &nPlatform) {
        std::set<std::shared_ptr<Platform>> Platforms;
        Platforms.insert(m_platforms.begin(), m_platforms.end());
        Platforms.insert(m_tempplatforms.begin(), m_tempplatforms.end());
        for (const auto &platform: Platforms) { /**Check collision for platforms and tempplatforms **/
            if (checkCollision(platform, nPlatform)  || checkYCollision(platform,nPlatform)) {
                return false;
            }
        }
        checkHVValidPlatform(nPlatform);
        return true;
    }

    bool World::checkHVValidPlatform(const shared_ptr<Platform> &nPlatform) {
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

    bool World::checkValidPlatform(const std::shared_ptr<Platform>& nPlatform) {
        std::set<std::shared_ptr<Platform>> Platforms;
        Platforms.insert(m_platforms.begin(), m_platforms.end());
        Platforms.insert(m_tempplatforms.begin(), m_tempplatforms.end());
        for (const auto &platform: Platforms) { /**Check collision for platforms and tempplatforms **/
            if (checkCollision(platform, nPlatform)) {
                return false;
            }
        }
        checkHVValidPlatform(nPlatform);
        return true;
    }

        bool World::checkCollision(const shared_ptr<Object> &obj1,
                                   const shared_ptr<Object> &obj2) { /**Check collision between 2 objects **/
            if (obj1->getC().getX() < obj2->getC().getX() + obj2->getMWidth() &&
                obj1->getC().getX() + obj1->getMWidth() > obj2->getC().getX() &&
                obj1->getC().getY() - obj1->getMHeigth() < obj2->getC().getY() &&
                obj1->getC().getY() > obj2->getC().getY() - obj2->getMHeigth()) {
                return true;
            }
            return false;
        }

        bool World::checkXCollision(const shared_ptr<VerticalPlatform> &obj1,
                                    const shared_ptr<Object> &obj2) { /**Check collision for a vertical platform with another object **/
            if (obj1->getC().getX() < obj2->getC().getX() + obj2->getMWidth() &&
                obj1->getC().getX() + obj1->getMWidth() > obj2->getC().getX()) {
                if (obj1->getMMaxH() > obj2->getC().getY() - obj2->getMHeigth() ||
                    obj1->getMMinH() > obj2->getC().getY()) {
                    return true;
                }
            }
            return false;
        }

        bool World::checkYCollision(const shared_ptr<Object> &obj1,
                                    const shared_ptr<Object> &obj2) { /**Check collision for a horizontal platform with another object **/
            if (obj1->getC().getY() - obj1->getMHeigth() < obj2->getC().getY() &&
                obj1->getC().getY() > obj2->getC().getY() - obj2->getMHeigth()) {
                return true;
            }
            return false;
        }

        World::World(std::shared_ptr<AbstractEntityFactory>
        factory) : m_factory(factory)
        {

        }

        void World::generateNewEntities() {
            if (m_player->isReachingnewheight()) {
                bool newrandomplatform = false;
                bool newrandomplatformchance = false;
                double randomplatforms = 15 - pow((m_player->getMReachedheight() / 63), 1.2);
                if (randomplatforms > allPlatforms().size()) { /** If there are less platforms than randomplatforms */
                    for (const auto &platform: allPlatforms()) {
                        newrandomplatform = true;
                        if (platform->getC().getY() > 3) /** If there is a platform above logical coord 3 */
                            newrandomplatformchance = true;
                    }
                }
                if (newrandomplatform) {
                    if (newrandomplatformchance) {
                        if (Random::getInstance()->makerandom(1, 10) ==
                            1) { /** 1/10 chance to make platform if there is a platform above 3 */
                            makeRandomPlatform();
                        }
                    } else {
                        makeRandomPlatform();
                    }
                }
                bool mustplatform = true;
                for (const auto &platform: allPlatforms()) {
                    if (platform->getC().getY() > 1.5) {
                        mustplatform = false;
                    }
                }
                if (mustplatform) {
                    makeRandomPlatform();
                }
            }
        }

        std::set<std::shared_ptr<Platform>> World::allPlatforms() {
            std::set<std::shared_ptr<Platform>> Platforms;
            Platforms.insert(m_platforms.begin(), m_platforms.end());
            Platforms.insert(m_verticalplatforms.begin(), m_verticalplatforms.end());
            Platforms.insert(m_horizontalplatforms.begin(), m_horizontalplatforms.end());
            Platforms.insert(m_tempplatforms.begin(), m_tempplatforms.end());
            return Platforms;
        }

        void World::makeRandomPlatform() {
            double randomplatform = 100.0 - pow(m_player->getMReachedheight() / 13, 1.2);
            if (randomplatform < 0) {
                randomplatform = 0;
            }
            int hardplatformchance = 100.0 - randomplatform;
            //std::cout << hardplatformchance << std::endl;
            int platformchance = Random::getInstance()->makerandom(0, hardplatformchance);
            Coordinate newcoord(Random::getInstance()->makerandom(-3.0, 3.0), 4.0);

            bool bonus = Random::getInstance()->makerandom(1, 100) <= 4;
            int bonuschance = Random::getInstance()->makerandom(1, 100);
            Coordinate bonuscoord(newcoord.getX(),newcoord.getY());
            auto b = std::make_shared<Bonus>(bonuscoord);
            if(bonus){
                newcoord.setY(newcoord.getY()-b->getMHeigth());
                if(bonuschance <=25){
                    b = std::make_shared<Jetpack>(bonuscoord);
                    b->addObserver(m_Jetpackview);
                }
                else{
                    b = std::make_shared<Springs>(bonuscoord);
                    b->addObserver(m_Springsview);
                }
            }

                if (Random::getInstance()->makerandom(1, 100) > hardplatformchance) {
                    auto newplatform = std::make_shared<Platform>(newcoord);
                    if (checkValidPlatform(newplatform)) {
                        if(bonus){
                            newplatform->setMBonus(b);
                        }
                        m_platforms.insert(newplatform);
                        newplatform->addObserver(m_Platformview);
                        newplatform->addObserver(m_Score);

                    }

                } else {
                    if (platformchance <= hardplatformchance / 3) {
                        auto newtempplatform = std::make_shared<TempPlatform>(newcoord);
                        if (checkValidPlatform(newtempplatform)) {
                            if(bonus){
                                newtempplatform->setMBonus(b);
                            }
                            m_tempplatforms.insert(newtempplatform);
                            newtempplatform->addObserver(m_TempPlatformview);
                            newtempplatform->addObserver(m_Score);

                        }
                    } else if (platformchance <= (hardplatformchance / 3) * 2) {
                        auto newverticalplatform = std::make_shared<VerticalPlatform>(newcoord);
                        if (checkValidPlatform(newverticalplatform)) {
                            if(bonus){
                                newverticalplatform->setMBonus(b);
                            }
                            m_verticalplatforms.insert(newverticalplatform);
                            newverticalplatform->addObserver(m_VerticalPlatformview);
                            newverticalplatform->addObserver(m_Score);

                        }
                    } else {
                        auto newhorizontalplatform = std::make_shared<HorizontalPlatform>(newcoord);
                        if (checkValidPlatform(newhorizontalplatform)) {
                            if(bonus){
                                newhorizontalplatform->setMBonus(b);
                            }
                            m_horizontalplatforms.insert(newhorizontalplatform);
                            newhorizontalplatform->addObserver(m_HorizontalPlatformview);
                            newhorizontalplatform->addObserver(m_Score);

                        }
                    }
                }
        }

    const shared_ptr<Score> &World::getMScore() const {
        return m_Score;
    }

    void World::setMScore(const shared_ptr<Score> &mScore) {
        m_Score = mScore;
    }

    void World::checkBackground() {
        for (const auto &bgtile: m_bgtile){
            if(bgtile->getC().getY() <-4.99){
                Coordinate bgtilecoord(-3,bgtile->getC().getY()+18);
                bgtile->setC(bgtilecoord);
            }
        }

    }

    const set<std::shared_ptr<BG_Tile>> &World::getMBgtile() const {
        return m_bgtile;
    }

    void World::setMBgtile(const set<std::shared_ptr<BG_Tile>> &mBgtile) {
        m_bgtile = mBgtile;
    }

}