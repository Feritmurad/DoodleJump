//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_SCORE_H
#define JUMPGAME_SCORE_H

#include "../Observer/Observer.h"

namespace DoodleJump {

class Score : public Observer
{
public:
        /**
         * Simple constructor where @player_score is 0
         */
        Score() : player_score(0) {}

        ~Score() = default;

        /**
         * overriden function to handle a event
         */
        void handleEvent(const ObserverEvent& event) override;

        int getPlayerScore() const;

private:
        int player_score;
};
} // namespace DoodleJump

#endif // JUMPGAME_SCORE_H
