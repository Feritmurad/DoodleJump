//
// Created by ferit on 05/12/2021.
//

#include "Game.h"
void Game::run()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(700,900),"Jumpgame");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //make World
    m_world = std::make_shared<jumpgame::World>(std::make_shared<SFMLjumpgame::ConcreteFactory>(window));
    m_world->makeWorld();
    //make score
    m_score = std::make_shared<jumpgame::Score>();

    auto camera = std::make_shared<SFMLjumpgame::Camera>(m_world);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        jumpgame::Clock *clock = jumpgame::Clock::getInstance(30);
        if(clock->tick()){

            window->clear();

            movement(event);

            m_world->update();
            camera->moveForward();
            std::cout << m_world->getMPlayer()->getMReachedheight() << std::endl;

            window->display();
        }

    }
}

void Game::movement(sf::Event &event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_world->playermove(jumpgame::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_world->playermove(jumpgame::Right);
    }
    else if (event.type == sf::Event::KeyReleased &&
        (event.key.code == sf::Keyboard::Left ||
        event.key.code == sf::Keyboard::A ||
        event.key.code == sf::Keyboard::Right ||
        event.key.code == sf::Keyboard::R)) {
        m_world->playermove(jumpgame::Static);

    }

}
