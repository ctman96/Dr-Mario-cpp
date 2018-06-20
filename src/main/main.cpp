/*!
 * @author: Cody Newman
 *
 * Created on: 08/06/2018
 */

#include <iostream>
#include "Engine/GameEngine.h"
#include "Engine/States/MainMenuState.h"

int main(int argv, char** args) {
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
    while(game.isRunning()){
        game.handle();
        game.update();
        game.draw();
    }

    game.terminate();

    return 0;
}