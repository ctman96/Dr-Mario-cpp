//
// Created by Cody on 6/10/2018.
//

#include <SDL_image.h>
#include "OptionsState.h"
#include "../../Resources/spritesheets.h"
#include "MainMenuState.h"
#include "../../Constants.h"
#include "../RenderUtils.h"
#include "SinglePlayerState.h"

using namespace RenderUtils;

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

    //Load music
    Mix_FreeMusic(game->music);
    game->music = Mix_LoadMUS("audio/mus_Select.mp3");
    if(game->music == nullptr){
        printf("Couldn't find music");
        //TODO
    }
    else{
        Mix_PlayMusic(game->music,-1);
    }
}

void OptionsState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;
}

void OptionsState::handle(GameEngine *game) { //TODO use SDL key states to keep track of simultaneous key presses
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
                        switch(selection){
                            case Selection::level:
                                incLevel(level1);
                                break;
                            case Selection::speed:
                                incSpeed(speed1);
                                break;
                            case Selection::music:
                                incMusic();
                                break;
                        }
                        break;
                    case SDLK_RIGHT:
                        switch(selection){
                            case Selection::level:
                                incLevel(level2);
                                break;
                            case Selection::speed:
                                incSpeed(speed2);
                                break;
                            case Selection::music:
                                incMusic();
                                break;
                        }
                        break;
                    case SDLK_a:
                        switch(selection){
                            case Selection::level:
                                decLevel(level1);
                                break;
                            case Selection::speed:
                                decSpeed(speed1);
                                break;
                            case Selection::music:
                                decMusic();
                                break;
                        }
                        break;
                    case SDLK_LEFT:
                        switch(selection){
                            case Selection::level:
                                decLevel(level2);
                                break;
                            case Selection::speed:
                                decSpeed(speed2);
                                break;
                            case Selection::music:
                                decMusic();
                                break;
                        }
                        break;
                    case SDLK_RETURN:
                        if(twoplayer){
                            //TODO
                        }
                        else {
                            game->changeState(new SinglePlayerState(level1, speed1, music));
                        }
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

// Helper for swapping between selections
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
// Helper for swapping between selections
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

// Helper for incrementing an int so that it is never greater than 20
void OptionsState::incLevel(int& level){
    if(level < 20){
        ++level;
    }
    else{
        level = 20;
    }
}

// Helper for decrementing an int so that it is never less than 0
void OptionsState::decLevel(int& level){
    if(level > 0){
        --level;
    }
    else{
        level = 0;
    }
}

// Helper for swapping between speeds
void OptionsState::decSpeed(Speed& speed){
    switch (speed){
        case Speed::hi:
            speed = Speed::med;
            break;
        case Speed::med:
        case Speed::low:
            speed = Speed::low;
            break;

    }
}
// Helper for swapping between speeds
void OptionsState::incSpeed(Speed& speed){
    switch (speed){
        case Speed::low:
            speed = Speed::med;
            break;
        case Speed::med:
        case Speed::hi:
            speed = Speed::hi;
            break;

    }
}
// Helper for swapping between musics
void OptionsState::incMusic(){
    switch (music){
        case Music::fever:
            music = Music::chill;
            break;
        case Music::chill:
        case Music::off:
            music = Music::off;
            break;
    }
}
// Helper for swapping between musics
void OptionsState::decMusic(){
    switch (music){
        case Music::off:
            music = Music::chill;
            break;
        case Music::chill:
        case Music::fever:
            music = Music::fever;
            break;
    }
}

void OptionsState::update(GameEngine *game) {

}

void OptionsState::draw(GameEngine *game) {
    SDL_RenderClear(game->renderer);

    // Background
    renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &sprites[ 0 ]);

    // Selection Area
    renderSpriteFromSheet(game->renderer, 24, 16, spritesheet, &sprites[ 1 ]);

    // Title
    if (!twoplayer) {
        renderSpriteFromSheet(game->renderer, 81, 32, spritesheet, &sprites[2]);
    }
    else{
        renderSpriteFromSheet(game->renderer, 81, 32, spritesheet, &sprites[3]);
    }


    // Level Title
    if (selection == Selection::level){
        renderSpriteFromSheet(game->renderer, 42, 50, spritesheet, &sprites[6]);
    }else{
        renderSpriteFromSheet(game->renderer, 42, 50, spritesheet, &sprites[7]);
    }
    // Level P1 indicator
    renderSpriteFromSheet(game->renderer, 66, 79, spritesheet, &sprites[4]);
    // Level P2 indicator
    if (twoplayer){
        renderSpriteFromSheet(game->renderer, 66, 87, spritesheet, &sprites[5]);
    }
    // Level bar
    renderSpriteFromSheet(game->renderer, 90, 83, spritesheet, &sprites[8]);
    // Level Display
    renderSpriteFromSheet(game->renderer, 182,66,spritesheet, &sprites[9]);
    renderNum(game->renderer, level1, 187,71);
    if (twoplayer){
        renderSpriteFromSheet(game->renderer, 182,89,spritesheet, &sprites[9]);
        renderNum(game->renderer, level2, 187,94);
    }
    // Level Cursor P1
    renderSpriteFromSheet(game->renderer, 88+level1*4, 76,spritesheet, &sprites[10]);
    // Level Cursor P2
    if (twoplayer) {
        renderSpriteFromSheet(game->renderer, 88+level2*4, 91,spritesheet, &sprites[11]);
    }



    // Speed Title
    if (selection == Selection::speed){
        renderSpriteFromSheet(game->renderer, 42, 104, spritesheet, &sprites[12]);
    }else{
        renderSpriteFromSheet(game->renderer, 42, 104, spritesheet, &sprites[13]);
    }
    // Speed Low
    renderSpriteFromSheet(game->renderer, 90, 135, spritesheet, &sprites[14]);
    // Speed Med
    renderSpriteFromSheet(game->renderer, 129, 135, spritesheet, &sprites[15]);
    // Speed Hi
    renderSpriteFromSheet(game->renderer, 169, 135, spritesheet, &sprites[16]);
    // Speed Cursor P1
    switch(speed1){
        case Speed::low:
            renderSpriteFromSheet(game->renderer, 90, 128, spritesheet, &sprites[17]);
            break;
        case Speed::med:
            renderSpriteFromSheet(game->renderer, 130, 128, spritesheet, &sprites[17]);
            break;
        case Speed::hi:
            renderSpriteFromSheet(game->renderer, 166, 128, spritesheet, &sprites[17]);
            break;
    }
    // Speed Cursor P2
    if (twoplayer) {
        switch(speed2){
            case Speed::low:
                renderSpriteFromSheet(game->renderer, 90, 143, spritesheet, &sprites[18]);
                break;
            case Speed::med:
                renderSpriteFromSheet(game->renderer, 130, 143, spritesheet, &sprites[18]);
                break;
            case Speed::hi:
                renderSpriteFromSheet(game->renderer, 166, 143, spritesheet, &sprites[18]);
                break;
        }
    }
    // Speed P1 indicator
    renderSpriteFromSheet(game->renderer, 66, 131, spritesheet, &sprites[4]);
    // Speed P2 indicator
    if (twoplayer){
        renderSpriteFromSheet(game->renderer, 66, 139, spritesheet, &sprites[5]);
    }


    // Music Title
    if (selection == Selection::music){
        renderSpriteFromSheet(game->renderer, 42, 154, spritesheet, &sprites[19]);
    }else{
        renderSpriteFromSheet(game->renderer, 42, 154, spritesheet, &sprites[20]);
    }
    // Music Fever
    if (music == Music::fever){
        renderSpriteFromSheet(game->renderer, 60, 178, spritesheet, &sprites[22]);
    }
    else {
        renderSpriteFromSheet(game->renderer, 60, 178, spritesheet, &sprites[21]);
    }
    // Music Chill
    if (music == Music::chill){
        renderSpriteFromSheet(game->renderer, 116, 178, spritesheet, &sprites[24]);
    }
    else {
        renderSpriteFromSheet(game->renderer, 116, 178, spritesheet, &sprites[23]);
    }
    // Music Off
    if (music == Music::off){
        renderSpriteFromSheet(game->renderer, 172, 178, spritesheet, &sprites[26]);
    }
    else {
        renderSpriteFromSheet(game->renderer, 172, 178, spritesheet, &sprites[25]);
    }

    SDL_RenderPresent(game->renderer);
}

void OptionsState::loadSprites(){
    for(int i = 0; i < 37; i++){ //TODO not hardcode value
        sprites[i] = spr_options[i];
    }
}

// Display a two digit number at the x,y coordinates provided
void OptionsState::renderNum(SDL_Renderer* renderer, int num, int x, int y) {
    int x2 = x+8;

    if (num < 0  || num > 99 || x < 0 || y < 0){
        return; //TODO errors
    }
    int tens = num / 10;
    int ones = num % 10;

    renderSpriteFromSheet(renderer, x,y, spritesheet, &sprites[27+tens]);
    renderSpriteFromSheet(renderer, x2, y, spritesheet, &sprites[27+ones]);
}
