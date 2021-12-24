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

namespace jumpgame{

    class World : public Entity{
    public:

        World() = default;

        void update() override;

        void makeWorld();

        void checkPlayerPlatformCollision();

        const std::shared_ptr<Player> &getMPlayer() const;

        const std::set<std::shared_ptr<Platform>> &getMPlatforms() const;

        void playermove(Horizontalstate state);

        void checkPlatformsValid();

        const std::set<std::shared_ptr<HorizontalPlatform>> &getMHorizontalplatforms() const;

        const std::set<std::shared_ptr<VerticalPlatform>> &getMVerticalplatforms() const;



    private:
        std::shared_ptr<Player> m_player;

        std::set<std::shared_ptr<Platform>> m_platforms;

        std::set<std::shared_ptr<HorizontalPlatform>> m_horizontalplatforms;

        std::set<std::shared_ptr<VerticalPlatform>> m_verticalplatforms;



    };

}


#endif //GAME_WORLD_H
