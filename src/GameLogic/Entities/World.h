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
#include "BG_Tile.h"

namespace DoodleJump{

    class World{
    public:

        /**
         * Constructor
         * @param factory: abstract factory
         */
        explicit World(std::shared_ptr<AbstractEntityFactory> factory);

        /**
         * Updates members of World
         */
        void update();

        /**
         * Initializes some members of World
         */
        void makeWorld();

        /**
         * Checks if a player colides with a Platform and with a platforms bonus
         */
        void checkPlayerPlatformCollision();

        /**
         * Makes the player move
         * @param state: The state where the player will move
         */
        void playermove(Horizontalstate state);

        /**
         * Deletes platforms that go out of the screen or has to be deleted
         */
        void deletePlatforms();

        /**
         * Generates random start of the game
         */
        void generateRandomStart();

        /**
         * Checks if a platform can be spawned
         * @param nPlatform
         * @return bool
         */
        bool checkValidPlatform(const std::shared_ptr<Platform>& nPlatform);

        /**
         * Checks if a vertical platform can be spawned
         * @param nPlatform
         * @return bool
         */
        bool checkValidPlatform(const std::shared_ptr<VerticalPlatform>& nPlatform);

        /**
         * Checks if a horizontal platform can be spawned
         * @param nPlatform
         * @return bool
         */
        bool checkValidPlatform(const std::shared_ptr<HorizontalPlatform>& nPlatform);

        /**
         * Checks if a platform will colide with vertical or horizontal platforms
         * @param nPlatform
         * @return bool
         */
        bool checkHVValidPlatform(const std::shared_ptr<Platform>& nPlatform);

        /**
         * Check collision between 2 objects
         * @param obj1 : object 1
         * @param obj2 : object 2
         * @return bool
         */
        bool checkCollision(const std::shared_ptr<Object>& obj1,const std::shared_ptr<Object>& obj2);

        /**
         * Helper function for checkHVValidPlatforms
         * @param obj1 : object 1
         * @param obj2 : object 2
         * @return bool
         */
        bool checkXCollision(const std::shared_ptr<VerticalPlatform>& obj1,const std::shared_ptr<Object>& obj2);

        /**
         * Helper function for checkHVValidPlatforms
         * @param obj1 : object 1
         * @param obj2 : object 2
         * @return bool
         */
        bool checkYCollision(const std::shared_ptr<Object>& obj1,const std::shared_ptr<Object>& obj2);

        /**
         * Generates new entities
         */
        void generateNewEntities();

        /**
         * Makes a random new platform
         */
        void makeRandomPlatform();

        /**
         * Checks if background has to be replaced
         */
        void checkBackground();

        /**
         * Takes all platforms in one set
         * @return : set with all platforms of world
         */
        std::set<std::shared_ptr<Platform>> allPlatforms();

        ////////////////// Getters and Setters //////////////////
        const shared_ptr<Score> &getMScore() const;

        void setMScore(const shared_ptr<Score> &mScore);

        const set<std::shared_ptr<BG_Tile>> &getMBgtile() const;

        void setMBgtile(const set<std::shared_ptr<BG_Tile>> &mBgtile);

        const std::shared_ptr<Player> &getMPlayer() const;

        const std::set<std::shared_ptr<Platform>> &getMPlatforms() const;

        const std::set<std::shared_ptr<HorizontalPlatform>> &getMHorizontalplatforms() const;

        const std::set<std::shared_ptr<VerticalPlatform>> &getMVerticalplatforms() const;
        /////////////////////////////////////////////////////////

    private:
        std::shared_ptr<Player> m_player;

        std::set<std::shared_ptr<Platform>> m_platforms;

        std::set<std::shared_ptr<HorizontalPlatform>> m_horizontalplatforms;

        std::set<std::shared_ptr<VerticalPlatform>> m_verticalplatforms;

        std::set<std::shared_ptr<TempPlatform>> m_tempplatforms;

        std::shared_ptr<AbstractEntityFactory> m_factory;

        std::set<std::shared_ptr<BG_Tile>> m_bgtile;

        std::shared_ptr<Observer> m_Playerview;

        std::shared_ptr<Observer> m_Platformview;

        std::shared_ptr<Observer> m_VerticalPlatformview;

        std::shared_ptr<Observer> m_HorizontalPlatformview;

        std::shared_ptr<Observer> m_TempPlatformview;

        std::shared_ptr<Observer> m_Jetpackview;

        std::shared_ptr<Observer> m_Springsview;

        std::shared_ptr<Observer> m_bgtileview;

        std::shared_ptr<Score> m_Score;



    };

}


#endif //GAME_WORLD_H
