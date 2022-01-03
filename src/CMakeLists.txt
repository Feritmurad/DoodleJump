set(CMAKE_CXX_STANDARD 14)

ADD_EXECUTABLE(
        Jumpgame
        main.cpp
        GameLogic/Entities/Entity.h
        GameLogic/Entities/Entity.cpp
        GameLogic/Entities/Player.h
        GameLogic/Entities/Player.cpp
        GameLogic/Entities/World.h
        GameLogic/Entities/World.cpp
        GameLogic/Utility/Random.cpp
        GameLogic/Utility/Random.h
        GameLogic/Coordinate/Coordinate.h
        GameLogic/Coordinate/Coordinate.cpp
        GameLogic/Entities/Object.h
        GameLogic/Entities/Object.cpp
        GameLogic/Utility/Clock.h
        GameLogic/Utility/Clock.cpp
        GameLogic/Factory/AbstractEntityFactory.h
        GameLogic/Factory/AbstractEntityFactory.cpp
        GameLogic/Observer/Observer.h
        GameLogic/Observer/Observer.cpp
        GameLogic/Observer/Observable.h
        GameLogic/Observer/Observable.cpp
        GameLogic/Score/Score.h
        GameLogic/Score/Score.cpp
        GameLogic/Observer/ObserverEvent.cpp
        GameLogic/Observer/ObserverEvent.h
        GameLogic/Entities/Platform.cpp
        GameLogic/Entities/Platform.h
        SFMLConversion/Game/Game.h
        SFMLConversion/Game/Game.cpp
        GameLogic/Camera/Camera.h
        GameLogic/Camera/Camera.cpp
        SFMLConversion/Entities/SFMLPlayer.h
        SFMLConversion/Entities/SFMLPlayer.cpp
        SFMLConversion/Entities/SFMLEntity.h
        SFMLConversion/Entities/SFMLEntity.cpp
        SFMLConversion/Entities/SFMLObject.cpp
        SFMLConversion/Entities/SFMLObject.h
        SFMLConversion/Entities/SFMLPlatform.cpp
        SFMLConversion/Entities/SFMLPlatform.h
        GameLogic/Entities/TempPlatform.cpp
        GameLogic/Entities/TempPlatform.h
        GameLogic/Entities/HorizontalPlatform.cpp
        GameLogic/Entities/HorizontalPlatform.h
        GameLogic/Entities/VerticalPlatform.cpp
        GameLogic/Entities/VerticalPlatform.h
        SFMLConversion/Factory/ConcreteFactory.cpp
        SFMLConversion/Factory/ConcreteFactory.h GameLogic/Entities/jetpack.cpp GameLogic/Entities/jetpack.h GameLogic/Entities/Springs.cpp GameLogic/Entities/Springs.h SFMLConversion/Entities/SFMLJetpack.cpp SFMLConversion/Entities/SFMLJetpack.h SFMLConversion/Entities/SFMLSprings.cpp SFMLConversion/Entities/SFMLSprings.h SFMLConversion/Entities/SFMLTempPlatform.cpp SFMLConversion/Entities/SFMLTempPlatform.h SFMLConversion/Entities/SFMLVerticalPlatform.cpp SFMLConversion/Entities/SFMLVerticalPlatform.h SFMLConversion/Entities/SFMLHorizontalPlatform.cpp SFMLConversion/Entities/SFMLHorizontalPlatform.h GameLogic/Entities/Bonus.cpp GameLogic/Entities/Bonus.h GameLogic/Entities/BG_Tile.cpp GameLogic/Entities/BG_Tile.h SFMLConversion/Entities/SFMLBG_Tile.cpp SFMLConversion/Entities/SFMLBG_Tile.h)

TARGET_LINK_LIBRARIES (Jumpgame sfml-graphics sfml-window sfml-system sfml-audio)
INSTALL(TARGETS Jumpgame DESTINATION ${PROJECT_SOURCE_DIR}/bin)

