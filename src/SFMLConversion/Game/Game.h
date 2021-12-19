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
#include "../../GameLogic/Entities/Player.h"
#include "../../GameLogic/Observer/Observable.h"
#include "../../GameLogic/Entities/Platform.h"
#include "../../SFMLConversion/Entities/SFMLPlatform.h"
#include "../../GameLogic/Entities/World.h"

class Game {
public:
    void run();

    void movement(sf::Event &event);

private:
    std::shared_ptr<jumpgame::World> m_world;

};


#endif //JUMPGAME_GAME_H
