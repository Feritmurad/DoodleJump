//
// Created by ferit on 03/08/2021.
//

#ifndef GAME_ARRAYWORLD_H
#define GAME_ARRAYWORLD_H

namespace jumpgame{
    class Coordinate {

    private:

        double x;

        double y;

    public:

        /**
         * simple constructor
         */
        Coordinate() : x(0), y(0){}

        /**
         * simple constructor
         * @param x = x coordinate
         * @param y = y coordinate
         */
        Coordinate(double x, double y) : x(x), y(y){}

        /**
         * Getter for x
         */
        double getX() const;

        /**
         * Setter for x
         */
        void setX(double x);

        /**
         * Getter for y
         */
        double getY() const;

        /**
         * Setter for y
         */
        void setY(double y);

    };
}


#endif //GAME_ARRAYWORLD_H