//
// Created by ferit on 07/12/2021.
//

#ifndef JUMPGAME_SFMLENTITY_H
#define JUMPGAME_SFMLENTITY_H
#include <SFML/Graphics.hpp>
#include "../Camera/Camera.h"
#include "../../GameLogic/Entities/Entity.h"

namespace SFMLjumpgame {

    class SFMLEntity {
        public:
            /**
             * default constructor
             */
            SFMLEntity(const std::shared_ptr<sf::RenderWindow> &window) : m_window(window) {}

            /**
            * Getter for m_window
            */
            const std::shared_ptr<sf::RenderWindow>& getWindow() const;

            virtual void draw() = 0;

        private:
        std::shared_ptr<sf::RenderWindow> m_window;
    };

}


#endif //JUMPGAME_SFMLENTITY_H
