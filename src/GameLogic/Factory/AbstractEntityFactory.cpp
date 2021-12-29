//
// Created by ferit on 19/12/2020.
//

#include "AbstractEntityFactory.h"

namespace jumpgame {

    const std::shared_ptr<Observer> &jumpgame::AbstractEntityFactory::getMPlayerview() const {
        return m_Playerview;
    }

    const std::shared_ptr<Observer> &jumpgame::AbstractEntityFactory::getMPlatformview() const {
        return m_Platformview;
    }

    void AbstractEntityFactory::setMPlayerview(const std::shared_ptr<Observer> &mPlayerview) {
        m_Playerview = mPlayerview;
    }

    void AbstractEntityFactory::setMPlatformview(const std::shared_ptr<Observer> &mPlatformview) {
        m_Platformview = mPlatformview;
    }
}