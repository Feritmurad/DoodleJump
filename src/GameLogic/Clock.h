//
// Created by ferit on 05/12/2021.
//

#ifndef JUMPGAME_CLOCK_H
#define JUMPGAME_CLOCK_H
#include <iostream>
#include "chrono"

namespace jumpgame {
    class Clock {
    private:
        int Tick = 0;
        std::chrono::system_clock::time_point startTime;

    public:
        /*
         * simple constructor
         */
        Clock(int tick);

        bool tick();

        void reset();

        std::chrono::system_clock::time_point currentTime();
    };
}

#endif //JUMPGAME_CLOCK_H
