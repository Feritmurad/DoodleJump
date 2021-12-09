set(CMAKE_CXX_STANDARD 14)

ADD_EXECUTABLE(
        Jumpgame
        main.cpp
        GameLogic/Include/Entities/Entity.h
        GameLogic/Source/Entities/Entity.cpp
        GameLogic/Include/Entities/Player.h
        GameLogic/Source/Entities/Player.cpp
        GameLogic/Include/Entities/World.h
        GameLogic/Source/Entities/World.cpp
        GameLogic/Random.cpp
        GameLogic/Random.h
        GameLogic/Include/Coordinate.h
        GameLogic/Source/Coordinate.cpp
        GameLogic/Include/Entities/Object.h
        GameLogic/Source/Entities/Object.cpp
        GameLogic/Clock.h
        GameLogic/Clock.cpp
        GameLogic/Include/AbstractEntityFactory.h
        GameLogic/Source/AbstractEntityFactory.cpp
        GameLogic/Include/EntityFactory.h
        GameLogic/Source/EntityFactory.cpp
        SFMLConversion/Include/Game.h
        SFMLConversion/Source/Game.cpp
        SFMLConversion/Include/Transformation.h
        SFMLConversion/Source/Transformation.cpp
        SFMLConversion/Include/SFMLEntityFactory.h
        SFMLConversion/Source/SFMLEntityFactory.cpp
        SFMLCONVERSION/Include/Entities/SFMLPlayer.h
        SFMLCONVERSION/Include/Entities/SFMLEntity.h
        )

link_directories(/usr/include/SFML)
INSTALL(TARGETS Jumpgame DESTINATION ${PROJECT_SOURCE_DIR}/bin)

