//
// Created by ferit on 12/25/21.
//

#ifndef JUMPGAME_CONCRETEFACTORY_H
#define JUMPGAME_CONCRETEFACTORY_H
#include "../../GameLogic/Factory/AbstractEntityFactory.h"
#include "../Entities/SFMLBG_Tile.h"
#include "../Entities/SFMLHorizontalPlatform.h"
#include "../Entities/SFMLJetpack.h"
#include "../Entities/SFMLPlatform.h"
#include "../Entities/SFMLPlayer.h"
#include "../Entities/SFMLSprings.h"
#include "../Entities/SFMLTempPlatform.h"
#include "../Entities/SFMLVerticalPlatform.h"

namespace SFMLDoodleJump {

class ConcreteFactory : public DoodleJump::AbstractEntityFactory
{

public:
        /**
         * Constructor
         * @param window
         */
        explicit ConcreteFactory(const std::shared_ptr<sf::RenderWindow>& window) : m_window(window) {}

        /**
         * Default Destructor
         */
        ~ConcreteFactory() override = default;

        /**
         * overriden fucntion to create an SFMLPlayer
         */
        std::shared_ptr<DoodleJump::Observer> createPlayerView() override;

        /**
         * overriden fucntion to create an SFMLPlatform
         */
        std::shared_ptr<DoodleJump::Observer> createPlatformView() override;

        /**
         * overriden fucntion to create an SFMLTempPlatform
         */
        std::shared_ptr<DoodleJump::Observer> createTempPlatformView() override;

        /**
         * overriden fucntion to create an SFMLVerticalPlatform
         */
        std::shared_ptr<DoodleJump::Observer> createVerticalPlatformView() override;

        /**
         * overriden fucntion to create an SFMLHorizontalPlatform
         */
        std::shared_ptr<DoodleJump::Observer> createHorizontalPlatformView() override;

        /**
         * overriden fucntion to create an SFMLJetpack
         */
        std::shared_ptr<DoodleJump::Observer> createJetpackView() override;

        /**
         * overriden fucntion to create an SFMLSprings
         */
        std::shared_ptr<DoodleJump::Observer> createSpringsView() override;

        /**
         * overriden fucntion to create an SFMLBGtile
         */
        std::shared_ptr<DoodleJump::Observer> createBGtileView() override;

private:
        std::shared_ptr<sf::RenderWindow> m_window;
};

} // namespace SFMLDoodleJump

#endif // JUMPGAME_CONCRETEFACTORY_H
