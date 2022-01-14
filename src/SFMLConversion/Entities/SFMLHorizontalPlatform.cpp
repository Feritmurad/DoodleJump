//
// Created by ferit on 12/29/21.
//

#include "SFMLHorizontalPlatform.h"
namespace SFMLDoodleJump {

void SFMLHorizontalPlatform::draw()
{
        std::shared_ptr<DoodleJump::Camera> camera = std::make_shared<DoodleJump::Camera>();
        // transform to pixel
        // transform only if it is in geocoordintes
        if (getC().validCoordinate()) {
                DoodleJump::Coordinate tempc = camera->rescale(getC());
                sf::RectangleShape rectangle = makePlatformshape(sf::Color::Blue);
                rectangle.setPosition(tempc.getX(), tempc.getY());
                getWindow()->draw(rectangle);
        }
        DoodleJump::Coordinate tempcoord;
        setC(tempcoord);
}
} // namespace SFMLDoodleJump