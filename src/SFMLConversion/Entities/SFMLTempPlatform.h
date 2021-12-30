//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SFMLTEMPPLATFORM_H
#define JUMPGAME_SFMLTEMPPLATFORM_H
#include "SFMLObject.h"

namespace SFMLjumpgame {

    class SFMLTempPlatform : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLTempPlatform() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLTempPlatform(const std::shared_ptr<sf::RenderWindow> &window, const jumpgame::Coordinate &c={0,0}) : SFMLObject(window,c) {}

        void handleEvent(const jumpgame::ObserverEvent &event) override;

        void draw();

    };

}


#endif //JUMPGAME_SFMLTEMPPLATFORM_H
