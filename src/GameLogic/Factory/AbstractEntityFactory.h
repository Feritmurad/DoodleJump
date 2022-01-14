//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_ABSTRACTENTITYFACTORY_H
#define GAME_ABSTRACTENTITYFACTORY_H
#include "../Observer/Observer.h"
#include "memory"

namespace DoodleJump {
class AbstractEntityFactory
{

public:
        /**
         * Default constructor
         */
        AbstractEntityFactory() = default;

        /**
         * Default Destructor
         */
        virtual ~AbstractEntityFactory() = default;

        /**
         * pure virtual fucntion to create an SFMLPlayer
         */
        virtual std::shared_ptr<Observer> createPlayerView() = 0;

        /**
         * pure virtual fucntion to create an SFMLPlatform
         */
        virtual std::shared_ptr<Observer> createPlatformView() = 0;

        /**
         * pure virtual fucntion to create an SFMLTempPlatform
         */
        virtual std::shared_ptr<Observer> createTempPlatformView() = 0;

        /**
         * pure virtual fucntion to create an SFMLVerticalPlatform
         */
        virtual std::shared_ptr<Observer> createVerticalPlatformView() = 0;

        /**
         * pure virtual fucntion to create an SFMLHorizontalPlatform
         */
        virtual std::shared_ptr<Observer> createHorizontalPlatformView() = 0;

        /**
         * pure virtual fucntion to create an SFMLJetpack
         */
        virtual std::shared_ptr<Observer> createJetpackView() = 0;

        /**
         * pure virtual fucntion to create an SFMLSprings
         */
        virtual std::shared_ptr<Observer> createSpringsView() = 0;

        /**
         * pure virtual fucntion to create an SFMLBGtile
         */
        virtual std::shared_ptr<Observer> createBGtileView() = 0;
};

} // namespace DoodleJump

#endif // GAME_ABSTRACTENTITYFACTORY_H
