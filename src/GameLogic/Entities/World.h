//
// Created by ferit on 07/12/2020.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H
#include "Player.h"
#include "Platform.h"
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



    private:
        std::shared_ptr<Player> m_player;

        std::set<std::shared_ptr<Platform>> m_platforms;


    };

}


#endif //GAME_WORLD_H
