//
// Created by Cody on 6/10/2018.
//

#include "OptionsState.h"

void OptionsState::init(GameEngine *game) {

}

void OptionsState::terminate() {

}

void OptionsState::handle(GameEngine *game) {
    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                game->quit();
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_s:
                    case SDLK_DOWN:
                        //TODO
                        break;
                    case SDLK_w:
                    case SDLK_UP:
                        //TODO
                        break;
                    case SDLK_d:
                    case SDLK_RIGHT:
                        //TODO
                        break;
                    case SDLK_a:
                    case SDLK_LEFT:
                        //TODO
                        break;
                    case SDLK_KP_ENTER:
                        //TODO
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void OptionsState::update(GameEngine *game) {

}

void OptionsState::draw(GameEngine *game) {

}
