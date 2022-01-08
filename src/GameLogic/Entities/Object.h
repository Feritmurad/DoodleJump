//
// Created by ferit on 03/08/2021.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "../Coordinate/Coordinate.h"
#include "Entity.h"
#include "../Observer/Observable.h"

namespace DoodleJump {
    class Object : public Entity, public Observable {

    public:

        /**
         * default destructor
         */
        ~Object() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
         explicit Object(const Coordinate &c,const double &height,const double &width) : m_c(c),m_heigth(height),m_width(width) {}



    public:

        /**
        * Getter for c
        */
        Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(const Coordinate& m_c);

        double getMHeigth() const;

        double getMWidth() const;

        bool checkValid();




    private:

        Coordinate m_c;

        double m_heigth;

        double m_width;



    };
}
#endif //GAME_OBJECT_H
