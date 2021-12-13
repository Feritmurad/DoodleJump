//
// Created by ferit on 19/12/2020.
//

#ifndef GAME_RANDOM_H
#define GAME_RANDOM_H

#include<iostream>
#include "random"
#include "math.h"
using namespace std;

class Random {
private:
    /*
     * Stored instance
     */
    static Random *instance;

    /*
     * Private constructor
     */
    Random();

public:
    /*Static acces method */
    static Random *getInstance();

    /*Delete copy constructor*/
    Random(const Random &obj) = delete;

    /*Delete copy assignment*/
    Random &operator=(const Random &) = delete;

    /*
     *Create random integer
     */
    int makerandom(int first, int last);
    /*
     *Create random integer
     */
    double makerandom(double first, double last);

};


#endif //GAME_RANDOM_H
