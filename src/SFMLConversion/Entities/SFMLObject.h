//
// Created by ferit on 12/16/21.
//

#ifndef JUMPGAME_SFMLOBJECT_H
#define JUMPGAME_SFMLOBJECT_H
#include "SFMLEntity.h"
#include "../../GameLogic/Coordinate/Coordinate.h"

namespace SFMLDoodleJump{

    class SFMLObject : public SFMLEntity , public DoodleJump::Observer {
    public:

        /**
         * default destructor
         */
        ~SFMLObject();

        /**
         * Constructior with coordinate
         * @param c: coordinate of object
         */
        explicit SFMLObject(const std::shared_ptr<sf::RenderWindow> &windowconst,const DoodleJump::Coordinate &c={0,0});

    public:

        /**
        * Getter for c
        */
        DoodleJump::Coordinate getC() const;

        /**
         * Setter for c
         */
        void setC(const DoodleJump::Coordinate& c);

        void handleEvent(const DoodleJump::ObserverEvent &event) override;

        virtual void draw();

        virtual sf::RectangleShape makePlatformshape(const sf::Color &color);




    private:
        DoodleJump::Coordinate m_c;


    };

}



#endif //JUMPGAME_SFMLOBJECT_H
