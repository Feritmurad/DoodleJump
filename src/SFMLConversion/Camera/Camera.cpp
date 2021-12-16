//
// Created by ferit on 15/12/2020.
//

#include "Camera.h"

namespace SFMLjumpgame {

    jumpgame::Coordinate Camera::rescale(jumpgame::Coordinate coordinate){
        double xscale = res_x /8.0;
        double yscale = res_y /6.0;

        double x = coordinate.getX() * xscale;
        double y = -coordinate.getY() * yscale;

        return {x,y};
    }

}