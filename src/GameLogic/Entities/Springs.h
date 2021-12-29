//
// Created by ferit on 12/29/21.
//

#ifndef JUMPGAME_SPRINGS_H
#define JUMPGAME_SPRINGS_H

#include "Object.h"

namespace jumpgame {

    class Springs : public Object {
    public:
        explicit Springs(const Coordinate &c, const double &height = 0.4, const double &width = 1,
                         const bool &jumped = false) : Object(c, height, width) {}

        ~Springs() = default;

        void update() override;

        bool isUsed() const;

        void setUsed(bool used);

    private:
        bool used;

    };
}
#endif //JUMPGAME_SPRINGS_H
