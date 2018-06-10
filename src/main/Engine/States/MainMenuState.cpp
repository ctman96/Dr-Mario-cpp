//
// Created by Cody on 6/8/2018.
//

#include <SDL_image.h>
#include "MainMenuState.h"

void MainMenuState::init() {
    //SDL_Surface* tmp = IMG_Load()
}

void MainMenuState::terminate() {

}

void MainMenuState::handle(GameEngine *game) {
    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                game->quit();
                break;
            default:
                break;
        }
    }
}

void MainMenuState::update(GameEngine *game) {

}

void MainMenuState::draw(GameEngine *game) {

}
