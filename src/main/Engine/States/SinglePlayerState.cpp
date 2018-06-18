//
// Created by Cody on 13/06/2018.
//

#include <SDL_image.h>
#include "SinglePlayerState.h"
#include "../../Resources/spritesheets.h"
#include "../RenderUtils.h"

using namespace RenderUtils;

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
    loadSprites();

    // Load Music
    Mix_FreeMusic(game->music);
    switch(music){
        case Music::fever:
            game->music = Mix_LoadMUS("audio/mus_Fever.mp3");
            break;
        case Music::chill:
            game->music = Mix_LoadMUS("audio/mus_Chill.mp3");
            break;
        case Music::off:
            game->music = nullptr;
            break;
    }
    if(game->music == nullptr){
        printf("Couldn't find music");
        //TODO
    }
    else if (music != Music::off){
        Mix_PlayMusic(game->music,-1);
    }

    //TODO: load the level
    board = new Board();
    board->init(level);
}

void SinglePlayerState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;

    board->clear();
    delete(board);
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
    SDL_RenderClear(game->renderer);

    // Background
    switch(speed){
        case Speed::low:
            renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &sprites[ 2 ]);
            renderSpriteFromSheet(game->renderer, 88, 32, spritesheet, &sprites[ 5 ]);
            break;
        case Speed::med:
            renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &sprites[ 0 ]);
            renderSpriteFromSheet(game->renderer, 88, 32, spritesheet, &sprites[ 3 ]);
            break;
        case Speed::hi:
            renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &sprites[ 1 ]);
            renderSpriteFromSheet(game->renderer, 88, 32, spritesheet, &sprites[ 4 ]);
            break;
    }

    // UI elements

    // Title
    renderSpriteFromSheet(game->renderer, 159, 18, spritesheet, &sprites[ 6 ]);
    // Dr Mario Area
    renderSpriteFromSheet(game->renderer, 176, 56, spritesheet, &sprites[ 7 ]);
    // Viruses Area
    renderSpriteFromSheet(game->renderer, 0, 120, spritesheet, &sprites[ 8 ]);
    // Score board
    renderSpriteFromSheet(game->renderer, 8, 26, spritesheet, &sprites[ 9 ]);
    // Level stats
    renderSpriteFromSheet(game->renderer, 176, 114, spritesheet, &sprites[ 10 ]);

    // Animations / Dynamic

    // Dr Mario/Next Capsule Display
    //TODO
    // Viruses Display
    //TODO
    // Scoreboard
    //TODO
    // Level Stats
    //TODO


    //Board
    //board.draw(game->renderer, x, y); TODO

    SDL_RenderPresent(game->renderer);
}

void SinglePlayerState::loadSprites() {
    for(int i = 0; i < 11; i++){ // TODO Not hardcode size
        sprites[i] = spr_game[i];
    }
}


