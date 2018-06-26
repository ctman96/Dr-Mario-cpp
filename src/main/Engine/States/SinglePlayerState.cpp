/*!
 * @author: Cody Newman
 *
 * Created on: 13/06/2018
 */

#include <SDL_image.h>
#include "SinglePlayerState.h"
#include "../../Resources/spritesheets.h"

/*!
 * Constructs the state based on the provided game level, speed, and music choice
 * @param level the game difficulty level
 * @param speed the speed of the game
 * @param music the selected music
 */
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

/*!
 * Initializes the state by loading in the spritesheet and music,
 * as well as setting up the Board
 * @param game the current game engine
 */
void SinglePlayerState::init(GameEngine *game) {
    // Load the spritesheet from memory into a surface
    SDL_RWops *io = SDL_RWFromConstMem(spr_game_png, sizeof(spr_game_png));
    SDL_Surface* tmp = IMG_LoadPNG_RW(io);

    // Create a texture from the surface
    spritesheet = SDL_CreateTextureFromSurface(game->renderer, tmp);

    // Get rid of temp surface
    SDL_FreeSurface(tmp);

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

/*!
 * Cleans up the state for destruction,
 * destroying the spritesheet and clearing
 * the game board
 */
void SinglePlayerState::terminate() {
    SDL_DestroyTexture(spritesheet);
    spritesheet = nullptr;

    board->clear();
    delete(board);
}

/*!
 * Handles any SDL_Events, such as key presses or
 * quitting
 * @param game the current game engine
 */
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
                    case SDLK_q:
                        //TODO
                        board->getActiveCapsule().rotateCCW();
                        break;
                    case SDLK_e:
                        board->getActiveCapsule().rotateCW();
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
 * Updates the state, ticking the game board
 * @param game the current game engine
 */
void SinglePlayerState::update(GameEngine *game) {
    board->update();
}


