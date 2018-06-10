//
// Created by Cody on 6/8/2018.
//

#include <iostream>
#include <SDL_image.h>
#include "GameEngine.h"
#include "States/GameState.h"
#include "../Constants.h"

//Initialize the game engine - SDL setup
void GameEngine::init() {
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::string msg = "SDL could not be initialized. SDL_GetError: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    // Create Window
    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::string msg = "Window could not be created. SDL_GetError: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    //Initialize image loading
    int flags = IMG_INIT_PNG;
    int imginit = IMG_Init(flags);
    if((imginit&flags) != flags){
        std::string msg = "SLD_image could not be initialized. IMG_GetError: ";
        std::string error = IMG_GetError();
        throw std::runtime_error(msg+error);
    }

    screen = SDL_GetWindowSurface(window);

    running = true;
}

//Clean up and close the game
void GameEngine::terminate() {
    if (state != nullptr){
        state->terminate();
    }
    SDL_Quit();
}

//Change the game state
void GameEngine::changeState(GameState *state) {
    this->state = state;
}

//Handle SDL events
void GameEngine::handle() {
    state->handle(this);
}

//Update the game state
void GameEngine::update() {
    state->update(this);
}

// Render the game state
void GameEngine::draw() {
    state->draw(this);
}
