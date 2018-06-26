/*!
 * @author Cody Newman
 *
 * Created on: 25/06/2018
 */

#include "MainMenuState.h"
#include "../../Resources/spritesheets.h"
#include "../Rendering/RenderUtils.h"

using namespace RenderUtils;

/*!
 * Renders the state from the spritesheet
 * @param game the current game engine
 */
void MainMenuState::draw(GameEngine *game) {
    int x, y = 0;
    int ticks = SDL_GetTicks();
    int spr3 = (ticks/100)%3;

    SDL_RenderClear(game->renderer);

    // Background
    renderSpriteFromSheet(game->renderer, 0, 0, spritesheet, &spr_mainmenu[ 0 ]);
    // Pill
    renderSpriteFromSheet(game->renderer, 16, 32, spritesheet, &spr_mainmenu[ 1 ]);
    // Title animation
    renderSpriteFromSheet(game->renderer, 37,56, spritesheet, &spr_mainmenu[ 2 + ((ticks/275)%2) ]);
    // Selection Area
    renderSpriteFromSheet(game->renderer, 33, 152, spritesheet, &spr_mainmenu[ 4 ]);
    // Selection options
    renderSpriteFromSheet(game->renderer, 60, 154, spritesheet, &spr_mainmenu[ 5 ]);
    // Dr Mario animation
    renderSpriteFromSheet(game->renderer, 43, 162, spritesheet, &spr_mainmenu[ 6 + ((ticks/200)%2)]);
    // Cursor
    y = cursor ? 176 : 160;
    renderSpriteFromSheet(game->renderer, 69, y, spritesheet, &spr_mainmenu[ 8 ]);
    // Virus animation
    int frame = (ticks/150)%6;
    if (frame >= 3){
        frame = 5-frame;
    }
    renderSpriteFromSheet(game->renderer, 192, 169, spritesheet, &spr_mainmenu[ 9 + frame ]);


    SDL_RenderPresent(game->renderer);
}