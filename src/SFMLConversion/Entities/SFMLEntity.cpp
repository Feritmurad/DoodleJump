//
// Created by ferit on 07/12/2021.
//

#include "SFMLEntity.h"

namespace SFMLDoodleJump{


    const std::shared_ptr<sf::RenderWindow> &SFMLEntity::getWindow() const {
        return m_window;
    }


}