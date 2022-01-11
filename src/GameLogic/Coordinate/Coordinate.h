//
// Created by ferit on 03/08/2021.
//

#ifndef GAME_ARRAYWORLD_H
#define GAME_ARRAYWORLD_H

namespace DoodleJump{
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
        void setX(double xx);

        /**
         * Getter for y
         */
        double getY() const;

        /**
         * Setter for y
         */
        void setY(double yy);

        /**
         * Checks if coordinates are valid with extended y and x
         * @return bool
         */
        bool validCoordinate() const;

        /**
         * Checks if coordinates are valid with extended y
         * @return bool
         */
        bool validCoordinate2() const;

        /**
         * Checks if Coordinates are valid for x and for only max y
         * @return bool
         */
        bool validHorizontallyandTop() const;

        ///////////////////// Overloaded operators /////////////////////
        bool operator>= (const Coordinate& c) const;

        bool operator>(const Coordinate& c) const;

        bool operator<(const Coordinate& c) const;

        bool operator==(const Coordinate& c) const;
        ////////////////////////////////////////////////////////////////


    };
}


#endif //GAME_ARRAYWORLD_H
