//
// Created by ferit on 1/2/22.
//

#include "BG_Tile.h"
namespace DoodleJump {

void BG_Tile::update()
{
        ObserverEvent observerevent(0, getC());
        notifyObservers(observerevent);
}
} // namespace DoodleJump