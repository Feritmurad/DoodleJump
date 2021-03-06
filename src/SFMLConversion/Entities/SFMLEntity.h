//
// Created by ferit on 07/12/2021.
//

#ifndef JUMPGAME_SFMLENTITY_H
#define JUMPGAME_SFMLENTITY_H
#include "../../GameLogic/Camera/Camera.h"
#include "../../GameLogic/Observer/Observer.h"
#include "iostream"
#include <SFML/Graphics.hpp>

namespace SFMLDoodleJump {

class SFMLEntity
{
public:
        /**
         * default constructor
         */
        explicit SFMLEntity(const std::shared_ptr<sf::RenderWindow>& window) : m_window(window) {}

        /**
         * default destructor
         */
        virtual ~SFMLEntity() = default;
        ;

        /**
         * Getter for m_window
         */
        const std::shared_ptr<sf::RenderWindow>& getWindow() const;

private:
        std::shared_ptr<sf::RenderWindow> m_window;
};

} // namespace SFMLDoodleJump

#endif // JUMPGAME_SFMLENTITY_H
