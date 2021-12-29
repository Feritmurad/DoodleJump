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

        bool checkCollision(const std::shared_ptr<Object>& obj1,const std::shared_ptr<Object>& obj2);

        bool checkXCollision(const std::shared_ptr<Object>& obj1,const std::shared_ptr<Object>& obj2);

        bool checkYCollision(const std::shared_ptr<Object>& obj1,const std::shared_ptr<Object>& obj2);


        void generateNewEntities();

        std::set<std::shared_ptr<Platform>> allPlatforms();

    private:
        std::shared_ptr<Player> m_player;

        std::set<std::shared_ptr<Platform>> m_platforms;

        std::set<std::shared_ptr<HorizontalPlatform>> m_horizontalplatforms;

        std::set<std::shared_ptr<VerticalPlatform>> m_verticalplatforms;

        std::set<std::shared_ptr<TempPlatform>> m_tempplatforms;

        std::shared_ptr<AbstractEntityFactory> m_factory;



    };

}


#endif //GAME_WORLD_H
