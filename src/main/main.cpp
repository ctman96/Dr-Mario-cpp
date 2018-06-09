#include <iostream>
#include "Engine/GameEngine.h"
#include "Engine/States/MainMenuState.h"

int main(int argv, char** args) {
    std::cout << "test" << std::endl;
    GameEngine game{};
    try {
        game.init();
    }
    catch(std::runtime_error &e){
        printf(e.what());
        return -1;
    }
    GameState *start = new MainMenuState;
    game.changeState(start);
    std::cout << "test" << std::endl;
    while(game.isRunning()){
        game.handle();
        game.update();
        game.draw();
    }

    game.terminate();

    return 0;
}