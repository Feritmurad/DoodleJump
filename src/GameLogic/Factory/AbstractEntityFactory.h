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


        // Getters and Setters
        void setMPlayerview(const std::shared_ptr<Observer> &mPlayerview);

        void setMPlatformview(const std::shared_ptr<Observer> &mPlatformview);

        const std::shared_ptr<Observer> &getMPlayerview() const;

        const std::shared_ptr<Observer> &getMPlatformview() const;

    private:
        std::shared_ptr<Observer> m_Playerview;

        std::shared_ptr<Observer> m_Platformview;



    };

}


#endif //GAME_ABSTRACTENTITYFACTORY_H
