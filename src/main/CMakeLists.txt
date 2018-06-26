set(
        SOURCE_FILES

        main.cpp
        Constants.h
        enums.h
        Board/DrawableObject.h
        Board/Block.cpp Board/Block.h
        Board/Capsule.cpp Board/Capsule.h
        Board/Virus.cpp Board/Virus.h
        Board/Board.cpp Board/Board.h
        Board/GameUtils.cpp Board/GameUtils.h
        Engine/GameEngine.cpp Engine/GameEngine.h
        Engine/Rendering/RenderUtils.cpp Engine/Rendering/RenderUtils.h
        Engine/States/GameState.h
        Engine/States/MainMenuState.cpp Engine/States/MainMenuState.h
        Engine/States/OptionsState.cpp Engine/States/OptionsState.h
        Engine/States/SinglePlayerState.cpp Engine/States/SinglePlayerState.h Engine/Rendering/Sprite.cpp Engine/Rendering/Sprite.h Engine/Rendering/AnimatedSprite.cpp Engine/Rendering/AnimatedSprite.h)

file(GLOB RESOURCE_FILES Resources/*.h)


add_executable(
        DrMario
        ${SOURCE_FILES}
        ${RESOURCE_FILES}
        )
target_link_libraries(DrMario ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})