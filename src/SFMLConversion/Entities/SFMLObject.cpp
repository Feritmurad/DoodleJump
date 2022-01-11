//
// Created by ferit on 12/16/21.
//

#include "SFMLObject.h"

namespace SFMLDoodleJump {

    DoodleJump::Coordinate SFMLObject::getC() const {
        return m_c;
    }

    void SFMLObject::setC(const DoodleJump::Coordinate& c) {
        SFMLObject::m_c = c;
    }

    void SFMLObject::handleEvent(const DoodleJump::ObserverEvent &event) {
        if(event.getMUpdateAmount() == 0 && event.getMBonusevent() == DoodleJump::NoBonus){
            setC(event.getMCoordinate());
            draw();
        }
    }

    void SFMLObject::draw() {

    }

    SFMLObject::SFMLObject(const shared_ptr<sf::RenderWindow> &window, const DoodleJump::Coordinate &c
                           ) : SFMLEntity(window),m_c(c){

    }

    sf::RectangleShape SFMLObject::makePlatformshape(const sf::Color &color) {
        sf::RectangleShape rectangle(sf::Vector2f(100.f, 40.f));
        rectangle.setFillColor(color);
        rectangle.setOutlineThickness(2);
        rectangle.setOutlineColor(sf::Color::Black);
        return rectangle;
    }




}