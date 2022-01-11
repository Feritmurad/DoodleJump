//
// Created by ferit on 12/23/21.
//

#ifndef JUMPGAME_VERTICALPLATFORM_H
#define JUMPGAME_VERTICALPLATFORM_H
#include "Platform.h"
#include "iostream"


namespace DoodleJump {

    class VerticalPlatform : public Platform {

    public:

        /**
         * Simple constructor
         * @param c: coordinate of the object
         * @param Yvelocity: vertical velocity
         * @param height: Height of the object
         * @param width: Width of the object
         * @param jumped: indicates if the player has jumped on this platform before
         */
        explicit VerticalPlatform(const Coordinate &c,const double &Yvelocity = -0.075, const double &height = 0.4, const double &width = 1,
                                    const bool &jumped = false);
        /**
         * Default destructor
         */
        ~VerticalPlatform() override = default;

        /**
         * Update the object and notify observers
         */
        void update() override;

        /**
         * virtual function that updates score
         */
        void updateScore() override;

        /**
         * Moves the vertical platform
         */
        void move();

        ////////////////// Getters and Setters //////////////////
        double getMMinH() const;

        void updateMMinH(double mMinH);

        double getMMaxH() const;

        void updateMMaxH(double mMaxH);
        /////////////////////////////////////////////////////////

    private:

        double m_velocity_Y;

        double m_minH;

        double m_maxH;
    };

}


#endif //JUMPGAME_VERTICALPLATFORM_H
