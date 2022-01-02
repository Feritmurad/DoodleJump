//
// Created by ferit on 07/12/2020.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H
#include "Player.h"
#include "Platform.h"
#include "HorizontalPlatform.h"
#include "VerticalPlatform.h"
#include "set"
#include "../Factory/AbstractEntityFactory.h"
#include "../Utility/Random.h"
#include "TempPlatform.h"
#include "jetpack.h"
#include "Springs.h"
#include "../Score/Score.h"

namespace jumpgame{

    class World : public Entity{
    public:

        explicit World(std::shared_ptr<AbstractEntityFactory> factory);

        void update() override;

        void makeWorld();

        void checkPlayerPlatformCollision();


        const std::shared_ptr<Player> &getMPlayer() const;

        const std::set<std::shared_ptr<Platform>> &getMPlatforms() const;

        void playermove(Horizontalstate state);

        void deletePlatforms();

        const std::set<std::shared_ptr<HorizontalPlatform>> &getMHorizontalplatforms() const;

        const std::set<std::shared_ptr<VerticalPlatform>> &getMVerticalplatforms() const;

        void generateRandomStart();

        bool checkValidPlatform(const std::shared_ptr<Platform>& nPlatform);

        bool checkValidPlatform(const std::shared_ptr<VerticalPlatform>& nPlatform);

        bool checkValidPlatform(const std::shared_ptr<HorizontalPlatform>& nPlatform);

        bool checkHVValidPlatform(const std::shared_ptr<Platform>& nPlatform);

        bool checkCollision(const std::shared_ptr<Object>& obj1,const std::shared_ptr<Object>& obj2);

        bool checkXCollision(const std::shared_ptr<VerticalPlatform>& obj1,const std::shared_ptr<Object>& obj2);

        bool checkYCollision(const std::shared_ptr<Object>& obj1,const std::shared_ptr<Object>& obj2);

        void generateNewEntities();

        void makeRandomPlatform();

        std::set<std::shared_ptr<Platform>> allPlatforms();

        const shared_ptr<Score> &getMScore() const;

        void setMScore(const shared_ptr<Score> &mScore);

    private:
        std::shared_ptr<Player> m_player;

        std::set<std::shared_ptr<Platform>> m_platforms;

        std::set<std::shared_ptr<HorizontalPlatform>> m_horizontalplatforms;

        std::set<std::shared_ptr<VerticalPlatform>> m_verticalplatforms;

        std::set<std::shared_ptr<TempPlatform>> m_tempplatforms;

        std::shared_ptr<AbstractEntityFactory> m_factory;

        std::shared_ptr<Observer> m_Playerview;

        std::shared_ptr<Observer> m_Platformview;

        std::shared_ptr<Observer> m_VerticalPlatformview;

        std::shared_ptr<Observer> m_HorizontalPlatformview;

        std::shared_ptr<Observer> m_TempPlatformview;

        std::shared_ptr<Observer> m_Jetpackview;

        std::shared_ptr<Observer> m_Springsview;

        std::shared_ptr<Score> m_Score;



    };

}


#endif //GAME_WORLD_H
