/*!
 * @author Cody Newman
 *
 * Created on: 25/06/2018
 */

#include <cmath>
#include "SinglePlayerState.h"
#include "../../Resources/spritesheets.h"
#include "../Rendering/RenderUtils.h"

using namespace RenderUtils;

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
    //Level
    drawNum(game->renderer, level, 216, 145);
    //Speed
    switch(speed){
        case Speed::low:
            renderSpriteFromSheet(game->renderer, 209,169, spritesheet, &spr_game[70]);
            break;
        case Speed::med:
            renderSpriteFromSheet(game->renderer, 208,169, spritesheet, &spr_game[71]);
            break;
        case Speed::hi:
            renderSpriteFromSheet(game->renderer, 216,169, spritesheet, &spr_game[72]);
            break;
    }
    //Viruses remaining
    drawNum(game->renderer, board->getViruses().size(), 216, 193);
    // Scoreboard
    //TODO
    // Dr Mario/Next Capsule Display
    //TODO, this is placeholder
    if(board->getBoardState() == Board::BoardState::loss) {
        renderSpriteFromSheet(game->renderer, 185, 70, spritesheet, &spr_game[21]);
    }
    else {
        renderSpriteFromSheet(game->renderer, 185, 68, spritesheet, &spr_game[16]);
    }
    // Viruses Display
    drawVirusDisplayAnimation(game->renderer);


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
        int x = xoffset + (CELL_PIXELS)*capsule.x;
        int y = yoffset - CELL_PIXELS*capsule.y;
        drawCapsule(game->renderer, capsule, x, y);
    }


    if (!(board->getBoardState() == Board::BoardState::loading)) {
        // Draw the current active capsule
        Capsule activeCapsule = board->getActiveCapsule();
        int x = xoffset + (CELL_PIXELS)*activeCapsule.x;
        int y = yoffset - CELL_PIXELS*activeCapsule.y;
        drawCapsule(game->renderer, activeCapsule, x, y);

        // Draw the upcoming capsule
        drawCapsule(game->renderer, board->getNextCapsule(), 191, 62);
    }


    //TODO: Gameover/cleared screens

    SDL_RenderPresent(game->renderer);
}

void SinglePlayerState::drawVirus(SDL_Renderer* renderer, Virus v){
    int ticks = SDL_GetTicks();
    int x = xoffset + (CELL_PIXELS)*v.x;
    int y = yoffset - CELL_PIXELS*v.y;
    switch(v.color){
        case Color::red:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[48+(ticks/275)%2]);
            break;
        case Color::blue:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[44+(ticks/275)%2]);
            break;
        case Color::yellow:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[46+(ticks/275)%2]);
            break;
    }
}

void SinglePlayerState::drawBlock(SDL_Renderer* renderer, Block b){
    int x = xoffset + (CELL_PIXELS)*b.x;
    int y = yoffset - CELL_PIXELS*b.y;
    switch(b.color){
        case Color::red:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[52]);
            break;
        case Color::blue:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[51]);
            break;
        case Color::yellow:
            renderSpriteFromSheet(renderer, x,y,spritesheet, &spr_game[50]);
            break;
    }
}

void SinglePlayerState::drawCapsule(SDL_Renderer* renderer, Capsule c, int x, int y){
    int rotation = 0;
    // TODO: Rotation is weird. Try working around it by adjusting rendering, or else add rotated sprites to the sheet
    switch(c.getRotation()){
        case Rotation::l:
            break;
        case Rotation::u:
            rotation = 90;
            break;
        case Rotation::r:
            rotation = 180;
            break;
        case Rotation::d:
            rotation = 270;
            break;
    }

    int sprite = 0;
    switch(c.color1){
        case Color::red:
            switch(c.color2){
                case Color::red:
                    sprite = 59;
                    break;
                case Color::blue:
                    sprite = 60;
                    break;
                case Color::yellow:
                    sprite = 61;
                    break;
            }
            break;
        case Color::blue:
            switch(c.color2){
                case Color::red:
                    sprite = 58;
                    break;
                case Color::blue:
                    sprite = 56;
                    break;
                case Color::yellow:
                    sprite = 57;
                    break;
            }
            break;
        case Color::yellow:
            switch(c.color2){
                case Color::red:
                    sprite = 55;
                    break;
                case Color::blue:
                    sprite = 54;
                    break;
                case Color::yellow:
                    sprite = 53;
                    break;
            }
            break;
    }

    renderSpriteFromSheet(renderer, x, y, spritesheet, &spr_game[sprite], rotation);
}

/*!
 * Renders a two digit number at the coordinates provided
 * @param renderer the Renderer to be used
 * @param num the number to be rendered
 * @param x the x position to render at
 * @param y the y position to render at
 */
void SinglePlayerState::drawNum(SDL_Renderer* renderer, int num, int x, int y) { //TODO duplicate code in optionstate
    int x2 = x+8;

    if (num < 0  || num > 99 || x < 0 || y < 0){
        return; //TODO errors
    }
    int tens = num / 10;
    int ones = num % 10;

    renderSpriteFromSheet(renderer, x,y, spritesheet, &spr_game[73+tens]);
    renderSpriteFromSheet(renderer, x2, y, spritesheet, &spr_game[73+ones]);
}

void SinglePlayerState::drawVirusDisplayAnimation(SDL_Renderer* renderer){
    int ticks = SDL_GetTicks();
    // Virus animation frame timer
    int frame = (ticks/250)%6;
    if (frame >= 3){
        frame = 5-frame;
    }
    double time = ((ticks/420)%360)*3.14/180;
    int circX = 33;
    int circY = 146;
    int r = 17;
    auto bX = static_cast<int>(circX - r * cos(time));
    auto bY = static_cast<int>(circY + r * sin(time));
    renderSpriteFromSheet(renderer, bX, bY, spritesheet, &spr_game[22+frame]);
    auto yX = static_cast<int>(circX - r * cos(time + 400));
    auto yY = static_cast<int>(circY + r * sin(time + 400));
    renderSpriteFromSheet(renderer, yX, yY, spritesheet, &spr_game[29+frame]);
    auto rX = static_cast<int>(circX - r * cos(time + 800));
    auto rY = static_cast<int>(circY + r * sin(time + 800));
    renderSpriteFromSheet(renderer, rX, rY, spritesheet, &spr_game[36+frame]);
}