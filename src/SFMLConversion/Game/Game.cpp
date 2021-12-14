//
// Created by ferit on 05/12/2021.
//

#include "Game.h"
void Game::run(){

    jumpgame::Clock *clock = clock->getInstance(100);
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280,700),"Jumpgame");
    jumpgame::Coordinate coordinate(1,2);
    SFMLjumpgame::SFMLPlayer player(coordinate,window);
    while (window->isOpen()){
        sf::CircleShape shape(50);
        window->draw(shape);
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
}