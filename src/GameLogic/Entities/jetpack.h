//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_JETPACK_H
#define JUMPGAME_JETPACK_H
#include "Object.h"

namespace jumpgame {

    class Jetpack : public Object {
    public:
        explicit Jetpack(const Coordinate &c, const double &height = 0.4, const double &width = 1,
                         const bool &jumped = false) : Object(c, height, width) {}

        ~Jetpack() = default;

        void update() override;

        bool isUsed() const;

        void setUsed(bool used);

    private:
        bool used;

    };
}

#endif //JUMPGAME_JETPACK_H
