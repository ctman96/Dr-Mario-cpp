/*!
 * @author Cody Newman
 *
 * Created on: 25/06/2018
 */

#include "OptionsState.h"
#include "../../Resources/spritesheets.h"
#include "../Rendering/RenderUtils.h"

using namespace RenderUtils;

/*!
 * Renders the state from the spritesheet
 * @param game the current game engine
 */
void OptionsState::draw(GameEngine *game) {
    SDL_RenderClear(game->renderer);

    // Background
    renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &spr_options[ 0 ]);

    // Selection Area
    renderSpriteFromSheet(game->renderer, 24, 16, spritesheet, &spr_options[ 1 ]);

    // Title
    if (!twoplayer) {
        renderSpriteFromSheet(game->renderer, 81, 32, spritesheet, &spr_options[2]);
    }
    else{
        renderSpriteFromSheet(game->renderer, 81, 32, spritesheet, &spr_options[3]);
    }


    // Level Title
    if (selection == Selection::level){
        renderSpriteFromSheet(game->renderer, 42, 50, spritesheet, &spr_options[6]);
    }else{
        renderSpriteFromSheet(game->renderer, 42, 50, spritesheet, &spr_options[7]);
    }
    // Level P1 indicator
    renderSpriteFromSheet(game->renderer, 66, 79, spritesheet, &spr_options[4]);
    // Level P2 indicator
    if (twoplayer){
        renderSpriteFromSheet(game->renderer, 66, 87, spritesheet, &spr_options[5]);
    }
    // Level bar
    renderSpriteFromSheet(game->renderer, 90, 83, spritesheet, &spr_options[8]);
    // Level Display
    renderSpriteFromSheet(game->renderer, 182,66,spritesheet, &spr_options[9]);
    renderNum(game->renderer, level1, 187,71);
    if (twoplayer){
        renderSpriteFromSheet(game->renderer, 182,89,spritesheet, &spr_options[9]);
        renderNum(game->renderer, level2, 187,94);
    }
    // Level Cursor P1
    renderSpriteFromSheet(game->renderer, 88+level1*4, 76,spritesheet, &spr_options[10]);
    // Level Cursor P2
    if (twoplayer) {
        renderSpriteFromSheet(game->renderer, 88+level2*4, 91,spritesheet, &spr_options[11]);
    }



    // Speed Title
    if (selection == Selection::speed){
        renderSpriteFromSheet(game->renderer, 42, 104, spritesheet, &spr_options[12]);
    }else{
        renderSpriteFromSheet(game->renderer, 42, 104, spritesheet, &spr_options[13]);
    }
    // Speed Low
    renderSpriteFromSheet(game->renderer, 90, 135, spritesheet, &spr_options[14]);
    // Speed Med
    renderSpriteFromSheet(game->renderer, 129, 135, spritesheet, &spr_options[15]);
    // Speed Hi
    renderSpriteFromSheet(game->renderer, 169, 135, spritesheet, &spr_options[16]);
    // Speed Cursor P1
    switch(speed1){
        case Speed::low:
            renderSpriteFromSheet(game->renderer, 90, 128, spritesheet, &spr_options[17]);
            break;
        case Speed::med:
            renderSpriteFromSheet(game->renderer, 130, 128, spritesheet, &spr_options[17]);
            break;
        case Speed::hi:
            renderSpriteFromSheet(game->renderer, 166, 128, spritesheet, &spr_options[17]);
            break;
    }
    // Speed Cursor P2
    if (twoplayer) {
        switch(speed2){
            case Speed::low:
                renderSpriteFromSheet(game->renderer, 90, 143, spritesheet, &spr_options[18]);
                break;
            case Speed::med:
                renderSpriteFromSheet(game->renderer, 130, 143, spritesheet, &spr_options[18]);
                break;
            case Speed::hi:
                renderSpriteFromSheet(game->renderer, 166, 143, spritesheet, &spr_options[18]);
                break;
        }
    }
    // Speed P1 indicator
    renderSpriteFromSheet(game->renderer, 66, 131, spritesheet, &spr_options[4]);
    // Speed P2 indicator
    if (twoplayer){
        renderSpriteFromSheet(game->renderer, 66, 139, spritesheet, &spr_options[5]);
    }


    // Music Title
    if (selection == Selection::music){
        renderSpriteFromSheet(game->renderer, 42, 154, spritesheet, &spr_options[19]);
    }else{
        renderSpriteFromSheet(game->renderer, 42, 154, spritesheet, &spr_options[20]);
    }
    // Music Fever
    if (music == Music::fever){
        renderSpriteFromSheet(game->renderer, 60, 178, spritesheet, &spr_options[22]);
    }
    else {
        renderSpriteFromSheet(game->renderer, 60, 178, spritesheet, &spr_options[21]);
    }
    // Music Chill
    if (music == Music::chill){
        renderSpriteFromSheet(game->renderer, 116, 178, spritesheet, &spr_options[24]);
    }
    else {
        renderSpriteFromSheet(game->renderer, 116, 178, spritesheet, &spr_options[23]);
    }
    // Music Off
    if (music == Music::off){
        renderSpriteFromSheet(game->renderer, 172, 178, spritesheet, &spr_options[26]);
    }
    else {
        renderSpriteFromSheet(game->renderer, 172, 178, spritesheet, &spr_options[25]);
    }

    SDL_RenderPresent(game->renderer);
}

/*!
 * Renders a two digit number at the coordinates provided
 * @param renderer the Renderer to be used
 * @param num the number to be rendered
 * @param x the x position to render at
 * @param y the y position to render at
 */
void OptionsState::renderNum(SDL_Renderer* renderer, int num, int x, int y) {
    int x2 = x+8;

    if (num < 0  || num > 99 || x < 0 || y < 0){
        return; //TODO errors
    }
    int tens = num / 10;
    int ones = num % 10;

    renderSpriteFromSheet(renderer, x,y, spritesheet, &spr_options[27+tens]);
    renderSpriteFromSheet(renderer, x2, y, spritesheet, &spr_options[27+ones]);
}