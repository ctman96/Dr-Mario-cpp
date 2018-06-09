//
// Created by Cody on 6/8/2018.
//

#include <iostream>
#include "GameEngine.h"
#include "States/GameState.h"
#include "../Constants.h"

//Initialize the game engine - SDL setup
void GameEngine::init() {

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::string msg = "SDL could not be initialized. SDL_Error: ";
        std::string error = SDL_GetError();
        throw std::runtime_error(msg+error);
    }

    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr){
        std::string msg = "Window could not be created. SDL_Error: ";
        std::string error = SDL_GetError();
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
    quit();
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
