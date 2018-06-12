set(
        SOURCE_FILES

        main.cpp
        resources.h
        Constants.h
        Block.cpp Block.h
        Capsule.cpp Capsule.h
        Virus.cpp Virus.h
        Engine/GameEngine.cpp Engine/GameEngine.h
        Engine/RenderUtils.h
        Engine/States/GameState.h
        Engine/States/MainMenuState.cpp Engine/States/MainMenuState.h
        Engine/States/OptionsState.cpp Engine/States/OptionsState.h Engine/RenderUtils.cpp)



add_executable(
        DrMario
        ${SOURCE_FILES}
        )
target_link_libraries(DrMario ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})