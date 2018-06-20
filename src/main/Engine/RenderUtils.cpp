/*!
 * @author: Cody Newman
 *
 * Created on: 11/06/2018
 */

#include "RenderUtils.h"
#include "../Constants.h"

/*!
 * Renders a sprite from a spritesheet to the game window
 * @param renderer The Renderer to be used for rendering
 * @param x The x coordinate to render the sprite at
 * @param y The y coordinate to render the sprite at
 * @param spritesheet The spritesheet SDL_Texture containing the sprite
 * @param sprite The SDL_Rect containing the sprites location and size in the spritesheet
 */
void RenderUtils::renderSpriteFromSheet(SDL_Renderer *renderer, int x, int y, SDL_Texture *spritesheet, SDL_Rect *sprite) {
    if (sprite == nullptr){
        return;
    }
    SDL_Rect render = {x*SCALING,y*SCALING,sprite->w*SCALING,sprite->h*SCALING};
    SDL_RenderCopy(renderer, spritesheet, sprite, &render);
}
