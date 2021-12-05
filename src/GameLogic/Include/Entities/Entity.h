//
// Created by ferit on 16/12/2020.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

namespace jumpgame {

    class Entity {
    public:
        /**
         * default constructor
         */
        Entity();
        /**
         * default destructor
         */
        ~Entity();

        /**
         * virtual function to update entity
         */
        virtual void update() = 0;
    };

}


#endif //GAME_ENTITY_H
