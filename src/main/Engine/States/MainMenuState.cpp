//
// Created by Cody on 6/8/2018.
//

#include <SDL_image.h>
#include "MainMenuState.h"
#include "../../resources.h"
#include "../../Constants.h"
#include "OptionsState.h"
#include "../RenderUtils.h"

using namespace RenderUtils;

void MainMenuState::init(GameEngine* game) {

    // Load the spritesheet from memory into a surface
    SDL_RWops *io = SDL_RWFromConstMem(spr_mainmenu_png, sizeof(spr_mainmenu_png));
    SDL_Surface* tmp = IMG_LoadPNG_RW(io);

    // Create a texture from the surface
    spritesheet = SDL_CreateTextureFromSurface(game->renderer, tmp);

    // Get rid of temp surface
    SDL_FreeSurface(tmp);

    // Create the sprites
    loadSprites();
}

void MainMenuState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;

}

void MainMenuState::handle(GameEngine *game) {
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
                        cursor = true;
                        break;
                    case SDLK_w:
                    case SDLK_UP:
                        cursor = false;
                        break;
                    case SDLK_RETURN:
                        game->changeState(new OptionsState(cursor));
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void MainMenuState::update(GameEngine *game) {

}

void MainMenuState::draw(GameEngine *game) {
    int x, y = 0;
    int ticks = SDL_GetTicks();
    int spr3 = (ticks/100)%3;

    SDL_RenderClear(game->renderer);

    // Background
    renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &sprites[ 0 ]);
    // Pill
    renderSpriteFromSheet(game->renderer, 16, 32, spritesheet, &sprites[ 1 ]);
    // Title animation
    renderSpriteFromSheet(game->renderer, 37,56, spritesheet, &sprites[ 2 + ((ticks/275)%2) ]);
    // Selection Area
    renderSpriteFromSheet(game->renderer, 33, 152, spritesheet, &sprites[ 4 ]);
    // Selection options
    renderSpriteFromSheet(game->renderer, 60, 154, spritesheet, &sprites[ 5 ]);
    // Dr Mario animation
    renderSpriteFromSheet(game->renderer, 43, 162, spritesheet, &sprites[ 6 + ((ticks/200)%2)]);
    // Cursor
    y = cursor ? 176 : 160;
    renderSpriteFromSheet(game->renderer, 69, y, spritesheet, &sprites[ 8 ]);
    // Virus animation
    int frame = (ticks/150)%6;
    if (frame >= 3){
        frame = 5-frame;
    }
    renderSpriteFromSheet(game->renderer, 192, 169, spritesheet, &sprites [ 9 + frame ]);


    SDL_RenderPresent(game->renderer);
}

void MainMenuState::loadSprites(){
    for(int i = 0; i < 12; i++){
        sprites[i] = spr_mainmenu[i];
    }
}