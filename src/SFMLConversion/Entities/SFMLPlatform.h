//
// Created by ferit on 12/17/21.
//

#ifndef JUMPGAME_SFMLPLATFORM_H
#define JUMPGAME_SFMLPLATFORM_H
#include "SFMLObject.h"

namespace SFMLjumpgame {

    class SFMLPlatform : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLPlatform() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLPlatform(const std::shared_ptr<sf::RenderWindow> &window, const jumpgame::Coordinate &c={0,0}) : SFMLObject(window,c) {}

        void handleEvent(const jumpgame::ObserverEvent &event) override;

        void draw(const std::shared_ptr<Camera> &camera);

    };

}


#endif //JUMPGAME_SFMLPLATFORM_H
