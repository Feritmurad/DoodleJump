//
// Created by ferit on 12/25/21.
//

#include "ConcreteFactory.h"

namespace SFMLjumpgame {

    std::shared_ptr<jumpgame::Observer> ConcreteFactory::createPlayerView() {
        return std::make_shared<SFMLPlayer>(m_window);
    }

    std::shared_ptr<jumpgame::Observer> ConcreteFactory::createPlatformView() {
        return std::make_shared<SFMLPlatform>(m_window);
    }
}
