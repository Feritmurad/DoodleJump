//
// Created by ferit on 05/12/2021.
//

#include "../Include/Game.h"

void Game::run(){
    std::cout << "asd" << std::endl;
    jumpgame::Clock clock = jumpgame::Clock(10000000);
    int x = 0;
    while(x == 0){
        clock.tick();
        std::cout << "tick" << std::endl;
    }


}