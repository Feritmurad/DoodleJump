//
// Created by ferit on 03/08/2021.
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "../Coordinate/Coordinate.h"
#include "../Observer/Observable.h"
#include "Entity.h"

namespace DoodleJump {

class Object : public Entity, public Observable
{

public:
        /**
         * default destructor
         */
        ~Object() override = default;

        /**
         * Simple constructor
         * @param c: coordinate of the object
         * @param height: Height of the object
         * @param width: Width of the object
         */
        explicit Object(const Coordinate& c, const double& height, const double& width)
            : m_c(c), m_heigth(height), m_width(width)
        {
        }

        /**
         * Getter for c
         */
        Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(const Coordinate& m_c);

        /**
         * Getter for m_height
         * @return: height of object
         */
        double getMHeigth() const;

        /**
         * Getter for m_width
         * @return: width of object
         */
        double getMWidth() const;

        /**
         * Checks if object has valid coordinates
         * @return bool
         */
        bool checkValid();

private:
        Coordinate m_c;

        double m_heigth;

        double m_width;
};
} // namespace DoodleJump
#endif // GAME_OBJECT_H
