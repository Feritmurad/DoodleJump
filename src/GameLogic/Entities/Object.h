//
// Created by ferit on 03/08/2021.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "../Coordinate/Coordinate.h"
#include "Entity.h"
#include "../Observer/Observable.h"

namespace jumpgame {
    class Object : public Entity, public Observable {

    public:

        /**
         * default destructor
         */
        ~Object();

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
         explicit Object(const Coordinate &c) : m_c(c) {}

    public:

        /**
        * Getter for c
        */
        Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(const Coordinate& m_c);


    private:
        Coordinate m_c;


    };
}
#endif //GAME_OBJECT_H
