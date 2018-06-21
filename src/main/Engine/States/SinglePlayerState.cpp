/*!
 * @author: Cody Newman
 *
 * Created on: 13/06/2018
 */

#include <SDL_image.h>
#include "SinglePlayerState.h"
#include "../../Resources/spritesheets.h"
#include "../RenderUtils.h"

using namespace RenderUtils;

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

/*!
 * Renders the state from the spritesheet
 * @param game the current game engine
 */
void SinglePlayerState::draw(GameEngine *game) {
    SDL_RenderClear(game->renderer);

    // Background
    switch(speed){
        case Speed::low:
            renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &spr_game[ 2 ]);
            renderSpriteFromSheet(game->renderer, 88, 32, spritesheet, &spr_game[ 5 ]);
            break;
        case Speed::med:
            renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &spr_game[ 0 ]);
            renderSpriteFromSheet(game->renderer, 88, 32, spritesheet, &spr_game[ 3 ]);
            break;
        case Speed::hi:
            renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &spr_game[ 1 ]);
            renderSpriteFromSheet(game->renderer, 88, 32, spritesheet, &spr_game[ 4 ]);
            break;
    }

    // UI elements

    // Title
    renderSpriteFromSheet(game->renderer, 159, 18, spritesheet, &spr_game[ 6 ]);
    // Dr Mario Area
    renderSpriteFromSheet(game->renderer, 176, 56, spritesheet, &spr_game[ 7 ]);
    // Viruses Area
    renderSpriteFromSheet(game->renderer, 0, 120, spritesheet, &spr_game[ 8 ]);
    // Score board
    renderSpriteFromSheet(game->renderer, 8, 26, spritesheet, &spr_game[ 9 ]);
    // Level stats
    renderSpriteFromSheet(game->renderer, 176, 114, spritesheet, &spr_game[ 10 ]);

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
    auto viruses = board->getViruses();
    auto itv = viruses.begin();
    for( int i = 0; i < viruses.size(); i++){
        drawVirus(game->renderer, *itv);
        next(itv);
    }
    auto blocks = board->getBlocks();
    auto itb = blocks.begin();
    for(int i = 0; i < blocks.size(); i++){
        if (dynamic_cast<Block*>(*itb) != nullptr){
            drawBlock(game->renderer, dynamic_cast<Block*>(*itb));
        }
        else if (dynamic_cast<Capsule*>(*itb) != nullptr){
            drawCapsule(game->renderer, dynamic_cast<Capsule*>(*itb));
        }
        next(itb);
    }
    //TODO: Draw activeCapsule, nextcapsule

    SDL_RenderPresent(game->renderer);
}

void SinglePlayerState::drawVirus(SDL_Renderer* renderer, Virus v){
    int xoffset = 96;
    int yoffset = 72;
    int x = CELL_PIXELS*SCALING*v.x + xoffset;
    int y = CELL_PIXELS*SCALING*v.y + yoffset;
    switch(v.color){
        case Color::yellow:
            //renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[6]); //TODO sprite index
            break;
        case Color::blue:
            //renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[6]); //TODO sprite index
            break;
        case Color::red:
            //renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[6]); //TODO sprite index
            break;
    }
}

void SinglePlayerState::drawBlock(SDL_Renderer* renderer, Block* b){
    //TODO
}

void SinglePlayerState::drawCapsule(SDL_Renderer* renderer, Capsule* c){
    //TODO
}


