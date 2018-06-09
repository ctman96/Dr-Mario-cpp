#include <iostream>
#include "Engine/GameEngine.h"
#include "Engine/States/MainMenuState.h"

int main() {
    GameEngine game{};
    game.init();
    GameState *start = new MainMenuState;
    game.changeState(start);

    while(game.isRunning()){
        game.handle();
        game.update();
        game.draw();
    }

    game.terminate();

    return 0;
}