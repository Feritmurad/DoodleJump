//
// Created by ferit on 05/12/2021.
//
#include <iostream>
#include "Clock.h"

namespace jumpgame {

    /*Instance = nullptr */
    Clock *Clock::instance = nullptr;

    /* Instance initialized on demand */
    Clock *Clock::getInstance(int tick) {
        if (instance == nullptr) {
            instance = new Clock(tick);
        }
        return instance;
    }

    void Clock::reset() {
        startTime = std::chrono::system_clock::now();

    }

    Clock::Clock(int tick) {
        Tick = tick;
        reset();
    }

    std::chrono::system_clock::time_point Clock::currentTime() {
        return std::chrono::system_clock::now();
    }

    bool Clock::tick() {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime() - startTime).count() >= Tick) {
            reset();
            return true;
        }
        return false;

    }
}