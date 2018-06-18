//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_GAMEENGINE_H
#define DRMARIO_GAMEENGINE_H

#include <SDL_mixer.h>
#include "SDL.h"

class GameState;

class GameEngine {
public:
    void init();
    void terminate();

    void changeState(GameState *state);

    void handle();
    void update();
    void draw();

    bool isRunning(){return running;}
    void quit() {running = false;}

    SDL_Window* window;
    SDL_Surface* screen;
    SDL_Renderer* renderer;
    Mix_Music * music;

private:
    bool running;
    GameState *state;
};


#endif //DRMARIO_ENGINE_H
