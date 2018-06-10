//
// Created by Cody on 6/10/2018.
//

#include <SDL_image.h>
#include "OptionsState.h"
#include "../../resources.h"
#include "MainMenuState.h"
#include "../../Constants.h"

OptionsState::OptionsState(bool twoplayer) : twoplayer(twoplayer) {}

void OptionsState::init(GameEngine *game) {
    if (!twoplayer){
        twoplayer = false;
    }

    selection = Selection::level;

    // Load the spritesheet from memory into a surface
    SDL_RWops *io = SDL_RWFromConstMem(spr_options_png, sizeof(spr_options_png));
    SDL_Surface* tmp = IMG_LoadPNG_RW(io);

    // Create a texture from the surface
    spritesheet = SDL_CreateTextureFromSurface(game->renderer, tmp);

    // Get rid of temp surface
    SDL_FreeSurface(tmp);

    // Create the sprites
    loadSprites();
}

void OptionsState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;
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
                    case SDLK_ESCAPE:
                        game->changeState(new MainMenuState);
                    case SDLK_s:
                    case SDLK_DOWN:
                        selectionDown();
                        break;
                    case SDLK_w:
                    case SDLK_UP:
                        selectionUp();
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

void OptionsState::selectionDown() {
    switch(selection){
        case Selection::level:
            selection = Selection::speed;
            break;
        case Selection::speed:
        case Selection::music:
            selection = Selection::music;
            break;
    }
}
void OptionsState::selectionUp() {
    switch(selection){
        case Selection::music:
            selection = Selection::speed;
            break;
        case Selection::speed:
        case Selection::level:
            selection = Selection::level;
    }
}

void OptionsState::update(GameEngine *game) {

}

void OptionsState::draw(GameEngine *game) {
    SDL_RenderClear(game->renderer);

    // Background
    renderSprite(game->renderer, 0, 0, &sprites[ 0 ]);

    // Selection Area
    renderSprite(game->renderer, 24, 16, &sprites[ 1 ]);

    // Title
    if (!twoplayer) {
        renderSprite(game->renderer, 81, 32, &sprites[2]);
    }
    else{
        renderSprite(game->renderer, 81, 32, &sprites[3]);
    }


    // Level Title
    if (selection == Selection::level){
        renderSprite(game->renderer, 42, 50, &sprites[6]);
    }else{
        renderSprite(game->renderer, 42, 50, &sprites[7]);
    }
    // P1 indicator
    renderSprite(game->renderer, 66, 79, &sprites[4]);
    // P2 indicator
    if (twoplayer){
        renderSprite(game->renderer, 66, 87, &sprites[5]);
    }
    // Level bar
    renderSprite(game->renderer, 89, 83, &sprites[8]);



    // Speed Title
    if (selection == Selection::speed){
        renderSprite(game->renderer, 42, 104, &sprites[12]);
    }else{
        renderSprite(game->renderer, 42, 104, &sprites[13]);
    }


    // Music Title
    if (selection == Selection::music){
        renderSprite(game->renderer, 42, 154, &sprites[19]);
    }else{
        renderSprite(game->renderer, 42, 154, &sprites[20]);
    }

    SDL_RenderPresent(game->renderer);
}

void OptionsState::renderSprite(SDL_Renderer* renderer, int x, int y, SDL_Rect* sprite) {
    if (sprite == nullptr){
        return;
    }
    SDL_Rect render = {x*SCALING,y*SCALING,sprite->w*SCALING,sprite->h*SCALING};
    SDL_RenderCopy(renderer, spritesheet, sprite, &render);
}

void OptionsState::loadSprites(){
    // Background
    sprites[ 0 ].x = 228;
    sprites[ 0 ].y = 3;
    sprites[ 0 ].w = 256;
    sprites[ 0 ].h = 224;
    // Selection area
    sprites[ 1 ].x = 11;
    sprites[ 1 ].y = 233;
    sprites[ 1 ].w = 208;
    sprites[ 1 ].h = 192;
    // Title - 1 player
    sprites[ 2 ].x = 61;
    sprites[ 2 ].y = 21;
    sprites[ 2 ].w = 103;
    sprites[ 2 ].h = 7;
    // Title - 2 player
    sprites[ 3 ].x = 61;
    sprites[ 3 ].y = 31;
    sprites[ 3 ].w = 103;
    sprites[ 3 ].h = 7;
    // 1p
    sprites[ 4 ].x = 40;
    sprites[ 4 ].y = 21;
    sprites[ 4 ].w = 15;
    sprites[ 4 ].h = 7;
    // 2p
    sprites[ 5 ].x = 40;
    sprites[ 5 ].y = 31;
    sprites[ 5 ].w = 15;
    sprites[ 5 ].h = 7;

    // Level Selection Sprites

    // Level Title active
    sprites[ 6 ].x = 8;
    sprites[ 6 ].y = 151;
    sprites[ 6 ].w = 103;
    sprites[ 6 ].h = 21;
    // Level Title inactive
    sprites[ 7 ].x = 115;
    sprites[ 7 ].y = 151;
    sprites[ 7 ].w = 103;
    sprites[ 7 ].h = 21;
    // Level bar
    sprites[ 8 ].x = 53;
    sprites[ 8 ].y = 48;
    sprites[ 8 ].w = 83;
    sprites[ 8 ].h = 8;
    // Level display TODO
    sprites[ 9 ].x = 0;
    sprites[ 9 ].y = 0;
    sprites[ 9 ].w = 0;
    sprites[ 9 ].h = 0;
    // Level cursor 1 TODO
    sprites[ 10 ].x = 0;
    sprites[ 10 ].y = 0;
    sprites[ 10 ].w = 0;
    sprites[ 10 ].h = 0;
    // Level cursor 2 TODO
    sprites[ 11 ].x = 0;
    sprites[ 11 ].y = 0;
    sprites[ 11 ].w = 0;
    sprites[ 11 ].h = 0;

    // Speed Selection Sprites

    // Speed Title active
    sprites[ 12 ].x = 29;
    sprites[ 12 ].y = 175;
    sprites[ 12 ].w = 55;
    sprites[ 12 ].h = 21;
    // Speed Title inactive
    sprites[ 13 ].x = 136;
    sprites[ 13 ].y = 175;
    sprites[ 13 ].w = 55;
    sprites[ 13 ].h = 21;
    // Speed Low TODO
    sprites[ 14 ].x = 0;
    sprites[ 14 ].y = 0;
    sprites[ 14 ].w = 0;
    sprites[ 14 ].h = 0;
    // Speed Med TODO
    sprites[ 15 ].x = 0;
    sprites[ 15 ].y = 0;
    sprites[ 15 ].w = 0;
    sprites[ 15 ].h = 0;
    // Speed Hi TODO
    sprites[ 16 ].x = 0;
    sprites[ 16 ].y = 0;
    sprites[ 16 ].w = 0;
    sprites[ 16 ].h = 0;
    // Speed Cursor 1 TODO
    sprites[ 17 ].x = 0;
    sprites[ 17 ].y = 0;
    sprites[ 17 ].w = 0;
    sprites[ 17 ].h = 0;
    // Speed Cursor 2 TODO
    sprites[ 18 ].x = 0;
    sprites[ 18 ].y = 0;
    sprites[ 18 ].w = 0;
    sprites[ 18 ].h = 0;

    // Music Selection

    // Music Title active
    sprites[ 19 ].x = 11;
    sprites[ 19 ].y = 127;
    sprites[ 19 ].w = 95;
    sprites[ 19 ].h = 21;
    // Music Title inactive
    sprites[ 20 ].x = 118;
    sprites[ 20 ].y = 127;
    sprites[ 20 ].w = 95;
    sprites[ 20 ].h = 21;
    // Music Fever TODO
    sprites[ 21 ].x = 0;
    sprites[ 21 ].y = 0;
    sprites[ 21 ].w = 0;
    sprites[ 21 ].h = 0;
    // Music Fever Selected TODO
    sprites[ 22 ].x = 0;
    sprites[ 22 ].y = 0;
    sprites[ 22 ].w = 0;
    sprites[ 22 ].h = 0;
    // Music Chill TODO
    sprites[ 23 ].x = 0;
    sprites[ 23 ].y = 0;
    sprites[ 23 ].w = 0;
    sprites[ 23 ].h = 0;
    // Music Chill Selected TODO
    sprites[ 24 ].x = 0;
    sprites[ 24 ].y = 0;
    sprites[ 24 ].w = 0;
    sprites[ 24 ].h = 0;
    // Music Off TODO
    sprites[ 25 ].x = 0;
    sprites[ 25 ].y = 0;
    sprites[ 25 ].w = 0;
    sprites[ 25 ].h = 0;
    // Music Off Selected TODO
    sprites[ 26 ].x = 0;
    sprites[ 26 ].y = 0;
    sprites[ 26 ].w = 0;
    sprites[ 26 ].h = 0;

    // Num0
    sprites[ 27 ].x = 67;
    sprites[ 27 ].y = 208;
    sprites[ 27 ].w = 7;
    sprites[ 27 ].h = 7;
    // Num1
    sprites[ 28 ].x = 75;
    sprites[ 28 ].y = 208;
    sprites[ 28 ].w = 7;
    sprites[ 28 ].h = 7;
    // Num2
    sprites[ 29 ].x = 84;
    sprites[ 29 ].y = 208;
    sprites[ 29 ].w = 7;
    sprites[ 29 ].h = 7;
    // Num3
    sprites[ 30 ].x = 93;
    sprites[ 30 ].y = 208;
    sprites[ 30 ].w = 7;
    sprites[ 30 ].h = 7;
    // Num4
    sprites[ 31 ].x = 102;
    sprites[ 31 ].y = 208;
    sprites[ 31 ].w = 7;
    sprites[ 31 ].h = 7;
    // Num5
    sprites[ 32 ].x = 111;
    sprites[ 32 ].y = 208;
    sprites[ 32 ].w = 7;
    sprites[ 32 ].h = 7;
    // Num6
    sprites[ 33 ].x = 120;
    sprites[ 33 ].y = 208;
    sprites[ 33 ].w = 7;
    sprites[ 33 ].h = 7;
    // Num7
    sprites[ 34 ].x = 128;
    sprites[ 34 ].y = 208;
    sprites[ 34 ].w = 7;
    sprites[ 34 ].h = 7;
    // Num8
    sprites[ 35 ].x = 137;
    sprites[ 35 ].y = 208;
    sprites[ 35 ].w = 7;
    sprites[ 35 ].h = 7;
    // Num9
    sprites[ 36 ].x = 146;
    sprites[ 36 ].y = 208;
    sprites[ 36 ].w = 7;
    sprites[ 36 ].h = 7;
}
