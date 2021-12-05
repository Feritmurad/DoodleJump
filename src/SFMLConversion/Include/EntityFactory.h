//
// Created by ferit on 02/08/2021.
//

#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H
#include "AbstractEntityFactory.h"

namespace jumpgame {
    class EntityFactory : public AbstractEntityFactory {
    public:
        EntityFactory()= default;

    /**
     * overriden function to create player
     */
    std::shared_ptr<Entity> createPlayer(double x, double y) override;

    };
}


#endif //GAME_FACTORY_H
