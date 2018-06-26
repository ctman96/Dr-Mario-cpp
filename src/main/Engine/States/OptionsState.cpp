/*!
 * @author: Cody Newman
 *
 * Created on: 10/06/2018
 */

#include <SDL_image.h>
#include "OptionsState.h"
#include "../../Resources/spritesheets.h"
#include "MainMenuState.h"
#include "../../Constants.h"
#include "SinglePlayerState.h"

/*!
 * Constructor creating an OptionsState. Sets the twoplayer flag
 * depending on input
 * @param twoplayer boolean representing whether or no the game is 2player
 */
OptionsState::OptionsState(bool twoplayer) : twoplayer(twoplayer) {}

/*!
 * Initializes the state by loading in the spritesheet and music
 *
 * @param game the current game engine
 */
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

/*!
 * Cleans up the state for destruction,
 * destroying the spritesheet
 */
void OptionsState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;
}

/*!
 * Handles any SDL_Events, such as key presses or
 * quitting
 * @param game the current game engine
 */
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

//! Helper for swapping between selections
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
//! Helper for swapping between selections
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

//! Helper for incrementing an int so that it is never greater than 20
void OptionsState::incLevel(int& level){
    if(level < 20){
        ++level;
    }
    else{
        level = 20;
    }
}

//! Helper for decrementing an int so that it is never less than 0
void OptionsState::decLevel(int& level){
    if(level > 0){
        --level;
    }
    else{
        level = 0;
    }
}

//! Helper for swapping between speeds
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
//! Helper for swapping between speeds
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
//! Helper for swapping between musics
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
//! Helper for swapping between musics
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

/*!
 * Updates the state of the menu. Doesn't currently need to do anything
 * @param game the current game engine
 */
void OptionsState::update(GameEngine *game) {

}