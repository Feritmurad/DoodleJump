//
// Created by ferit on 19/12/2020.
//

#include "Random.h"

Random::Random() = default;

/*Instance = nullptr */
Random* Random::instance = nullptr;

/* Instance initialized on demand */
Random* Random::getInstance()
{
        if (instance == nullptr) {
                instance = new Random();
        }
        return instance;
}
/* Makes a random int between first and last*/
int Random::makerandom(int first, int last)
{
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(first, last);
        return dist(mt);
}
/* Makes a random double between first and last*/
double Random::makerandom(double first, double last)
{
        random_device rd;
        mt19937 mt(rd());
        uniform_real_distribution<double> dist(first, last);
        double returndouble = ceil(dist(mt) * 100) / 100;
        return returndouble;
}