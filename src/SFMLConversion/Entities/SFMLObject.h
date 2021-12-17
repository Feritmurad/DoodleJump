//
// Created by ferit on 12/16/21.
//

#ifndef JUMPGAME_SFMLOBJECT_H
#define JUMPGAME_SFMLOBJECT_H
#include "SFMLEntity.h"
#include "../../GameLogic/Coordinate/Coordinate.h"
#include "../Camera/Camera.h"

namespace SFMLjumpgame{

class SFMLObject : public SFMLEntity , public jumpgame::Observer {
    public:

        /**
         * default destructor
         */
        ~SFMLObject();

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        SFMLObject(const std::shared_ptr<sf::RenderWindow> &window, const jumpgame::Coordinate &c={0,0}) : SFMLEntity(window),
                                                                                                     m_c(c) {}

    public:

        /**
        * Getter for c
        */
        jumpgame::Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(const jumpgame::Coordinate& m_c);

        void handleEvent() override;

    private:
        jumpgame::Coordinate m_c;
    };

}



#endif //JUMPGAME_SFMLOBJECT_H
