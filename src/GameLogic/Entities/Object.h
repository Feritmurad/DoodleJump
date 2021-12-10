//
// Created by ferit on 03/08/2021.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "../Coordinate/Coordinate.h"
#include "Entity.h"

namespace jumpgame {
    enum State {LEFT,RIGHT,JUMP,STATIC};
    class Object : public Entity {

    public:

        /**
         * default constructor
         */
        Object();

        /**
         * default constructor
         */
        ~Object();

    public:

        /**
        * Getter for c
        */
        Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(Coordinate c);

    private:
        Coordinate c;
        State state;


    };
}
#endif //GAME_OBJECT_H
