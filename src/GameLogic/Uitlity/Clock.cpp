//
// Created by ferit on 05/12/2021.
//
#include <iostream>
#include "Clock.h"


void jumpgame::Clock::reset() {
    startTime = std::chrono::system_clock::now();

}

jumpgame::Clock::Clock(int tick){
    Tick = tick;
    reset();
}

std::chrono::system_clock::time_point jumpgame::Clock::currentTime() {
    return std::chrono::system_clock::now();
}

bool jumpgame::Clock::tick() {
    if(std::chrono::duration_cast<std::chrono::milliseconds>(currentTime()-startTime).count() >= Tick){
        reset();
        return true;
    }
    return false;

}