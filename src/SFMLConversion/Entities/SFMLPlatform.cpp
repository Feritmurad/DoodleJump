//
// Created by ferit on 12/17/21.
//

#include "SFMLPlatform.h"

namespace SFMLDoodleJump {

void SFMLPlatform::draw()
{
        std::shared_ptr<DoodleJump::Camera> camera = std::make_shared<DoodleJump::Camera>();
        if (getC().validCoordinate()) {
                DoodleJump::Coordinate tempc = camera->rescale(getC());
                sf::RectangleShape rectangle = makePlatformshape(sf::Color::Green);
                rectangle.setPosition(tempc.getX(), tempc.getY());
                getWindow()->draw(rectangle);
        }
        DoodleJump::Coordinate tempcoord;
        setC(tempcoord);
}

} // namespace SFMLDoodleJump