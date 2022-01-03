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


namespace SFMLjumpgame{

class ConcreteFactory : public jumpgame::AbstractEntityFactory{

public:

    explicit ConcreteFactory(const std::shared_ptr<sf::RenderWindow> &window) : m_window(window) {}

    std::shared_ptr<jumpgame::Observer> createPlayerView() override;

    std::shared_ptr<jumpgame::Observer> createPlatformView() override;

    std::shared_ptr<jumpgame::Observer> createTempPlatformView() override;

    std::shared_ptr<jumpgame::Observer> createVerticalPlatformView() override;

    std::shared_ptr<jumpgame::Observer> createHorizontalPlatformView() override;

    std::shared_ptr<jumpgame::Observer> createJetpackView() override;

    std::shared_ptr<jumpgame::Observer> createSpringsView() override;

    std::shared_ptr<jumpgame::Observer> createBGtileView() override;

private:
    std::shared_ptr<sf::RenderWindow> m_window;




};

}


#endif //JUMPGAME_CONCRETEFACTORY_H
