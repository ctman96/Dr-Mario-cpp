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
        std::string msg = "SDL could not be initialized. SDL Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    // Create window
    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::string msg = "Window could not be created. SDL Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    // Set scaling interpolation algorithm
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::string msg = "Renderer could not be created. SDL Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    //Initialize image loading
    int flags = IMG_INIT_PNG;
    int imginit = IMG_Init(flags);
    if((imginit&flags) != flags){
        std::string msg = "SLD_image could not be initialized. SDL_image Error: ";
        std::string error = IMG_GetError();
        throw std::runtime_error(msg+error);
    }

    screen = SDL_GetWindowSurface(window);

    running = true;
}

//Clean up and close the game
void GameEngine::terminate() {
    // Clean up the current state
    if (state != nullptr){
        state->terminate();
    }
    delete(state);
    state = nullptr;

    // Destroy renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    renderer, screen, window = nullptr;

    // Quit SDL
    IMG_Quit();
    SDL_Quit();
}

//Change the game state
void GameEngine::changeState(GameState *state) {
    this->state = state;
    state->init(this);
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
