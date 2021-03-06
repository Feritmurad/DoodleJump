//
// Created by ferit on 12/25/21.
//

#include "ConcreteFactory.h"

namespace SFMLDoodleJump {

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createPlayerView()
{
        return std::make_shared<SFMLPlayer>(m_window);
}

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createPlatformView()
{
        return std::make_shared<SFMLPlatform>(m_window);
}

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createTempPlatformView()
{
        return std::make_shared<SFMLTempPlatform>(m_window);
}

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createVerticalPlatformView()
{
        return std::make_shared<SFMLVerticalPlatform>(m_window);
}

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createHorizontalPlatformView()
{
        return std::make_shared<SFMLHorizontalPlatform>(m_window);
}

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createJetpackView()
{
        return std::make_shared<SFMLJetpack>(m_window);
}

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createSpringsView()
{
        return std::make_shared<SFMLSprings>(m_window);
}

std::shared_ptr<DoodleJump::Observer> ConcreteFactory::createBGtileView()
{
        return std::make_shared<SFMLBG_Tile>(m_window);
}

} // namespace SFMLDoodleJump
