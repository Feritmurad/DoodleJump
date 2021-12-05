//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_ABSTRACTENTITYFACTORY_H
#define GAME_ABSTRACTENTITYFACTORY_H
#include "memory"
#include "../../GameLogic/Include/Entities/Player.h"



namespace jumpgame {
    class AbstractEntityFactory {

    public:

        AbstractEntityFactory();

        ~AbstractEntityFactory();

        virtual std::shared_ptr<Entity> createPlayer(double x, double y)=0;
    };

}


#endif //GAME_ABSTRACTENTITYFACTORY_H
