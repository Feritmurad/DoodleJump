//
// Created by ferit on 05/12/2021.
//

#include "Game.h"
void Game::run(){
    jumpgame::Clock *c = c->getInstance(100);
    std::shared_ptr<sf::RenderWindow> sfmlWindow;
    sfmlWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Jumpgame");
}