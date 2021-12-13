//
// Created by ferit on 09/12/2021.
//

#ifndef JUMPGAME_ENTITYFACTORY_H
#define JUMPGAME_ENTITYFACTORY_H

#include "AbstractEntityFactory.h"

namespace jumpgame {

    class EntityFactory : public AbstractEntityFactory {
        /**
         * Default constructor
         */
        EntityFactory();

        std::shared_ptr<Entity> createPlayer(double x, double y) override;
    };

}


#endif //JUMPGAME_ENTITYFACTORY_H
