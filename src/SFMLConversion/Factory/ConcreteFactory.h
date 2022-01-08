//
// Created by ferit on 12/25/21.
//

#ifndef JUMPGAME_CONCRETEFACTORY_H
#define JUMPGAME_CONCRETEFACTORY_H
#include "../../GameLogic/Factory/AbstractEntityFactory.h"
#include "../Entities/SFMLPlayer.h"
#include "../Entities/SFMLPlatform.h"
#include "../Entities/SFMLTempPlatform.h"
#include "../Entities/SFMLVerticalPlatform.h"
#include "../Entities/SFMLHorizontalPlatform.h"
#include "../Entities/SFMLJetpack.h"
#include "../Entities/SFMLSprings.h"
#include "../Entities/SFMLBG_Tile.h"


namespace SFMLDoodleJump{

class ConcreteFactory : public DoodleJump::AbstractEntityFactory{

public:

    explicit ConcreteFactory(const std::shared_ptr<sf::RenderWindow> &window) : m_window(window) {}

    std::shared_ptr<DoodleJump::Observer> createPlayerView() override;

    std::shared_ptr<DoodleJump::Observer> createPlatformView() override;

    std::shared_ptr<DoodleJump::Observer> createTempPlatformView() override;

    std::shared_ptr<DoodleJump::Observer> createVerticalPlatformView() override;

    std::shared_ptr<DoodleJump::Observer> createHorizontalPlatformView() override;

    std::shared_ptr<DoodleJump::Observer> createJetpackView() override;

    std::shared_ptr<DoodleJump::Observer> createSpringsView() override;

    std::shared_ptr<DoodleJump::Observer> createBGtileView() override;

private:
    std::shared_ptr<sf::RenderWindow> m_window;




};

}


#endif //JUMPGAME_CONCRETEFACTORY_H
