//
// Created by ferit on 15/12/2020.
//

#include "Camera.h"

namespace SFMLjumpgame {

    jumpgame::Coordinate Camera::rescale(jumpgame::Coordinate coordinate){
        double xscale = res_x /7.0;
        double yscale = res_y /9.0;



        double x = (coordinate.getX()+3.0) * xscale;
        double y = ((-coordinate.getY())+4.0) * yscale;

        return {x,y};
    }

}