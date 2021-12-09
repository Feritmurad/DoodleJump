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

        static Clock *instance;

        /*
         * private constructor
         */
        Clock(int tick);

    public:
        /*
         * Static acces method
         */
        static Clock *getInstance();

        /*
         * Delete copy constructor
         */
        Clock(const Clock &obj) = delete;

        /*
         * Delete copy assignment
         */
        Clock &operator=(const Clock &) = delete;

        bool tick();

        void reset();

        std::chrono::system_clock::time_point currentTime();
    };
}

#endif //JUMPGAME_CLOCK_H
