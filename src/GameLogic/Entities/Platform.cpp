//
// Created by ferit on 12/17/21.
//

#include "Platform.h"

namespace jumpgame {


    void Platform::update() {
        jumpgame::ObserverEvent observerevent(0,getC());
        notifyObservers(observerevent);
        if(m_bonus != nullptr){
            Coordinate bonuscoord(getC().getX()+(getMWidth()/2)-0.1,getC().getY()+m_bonus->getMHeigth());
            m_bonus->setC(bonuscoord);
            m_bonus->update();
        }
    }



    void Platform::setMJumpedOn(bool mJumpedOn) {
        m_jumpedOn = mJumpedOn;
    }

    bool Platform::isMJumpedOn() const {
        return m_jumpedOn;
    }

    const std::shared_ptr<Bonus> &Platform::getMBonus() const {
        return m_bonus;
    }

    void Platform::setMBonus(const std::shared_ptr<Bonus> &mBonus) {
        m_bonus = mBonus;
    }

}