//
// Created by ferit on 12/25/21.
//

#include "ConcreteFactory.h"

namespace SFMLjumpgame {

    std::shared_ptr<jumpgame::Observer> ConcreteFactory::createPlayerView() {
        setMPlayerview(std::make_shared<SFMLPlayer>(m_window));
        return getMPlayerview();
    }

    std::shared_ptr<jumpgame::Observer> ConcreteFactory::createPlatformView() {
        setMPlatformview(std::make_shared<SFMLPlatform>(m_window));
        return getMPlatformview();
    }
}
