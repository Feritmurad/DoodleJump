//
// Created by ferit on 10/12/2021.
//

#include "Score.h"

namespace jumpgame{

    void Score::handleEvent(const ObserverEvent &event){
        if(event.getMUpdateAmount() != 0){
            player_score+= event.getMUpdateAmount();
        }
    }

    int Score::getPlayerScore() const {
        return player_score;
    }

}