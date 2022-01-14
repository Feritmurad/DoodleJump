//
// Created by ferit on 05/12/2021.
//

#ifndef JUMPGAME_CLOCK_H
#define JUMPGAME_CLOCK_H
#include "chrono"
#include <iostream>

namespace DoodleJump {
class Clock
{
private:
        int Tick = 0;
        std::chrono::system_clock::time_point startTime;
        static Clock* instance;

        /**
         * Private constructor
         */
        Clock(int tick);

public:
        /**
         * Static acces method
         */
        static Clock* getInstance(int tick);

        /**
         * Delete copy constructor
         */
        Clock(const Clock& obj) = delete;

        /**
         * Delete copy assignment
         */
        Clock& operator=(const Clock&) = delete;

        /**
         * Checks if clock has ticked
         * @return bool
         */
        bool tick();

        /**
         * Resets the clock
         */
        void reset();

        /**
         * Gets the current time
         * @return current time
         */
        std::chrono::system_clock::time_point currentTime();
};
} // namespace DoodleJump

#endif // JUMPGAME_CLOCK_H
