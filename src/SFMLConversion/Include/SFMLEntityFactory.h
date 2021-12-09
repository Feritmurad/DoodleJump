//
// Created by ferit on 02/08/2021.
//

#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H
#include "../../GameLogic/Include/EntityFactory.h"

namespace SFMLjumpgame {
class SFMLEntityFactory : public jumpgame::EntityFactory {
    public:
        EntityFactory()= default;

    /**
     * overriden function to create player
     */
    std::shared_ptr<jumpgame::Entity> createPlayer(double x, double y) override;

    };
}


#endif //GAME_FACTORY_H
