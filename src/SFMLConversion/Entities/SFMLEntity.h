//
// Created by ferit on 07/12/2021.
//

#ifndef JUMPGAME_SFMLENTITY_H
#define JUMPGAME_SFMLENTITY_H
#include <SFML/Graphics.hpp>
#include "../Camera/Camera.h"
#include "../../GameLogic/Entities/Entity.h"
#include "../../GameLogic/Observer/Observer.h"
#include "iostream"

namespace SFMLjumpgame {

    class SFMLEntity {
        public:
            /**
             * default constructor
             */
            SFMLEntity(const std::shared_ptr<sf::RenderWindow>& window) : m_window(window) {}

            /**
             * default destructor
             */
            ~SFMLEntity();

            /**
            * Getter for m_window
            */
            const std::shared_ptr<sf::RenderWindow>& getWindow() const;

        private:
        std::shared_ptr<sf::RenderWindow> m_window;
    };

}


#endif //JUMPGAME_SFMLENTITY_H
