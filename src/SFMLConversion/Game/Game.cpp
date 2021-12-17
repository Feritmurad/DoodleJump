//
// Created by ferit on 05/12/2021.
//

#include "Game.h"
void Game::run()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800,1000),"Jumpgame");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    jumpgame::Coordinate coordinate(2,-4);
    auto player = std::make_shared<jumpgame::Player>(coordinate);

    //make SFMLPlayer
    auto SFMLplayer = std::make_shared<SFMLjumpgame::SFMLPlayer>(window);
    //add sfmlplayer to the observer
    player->addObserver(SFMLplayer);


    auto camera = std::make_shared<SFMLjumpgame::Camera>();

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        jumpgame::Clock *clock = jumpgame::Clock::getInstance(20);
        if(clock->tick()){

            window->clear();

            player->update();
            player->notifyObservers();
            jumpgame::Coordinate pixelcoordinate = camera->rescale(player->getC());

            shape.setPosition(pixelcoordinate.getX(),pixelcoordinate.getY());
            window->draw(shape);


            window->display();
        }

    }
}
    /*
    {
    //jumpgame::Clock *clock = clock->getInstance(100);
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280,700),"Jumpgame");
    //jumpgame::Coordinate coordinate(1,2);
    //SFMLjumpgame::SFMLPlayer player(coordinate,window);
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100, 250, 50));
    window->draw(shape);
    while (window->isOpen()){
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

    }
     }
    */
