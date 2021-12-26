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
        SFMLConversion/Camera/Camera.h
        SFMLConversion/Camera/Camera.cpp
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
        SFMLConversion/Factory/ConcreteFactory.h)

TARGET_LINK_LIBRARIES (Jumpgame sfml-graphics sfml-window sfml-system sfml-audio)
INSTALL(TARGETS Jumpgame DESTINATION ${PROJECT_SOURCE_DIR}/bin)

