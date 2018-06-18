set(
        SOURCE_FILES

        main.cpp
        Constants.h
        Board/Block.cpp Board/Block.h
        Board/Capsule.cpp Board/Capsule.h
        Board/Virus.cpp Board/Virus.h
        Engine/GameEngine.cpp Engine/GameEngine.h
        Engine/RenderUtils.cpp Engine/RenderUtils.h
        GameUtils.cpp GameUtils.h
        Engine/States/GameState.h
        Engine/States/MainMenuState.cpp Engine/States/MainMenuState.h
        Engine/States/OptionsState.cpp Engine/States/OptionsState.h
        Engine/States/SinglePlayerState.cpp Engine/States/SinglePlayerState.h Board/Board.cpp Board/Board.h Board/DrawableObject.h)
file(GLOB RESOURCE_FILES Resources/*.h)


add_executable(
        DrMario
        ${SOURCE_FILES}
        ${RESOURCE_FILES}
        )
target_link_libraries(DrMario ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})