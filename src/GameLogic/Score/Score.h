//
// Created by ferit on 10/12/2021.
//

#ifndef JUMPGAME_SCORE_H
#define JUMPGAME_SCORE_H

#include "../Observer/Observer.h"

namespace jumpgame {

    class Score : public Observer {
    public:
        /**
         * Simple constructor where @player_score is 0
         */
        Score() : player_score(0) {}

        /**
        * overriden function to handle a event
        * @param update_amount: amount that has to be added to score
        */
        void handleEvent(int update_amount) override;

    private:
        int player_score;

    };
}

#endif //JUMPGAME_SCORE_H
