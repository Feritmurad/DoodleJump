//
// Created by ferit on 12/23/21.
//

#ifndef JUMPGAME_TEMPPLATFORM_H
#define JUMPGAME_TEMPPLATFORM_H
#include "Platform.h"

namespace DoodleJump {

    class TempPlatform : public Platform {
    public:

        explicit TempPlatform(const Coordinate &c,const double &height=0.4,const double &width=1, const bool &jumped = false) : Platform(c,height,width,jumped) {}

        void update() override;

        void updateScore() override;

    };

}


#endif //JUMPGAME_TEMPPLATFORM_H
