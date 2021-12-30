//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_ABSTRACTENTITYFACTORY_H
#define GAME_ABSTRACTENTITYFACTORY_H
#include "memory"
#include "../Observer/Observer.h"


namespace SFMLjumpgame{
    class SFMLPlayer;
}


namespace jumpgame {
    class AbstractEntityFactory {

    public:
        /**
         * Default constructor
         */
        AbstractEntityFactory() = default;

        ~AbstractEntityFactory() = default;

        /**
         * virtual fucntion to create a SFMLplayer
         */
        virtual std::shared_ptr<Observer> createPlayerView()=0;

        virtual std::shared_ptr<Observer> createPlatformView()=0;

        virtual std::shared_ptr<Observer> createTempPlatformView()=0;

        virtual std::shared_ptr<Observer> createVerticalPlatformView()=0;

        virtual std::shared_ptr<Observer> createHorizontalPlatformView()=0;

        virtual std::shared_ptr<Observer> createJetpackView()=0;

        virtual std::shared_ptr<Observer> createSpringsView()=0;







    };

}


#endif //GAME_ABSTRACTENTITYFACTORY_H
