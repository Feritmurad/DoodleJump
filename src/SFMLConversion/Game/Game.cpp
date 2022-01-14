//
// Created by ferit on 05/12/2021.
//

#include "Game.h"
void Game::run()
{
        auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(700, 900), "DoodleJump");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        // make World
        m_world = std::make_shared<DoodleJump::World>(std::make_shared<SFMLDoodleJump::ConcreteFactory>(window));
        m_world->makeWorld();

        auto camera = std::make_shared<DoodleJump::Camera>(m_world);

        while (window->isOpen()) {
                sf::Event event;
                while (window->pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                                window->close();
                }
                DoodleJump::Clock* clock = DoodleJump::Clock::getInstance(30);
                if (clock->tick()) {

                        window->clear();

                        movement(event);

                        m_world->update();
                        camera->moveForward();
                        ScoreText(window);
                        window->display();
                        GameOver(window);
                }
        }
}

void Game::movement(sf::Event& event)
{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                m_world->playermove(DoodleJump::Left);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                m_world->playermove(DoodleJump::Right);
        } else if (event.type == sf::Event::KeyReleased &&
                   (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A ||
                    event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)) {
                m_world->playermove(DoodleJump::Static);
        }
}

void Game::ScoreText(const std::shared_ptr<sf::RenderWindow>& window)
{
        sf::Font font;
        font.loadFromFile("Font/drivecorps.ttf");
        sf::Text text;
        text.setFont(font);
        std::string message = "Score: " + to_string(m_world->getMScore()->getPlayerScore());
        text.setString(message);
        text.setFillColor(sf::Color::Red);
        text.setCharacterSize(40);
        window->draw(text);
}

void Game::GameOver(const shared_ptr<sf::RenderWindow>& window)
{
        if (m_world->getMPlayer()->getC().validCoordinate()) {
                return;
        } else {
                window->clear();
                sf::Font font;
                font.loadFromFile("Font/drivecorps.ttf");
                sf::Text text;
                text.setFont(font);
                std::string message = "Your score: " + to_string(m_world->getMScore()->getPlayerScore());
                text.setString(message);
                text.setFillColor(sf::Color::Red);
                text.setCharacterSize(50);
                sf::FloatRect textRect = text.getLocalBounds();
                text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
                text.setPosition(sf::Vector2f(700 / 2.0f, 900 / 2.0f));

                sf::Text gameover;
                gameover.setFont(font);
                std::string gameovermessage = "Game Over";
                gameover.setString(gameovermessage);
                gameover.setFillColor(sf::Color::Red);
                gameover.setCharacterSize(50);
                sf::FloatRect gameoverRect = gameover.getLocalBounds();
                gameover.setOrigin(gameoverRect.left + gameoverRect.width / 2.0f,
                                   gameoverRect.top + gameoverRect.height / 2.0f);
                gameover.setPosition(sf::Vector2f(700 / 2.0f, 900 / 2.0 - 100));

                string line;
                bool highscore = false;
                string highestscoretxt;
                ifstream myfile("Highestscore.txt");
                if (myfile.is_open()) {

                        while (getline(myfile, line)) {
                                highestscoretxt = line;
                                if (std::stoi(line) < m_world->getMScore()->getPlayerScore()) {
                                        highscore = true;
                                }
                        }
                        myfile.close();
                }
                if (highscore) {
                        ofstream myfile2;
                        myfile2.open("Highestscore.txt", ios::out | ios::trunc);
                        highestscoretxt = to_string(m_world->getMScore()->getPlayerScore());
                        myfile2 << highestscoretxt;
                        myfile2.close();
                }

                sf::Text highestscore;
                highestscore.setFont(font);
                std::string highestscoremessage = "Highest Score: " + highestscoretxt;
                highestscore.setString(highestscoremessage);
                highestscore.setFillColor(sf::Color::Red);
                highestscore.setCharacterSize(50);
                sf::FloatRect highestscoreRect = highestscore.getLocalBounds();
                highestscore.setOrigin(highestscoreRect.left + highestscoreRect.width / 2.0f,
                                       highestscoreRect.top + highestscoreRect.height / 2.0f);
                highestscore.setPosition(sf::Vector2f(700 / 2.0f, 900 / 2.0 + 100));

                window->draw(highestscore);
                window->draw(gameover);
                window->draw(text);
                window->display();
                while (window->isOpen()) {
                        sf::Event event;
                        while (window->pollEvent(event)) {
                                if (event.type == sf::Event::Closed)
                                        window->close();
                        }
                }
        }
}
