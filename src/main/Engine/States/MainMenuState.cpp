/*!
 * @author: Cody Newman
 *
 * Created on: 8/06/2018
 */

#include <SDL_image.h>
#include "MainMenuState.h"
#include "../../Resources/spritesheets.h"
#include "../../Constants.h"
#include "OptionsState.h"

/*!
 * Initializes the state by loading in the spritesheet and music
 * @param game the current game engine
 */
void MainMenuState::init(GameEngine* game) {

    // Load the spritesheet from memory into a surface
    SDL_RWops *io = SDL_RWFromConstMem(spr_mainmenu_png, sizeof(spr_mainmenu_png));
    SDL_Surface* tmp = IMG_LoadPNG_RW(io);

    // Create a texture from the surface
    spritesheet = SDL_CreateTextureFromSurface(game->renderer, tmp);

    // Get rid of temp surface
    SDL_FreeSurface(tmp);

    //Load music
    Mix_FreeMusic(game->music);
    game->music = Mix_LoadMUS("audio/mus_Title.mp3");
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
void MainMenuState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;

}

/*!
 * Handles any SDL_Events, such as key presses or
 * quitting
 * @param game the current game engine
 */
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

/*!
 * Updates the state of the menu. Doesn't currently need to do anything
 * @param game the current game engine
 */
void MainMenuState::update(GameEngine *game) {

}