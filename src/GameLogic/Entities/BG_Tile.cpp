//
// Created by ferit on 1/2/22.
//

#include "BG_Tile.h"

void jumpgame::BG_Tile::update() {
    std::cout<< "bgtile" << getC().getX() << "," << getC().getY() << std::endl;
    jumpgame::ObserverEvent observerevent(0,getC());
    notifyObservers(observerevent);
}
