//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_RANDOM_H
#define GAME_RANDOM_H

#include "math.h"
#include "random"
#include <iostream>
using namespace std;

class Random
{
private:
        /**
         * Stored instance
         */
        static Random* instance;

        /**
         * Private constructor
         */
        Random();

public:
        /**
         * Static acces method
         * */
        static Random* getInstance();

        /**
         * Deleted copy constructor
         * */
        Random(const Random& obj) = delete;

        /**
         * Deleted copy assignment
         */
        Random& operator=(const Random&) = delete;

        /**
         * Generates a random integer between 2 integers
         * @param first: first integer
         * @param last:  second integer
         * @return integer
         */
        int makerandom(int first, int last);

        /**
         * Generates a random double between 2 doubles
         * @param first: first double
         * @param last:  second double
         * @return double
         */
        double makerandom(double first, double last);
};

#endif // GAME_RANDOM_H
