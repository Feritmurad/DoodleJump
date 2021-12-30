;//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SFMLHORIZONTALPLATFORM_H
#define JUMPGAME_SFMLHORIZONTALPLATFORM_H
#include "SFMLObject.h"

namespace SFMLjumpgame {

    class SFMLHorizontalPlatform : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLHorizontalPlatform() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLHorizontalPlatform(const std::shared_ptr<sf::RenderWindow> &window, const jumpgame::Coordinate &c={0,0}) : SFMLObject(window,c) {}

        void handleEvent(const jumpgame::ObserverEvent &event) override;

        void draw();

    };

}



#endif //JUMPGAME_SFMLHORIZONTALPLATFORM_H
