//
// Created by ferit on 05/12/2021.
//

#ifndef JUMPGAME_GAME_H
#define JUMPGAME_GAME_H

#include "iostream"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../GameLogic/Utility/Clock.h"
#include "memory"
#include "../Entities/SFMLPlayer.h"
#include "../SFMLFactory/SFMLEntityFactory.h"

class Game {
public:
    void run();
};


#endif //JUMPGAME_GAME_H
