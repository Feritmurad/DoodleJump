//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_ABSTRACTENTITYFACTORY_H
#define GAME_ABSTRACTENTITYFACTORY_H
#include "memory"
#include "../Include/Entities/Entity.h"



namespace jumpgame {
    class AbstractEntityFactory {

    public:
        /*
         * Default constructor
         */
        AbstractEntityFactory();

        ~AbstractEntityFactory();

        /*
         * virtual fucntion to create a player
         */
        virtual std::shared_ptr<Entity> createPlayer(double x, double y)=0;
    };

}


#endif //GAME_ABSTRACTENTITYFACTORY_H
