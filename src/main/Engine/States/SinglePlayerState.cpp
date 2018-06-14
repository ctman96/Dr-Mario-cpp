//
// Created by Cody on 13/06/2018.
//

#include <SDL_image.h>
#include "SinglePlayerState.h"
#include "../../resources.h"

SinglePlayerState::SinglePlayerState(int level, Speed speed, Music music){
    // TODO Keep this handling? Or give an exception?
    if (level < 0){
        this->level = 0;
    }
    else if (level > 20){
        this->level = 20;
    }
    else{
        this->level = level;
    }

    this->speed = speed;
    this->music = music;
}

void SinglePlayerState::init(GameEngine *game) {
    // Load the spritesheet from memory into a surface
    SDL_RWops *io = SDL_RWFromConstMem(spr_game_png, sizeof(spr_game_png));
    SDL_Surface* tmp = IMG_LoadPNG_RW(io);

    // Create a texture from the surface
    spritesheet = SDL_CreateTextureFromSurface(game->renderer, tmp);

    // Get rid of temp surface
    SDL_FreeSurface(tmp);

    // Create the sprites
    //loadSprites();


    //TODO: load music depending on music

    //TODO: load the level

}

void SinglePlayerState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;
}

void SinglePlayerState::handle(GameEngine *game) {
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
                    case SDLK_a:
                    case SDLK_LEFT:
                        //TODO
                        break;
                    case SDLK_d:
                    case SDLK_RIGHT:
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

void SinglePlayerState::update(GameEngine *game) {
    // TODO: Update block positions (moving down). If active capsule can't move, create a new active capsule;
}

void SinglePlayerState::draw(GameEngine *game) {

}
