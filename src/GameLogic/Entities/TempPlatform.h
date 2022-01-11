//
// Created by ferit on 12/23/21.
//

#ifndef JUMPGAME_TEMPPLATFORM_H
#define JUMPGAME_TEMPPLATFORM_H
#include "Platform.h"

namespace DoodleJump {

    class TempPlatform : public Platform {

    public:
        /**
         * Constructor
         * @param c: coordinate of the object
         * @param height: Height of the object
         * @param width: Width of the object
         * @param jumped: indicates if the player has jumped on this platform before
         */
        explicit TempPlatform(const Coordinate &c,const double &height=0.4,const double &width=1, const bool &jumped = false) : Platform(c,height,width,jumped) {}

        /**
         * Default destructor
         */
        ~TempPlatform() override = default;

        /**
         * Update the object and notify observers
         */
        void update() override;

        /**
         * virtual function that updates score
         */
        void updateScore() override;
    };
}


#endif //JUMPGAME_TEMPPLATFORM_H
