/*!
 * @author: Cody Newman
 *
 * Created on: 13/06/2018
 */

#include <SDL_image.h>
#include <cmath>
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

    int ticks = SDL_GetTicks();

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

    // Static Text

    // Level
    renderSpriteFromSheet(game->renderer, 185, 136, spritesheet, &spr_game[ 11 ]);
    //Speed
    renderSpriteFromSheet(game->renderer, 185, 160, spritesheet, &spr_game[ 12 ]);
    //Virus
    renderSpriteFromSheet(game->renderer, 185, 184, spritesheet, &spr_game[ 13 ]);
    //Top
    renderSpriteFromSheet(game->renderer, 18, 49, spritesheet, &spr_game[ 14 ]);
    //Score
    renderSpriteFromSheet(game->renderer, 17, 72, spritesheet, &spr_game[ 15 ]);

    // Animations / Dynamic

    // Level Stats
    //TODO
    // Scoreboard
    //TODO
    // Dr Mario/Next Capsule Display
    //TODO
    renderSpriteFromSheet(game->renderer, 185, 70, spritesheet, &spr_game[ 21 ]);
    // Viruses Display
    // Virus animation frame timer
    int frame = (ticks/250)%6;
    if (frame >= 3){
        frame = 5-frame;
    }
    //TODO: 42 pixel radius circle, 0=38,151
    // x = 38+21*cos(time), y = 151+21*sin(time)?
    double time = ((ticks/420)%360)*3.14/180;
    int circX = 33;
    int circY = 146;
    int r = 17;
    auto bX = static_cast<int>(circX - r * cos(time));
    auto bY = static_cast<int>(circY + r * sin(time));
    renderSpriteFromSheet(game->renderer, bX, bY, spritesheet, &spr_game[22+frame]);
    auto yX = static_cast<int>(circX - r * cos(time + 400));
    auto yY = static_cast<int>(circY + r * sin(time + 400));
    renderSpriteFromSheet(game->renderer, yX, yY, spritesheet, &spr_game[29+frame]);
    auto rX = static_cast<int>(circX - r * cos(time + 800));
    auto rY = static_cast<int>(circY + r * sin(time + 800));
    renderSpriteFromSheet(game->renderer, rX, rY, spritesheet, &spr_game[36+frame]);


    //Board

    // Draw Viruses
    auto viruses = board->getViruses();
    for (const auto &virus : viruses) {
        drawVirus(game->renderer, virus);
    }

    // Draw Blocks
    auto blocks = board->getBlocks();
    for (const auto &block : blocks){
        drawBlock(game->renderer, block);
    }

    // Draw Capsules
    auto capsules = board->getCapsules();
    for (const auto &capsule : capsules){
        drawCapsule(game->renderer, capsule);
    }

    // Draw the current active capsule
    Capsule activeCapsule = Capsule(board->getActiveCapsule());
    drawCapsule(game->renderer, activeCapsule);

    // Draw the upcoming capsule
    drawNextCapsule(game->renderer, board->getNextCapsule());


    //TODO: Gameover/cleared screens

    SDL_RenderPresent(game->renderer);
}

void SinglePlayerState::drawVirus(SDL_Renderer* renderer, Virus v){
    int ticks = SDL_GetTicks();

    int xoffset = 96;
    int yoffset = 191;
    int x = xoffset + (CELL_PIXELS)*v.x;
    int y = yoffset - CELL_PIXELS*v.y;
    switch(v.color){
        case Color::blue:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[44+(ticks/275)%2]); //TODO animate
            break;
        case Color::yellow:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[46+(ticks/275)%2]); //TODO animate
            break;
        case Color::red:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[48+(ticks/275)%2]); //TODO animate
            break;
    }
}

void SinglePlayerState::drawBlock(SDL_Renderer* renderer, Block b){
    //TODO
}

void SinglePlayerState::drawCapsule(SDL_Renderer* renderer, Capsule c){
    //TODO
}

void SinglePlayerState::drawNextCapsule(SDL_Renderer* renderer, Capsule c){
    //TODO
}


