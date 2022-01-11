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
#include "../../GameLogic/Entities/Player.h"
#include "../../GameLogic/Observer/Observable.h"
#include "../../GameLogic/Entities/Platform.h"
#include "../../SFMLConversion/Entities/SFMLPlatform.h"
#include "../../GameLogic/Entities/World.h"
#include "../../GameLogic/Score/Score.h"
#include "../../SFMLConversion/Factory/ConcreteFactory.h"
#include "string"
#include <iostream>
#include <fstream>
#include <string>


class Game {
public:
    /**
     * function that runs the game
     */
    void run();

    /**
     * function that gets the input of keyboard
     * @param event
     */
    void movement(sf::Event &event);

    /**
     * Function that makes the score text
     * @param window
     */
    void ScoreText(const std::shared_ptr<sf::RenderWindow> &window);

    /**
     * Function that checks if the game is over and changes the window if its over
     * @param window
     */
    void GameOver(const std::shared_ptr<sf::RenderWindow> &window);


private:
    std::shared_ptr<DoodleJump::World> m_world;


};


#endif //JUMPGAME_GAME_H
