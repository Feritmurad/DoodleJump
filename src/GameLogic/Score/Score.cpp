//
// Created by ferit on 10/12/2021.
//

#include "Score.h"

namespace jumpgame{

    void Score::handleEvent(int update_amount){
        player_score +=update_amount;
    }

}