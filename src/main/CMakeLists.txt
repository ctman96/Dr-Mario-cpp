set(
        SOURCE_FILES

        main.cpp
        Block.cpp Block.h
        Capsule.cpp Capsule.h
        Virus.cpp Virus.h
        Constants.h
        Engine/GameEngine.cpp Engine/GameEngine.h
        Engine/States/GameState.h
        Engine/States/MainMenuState.cpp Engine/States/MainMenuState.h
)



add_executable(
        DrMario
        ${SOURCE_FILES}
        )
target_link_libraries(DrMario ${SDL2_LIBRARY})