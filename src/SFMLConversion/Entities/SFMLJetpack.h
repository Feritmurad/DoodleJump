//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SFMLJETPACK_H
#define JUMPGAME_SFMLJETPACK_H
#include "SFMLObject.h"


namespace SFMLjumpgame {

    class SFMLJetpack : public SFMLObject {
    public:

        /**
        * default destructor
        */
        ~SFMLJetpack() = default;

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLJetpack(const std::shared_ptr<sf::RenderWindow> &window, const jumpgame::Coordinate &c={0,0}) : SFMLObject(window,c) {}

        void handleEvent(const jumpgame::ObserverEvent &event) override;

        void draw();

    };

}


#endif //JUMPGAME_SFMLJETPACK_H
