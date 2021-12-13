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
        GameLogic/Factory/EntityFactory.h
        GameLogic/Factory/EntityFactory.cpp
        Gamelogic/Observer/Observer.h
        GameLogic/Observer/Observer.cpp
        GameLogic/Observer/Observable.h
        GameLogic/Observer/Observable.cpp
        GameLogic/Score/Score.h
        GameLogic/Score/Score.cpp
        SFMLConversion/Game/Game.h
        SFMLConversion/Game/Game.cpp
        SFMLConversion/Camera/Camera.h
        SFMLConversion/Camera/Camera.cpp
        SFMLConversion/SFMLFactory/SFMLEntityFactory.h
        SFMLConversion/SFMLFactory/SFMLEntityFactory.cpp
        SFMLConversion/Entities/SFMLPlayer.h
        SFMLConversion/Entities/SFMLEntity.h
        )

link_directories(/usr/include/SFML)
INSTALL(TARGETS Jumpgame DESTINATION ${PROJECT_SOURCE_DIR}/bin)

