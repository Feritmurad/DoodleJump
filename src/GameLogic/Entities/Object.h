//
// Created by ferit on 03/08/2021.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "../Coordinate/Coordinate.h"
#include "Entity.h"

namespace jumpgame {
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

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
         Object(const Coordinate &c) : m_c(c) {}

    public:

        /**
        * Getter for c
        */
        Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(Coordinate m_c);

    private:
        Coordinate m_c;


    };
}
#endif //GAME_OBJECT_H
